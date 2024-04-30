% Define the folder path
folderPath = 'D:\github\VirtualHeart&Pacemaker\1-MatlabToCSV\cases'; 
SaveCSVPath = 'D:\github\VirtualHeart&Pacemaker\2-MatlabToCSVOutput';
% Get all .mat files in the folder
files = dir(fullfile(folderPath, '*.mat'));

for i = 1:length(files)
    % Get the filename
    filename = files(i).name;
    
    % Create folder named for each .mat file (without extension)
    folder_name = filename(1:end-4); % Extract name without .mat extension
    folder_fullpath = fullfile(SaveCSVPath, folder_name);
    if ~exist(folder_fullpath, 'dir')
      mkdir(folder_fullpath);
    end
    
    % Load the .mat file
    data = load(fullfile(folderPath, filename));
    
    % Get variable names
    variable_names = fieldnames(data);
    
    % Loop through each variable and export to CSV
    for j = 1:numel(variable_names)
        variable_name = variable_names{j};
        variable_data = data.(variable_name);

               % Handle arrays within fields and cell arrays
            if isstruct(variable_data)
               %%skip if already structed
            elseif iscell(variable_data)
                % Check if all cell elements are numeric or strings
                numericCheck = cellfun(@isnumeric, variable_data);
                stringCheck = cellfun(@ischar, variable_data);
    
                if all(numericCheck(:)) || all(stringCheck(:)) 
                    variable_data = cell2mat(variable_data); % Convert to matrix
                    csv_filename = fullfile(SaveCSVPath, folder_name, [variable_name '.csv']);
                    writetable(variable_data, csv_filename);
                else
                    % Handle complex cell arrays (mixed data types)
                    csv_filename = fullfile(SaveCSVPath, folder_name, [variable_name '.csv']);
                    
                    % Open file for writing
                    fid = fopen(csv_filename, 'w');
                    
                    % Iterate through each cell and write to file
                    for row = 1:size(variable_data, 1)
                        for col = 1:size(variable_data, 2)
                            cell_value = variable_data{row, col};
                            
                           
                            % check if there is array in the cell and save it as a string with commas separating the elements and enclosed in brackets
                            if isnumeric(cell_value) && numel(cell_value) > 1
                                fprintf(fid, '"[%s]",', strjoin(cellstr(num2str(cell_value(:))), ',')); % Write the array enclosed in brackets
                            % Check if cell_value contains a comma
                            elseif ischar(cell_value) && contains(cell_value, ',')
                                fprintf(fid, '"%s",', cell_value); % Write the string enclosed in double quotes

                            % check if data is True and false and save it as 1 and 0
                            elseif islogical(cell_value)
                                fprintf(fid, '"%d",', cell_value); % Write the logical value as 1 or 0
                            else
                                % Format based on data type
                                if isnumeric(cell_value)
                                    fprintf(fid, '"%f",', cell_value);
                                elseif ischar(cell_value)
                                    fprintf(fid, '"%s",', cell_value);
                                else
                                    % Handle other data types as needed
                                    fprintf(fid, '"?",'); % Placeholder for unsupported types
                                end
                            end
                        end
                        fprintf(fid, '\n'); % Newline after each row
                    end
                    
                    fclose(fid); 
                end
            else
                % Handle other data types as needed (e.g., numeric arrays)
                csv_filename = fullfile(SaveCSVPath, folder_name, [variable_name '.csv']);
                writematrix(variable_data, csv_filename); 
            end
    end
end





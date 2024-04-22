% Define the folder path
folder_path = 'D:\github\VirtualHeart&Pacemaker\cases'; 

% Get all .mat files in the folder
files = dir(fullfile(folder_path, '*.mat'));

for i = 1:length(files)
    % Get the filename
    filename = files(i).name;
    
    % Create folder named after the .mat file (without extension)
    folder_name = filename(1:end-4); % Extract name without .mat extension
    folder_fullpath = fullfile(folder_path, folder_name);
    if ~exist(folder_fullpath, 'dir')
      mkdir(folder_fullpath);
    end
    
    % Load the .mat file
    data = load(fullfile(folder_path, filename));
    
    % Get variable names
    variable_names = fieldnames(data);
    
    % Loop through each variable and export to CSV
    for j = 1:numel(variable_names)
        variable_name = variable_names{j};
        variable_data = data.(variable_name);

               % Handle arrays within fields and cell arrays
               if isstruct(variable_data)
                % (Handle structs as needed - code not shown here)
                % You might want to recursively process nested structs
                % and export their fields to separate CSV files or within 
                % the same file using appropriate formatting. 
            elseif iscell(variable_data)
                % Check if all cell elements are numeric or strings
                numericCheck = cellfun(@isnumeric, variable_data);
                stringCheck = cellfun(@ischar, variable_data);
    
                if all(numericCheck(:)) || all(stringCheck(:)) 
                    variable_data = cell2mat(variable_data); % Convert to matrix
                    csv_filename = fullfile(folder_path, folder_name, [variable_name '.csv']);
                    writetable(variable_data, csv_filename);
                else
                    % Handle complex cell arrays (mixed data types)
                    csv_filename = fullfile(folder_path, folder_name, [variable_name '.csv']);
                    
                    % Open file for writing
                    fid = fopen(csv_filename, 'w');
                    
                    % Iterate through each cell and write to file
                    for row = 1:size(variable_data, 1)
                        for col = 1:size(variable_data, 2)
                            cell_value = variable_data{row, col};
                            
                            % Check if cell_value contains a comma
                            if ischar(cell_value) && contains(cell_value, ',')
                                fprintf(fid, '"%s",', cell_value); % Write the string enclosed in double quotes
                            else
                                % Format based on data type
                                if isnumeric(cell_value)
                                    fprintf(fid, '%f,', cell_value);
                                elseif ischar(cell_value)
                                    fprintf(fid, '%s,', cell_value);
                                else
                                    % Handle other data types as needed
                                    fprintf(fid, '?,'); % Placeholder for unsupported types
                                end
                            end
                        end
                        fprintf(fid, '\n'); % Newline after each row
                    end
                    
                    fclose(fid); 
                end
            else
                % Handle other data types as needed (e.g., numeric arrays)
                csv_filename = fullfile(folder_path, folder_name, [variable_name '.csv']);
                writematrix(variable_data, csv_filename); 
            end
    end
end


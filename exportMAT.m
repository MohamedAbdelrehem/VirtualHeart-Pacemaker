%writematrix(egm_table,'egm_table.xlsx','Sheet',1)


 data=load('FileName');
 f=fieldnames(data);
 for k=1:size(f,1)
   writematrix('FileName.xlsx',data.(f{k}),f{k})
 end
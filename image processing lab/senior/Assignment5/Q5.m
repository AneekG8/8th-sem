myFolder = '.\image';
% Check to make sure that folder actually exists.  Warn user if it does not.
if ~isfolder(myFolder)
    errorMessage = sprintf('Error: The following folder does not exist:\n%s\nPlease specify a new folder.', myFolder);
    uiwait(warndlg(errorMessage));
    myFolder = uigetdir(); % Ask for a new one.
    if myFolder == 0
         % User clicked Cancel
         return;
    end
end
% Get a list of all files in the folder with the desired file name pattern.
filePattern = fullfile(myFolder, '*.dat'); % Change to whatever pattern you need.
theFiles = dir(filePattern);
for k = 1 : length(theFiles)
    baseFileName = theFiles(k).name;
    fullFileName = fullfile(theFiles(k).folder, baseFileName);
    fprintf(1, 'Now reading %s\n', fullFileName);
    R = load(fullFileName);
    S = bitcmp(R, 'uint8');
    
    subplot(4,4,k),imshowpair(R,S,'montage'),xlabel(baseFileName);
end

R = load('.\image\l256.dat');
S = bitcmp(R, 'uint8');
FileName = sprintf('negatedImgNot.png');
imwrite(repmat(uint8(S), [1 1 3]), FileName);



R = load('.\image\l256.dat');
L = max(max(R));
S = (L) - R; % should be L-1-R but L-1 is maximum value, so it is maxVal-R
FileName = sprintf('negatedImg.png');
imwrite(repmat(uint8(S), [1 1 3]), FileName);

myFolder = '.\image';
% Check to make sure that folder actually exists.  Warn user if it doesn't.
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
    L = max(max(R));
    S = (L) - R; % should be L-1-R but L-1 is maximum value, so it is maxVal-R

    subplot(4,4,k),imshowpair(R,S,'montage'),xlabel(baseFileName);
end


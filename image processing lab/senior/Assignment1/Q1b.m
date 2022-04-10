R = load('D:\Downloads\image\o256.dat');
S = load('D:\Downloads\image\o256.dat');
th = 128;
R(R<=th) = 0;
FileName = sprintf('thresh128.png');
imwrite(repmat(uint8(R), [1 1 3]), FileName);



myFolder = 'D:\Downloads\image';
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
    S = load(fullFileName);
    th = 128;
    R(R<=th) = 0;

    subplot(4,4,k),imshowpair(S,R,'montage'),xlabel(baseFileName);
end


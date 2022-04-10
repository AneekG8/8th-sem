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
    drawnow; % Force display to update immediately.
    histogram(R, 0:255)
    pause(1)

    B0 = bitget(R,1)*(2^0);
    B1 = bitget(R,2)*(2^1);
    B2 = bitget(R,3)*(2^2);
    B3 = bitget(R,4)*(2^3);
    B4 = bitget(R,5)*(2^4);
    B5 = bitget(R,6)*(2^5);
    B6 = bitget(R,7)*(2^6);
    B7 = bitget(R,8)*(2^7);

    S1 = uint8(B0 + B1 + B2 + B3);
    S2 = uint8(B4 + B5 + B6 + B7);

    binRange = 0:1:255;

    hcx = histcounts(S1,[binRange Inf]);
    pause(1);
    hcy = histcounts(S2,[binRange Inf]);
%     pause(1);
    figure;
    bar(binRange,[hcx;hcy]', 1)
%     pause(2);
end


R = load('.\image\l256.dat');
f=figure;    
h = histogram(R, 0:255);
set(h, {'DisplayName'}, {'Histogram of l256.dat'}')
% Legend will show names for each color
legend()
saveas(f, 'histogram.png');

B0 = bitget(R,1)*(2^0);
B1 = bitget(R,2)*(2^1);
B2 = bitget(R,3)*(2^2);   
B3 = bitget(R,4)*(2^3);    
B4 = bitget(R,5)*(2^4);    
B5 = bitget(R,6)*(2^5);
B6 = bitget(R,7)*(2^6);    
B7 = bitget(R,8)*(2^7);

S1 = uint8(B0 + B1 + B2 + B3);
S2 = uint8(B4 + B5 + B6 + B7);

binRange = 0:1:255;
hcx = histcounts(S1,[binRange Inf]);
pause(1);
hcy = histcounts(S2,[binRange Inf]);
pause(1);
f = figure;
h = bar(binRange,[hcx;hcy]', 1);
set(h, {'DisplayName'}, {'Lower Order Bit Planes','Higher Order Bit Planes'}')
% Legend will show names for each color
legend()
saveas(f, 'modified.png');
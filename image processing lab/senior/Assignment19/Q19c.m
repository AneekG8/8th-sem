R = load('D:\Downloads\image\l256.dat');
S = imrotate(R,60);
f = figure;
imshowpair(R,S,'montage');
saveas(f,'rotation2D60.png');
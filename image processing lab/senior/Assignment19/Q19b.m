R = load('D:\Downloads\image\l256.dat');
S = imrotate(R,45);
f = figure;
imshowpair(R,S,'montage');
saveas(f,'rotation2D45.png');
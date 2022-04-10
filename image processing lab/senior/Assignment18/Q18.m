R = load('.\image\l256.dat');
%S = zeros(364,410);
%for i = 1:256
%   for j = 1:256
%      row = round(i*1.42);
%      col = round(j*1.6);
%      S(row,col) = R(i,j);
%   end
%end
S = imresize(R, [364 410]);
f = figure;
imshowpair(R,S,'montage');
saveas(f,'Scaling2D.png');
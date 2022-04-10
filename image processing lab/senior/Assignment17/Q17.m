R = load('.\image\l256.dat');
S = zeros(256);
for i = 1:256
   for j = 1:256
      row = i-7;
      col = j+5;
      if(row>1 && col<256)
        S(row,col) = R(i,j);
      end
   end
end 
f = figure;
imshowpair(R,S,'montage');
saveas(f,'translation2D.png');
R = load('.\image\l256.dat');
S = uint8(R);
width = 3;
for A = [1,2.5,4.5]
   kernel = ones(width)/(width^2);
   output = conv2(S, kernel);
   output(:,1) = [];
   output(:,257) = [];
   output(1,:) = [];
   output(257,:) = [];
   mask = S - uint8(output);
   final = uint8(S + A * mask);
   figure,imshowpair(R,final,'montage');
   FileName = sprintf('highBoostFilteringk%d.png',A);
   imwrite(repmat(uint8(final), [1 1 3]), FileName);
end    
R = load('.\image\o256.dat');
p = input('Enter the percentage of pixels which have to be noise corrupted: ');
NumofPixels = size(R,1) * size(R,2);
NoisyPixels = round((p*NumofPixels)/100);
q = input('Enter the percentage by which pixels have to be noise corrupted: ');
S = R;
for i = 1:1:NoisyPixels
    row = round(randi([0,255],1,1));
    col = round(randi([0,255],1,1));
    if(i < (NoisyPixels/2))
        S(row+1,col+1) = round(R(row+1,col+1) + round((q*R(row+1,col+1))/100));
    elseif(i >= (NoisyPixels/2))
        S(row+1,col+1) = round(R(row+1,col+1) - round((q*R(row+1,col+1))/100));
    end
end
S = uint8(S);
figure, imshowpair(R,S,'montage');
imwrite(repmat(uint8(S), [1 1 3]), 'SaltandPepperNoiseAdded.png');

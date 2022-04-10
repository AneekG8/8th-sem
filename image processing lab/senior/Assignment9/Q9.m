R = load('.\image\o256.dat');
k = 32;
for i = 1:1:k
    S = cat(i,R);
end
p = 40;
q = 40;
for j = 1:1:k
    S(:,:,j) = R;
        
    NumofPixels = size(R,1) * size(R,2);
    NoisyPixels = round((p*NumofPixels)/100);
        
    for i = 1:1:NoisyPixels
        row = round(255*rand());
        col = round(255*rand());
        S(row+1,col+1,j) = round(R(row+1,col+1) + (q*R(row+1,col+1))/100);
        if(i < (NoisyPixels/2))
            S(row+1,col+1,j) = round(R(row+1,col+1) + (q*R(row+1,col+1))/100);
        elseif(i >= (NoisyPixels/2))
            S(row+1,col+1,j) = round(R(row+1,col+1) - (q*R(row+1,col+1))/100);
        end
    end
    S(:,:,j) = uint8(S(:,:,j));
end
    

for k = [8,16,32]
    output = zeros(256,256);
    for i = 1:1:k
        output = output + S(:,:,i);
    end
    output = round(output/k);
    final = uint8(output - R);
    
    figure,imshowpair(R,output,'montage');
    FileName = sprintf('Average%dimages.png',k);
    imwrite(repmat(uint8(output), [1 1 3]), FileName);
    
    figure,imshowpair(R,final,'montage');
    FileName = sprintf('difference%dimages.png',k);
    imwrite(repmat(uint8(final), [1 1 3]), FileName);
    
    Name = sprintf('histogram%d', k);
    f = figure;
    histogram(final,0:50),title(Name);
    filename = sprintf('differenceHistogram%d.png',k);
    saveas(f,filename);
end
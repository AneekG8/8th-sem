import numpy as np
from PIL import Image

imgArr = np.loadtxt('../../image/b256.dat',dtype=np.uint8)

img = Image.fromarray(imgArr)

img.save('original.png')

a = np.amin(imgArr)

b = np.amax(imgArr)

c = int(input('enter the minimum value of outuput range: '))

d = int(input('enter the maximum value of outuput range: '))

outImgArr = np.uint8((imgArr-a)/(b-a) * (d-c) + c)

outImg = Image.fromarray(outImgArr)

outImg.save('output.png')
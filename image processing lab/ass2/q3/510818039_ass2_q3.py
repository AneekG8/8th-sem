import numpy as np
from PIL import Image

imgArr = np.loadtxt('../../image/b256.dat',dtype=np.uint8)

img = Image.fromarray(imgArr)

img.save('original.png')

negImgArr = ~imgArr

negImg = Image.fromarray(negImgArr)

negImg.save('neg.png')
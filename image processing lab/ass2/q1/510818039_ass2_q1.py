import numpy as np
from PIL import Image

imgArr = np.loadtxt('../../image/b256.dat',dtype=np.uint8)

img = Image.fromarray(imgArr)

img.save('original.png')

negArr1 = np.array(254-imgArr)

negImg1 = Image.fromarray(negArr1)

negImg1.save('neg1.png')

maxGray = np.amax(imgArr)

negArr2 = np.array(maxGray-imgArr)

negImg2 = Image.fromarray(negArr2)

negImg2.save('neg2.png')

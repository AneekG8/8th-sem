from pickletools import uint8
from turtle import down
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

imgArr = np.loadtxt('./image/b256.dat',dtype=np.uint8)

print(imgArr.shape)

img = Image.fromarray(imgArr)

img.save('original.png')

width,height = img.size

down2 = img.resize((int(width/2),int(height/2)))

down2.show()

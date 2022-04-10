from matplotlib.pyplot import axis
import numpy as np
from PIL import Image

imgArr = np.loadtxt('../image/b256.dat',dtype=np.uint8)

img = Image.fromarray(imgArr)

img.save('original.png')

# downsampling to 128,128

downArr2 = imgArr[::2,::2]

np.savetxt('down2.dat',downArr2,fmt='%.0d')

downImg2 = Image.fromarray(downArr2)

downImg2.save('down2.png')

print('downsampled to',downArr2.shape)

# downsampling to 64,64

downArr4 = downArr2[::2,::2]

np.savetxt('down4.dat',downArr4,fmt='%.0d')

downImg4 = Image.fromarray(downArr4)

downImg4.save('down4.png')

print('downsampled to',downArr4.shape)

# upsampling to 128,128

upArr2 = downArr4.repeat(2,axis=0).repeat(2,axis=1)

np.savetxt('up2.dat',upArr2,fmt='%.0d')

upImg2 = Image.fromarray(upArr2)

upImg2.save('up2.png')

print('upsampled to',upArr2.shape)

# upsampling to 256,256

upArr4 = upArr2.repeat(2,axis=0).repeat(2,axis=1)

np.savetxt('up4.dat',upArr4,fmt='%.0d')

upImg4 = Image.fromarray(upArr4)

upImg4.save('up4.png')

print('upsampled to',upArr4.shape)



# USING LINEAR INTERPOLATION

# downsampling to 128,128

downImg2IP = img.resize((128,128),resample=Image.BILINEAR)

downArr2IP = np.array(downImg2IP)

np.savetxt('down2IP.dat',downArr2IP,fmt='%.0d')

downImg2IP.save('down2IP.png')

print('downsampled to',downArr2IP.shape)

# downsampling to 64,64

downImg4IP = downImg2IP.resize((64,64),resample=Image.BILINEAR)

downArr4IP = np.array(downImg4IP)

np.savetxt('down4IP.dat',downArr4IP,fmt='%.0d')

downImg4IP.save('down4IP.png')

print('downsampled to',downArr4IP.shape)

# upsampling to 128,128

upImg2IP = downImg4IP.resize((128,128),resample=Image.BILINEAR)

upArr2IP = np.array(upImg2IP)

np.savetxt('up2IP.dat',upArr2IP,fmt='%.0d')

upImg2IP.save('up2IP.png')

print('upsampled to',upArr2IP.shape)

# upsampling to 256,256

upImg4IP = upImg2IP.resize((256,256),resample=Image.BILINEAR)

upArr4IP = np.array(upImg4IP)

np.savetxt('up2IP.dat',upArr4IP,fmt='%.0d')

upImg4IP.save('up4IP.png')

print('upsampled to',upArr4IP.shape)

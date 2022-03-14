#import os
#os.environ["TF_CPP_MIN_LOG_LEVEL"] = '2'

from unittest import result
import tensorflow as tf
from six import BytesIO
from PIL import Image
#import numpy as np

def load_image(path):
  image = None
  image_data = tf.io.gfile.GFile(path, 'rb').read()
  image = Image.open(BytesIO(image_data))
  (im_width, im_height) = image.size
  return tf.experimental.numpy.uint8(image.getdata()).reshape(
      (1, im_height, im_width, 3))


# Run model on image
image_np = load_image("./lenna.jpg")
detector = tf.saved_model.load('./model')

results = detector(image_np)

print(results)

# Salvando resultado
#np.savetxt("/tmp/t2/out.csv", result, fmt='%u', delimiter='\n')
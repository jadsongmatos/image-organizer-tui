import sys
import torch

print(f"Path : {sys.argv[1]}")

# Model
model = torch.hub.load('ultralytics/yolov5', 'yolov5x6', pretrained=True)

# Inference
results = model(sys.argv[1])

data = results.pandas().xyxy[0]
print(data)

data.to_json("/tmp/result.json")
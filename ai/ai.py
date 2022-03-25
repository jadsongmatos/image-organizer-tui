import sys
import torch
from http.server import BaseHTTPRequestHandler, HTTPServer
import time
from urllib.parse import unquote

hostName = "localhost"
serverPort = 8080

class MyServer(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        # Model
        print(f"Path : {unquote(self.path)}")
        model = torch.hub.load('ultralytics/yolov5', 'yolov5x6', pretrained=True)
        # Inference
        results = model(unquote(self.path))
        data = results.pandas().xyxy[0]
        self.wfile.write(bytes(data.to_json(orient = 'columns'), "utf-8"))


if __name__ == "__main__":
    webServer = HTTPServer((hostName, serverPort), MyServer)
    print("Server started http://%s:%s" % (hostName, serverPort))

    try:
        webServer.serve_forever()
    except KeyboardInterrupt:
        pass

    webServer.server_close()
    print("Server stopped.")

"""
print(f"Path : {sys.argv[1]}")

# Model
model = torch.hub.load('ultralytics/yolov5', 'yolov5x6', pretrained=True)

# Inference
results = model(sys.argv[1])

data = results.pandas().xyxy[0]
print(data)

data.to_json("/tmp/result.json")
"""

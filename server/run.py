from http.server import HTTPServer, CGIHTTPRequestHandler
import socket 

if len(socket.gethostbyname_ex(socket.gethostname())[2]) > 1:
    print("Сервер запущений на адресі: %s"%socket.gethostbyname_ex(socket.gethostname())[2][1]) 
server_address = ("", 80) 
httpd = HTTPServer(server_address, CGIHTTPRequestHandler) 
httpd.serve_forever() 

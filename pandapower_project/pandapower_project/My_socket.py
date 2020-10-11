import socket
class My_socket:
    sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    def __init__(self):
        pass
    def send(self, str, ip, port):
        self.sock.sendto(str.encode(), ( ip , port ))


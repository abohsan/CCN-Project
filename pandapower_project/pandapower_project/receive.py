import socket

UDP_IP = "192.168.1.246"
UDP_PORT = 5005
count = 0
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
sock.bind ((UDP_IP,UDP_PORT))

while True:
	count += 1
	data, addr = sock.recvfrom(1024)
	print ("Received message", count,":" , data.decode())

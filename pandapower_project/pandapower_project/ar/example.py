import socket
import time

TARGET_IP_80 = "192.168.5.180"
TARGET_IP_78 = "192.168.5.178"

UDP_PORT_80 = 5005
UDP_PORT_78 = UDP_PORT_80

MESSAGE_80 = "Hello 192.168.5.180"
MESSAGE_78 = "Hello 192.168.5.178"

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

while True:
    sock.sendto(MESSAGE_80.encode(), (TARGET_IP_80, UDP_PORT_80))
    sock.sendto(MESSAGE_78.encode(), (TARGET_IP_78, UDP_PORT_78))
    time.sleep(1)

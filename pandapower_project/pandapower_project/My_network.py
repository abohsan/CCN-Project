from My_socket import My_socket

class My_network:
    socket = My_socket()
    IPs = []
    ports = []

    
    def __init__(self):
        self.appand_device("192.168.5.180",5005)
        self.appand_device("192.168.5.178",5005)
        # self.appand_device("192.168.5.185",5005)

    def appand_device(self, ip , port):
        self.IPs.append(ip)
        self.ports.append(port)

    def print_All_Devices(self):
        port = iter(self.ports)
        for IP in self.IPs:
            print(IP, next(port))
    
    def number_of_devices(self):
        print(len(self.IPs))
    
    def send_to_all(self,str):
        port = iter(self.ports)
        for IP in self.IPs:
            self.socket.send(str,IP, next(port))
        




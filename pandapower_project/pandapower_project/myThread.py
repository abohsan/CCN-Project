import threading
import time

from My_pandapower import My_pandapower

class myThread (threading.Thread):
    pow = My_pandapower()
    exitFlag = 0

    def __init__(self, threadID, name, counter):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
    def run(self):
        print ("Starting " + self.name)
        self.print_time()
        print ("Exiting " + self.name)
    
    def print_time(self):
        self.pow.runn()
        while True:
            self.pow.send_buses_vn_kv()
            time.sleep(0.5)
from operator import itemgetter
import numpy as np
from SJF import SJF
class com:
    data = []
    sjf = ''
    num = 0
    max_Arrival = 3
    min_Arrival = 0
    
    max_burstTime = 2
    min_burstTime = 1
    
    waitingTime_Array = []
    turnAroundTime_Array = []

    def __init__(self, num):
        self.num = num

    def creatObj(self):
        self.sjf = SJF(self.data,len(self.data) )

    def Cal(self):
        for i in range(1,self.num +1):
            self.setData(i)
            self.creatObj()
            self.getData()
        print(self.waitingTime_Array)
    
    def setData(self, num):
        packet_ID = np.arange(1,num + 1)
        Arrival_Time = np.random.randint(self.min_Arrival,self.max_Arrival, size=num)
        Burst_Time = np.random.randint(self.min_burstTime,self.max_burstTime, size=num)
        col3 = np.zeros(num)
        data = []
        data.append(packet_ID)
        data.append(Arrival_Time)
        data.append(Burst_Time)
        data.append(col3)
        data.append(col3)
        data.append(col3)
        self.data = np.transpose(data)


    def getData(self):
        self.waitingTime_Array.append(self.sjf.getWaitingTimeAverage())
        self.turnAroundTime_Array.append(self.sjf.getTurnAroundAverage())
        
    def testData(self):
        self.num = 10
        packet_ID = [1,2,3,4,5,6,7,8,9,10]
        Arrival_Time = [2,0,1,1,4,1,3,3,2,5]
        Burst_Time = [3,2,5,9,14,8,12,1,6,4]
        col3 = np.zeros(self.num)
        data = []
        data.append(packet_ID)
        data.append(Arrival_Time)
        data.append(Burst_Time)
        data.append(col3)
        data.append(col3)
        data.append(col3)
        self.data = np.transpose(data)

    def printMain(self):
        print(self.sjf.getWaitingTimeAverage())
        print(self.sjf.getTurnAroundAverage())

        
   

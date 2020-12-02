from operator import itemgetter
import numpy as np

class SJF:
    data =  []  
    num = 0

    def __init__(self,data, num):
        self.num = num
        self.data = data.tolist()
        self.arrangeArrivalAndBurst()
        self.completionTime()

    def arrangeArrivalAndBurst(self):
        self.data.sort(key=lambda x: (x[1], x[2]))

    def printt(self):
        print("Start Printing")
        for x in self.data:
            print(x)
        print("End Printing")

    def getWaitingTimeAverage(self):
        self.data = np.asarray(self.data)
        theMean = self.data[:,4].mean()
        self.data = self.data.tolist()
        return theMean

    def getTurnAroundAverage(self):
        self.data = np.asarray(self.data)
        theMean = self.data[:,5].mean()
        self.data = self.data.tolist()
        return theMean

    def completionTime(self):
        temp = 0
        val = 0
        self.data[0][3] = self.data[0][1] + self.data[0][2] 
        self.data[0][5] = self.data[0][3] - self.data[0][1]
        self.data[0][4] = self.data[0][5] - self.data[0][2]
        
        for i in range(self.num):
            temp = self.data[i-1][3] #compilation_time_1
            low = self.data[i][2] # burst
            for j in range(i,self.num):
                if temp >= self.data[j][1] and low >= self.data[j][2]:
                    low = self.data[j][2]
                    val = j 
            self.data[val][3]        =          temp       +    self.data[val][2]
            self.data[val][5] = self.data[val][3] - self.data[val][1] 
            self.data[val][4] = self.data[val][5] - self.data[val][2]
            
            self.data = np.asarray(self.data)

            self.data[[val, i]] = self.data[[i, val]]
            self.data = self.data.tolist()



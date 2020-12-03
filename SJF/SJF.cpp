// C++ program to implement Shortest Job first with Arrival Time 
#include<iostream> 
using namespace std;
//A 2d array is created to store the needed information.
// Each row will have a packet info 
//whereas colunms are Packet ID, Arrival Time, Burst Time, Waiting Time and Turnaround Time
int packetArray[10][6]; 


// swap method is used two rows when the array sorted based on the arrival time.
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

// iterating throght column 1, Arrival time, and sort them from increaing order.
void arrangeBasedOnArrivalTime(int numOfPacket, int packetArray[][6]) 
{ 
    for(int i=0; i<numOfPacket; i++) // iterating through packets ,Rows.
    { 
        for(int j=0; j<numOfPacket-i-1; j++) // iterating through arrival time ,columns.
        { 
            //comparing arrival time in row J with row J+1
            if(packetArray[j][1] > packetArray[j+1][1])  // IF arrival time in row j bigger than in row j+1,  swap them
            { 
                for(int k=0; k<5; k++) 
                { 
                    swap(packetArray[j][k], packetArray[j+1][k]); 
                } 
            } 
        } 
    } 
} 
  
void calculatCompletionTime(int numOfPacket, int packetArray[][6]) 
{ 
    
    // a = arrival time
    // b = Burst
    // w = waiting time, W = t - b
    // t = turnarround time, t = b + w 
    // compilation time = a + b + w

    int temp, val; 
    // Frist processed packet will have zero waiting time.
    // therefore, there is no need to include it in this step
    //a+b+w      // a     +    b      +    w 
    packetArray[0][3] = packetArray[0][1] + packetArray[0][2] ;   
    // t      =   a+b+w   -     a
    packetArray[0][5] = packetArray[0][3] - packetArray[0][1];  
    // w      =      t    -        b
    packetArray[0][4] = packetArray[0][5] - packetArray[0][2]; 
    
    for(int i=1; i<numOfPacket; i++) // numOfPacket is the count of Packets
    { 
        temp = packetArray[i-1][3];  // compilation_time at i
        int low = packetArray[i][2]; // burst time at i
        for(int j=i; j<numOfPacket; j++)  // assume i = 2, therefore j = 2..numOfPacket
        { // (comlilation at i) >= (a at j ) && (b at i )  >= ( b at j)    
                if(temp >= packetArray[j][1] && low >= packetArray[j][2]) 
                { 
                    low = packetArray[j][2]; 
                    val = j;  // val = 10
                } 
        } 
       //(compilation_time at val)   = (compilation_time at i)  +    (burst at val)
        packetArray[val][3]        =          temp       +    packetArray[val][2]; 
       // t at val      = (com_time at val) - (a at val )
        packetArray[val][5] = packetArray[val][3] - packetArray[val][1]; 
       // (w at val)  = (t at val ) -  (b at val)
        packetArray[val][4] = packetArray[val][5] - packetArray[val][2]; 
        for(int k=0; k<6; k++) 
        { 
            swap(packetArray[val][k], packetArray[i][k]); 
        } 
    } 
} 
  
int main() 
{ 
    int numOfPacket, temp; 
      
    cout<<"Enter number of Packet: "; 
    cin>>numOfPacket; 
    
    cout<<"...Enter the Packet ID...\n"; 
    for(int i=0; i<numOfPacket; i++) 
    { 
        cout<<"...Packet "<<i+1<<"...\n"; 
        cout<<"Enter Packet Id: "; 
        cin>>packetArray[i][0]; 
        cout<<"Enter Arrival Time: "; 
        cin>>packetArray[i][1]; 
        cout<<"Enter Burst Time: "; 
        cin>>packetArray[i][2]; 
    } 
      
    cout<<"Before Arrange...\n"; 
    cout<<"Packet ID\tArrival Time\tBurst Time\n"; 
    for(int i=0; i<numOfPacket; i++) 
    { 
        cout<<packetArray[i][0]<<"\t\t"<<packetArray[i][1]<<"\t\t"<<packetArray[i][2]<<"\n"; 
    } 
      
    arrangeBasedOnArrivalTime(numOfPacket, packetArray); 
    calculatCompletionTime(numOfPacket, packetArray); 
    cout<<"Final Result...\n"; 
    cout<<"Packet ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n"; 
    
    for(int i=0; i<numOfPacket; i++) 
    { 
        cout<<packetArray[i][0]<<"\t\t"<<packetArray[i][1]<<"\t\t"<<packetArray[i][2]<<"\t\t"<<packetArray[i][4]<<"\t\t"<<packetArray[i][5]<<"\n"; 
    } 
}
// C++ program to implement Shortest Job first with Arrival Time 
#include<iostream> 
using namespace std;
//A 2d array is created to store the need it information.
// Each row will have a packet info 
//whereas colunms are Packet ID, Arrival Time, Burst Time, Waiting Time and Turnaround Time
int mat[10][6]; 


// swap method is used two rows when the array sorted based on the arrival time.
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

// iterating throght column 1, Arrival time, and sort them from increaing order.
void arrangeArrival(int num, int mat[][6]) 
{ 
    for(int i=0; i<num; i++) // iterating through packets ,Rows.
    { 
        for(int j=0; j<num-i-1; j++) // iterating through arrival time ,columns.
        { 
            //comparing arrival time in row J with row J+1
            if(mat[j][1] > mat[j+1][1])  // IF arrival time in row j bigger than in row j+1,  swap them
            { 
                for(int k=0; k<5; k++) 
                { 
                    swap(mat[j][k], mat[j+1][k]); 
                } 
            } 
        } 
    } 
} 
  
void completionTime(int num, int mat[][6]) 
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
    mat[0][3] = mat[0][1] + mat[0][2] ;    // Adding the 
    // t      =   a+b+w   -     a
    mat[0][5] = mat[0][3] - mat[0][1];  
    // w      =      t    -        b
    mat[0][4] = mat[0][5] - mat[0][2]; 
    
    for(int i=1; i<num; i++) // num is the number of Packets
    { 
        temp = mat[i-1][3];  // compilation_time at i
        int low = mat[i][2]; // burst time at i
        for(int j=i; j<num; j++)  // assume i = 2, therefore j = 2..num
        { // (comlilation at i) >= (a at j ) && (b at i )  >= ( b at j)    
                if(temp >= mat[j][1] && low >= mat[j][2]) 
                { 
                    low = mat[j][2]; 
                    val = j;  // val = 10
                } 
        } 
       //(compilation_time at val)   = (compilation_time at i)  +    (burst at val)
        mat[val][3]        =          temp       +    mat[val][2]; 
       // t at val      = (com_time at val) - (a at val )
        mat[val][5] = mat[val][3] - mat[val][1]; 
       // (w at val)  = (t at val ) -  (b at val)
        mat[val][4] = mat[val][5] - mat[val][2]; 
        for(int k=0; k<6; k++) 
        { 
            swap(mat[val][k], mat[i][k]); 
        } 
    } 
} 
  
int main() 
{ 
    int num, temp; 
      
    cout<<"Enter number of Packet: "; 
    cin>>num; 
    
    cout<<"...Enter the Packet ID...\n"; 
    for(int i=0; i<num; i++) 
    { 
        cout<<"...Packet "<<i+1<<"...\n"; 
        cout<<"Enter Packet Id: "; 
        cin>>mat[i][0]; 
        cout<<"Enter Arrival Time: "; 
        cin>>mat[i][1]; 
        cout<<"Enter Burst Time: "; 
        cin>>mat[i][2]; 
    } 
      
    cout<<"Before Arrange...\n"; 
    cout<<"Packet ID\tArrival Time\tBurst Time\n"; 
    for(int i=0; i<num; i++) 
    { 
        cout<<mat[i][0]<<"\t\t"<<mat[i][1]<<"\t\t"<<mat[i][2]<<"\n"; 
    } 
      
    arrangeArrival(num, mat); 
    completionTime(num, mat); 
    cout<<"Final Result...\n"; 
    cout<<"Packet ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n"; 
    
    for(int i=0; i<num; i++) 
    { 
        cout<<mat[i][0]<<"\t\t"<<mat[i][1]<<"\t\t"<<mat[i][2]<<"\t\t"<<mat[i][4]<<"\t\t"<<mat[i][5]<<"\n"; 
    } 
}
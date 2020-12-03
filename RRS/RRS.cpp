
#include<iostream> 
using namespace std; 

int numOfPacket ; // number of packet
int quantumTime ; // Time quantum / time slot
int totalWaitingTime = 0; // the Total waiting time
int totalTurnAroundTime = 0;// the Total turn around time
// Function to find the waiting time for all 
// packet_id 
void calculateTheWaitingTime(int packet_id[],  
			int burstTime[], int waitingTime[]) 
{ 
	// Make a copy of burst times to store remaining burst times. 
	int remainingBurstTime[numOfPacket];
	for (int i = 0 ; i < numOfPacket ; i++) 
		remainingBurstTime[i] = burstTime[i]; 

	int currentTime = 0; // Current time 
	// Keep itrating through packet_id in round robin manner 
	// if all of the are done, raise a flag. 
	while (1) 
	{ 
		bool Flag = true; 
		// Traverse all packet_id one by one repeatedly 
		for (int i = 0 ; i < numOfPacket; i++) 
		{ 
			// If burst time of a packet is not zero 
			// then process the packet 
			if (remainingBurstTime[i] > 0) 
			{ 
				Flag = false; // There is a pending process 

				//if the burst time is greater than the quntum time
				// then it will use all the given time, quntum time.
				if (remainingBurstTime[i] > quantumTime) 
				{ 
					//Add up the quantum time to the current time
					currentTime += quantumTime; 
					//subtract the quantum time from the burst time
					//and save the remainder
					remainingBurstTime[i] -= quantumTime; 
				} 
				// else the quantum is greater or equal to the burst time.
				// therefore, it will be the last iteration
				else
				{
					// Add the brust time of the target packet to the 
					// current time.
					currentTime = currentTime + remainingBurstTime[i]; 
					// used by this process
					//subtracting the burst time from the current time give the waiting time 
					waitingTime[i] = currentTime - burstTime[i]; 
					
					//since the burst time is less than the quantumTime,
					// the packet will be excuted completely then set the burst time to zero.
					remainingBurstTime[i] = 0; 
				} 
			} 
		} 
		// If all packets are done 
		if (Flag == true) 
		break; 
	} 
} 

// Function to calculate turn around time 
void calculateTurnAroundTime(int packet_id[],  
						int burstTime[], int waitingTime[], int tat[]) 
{ 
	// calculating turnaround time by adding 
	// burstTime[i] + waitingTime[i] 
	for (int i = 0; i < numOfPacket ; i++) 
		tat[i] = burstTime[i] + waitingTime[i]; 
} 

void displayPacket(int waitingTime[],int tat[], int burstTime[]){
	// Display packets along with all its details 
	cout << "packet_id "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 

	// Calculate total waiting time and total turn around time 
	for (int i=0; i<numOfPacket; i++) 
	{ 
		totalWaitingTime = totalWaitingTime + waitingTime[i]; 
		totalTurnAroundTime = totalTurnAroundTime + tat[i]; 
		cout << " " << i+1 << "\t\t" << burstTime[i] <<"\t "
			<< waitingTime[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< (float)totalWaitingTime / (float)numOfPacket; 
	cout << "\nAverage turn around time = "
		<< (float)totalTurnAroundTime / (float)numOfPacket; 

}

// Function to calculate the Average Time 
void calculateTheAverageTime(int packet_id[], int numOfPacket, int burstTime[]) 
{ 
	int waitingTime[numOfPacket], turnAroundTime[numOfPacket] ; 

	// Finding the waiting time of all packets 
	calculateTheWaitingTime(packet_id,  burstTime, waitingTime); 

	// Finding turn around time for all packets
	calculateTurnAroundTime(packet_id,  burstTime, waitingTime, turnAroundTime); 

	// Display packets along with all details 
	displayPacket( waitingTime, turnAroundTime, burstTime);
} 

int main() 
{ 
	// Packet id's 
	int packet_id[] = { 1,2,3,4,5,6,7,8,9,10}; 

	numOfPacket = sizeof packet_id / sizeof packet_id[0]; 
	
	// Burst time of all packets 
	int burstTime[] = {3,2,5,9,14,8,12,1,6,4}; 

	// Time quantum / time slot
	quantumTime = 1; 
	cout << "quantum = " << quantumTime << endl;
	calculateTheAverageTime(packet_id, numOfPacket, burstTime); 
	return 0; 
} 

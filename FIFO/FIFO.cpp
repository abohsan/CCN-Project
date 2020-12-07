
#include <iostream>
using namespace std;
int numOfPacket = 0;		 // number of packet
int totalWaitingTime = 0;	 // the Total waiting time
int totalTurnAroundTime = 0; // the Total turn around time
// Function to find the waiting time for all
// packetArray calculateTheAverageTime
void calculateTheWaitingTime(int packetArray[], int bt[], int wt[])
{ // waiting time for first process is 0
	wt[0] = 0;
	// calculating waiting time
	for (int i = 1; i < numOfPacket; i++)
		wt[i] = bt[i - 1] + wt[i - 1];
}
// Function to calculate turn around time
void calculateTheTurnAroundTime(int packetArray[], int burstTime[], int waitingTime[], int turnAroundTime[])
{
	// calculating turnaround time by adding
	// burstTime[i] + waitingTime[i]
	for (int i = 0; i < numOfPacket; i++)
		turnAroundTime[i] = burstTime[i] + waitingTime[i];
}
void displayPacket(int waitingTime[], int turnAroundTime[], int burstTime[])
{
	// Display packets along with all details
	cout << "packetArray "
		 << " Burst time "
		 << " Waiting time "
		 << " Turn around time\n";
	// Calculate total waiting time and total turn
	// around time
	for (int i = 0; i < numOfPacket; i++)
	{
		totalWaitingTime = totalWaitingTime + waitingTime[i];
		totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];
		cout << " " << i + 1 << "\t\t" << burstTime[i] << "\t "
			 << waitingTime[i] << "\t\t " << turnAroundTime[i] << endl;
	}
	cout << "Average waiting time = "
		 << (float)totalWaitingTime / (float)numOfPacket;
	cout << "\nAverage turn around time = "
		 << (float)totalTurnAroundTime / (float)numOfPacket;
}
//Function to calculate average time
void calculateTheAverageTime(int packetArray[], int burstTime[])
{
	int waitingTime[numOfPacket], turnAroundTime[numOfPacket];
	//Function to find waiting time of all packetArray
	calculateTheWaitingTime(packetArray, burstTime, waitingTime);
	//Function to find turn around time for all packetArray
	calculateTheTurnAroundTime(packetArray, burstTime, waitingTime, turnAroundTime);
	// Display packets along with all details
	displayPacket(waitingTime, turnAroundTime, burstTime);
}
// Driver code
int main()
{
	//packet id's
	int packetArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	numOfPacket = sizeof packetArray / sizeof packetArray[0];
	//Burst time of all packetArray 1,4,6,7,
	int burst_time[] = {3, 2, 5, 9, 14, 8, 12, 1, 6, 4};
	calculateTheAverageTime(packetArray, burst_time);
	return 0;
}

//combination of both positive and negative bead sort (with zeros)
//positive bead sort = O(1/2n) where n is the sumation of all positive integers
//negative bead sort = O(1/2|n|) where n is the absolute value of the summation of all negative integers
//count zeros and insert = O(z) where z is number of zeros
//so all in all, the bead sort is still (O(S) where is is the summation of negative and positive bead sort algorithms
//space complexity is now O(5n) where 1 array is set and the others are expandable. if lists were used, it could
//probably be faster and better for insertion later but since I am only proving correctness, this will do.
//As seen here: http://rosettacode.org/wiki/User_talk:MichaelChrisco#Bead_sort:_a_Unique_Solution



//By Michael Chrisco 
// michaelachrisco@gmail.com


#include<iostream>
#include<vector>
using namespace std;

void distribute_neg( int dist, vector<int> &List)//in theory makes *beads* go down into different buckets using gravity. 
{
	dist=-dist; //resets to positive number for implamentation 
	
	if (dist > List.size() ) 
		List.resize(dist,0);//can be done differently but *meh*
	
	
	
	for (int i=0; i < dist; i++)
		List[i]=List[i]-1;	
		
} 
//end of distribute negative

void distribute_pos( int dist, vector<int> &List)//in theory makes *beads* go down into different buckets using gravity. 
{
	
	
	if (dist > List.size() ) 
		List.resize(dist,0);//can be done differently but *meh*
	
	
	
	for (int i=0; i < dist; i++)
		List[i]=List[i]+1;	
		
	
} 
//end of distribute positive
void sort(vector<int> &List){
	int i;
	int zeros=0;
	vector<int> list;
	vector<int> list_pos;
	vector<int> sorted;
	vector<int> sorted_pos;
	cout << "#1 Beads falling down: ";
	for (i=0; i < List.size(); i++)
		if (List[i] < 0) 
			distribute_neg (List[i], list);
			else if (List[i] > 0) 
				distribute_pos(List[i], list_pos);
				else 
					zeros++;
		
	
	cout << endl;
	
	cout <<endl<< "Beads on their sides: ";
	for (i=0; i < list.size(); i++)
		cout << " " << list[i];
	cout << endl;	
	
	cout <<endl<< "Beads on their sides positive: ";
	for (i=0; i < list_pos.size(); i++)
		cout << " " << list_pos[i];
	cout << endl;
	//second part	
	
	cout << "#2 Beads right side up: ";
	for (i=0; i < list.size(); i++)
		distribute_neg (list[i], sorted);
	
	for (i=0; i < list_pos.size(); i++)
		distribute_pos(list_pos[i], sorted_pos);
	cout << endl;

	cout << endl;
	
	
	cout <<endl<< "Sorted list/array neg";
	for (i=0; i < sorted.size(); i++)
		cout << " " << sorted[i];
	cout << endl;
	
	cout <<endl<< "Sorted list/array pos";
	for (i=0; i < sorted_pos.size(); i++)
		cout << " " << sorted_pos[i];
	cout << endl;
	
	//combine two at end. 
	//In theory, a list for both positive and negative structures would give better performance at the end, combining the
	//two lists in O(1) time. You may chose to do so if you wish. The same goes with zeros. 

	
	
	while (zeros > 0)
	{
		sorted_pos.push_back(0);
		zeros--;
	}
		
	i=sorted.size()-1;	
	while (i >= 0) {
		sorted_pos.push_back(sorted[i]);
		i--;
	}

	cout <<endl<< "Sorted list/array";
	for (i=0; i < sorted_pos.size(); i++)
		cout << " " << sorted_pos[i];
	cout << endl;
	

}


int main(){
	int myints[] = {-1, -4, -3, 1, 4, 3, 0};
	vector<int> here_be_dragons (myints, myints + sizeof(myints) / sizeof(int) );
	
	sort(here_be_dragons);
	
	
	
	return 0;
	
}




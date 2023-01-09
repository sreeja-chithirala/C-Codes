/*
There are N teams participating in a knockout tournament (where if a team loses a game, then it is out of the tournament). Each team is assigned an ID. In this tournament, the ID of the first team is 1, second team is 2, and so on till upto N. The strength of each team is decided by the strength that it contains in the following units:
Batting
Bowling
Fielding
All-rounder's performance
Captain's performance
 Now, a team can win against another team if it can win at least 3 units. If a team's strength in a specific unit is higher than the other team, then the former team wins that specific unit. In case, the strength of both teams are the same in a specific unit, then the team that contains the lower team ID wins that unit.
The fixture of the tournament is decided as follows:
  In each round, among the remaining teams, the team that is assigned the lowest team ID plays with the team that contains the next lowest team ID. For example, the team that contains the 3rd lowest ID plays with the team that is assigned the 4th lowest ID and so on.


Write a C++ program using functions that determines the winning team of the tournament and print its respective team ID.

Sample Input: 
Number of teams participating in the tournament: 4
Individual team statistic/performance: 

Team 1: 1 2 3 4 5
Team 2: 2 4 5 6 7
Team 3: 1 2 3 4 5
Team 4: 1 4 2 2 3

Output: 
The winner is Team 2

*/

#include<iostream>

using namespace std;

int main()
{
	int num,k;      //'num' stores the no of teams participating in the tournament

	cout << "Enter the number of teams in the tournament: ";
	cin >> num;
	cout << "Enter the points for each of the " << num << " teams in these units:\n";
	cout << "- Batting\n- Bowling\n- Fielding\n- All-rounder's performance\n- Captain's performance\n";
	
	k=num;       //since 'num' gets modified later no we will store that in another variable 'k'.
	int A[num][5],B[(2*num)-1],i,j;  
	// A is the two dimentional matrix which has 'num' rows and 5 columns(as 5 units)
	//B is the array which first stores the teams to be played and then continues storing the teams that won the matches.
	//for a tornament of 4 teams  B will be of the form  |0|1|2|3|(0 or 1)|(2 or 3)|final winner|
	//since there will 2*num-1 mataches for num teams
	
	
	for(i=0;i<num;i++)              //this loop will take the points of each team
	{
		cout << "Team " << i+1 << ": ";
		for(j=0;j<5;j++)
		{
			cin >> A[i][j];
		}
		B[i]=i;                    //simultaneously stores the team numbers in array B
	}
	
    int c1=0;        //these c1,c2 variables are used to used to count the number of units each team won
	int c2=0;
	int n=0;        //n is used to access the values in the array B 

	for(i=0;i<k-1;i++)              //this loop will execute 'k'(no of matches) times .The variable i keeps count of it.
	{
	    for(j=0;j<5;j++)                       //this loop compares the units of two teams
	    {
		    if(A[B[n+1]][j] > A[B[n]][j])        //ex: if in a unit team 1 has more points than team 0 then c2 is incremented  or else if team 0 has more points than team 1 or both have equal points the c1 is incremented
		    {
			    c2++;
		    }
		    else 
		    {
			    c1++;
		    }
			
			
			
			if(c1==3 || c2==3)         //if any of the c1 or c2 gets  points the loop  breaks
			{
				break;	
			}	
	    }
	  
		 
	    if(c1>c2)                //basing on which team gets more points, the next index('num' keeps the note of it) in B stores that team's number.
	    {
		    B[num] = B[n];
	    }
	    else
	    {
	    	B[num] = B[n+1];
		}
		
	    n=n+2;    //Now n is incremented by 2 to compare the next two teams in the B array
	    num++;    //num is incremented to store the next team number that wins in the comparison
	    c1=0;     //c1 and c2 are again updated to 0 for the next teams
	    c2=0; 
	    
    }
    
    
	cout <<"Team " << B[num-1]+1 << " is the winner";   //since the final index of B array stores the final winner we will display it .
	
	return 0;
}

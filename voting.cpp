#include<iostream>
using namespace std;

class candidate   //class candidate stores the information of  every candidate
{
	public:
	    int no_votes;       //stores the number of candidates voted by the object of class 
	    float rank[10];     //rank array stores the rank of the candidate after each iteration
		//    rank|initial rank|after iteration 1|after 2|after 3|.........  
};

int main()
{
	float B[7],A[7],key;    //A and B arrays stores the rank of each candidate after k iterations
	int num,i,j,c,k;
	//details of each candidate in the voting process
	cout << "In the voting process,\n";        
	cout << "Contestant 1 voted to: 2,3\n";
	cout << "And got voted by 3\n";
	cout << "Contestant 2 voted to: Nil\n";
	cout << "And got voted by 1,3\n";
	cout << "Contestant 3 voted to: 1,2,5\n";
	cout << "And got voted by 1\n";
	cout << "Contestant 4 voted to: 5,6\n";
	cout << "And got voted by 5,6\n";
	cout << "Contestant 5 voted to: 4,6\n";
	cout << "And got voted by 3,4\n";
	cout << "Contestant 6 voted to: 4\n";
	cout << "And got voted by 4,5\n";
	
	//contestant 1
	candidate p1;
	p1.no_votes=2;
	p1.rank[0]=100000/6;
	
	//contestant 2
	candidate p2;
	p2.no_votes=0;
	p2.rank[0]=100000/6;
	
	//contestant 3
	candidate p3;
	p3.no_votes=3;
	p3.rank[0]=100000/6;
	
	//contestant 4
	candidate p4;
	p4.no_votes=2;
	p4.rank[0]=100000/6;
	
	//contestant 5
	candidate p5;
	p5.no_votes=2;
	p5.rank[0]=100000/6;
	
	//contestant 6
	candidate p6;
	p6.no_votes=1;
	p6.rank[0]=100000/6;
	
	
	cout << "How many top candidates of the voting result do you want: ";
	cin >> c;
	cout << "After how many iterations you want to find the top candidates: ";
	cin >> k;
	
	//According to the problem ,    rank(A) = summataion of all the terms.
	//term is  (previous iteration rank of B who voted to A) / (total no of votes by B )
	//B's are the candidates who voted to A.
     
	for(i=1;i<=k;i++)
	{
		//calculates the rank of each candidate at each iteration
	   p1.rank[i]=(p3.rank[i-1])/(p3.no_votes);
	   if(i==k)   //At kth iteration rank is copied into the arrays
	       B[1]=A[1]=p1.rank[i];
	   p2.rank[i]=(p1.rank[i-1])/(p1.no_votes) +(p3.rank[i-1])/(p3.no_votes);
	   if(i==k)
	       B[2]=A[2]=p2.rank[i];
	   p3.rank[i]=(p1.rank[i-1])/(p1.no_votes);
	   if(i==k)
	       B[3]=A[3]=p3.rank[i];
	   p4.rank[i]=(p5.rank[i-1])/(p5.no_votes) + (p6.rank[i-1])/(p6.no_votes);
	   if(i==k)
	       B[4]=A[4]=p4.rank[i];
	   p5.rank[i]=(p3.rank[i-1])/(p3.no_votes) + (p4.rank[i-1])/(p4.no_votes);
	   if(i==k)
	       B[5]=A[5]=p5.rank[i];
	   p6.rank[i]=(p4.rank[i-1])/(p4.no_votes) + (p5.rank[i-1])/(p5.no_votes);
	   if(i==k)
	       B[6]=A[6]=p6.rank[i];
    }
    
    for(j=1;j<=6;j++)   //the values in the array A is sorted using insertion sort algorithm
	{
		key=A[j];
		i=j-1;
		while(i>=0 && A[i]>=key)
		{
			A[i+1]=A[i];
			i--;
		}
		A[i+1]=key;
	}

	int l=7;
	for(i=1;i<=c;i++)  
	{
		l--;
		for(j=1;j<=6;j++)   //Now the top rank value is present at A[6] ,next one at A[5] ,next one .......
		{
			if(A[l]==B[j])    //since the arrays both have same values the top 1 element is searched in the B array and printed.
			{
				cout << "Top " << i << " contestant is " << j << "\n";
				break;
			}
		}
	}
    
}

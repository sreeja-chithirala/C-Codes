/*
Given two matrix M and N, use function overloading and operator overloading to perform the following operations:
1.      M+N
2.      M-N 
3.      Transpose(M)
4.      M*N
5.      Inverse(M)
6.      Rank(M)
*/

#include<iostream>
using namespace std;

class matrix                         //class definiton
{
	public:
		float arr[3][3];
		matrix(){	}              //default constructor
		matrix(char name)          //parametrised constructor
		{
			int i,j;
			cout << "Enter 9 elements into the matrix " << name << " : \n";
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					cin >> arr[i][j];
				}
			}
		}
		void display()          //function to display the matrix
		{
			int i,j;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					cout << arr[i][j] << " ";
				}
				cout << "\n";
			}
		}
		
		matrix  operator +(matrix C)    //operator function for addition of matrices
		{
			matrix O;
			int i,j;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					O.arr[i][j]=arr[i][j]+C.arr[i][j];
				}
			}
			return(O);
		}
		
		matrix  operator -(matrix C)   //operator function for subtraction of matrices
		{
			matrix O;
			int i,j;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					O.arr[i][j]=arr[i][j]-C.arr[i][j];
				}
			}
			return(O);
		}
		
		matrix  operator *(matrix C)   //operator function for multiplication of matrices
		{
			matrix O;
			int i,j,k;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					O.arr[i][j]=0;
					for(k=0;k<3;k++)
					{
						O.arr[i][j]+=(arr[i][k])*(C.arr[k][j]);
					}
				}
			}
			return(O);
		}
		
		
		matrix transpose()     //function to get the transpose of a matrix
		{
			matrix O;
			int i,j;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					O.arr[j][i]=arr[i][j];
				}
			}
			return(O);
		}
		
		matrix inverse()     //function to get the inverse of a matrix
		{
			matrix O;
			int i,j;
			float det=0;
			for(i = 0; i < 3; i++)   //finding the determinant of the matrix
                det = det + (arr[0][i] * (arr[1][(i+1)%3] * arr[2][(i+2)%3] - arr[1][(i+2)%3] * arr[2][(i+1)%3]));
            for(i = 0; i < 3; i++)
			{
                for(j = 0; j < 3; j++)  //storing the adjoint/det in the O matrix
                    O.arr[i][j]=((arr[(j+1)%3][(i+1)%3] * arr[(j+2)%3][(i+2)%3]) - (arr[(j+1)%3][(i+2)%3] * arr[(j+2)%3][(i+1)%3]))/ det ;
			}
			return(O);
		}
		
		matrix copy()      //function to copy a matrix object into another matrix object
		{
			matrix O;
			int i,j;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					O.arr[i][j]=arr[i][j];
				}
			}
			return(O);
		}
		
		int rank()       //function to find the rank of a matrix
		{
			int rank=3;
			int i,j;
			float mul;
			for(i=0;i<rank;i++)
			{
				if(arr[i][i])
				{
					for(j=0;j<3;j++)
					{
						if(j!=i)
						{
							mul=arr[j][i]/arr[i][i];
							for(int p=0;p<rank;p++)
							{
								arr[j][p]-=mul*arr[i][p];
							}
						}
					}
				}
				else
				{
					int r=1;
					for(int p=i+1;p<3;p++)
					{
						if(arr[p][i])
						{
							for(int m=0;m<rank;m++)
			                {
				                int temp=arr[i][m];
				                arr[i][m]=arr[p][m];
				                arr[p][m]=temp;
			                }
							r=0;
							break;
						}
					}
					if(r)
					{
						rank--;
						for(int p=0;p<3;p++)
						{
							arr[p][i]=arr[p][rank];
						}
					}
					i--;
				}
			}
			return rank;	
		}
		
		~matrix()
		{
			
		}
		
};

int main()
{
	int choice;
	cout << "Let us perform the matrix operations: \n";
	matrix M('M');  //calling parametrised constructor
	matrix N('N');
	
	do
	{
		cout << "Select an operation: \n";
		cout << "1. M+N  \n";
		cout << "2. M-N  \n";
		cout << "3. Transpose(M)  \n";
		cout << "4. M*N  \n";
		cout << "5. Inverse(M)  \n";
		cout << "6. Rank(M)   \n";
		cout << "7.Exit \n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1 : {
				        matrix O;   //default constructor is called
				        O = M + N;   //operator function is called
				        cout << "The matrix M+N is:\n";
				        O.display();  //O is displayed
			         }               //destructor is called
			         break;
			case 2 : {
				        matrix O;
				        O = M - N;
				        cout << "The matrix M-N is:\n";
				        O.display();
			         }
			         break;
		    case 3 : {
				        matrix O;
				        O = M.transpose();
				        cout << "The transpose of the matrix M is:\n";
				        O.display();
			         }
			         break;
			case 4 : {
				        matrix O;
				        O = M*N;
				        cout << "The matrix M*N is:\n";
				        O.display();
			         }
			         break; 
			case 5 : {
				        matrix O;
				        O = M.inverse();
				        cout << "The inverse of the matrix M is:\n";
				        O.display();
			         }
			         break;
			case 6 : {
				        int rank;
				        matrix O;
				        O=M.copy();
				        rank = O.rank();
				        cout << "The rank of the matrix M is: " << rank << "\n";
			         }
			         break;
			case 7 : cout << "End of program!";
			         break;
		}
	}while(choice!=7);
	
}

#include<iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token='X';
bool tie=false;
string n1="";
string n2="";
int a=0;
int b=0;
int num;

void function1(){

cout<<"      |      |      \n";
cout<<"   "<<board[0][0]<<"  |   "<<board[0][1]<<"  |   "<<board[0][2]<<"    \n";
cout<<"      |      |      \n";
cout<<"------|------|------\n";
cout<<"      |      |      \n";
cout<<"   "<<board[1][0]<<"  |   "<<board[1][1]<<"  |   "<<board[1][2]<<"   \n";
cout<<"      |      |      \n";
cout<<"------|------|------\n";
cout<<"      |      |      \n";
cout<<"   "<<board[2][0]<<"  |   "<<board[2][1]<<"  |   "<<board[2][2]<<"   \n";
cout<<"      |      |      \n";


}

void function2(){

int digit;
	if(token=='X')
	{
		cout<<"its "<<n1<<"'s turn";
		cin>>digit;
	}	

	if(token=='O')
	{
		cout<<"its "<<n2<<"'s turn";
		cin>>digit;
	}


	if(digit==1)
		{
			row=0;
			column=0;
		}
	else if(digit==2)
		{
			row=0;
			column=1;
		}
	else if(digit==3)
		{
			row=0;
			column=2;
		}
	else if(digit==4)
		{
			row=1;
			column=0;
		}
	else if(digit==5)
		{
			row=1;
			column=1;
		}
	else if(digit==6)
		{
			row=1;
			column=2;
		}
	else if(digit==7)
		{
			row=2;
			column=0;
		}
	else if(digit==8)
		{
			row=2;
			column=1;
		}
	else if(digit==9)
		{
			row=2;
			column=2;
		}
	else if(digit<1 || digit>9)
	{
			cout<<"invalid!"<<endl;
	}

	if(token=='X' && board[row][column] !='X' && board[row][column] !='O')
	{
		board[row][column]='X';
		token='O';
	}
	else if(token=='O' && board[row][column] !='X' && board[row][column] !='O')
		{
		board[row][column]='O';
		token='X';
		}
	else
	{
		cout<<"there is no empty space!"<<endl;
		function2();
	}
}

bool function3()
{
	for(int i=0;i<3;i++)
	{
		if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i])
		return true;
	}
	if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0])
	{
	return true;
	}

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j] !='X' && board[i][j] !='O')
			{
			return false;
			}
		}
	}
	tie=true;
	return false;

}


int main()
{
cout<<"please enter the name of the firt player: \n";
getline(cin, n1);
cout<<"please enter the name of the second player: \n";
getline(cin, n2);
cout<<n1<<" starts firt and "<<n2<<" will play after him/her \n";
	
	do{

	while(!function3())
	{
		function1();
		function2();
		function3();
	}
		if(token=='X' && tie==false)
		{
			cout<<n2<<"wins!!"<<endl;
			a=+1;
		cout<<n2<<"'s score: "<<a<<"     "<<n1<<"'s score: "<<b<<endl;
		cout<<"do you want to continue this game?\n"<<"(press 0 for no and any other number for yes)\n";
		cin>>num;
		}
	
		else if(token =='O' && tie==false)
		{
			cout<<n1<<"wins!!"<<endl;
			b=+1;
			cout<<n2<<"'s score: "<<a<<"     "<<n1<<"'s score: "<<b<<endl;
			cout<<"do you want to continue this game?\n"<<"(press 0 for no and any other number for yes)\n";
			cin>>num;
		}
		else
		{
			cout<<"its a draw!"<<endl;
			cout<<"do you want to continue this game?\n"<<"(press 0 for no and any other number for yes)\n";
			cin>>num;
		}
	}while(num !=0);
	
	return 0;
}

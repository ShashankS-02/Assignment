#include<bits/stdc++.h>
using namespace std;
int tile=1;
int board[20][20];
void defectiveChessBoard(int trow, int tcol, int drow, int dcol,int size)
{
    if(size==1)
        return;
    int qsize=size/2;
    int tileToUse=tile++;
    if(drow<=trow+qsize-1 && dcol<=tcol+qsize-1)
    {
        defectiveChessBoard(trow,tcol,drow,dcol,qsize);
    }
    else
    {
        board[trow+qsize-1][tcol+qsize-1]=tileToUse;
        defectiveChessBoard(trow,tcol,trow+qsize-1,tcol+qsize-1,qsize);
    }
    if(drow<=trow+qsize-1 && dcol>=tcol+qsize)
    {
        defectiveChessBoard(trow,tcol+qsize,drow,dcol,qsize);
    }
     else
    {
        board[trow+qsize-1][tcol+qsize]=tileToUse;
        defectiveChessBoard(trow,tcol+qsize,trow+qsize-1,tcol+qsize,qsize);
    }
    if(drow>=trow+qsize && dcol<=tcol+qsize-1)
    {
        defectiveChessBoard(trow+qsize,tcol,drow,dcol,qsize);
    }
    else
    {
        board[trow+qsize][tcol+qsize-1]=tileToUse;
        defectiveChessBoard(trow+qsize,tcol,trow+qsize,tcol+qsize-1,qsize);
    }
    if(drow>=trow+qsize && dcol>=tcol+qsize)
    {
        defectiveChessBoard(trow+qsize,tcol+qsize,drow,dcol,qsize);
    }
    else
    {
        board[trow+qsize][tcol+qsize]=tileToUse;
        defectiveChessBoard(trow+qsize,tcol+qsize,trow+qsize,tcol+qsize,qsize);
    }
}

int main()
{
    int n,drow,dcol,i,j;
    cout<<"Enter the size\n";
    cin>>n;
    cout<<"Enter the defective row and coloumn\n";
    cin>>drow>>dcol;
    defectiveChessBoard(0,0,drow,dcol,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

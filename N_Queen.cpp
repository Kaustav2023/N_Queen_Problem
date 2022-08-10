#include<bits/stdc++.h>
using namespace std;


bool Check(int col,int row,vector<string>&board,int n){
    int coldup=col;
    int rowdup=row;
    while(col>=0 && row>=0){
        if(board[row][col]=='Q') return false;
        col--;
        row--;
    }
     col=coldup;
     row=rowdup;
    while(col>=0){
        if(board[row][col]=='Q')return false;
        col--;
    }
     col=coldup;
     row=rowdup;
    while(row<n && col>=0){
        if(board[row][col ]=='Q')return false;
        col--;
        row++;
    }
    return true;
}

void nQueen(int col,vector<string>&board,vector<vector<string>>&chess,int n){
    
    if(col==n){
        chess.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(Check(col,row,board,n)){
            board[row][col]='Q';
            nQueen(col+1,board,chess,n);
            board[row][col]='.';
        }
    }
}




int main(){
    int n;
    cin>>n;
    string st(n,'.');
    vector<string>board(n);
    vector<vector<string>>chess;
    for(int i=0;i<n;i++){
        board[i]=st;
    }
    nQueen(0,board,chess,n);
  for(int i=0;i<chess.size();i++){
    cout<<"Arrangement "<<i+1<<'\n';
    for(int j=0;j<chess.size();j++){
        cout<<chess[i][j];
        cout<<endl;
    }
    cout<<endl;
    
  }

}
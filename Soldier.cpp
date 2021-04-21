#include<iostream>
#include<vector>

using namespace std;
/* for printing the position of soldier*/
void printPostion(vector<vector<int>>board,int num_soldier){
    cout<<"Solution is: "<<endl;
    for(int i=0;i<num_soldier;i++){
        for(int j=0;j<num_soldier;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>>&board,int curr_pos_row,int col,int row){
    /*
     1. Traverse in row
     2. Traverse in lower Diagonal
     3. Traverse in upper diagonal
    */
   for(int i=0;i<col;i++){
       if(board[curr_pos_row][i]==1){
           return false;
       }
   }
   // traversing in upper left diagonal
   int i=curr_pos_row,j=col;
   while(i>=0 && j>=0){
       if(board[i][j]==1){
           return false;
       }
       i--;
       j--;
   }
   // checking in lower left diagonal
   i=curr_pos_row,j=col;
   while(i<row && j>=0){
       if(board[i][j]==1){
           return false;
       }
       i++;
       j--;
   }
   
   return true;
}
/*
  Idea is solve the problem using backtracking
 1. place the soldier one by one in column ( means first solidier will be in first column, second soldier will be in second column and so on)
 2. Before placing the soldier check that position is safe or not, if safe then place the soldier, otherwise check in other row in same column
*/

bool soldier_pos(vector<vector<int>>&board,int col,int row){
   if(col>=row){
       return true;
   }

   for(int i=0;i<row;i++){
       if(isSafe(board,i,col,row)){
           board[i][col]=1;
           if(soldier_pos(board,col+1,row)){
               return true;
           }
           board[i][col]=0;
       }
   }

   return false;

}

void SaveSoldier(int num_soldier){
   
   vector<vector<int>>board(num_soldier,vector<int>(num_soldier,0));
   if(soldier_pos(board,0,num_soldier)==1){
      printPostion(board,num_soldier);
   }else{
       cout<<"Solution Does Not Exist:"<<endl;
   }
   

}

int main(void){
    int test;
    cout<<"Enter the Number of Test:"<<endl;
    cin>>test;  // Number of test is for how many times code wil test
    while(test--){
        int num_soldier;
        cout<<"Enter the Number of Soldier:"<<endl;
        cin>>num_soldier;  // Number of soldier 
        SaveSoldier(num_soldier);
    }
    return 0;
}
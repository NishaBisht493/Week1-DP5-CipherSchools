#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<bool>> &Chess, int x, int y, const int &N){
    //Horizontally back
    for(int i = x; i >= 0; i--){
        if(Chess[i][y]){
            return false;
        }
    }
    //Diagonally Up
    for(int i = x, j = y; i >= 0 && j >= 0; i--, j--){
        if(Chess[i][y]){
            return false;
        }
    }
    //Diagonally Down
    for(int i = x, j = y; i < N && j >= 0; i++, j--){
        if(Chess[i][y]){
            return false;
        }
    }

    return true;
}
bool solveNQueens(vector<vector<bool>> &Chess, int y, const int &N){
    //base case
    if(y == N){
        return true;
    }
    //recursion
    for(int x = 0; x < N; x++){
        if(isSafe(Chess, x, y, N)){
            Chess[x][y] = true;
            if(solveNQueens(Chess, y + 1, N)){
                return true;
            }
            //backtracking
            Chess[x][y] = false;
        }
    }
}

vector<vector<bool>> NQueens(int N) {
    vector<vector<bool>> Chess(N, vector<bool>(N, false));
    solveNQueens(Chess, 0, N);
    return Chess;
}

int main(){

}
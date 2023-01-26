#include<bits/stdc++.h>
using namespace std;

#define Size 9
bool isEmpty(vector<vector<char>> &sudoku, int &row, int &col){
    for(row = 0; row < Size; row++){
        for(col = 0; col < Size; col++){
            if(sudoku[row][col] == 0){
                return true;
            }
        }    
    }
    return false;
}

bool usedInRow(vector<vector<char>> &sudoku, int row, int fill){
    for(int j = 0; j < Size; j++){
        if(sudoku[row][j] == fill){
            return true;
        }
    }
    return false;
}

bool usedInCol(vector<vector<char>> &sudoku, int col, int fill){
    for(int i = 0; i < Size; i++){
        if(sudoku[i][col] == fill){
            return true;
        }
    }
    return false;
}

bool usedInBox(vector<vector<char>> &sudoku, int row, int col, int fill){
    row = row - (row % 3);
    col = col - (col % 3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(sudoku[i + row][j + col] == fill){
                return true;
            }
        }
    }
    return false;
}

bool isSafe(vector<vector<char>> &sudoku, int row, int col, int fill){
    //Used In Row
    //Used In Col
    //Used In Box

    return(!usedInRow(sudoku, row, fill) && !usedInCol(sudoku, col, fill) && !usedInBox(sudoku, row, col, fill));
}

bool isValidSudoku(vector<vector<char>>& sudoku) {
    int row, col; //location of empty cell
    if(!isEmpty(sudoku, row, col)){
        //If I can not find any empty cell
        return true;
    }
    // bool found = false;
    // for(row = 0; row < Size; row++){
    //     for(col = 0; col < Size; col++){
    //         if(sudoku[row][col] == 0){
    //             found = true;
    //             break;
    //         }
    //     }  
    //     if(found){
    //         break;
    //     }  
    // }
    // if(!found){
    //     return true;
    // }

    for(int i = 1; i <= 9; i++){
        if(isSafe(sudoku, row, col, i)){
            sudoku[row][col] = i;
            if(isValidSudoku(sudoku)){
                return true;
            }
            //backtracking
            sudoku[row][col] = 0;
        }
    }
    return false;

}

int main(){

}
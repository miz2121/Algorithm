//C++로 구현하는 자료구조와 알고리즘 한티에듀
//129p_Tic-Tac-Toe
 
#include <iostream>
using namespace std;
 
//가능한 표시들
const int X = 1;
const int O = -1;
const int EMPTY = 0;
 
int board[3][3];   //게임 보드
int currentPlayer; //현재의 플레이어(X또는 O)
 
void clearBoard()
{ //게임 보드 정리
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = EMPTY; //모든 칸이 비어있음
        }
    }
    currentPlayer = X; //플레이어 X로 시작
}
 
void putMark(int i, int j)
{                                   //i행 j열에 표시
    board[i][j] = currentPlayer;    //현재의 플레이어로 표시
    currentPlayer = -currentPlayer; //플레이어 변경
}
 
bool isWin(int mark)
{                       //현 mark가 승리?
    int win = 3 * mark; //+3이면 X, -3이면 O
    return (
        (board[0][0] + board[0][1] + board[0][2] == win)    //행0
        || (board[1][0] + board[1][1] + board[1][2] == win) //행1
        || (board[2][0] + board[2][1] + board[2][2] == win) //행2
        || (board[0][0] + board[1][0] + board[2][0] == win) //열0
        || (board[0][1] + board[1][1] + board[2][1] == win) //열1
        || (board[0][2] + board[1][2] + board[2][2] == win) //열2
        || (board[0][0] + board[1][1] + board[2][2] == win) //대각선
        || (board[2][0] + board[1][1] + board[0][2] == win) //대각선
    );
}
 
int getWinner()
{ //누가 이겼는가? (EMPTY는 동점을 의미)
    if (isWin(X))
        return X;
    else if (isWin(O))
        return O;
    else
        return EMPTY;
}
 
void printBorad()//게임 보드를 출력
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (board[i][j])
            {
            case X:
                cout << "X";
                break;
            case O:
                cout << "O";
                break;
            case EMPTY:
                cout << " ";
                break;
            }
            if (j<2)cout<<"|";//열의 경계
        }
        if(i<2)cout<<"\n-+-+-\n";//행의 경계
    }
}
 
int main(){//main 프로그램
    clearBoard();//보드를 비움
    putMark(0,0);   putMark(1,1);//표시를 더함
    putMark(0,1);   putMark(0,2);
    putMark(2,0);   putMark(1,2);
    putMark(2,2);   putMark(2,1);
    putMark(1,0);
    printBorad();//마지막 보드를 출력
    int winner = getWinner();
    if(winner!=EMPTY){//승리자를 출력
        cout<<" "<<(winner == X ? 'X' : 'O')<<" wins"<<endl;
    }
    else{
        cout<<" Tie"<<endl;
    }
    return EXIT_SUCCESS;
}


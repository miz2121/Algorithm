//C++로 구현하는 자료구조와 알고리즘 한티에듀
//118p_3.1.1_배열에_게임_엔트리_저장
#include <iostream>
using namespace std;
class RuntimeException
{
public:
    RuntimeException(const string &err) : errMsg(err) {}
    string getMsg() const { return errMsg; }
 
private:
    string errMsg;
};
class IndexOutOfBounds : public RuntimeException
{
public:
    IndexOutOfBounds(const string &err) : RuntimeException(err){};
};
 
class GameEntry
{ //게임 점수 엔트리
public:
    GameEntry(const string &n = "", int s = 0); //생성자
    string getName() const;                     //선수 이름 가져오기
    int getScore() const;                       //점수 가져오기
private:
    string name; //선수 이름
    int score;   //선수의 점수
};
GameEntry::GameEntry(const string &n, int s) : name(n), score(s) {} //생성자
string GameEntry::getName() const { return name; }                  //접근자
int GameEntry::getScore() const { return score; }                   //접근자
 
class Scores
{ //게임의 높은 점수들을 저장한다.
public:
    Scores(int mexEnt = 10);                         //생성자
    ~Scores();                                       //소멸자
    void add(const GameEntry &e);                    //게임 엔트리 추가
    GameEntry remove(int i) throw(IndexOutOfBounds); //i번째 엔트리 삭제
private:
    int maxEntries;     //엔트리들의 최대 숫자
    int numEntries;     //엔트리들의 실제 숫자
    GameEntry *entries; //게임 엔트리들의 배열
};
Scores::Scores(int maxEnt)
{                                        //생성자
    maxEntries = maxEnt;                 //최대 크기를 저장
    entries = new GameEntry[maxEntries]; //배열 공간 할당
    numEntries = 0;                      //처음에는 원소 없음
}
Scores::~Scores()
{ //소멸자
    delete[] entries;
}
void Scores::add(const GameEntry &e)
{                                //게임 엔트리 추가
    int newScore = e.getScore(); //추가될 점수
    if (numEntries == maxEntries)
    { //배열이 꽉 찼음
        if (newScore <= entries[maxEntries - 1].getScore())
        { //충분히 크지 않다 - 무시하기
            return;
        }
    }
    else
        numEntries++; //꽉 차있지 않다면, 엔트리 추가
 
    int i = numEntries - 2; //마지막 엔트리 옆에서 시작하기
    while (i >= 0 && newScore > entries[i].getScore())
    {
        entries[i + 1] = entries[i]; //만약 작다면 오른쪽 이동
        i--;
    }
    entries[i + 1] = e; //빈 공간에 e 넣기
}
GameEntry Scores::remove(int i) throw(IndexOutOfBounds)
{
    if ((i < 0) || (i > numEntries))
    { //부적절한 색인
        throw IndexOutOfBounds("Invalid index");
    }
    GameEntry e = entries[i];//제거 객체 저장
    for (int j = i + 1; j < numEntries; j++)
    {
        entries[j - 1] = entries[j];//엔트리 왼쪽 이동
    }
    numEntries--;//엔트리 수 줄이기
    return e;//제거된 객체 반환
}


//C++로 구현하는 자료구조와 알고리즘 한티에듀
//146p_3.4.1_환형_링크드_리스트
 
//커서(cursor) 노드는 환형 링크드 리스트를 탐색할 필요가 있을 때, 시작할 지점을 지정해 준다.
#include <iostream>
using namespace std;
 
typedef string Elem; //원소 타입
 
class CNode
{ //환형 링크드 리스트 노드
private:
    Elem elem;               //링크드 리스트 원소 값
    CNode *next;             //리스트의 다음 엔트리
    friend class CircleList; //CircleList에게 접근 제공
};
 
class CircleList
{ //환형 링크드 리스트
public:
    int size=0;
    CircleList();              //생성자
    ~CircleList();             //소멸자
    bool empty() const;        //비었는가?
    const Elem &front() const; //커서 다음의 원소
    const Elem &back() const;  //커서의 원소
    void advance();            //커서를 다음으로 이동
    void add(const Elem &e);   //커서 뒤에 추가
    void remove();             //커서의 다음 노드 삭제
    void print();
private:
    CNode *cursor; //커서
};
CircleList::CircleList() : cursor(NULL) {} //생성자
CircleList::~CircleList()
{
    while (!empty())
        remove();
} //소멸자
bool CircleList::empty() const { return cursor == NULL; } //비었는가?
const Elem &CircleList::back() const //커서의 원소
{
    return cursor->elem;
}
const Elem &CircleList::front() const //커서의 다음 원소
{
    return cursor->next->elem;
}
void CircleList::advance() //커서를 다음으로 이동
{
    cursor = cursor->next;
}
 
void CircleList::add(const Elem &e)
{                         //커서의 다음에 추가
    CNode *v = new CNode; //새로운 노드를 생성
    size++;
    v->elem = e;
    if (cursor == NULL)
    {                //빈 리스트?
        v->next = v; //v는 자기 자신을 가리킴
        cursor = v;  //커서는 v를 가리킴
    }
    else
    {                           //빈 리스트가 아님?
        v->next = cursor->next; //v를 커서의 뒤에 연결
        cursor->next = v;
    }
}
void CircleList::remove(){ //커서의 다음 노드 삭제
    CNode* old = cursor->next; //삭제될 노드
    if(old==cursor) //유일한 노드를 삭제하는 경우?
        cursor==NULL; //이제 빈 리스트
    else 
        cursor->next = old->next; //삭제할 노드의 연결 끊기
    if(size>0)size--;
    else size=0;
    delete old; //노드 삭제
}
void CircleList::print(){
    for(int i = 0; i < size ; i++){
        cout<<back()<<" "<<endl;
        advance();
    }
}
int main(){
    // 환형 링크드 리스트의 CircleList 구현의 응용을 설명하기 위해서, 
    // MP3를 위한 재생 목록을 유지하는 간단한 인터페이스를 어떻게 구현하는지에 대해서 고려해보자.
    CircleList playList; //[]
    playList.add("Stayin Alive"); //[Stayin Alive*]
    playList.add("Le Freak"); //[Le Freak, Stayin Alive*]
    playList.add("Jive Talkin"); //[Jive Talkin, Le Freak, Stayin Alive*]
 
    playList.advance(); //[Le Freak, Stayin Alive, Jive Talkin*]
    playList.advance(); //[Stayin Alive, Jive Talkin, Le Freak*]
    playList.remove(); //[Jive Talkin, Le Freak*]
    playList.add("Disco Inferno"); //[Disco Inferno, Jive Talkin, Le Freak*]
    playList.print();//print()는 back()을 사용하므로 커서가 가리키고있는 원소부터 출력된다.
    return EXIT_SUCCESS;
}
 


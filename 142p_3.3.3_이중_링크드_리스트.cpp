 //C++로 구현하는 자료구조와 알고리즘 한티에듀
//142p_3.3.3_이중_링크드_리스트
 
/*
프로그래밍을 단순화하기 위해, 이중 링크드 리스트의 양 끝에 특별한 노드들(리스트 헤드(head) 앞의 헤더(header) 노드와 리스트 후미(trail) 다음의 트레일러(trailer) 노드)를 추가하는 것이 좋다. 이러한 더미(dummy) 또는 센티널(sentinal) 노드들은 어떠한 원소도 저장하지 않는다. 이 노드들은 리스트의 첫 번째와 마지막 노드들에 대한 빠른 접근을 제공한다. 특히, 헤더 노드의 next 포인터는 리스트의 첫 번째 노드를 가리키고, 트레일러 노드의 prev 포인터는 리스트의 마지막 노드를 가리킨다. 
*/
 
#include <iostream>
using namespace std;
 
typedef string Elem; //리스트의 원소 타입
class DNode
{ //이중 링크드 리스트 노드
private:
    Elem elem;                //노드 원소 값
    DNode *prev;              //리스트의 이전 노드
    DNode *next;              //리스트의 다음 노드
    friend class DLinkedList; //DLinkedList에게 접근을 허용
};
class DLinkedList
{ //이중 링크드 리스트
public:
    DLinkedList(); //생성자
    ~DLinkedList(); //소멸자
    bool empty() const; //빈 리스트?
    const Elem &front() const; //앞의 원소를 얻음
    const Elem &back() const; //뒤의 원소를 얻음
    void addFront(const Elem &e); //리스트의 앞에서 추가
    void addBack(const Elem &e); //리스트의 뒤에서 추가
    void removeFront(); //앞에서 제거
    void removeBack(); //뒤에서 제거
 
private: //로컬 타입 정의
    DNode *header; //리스트 센티널
    DNode *trailer;
 
protected: //로컬 유틸리티
    void add(DNode *v, const Elem &e); //v 전에 새로운 노드 삽입
    void remove(DNode *v); //v 노드 제거
};
DLinkedList::DLinkedList() //생성자
{
    header = new DNode; //센티널들을 만듦
    trailer = new DNode;
    header->next = trailer; //서로를 가리키도록 함
    trailer->prev = header;
}
DLinkedList::~DLinkedList() //소멸자
{
    while (!empty())
        removeFront(); //센티널들을 제외한 모든 노드 삭제
    delete header; //센티널들을 삭제
    delete trailer;
}
bool DLinkedList::empty() const //빈 리스트?
{
    return (header->next == trailer);
}
const Elem &DLinkedList::front() const //가장 앞의 원소를 얻음
{
    return header->next->elem;
}
const Elem &DLinkedList::back() const //가장 뒤의 원소를 얻음
{
    return trailer->prev->elem;
}
 
void DLinkedList::add(DNode *v, const Elem &e)
{ //v 전에 새로운 노드 삽입
    DNode *u = new DNode; //e를 위한 새로운 노드 생성
    u->elem = e; 
    u->next = v; //u와 v를 연결
    u->prev = v->prev; //v->prev와도 연결
    v->prev->next = v->prev = u; 
}
void DLinkedList::addFront(const Elem &e) //리스트의 앞에서 추가
{
    add(header->next, e);
}
void DLinkedList::addBack(const Elem &e) //리스트의 뒤에서 추가
{
    add(trailer, e);
}
 
void DLinkedList::remove(DNode *v)
{ //v노드를 삭제
    DNode *u = v->prev; //선행자
    DNode *w = v->next; //후속자
    u->next = w; //리스트에서 v의 연결 끊기
    w->prev = u;
    delete v;
}
void DLinkedList::removeFront() //앞에서 삭제
{
    remove(header->next); 
}
void DLinkedList::removeBack() //뒤에서 삭제
{
    remove(trailer->prev);
}


//C++로 구현하는 자료구조와 알고리즘 한티에듀
//133p_3.2.1_단일_링크드_리스트_구현
//문자열의 단일 링크드 리스트 구현
#include <iostream>
using namespace std;

class StringNode //문자열 리스트의 노드
{
private:
    string elem;      //원소값
    StringNode *next; //리스트의 다음 항목

    friend class StringLinkedList; //StringLinkedList에 접근 제공
};
class StringLinkedList
{ //문자열의 링크드 리스트
public:
    StringLinkedList();             //빈 리스트 생성자
    ~StringLinkedList();            //소멸자
    bool empty() const;             //리스트가 비어있는가?
    const string &front() const;    //이전 원소를 얻는다.
    void addFront(const string &e); //리스트의 앞에서 추가한다.
    void removeFront();             //앞의 리스트 항목을 삭제한다.
private:
    StringNode *head; //리스트의 헤드를 가리키는 포인터
};
StringLinkedList::StringLinkedList() : head(NULL) {} //생성자
StringLinkedList::~StringLinkedList() //소멸자
{
    while (!empty())
        removeFront();
}
bool StringLinkedList::empty() const //빈 리스트?
{
    return head == NULL;
}
const string &StringLinkedList::front() const //이전 원소를 얻는다.
{
    return head->elem;
}
void StringLinkedList::addFront(const string &e){ //리스트의 앞에 추가
    StringNode* v = new StringNode; //새로운 노드 생성
    v->elem = e; //데이터를 저장
    v->next = head; //지금 head는 v의 뒤에 있다. head의 앞 위치에 생성한 v를 두자.
    head = v; //v가 이제 head가 된다.
}
void StringLinkedList::removeFront(){ //앞의 항목 제거
    StringNode* old = head; //현재 head 저장
    head = old->next; //이전 head를 건너뛴다.
    delete old; //이전 head 삭제
}

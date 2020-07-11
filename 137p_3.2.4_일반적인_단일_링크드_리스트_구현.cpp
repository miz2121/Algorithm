//C++로 구현하는 자료구조와 알고리즘 한티에듀
//137p_3.2.4_일반적인_단일_링크드_리스트_구현
#include <iostream>
 
using namespace std;
 
template<typename E>
class SNode //단일 링크드 리스트의 노드
{
private:
    E elem;      //링크드 리스트 원소값
    SNode<E> *next; //리스트의 다음 항목
 
    friend class SLinkedList<E>; //SLinkedList에게 접근 제공
};
template<typename E>
class SLinkedList
{ //문자열의 링크드 리스트
public:
    SLinkedList();             //빈 리스트 생성자
    ~SLinkedList();            //소멸자
    bool empty() const;             //리스트가 비어있는가?
    const E &front() const;    //이전 원소를 얻는다.
    void addFront(const E &e); //리스트의 앞에서 추가한다.
    void removeFront();             //앞의 리스트 항목을 삭제한다.
private:
    SNode<E> *head; //리스트의 head를 가리키는 포인터
};
template<typename E>
SLinkedList<E>::SLinkedList() : head(NULL) {} //생성자
template<typename E>
SLinkedList<E>::~SLinkedList() //소멸자
{
    while (!empty())
        removeFront();
}
template<typename E>
bool SLinkedList<E>::empty() const //빈 리스트?
{
    return head == NULL;
}
template<typename E>
const E &SLinkedList<E>::front() const //이전 원소를 얻는다.
{
    return head->elem;
}
template<typename E>
void SLinkedList<E>::addFront(const E &e){ //리스트의 앞에 추가
    SNode<E>* v = new SNode<E>; //새로운 노드 생성
    v->elem = e; //데이터를 저장
    v->next = head; //지금 head는 v의 뒤에 있다. head의 앞 위치에 생성한 v를 두자.
    head = v; //v가 이제 head가 된다.
}
template<typename E>
void SLinkedList<E>::removeFront(){ //앞의 항목 제거
    SNode<E>* old = head; //현재 head 저장
    head = old->next; //이전 head를 건너뛴다.
    delete old; //이전 head 삭제
}
int main(){
    SLinkedList<string> a;
    a.addFront("MegaMinsoo");
    //...
    SLinkedList<int> b;
    b.addFront(13);
    //...
    return EXIT_SUCCESS;
}


//C++로 구현하는 자료구조와 알고리즘 한티에듀
//151p_3.4.2_링크드_리스트_반전
//'142p_3.3.3_이중_링크드_리스트'와 함께 본다.
 
void listReverse(DLinkedList& L){ //리스트 반전
    DLinkedList T; //임시 리스트
    while(!L.empty()){ //L을 T로 반전
        Elem e = L.front();
        L.removeFront();
        T.addFront(e);
    }
    while(!T.empty()){ //T를 다시 L로 복사
        Elem e = T.front();
        T.removeFront();
        L.addBack(e);
    }
}
 


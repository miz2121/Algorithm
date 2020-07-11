//C++로 구현하는 자료구조와 알고리즘 한티에듀
//124p_3.1.2_배열정렬_삽입정렬
 
#include<iostream>
using namespace std;
 
void insertionSort(char* A, int n){//n개 문자의 배열을 정렬
    for(int i = 1; i < n; i++){//삽입 루프
        char cur = A[i];//삽입하려는 현재의 문자
        int j = i - 1;//바로 앞의 문자에서 시작
        while((j>=0)&&(A[j]>cur)){//A[j]가 순서에 어긋나 있는 동안
            A[j+1] = A[j];//A[j]를 오른쪽으로 이동
            j--;//j를 감소
        }
        A[j+1] = cur;//이곳이 cur에게 맞는 위치
    }
}


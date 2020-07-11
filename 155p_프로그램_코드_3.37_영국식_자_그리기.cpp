//C++로 구현하는 자료구조와 알고리즘 한티에듀
//155p_프로그램_코드_3.37_영국식_자_그리기
#includeiostream
using namespace std;
 
void drawOneTick(int tickLength, int tickLabel = -1){
    for(int i = 0; itickLength; i++){
        cout-;
    }
    if(tickLabel=0)cout tickLabel;
    coutn;
}
void drawTicks(int tickLength){
    if(tickLength0){
        drawTicks(tickLength-1);
        drawOneTick(tickLength);
        drawTicks(tickLength-1);
    }
}
void drawRuler(int nInches, int majorLength){//majorLength개의 주요 표식을 갖는 nInches인치 자를 그린다.
    drawOneTick(majorLength, 0);
    for(int i = 1; i=nInches; i++){
        drawTicks(majorLength-1);
        drawOneTick(majorLength, i);
    }
}
int main(){
    int nInches = 3;
    int majorLength = 3;
    drawRuler(nInches, majorLength);
}


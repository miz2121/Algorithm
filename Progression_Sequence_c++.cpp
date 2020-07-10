//C++로 구현하는 자료구조와 알고리즘 한티에듀
//88p_2.2.3_C++에서_상속의_예제
//점차적으로 진행하는 수열을 출력하는 몇 클래스들을 갖는 예를 고려하자.
#include <iostream>
using namespace std;
 
class Progression
{
public:
    Progression(long f = 0) : first(f), cur(f) {}
    virtual ~Progression(){};
    void printProgression(int n);
 
protected:
    virtual long firstValue();
    virtual long nextValue();
 
protected:
    int first;
    int cur;
};
void Progression::printProgression(int n)
{
    cout << firstValue();
    for (int i = 2; i <= n; i++)
    {
        cout << ' ' << nextValue();
    }
    cout << endl;
}
long Progression::firstValue()
{
    cur = first;
    return cur;
}
long Progression::nextValue()
{
    return ++cur;
}
class ArithProgression : public Progression
{ //등차수열 클래스. 상속.
public:
    ArithProgression(long i = 1);
 
protected:
    virtual long nextValue();
 
protected:
    long inc;
};
ArithProgression::ArithProgression(long i) : Progression(), inc(i) {}
long ArithProgression::nextValue()
{
    cur += inc;
    return cur;
}
class GeomProgression : public Progression
{ //등비수열 클래스. 상속.
public:
    GeomProgression(long b = 2);
 
protected:
    virtual long nextValue();
 
protected:
    long base;
};
GeomProgression::GeomProgression(long b) : Progression(1), base(b) {}
long GeomProgression::nextValue()
{
    cur *= base;
    return cur;
}
class FibonacciProgression : public Progression
{
public:
    FibonacciProgression(long f = 0, long s = 0);
 
protected:
    virtual long firstValue();
    virtual long nextValue();
 
protected:
    long second;
    long prev;
};
FibonacciProgression::FibonacciProgression(long f, long s) : Progression(f), second(s), prev(second - first) {}
long FibonacciProgression::firstValue()
{
    cur = first;
    prev = second - first;
    return cur;
}
long FibonacciProgression::nextValue()
{
    long temp = prev;
    prev = cur;
    cur += temp;
    return cur;
}
int main()
{
    Progression *prog;
    //등차수열 테스트
    cout << "Arithmetic progression with default increment: \n";
    prog = new ArithProgression();
    prog->printProgression(10);
    cout << "Arithmetic progression with default increment 5: \n";
    prog = new ArithProgression(5);
    prog->printProgression(10);
    //등비수열 테스트
    cout << "Geometric progression with default base: \n";
    prog = new GeomProgression();
    prog->printProgression(10);
    cout << "Geometric progression with base 3: \n";
    prog = new GeomProgression(3);
    prog->printProgression(10);
    //피보나치 수열 테스트
    cout << "Fibonacci progression with default start values: \n";
    prog = new FibonacciProgression();
    prog->printProgression(10);
    cout << "Fibonacci progression with start values 4 and 6:\n";
    prog = new FibonacciProgression(4, 6);
    prog->printProgression(10);
    return EXIT_SUCCESS;
}

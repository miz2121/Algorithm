//프로그래머스
//비밀지도
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string binaryToSharp(int num)
{
    string result = "";
    for (int i = 1; num > 0; i *= 10)
    {
        int binary = num % 2;
        if (binary == 1)
        {
            result += '#';
        }
        else
        {
            result += ' ';
        }
        num /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}
//vector<string>
void solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<int> temp(n);

    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        temp[i] = arr1[i] | arr2[i];
        answer.push_back(binaryToSharp(temp[i]));
    }

    for(int i = 0;i < answer.size(); i++){
        cout<<answer[i]<<endl;
    }
 }

int main()
{
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};
    int n = 5;
    solution(n, arr1, arr2);
}

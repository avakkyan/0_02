#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<string> generateGray(int n)
{
    if (n <= 0)
        return {"0"};
    if (n == 1)
    {
        return {"0","1"};
    }
    vector<string> temp_ans = generateGray(n-1);
    vector<string> Ans;
    for(int i=0;i<temp_ans.size();i++)
    {
        string s=temp_ans[i];
        Ans.push_back("0"+s);
    }
    for(int i=temp_ans.size()-1;i>=0;i--)
    {
        string s=temp_ans[i];
        Ans.push_back("1"+s);
    }
    return Ans;
}

void generateGrayarr(int n)
{
    vector<string> arr;
    arr=generateGray(n);
    for (int i = 0 ; i < arr.size();
         i++ )
        cout << arr[i] <<"\n";
}

int main()
{
    int n;
    cin >> n;
    generateGrayarr(n);
    return 0;
}

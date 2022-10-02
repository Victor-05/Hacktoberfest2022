#include <iostream>
#include <fstream>

using namespace std;

int n,p,s[101];
ifstream f("permutations.in");
ofstream g("permutations.out");

void init(int k)
{
    s[k]=0;
}

int next(int k)
{
    s[k]++;
    if(s[k]<=n)
        return 1;
    else
        return 0;
}

int valid(int k)
{
    int i;
    for(i=1;i<k;i++)
        if(s[i]==s[k])
            return 0;
    return 1;
}

int solution(int k)
{
    if(k==n)
        return 1;
    else
        return 0;
}

void display(int k)
{
    int i;
    for(i=1;i<=k;i++)
        g<<s[i]<<" ";
    g<<endl;
}

void back(int k)
{
    int ok1,ok2;
    init(k);
    while(k>0)
    {
        do
        {
            ok1=next(k);
            ok2=valid(k);
        }while(ok1 && !ok2);

        if(ok1)
        {
            if(solution(k))
                display(k);
            else
            {
                k++;
                init(k);
            }
        }
        else
            k--;
        }

}

int main()
{
    f>>n;
    back(1);
    return 0;
}

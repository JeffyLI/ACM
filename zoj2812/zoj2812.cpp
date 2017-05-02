
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int i,sum;
    char a[256];
    while(gets(a)&&a[0]!='#')
    {
        sum=0;
        for(i=0;i<strlen(a);i++)
            if(a[i]>='A'&&a[i]<='Z')
              sum+=(a[i]-'A'+1)*(i+1);
        cout<<sum<<endl;
    }
    return 0;
}

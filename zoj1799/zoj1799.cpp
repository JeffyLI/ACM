
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int i=0;
    char s[11];
    int a[11],b[11];
    char c[101],d[101];
    int tempi;
    char mc;
    while(cin>>s)
    {
        memset(a,0,sizeof(int)*11);
        if(strcmp(s,"THEEND")==0) break;
        for(i=0;i<strlen(s);i++)
        {
            for(int j=i+1;j<strlen(s);j++)
            {
                if(s[i]<=s[j]) a[j]++;
                else a[i]++;
            }
        }
        for(i=0;i<strlen(s);i++)
        {
            for(int g=0;g<strlen(s);g++)
            {
                if(a[g]==i) b[i]=g;
            }
        }
        cin>>c;
        int h=strlen(c)/strlen(s);
        for(int i=0;i<strlen(c);i++)
        {
            d[b[i/h]+(i%h)*strlen(s)]=c[i];
        }
        d[strlen(c)]='\0';
        cout<<d<<endl;
    }
    return 0;
}

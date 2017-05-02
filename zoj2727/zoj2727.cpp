
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct book
{
    char name[80];
    int year;
    int price;
};

int cmpN(const void*a,const void*b)
{
    if(strcmp((*(book*)a).name,(*(book*)b).name)==0)
    {
        if((*(book*)a).year==(*(book*)b).year)
        {
            return (*(book*)a).price-(*(book*)b).price;
        }
        return (*(book*)a).year-(*(book*)b).year;
    }
    return strcmp((*(book*)a).name,(*(book*)b).name);
}

int cmpP(const void*a,const void*b)
{
    if((*(book*)a).price==(*(book*)b).price)
    {
        if(strcmp((*(book*)a).name,(*(book*)b).name)==0)
        {
            return (*(book*)a).year-(*(book*)b).year;
        }
        return strcmp((*(book*)a).name,(*(book*)b).name);
    }
    return (*(book*)a).price-(*(book*)b).price;
}

int cmpY(const void*a,const void*b)
{
    if((*(book*)a).year==(*(book*)b).year)
    {
        if(strcmp((*(book*)a).name,(*(book*)b).name)==0)
        {
            return (*(book*)a).price-(*(book*)b).price;
        }
        return strcmp((*(book*)a).name,(*(book*)b).name);
    }
    return (*(book*)a).year-(*(book*)b).year;
}

int main()
{
    int n;
    char way[6];
    book b[100];
    int pe=0;
    while(cin>>n&&n!=0)
    {
        if(pe!=0) cout<<endl;
        pe=1;
        for(int i=0;i<n;i++)
        {
            cin>>b[i].name>>b[i].year>>b[i].price;
        }
        cin>>way;
        if(way[0]=='N')
        {
            qsort(b,n,sizeof(book),cmpN);
        }else if(way[0]=='P')
        {
            qsort(b,n,sizeof(book),cmpP);
        }else{
            qsort(b,n,sizeof(book),cmpY);
        }
        for(int i=0;i<n;i++)
        {
            cout<<b[i].name<<" "<<b[i].year<<" "<<b[i].price<<endl;
        }
    }
    return 0;
}

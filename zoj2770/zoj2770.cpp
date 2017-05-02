#include <cstdio>
#define INF 9999999
#define N 1001
#define E 23000
int d[N],c[N],x[N],s[N];
int n,m;
int dist[N];
struct edge{
    int u,v,w;
}e[E];
int edgeNum;
void add(int u,int v,int w){
    e[edgeNum].u=u;
    e[edgeNum].v=v;
    e[edgeNum++].w=w;
}
bool bellman(){
    int i,j;
    for(i=1;i<n;i++) dist[i]=INF;
    for(i=0;i<n;i++){
        for(j=0;j<edgeNum;j++)
            if(dist[e[j].u]!=INF&&dist[e[j].u]+e[j].w<dist[e[j].v]){
                dist[e[j].v]=dist[e[j].u]+e[j].w;
            }
    }
    for(int j=0;j<edgeNum;j++)
        if(dist[e[j].u]!=INF&&dist[e[j].u]+e[j].w<dist[e[j].v])
            return 0;
    return 1;
}
int main(){
    int i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF){
        edgeNum=0;
        d[n]=dist[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&c[i]);
            add(i-1,i,c[i]);
            add(i,i-1,0);
            d[i]=d[i-1]+c[i];
        }
        while(m--){
            scanf("%d%d%d",&i,&j,&k);
            add(j,i-1,-k);
            add(i-1,j,d[j]-d[i-1]);
        }
        if(!bellman()) puts("Bad Estimations");
        else printf("%d\n",dist[n]-dist[0]);
    }
    return 0;
}

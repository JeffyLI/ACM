#include<cstdio>
#define min( a, c ) (a)<(c)?(a):(c)
const int maxn = 500005, INF = 0x3fffffff;
int a[maxn], b[maxn], m[3*maxn];
void build(int k, int l, int r)
{
    m[k] = INF;
    if(l == r-1) return;
    build(k * 2 + 1,l, (l+r)/2);
    build(k * 2 + 2, (l+r)/2, r);
}
void update(int a, int  x, int k, int l, int r)
{
      m[k] = min(x, m[k]);
      if(l < r-1){
        int m = (l+r)/2;
        if(m > a) update(a, x, k * 2 + 1, l, m);
        else update(a, x, k * 2 + 2, m, r);
    }
}
int query(int a, int b, int k, int l, int r)
{
    if(a >= r|| b <= l) return INF;
    else if(a <= l && r <= b) return m[k];
    else {
        int ta = query(a, b, k * 2 + 1, l, (l+r)/2);
        int tb = query(a, b, k * 2 + 2, (l + r)/2, r);
        return min(ta, tb);
    }
}
int main (void)
{
    int n, _m;
    scanf("%d%d",&n,&_m);
    build(0, 0, n);
    update(0, 0, 0, 0, n);
    for(int i = 0; i < _m; i++) {
            scanf("%d%d",&a[i],&b[i]);
            int t = query(a[i]-1, b[i], 0, 0, n) + 1;
            update(b[i]-1, t, 0, 0, n);
    }
    printf("%d\n",query(n-1, n, 0, 0, n));
}


#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXN 31
#define MAXL 26

struct Coordinate{
    int x, y;
}lt[MAXL], rb[MAXL];

struct Letter {
    vector<int> covered;
    int in;
    bool exist;
}let[MAXL];

int row, col;
int total;
char ans[MAXL+1];
char board[MAXN][MAXN];

void dfs(int len)
{
    if (len == total)
    {
        ans[len] = '\0';
        printf("%s\n", ans);
        return;
    }

    for (int i = 0; i < MAXL; i++)
    {
        if (!let[i].exist) continue;
        if (let[i].in == 0)
        {
            ans[len] = i + 'A';
            let[i].in--;
            for (int j = 0; j < let[i].covered.size(); j++)
                let[let[i].covered[j]].in--;
            dfs(len + 1);
            for (int j = 0; j < let[i].covered.size(); j++)
                let[let[i].covered[j]].in++;
            let[i].in++;
        }
    }

}

int main()
{
    while (scanf("%d%d", &row, &col) != EOF)
    {
        total = 0;
        memset(let, 0, sizeof(let));
        memset(lt, 0x3f, sizeof(lt));
        memset(rb, -1, sizeof(rb));
        for (int i = 0; i < row; i++)
        {
            scanf("%s", board[i]);
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == '.') continue;
                int t = board[i][j] - 'A';
                if (!let[t].exist)
                    let[t].exist = ++total;
                lt[t].x = min(lt[t].x, i);
                lt[t].y = min(lt[t].y, j);
                rb[t].x = max(rb[t].x, i);
                rb[t].y = max(rb[t].y, j);
            }
        }
        for (int k = 0; k < MAXL; k++)
        {
            if (!let[k].exist) continue;
            for (int i = lt[k].x; i <= rb[k].x; i++)
                for (int j = lt[k].y; j <= rb[k].y; j++)
                {
                    if (i > lt[k].x && i < rb[k].x && j == lt[k].y + 1)
                        j = rb[k].y;
                    int cur = board[i][j] - 'A';
                    if (cur == k) continue;
                    let[k].covered.push_back(cur);
                    let[cur].in++;
                }
        }
        dfs(0);
    }

    return 0;
}

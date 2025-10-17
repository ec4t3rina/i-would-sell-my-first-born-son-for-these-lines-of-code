#include <fstream>
#include <vector>
#include <queue>
#define INF 1000000001
using namespace std;

ifstream cin("dijkstra.in");
ofstream cout("dijkstra.out");
long long d[50001];
bool inCoada[50001];
vector <int> C[50001],G[50001];

struct cmp{
    bool operator()(int x,int y)
    {
        return d[x]>d[y];
    }
};

void dijkstra(int start)
{
    priority_queue <int, vector<int>,cmp> Q;
    Q.push(start);
    d[start]=0;
    inCoada[start]=1;
    while(!Q.empty())
    {
        int x=Q.top();
        inCoada[x]=0;
        Q.pop();
        for(unsigned int i=0;i<G[x].size();++i)
        {
            int j=G[x][i];
            if(d[j]>d[x]+C[x][i])
            {
                d[j]=d[x]+C[x][i];
                if(!inCoada[j])
                {
                    inCoada[j]=1;
                    Q.push(j);
                }
            }
        }
    }
}

struct cmp {
    bool operator() (int x, int y) {
        return dp[x]>dp[y];
    }
}



struct cmp {
    bool operator() (int x, int y) {
        return dp[x]>dp[y];
    }
}

void dijkstra(int start) {
    dp[start] = 0;
    priority_queue<int, vector<int>, cmp> q;
    q.push(start);
    mark[start] = 1;
    while (!q.empty()) {
        x = q.top();
        mark[x] = 1;
        q.pop();
        for (vecin) {
            if (d[vecin]>d[nod]+c[nod][i]) {
                d[vecin] =
                if (mark[d]==0) {
                    mark(d) = 1;
                    q.push(j);
                }
            }
        }
    }
}


struct cmp {
    bool operator() (int x, int y) {
        return dp[x]>dp[y];
    }
}

void dijkstra(int start) {
    int vecin, mark;
    priority_queue<int, vector<int>, cmp> q;
    
    dp[start] = 0;
    q.push(start);
    mark[start] = 1;
    while (!q.empty()) {
        nod = q.top();
        mark[nod] = 1;
        q.pop();
        for (vecin) {
            if dp[vecin]>
                if (skjdh) {
                    bagam in coada
                }
        }
        
        
        
    }
    
}




int main() {
    int n, m, i;
    
    scanf("%d%d", &n, &m);
    
    for(i=1; i<=m; i++) {
        int x,y,c;
        cin>>x>>y>>c;
        g[x].push_back(y);
        c[x].push_back(c);
    }
    
    for(int i=1;i<=n;++i)
        dp[i]=INF;
    
    dijkstra(1);
    
    for(int i=2;i<=n;++i)
        if(dp[i]==INF) cout<<"0 ";
        else cout<<d[i]<<' ';
    return 0;
}

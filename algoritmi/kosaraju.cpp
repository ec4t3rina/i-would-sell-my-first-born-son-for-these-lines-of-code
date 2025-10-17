#include <iostream>
#include <vector>

using namespace std;

#define NMAX 101

vector <int> g[NMAX];
vector <int> gt[NMAX];

int f[NMAX];

int st[NMAX];
int k;


void dfs(int nod) {
    int nou, i;
    
    f[nod] = 1;
    
    for (i=0; i<g[nod].size(); i++) {
        nou = g[nod][i];
        if (f[nou]==0) {
            dfs(nou);
        }
    }
    
    st[k] = nod;
    k++;
}

void dfst(int nod) {
    int nou, i;
    
    f[nod] = 1;
    
    for (i=0; i<gt[nod].size(); i++) {
        nou = gt[nod][i];
        if (f[nou]==0) {
            dfst(nou);
        }
    }
}

int main() {
    FILE *fin, *fout;
    fin = fopen("kosaraju.in", "r");
    fout = fopen("kosaraju.out", "w");
    
    int n, m, a, b, cnt, i;
    
    scanf("%d%d", &n, &m);
    
    for (i=0; i<m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    
    for (i=1; i<=n; i++) {
        if (f[i]==0) {
            dfs(i);
        }
    }
    
    for (i=1; i<=n; i++) {
        f[i] = 0;
    }
    
    cnt = 0;
    for (i=k-1; i>=0; i--) {
        if (f[st[i]]==0) {
            dfst(st[i]);
            cnt++;
        }
    }
    
    printf("%d\n", cnt);
    
    
    fclose(fin);
    fclose(fout);
    return 0;
}

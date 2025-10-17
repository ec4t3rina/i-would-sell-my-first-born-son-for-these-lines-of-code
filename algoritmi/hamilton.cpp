#include <iostream>
#include <vector>

using namespace std;

#define NMAX 18
#define INF 1000000002

int dp[NMAX][1<<NMAX];
int a[NMAX][NMAX];

int main() {
    FILE *fin, *fout;
    fin = fopen("hamilton.in", "r");
    fout = fopen("hamilton.out", "w");
    
    int n, m, x, y, c, mask, l, i, j, rez;
    
    fscanf(fin, "%d%d", &n, &m);
    
    for (l=0; l<n; l++) {
        for (c=0; c<n; c++) {
            a[l][c] = INF;
        }
    }
    
    for (mask=0; mask < (1<<n); mask++) {
        for (i=0; i<n; i++) {
            dp[i][mask] = INF;
        }
    }
    
    for (i=0; i<m; i++) {
        fscanf(fin, "%d%d%d", &x, &y, &c);
        a[x][y] = c;
        a[x][x] = a[y][y] = 0;
    }
    
    dp[0][1] = 0;
    for (mask=0; mask<(1<<n); mask++) {
        for (i=0; i<n; i++) {
            if (mask & (1<<i)) {
                for (j=0; j<n; j++) {
                    if (!(mask & (1<<j))) {
                        dp[j][mask+(1<<j)] = min(dp[j][mask+(1<<j)], dp[i][mask]+a[i][j]);
                    }
                }
            }
        }
    }
    
    rez = INF;
    for (i=0; i<n; i++) {
        if (rez > dp[i][(1<<n)-1]+a[i][0]) {
            rez = dp[i][(1<<n)-1]+a[i][0];
        }
    }
    
    if (rez==INF) {
        fprintf(fout, "Nu exista solutie");
    } else {
        fprintf(fout, "%d", rez);
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}

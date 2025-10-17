#include <iostream>
#include <vector>

using namespace std;

#define NMAX 102
#define NCOADA 400

int a[NMAX][NMAX];
int lee[NMAX][NMAX];

int coadal[NMAX];
int coadac[NMAX];

int prim, ultim;

static inline void enqueue(int l, int c) {
    coadal[ultim] = l;
    coadac[ultim] = c;
    ultim = (ultim+1)%NCOADA;
}

static inline int dequeue() {
    int retval;
        
    retval = coadal[prim] * 256 + coadac[prim];
    prim = (prim+1)%NCOADA;
        
    return retval;
}

static inline int emptyqueue() {
    return prim==ultim;
}

int dlin[4] = {0, 1, 0, -1};
int dcol[4] = {1, 0, -1, 0};

int main() {
    FILE *fin, *fout;
    fin = fopen("lee.in", "r");
    fout = fopen("lee.out", "w");
    
    int n, m, l, c, lstart, cstart, dist, i, retval, ll, cc;
    
    lstart = cstart = 1;
    prim = ultim = 0;
    enqueue(lstart, cstart);
    do {
        retval = dequeue();
        l = retval/256;
        c = retval%256;
        dist = lee[l][c];
        for (i=0; i<4; i++) {
            ll = l+dlin[i];
            cc = c+dcol[i];
            if (lee[ll][cc]==0 && a[ll][cc]==0) {
                lee[ll][cc] = dist+1;
                enqueue(ll, cc);
            }
        }
    } while (!emptyqueue());
    
    
    
    fclose(fin);
    fclose(fout);
    return 0;
}

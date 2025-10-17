#include <iostream>

#define NMAX 101

int v[NMAX];

int main() {
    FILE *fin, *fout;
    fin = fopen("heap.in", "r");
    fout = fopen("heap.out", "w");
    
    int n, i;
    
    scanf("%d", &n);
    
    for (i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    
    st = 0;
    dr = n;
    while (dr-st>1) {
        mijl = (st+dr)/2;
        if (v[mijl]>e) {
            dr = mijl;
        } else {
            st = mijl;
        }
    }
    
    if (v[st]==e) {
        ///gasit, procesare aici...
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}

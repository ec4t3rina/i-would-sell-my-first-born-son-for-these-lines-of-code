#include <iostream>
#include <vector>

using namespace std;

#define NMAX 100

char ciur[NMAX+1];

int main() {
    FILE *fin, *fout;
    fin = fopen("ciur.in", "r");
    fout = fopen("ciur.out", "w");
    
    int d, i;
    
    for (d=2; d*d<=NMAX; d++) {
        if (ciur[d]==0) {
            for (i=d*d; i<=NMAX; i+=d) {
                ciur[i] = 1;
            }
        }
    }
    
    
    fclose(fin);
    fclose(fout);
    return 0;
}

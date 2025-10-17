#include <iostream>
#include <vector>

using namespace std;

int fastexp(int b, int e) {
    int p;
    
    p = 1;
    while (e>0) {
        if (e%2==1) {
            p*=b;
        }
        b*=b;
        e/=2;
    }
    
    return p;
}

int main() {
    FILE *fin, *fout;
    fin = fopen("exp-rapida.in", "r");
    fout = fopen("exp-rapida.out", "w");
    
    int b, e, rez;
    
    scanf("%d%d", &b, &e);
    
    rez = fastexp(b, e);
    
    printf("%d\n", rez);
    
    
    fclose(fin);
    fclose(fout);
    return 0;
}

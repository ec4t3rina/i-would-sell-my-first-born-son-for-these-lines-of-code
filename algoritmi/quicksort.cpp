#include <iostream>

#define NMAX 101

int v[NMAX];



void myqosrt(int begin, int end) {
    int b, e, aux, pivot;
    
    b = begin;
    e = end;
    pivot = v[(b+e)/2];
    
    while (v[b]<pivot) {
        b++;
    }
    while (v[e]>pivot) {
        e--;
    }
     
    while (b<e) {
        aux = v[b];
        v[b] = v[e];
        v[e] = aux;
        do {
            b++;
        } while (v[b]<pivot);
        do {
            e--;
        } while (v[e]>pivot);
    }
    
    if (begin<e) {
        myqosrt(begin, e);
    }
    if (e+1 < end) {
        myqosrt(e+1, end);
    }
}


void myqsort(int begin, int end) {
    int b, e, pivot, aux;
    
    b = begin;
    e = end;
    pivot = v[(b+e)/2];
    
    while (v[b]<pivot) {
        b++;
    }
    while (v[e]>pivot) {
        e--;
    }
    while (b<e) {
        aux = v[b];
        v[b] = v[e];
        v[e] = aux;
        do {
            b++;
        } while (v[b]<pivot);
        do {
            e--;
        } while (v[e]>pivot);
    }
    
    if (begin < e) {
        myqsort(begin, e);
    }
    if (e+1 < end) {
        myqsort(e+1, end);
    }
}

/*
void myqsort( int begin, int end ) {
  int aux, b = begin, e = end,
    pivot = v[(begin + end) / 2]; // poate fi orice pozitie intre begin si end - 1

  while (v[b] < pivot) // cauta primul element mai mare sau egal cu pivotul
    b++;

  while (v[e] > pivot) // cauta primul element mai mic sau egal cu pivotul
    e--;

  while( b < e ) { // daca indicii nu s-au atins
    aux = v[b];    // interschimba elementele la pozitiile b si e
    v[b] = v[e];
    v[e] = aux;
    
    do // cauta primul element mai mare sau egal cu pivotul
      b++;
    while (v[b] < pivot);

    do // cauta primul element mai mic sau egal cu pivotul
      e--;
    while (v[e] > pivot);
  }

  // acum [begin..e] sint mai mici sau egale cu pivotul
  if ( begin < e )
    myqsort(begin, e);
  // si [e+1..end] sint mai mari sau egale cu pivotul
  if ( e + 1 < end )
    myqsort(e + 1, end);
}
*/

int main() {
    FILE *fin, *fout;
    fin = fopen("heap.in", "r");
    fout = fopen("heap.out", "w");
    
    int n, i;
    
    scanf("%d", &n);
    
    for (i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    
    myqosrt(0, n-1);
    
    for (i=0; i<n; i++) {
        printf("%d ", v[i]);
    }

    
    fclose(fin);
    fclose(fout);
    return 0;
}

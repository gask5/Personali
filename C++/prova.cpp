#include <iostream>

using namespace std;

template <class T>
void mergesort(T *v, int n);

template <class T>
void merge(T *v, int n, int m);
void stampa(int *v, int n);
void scambia(int *v, int i, int j);
void selectionsort(int *v, int n);
void r_insertionsort(int *v, int n);
void insertionsort(int *v, int n);

int main()
{
    int v[] = {6, 2, 8, 1, 4, 9, 22, 3, 19, 10};
    stampa(v, 10);
    mergesort(v, 10);
    stampa(v, 10);
}

template <class T>
void mergesort(T *v, int n) // l'altezza del mergesort e' uguale a log2(n); complessita` O(nlog2(n)) detta anche complessita` linearitmica ( lineare * logaritmica);
{
    if (n <= 1)
        return;
    int m = n / 2;
    mergesort(v, m);
    mergesort(v + m, n - m);
    merge(v, n, m); //funzione ausiliaria poiche` il mergesort non e` in grado di lavorare in loco;
}

template <class T>
void merge(T *v, int n, int m) // complessita` O(n)
{
    T b[n]; // array ordinato;
    int i, j, k;
    i = k = 0;
    j = m;
    while (i<m && j<n) // scorro i due array con gli indici i  e j;
    {
        if (v[i]<v[j]) b[k++] = v[i++]; // confronto i primi due elementi degli array divisi , e quello piu` piccolo lo inserisco nell'array b;
        else b[k++] = v[j++];
    }
    while(i<m) b[k++] = v[i++];
    while(j<n) b[k++] = v[j++];
    for (int i = 0; i < n; i++)
    {
        v[i] = b[i];
    }
}

void stampa(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void scambia(int *v, int i, int j)
{
    int tmp = v[j];
    v[j] = v[i];
    v[i] = tmp;
}

void selectionsort(int *v, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[m])
            {
                m = j;
            }
        }
        scambia(v, i, m);
    }
}

void r_insertionsort(int *v, int n)
{
    if (n <= 1)
        return;
    r_insertionsort(v, n - 1);
    int j = n - 2;
    while (j >= 0 && v[j + 1] < v[j])
    {
        scambia(v, j, j + 1);
        cout << "Scambio" << v[j] << " con " << v[j + 1] << endl;
        j--;
    }
}

void insertionsort(int *v, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            scambia(v, j, j - 1);
            j--;
        }
    }
}
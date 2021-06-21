#include "funzioniripasso.hpp"
#include <cstdlib>
#include <chrono>
#include <sstream>

uint64_t ms() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}    

void randomFill(int* a, int n){
    for(int i=0;i<n;i++){
        a[i] = rand()%n + 1;
    }
}

void measureTime( void f(int*,int), int* a, int n, string name){

    randomFill(a,n);

    uint64_t time;
    stringstream stream;

    stream<< name <<" started..."<<endl;
    cout<<colors(stream.str(),2,3);

    time = ms();
    f(a,n);

    stream.str("");

    stream << name <<" ended in "<< ( ms()-time )<< " ms";
    cout<<colors(stream.str(),1,1)<<endl;
}

int main(){
    const int N = 25000;
    //int a[N]= {23,12,2,4,51,7,20,14,6,3};
    //int b[N]= {13,5,22,124,1,17,10,11,36,0};
    int* c = new int[N];
    //print(c,N);
    measureTime(bubblesort,c,N,"Bubble Sort");
    measureTime(insertionsort,c,N,"Insertion Sort");
    measureTime(selectionsort,c,N,"Selection Sort");
    measureTime(mergeSort,c,N,"Merge Sort");
    measureTime(quicksort,c,N,"Quick Sort");
    
    //print(c,N);
    
    // cout<<endl<<"Passi eseguiti: "<< passi<<endl;

}

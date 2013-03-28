#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iterator>
#include <set>
#include <algorithm>
#include <time.h>

#define maxn 111

using namespace std;

int n,sl;
int num[maxn];

void push(int a,int b,int c,int d,int e,int f){
    sl++;
    num[sl]=a;
    sl++;
    num[sl]=b;
    sl++;
    num[sl]=c;
    sl++;
    num[sl]=d;
    sl++;
    num[sl]=e;
    sl++;
    num[sl]=f;
}

int main(){
    srand(time(0));
    freopen("10.inp","w",stdout);
    int a,b,c,d,e,f;
    int i,u,v;
    n=100;
    sl=0;
    while (sl<=n-12){
        a=rand()%101;
        i=rand()%2;
        if (i==1) a=-a;
        b=rand()%101;
        i=rand()%2;
        if (i==1) b=-b;
        c=rand()%101;
        i=rand()%2;
        if (i==1) c=-c;
        d=1;
        v=abs(a*b+c);
        for (i=2;i<=min(100,int(sqrt(v)));i++)
            if (v%i==0) d=v;
        u=(a*b+c)/d;
        e=rand()%101;
        i=rand()%2;
        if (i==1) e=-e;
        f=u-e;
        push(a,b,c,d,e,f);
        i=rand()%5;
        if (i==0) push(-a,-b,c,d,e,f);
        if (i==1) push(-a,b,-c,-d,e,f);
        if (i==2) push(a,-b,-c,d,-e,-f);
        if (i==3) push(a,b,c,-d,-e,-f);
    }
    while (sl<n){
        sl++;
        num[sl]=rand()%101;
        i=rand()%2;
        if (i==1) num[sl]=-num[sl];
    }
    for (i=1;i<=100000;i++){
        u=rand()%n+1;
        v=rand()%n+1;
        swap(num[u],num[v]);
    }
    cout<<n<<"\n";
    for (i=1;i<=n;i++) cout<<num[i]<<"\n";
}

#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstdlib>
using namespace std;

int main(){
//Индексная переменная:
int i;
double x;
//Граница ряда:
int n_max=100;
//Аргумент функции и "рабочие" переменные:
double p,sum=0.0;
//Вычисление ряда:
for(i=1;i <=n_max;i++)
{
   p=double(pow(-1,i)/(sin(i*x)+25+i*i));
   sum+=p;
}
//Результат:
cout<<"sum = "<<fixed<<setprecision(10)<<sum<<endl;
return 0;
}

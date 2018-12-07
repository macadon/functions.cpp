#include <iostream>
#include <cmath>

using namespace std;

int sum(int n1, int n2) {
int total=0;
for(int i=n1;i<=n2;i++){
total+=i;
}
return total;
}

int print (int n1, int n2) {
for (int i=n1;i<=n2;i++) {
cout<<i<<endl;
}
}

int fib(int n){
if(n==0||n==1){
return 1;
}
else{
return fib(n-1)+fib(n-2);
}
}

double normcdf(double x){
double pi=3.141592653;
double m=1/sqrt(2*pi);
double k=1/(1+0.2316419*x);
if(x>0) {
return 1-(m)*k*exp(-x*x*0.5)*(0.319381530+k*(-0.356563782+k*(1.781477937+k*(-1.821255978+1.330274429*k))));
}
else {
return 1-normcdf(-x);
}


}


double BS(double S0, double r, double T, double sigma, double K)
{
double d1 = (log(S0/K)+(r+sigma*sigma*0.5)*sqrt(T))*(1/sigma)*(1/sqrt(T));
double d2 = (log(S0/K)+(r-sigma*sigma*0.5)*sqrt(T))*(1/sigma)*(1/sqrt(T));

return normcdf(d1)*S0-normcdf(d2)*K*exp(-r*T);





}
double Homerzero(double x, double a0) {
        return a0;
}

double Homerone(double x, double a0, double a1){
        return a0+x*Homerzero(x,a1);
}

double Homertwo(double x, double a0, double a1, double a2) {
        return a0+x*Homerone( x,  a1,  a2);
}

double Homerthree(double x, double a0, double a1, double a2, double a3) {
        return a0+x*Homertwo( x,  a1,  a2,  a3);
}

double Homerfour(double x, double a0, double a1, double a2, double a3, double a4) {
        return a0+x*Homerthree(x, a1,  a2,  a3,  a4);
}

double Homerfive(double x, double a0, double a1, double a2, double a3, double a4, double a5) {
        return a0+x*Homerfour(x, a1, a2, a3, a4, a5);
        }
double Homersix(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6){
        return a0+x*Homerfive(x,a1,a2,a3,a4,a5,a6);
}

double Homerseven(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7) {
        return a0+x*Homersix(x,a1,a2,a3,a4,a5,a6,a7);
}
double Homereight(double x, double a0, double a1, double a2, double a3, double $
        return a0+x*Homerseven(x,a1,a2,a3,a4,a5,a6,a7,a8);
}
 double a0 = 2.50662823884;
 double a1 = -18.61500062529;
 double a2 = 41.39119773534;
 double a3 = -25.44106049637;
 double b1 = -8.47351093090;
 double b2 = 23.08336743743;
 double b3 = -21.06224101826;
 double b4 = 3.13082909833;
 double c0 = 0.3374754822726147;
 double c1 = 0.9761690190917186;
 double c2 = 0.1607979714918209;
 double c3 = 0.0276438810333863;
 double c4 = 0.0038405729373609;
 double c5 = 0.0003951896511919;
 double c6 = 0.0000321767881768;
 double c7 = 0.0000002888167364;
 double c8 = 0.0000003960315187;

double norminv(double z) {
double y=z-0.5;


if (y<0.42 && y>-0.42) {
        double r=y*y;
        return y*(Homerthree(r,a0,a1,a2,a3)/Homerfour(r,1.0,b1,b2,b3,b4));
        }
else   {
        double r;
        if(y<0){
        r=z;
        }
        else{
        r=1-z;
        }
        double s=log(-log(r));
        double t=Homereight(s,c0,c1,c2,c3,c4,c5,c6,c7,c8);
        if (z>0.5) {
        return t;
        }
else {
        return -t;
        }
}




}




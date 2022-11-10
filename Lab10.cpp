#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::pow;
using namespace std;

double Fn(double x){
    return  (-6*pow(x,2)) + 5*x + 3;
}
double Integral(double x){
    return (-2*pow(x,3)) + (5.0/2.0)*(pow(x,2)) + (3*x);
}

double EstimateWithTraps(double a, double b, int n){
    double num = (b-a)/double(n);
    double sum = 0;
    for (double i=0;i<n;i++){
        double x = a+(i*num);
        double x2 = a+((i+1)*num);
        double y1 = Fn(x);
        double y2 = Fn(x2);
        double delta_x = x2-x;
        double area = ((y1+y2)/2)*delta_x;
        sum+= area;
    }
    return sum;

}      

int main(){

    double a,b,tolerance;
    int n;
    cout<<"Lower Range:"<<endl;
    cin>>a;
    cout<<"Upper Range:"<<endl;
    cin>>b;
    cout<<"Tolerance:"<<endl;
    cin>>tolerance;
    cout<<"Initial trapezoid count:"<<endl;
    cin>>n;
    double diff;
    while(true){
        cout<<fixed<<setprecision(4);
        diff = std::abs((Integral(b)-Integral(a))-EstimateWithTraps(a, b,n));
        cout<<"Estimate:"<<EstimateWithTraps(a, b,n)<<", "<<"Number of Traps:"<<n<<", Diff:"<<diff<<endl;
        if(diff>tolerance){
            n*=2;
            continue;
        }
        else if (diff<=tolerance){
            break;
        }
    }

    
}

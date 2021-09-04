double u(double a); //declaring function

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

int main(){

  double n = 1000;
  //defining vectors
  std::vector<double> x(n);
  std::vector<double> y(n);

  //opens file
  std::ofstream f;
  f.open("out.txt");

  //runs through i = 0 to 1 = 1000
  for (int i = 0; i <= n; i++){
    //making temporary values
    double tmp = i/n;
    double utmp = u(tmp);
    //pushes values to vector
    x[i] = tmp;
    y[i] = utmp;
    //prints in terminal and to file
    std::cout << tmp << " , " << utmp << "\n";
    f << tmp << ' ' << utmp << "\n";
  }
  //closing file
  f.close();
  return 0;
}

//defining function
double u(double a){
    double result =1 -std::exp(-10*a) - (1-std::exp(-10))*a;
    return result;
}

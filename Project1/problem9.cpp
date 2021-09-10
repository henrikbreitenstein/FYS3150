#include "problem9.hpp"
#include <iostream>
#include <cmath>
int main(){
  int n=10; //Changing manually
  arma::vec G=arma::vec(n).fill(0.);
  arma::vec x=arma::vec(n+2).fill(0.);
  double h=1/double(n+1);
  arma::vec i1=arma::vec(n).fill(0.);
  arma::vec i2=arma::vec(n).fill(0.);
  for (int i=0; i<=i1.size()-1;i++){
    i1(i)=1.*i/(i+1);
    i2(i)=1.*(i+1)/(i+2);
  }
  auto t1 = std::chrono::high_resolution_clock::now();
  for (int j=0;j<=(n+1);j++){
    x(j)=j*h;
  }
  for (int j=0;j<=(n-1);j++){
    G(j)=100*exp((-10)*x(j+1))*(h*h);
  }
  arma::vec v=arma::vec(n).fill(0.);
  arma::vec Gtilde=forsub(G, i1);
  arma::vec vnew=backsub(Gtilde, v, i2);
  auto t2 = std::chrono::high_resolution_clock::now();
  //std::cout<<vnew<<std::endl;
  double duration_seconds = std::chrono::duration<double>(t2 - t1).count();
  std::cout<<duration_seconds<<std::endl;
  write(x, vnew, n);
  return 0;
}

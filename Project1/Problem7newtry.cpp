#include <iostream>
#include "Problem7.hpp"
#include <armadillo>

int main(){
  int n=10;
  arma::mat U=arma::mat(n, n).fill(0.);
  arma::vec G=arma::vec(n);
  arma::vec a=arma::vec(n-1).fill(-1.);
  arma::vec b=arma::vec(n).fill(2.);
  arma::vec c=arma::vec(n-1).fill(-1.);
  U(0,0)=b(0);
  for(int p=1;p<n;p++){
    U(p,p-1)=a(p-1);
    U(p,p)=b(p);
    U(p-1,p)=c(p-1);
  }
  std::cout<<U<<std::endl;

  matvec UGNEW=forsub( U , G );
  arma::mat Unew=UGNEW[0];
  arma::mat Gnew=UGNEW[1];
  std::cout<<Unew<<std::endl;
  std::cout<<Gnew<<std::endl;
  return 0;
}


#include "project73.hpp"
#include <iostream>
#include <cmath>

int main(){
  int n=100;
  arma::vec G=arma::vec(n).fill(0.);
  arma::vec x=arma::vec(n+2).fill(0.);
  double h=1/double(n+1);
  for (int j=0;j<=(n+1);j++){
    x(j)=j*h;
  }
  for (int j=0;j<=(n-1);j++){
    G(j)=100*exp((-10)*x(j+1))*(h*h);
  }
  arma::vec v=arma::vec(n).fill(0.);
  //std::cout<<G<<std::endl;
  arma::vec a=arma::vec(n-1).fill(-1.);
  arma::vec b=arma::vec(n).fill(2.);
  arma::vec c=arma::vec(n-1).fill(-1.);
  //G.print();
  vecvec UGtilde=forsub(a,b,c,G);
  arma::vec atilde=UGtilde.H;
  arma::vec btilde=UGtilde.I;
  arma::vec ctilde=UGtilde.J;
  arma::vec Gtilde=UGtilde.K;
  //std::cout<<Gtilde<<std::endl;
  //std::cout<<Gtilde<<std::endl;
  vecvec UGstar=backsub(v,btilde,ctilde,Gtilde);
  arma::vec vnew=UGstar.H;
  arma::vec bstar=UGstar.I;
  arma::vec cstar=UGstar.J;
  arma::vec Gstar=UGstar.K;
  vnew.print();
  //std::cout<<vnew<<std::endl;
  return 0;
  write(x, vnew, n);
}


#include "Problem7.hpp"
#include <iostream>

int main(){
  int n=100;
  arma::mat U=arma::mat(n, n).fill(0.);
  arma::vec G=arma::vec(n).fill(0.);
  for (int j=0;j<=(n-1);j++){
    double x=(j+1)/double(n+1);
    G(j)=100*std::exp((-10)*x);
  }
  std::cout<<G<<std::endl;
  arma::vec a=arma::vec(n-1).fill(-1.);
  arma::vec b=arma::vec(n).fill(2.);
  arma::vec c=arma::vec(n-1).fill(-1.);
  U(0,0)=b(0);
  for(int p=1;p<n;p++){
    U(p,p-1)=a(p-1);
    U(p,p)=b(p);
    U(p-1,p)=c(p-1);
  }
  //std::cout<<U<<std::endl;

  matvec UGtilde=forsub(U,G);
  arma::mat Utilde=UGtilde.O;
  arma::vec Gtilde=UGtilde.P;
  std::cout<<Utilde<<std::endl;
  std::cout<<Gtilde<<std::endl;
  std::cout<<Utilde(int(G.size())-2, int(G.size())-2)<<std::endl;
  matvec UGstar=backsub(Utilde, Gtilde);
  arma::mat Ustar=UGstar.O;
  arma::vec Gstar=UGstar.P;
  std::cout<<Ustar<<std::endl;
  std::cout<<Gstar<<std::endl;
  matvec UGnew=toone(Ustar, Gstar);
  arma::mat Unew=UGnew.O;
  arma::vec Gnew=UGnew.P;
  //std::cout<<Unew<<std::endl;
  std::cout<<Gnew<<std::endl;
  return 0;
}

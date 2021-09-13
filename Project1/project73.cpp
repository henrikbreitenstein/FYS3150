
#include "project73.hpp"
#include <iostream>
#include <cmath>
#include <chrono>

int main(){
  //start timing
  std::ofstream fs;
  fs.open("Textfiles/timinggen.txt", std::ios::out | std::ios::trunc);
  for (int num = 1; num < 5; num++){
    for (int rep = 1; rep < 101; rep++){ // repaet 100 times
      int n = std::pow(10, num);
      arma::vec G=arma::vec(n).fill(0.);
      //arma::vec x=arma::vec(n+2).fill(0.);
      arma::vec x = arma::linspace(0, 1, n+2);
      double h = x(1)-x(0);
      //double h=1/double(n+1);
      //for (int j=0;j<=(n+1);j++){
      //  x(j)=j*h;
      //}
      //G = 100*arma::exp(-10*x)*h*h;
      for (int j=0;j<=(n-1);j++){
        G(j)=100*exp((-10)*x(j+1))*(h*h);
      }
      arma::vec v=arma::vec(n).fill(0.);
      //std::cout<<G<<std::endl;
      arma::vec a=arma::vec(n-1).fill(-1.);
      arma::vec b=arma::vec(n).fill(2.);
      arma::vec c=arma::vec(n-1).fill(-1.);
      //G.print();
      auto t1 = std::chrono::high_resolution_clock::now();
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
      auto t2 = std::chrono::high_resolution_clock::now();
      //vnew.print();
      //std::cout<<vnew<<std::endl;
      //std::cout<<x(n+1)<<std::endl;
      //std::cout<<vnew.size()<<std::endl;
      //write(x, vnew, n);
      double duration_seconds = std::chrono::duration<double>(t2 - t1).count();
      std::cout << "Duration:" << duration_seconds << std::endl;//Changing manually
      fs << n << " " << duration_seconds << std::endl;

    }
  }

  fs.close();
  return 0;
}

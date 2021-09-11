double f(double x); //Function f(x)

#include <iostream>
#include <armadillo>
#include <cmath>
#include <fstream>

int main(){
  int start = 0;
  double end = 1;
  int n = 1000;
  arma::vec x = arma::vec(n);
  arma::vec g = arma::vec(n);
  //Filling vectors with correct values
  x(0) = 0.;
  g(0) = f(0.);
  double h = (end-start)/n;
  for (int i = 0; i < n; i++){
    double tmp = i*h;
    x(i) = tmp;
    g(i) = f(tmp);
  }
  //Tridagonal matrix a, b and c, diagonals
  arma::vec a = arma::vec(n).fill(-1); int ao = -1;
  arma::vec b = arma::vec(n).fill(2); int bo = 2;
  arma::vec c = arma::vec(n).fill(-1); int co = -1;
  //Empty vector to fill inn with solutions
  arma::vec v = arma::vec(n);
  v(0) = 0.;
  v(n-1) = 0.;
  //Making btilde values into an array
  arma::vec btilde = arma::vec(n-1);
  arma::vec gtilde = arma::vec(n-1);
  arma::vec ghat = arma::vec(n-1);
  btilde(0) = bo;
  gtilde(0) = g(0);
  ghat(n-2) = gtilde(n-2);
  for (int i = 1; i < n-1; i++){
    double tmp = ao/btilde(i-1);
    btilde(i) = bo - tmp*co;
    gtilde(i) = g(i) - tmp*g(i-1);
  }
  for (int i = n-2; i > 0; i--){
    ghat(i-1) = gtilde(i-1) - co*ghat(i)/btilde(i);
  }
  for (int i=1; i < n-1; i++){
    v(i)=ghat(i)/(btilde(i));
  }
  std::fstream fs;
  fs.open("solution.txt", std::ios::out | std::ios::trunc);
  for (int i = 0; i < n; i++){
    fs << x(i) << "  " << v(i) << "\n";
  }
  fs.close();
  return 0;
}

double f(double x){
  double result = 100*std::exp(-10);
  return result;
}

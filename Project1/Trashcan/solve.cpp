double f(double x); //Function f(x)

#include <iostream>
#include <armadillo>
#include <cmath>
#include <fstream>

int main(){
  int start = 0;
  double end = 1;
  for (int count = 1; count < 15; count++){

      int n = 10*count;
      arma::vec x = arma::vec(n);
      arma::vec g = arma::vec(n);
      //Filling vectors with correct values
      x(0) = 0.;
      double h = (end-start)/n;
      g(0) = f(0.);

      for (int i = 0; i < n; i++){
        double tmp = i*h;
        x(i) = tmp;
        g(i) = h*h*f(tmp);
      }
      //Tridagonal matrix a, b and c, diagonals
      int ao = -1;
      int bo = 2;
      int co = -1;
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
        v[i] = (gtilde[i]-co*v[i+1])/btilde[i];
      }
      std::fstream fs;
      std::string s = "sol" + std::to_string(n) + ".txt";
      fs.open(s, std::ios::out | std::ios::trunc);
      for (int i = 0; i < n; i++){
        fs << x(i) << "  " << v(i) << "\n";
      }
      fs.close();
  }
  return 0;
}

double f(double x){
  double result = 100*std::exp(-10*x);
  return result;
}

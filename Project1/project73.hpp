#include <armadillo>

struct vecvec{
  arma::vec H;
  arma::vec I;
  arma::vec J;
  arma::vec K;
};
vecvec forsub(arma::vec a, arma::vec b, arma::vec c, arma::vec G);
vecvec backsub(arma::vec a, arma::vec b, arma::vec c, arma::vec G);
void write(arma::vec x, arma::vec v, int n);

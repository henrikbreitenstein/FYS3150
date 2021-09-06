#include <armadillo>

struct matvec{
  arma::mat O;
  arma::vec P;
};

matvec forsub(arma::mat U, arma::vec G);
matvec backsub(arma::mat U, arma::vec G);
matvec toone(arma::mat U, arma::vec G);

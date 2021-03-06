#ifndef PROBLEM_7_H
#define PROBLEM_7_H

#include <armadillo>

struct matvec{
  arma::mat O;
  arma::vec P;
};

matvec forsub(arma::mat U, arma::vec G);
void backsub(arma::mat U, arma::vec G);
void toone(arma::mat U, arma::vec G);

#endif

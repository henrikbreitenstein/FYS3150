#include "Problem7.hpp"
using namespace arma;

mat forsub(mat U, vec G){
  uword n =G.size();
  for(uword i=1;i<G.size();i++){
    double t= U(i,i-1)/U(i-1,i);
    U(i,i-1)=U(i,i-1)-t*U(i-1,i-1);
    U(i,i)=U(i,i-1)-U(i,i-1)*t;
    G(i)=G(i)-G(i-1)*t;
  }
  mat Unew=mat(n,n).fill(U.);
  return Unew;
}

void backsub(mat U, vec G){
  for(uword j=(int(G.size())-1);j>=0;j--){
    double k=U(j,j+1)/U(j+1,j);
    U(j,j+1)=U(j,j+1)-U(j+1,j+1)*k;
    U(j,j)=U(j,j)-U(j+1,j)*k;
    G(j)=G(j)-G(j+1)*k;
  }
}
void toone(mat U, vec G){
  for(uword l=0;l<G.size();l++){
    U(l)=U(l)/U(l);
    G(l)=G(l)/U(l);
  }
}

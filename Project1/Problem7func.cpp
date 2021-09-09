#include "Problem7.hpp"

matvec forsub(arma::mat U, arma::vec G){
  arma::uword n = G.size();
  for(arma::uword i=1;i<G.size();i++){
    double t= U(i,i-1)/U(i-1,i-1);
    U(i,i-1)=U(i,i-1)-t*U(i-1,i-1);
    U(i,i)=U(i,i)-U(i-1,i)*t;
    G(i)=G(i)-G(i-1)*t;
  }
  matvec UG={U, G};
  return UG;
}

matvec backsub(arma::mat U, arma::vec G){
  for(int j=(int(G.size())-2);j>=0;j--){
    //std::cout<<G.size()<<std::endl;
    double k=U(j,j+1)/U(j+1,j+1);
    U(j,j+1)=U(j,j+1)-U(j+1,j+1)*k;
    U(j,j)=U(j,j)-U(j+1,j)*k;
    G(j)=G(j)-G(j+1)*k;
  }
  matvec UG={U, G};
  return UG;
}
matvec toone(arma::mat U, arma::vec G){
  for(arma::uword l=0;l<G.size();l++){
    G(l)=G(l)/U(l,l);
    U(l,l)=U(l,l)/U(l,l);
  }
  matvec UG={U, G};
  return UG;
}
/*
void write(arma::vec x, arma::vec v){
  int n=G.size();
  std::fstream fs;
  std::string s = "sol7n" + std::to_string(n) + ".txt";
  fs.open(s, std::ios::out | std::ios::trunc);
  fs<<x(0)<<" "<< 0 << "\n";
  for (int i = 0; i < n; i++){
    fs << x(i) << "  " << v(i) << "\n";
  }
  fs<<x(n+1)<<" "<< 0<< "\n";
  fs.close();
}
*/

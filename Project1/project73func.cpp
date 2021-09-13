#include "project73.hpp"

vecvec forsub(arma::vec a, arma::vec b, arma::vec c, arma::vec G){
  arma::uword n = G.size();
  for(arma::uword i=1;i<=G.size()-1;i++){
    //std::cout<<i<<std::endl;
    double t= a(i-1)/b(i-1);
    //a(i)=a(i)-t*b(i-1);
    b(i)=b(i)-c(i-1)*t;
    G(i)=G(i)-G(i-1)*t;
    //std::cout<<G(i)<<std::endl;
  }
  vecvec UG={a, b, c, G};
  return UG;
}


vecvec backsub(arma::vec v, arma::vec b, arma::vec c, arma::vec G){
  int n=G.size();
  //std::cout<<G.size()<<std::endl;
  //std::cout<<v.size()<<std::endl;
  b(n-1)=b(n-1)/b(n-1);
  v(n-1)=G(n-1)/b(n-1);
  //std::cout<<"Got through b first"<<std::endl;
  for(int j=(int(n)-2);j>=0;j--){
    //std::cout<<j<<std::endl;
    //std::cout<<G.size()<<std::endl;
    //double k=c(j)/b(j+1);
    //c(j)=(c(j)-b(j+1)*c(j))/b(j);
    v(j)=(G(j)-c(j)*v(j+1))/b(j);
    //std::cout<<v(j)<<std::endl;
  }
  //v.print();
  vecvec UG={v, b, c, G};
  return UG;
}
/*
vecvec toone(arma::vec a, arma::vec b, arma::vec c,  arma::vec G){
  for(arma::uword l=0;l<G.size();l++){
    G(l)=G(l)/b(l);
    b(l)=b(l)/b(l);
  }
  vecvec UG={a, b, c, G};
  return UG;
}
*/
void write(arma::vec x, arma::vec v,int n){
  std::ofstream fs;
  std::string s = "Textfiles/sol7n" + std::to_string(n) + ".txt";
  //std::cout << s << std::endl;
  //std::ios::out | std::ios::trunc
  fs.open(s, std::ios::out | std::ios::trunc);
  fs << x(0) << "  " << 0 << "\n";
  for (int i = 0; i < n; i++){
    fs << x(i+1) << "  " << v(i) << "\n";
  }
  fs << x(n+1) << "  " << 0 << "\n";
  fs.close();
}

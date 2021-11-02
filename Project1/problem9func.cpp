#include "project73.hpp"

arma::vec forsub(arma::vec G, arma::vec i1){
  arma::uword n= G.size();
  for(arma::uword i=1;i<=G.size()-1;i++){
    G(i)=G(i)+G(i-1)*i1(i);
  }
  return G;
}

arma::vec backsub(arma::vec G, arma::vec v, arma::vec i2){
  arma::uword n=G.size();
  v(n-1)=G(n-1)*1.*(n+1)/(n+2);
  for(int i=(int(n)-2);i>=0;i--){
    //v(i)=G(i)+(1.*i*v(i+1))/(i+1);
    v(i) = ( G(i) + v(i+1) )*i2(i);
  }
  return v;
}
void write(arma::vec x, arma::vec v,int n){
  std::ofstream fs;
  std::string s = "Textfiles/sol9n" + std::to_string(n) + ".txt";
  std::cout << s << std::endl;
  //std::ios::out | std::ios::trunc
  fs.open(s, std::ios::out | std::ios::trunc);
  fs << x(0) << "  " << 0 << "\n";
  for (int i = 0; i < n; i++){
    fs << x(i+1) << "  " << v(i) << "\n";
  }
  fs << x(n+1) << "  " << 0 << "\n";
  fs.close();
}

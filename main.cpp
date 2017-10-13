#include<iostream>
#include"BigInteger.h"

int main() {
  BigInteger bg("5002");
  BigInteger bg1("520");
  BigInteger bgg = bg1-bg;
  bgg.printBigInteger();

  std::cout<<std::endl;
  BigInteger bg_sum("4569887530");
  BigInteger bg1_sum("1111456685880");
  BigInteger bggg = bg1_sum + bg_sum;
  bggg.printBigInteger();

  return 0;
}

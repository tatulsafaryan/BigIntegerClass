#include<iostream>
#include"BigInteger.h"
BigInteger::BigInteger(){
}
BigInteger::BigInteger(const std::string& number) {
   try{
    for(int i = 0; i < number.length(); ++i){
       if((int)number[i] < 48 || (int)number[i]> 57){
         throw "Error";
       }
       this->Number.push((int)(number[i] - 48));
     }
   }
   catch(const char* x){
     std::cout<<x<<": invalid BigInteger type ";
     exit(EXIT_FAILURE);
   }
}
void BigInteger::printBigInteger() {
  this->Number.print();
  std::cout<<std::endl;
}
BigInteger& BigInteger::operator=(const BigInteger& obj){
  if(this == &obj)
     return *this;
  this->Number = obj.Number;
  return *this;
}
BigInteger operator+(const BigInteger& bgi1,const BigInteger& bgi2){
  BigInteger bgi;
  bgi.Number = bgi.Number.sum(bgi1.Number,bgi2.Number);
  return bgi;
}
 BigInteger operator-(const BigInteger& bgi1,const BigInteger& bgi2){
  BigInteger bgi;
  bgi.Number = bgi.Number.sub(bgi1.Number,bgi2.Number);
  return bgi;
}

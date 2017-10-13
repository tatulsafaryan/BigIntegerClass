#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include"List.h"
class BigInteger {
 private:
    List Number;
 public:
    BigInteger();
    BigInteger(const std::string& number);
    void printBigInteger();
    BigInteger& operator=(const BigInteger& obj);
    friend BigInteger operator+(const BigInteger& bgi1,const BigInteger& bgi2);
    friend BigInteger operator-(const BigInteger& bgi1,const BigInteger& bgi2);
};
#endif

#include <iostream>
#include <math.h>
class Prime {     //素数类 
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	bool isPrime() { 
  	  //2到number-1的因子
      bool flag = true;
      for(int i = 2;i<this->number;i++)
      {
          if(number%i==0)
            flag = false;  
      }
  	  return flag;
	}
  private:
  	const int number;
}; 
class PrimeSet {   //素数集合 
  public:
  	PrimeSet(int size) {
  	  //集合的构造什么？ 
  	  N = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  for (int i = 0; i < index; ++i)  //销毁对象 
		delete N[i]; 
	  delete[] N;
	}
	bool add(int n) {
	  if(index == size)  return false;
	  Prime *p = new Prime(n);
	  N[index] = p;
	  index += 1;
	  return true;
	}
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!N[i]->isPrime())
	      return false;
	  return true;
	} 
  private:
  	Prime **N;
	int size, index; 
};
class SuperPrime {
  public:
  	SuperPrime():number(0), pset(3) {  //为什么必须有？ 
  	}
  	SuperPrime(int n):number(n), pset(3) {
  	  split();  //它就是构造对象 
	}
  	~SuperPrime() {
	}
  	bool isSuperPrime() {
  	  //怎么使用pset？ 
  	  Prime p(number);
	  if (p.isPrime())
	    return true; 
  	  return false;
	}
  private:
  	const int number;
  	PrimeSet pset;   
	void split() {   //工厂方法设计模式 
	  // number split into N
	  int temp = number;
	  while(temp > 0) {
	  	int n = temp % 10;   
	  	temp /= 10;
	  	pset.add(n);
	  	pset.add(n);  //作业：单个数字为对象？还是和/积/平方和为对象？ 
	  } 
	}
	int sum() {
      int temp = number;
      int sum = 0;
	  while(temp > 0) {
	  	int n = temp % 10;
        sum += n;   
	  	temp /= 10;
	  }
      return sum;
    }
	int multi() {
	  int temp = number;
      int result = 1;
	  while(temp > 0) {
	  	int n = temp % 10;
        result *= n;   
	  	temp /= 10;
	  }
      return result;
    }
	int squareSum() {
	  int temp = number;
      int result = 0;
	  while(temp > 0) {
	  	int n = temp % 10;
        result += pow(n,2);   
	  	temp /= 10;
	  }
      return result;
	}
};
class SuperPrimeSet {
  public:
  	SuperPrimeSet(int from, int to) {   // 
  	  size = to - from;
  	  for (int i = from; i < to; i++)
  	    set[i-from] = new SuperPrime(i);
	}
  	~SuperPrimeSet() {
  	  for(int i = 0; i < size; i++)
  	    delete set[i];
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isSuperPrime())
  	      count += 1;
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  /*
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      sum += set[i];
  	      */ 
	  return sum; 
	}
  private:
  	SuperPrime **set;
  	int size, index;
};
int main() {
  SuperPrime sp(113);
  if (sp.isSuperPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}


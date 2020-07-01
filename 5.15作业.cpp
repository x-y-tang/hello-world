//作业：面向对象设计以下框架的代码细节，程序能编译运行得到正确结果 
//作业：删除多余的集合类，使用继承方法实现相同的功能。 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	bool isPrime() { 
  	  //2到number-1的因子 
  	  return false;
	}
  private:
  	const int number;
};
class PrimeSet {
  public:
  	PrimeSet(int size) {
  	  //集合的构造什么？ 
  	  set = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  for (int i = 0; i < index; ++i)  //销毁对象 
		delete set[i]; 
	  delete[] set;
  	  delete[] set;
	}
 	int count() {
  	  int count = 0;
   class PrimeSet {
	  return count; 
	}

	bool add(int n) {
	bool add(Prime *p) {
	  if(index == size)  return false;
	  Prime *p = new Prime(n);
	  set[index] = p;
	  index += 1;
	  return true;
class SuperPrime : public Prime {
	  while(temp > 0) {
	  	int t = temp % 10;
	  	temp /= 10;
	  	pset.add(t);  //作业：单个数字为对象？还是和/积/平方和为对象？ 
	  	//pset.add(t);  //作业：单个数字为对象？还是和/积/平方和为对象？ 
	  } 
	}
  	~SuperPrime() {
class SuperPrime : public Prime {
	}
};
int main() {
  SuperPrime sp(113);
  if (sp.isPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  PrimeSet set(2);
  set.add(&sp); 
  set.add(&p);
  std::cout << "How Many : " << set.count() << std::endl;
  return 0;
}


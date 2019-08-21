#include <iostream>
using namespace std;
// [[Rcpp::export]]
int fib1(int n)	{
	if(n == 0) return 0;
	if(n == 1) return 1;
	return fib1(n-1) + fib1(n-2);
}

// [[Rcpp::export]]
int fib2( int n ) {
  long prev2 = 0, prev = 1, current = 0;
  for( int x = 0; x < n; x++ ){
    current = prev + prev2; 
    prev2 = prev;
    prev = current;
  }
  return prev2;
}

// [[Rcpp::export]]
bool test_fib1() {
	bool passed = true;
	int ns[] = {0, 1, 2, 3, 4, 5, 6};
	int Fs[] = {0, 1, 1, 2, 3, 5, 8};
	for(int i=0; i<7; i++) {
	 
		if(fib1(ns[i]) != Fs[i]) {
			passed = false;
			break;
		}
	}
	if(passed) {
		cout << "test_fib1() passed. Congratulations!" << endl;
	} else {
		cout << "test_fib1() failed!" << endl;
	}
	return passed;
}

// [[Rcpp::export]]
bool test_fib2() {
  bool passed = true;
  int ns[] = {0, 1, 2, 3, 4, 5, 6};
  int Fs[] = {0, 1, 1, 2, 3, 5, 8};
  for(int i=0; i<7; i++) {
    if(fib2(ns[i]) != Fs[i]) {
      passed = false;
      break;
    }
  }
  if(passed) {
    cout << "test_fib2() passed. Congratulations!" << endl;
  } else {
    cout << "test_fib2() failed!" << endl;
  }
  return passed;
}

int main() {
	test_fib2();
	return 0;
}

// Above is regular C++ portion
// ------------------------------------------------------
// Below is the R portion to visualize the performance

/*** R
k <- 10
ns <- 34+(1:k)
runtime <- vector(length=k)
runtime2 <- vector(length=k)
for(i in 1:k) {
	n <- ns[i]
	runtime[i] <- (system.time(fib1(n))["user.self"])
}
plot(ns, runtime, type="b", xlab="n",ylab="runtime (second)")
k <- 30
ns <- 10000000*(1:k)
for(i in 1:k) {
  n <- ns[i]
  runtime2[i] <- (system.time(fib2(n))["user.self"])
}

plot(ns, runtime2, type="b", xlab="n",ylab="runtime (second)")
grid(col="blue")
*/

#include <iostream>
#include <sys/time.h>
#include <cstdlib>

using std::cout;
using std::endl;

int fib_recurs(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else 
		return fib_recurs(n-1) + fib_recurs(n-2);

	
}

int fib_iter(int n) {
	int result = 0, prev_prev = 0, prev = 1, current = 1 ;
	if (n == 0)
		return result;
	for(int i =2; i < n; i++) {
		prev_prev = prev;
		prev = current;
		current = prev_prev + prev;
		
	}
	return result = current;
}

int stair_fun(int stairs) {
	if (stairs <= 0)
		return 0;
	else if (stairs == 1)
		return 1;
	else 
		return stair_fun(stairs-1) + stair_fun(stairs-2);




}

int main() {
	typedef struct timeval time;
	time stop, start;

	gettimeofday(&start, NULL);
	int result = fib_recurs(1);
	cout << endl << result << endl;

	gettimeofday(&stop, NULL);

	if(stop.tv_sec > start.tv_sec)
		cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;
	cout << endl << stair_fun(4) << endl;
	return 0;
}	

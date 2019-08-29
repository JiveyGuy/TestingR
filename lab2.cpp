/* Data Structures Lab2 by Jason Ivey 
 * Start date: 6/28/2019 Complete Date: 
 *
 */

//Imported libraries
#include <iostream> 
#include <vector> 
#include <bits/stdc++.h> 
#include <math.h>

//std namespace
using namespace std;

// Method header declaration
bool test(vector<bool> (* mul)(vector<bool> &x, vector<bool> &y));
bool testall();
bool equals(vector<bool> & x, vector<bool> & y);

vector<bool> decToBinVect( int input );
vector<bool> multiply_itr(vector<bool> & x, vector<bool> & y);
vector<bool> add_itr(vector<bool> & x, vector<bool> & y);


void printVect( vector<bool> & x );
void debug( string info );

int main();

//constant declaration
static bool DEBUG = false;

//main control flow
int main(){

	int val1 = 1, val2 = 1;

	vector<bool> x = decToBinVect(val1);
	vector<bool> y = decToBinVect(val2);

	cout << val1 << " * " << val2 << " = " << endl; 
	x = multiply_itr( x, y );
	printVect( x );


	return 0;	
}

//debug display function
void debug( string info ){

	if( DEBUG ) {
		cout << ( "DEBUG:: " + info ) << endl;
	}
}

//vectro display function
void printVect( vector<bool> & x ){
	//iterates backwards for human readable binary
	for (int i = x.size(); i --> 0; ){
		cout << (( x[i] ) ? "1" : "0" );
	} cout << endl;
}

//Convert decimal int to binary bool vector
vector<bool> decToBinVect( int n ){

	if ( n == 0 ) return vector<bool>{false};
	debug(" Dec to bin called with " + to_string(n));
	int size = (log10(n)/log10(2)) + 1; //Size of sig digits in binary
	debug(" size = " + to_string(size));
	int a[size], i = 0, r;
	while( n != 0){
 		r = n % 2;
		a[i] = r;
		i++;
		n /= 2;
	}
	vector<bool> result;
	for( int itor : a ){
		//debug( "loop#" + to_string() + " a[i] = " + to_string(itor));
    	result.push_back( ( itor > 0) ? true : false );
	}
	return result;
}

// bool test(vector<bool> (* mul)(vector<bool> &x, vector<bool> &y), int count){

// 	vector<bool> temp;
// 	for (int i = 0; i < count; i++) {
// 		temp = mul( decToBinVect(1), decToBinVect(1) );
// 		if ( !equals(temp, temp) ) return false;
// 	} return true;
// }

bool equals(vector<bool> & x, vector<bool> & y){
	debug( " Equals called with x = ");
	if ( DEBUG ){
		printVect(x);
		debug(" y = ");
		printVect(y);
	}

	if (x.size() < y.size()){
		debug(" X size les than y size ");
		vector<bool> temp = x;
		x = y; 
		y = temp;
	}

	debug( " updated equals with x = ");
	if ( DEBUG ){
		printVect(x);
		debug(" y = ");
		printVect(y);
	}

	for( int c = 0; c < x.size() ; c++ ){
		// A note on the below if statement "c <= y.size()" must be used twice for optimization reasons
		// 		as well as to avoid accesing null pointers. 
		if( ( x[c] || ( c <= y.size() && y[c]) ) && c <= y.size() &&( x[c] != y[c])){
			debug( " return false ");
			return false;
		}
	}
	debug( " return true ");
	return true;
}

vector<bool> multiply_itr(vector<bool> & x, vector<bool> & y){
	if (x.size() > y.size()){
		debug(" X size more than y size ");
		vector<bool> temp = x;
		x = y; 
		y = temp;
	}
	vector<bool> result{false};
	for(int c = 0; c < x.size(); c++){
		result = add_itr(result, y);
	}
	if( DEBUG ){
		debug(" multiply_itr result = " );
		printVect( result );
	}
	return result;
}

vector<bool> add_itr(vector<bool> & x, vector<bool> & y){
	int result = 0;
	if( DEBUG ){
		debug( " add_itr called with " );
		printVect(x);
		debug( "and");
		printVect(y);
	}	
	
	if (x.size() < y.size()){
		debug(" X size less than y size ");
		vector<bool> temp = x;
		x = y; 
		y = temp;
	}
	for(int c = 0; c < x.size(); c++){
		result += ( (x[c]) ? pow(2, c) : 0 ) + ((y[c] )? pow(2, c) : 0);  
	} 
	debug("returning " + to_string(result));
	return decToBinVect( result );
}

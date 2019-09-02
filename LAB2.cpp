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
bool testAdd();
bool testMult();
bool testall();
bool equals(vector<bool> & x, vector<bool> & y);

vector<bool> decToBinVect( int input );
vector<bool> multiply_itr(vector<bool> & x, vector<bool> & y);
vector<bool> add_itr(vector<bool> & x, vector<bool> & y);



void swap(vector<bool> & x, vector<bool> & y);
void printVect( vector<bool> & x );
void debug( string info );

int binaryVectToInt( vector<bool> & x );
int main();

//constant declaration
static bool DEBUG = false;

int main(){
	if( DEBUG ){
		//testing here;
		//	testing print
		debug("Testing print vector ");
		vector<bool> printTest{false};
		printVect(printTest);
		//	testing int to vect
		debug("testing int to vect");
		for (int i = 0; i < 10; ++i)
		{
			debug( to_string(i) + " = " );
			vector<bool> temp = decToBinVect(i);
			printVect(temp);
		}
		//	testing vect to int
		debug("testing vect to int");
		for (int i = 0; i < 10; ++i)
		{
			vector<bool> temp = decToBinVect(i);
			printVect(temp);
			int result = binaryVectToInt( temp );
			debug( to_string(i) + " = " + to_string(result));	
		}
		//	add_itr
		if ( testAdd() ) cout << "Test add passed" << endl;
		else cout << "test add failed" << endl;
		//	add_itr
		if ( testMult() ) cout << "Test mult passed" << endl;
		else cout << "test mult failed" << endl;
	}

	test
}

bool testMult(){

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			vector<bool> x = decToBinVect(i), y = decToBinVect(j);

			vector<bool> multResult = multiply_itr(  x, y);
			if ( binaryVectToInt( multResult ) != ( i * j )){
				debug(to_string(i) + " * " + to_string(j) + " = " + to_string(i*j)  + " not "  
					+ to_string(binaryVectToInt( multResult )));
				return false;
			}
		}
	}
	return true;
}


bool testAdd(){

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			vector<bool> x = decToBinVect(i), y = decToBinVect(j);

			vector<bool> addResult = add_itr(  x, y);
			if ( binaryVectToInt( addResult ) != ( i + j )){
				debug(to_string(i) + " + " + to_string(j) + " = " + to_string(i+j)  + " not "  
					+ to_string(binaryVectToInt( addResult )));
				return false;
			}
		}
	}
	return true;
}

vector<bool> multiply(vector<bool> & x, vector<bool> & y) {
	vector<bool> z;
	// your code here
	return z;
}


vector<bool> multiply_itr(vector<bool> & x, vector<bool> & y){\
	if( DEBUG ){
		int x_val = binaryVectToInt(x), y_val = binaryVectToInt(y);
		debug("MULT called with " + to_string(x_val) + " and " + to_string(y_val));
	}

	if( binaryVectToInt(x) > binaryVectToInt(y) ){
		debug("MULT x > y, swapping");
		vector<bool> temp = x;
		x = y;
		y = temp;
	} 
	if( binaryVectToInt(x) == 0 || binaryVectToInt(y) == 0) 
		return decToBinVect(0);
	int result = 0, count =0;
	while( ( binaryVectToInt(x) - count ) > 0){
		result += binaryVectToInt(y);
		count++;
	}
	debug("MULT returning " + to_string(result));
	return decToBinVect( result);
}

vector<bool> add_itr(vector<bool> & x, vector<bool> & y){
	int result_val = binaryVectToInt(x) + binaryVectToInt(y);
	return decToBinVect( result_val );
}


vector<bool> decToBinVect( int input ){
	vector<bool> result;
	if( input == 0 ){
		result.push_back(false);
		return result;
	}
	int size = ( (log10(input)/log10(2)) + 1);
	for (int i = 0; i < size; ++i)
	{
		result.push_back( (input % 2 ) > 0);
		input /= 2;
	}
	return result;
}

//Converts vector<binary> into int
int binaryVectToInt( vector<bool> & x ){
	int result = 0;

	for ( int pos = 0; pos < x.size(); pos++ ){
		result += (x[pos] ? ( pow(2, pos) ) : 0);
	}
	return result;
}

//debug function
void debug( string info ){
	if( DEBUG ) cout << ( "DEBUG:: " + info ) << endl;	
}

//vector display function
void printVect( vector<bool> & x ){
	//iterates backwards for human readable binary
	for (int i = x.size(); i --> 0; ){
		cout << (( x[i] ) ? "1" : "0" );
	} cout << endl;
}

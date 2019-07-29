#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class rotor{
	// a general rotor class
	
	protected:
	
	string contents;
	string ringstellung;
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	public:
	
	string path = "/home/yanbo/Documents/computing/c++/computing_exercises/exercise1/ringstellung/";
	
	rotor(string rot_num, string plaintxt){
		ifstream myfile (path + rot_num + ".txt");
		ringstellung.assign((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>());
		contents = plaintxt;
		cout << "Ringstellung is " << ringstellung << endl;
		// cout << "Plaintext is " << contents << endl;
	}
	
	void exporter(string &str){
		str = contents;
	}
	
};

class static_rotor : public rotor{
	string infile, outfile;
	public:
	static_rotor(string num, string plain, string in, string out) : rotor(num, plain){
		infile = in;
		outfile = out;
	}
	
	void fromfile(){
		ifstream myfile (path + infile + ".txt");
		contents.assign((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>());
	}
	
	void tofile(){
		ofstream myfile (path + outfile + ".txt");
		copy(contents.begin(), contents.end(), ostreambuf_iterator<char>(myfile));
		myfile.flush();
	}
	
	void plugboard(){
		string::iterator it;
		string::iterator ab_it = alphabet.begin();
		for (it = ringstellung.begin(); it < ringstellung.end(); it++){
			replace(contents.begin(), contents.end(), *ab_it, *it );
			ab_it++;
		}
	}
};

class moving_rotor : public rotor{

};

class reflector : public rotor{

};

//Begin main programme.

int main(int argc, char *argv[]){
	
	static_rotor rot1("plug", "PLACEHOLDER", "input.txt", "output.txt");
	rot1.plugboard();
	string test;
	rot1.exporter(test);
	
	cout << test << endl;

return 0;
}

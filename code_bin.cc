	// converts string into vector of integers
	
	void stv(){
		string::iterator it;
		for (it = contents.begin(); it < contents.end(); it++){
			v_contents.push_back((int)*it - 96);
		}		
	}
	
	// converts vector of integers to string

	void vts(){
		vector<int>::iterator it;
		for (it = v_contents.begin(); it < v_contents.end();it++){
			contents.push_back((char)(*it + 96));
		}
	}
	
		// constructor initialises the input and output destinations
	static_rotor(string i, string o){input = i; output = o; cout << "Input file is " << i <<". Output file is " << o << endl;}
	
	// imports input file contents
	void importer(string filename){
		ifstream myfile (filename);
		contents.assign((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>());
	}
	
	// exports to output file
	
	void exporter(string filename){
		ofstream myfile (filename);
		copy(contents.begin(), contents.end(), ostreambuf_iterator<char>(myfile));
		myfile.flush();
	}

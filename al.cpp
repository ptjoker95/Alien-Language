#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <sstream>
#include <string>
using namespace std;

class AlienWords
{
	private:
		string word;
		
	public:
		void InputWords( string iword )
		{
			word = iword;
		}
		string OutputWord( void )
		{
			return word;
		}
};

class CheckMessages
{
	private:
		vector<char> message[15];
		
	public:
		void InputCharacter( char chr, int i )
		{
			message[i].push_back( chr );
		}
		string OutputithChar( int ith )
		{
			string temp;
			for( unsigned int i=0; i<message[ith].size(); i++ )
				temp.push_back( message[ith][i] );
				
			return temp;
		}
		bool IsThere( string dict )
		{	
			
			for( unsigned int i=0; i<dict.size(); i++ )
			{
				int count;
				count = 0;
				for( unsigned int j=0; j<message[i].size(); j++ )
				{
					if( dict[i] == message[i][j] )
					{
						count++;
					}
				}
				if( count == 0 )
					return false;
			}
			
			return true;
		}
};

int main( int argc, char** argv )
{
	int L, D, N;
	string word;
	AlienWords awords[5000];
	CheckMessages cmesg[500];
	string alienmessage, token;
	char chr;
	
	ifstream myfile;
	
	myfile.open( argv[1] );
	
	myfile >> L >> D >> N;
	
	for( int i=0; i<D; i++ )
	{
		myfile >> word;
	
		awords[i].InputWords( word );
	}

	for( int i=0; i<N; i++ )
	{
		for( int j=0; j<L; j++ )
		{
			myfile >> chr;
			if( chr != '(' )
			{
				cmesg[i].InputCharacter( chr, j );
			}
			else
			{
				while( 1 )
				{
					myfile >> chr;
					if ( chr == ')' )
						break;
					cmesg[i].InputCharacter( chr, j );
				}
				
			}
		}
	}

	for( int i=0; i<N; i++ )
	{
		int count;
		for( int j=0; j<D; j++ )
		{
			string temp;
			temp = awords[j].OutputWord();
			if( cmesg[i].IsThere( temp ) )
			{
				count++;
			}
		}
		cout << "Case #" << i+1 << ": " << count << endl;
		count = 0;
	}
	
	myfile.close();

	return 0;
}

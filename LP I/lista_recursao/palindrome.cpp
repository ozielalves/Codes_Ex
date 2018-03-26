#include <iostream>

// Returns if the string is a palindrome or not
int palindrome( std::string &string, int onde )
{	
	if(string[onde] == string[string.size()]) return palindrome( &string, onde+1);	
	else if(string != string[string.size()]) return -1;
	else return 1;
}

int main ( void )
{
	std::string string; // mas como passar o inicio e final do "vetor" para facilitar o processo de procura
	
	std::cout << "Type the word: (ctrl + D to finish) " << std::endl;
	std::cin >> string;
	int onde = 0;

	int result = palindrome( string, onde ); // Ajeitar os parametros
	 
	if( result = 1 ) std::cout << "The word is a polindrome" << std::endl;
	else std::cout << "The world is not a polindrome" << std::endl;
	
	return 0;
}

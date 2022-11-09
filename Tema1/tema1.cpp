#include <iostream>
#include <string>
using namespace std;

class Uncopyable{
	protected:
	Uncopyable(){}
	~Uncopyable(){}

	private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

class Persoana : private Uncopyable{ //we keep Persoana objects from being copied
    public:
        string nume1;
	int varsta1;

	Persoana(string nume,int varsta) //Default Constructor
	:nume1(nume), //this are initializations
	varsta1(varsta)
	{} //the ctor body is empty

        ~Persoana() //Destructor
	{}

        //Persoana& persoana = (const Persoana &persoana) // Copy assignment operator
        //{}
	
	string getNume()
	{
       		return this->nume1;
	}

	int getVarsta()
	{
        	return this->varsta1;
	}
};




int main()
{
	Persoana persoana("Alex", 20);
	cout<<persoana.getNume()<<" are "<<persoana.getVarsta()<<" ani!"<<endl;

	//Persoana parsoana2(parsoana); //does not compile because of Uncopyable
	//cout<<persoana2.getNume()<<" are "<<persoana2.getVarsta()<<" ani!"<<endl;

	//Persoana persoana3 = persoana; //does not compile because of Uncopyable
	//cout<<persoana3.getNume()<<" are "<<persoana3.getVarsta()<<" ani!"<<endl;
    return 0;
}

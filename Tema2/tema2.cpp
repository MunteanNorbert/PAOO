#include <iostream>
#include <string>
using namespace std;


class Persoana {
    public:
        string nume1;
		int varsta1;

	Persoana(string nume,int varsta) //Default Constructor
	:nume1(nume), //this are initializations
	varsta1(varsta)
	{} //the ctor body is empty

    ~Persoana() //Destructor
	{
		cout<<"The person was removed!"<<endl;
	}

    Persoana(const Persoana& persoana):nume1(persoana.nume1),varsta1(persoana.varsta1) //Copy constructor
    {}
	
	/*Persoana& operator=(const Persoana& persoana) // return type is a reference to the current class
	{ //Item 10
	 	this->nume1 = persoana.nume1;
	 	this->varsta1 = persoana.varsta1;
	
		return *this; // return the left-hand object
	}*/
	
	Persoana& operator=(const Persoana& persoana) 
	{ //Item 11
	
		if(this == &persoana) 
			return *this; //Identity test: if a self-assignment, do nothing
		
	 	this->nume1 = persoana.nume1;
	 	this->varsta1 = persoana.varsta1;
	
		return *this; // return the left-hand object
	}

	/*void swap(Persoana& persoana) //swap function, Item 29
	{ 
		this->nume1 = persoana.nume1; //exchange this's and persoana's data
		this->varsta1 = persoana.varsta1;
	}*/
	
	/*Persoana& Persoana::operator=(const Persoana& persoana)
	{
		Persoana temp(persoana); // make a copy of persoana’s data
		swap(temp); // swap *this’s data with the copy’s
		return *this;
	}*/
	
	Persoana& operator+=(const Persoana& persoana) //assignment operator +=
	{ //Item 11
	
	 	this->varsta1 = this->varsta1 + persoana.varsta1;
		return *this; 
	}
	
	Persoana& operator-=(const Persoana& persoana) //assignment operator -=
	{ //Item 11
	
	 	this->varsta1 = this->varsta1 - persoana.varsta1;
		return *this; 
	}
	
	Persoana& operator*=(const Persoana& persoana) //assignment operator *=
	{ //Item 11
	
	 	this->varsta1 = this->varsta1 * persoana.varsta1;
		return *this; 
	}
	
	Persoana& operator/=(const Persoana& persoana) //assignment operator /=
	{ //Item 11
	
	 	this->varsta1 = persoana.varsta1 / this->varsta1;
		return *this; 
	}
			
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
	Persoana persoana1("Norbert", 22);
	Persoana persoana2("Florin", 22);
	Persoana persoana3("Andrei", 11);
	Persoana persoana4 = persoana2;
	Persoana persoana5("Alexandra", 29);
	Persoana persoana6("Andreea", 24);
	Persoana persoana7("Ana", 19);
	Persoana persoana8("Andrei", 11);
	persoana5 = persoana5;
	
	cout<<persoana1.getNume()<<" are "<<persoana1.getVarsta()<<" ani!"<<endl;
	cout<<persoana2.getNume()<<" are "<<persoana2.getVarsta()<<" ani!"<<endl;
	cout<<persoana3.getNume()<<" are "<<persoana3.getVarsta()<<" ani!"<<endl;
	cout<<persoana4.getNume()<<" are "<<persoana4.getVarsta()<<" ani!"<<endl;
	cout<<persoana5.getNume()<<" are "<<persoana5.getVarsta()<<" ani!"<<endl;
	
	persoana5 += persoana1;
	persoana6 -= persoana2;
	persoana7 *= persoana3;
	persoana8 /= persoana4;
	
	cout<<"Suma varstelor persoaneler 1 si 4 este: "<<persoana5.getVarsta()<<" ani!"<<endl;
	cout<<"Diferenta varstelor persoaneler 2 si 6 este: "<<persoana6.getVarsta()<<" ani!"<<endl;
	cout<<"Inmultirea varstelor persoaneler 3 si 7 este: "<<persoana7.getVarsta()<<"!"<<endl;
	cout<<"Impartirea varstelor persoaneler 4 si 8 este: "<<persoana8.getVarsta()<<"!"<<endl;

    return 0;
}
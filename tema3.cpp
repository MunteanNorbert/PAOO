#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Uncopyable{
	protected:
	Uncopyable(){}
	~Uncopyable(){}
	
	private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

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
		cout<< this->nume1<<" was removed!"<<endl;
	}

    Persoana(const Persoana& persoana):nume1(persoana.nume1),varsta1(persoana.varsta1) //Copy constructor
    {}


	Persoana& operator=(const Persoana& persoana)
	{ //Item 11

		if(this == &persoana)
			return *this; //Identity test: if a self-assignment, do nothing

	 	this->nume1 = persoana.nume1;
	 	this->varsta1 = persoana.varsta1;

		return *this; // return the left-hand object
	}


	string getNume()
	{
       	return this->nume1;
	}

	int getVarsta()
	{
        return this->varsta1;
	}
	
	void setNume(string nume)
	{
       	this->nume1 = nume;
	}

	void setVarsta(int varsta)
	{
        this->varsta1 = varsta;
	}
};

class Lock: private Uncopyable { //prohibit copying
	public:
		explicit Lock(Persoana& persoana1)
		: pers(persoana1)
		{ 
			cout<<pers.getNume() + " is locked!"<<endl;
		} // acquire resource


		~Lock() 
		{ 
			cout<<pers.getNume() + " is unlocked!"<<endl;
		} // release resource
		
	private:
		Persoana& pers;
};

int main()
{
	//Item 13
	
	auto_ptr<Persoana> persoana1(new Persoana("Norbert", 22)); // persoana1 points to the object returned from Persoana
	cout<<persoana1->getNume()<<" are "<<persoana1->getVarsta()<<" ani!"<<endl;
	
	auto_ptr<Persoana> persoana2(persoana1); // persoana2 now points to the object; persoana1 is now null
	cout<<persoana2->getNume()<<" are "<<persoana2->getVarsta()<<" ani!"<<endl;
	
	persoana1 = persoana2; //now persoana1 points to the object, and persoana2 is null
	cout<<persoana1->getNume()<<" are "<<persoana1->getVarsta()<<" ani!"<<endl;
	
	shared_ptr<Persoana> persoana3(new Persoana("Florin", 25)); // persoana3 points to the object returned from Persoana
	cout<<persoana3->getNume()<<" are "<<persoana3->getVarsta()<<" ani!"<<endl;
	
	shared_ptr<Persoana> persoana4(persoana3); // both persoana3 and persoana4 now point to the object 
	cout<<persoana3->getNume()<<" are "<<persoana3->getVarsta()<<" ani!"<<endl;
	cout<<persoana4->getNume()<<" are "<<persoana4->getVarsta()<<" ani!"<<endl;
	
	persoana3 = persoana4; //the same
	cout<<persoana3->getNume()<<" are "<<persoana3->getVarsta()<<" ani!"<<endl;
	cout<<persoana4->getNume()<<" are "<<persoana4->getVarsta()<<" ani!"<<endl;


	//Item 14
	
	Persoana persoana5("Alexandra", 29);
	cout<<persoana5.getNume()<<" are "<<persoana5.getVarsta()<<" ani!"<<endl;

	
	Lock lock(persoana5); //lock persoana5
	
	persoana5.setNume("Alina"); //change name
	persoana5.setVarsta(30); //change age
	//persoana5 is automatically unlocked
	
	cout<<persoana5.getNume()<<" are "<<persoana5.getVarsta()<<" ani!"<<endl;

    return 0;
}
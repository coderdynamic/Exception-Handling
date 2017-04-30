//Catch and throws In a Hierarchy

#include <iostream>
#include <string>
using namespace std;

class MyException
{

	int ExNumber;
	string ExMessage;
public:
	MyException(int ErrNo, string Description)
	{
		ExNumber = ErrNo;
		ExMessage = Description;
	}
	void ShowEx()
	{
		cout << "Error Number is "<< ExNumber << "\n";
		cout << ExMessage << "\n";
	}
};

int ExGen()
{
	MyException e1(20,"Error testing 1");
	int ch;
	cout<<"1.Float\n2.Int\n3.Char\n4.Class\n";
	cin>>ch;
	try
	{
		if(ch==1)
			throw 4.5f;
		else if(ch==2)
			throw 6;
		else if(ch==3)
			throw 'z';
		else if(ch==4)
			throw e1;
		else
			throw "No Matching";
	}

	catch(float x)
	{
		cout<<"Caught Float in Function\n";
		throw;		//handled by main's catch i.e. rethrow
	}

	catch(int x)
	{
		cout<<"Caught Int in Function\n";
		throw;		//handled by main's catch i.e. rethrow
	}

	catch(char x)
	{
		cout<<"Caught Char in Function\n";
		throw;		//handled by main's catch i.e. rethrow
	}

	catch (MyException Except)
	{
		cout << "Caught object in Function \n";
		Except.ShowEx();
	}

	return 100;
}

int main(void)
{
	int z;
	try
	{
		z = ExGen();	//if there is no catch statement for object in function, then this line will work as a throw for that object and will be caught by the main's catch
		MyException e2(40,"Error testing 2");		/*this statement wiil not get executed if there are no catch statements for the class object in the function*/
		cout<<"Control in main\n";
		throw e2;
	}

	catch(int x)
	{
		cout<<"Caught Int in Main\n";
	}

	catch(float x)
	{
		cout<<"Caught Float in Main\n";
	}

	catch(char x)
	{
		cout<<"Caught Char in Main\n";
	}

	catch (MyException Except)
	{
		cout << "Caught object in Main\n";
		Except.ShowEx();
	}

	catch(...)
	{
		cout<<"Caught All!\n";
	}

	cout << "This statement is printed inside the Main\n";
	cout<<z<<endl;
	return 0;
}

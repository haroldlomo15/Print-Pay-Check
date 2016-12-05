#include <iostream>	//library for input/output 
#include <string>	//library for strings
#include <fstream>	//for the file opening
#include <iomanip>	//library for setw
using namespace std;

//Identifiers for the value returning fuction and the void function
void class_heading();
void print_pay_check(string fname, string lname, float net_pay, int street_num, string street_name, string city, string state, int zipcode, float grossPay, float total_tax);
float compute_gross_pay(char parttime_fulltime, float payrate, int ded);
float compute_taxes(float fed_tax, float state_tax, float city_tax);
float compute_net_pay(float total_tax, float grossPay);
float compute_federal_tax(float grossPay);
float compute_state_tax(float fed_tax);
float compute_city_tax(float state_tax);

int main()
{
	class_heading();	//calls the class heading
	char parttime_fulltime;	//declaring character value
	string fname, lname, street_name, road, city, state; //declaring string values
	int ded, id, street_num, zipcode; //declaring interger values
	float payrate, grossPay, total_tax, fed_tax, state_tax, city_tax, net_pay;	//declaring float vlaues
	ifstream myfile;	//file into code
	myfile.open("infile.txt");	//opens the text file
	myfile.ignore(80);	//ignore function that ignores the heading in the text
	myfile >> fname >> lname >> ded >> id >> street_num >> street_name >> road >> city >> state >> zipcode >> payrate >> parttime_fulltime;	//stores each text from the text file into these variables
	grossPay = compute_gross_pay(parttime_fulltime, payrate, ded);	//assigns the gross pay value returning funtion grossPay
	fed_tax = compute_federal_tax(grossPay);	//assigns the federal tax value returning function to fed_tax
	state_tax = compute_state_tax(fed_tax);		//assigns the state tax value returning function to state_tax
	city_tax = compute_city_tax(state_tax);		// assigns the city tax value returning function to city_tax
	total_tax = compute_taxes(fed_tax, state_tax, city_tax);	//assigns the total tax value returning function to total_tax
	net_pay = compute_net_pay(total_tax, grossPay);		// assigns the net pay value returning function to net-pay
	print_pay_check(fname, lname, net_pay, street_num, street_name, city, state, zipcode, grossPay, total_tax);	//calls the print_pay_check void function
	//copies for next lines of text
	myfile >> fname >> lname >> ded >> id >> street_num >> street_name >> road >> city >> state >> zipcode >> payrate >> parttime_fulltime;
	grossPay = compute_gross_pay(parttime_fulltime, payrate, ded);
	fed_tax = compute_federal_tax(grossPay);
	state_tax = compute_state_tax(fed_tax);
	city_tax = compute_city_tax(state_tax);
	total_tax = compute_taxes(fed_tax, state_tax, city_tax);
	net_pay = compute_net_pay(total_tax, grossPay);
	print_pay_check(fname, lname, net_pay, street_num, street_name, city, state, zipcode, grossPay, total_tax);
	myfile >> fname >> lname >> ded >> id >> street_num >> street_name >> road >> city >> state >> zipcode >> payrate >> parttime_fulltime;
	grossPay = compute_gross_pay(parttime_fulltime, payrate, ded);
	fed_tax = compute_federal_tax(grossPay);
	state_tax = compute_state_tax(fed_tax);
	city_tax = compute_city_tax(state_tax);
	total_tax = compute_taxes(fed_tax, state_tax, city_tax);
	net_pay = compute_net_pay(total_tax, grossPay);
	print_pay_check(fname, lname, net_pay, street_num, street_name, city, state, zipcode, grossPay, total_tax);
	myfile >> fname >> lname >> ded >> id >> street_num >> street_name >> road >> city >> state >> zipcode >> payrate >> parttime_fulltime;
	grossPay = compute_gross_pay(parttime_fulltime, payrate, ded);
	fed_tax = compute_federal_tax(grossPay);
	state_tax = compute_state_tax(fed_tax);
	city_tax = compute_city_tax(state_tax);
	total_tax = compute_taxes(fed_tax, state_tax, city_tax);
	net_pay = compute_net_pay(total_tax, grossPay);
	print_pay_check(fname, lname, net_pay, street_num, street_name, city, state, zipcode, grossPay, total_tax);
	myfile >> fname >> lname >> ded >> id >> street_num >> street_name >> road >> city >> state >> zipcode >> payrate >> parttime_fulltime;
	grossPay = compute_gross_pay(parttime_fulltime, payrate, ded);
	fed_tax = compute_federal_tax(grossPay);
	state_tax = compute_state_tax(fed_tax);
	city_tax = compute_city_tax(state_tax);
	total_tax = compute_taxes(fed_tax, state_tax, city_tax);
	net_pay = compute_net_pay(total_tax, grossPay);
	print_pay_check(fname, lname, net_pay, street_num, street_name, city, state, zipcode, grossPay, total_tax);
	myfile >> fname >> lname >> ded >> id >> street_num >> street_name >> road >> city >> state >> zipcode >> payrate >> parttime_fulltime;
	grossPay = compute_gross_pay(parttime_fulltime, payrate, ded);
	fed_tax = compute_federal_tax(grossPay);
	state_tax = compute_state_tax(fed_tax);
	city_tax = compute_city_tax(state_tax);
	total_tax = compute_taxes(fed_tax, state_tax, city_tax);
	net_pay = compute_net_pay(total_tax, grossPay);
	print_pay_check(fname, lname, net_pay, street_num, street_name, city, state, zipcode, grossPay, total_tax);
	system("pause");
}
float compute_gross_pay(char parttime_fulltime, float payrate, int ded)	//value returning function for computing the gross pay
{
	if (parttime_fulltime == 'P')
	{
		return (40 * payrate) + (10.5 * ded);
	}
	else
	{
		return payrate * 40;
	}
	
}
float compute_taxes(float fed_tax, float state_tax, float city_tax)	//vaue returning function for computing total tax
{
	return fed_tax + state_tax + city_tax;
}

float compute_net_pay(float total_tax, float grossPay)	// value returning function for computing the net pay
{
	return grossPay - total_tax;
}
float compute_federal_tax(float grossPay)	//value returning to compute the federal tax
{
	if (grossPay >= 500)
	{
		return 0.35 * grossPay;
	}
	else if (200 <= grossPay <= 500)
	{
		return 0.25 * grossPay;
	}
	else
	{
		return 0.15 * grossPay;
	}
	
	return 0.0;
}
float compute_state_tax(float fed_tax)	//value returning function to compute the state tax
{
	if (fed_tax > 80)
	{
		return 0.10 * fed_tax;
	}
	else
	{
		return 0.0;
	}
}
float compute_city_tax(float state_tax)	//value returning function to compute the city tax
{
	if (state_tax >= 50)
	{
		return 0.08 * state_tax;
	}
	else
	{
		return 0;
	}
}
void print_pay_check(string fname, string lname, float net_pay, int street_num, string street_name, string city, string state, int zipcode, float grossPay, float total_tax) //void function that prints the pay check
{
	cout << "******************************************************************\n"
		"\nABC Flowers \n123 Georgia Ave \t\t\t\t 03/04/2010 \nWashington, DC 20059\n" << endl;
	cout << "Payable to:\t" << fname << " " << lname << "\t\t Pay this amount: " << fixed << showpoint << setprecision(2) << net_pay << endl;
	cout << "\t\t" << street_num << " " << street_name << "\n\t\t" << city << " " << state << " " << zipcode << "\n" << endl;
	cout << "Gross Pay $" << fixed << showpoint << setprecision(2) << grossPay << "\n" << "Total Taxes $" << total_tax << "\n" << endl;

}
void class_heading()	// declaring class heading
{
	cout << "******************************************************\n";
	cout << "Harold Lomotey\n"
		"@02732375\n"
		"SYCS-135 Computer Science I \n"
		"October 28, 2015\n"
		"*****************************************************\n" << endl;
}


// Output result

//******************************************************
//Harold Lomotey
//@02732375
//SYCS - 135 Computer Science I
//October 28, 2015
//* ****************************************************
//
//******************************************************************
//
//ABC Flowers
//123 Georgia Ave                                  03 / 04 / 2010
//Washington, DC 20059
//
//Payable to : Herold, Will             Pay this amount : 170.10
//123 Main
//Washington, DC 20019
//
//Gross Pay $226.80
//Total Taxes $56.70
//
//******************************************************************
//
//ABC Flowers
//123 Georgia Ave                                  03 / 04 / 2010
//Washington, DC 20059
//
//Payable to : Jackson, Stan            Pay this amount : 320.45
//12 Douglas
//Baltimore, MD 30229
//
//Gross Pay $442.00
//Total Taxes $121.55
//
//******************************************************************
//
//ABC Flowers
//123 Georgia Ave                                  03 / 04 / 2010
//Washington, DC 20059
//
//Payable to : Jerry, Francis           Pay this amount : 597.47
//2345 6th
//Woodbridge, VA 44040
//
//Gross Pay $971.50
//Total Taxes $374.03
//
//******************************************************************
//
//ABC Flowers
//123 Georgia Ave                                  03 / 04 / 2010
//Washington, DC 20059
//
//Payable to : John, Wilson             Pay this amount : 301.60
//12 Georgia
//Washington, DC 20019
//
//Gross Pay $416.00
//Total Taxes $114.40
//
//******************************************************************
//
//ABC Flowers
//123 Georgia Ave                                  03 / 04 / 2010
//Washington, DC 20059
//
//Payable to : Smith, Stanley           Pay this amount : 338.86
//56 D
//Baltimore, MD 30229
//
//Gross Pay $551.00
//Total Taxes $212.14
//
//******************************************************************
//
//ABC Flowers
//123 Georgia Ave                                  03 / 04 / 2010
//Washington, DC 20059
//
//Payable to : Jeffers, Claude          Pay this amount : 1029.23
//66 32nd
//Woodbridge, VA 44040
//
//Gross Pay $1681.20
//Total Taxes $651.97


#include<iostream>
using namespace std;

class consumer1
{
    private:
    char name[20];
    int id;
    char address[30];
    float unit=0;
    int unit_cost;
    char billing_dt[11];
    float prvis_amot;
    float prvis_paid;
    float prvis_due;
    float now_due;
    float total_due;

    public:
        void detail_in()
        {
            cout<<"\nBilling Date: "; cin>>billing_dt;
            cout<<"Name: "; cin>>name;
            cout<<"Address: "; cin>>address;
            cout<<"Account Number: "; cin>>id;
            cout<<"Cost of per Unit: "; cin>>unit_cost;
            cout<<"Unit Consumed: "; cin>>unit;
            cout<<"Total Previous Amount Charged: ";cin>>prvis_amot;
            cout<<"Amount Previously Paid: ";cin>>prvis_paid;
            
            cout<<"\n";
        }

        void display()
        {
            cout<<"\n\n\t SUMMURISED BILL";
            cout<<"\n ________________________________________\n";
            cout<<"\tAccount Number = "<<id<<"\n";
            cout<<"\tAmount Now Due = Rs. "<<total_due<<"\n";
            cout<<"\tBilling Date   = "<<billing_dt<<"\n";
            cout<<" ________________________________________ ";

            cout<<"\n\n\t DETAILED BILL";
            cout<<"\n\nBilling Date = "<<billing_dt<<endl;
            cout<<"Consumer Name = "<<name<<endl;
            cout<<"Account Number = "<<id<<endl;
            cout<<"Address = "<<address<<endl;
            cout<<"Cost of per Unit = "<<unit_cost<<endl;
            cout<<"Unit Consumed = "<<unit<<endl;
            now_due = unit*unit_cost;
            cout<<"Total Previous Amount Charged = "<<prvis_amot<<endl;
            cout<<"Amount Previously Paid = "<<prvis_paid<<endl;
            cout<<"Amount to pay by consumer for this month = Rs. "<<now_due<<endl;
            prvis_due = prvis_amot-prvis_paid;
            cout<<"Total Amount due on last bill = Rs. "<<prvis_due<<endl;
            total_due = prvis_due + now_due;
            cout<<"Total Payable Amount now = Rs. "<<total_due<<endl;
            
        }
};

class consumer2     //this class is only commented out in order to make program more capable
{                   // if you want to see ambiguity in multiple inheritance go and comment out function calling of this class
    private:
    char name[20];
    int id;
    char address[30];
    float unit=0;
    int unit_cost;
    char billing_dt[11];
    float prvis_amot;
    float prvis_paid;
    float prvis_due;
    float now_due;
    float total_due;

    public:
        void detail_in()
        {
            cout<<"\nBilling Date: "; cin>>billing_dt;
            cout<<"Name: "; cin>>name;
            cout<<"Address: "; cin>>address;
            cout<<"Account Number: "; cin>>id;
            cout<<"Cost of per Unit: "; cin>>unit_cost;
            cout<<"Unit Consumed: "; cin>>unit;
            cout<<"Total Previous Amount Charged: ";cin>>prvis_amot;
            cout<<"Amount Previously Paid: ";cin>>prvis_paid;
            
            cout<<"\n";
        }

        void display()
        {
            cout<<"\nBilling Date = "<<billing_dt<<endl;
            cout<<"Consumer Name = "<<name<<endl;
            cout<<"Account Number = "<<id<<endl;
            cout<<"Address = "<<address<<endl;
            cout<<"Cost of per Unit = "<<unit_cost<<endl;
            cout<<"Unit Consumed = "<<unit<<endl;
            now_due = unit*unit_cost;
            cout<<"Total Previous Amount Charged = "<<prvis_amot<<endl;
            cout<<"Amount Previously Paid = "<<prvis_paid<<endl;
            cout<<"Amount to pay by consumer for this month = Rs. "<<now_due<<endl;
            prvis_due = prvis_amot-prvis_paid;
            cout<<"Total Amount due on last bill = Rs. "<<prvis_due<<endl;
            total_due = prvis_due + now_due;
            cout<<"Total Payable Amount = Rs. "<<total_due<<endl;
            
        }
};

class Derived : public consumer1, public consumer2
{
    public:
    void alert()
    {
        cout << "\n>>> NOTE: - If 31 days pass from the meter-reading, a late payment charge will be billed at a 10% annual interest rate (approximately 0.03% per day) based on the number of days elapsed.\n" << endl;
    }
};


int main()
{
    Derived obj;
    int no_of_consmer,i;
    cout<<"\nProgram Name: - Write a Program in C++ Language to implement Ambiguity Operator in Multiple Inheritance.";
    cout<<"\nName : - Sarthak Mishra ";
    cout<<"\nEnrollement no.: - A2345920084";
    cout<<"\nSection: - 3CSE2 Evening";
    cout<<"\n--------------------------------------------------------------------\n";

    cout<<"\n\t___________Electricity Bill___________";
    cout<<" \n\nEnter the Number of Consumers : " ; 
    cin>> no_of_consmer ; 
    for (i = 1; i <= no_of_consmer; i++) 
    { 
        cout<<"\n\n\t  ______Inputs Consumer "<<i<<" Bill______\n";
        obj.consumer1::detail_in();                                         // Ambiguity
    //    obj.consumer2::detail_in();
    }
    for (i = 1; i <= no_of_consmer; i++)
    {
        cout<<"\n\n\t  ______Display Consumer "<<i<<" Bill______";
        obj.consumer1::display();
    //    obj.consumer2::display();
        obj.alert();
    }
    return 0;
}
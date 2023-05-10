#include<iostream>
#include<fstream>
#include "Staff.cpp"
#include "Customer.cpp"
using namespace std;
class Account
{
	protected:
		int total_balance_of_hotel;
		int total_salary_of_staff,total_cash_recived_by_customers,salary_of_manager;
		int *salary_of_recieptionist,*salary_of_roomservice,*salary_of_otherstaff,*bill_of_customer;
		Manager m;
	    customer cus;
	    Staff s;
        Receptionist re;
        RoomService rs;
        OtherStaff os;
	public:
		void friend operator +(Account &);
		void setter();
		void getter();
};
void operator +(Account &A)
{
			A.total_salary_of_staff=0;
			A.salary_of_recieptionist=A.re.re_salary_show();
			for(int i=0;i<A.re.get_count();i++)
			{
				A.total_salary_of_staff=A.total_salary_of_staff+A.salary_of_recieptionist[i];
			}
			
			A.salary_of_roomservice=A.rs.rs_salary_show();
			for(int i=0;i<A.rs.get_count();i++)
			{
				A.total_salary_of_staff=A.total_salary_of_staff+A.salary_of_roomservice[i];
			}

            A.salary_of_otherstaff=A.os.ot_salary_show();
			for(int i=0;i<A.os.get_count();i++)
			{
				A.total_salary_of_staff=A.total_salary_of_staff+A.salary_of_otherstaff[i];
			}

			A.total_salary_of_staff=A.total_salary_of_staff+A.m.m_show_salary();
            A.total_cash_recived_by_customers=0;
            A.bill_of_customer=A.cus.c_show_bill();
			for(int i=0;i<A.cus.get_count();i++)
			{
                A.total_cash_recived_by_customers=A.total_cash_recived_by_customers+A.bill_of_customer[i];
			}
}

void Account::setter()
		{
			int s,c,b;
			fstream z;
			z.open("account.txt",ios::in);
			z>>s>>c>>b;
			z.close();
			total_balance_of_hotel=b+total_cash_recived_by_customers-total_salary_of_staff;
			fstream f;
			f.open("account.txt",ios::out);
			{
				f<<total_salary_of_staff<<' '<<total_cash_recived_by_customers<<' '<<total_balance_of_hotel<<endl;
			}
			f.close();
		}

void Account::getter()
		{
			fstream f;
			f.open("account.txt",ios::in);
			f>>total_salary_of_staff>>total_cash_recived_by_customers>>total_balance_of_hotel;
			int select;
			char choice;
			cout<<"\n\t\t\tWhat you want to know"<<endl;
			cout<<"\n\t\t\t1.Total Cash Recieved By The Customers\n\t\t\t2.Total Salary Given to Staff\n\t\t\t3.Total Balance Of Hotel\n\t\t\tEnter Choice: ";
			V:
            cin>>select;
			switch(select)
			{
				case 1:
				cout<<"\n\t\t\tTotal Cash Recieved By The Customers: "<<total_cash_recived_by_customers<<endl;
				break;
				case 2:
				cout<<"\n\t\t\tTotal Salary Given to Staff: "<<total_salary_of_staff<<endl;
				break;
				case 3:
				cout<<"\n\t\t\tTotal Balance Of Hotel is: "<<total_balance_of_hotel<<endl;
				break;
				default:
				cout<<"\n\t\t\tWrong choice!! Enter correct choice: ";goto V;
				break;
			}
		}
// int main()
// {
// 	Account a;
// 	+a;
//        a.setter();
//        a.getter();
// }

		

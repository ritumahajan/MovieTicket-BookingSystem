// Online C++ compiler to run C++ program online
// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
static float total_revenue=0;
static float total_service_t=0;
static float total_swachh_b_t=0;
static float total_krishi_k_t=0;
//Static Variables for admin use available All over the Program.

class Theatre{
	public:
	
   	vector<vector <string>> show1seats={
       {"A1","A2","A3","A4","A5","A6","A7","A8","A9"},
       {"B1","B2","B3","B4","B5","B6"},
       {"C2","C3","C4","C5","C6","C7"} 
   	};//Show 1 Running in Audi 1

   	vector<vector <string>> show2seats={
       {"A1","A2","A3","A4","A5","A6","A7"},
       {"B2","B3","B4","B5","B6"},
       {"C1","C2","C3","C4","C5","C6","C7"} 
   	};//Show 2 Running in Audi 2
   
   	vector<vector <string>> show3seats={
       {"A1","A2","A3","A4","A5","A6","A7"},
       {"B1","B2","B3","B4","B5","B6","B7","B8"},
       {"C1","C2","C3","C4","C5","C6","C7","C9"} 
   	};  //Show 3 Running in Audi 3
 	int pricej=0;
    
	bool isSeatsAvailable(string item,vector<vector <string>> &vect){
        for (int i = 0; i < vect.size(); i++){
        	for (int j = 0; j < vect[i].size(); j++){
   				if(item==vect[i][j]){
   					vect[i][j]="0";
   					//cout<<"++"<<vect[i][j];
   					return true;
				   }
   						
	        }    
    	}
    	return false;
    }//if seat available?return true: return false
    
    /*
    void availableSeats(vector<vector <string>> vect){
    	for (int i = 0; i < vect.size(); i++){
        	for (int j = 0; j < vect[i].size(); j++){
   				cout<<" "<<vect[i][j];	
	        }    cout<<endl;
    	}
	}
	*/
	
	void printBill(int num){
		int ticket_price[]={320,280,240};
		float total_bill;
		float bill=(num*ticket_price[pricej]);
		float service_t=bill*0.14;
		float swachh_b_t=bill*(0.5/100);
		float krishi_k_t=bill*(0.5/100);
		total_bill=bill+service_t+swachh_b_t+krishi_k_t;
	
		cout<<endl<<endl<<"_____________________________________________"<<endl;
		cout<<"Subtotal:	"<<bill<<endl;
		cout<<"Service Tax @14%:	"<<service_t<<endl;
		cout<<"Swachh Bharat Cess @0.5%:	"<<swachh_b_t<<endl;
		cout<<"Krishi Kalyan Cess @0.5%:	"<<krishi_k_t<<endl;
		cout<<"Total Bill:	"<<total_bill<<endl;
		cout<<endl<<"_____________________________________________"<<endl;
		
		total_revenue=+bill;
		total_service_t=+service_t;
		total_swachh_b_t=+swachh_b_t;
		total_krishi_k_t=+krishi_k_t;
	}// For Customer Billing
	
	void printToatalSales(){
		cout<<endl<<"Total Sales:	";
		cout<<endl<<"_____________________________________________"<<endl;
		cout<<"Revenue:	Rs."<<total_revenue<<endl;
		cout<<"Service Tax:	Rs."<<total_service_t<<endl;
		cout<<"Swachh Bharat Cess:	Rs."<<total_swachh_b_t<<endl;
		cout<<"Krishi Kalyan Cess:	Rs."<<total_krishi_k_t<<endl;
		cout<<endl<<"_____________________________________________"<<endl;
	}// For Administritator Billing
};

int main() {
    Theatre obj;
    int choice;
    string *book_seats;
    int total_seats_to_book;
    int flag=0;
    //cout<<"--"<<obj.show1seats[0][0];
    
    do{
    	cout<<endl<<"MENU:"<<endl<<"1 : For Show 1 \n 2 : For Show 2 \n 3 : For Show 3 \n 0: For Exit ";
    	cout<<endl<<"Enter Show Number: ";
    	cin>>choice;
    	
    	switch(choice){
        	case 1:cout<<endl<<"Show NO 1";
                cout<<endl<<"Enter Number of Seats To Book:    ";
                cin>>total_seats_to_book;
                book_seats=new string[total_seats_to_book];
                 
                cout<<endl<<"Enter Seats To Book:   ";
                for(int i=0;i<total_seats_to_book;i++){
                    cin>>book_seats[i];
                   // cout<<"* "<<obj.show1seats[0][0];
                    if(obj.isSeatsAvailable(book_seats[i],obj.show1seats)==0){
                    	cout<<endl<<book_seats[i]<<"  Not available, Please select different seats";
                    	flag=1;
						break;
					}	
                }
                
                if(flag==0){
                	cout<<endl<<" Successfully Booked - Show 1 "<<endl;    	
                	obj.printBill(total_seats_to_book);
				}
                break;
        
        	case 2: cout<<endl<<"Show NO 2";
    		    cout<<endl<<"Enter Number of Seats To Book:    ";
                cin>>total_seats_to_book;
                book_seats=new string[total_seats_to_book]; 
                cout<<endl<<"Enter Seats To Book:   ";
                for(int i=0;i<total_seats_to_book;i++){
                    cin>>book_seats[i];
                    if(obj.isSeatsAvailable(book_seats[i],obj.show2seats)==0){
                    	cout<<endl<<book_seats[i]<<"  Not available, Please select different seats";
                    	flag=1;
						break;
					}	
                }
                
                if(flag==0){
                	cout<<endl<<" Successfully Booked - Show 2 "<<endl;    	
                	obj.printBill(total_seats_to_book);
				}
                break;        
			
        	case 3: cout<<endl<<"Show NO 3";
            	cout<<endl<<"Enter Number of Seats To Book:    ";
                cin>>total_seats_to_book;
                book_seats=new string[total_seats_to_book];
                 
                cout<<endl<<"Enter Seats To Book:   ";
                for(int i=0;i<total_seats_to_book;i++){
                    cin>>book_seats[i];
                    if(obj.isSeatsAvailable(book_seats[i],obj.show3seats)==0){
                    	cout<<endl<<book_seats[i]<<"  Not available, Please select different seats";
                    	flag=1;
						break;
					}	
                }
                
                if(flag==0){
                	cout<<endl<<" Successfully Booked - Show 3 "<<endl;    	
                	obj.printBill(total_seats_to_book);
				}
                break;
			
        	default: cout<<endl<<"Enter Valid Show Number ";
    	}	
	}while(choice!=0);
	
	cout<<endl<<"Total Sales:";
	obj.printToatalSales();    
    return 0;
}
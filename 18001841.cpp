#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;


class flight{
	private:
		string fl_no;
		string date;
		string dep_airport;
		string arriv_airport;
		char seat[60][7];
		int eavail_seat_count;
		int bavail_seat_count;
	public:
		void display_avail(flight *,int n);
		void view_flight(flight *,int n);
		void seat_avail(flight *,int n);
		void seat_book(flight *,int n);
		void exit(flight *,int n);
		void setdata(flight *,int n);
};

int a,b,c,m;
static int p=0;
static int i=0;


void flight::setdata(flight*flights,int n){
	
	ifstream data;
	string receive;
	int j=0;
	int k=0;
	data.open("flights.txt");
		while (getline(data,receive))
{
	while(i<n){
	j=0;
	int seat_count=0;
		while(j<3){
			flights[i].fl_no=receive;
			getline(data,receive);
			j++;
			flights[i].date=receive;
			getline(data,receive);
			j++;
			flights[i].dep_airport=receive;
			getline(data,receive);
			j++;
			flights[i].arriv_airport=receive;
}

while(getline(data,receive) && !receive.empty()){
	if(receive[3]==' '){
		receive[3]=receive[2];
		receive[2]=' ';
	receive[1]=receive[0];
	receive[0]='0';
	
}
a=(((int)((receive[0]))-48)*10)+((int)(receive[1]-48));

int c=4;
if(receive[3]=='B'){
	flights[i].seat[a][0]='B';
	
}
else{
	flights[i].seat[a][0]='E';
}
for(b=1;b<7;b++){	
if(receive[c]==' '){
	c++;
	b--;
}
else{
flights[i].seat[a][b]=receive[c];
c++;	
}
}

int j=0;

for(k=1;k<7;k++){
	if(flights[i].seat[a][k]!='\0'){
			if(flights[i].seat[a][0]=='B'){
				flights[i].bavail_seat_count++;
			}
		}
}
for(k=1;k<7;k++){
	if(flights[i].seat[a][k]!='\0'){
			if(flights[i].seat[a][0]=='E'){
				flights[i].eavail_seat_count++;
			}
		}
}
}

getline(data,receive);

i++;
}
}
}

void flight::display_avail(flight *flights,int n){
	cout<<endl<<"Number of flights available : "<<n<<endl;
	cout<<endl<<"Available Flights are: "<<endl<<endl;
	i=0;
	while(i<n){		
		cout<<"Flight Number                : "<<flights[i].fl_no<<endl;
		cout<<"Date and Time                : "<<flights[i].date<<endl;
		cout<<"Depature Airport             : "<<flights[i].dep_airport<<endl;
		cout<<"Arrival Airport              : "<<flights[i].arriv_airport<<endl;
		cout<<"seat count in Business class : "<<flights[i].bavail_seat_count<<endl;
		cout<<"seat count in Economic Class : "<<flights[i].eavail_seat_count<<endl;
		cout<<endl;
		i++;
	}
}

	





void flight::view_flight(flight *flights,int n){
	cout<<endl<<"Enter the flight number: ";
	string flno;
	int flag=0;
	cin>>flno;
	while(flag==0){
	
	for(i=0;i<n;i++){
		if(flights[i].fl_no==flno){
			flag=1;
		}
	}
	if(flag==0){
				cout<<"Please enter a valid flight number: ";
				cin>>flno;
			}
	
}
	string receive_2;
	ifstream data;
	data.open("flights.txt");
	i=0;
	while(i<n)
{
		if(flights[i].fl_no==flno){
			cout<<endl<<endl<<"Flight Number   :"<<flights[i].fl_no<<endl;
			cout<<"Date and Time   : "<<flights[i].date<<endl;
			cout<<"Depature Airport: "<<flights[i].dep_airport<<endl;
			cout<<"Arrival Airport: "<<flights[i].arriv_airport<<endl;
			cout<<endl<<"Available seats are: "<<endl<<endl;
			cout<<"Class     RowNumber  Seat";
			
	for(a=0;a<60;a++){
	if(flights[i].seat[a][0]!='\0' && flights[i].seat[a][1]!='\0'){
		cout<<endl;
}
	if(flights[i].seat[a][0]=='B' && flights[i].seat[a][1]!='\0'){
			cout<<"Business: ";
			cout<<"  "<<a<<"         ";
		}
		else if(flights[i].seat[a][0]=='E' && flights[i].seat[a][1]!='\0'){
			cout<<"Economy : ";
			cout<<"  "<<a<<"        ";
		}
		
		for(b=1;b<7;b++){	
		
		if(flights[i].seat[a][b]!='\0'){
				cout<<flights[i].seat[a][b]<<",";
				
			}
		}
	
		}
		cout<<endl;
		cout<<endl;
		cout<<"seat count in Business class : "<<flights[i].bavail_seat_count<<endl;
		cout<<"seat count in Economic Class : "<<flights[i].eavail_seat_count<<endl;
		
	
}
i++;
	}
	
	data.close();
}

void flight::seat_avail(flight *flights, int n){
	string fn;
	int flag=0;
	cout<<endl<<"Enter the flight Number: "<<endl;
	cin>>fn;
	while(flag==0){
	for(i=0;i<n;i++){
		if(flights[i].fl_no==fn){
			flag=1;
		}
	}
	if(flag==0){
				cout<<"Please enter a valid flight number: ";
				cin>>fn;
			}
}
	int seat;
	int cl;
	int flag_2=0;
	int select;
	cout<<endl<<"Enter the class you prefer: "<<endl;
	cout<<"1.Business Class"<<endl;
	cout<<"2.Economic Class"<<endl;
	cin>>cl;
	switch(cl){
		case 1:
			cout<<endl<<"Enter the number of seats you want: ";
			cin>>seat;
			for(i=0;i<n;i++){
				
				
				if(flights[i].fl_no==fn && flights[i].bavail_seat_count>=seat){

				cout<<'\t'<<"Seats are available. You can book right now."<<endl;
				for(a=0;a<60;a++){
				if(flights[i].seat[a][0]!='\0'){
					cout<<endl;
				}
				if(flights[i].seat[a][0]=='B'){
				cout<<a<<" ";
				for(b=1;b<7;b++){	
		
					if(flights[i].seat[a][b]!='\0'){
						cout<<flights[i].seat[a][b];
				
					}	
				}
			}
				}
				cout<<endl;
				}
				else if(flights[i].fl_no==fn && ((flights[i].eavail_seat_count>=seat) || (flights[i].eavail_seat_count<=0))){
					cout<<"Sorry,only "<<flights[i].bavail_seat_count<<" seat/seats available in this flight."<<endl;
					flag=1;
					break;
				
				}
				else{
					flag=0;
				}
			}
			if(flag==0){
			
			cout<<"Do you want to book the seats?"<<endl;
				cout<<"1.Yes"<<endl<<"2.No"<<endl;
				cin>>select;
				switch(select){
					case 1:
						flight::seat_book(flights,n);
						break;
					case 2:
						cout<<"Okay thank you."<<endl;
						break;
					default:
						cout<<"You have entered an invalid choice."<<endl;
						break;
				}
			}
			break;
		case 2:
			cout<<endl<<"Enter the number of seats you want: ";
			cin>>seat;
			for(i=0;i<n;i++){
				if(flights[i].fl_no==fn && flights[i].eavail_seat_count>=seat){

				cout<<'\t'<<"Seats are available. You can book right now."<<endl;
				for(a=0;a<60;a++){
				if(flights[i].seat[a][0]!='\0'){
					cout<<endl;
				}
				if(flights[i].seat[a][0]=='E'){
				cout<<a<<" ";
				for(b=1;b<7;b++){	
		
					if(flights[i].seat[a][b]!='\0'){
						cout<<flights[i].seat[a][b];
				
					}	
				}
			}
				}
				cout<<endl;
				}
				
				else if(flights[i].fl_no==fn && ((flights[i].eavail_seat_count<seat) || (flights[i].eavail_seat_count<=0))){
					cout<<"Sorry,only "<<flights[i].eavail_seat_count<<" seats are available in this flight."<<endl;
					flag=1;
					break;
				}
				else{
					flag=0;
				}
			}
			if(flag==0){
			
			cout<<endl<<"Do you want to book the seats?"<<endl;
				cout<<"1.Yes"<<endl<<"2.No"<<endl;
				cin>>select;
				switch(select){
					case 1:
						flight::seat_book(flights,n);
						break;
					case 2:
						cout<<"Okay thank you."<<endl;
						break;
					default:
						cout<<"You have entered an invalid choice."<<endl;
						break;
				}
			}
			break;
			
}
	}
	

void flight::seat_book(flight *flights,int n){
	int fn;
	string row;
	int j;
	int d;
	string x;
	int seat;
	string num;
	int flag=0;
	int flag_2=0;
	int flag_3=0;
	cout<<endl<<"Enter the flight Number: "<<endl;
	cin>>x;
	while(flag==0){
	for(i=0;i<n;i++){
		if(flights[i].fl_no==x){
			flag=1;
		}
	}
	if(flag==0){
				cout<<"Please enter a valid flight number: ";
				cin>>x;
			}
}
	cout<<"Enter the class: "<<endl;
	cout<<"1.Business Class"<<endl<<"2.Economy Class"<<endl;
	cin>>d;
	
	
	switch(d){
		case 1:
			cout<<endl<<"Enter the number of seats you want: ";
			cin>>seat;
			for(i=0;i<n;i++){
				
				
				if(flights[i].fl_no==x && flights[i].bavail_seat_count>=seat){

				cout<<'\t'<<"Seats are available. You can book right now."<<endl;
				cout<<endl;
				}
				else if(flights[i].fl_no==x && ((flights[i].eavail_seat_count>=seat) || (flights[i].eavail_seat_count<=0))){
					cout<<"Sorry,only "<<flights[i].bavail_seat_count<<" seat/seats available in this flight."<<endl;
					flag=1;
					break;
				
				}
				else{
					flag=0;
				}
			}
			break;
		case 2:
			cout<<endl<<"Enter the number of seats you want: ";
			cin>>seat;
			for(i=0;i<n;i++){
				if(flights[i].fl_no==x && flights[i].eavail_seat_count>=seat){

				cout<<'\t'<<"Seats are available. You can book right now."<<endl;
				cout<<endl;
				}
				
				else if(flights[i].fl_no==x && ((flights[i].eavail_seat_count<seat) || (flights[i].eavail_seat_count<=0))){
					cout<<"Sorry,only "<<flights[i].eavail_seat_count<<" seats are available in this flight."<<endl;
					flag=1;
					break;
				}
				else{
					flag=0;
				}
			}
			break;
		}
	
	
	
if(flag==0){	
		
	while(seat>0){
	
	cout<<endl<<"Enter Seats' locations: "<<endl<<'\t';
	cout<<"Enter Row number in two digits: ";
	cin>>row;
	while(row.size()!=2){
		cout<<"Please enter the row number in two digits: ";
		cin>>row;
	}
	a=((((int)((row[0]))-48)*10)+((int)(row[1]-48)));
	
	if((a>60) || (a<1)){
		cout<<endl<<"Please enter a valid row number."<<endl;
	}

	
	cout<<'\t'<<"Enter Seat Number: ";
	cin>>num;
	int l=num.size();
	while(flag_3==0){
	
	for(i=0;i<l;i++){
	
	if((num[i]>'F') || (num[i]<'A')) {
		cout<<endl<<"Please enter a valid seat number: ";
		cin>>num;
		
	}
	else{
		flag_3=1;
	}
}
}
	if(d==1){
		for(i=0;i<n;i++){
		if(flights[i].fl_no==x &&flights[i].seat[a][0]=='B'){
			c=i;
			int l=num.size();
			
			seat=seat-l;
			while(l){
				flag=0;
			for(m=1;m<7;m++){
				
			for(p=0;p<l;p++){
				
				if(flights[i].seat[a][m]==num[p] && flights[i].seat[a][m]!='\0'){
					j=a;
					flights[i].seat[a][m]='\0';
					flights[i].bavail_seat_count--;
					flag=1;
					
					if(flights[i].seat[a][m]!='\0'){
							flag_2=1;
							}
					

	
		}
			}
		}
		if(flag==1){
	cout<<"Your seat is booked."<<endl;
	}

else if(flag==0){
	cout<<endl<<"Sorry that seat is not available."<<endl<<endl;
	seat++;
}
		l--;
	}
		}
	}
	
	}
	
	if(d==2){
		for(i=0;i<n;i++){
		if(flights[i].fl_no==x && flights[i].seat[a][0]=='E'){
			c=i;
			int l=num.size();
			seat=seat-l;
			while(l){
				flag=0;
			for(m=1;m<7;m++){
			
			for(p=0;p<l;p++){
				
				if(flights[i].seat[a][m]==num[p] && flights[i].seat[a][m]!='\0'){
				j=a;
				flights[i].seat[a][m]='\0';
				flights[i].eavail_seat_count--;
				flag=1;
			}
		}
		}
		if(flag==1){
	cout<<"Your seat is booked"<<endl;
	}

else if(flag==0){
	cout<<endl<<"Sorry that seat is not available."<<endl<<endl;
	seat++;
}
		l--;
	}
		}
	}
	
}

}
}
}


void flight::exit(flight *flights,int n){
		char seat[60][7];
	ofstream send;
	send.open("flights.dat");
	for(i=0;i<n;i++){
		
	send<<flights[i].fl_no<<endl;
	send<<flights[i].date<<endl;
	send<<flights[i].dep_airport<<endl;
	send<<flights[i].arriv_airport<<endl;
		for(a=0;a<60;a++){
			if(flights[i].seat[a][0]!='\0' && flights[i].seat[a][1]!='\0'){
					send<<a<<" ";
					send<<flights[i].seat[a][0]<<" ";
				}
			
			
			for(b=1;b<7;b++){	
		
		if(flights[i].seat[a][b]!='\0'){
				send<<flights[i].seat[a][b];
			}
			
		}
		if(flights[i].seat[a][0]!='\0' && flights[i].seat[a][1]!='\0'){
			send<<endl;
		}
		}
		send<<endl;
		send<<endl;

}
cout<<endl<<"  ******************** THANK YOU. *******************"<<endl;
}






int main(){
	int choice;
	string receive;
	string line;
	int space;
	ifstream data;
	int eseat_count=0;
	int bseat_count=0;
	int j=0;
	int k=0;
	int n=0;


data.open("flights.txt");
while(getline(data,receive)){
		if(receive!="" && n==0){
			n=1;
		}
		if(receive==""){
			n++;
		}
	}
data.clear();
data.seekg(0,ios::beg); 
flight *flights = new flight[n];	

for(i=0;i<n;i++){

flights[i].setdata(flights,n);

data.close();
cout<<endl<<endl<<"   ******************** WELCOME *********************"<<endl;
while(choice!=5){
cout<<endl<<endl<<"                        Menu           "<<endl<<endl;
	cout<<"                 1.Display available flights."<<endl<<"                 2.View flight."<<endl<<"                 3.Seat availability."<<endl<<"                 4.Seat booking."<<endl<<"                 5.Exit"<<endl;
	cout<<endl<<"Enter your choice: ";
	cin>>choice;
	switch(choice){
		case 1:
			flights[i].display_avail(flights,n);
			break;
		case 2:
			flights[i].view_flight(flights,n);
			break;
		case 3:
			flights[i].seat_avail(flights,n);
			break;
		case 4:
			flights[i].seat_book(flights,n);
			break;
		case 5:
			flights[i].exit(flights,n);
			break;
			
		default:
			cout<<"Please enter a valid choice."<<endl;
			break;
	}
	
}
}
	return 0;
}


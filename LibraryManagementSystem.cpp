#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book {
private:
 char *author,*title,*publisher;
 float *price;
 int *stock;
public: 
 book() {
 author= new char[25];
 title=new char[25];
 publisher=new char[25];
 price= new float;
 stock=new int;
 }
 void feeddata();
 void editdata();
 void showdata();
 int search(char[],char[]);
 void buybook();
	
};

void book::feeddata() {
 cin.ignore();
 cout<<"\nEnter Author's Name: "; cin.getline(author,25);
 cout<<"Enter Title of the Book: "; cin.getline(title,25);
 cout<<"Enter Publisher's Name: "; cin.getline(publisher,25);
 cout<<"Enter Price of the Book: "; cin>>*price;
 cout<<"Enter number of Books in Stock: "; cin>>*stock;   
	
}

void book::editdata() {
	
 cout<<"\nEnter Author's Name: "; cin.getline(author,25);
 cout<<"Enter Title of the Book: "; cin.getline(title,25);
 cout<<"Enter Publisher's Name: "; cin.getline(publisher,25);
 cout<<"Enter Price of the Book: "; cin>>*price;
 cout<<"Enter number of Books in Stock: "; cin>>*stock;   
	
}

void book::showdata() {
 cout<<"\nAuthor's Name: "<<author;
 cout<<"\nTitle: "<<title;
 cout<<"\nPublisher's Name: "<<publisher;
 cout<<"\nPrice: "<<*price;
 cout<<"\nIn Stock: "<<*stock;   
	
}

int book::search(char tbuy[25],char abuy[25] ) {
 if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
  return 1;
 else return 0;
  
}

void book::buybook() {
 int count;
 cout<<"\nEnter Number Of Books to buy: ";
 cin>>count;
 if(count<=*stock) {
  *stock=*stock-count;
  cout<<"\nBooks Bought Sucessfully!";
  cout<<"\nAmount: Rs. "<<(*price)*count;
 }
 else
  cout<<"\nRequired Copies are not in Stock";
}

int main() {
 book *B[25];
 int i=0,r,t,choice;
 char titlebuy[25],authorbuy[25];
 while(1) {
  cout<<"\n\n\t\tMENU"
  <<"\n1. Entry of New Book"
  <<"\n2. Buy Book"
  <<"\n3. Search For Book"
  <<"\n4. Edit Details Of Book"
  <<"\n5. Exit"
  <<"\n\nEnter your Choice: ";
  cin>>choice;
  
  switch(choice) {
   case 1: B[i] = new book;
    B[i]->feeddata();
    i++; break;
    
   case 2: cin.ignore();
    cout<<"\nEnter Title Of the Book: "; cin.getline(titlebuy,25);
    cout<<"Enter Author Of the Book: "; cin.getline(authorbuy,25);
    for(t=0;t<i;t++) {
     if(B[t]->search(titlebuy,authorbuy)) {
      B[t]->buybook();
      break;
     }
    }
    if(t==1)
    cout<<"\nThis Book is Not available in Stock";
    
    break;
   case 3: cin.ignore();
    cout<<"\nEnter Title Of the Book: "; cin.getline(titlebuy,25);
    cout<<"Enter Author Of the Book: "; cin.getline(authorbuy,25);
    
    for(t=0;t<i;t++) {
     if(B[t]->search(titlebuy,authorbuy)) {
      cout<<"\nBook Found Successfully!";
      B[t]->showdata();
      break;
     }
    }
    if(t==i)
    cout<<"\nThis Book is Not in Stock";
    break;
   
   case 4: cin.ignore();
    cout<<"\nEnter Title Of the Book: "; cin.getline(titlebuy,25);
    cout<<"Enter Author Of the Book: "; cin.getline(authorbuy,25);
    
    for(t=0;t<i;t++) {
     if(B[t]->search(titlebuy,authorbuy)) {
      cout<<"\nBook Found Successfully!";
      B[t]->editdata();
      break;
     }
    }
    if(t==i)
    cout<<"\nThis Book is Not available in Stock";
    break;
   
   case 5: exit(0);
   default: cout<<"\nInvalid Choice Entered";
   
  }
 }
	
	
	
	
 return 0;
}

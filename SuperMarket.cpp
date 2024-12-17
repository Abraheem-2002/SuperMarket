cout << "\\t\t name of the prodact :";
     cin >> n;
     cout << "\n\t\t price :";
     cin >> p;
     cout << "\n\t\t discound :";
     cin >> d;
     data1 << " " << c << " " << n << " " << p << " " << d << "\n";
     cout << "\n\n\t\t recode edied ";
     token++;

    }
    else {
     data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";

    }
    data >> pcode >> pname >> price >> dis;
   }
   data.close();
   data1.close();

   remove("databease.txt");
   rename("databease1.txt", "databease.txt");
   if (token == 0) {
    cout << "\n\n recode not found sorry";
   }
  }



 }

 void market::rem() {
  fstream data, data1;
  int pkey;
  int token = 0;
  cout << "\n\n\t Delet product ";
  cout << "\n\n\t prodacut code :";
  cin >> pkey;
  data.open("databease.txt", ios::in);
  if (!data) {
   cout << "file dosent exits";

  }
  else {
   data1.open("databease.txt", ios::app | ios::out);
   data >> pcode >> pname >> price >> dis;
   while (!data.eof()) {
    if (pcode == pkey) {
     cout << "\n\n\t prodauct deleted scssfule ";
     token++;
    }
    else {
     data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";

    }
    data >> pcode >> pname >> price >> dis;
   }
   data.close();
   data1.close();
   //rename("databease.txt");
   rename("databease1.txt","databease.txt");

   if (token == 0) {
    cout << "\n\n recode not found ";
   }

  }
 }

 void market::list() {
  fstream data;
  data.open("databeas.txt", ios::in);
  cout << "\n\n--------------------------------------------\n";
  cout << "prono \t\tname\t\tprice ";
  cout << "\n\n---------------------------------------------\n";
  data >> pcode >> pname >> price >> dis;
  while (!data.eof()) {
   cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
   data >> pcode >> pname >> price >> dis;
  }
  data.close();
   
 }
 void market::receipt() {
  m:
  fstream data;
  int arrc[100];
  int arrq[100];
  char choise;
  int c = 0;
  float amount=0;
  float dis = 0;
  float totle = 0;
  cout << "\n\n\t\t\t\t RECEIPT";
  data.open("databease.txt", ios::in);
   if(!data) {
    cout << "\n\n empty databease ";

   }else 
   {
    data.close();
    list();
    cout << "\n-----------------------------------------------\n";
    cout << "\n|                                              \n";
    cout << "\n           plase place the oder                \n";
    cout << "\n|                                              \n";
    cout << "\n-----------------------------------------------\n";
    do {
     cout << "\n\n Enter prodact code :";
     cin  >> arrc[c];
     cout << "\n\n Enter the prodact quantiy :";
     cin >> arrq[c];
     for (int i = 0;i < c;i++) {
      if (arrc[c] == arrc[i]) {
       cout << "\n\n Duplicate product code . plese try agine !";
       goto m;
      }
     }
     c++;
     cout << "\n\n Do you went buy anther prodact ? if yes than press y else no";
    } while (choise == 'y');
    cout << "\n\n\t\t\t--------------------RECEIPT--------------------\n";
    cout << "\n prodact number no \t prodact name \t prodact qunantity \t price \t amount \t aount whit discound ";
    for (int i = 0;i < c; i++) {
     data.open("databeas.txt", ios::in);
     data >> pcode >> pname >> price >> dis;
     while (!data.eof()) {
      if (pcode == arrc[i]) {
       amount = price * arrq[i];
       dis = amount - (amount * dis / 100);
       totle = totle * dis;
       cout << "\n " << pcode <<"\t\t"<< pname <<"\t\t" << arrq[i]  <<"\t\t"<< price <<"\t\t"<< amount <<"\t\t"<< dis;

      }
      data >> pcode >> pname >> price >> dis;
     }
    }
    data.close();
   }
   cout << "\n\n----------------------------------------------------------";
   cout << "\n TOTLE AMOUNT :" << totle;
 }
 
 market:: market()
{
}

 market::~ market()
{
}


int main()
{
  
 market a1;
 a1.menu();
 
 return 0;
}

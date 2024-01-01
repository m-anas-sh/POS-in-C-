#include<iostream>
#include<fstream>
#include<ctime>
#include <string>
#include<sstream>
#include<cstdio>
using namespace std;

// =================================================== ADMIN FUNCTIONS ===================================================

int getLastSerialNumber() // used to get serial number of last product in file
{
	ifstream file;
	file.open("POS Project.csv");
	string line;
	string lastLine;
	int lastProductSerialNumber;
	if (file.is_open())
	{
		while(file.good())
		{
			getline(file, line);
			if (line!= "")
				lastLine = line;
		}
	}
	stringstream ss(lastLine);
	ss >> lastProductSerialNumber;
	return lastProductSerialNumber;
}

void insertProduct()
{
	string product;
	int quantity;
	int costPrice;
	int sellPrice;
	int minQuantity;
	string category;
	string unitmeasure;
	int serialNumber;
	string lastSerialNumber;
	bool inserted = false;	

	ifstream infile("POS Project.csv");

	cout << "\tEnter Product Name: "; 
	cin.ignore(); 
	getline(cin, product);
	cout << "\tEnter Product Quantity: ";	
	cin >> quantity;
	cout << "\tEnter Product Cost Price: ";	
	cin >> costPrice;
	cout << "\tEnter Product Sell Price: ";	
	cin >> sellPrice;
	cout << "\tEnter Product Minimum Quantity: ";	
	cin >> minQuantity;
	cout << "\tEnter Product Category: ";	
	cin >> category;
	cout << "\tEnter Product Unit Of Measurement(i.e: Pc,Liter,Kg): ";  
	cin >> unitmeasure;

	fstream file;
	file.open("POS Project.csv", ios::app);
	if (file.is_open())
	{
		serialNumber = getLastSerialNumber() + 1;
		file << serialNumber << "," << product << "," << quantity << "," << sellPrice << "," << costPrice << "," << category << "," << minQuantity << "," << unitmeasure << endl;
		file.close();
		inserted = true;
	}
	else
		cout<<"\tFile Not Found"<<endl;
		
	if (inserted)
		cout<<"\tRecord Inserted Successfully"<<endl;
	else
		cout<<"\tInsertion Error"<<endl;	

}

void updateProductName() {
	
	string productNameToFind;
	string productName;
	string qty;
	string costPrice;
	string sellPrice;
	string minLimit;
	string serialNumber;
	string unitOfMeasurement;
	string category;
	string newProductName;
	bool found = false;
	
	cout<<"\tEnter Product Name: ";
	cin.ignore(); 
	getline(cin, productNameToFind);

	
	ofstream fout;
	ifstream fin;
	fin.open("POS Project.csv", ios::in);
	fout.open("temp.csv", ios::out);
	
	while(fin.good())
	{
			getline(fin, serialNumber, ',');
			getline(fin, productName, ',');
			getline(fin, qty, ',');
			getline(fin, sellPrice, ',');
			getline(fin, costPrice,',');
			getline(fin, category, ',');
			getline(fin, minLimit, ',');
			getline(fin, unitOfMeasurement);
			
		    if (serialNumber == "" || productName == "" || qty == "" || sellPrice == "" || costPrice == "" || category == "" || minLimit == "" || unitOfMeasurement == "") 
			{
		        break;
		    }
			
			if (productNameToFind == productName)
			{
				found = true;
				cout<<"\tEnter New Product Name: ";
				cin.ignore(); 
				getline(cin, newProductName);
				fout << serialNumber << "," << newProductName << "," << qty << "," << costPrice << "," << sellPrice << "," << minLimit << "," << category << "," << unitOfMeasurement << endl;
			}
			else if (productName != "")
			{
				fout << serialNumber << "," << productName << "," << qty << "," << costPrice << "," << sellPrice << "," << minLimit << "," << category << "," << unitOfMeasurement << endl;
			}
	}
	
	fout.close();
	fin.close();
	
	remove("POS Project.csv");
	rename("temp.csv", "POS Project.csv");
	
	if (found)
	{
		cout<<"\n\tRecord Updated Successfully"<<endl;
	}
	else
	{
		cout<<"\n\tProduct Not Found"<<endl;
	}
	
}

void updateSellPrice() {
	
	string productNameToFind;
	string productName;
	string qty;
	string costPrice;
	string sellPrice;
	string minLimit;
	string serialNumber;
	string unitOfMeasurement;
	string category;
	int newSellPrice;
	bool found = false;
	
	cout<<"\tEnter Product Name: ";
	cin.ignore(); 
	getline(cin, productNameToFind);

	
	ofstream fout;
	ifstream fin;
	fin.open("POS Project.csv", ios::in);
	fout.open("temp.csv", ios::out);
	
	while(fin.good())
	{
			getline(fin, serialNumber, ',');
			getline(fin, productName, ',');
			getline(fin, qty, ',');
			getline(fin, sellPrice, ',');
			getline(fin, costPrice,',');
			getline(fin, category, ',');
			getline(fin, minLimit, ',');
			getline(fin, unitOfMeasurement);
			
		    if (serialNumber == "" || productName == "" || qty == "" || sellPrice == "" || costPrice == "" || category == "" || minLimit == "" || unitOfMeasurement == "") 
			{
		        break;
		    }
			
			if (productNameToFind == productName)
			{
				found = true;
				cout<<"\tEnter New Sell Price: ";
				cin>>newSellPrice;
				fout << serialNumber << "," << productName << "," << qty << "," << costPrice << "," << newSellPrice << "," << minLimit << "," << category << "," << unitOfMeasurement << endl;
			}
			else if (productName != "")
			{
				fout << serialNumber << "," << productName << "," << qty << "," << costPrice << "," << sellPrice << "," << minLimit << "," << category << "," << unitOfMeasurement << endl;
			}
	}
	
	fout.close();
	fin.close();
	
	remove("POS Project.csv");
	rename("temp.csv", "POS Project.csv");
	
	if (found)
	{
		cout<<"\n\tRecord Updated Successfully"<<endl;
	}
	else
	{
		cout<<"\n\tProduct Not Found"<<endl;
	}
	
}

void deleteProduct() {
	
	string productNameToFind;
	string productName;
	string qty;
	string costPrice;
	string sellPrice;
	string minLimit;
	string serialNumber;
	string unitOfMeasurement;
	string category;
	bool found = false;
	
	cout<<"\tEnter Product Name: ";
	cin.ignore(); 
	getline(cin, productNameToFind);

	
	ofstream fout;
	ifstream fin;
	fin.open("POS Project.csv", ios::in);
	fout.open("temp.csv", ios::out);
	
	while(fin.good())
	{
			getline(fin, serialNumber, ',');
			getline(fin, productName, ',');
			getline(fin, qty, ',');
			getline(fin, sellPrice, ',');
			getline(fin, costPrice,',');
			getline(fin, category, ',');
			getline(fin, minLimit, ',');
			getline(fin, unitOfMeasurement);
			
		    if (serialNumber == "" || productName == "" || qty == "" || sellPrice == "" || costPrice == "" || category == "" || minLimit == "" || unitOfMeasurement == "") 
			{
		        break;
		    }
			
			if (productNameToFind == productName)
			{
				found = true;
				continue;
			}
			else if (productName != "")
			{
				fout << serialNumber << "," << productName << "," << qty << "," << costPrice << "," << sellPrice << "," << minLimit << "," << category << "," << unitOfMeasurement << endl;
			}
	}
	
	fout.close();
	fin.close();
	
	remove("POS Project.csv");
	rename("temp.csv", "POS Project.csv");
	
	if (found)
	{
		cout<<"\n\tRecord Deleted Successfully"<<endl;
	}
	else
	{
		cout<<"\n\tProduct Not Found"<<endl;
	}
}

void updateQuantity() {
	
	string productNameToFind;
	string productName;
	string qty;
	string costPrice;
	string sellPrice;
	string minLimit;
	string serialNumber;
	string unitOfMeasurement;
	string category;
	int newQty;
	bool found = false;
	
	cout<<"\tEnter Product Name: ";
	cin.ignore(); 
	getline(cin, productNameToFind);

	
	ofstream fout;
	ifstream fin;
	fin.open("POS Project.csv", ios::in);
	fout.open("temp.csv", ios::out);
	
	while(fin.good())
	{
			getline(fin, serialNumber, ',');
			getline(fin, productName, ',');
			getline(fin, qty, ',');
			getline(fin, sellPrice, ',');
			getline(fin, costPrice,',');
			getline(fin, category, ',');
			getline(fin, minLimit, ',');
			getline(fin, unitOfMeasurement);
			
		    if (serialNumber == "" || productName == "" || qty == "" || sellPrice == "" || costPrice == "" || category == "" || minLimit == "" || unitOfMeasurement == "") 
			{
		        break;
		    }
			
			if (productNameToFind == productName)
			{
				found = true;
				cout<<"\tEnter New Quantity: ";
				cin>>newQty;
				fout << serialNumber << "," << productName << "," << newQty << "," << costPrice << "," << sellPrice << "," << minLimit << "," << category << "," << unitOfMeasurement << endl;
			}
			else if (productName != "")
			{
				fout << serialNumber << "," << productName << "," << qty << "," << costPrice << "," << sellPrice << "," << minLimit << "," << category << "," << unitOfMeasurement << endl;
			}
	}
	
	fout.close();
	fin.close();
	
	remove("POS Project.csv");
	rename("temp.csv", "POS Project.csv");
	
	if (found)
	{
		cout<<"\n\tRecord Updated Successfully"<<endl;
	}
	else
	{
		cout<<"\n\tProduct Not Found"<<endl;
	}
}

void updateCostPrice() {
	
	string productNameToFind;
	string productName;
	string qty;
	string costPrice;
	string sellPrice;
	string minLimit;
	string serialNumber;
	string unitOfMeasurement;
	string category;
	int newCostPrice;
	bool found = false;
	
	cout<<"\tEnter Product Name: ";
	cin.ignore(); 
	getline(cin, productNameToFind);

	
	ofstream fout;
	ifstream fin;
	fin.open("POS Project.csv", ios::in);
	fout.open("temp.csv", ios::out);
	
	while(fin.good())
	{
			getline(fin, serialNumber, ',');
			getline(fin, productName, ',');
			getline(fin, qty, ',');
			getline(fin, sellPrice, ',');
			getline(fin, costPrice,',');
			getline(fin, category, ',');
			getline(fin, minLimit, ',');
			getline(fin, unitOfMeasurement);
			
		    if (serialNumber == "" || productName == "" || qty == "" || sellPrice == "" || costPrice == "" || category == "" || minLimit == "" || unitOfMeasurement == "") 
			{
		        break;
		    }
			
			if (productNameToFind == productName)
			{
				found = true;
				cout<<"\tEnter New Cost Price: ";
				cin>>newCostPrice;
				fout << serialNumber << "," << productName << "," << qty << "," << newCostPrice << "," << sellPrice << "," << minLimit << "," << category << "," << unitOfMeasurement << endl;
			}
			else if (productName != "")
			{
				fout << serialNumber << "," << productName << "," << qty << "," << costPrice << "," << sellPrice << "," << minLimit << "," << category << "," << unitOfMeasurement << endl;
			}
	}
	
	fout.close();
	fin.close();
	
	remove("POS Project.csv");
	rename("temp.csv", "POS Project.csv");
	
	if (found)
	{
		cout<<"\n\tRecord Updated Successfully"<<endl;
	}
	else
	{
		cout<<"\n\tProduct Not Found"<<endl;
	}
	
}

void readFile() {

	string productName;
	string qty;
	string costPrice;
	string sellPrice;
	string minLimit;
	string serialNumber;
	string unitOfMeasurement;
	string category;

	ifstream file;
	file.open("POS Project.csv", ios::in);
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, serialNumber, ',');
			getline(file, productName, ',');
			getline(file, qty, ',');
			getline(file, sellPrice, ',');
			getline(file, costPrice,',');
			getline(file, category, ',');
			getline(file, minLimit, ',');
			getline(file, unitOfMeasurement);
			
			if (serialNumber == "" || productName == "" || qty == "" || sellPrice == "" || costPrice == "" || category == "" || minLimit == "" || unitOfMeasurement == "") 
			{
		        break;
		    }
			
			cout << "Serial Number: " << serialNumber << "\nProduct Name: " << productName << "\nQuantity: " << qty << "\nCost: " << costPrice << "\nSell Price: " << sellPrice << "\nMinimum Quantity: " << minLimit << "\nCategory: " << category << "\nUnit of Measurement: " << unitOfMeasurement << endl;
			cout<<"------------------------------------------"<<endl;
			
		}
		file.close();
	}
	else
	{
		cout << "File not found" << endl;
	}
	return;
}

void viewSalesRecords(){
	string name;
	string date;
	string totalPrice;
	string discountPrice;
	string priceAfterDiscount;
	fstream filein;
	filein.open("sales history.csv", ios::in);
	while(filein.good())
	{
		getline(filein, name, ',');
		getline(filein, date, ',');
		getline(filein, totalPrice, ',');
		getline(filein, discountPrice, ',');
		getline(filein, priceAfterDiscount, '\n');
		
		if (name == "") break;
		
		cout << "------------------------------------------------------------" << endl;
		cout << " | Name : " << name << endl;
		cout << " | Date & Time : " << date <<endl;
		cout << " | Total Price : " << totalPrice <<endl;
		cout << " | Discount : " << discountPrice <<endl;
		cout << " | Price After Discount : " << priceAfterDiscount << endl << endl;			
	}
	filein.close();
	return;
}

void admin()
{
	int choice = 0;
	while (true)
	{
		time_t now = time(0);
		char dt[26];
		strftime(dt, sizeof(dt), "%Y-%m-%d %H:%M:%S", localtime(&now));
	    string str(dt);
		cout << "\n\n\tAdmin Logged In        "  << dt << endl;
		cout << "1. Add Product\n2. Update Sell Price\n3. Delete Product\n4. Update Quantity\n5. Update Product Name\n6. Update Cost Price\n7. Display All Products\n8. View Sales History\n9. Exit" << endl;
		
		cout << "\tChoose: ";	cin >> choice;

		if (choice == 1)
			insertProduct();
			
		else if (choice == 2)
			updateSellPrice();

		else if (choice == 3)
			deleteProduct();

		else if (choice == 4)
			updateQuantity();
		
		else if (choice == 5)
			updateProductName();

		else if (choice == 6)
			updateCostPrice();			

		else if (choice == 7)
			readFile();
			
		else if (choice == 8)
			viewSalesRecords();	
			
		else if (choice == 9)
			break;
	}
	
}

// ==================================================== CASHIER FUNCTIONS =================================================

void generateReceipt(){
	ifstream recieptFile;
	recieptFile.open("reciept.txt", ios::in);
	string line;
	int qty = 0;
	int salePrice = 0;
	int sum;
	string customerName;
	cout<<"Enter Customer Name: ";
	cin.ignore();
	getline(cin, customerName);
	cout<<"------------------------------------------------------------"<<endl;
	while(recieptFile.good())
	{
		getline(recieptFile, line);
		if (line == "") break;
		
		cout << " | Product Name : " << line <<endl;
		
		getline(recieptFile, line);
		cout << " | Quantity : " << line <<endl;
		stringstream s1(line);
		s1 >> qty;
		
		getline(recieptFile, line);
		cout << " | Price : " << line <<endl;
		stringstream s2(line);
		s2 >> salePrice;
		
		cout << " | Sub Total : " << salePrice * qty <<endl;
		
		sum += (salePrice * qty);
		
		getline(recieptFile, line);
		cout<<"------------------------------------------------------------"<<endl;	
	}
	cout<<" | Total : " << sum << endl;
	cout<<"------------------------------------------------------------"<<endl;


	cout<<"\n\nEnter Discount Value : ";
	int discount; cin>> discount;
	
	int total = sum - discount;
	
	cout<<"------------------------------------------------------------"<<endl;
	cout<<" | Total : " << sum << endl;
	cout<<" | Discount : " << discount << endl;
	cout<<" | Total After Discount : "<< total << endl; 
	cout<<"------------------------------------------------------------"<<endl;
	
	
	recieptFile.close();
	remove("reciept.txt");
	
	time_t now = time(0);
	char dt[26];
	strftime(dt, sizeof(dt), "%Y-%m-%d %H:%M:%S", localtime(&now));
    string str(dt);
	ofstream outfile;
	outfile.open("sales history.csv", ios::app);
	outfile << customerName << "," << dt << "," << sum << "," << discount << "," << total << endl;
	outfile.close();

}

void saleTransaction(){
	
	string productNameToFind;
	string productName;
	string qty;
	int quantity;
	string costPrice;
	string sellPrice;
	string minLimit;
	string serialNumber;
	string unitOfMeasurement;
	string category;
	string newProductName;	
	int requestedQuantity;
	ifstream fin;
	
	do{
		bool found = false;
		cout<<"Enter Product Name: ";
		cin.ignore(); 
		getline(cin, productNameToFind);
		
		cout<< "You have entered "<< productNameToFind << endl;
		
		fin.open("POS Project.csv", ios::in);
		while(fin.good())
		{
			getline(fin, serialNumber, ',');
			getline(fin, productName, ',');
			getline(fin, qty, ',');
			getline(fin, sellPrice, ',');
			getline(fin, costPrice,',');
			getline(fin, category, ',');
			getline(fin, minLimit, ',');
			getline(fin, unitOfMeasurement);
			if (productNameToFind == productName)
			{
				found = true;
				cout<<"Enter Quantity: ";
				cin>>requestedQuantity;
				stringstream ss(qty);
				ss >> quantity;
				if (quantity - requestedQuantity < 0)
				{
					cout<<"Stock not available"<<endl;
					cout<<quantity<<" Units available"<<endl;
				}
				else
				{
					fin.close();
					ofstream fout;
					ifstream filein;
					ofstream recieptFile;
					recieptFile.open("reciept.txt", ios::app);
					fout.open("temp.csv", ios::out);
					filein.open("POS Project.csv", ios::in);
					while(filein.good())
					{
						getline(filein, serialNumber, ',');
						getline(filein, productName, ',');
						getline(filein, qty, ',');
						getline(filein, sellPrice, ',');
						getline(filein, costPrice,',');
						getline(filein, category, ',');
						getline(filein, minLimit, ',');
						getline(filein, unitOfMeasurement);
						
					    if (serialNumber == "" || productName == "" || qty == "" || sellPrice == "" || costPrice == "" || category == "" || minLimit == "" || unitOfMeasurement == "") 
						{
					        break;
					    }
						
						if (productNameToFind == productName)
						{
							fout << serialNumber << "," << productName << "," << quantity - requestedQuantity << "," << costPrice << "," << sellPrice << "," << minLimit << "," << category << "," << unitOfMeasurement << endl;
							recieptFile << productName << endl << requestedQuantity << " " << unitOfMeasurement << endl <<  sellPrice << endl << "---" << endl;
						}
						else if (productName != "")
						{
							fout << serialNumber << "," << productName << "," << qty << "," << costPrice << "," << sellPrice << "," << minLimit << "," << category << "," << unitOfMeasurement << endl;
						}
					}
					
					fout.close();
					filein.close();
					recieptFile.close();
					
					remove("POS Project.csv");
					rename("temp.csv", "POS Project.csv");
				}
				
			}
		}
		
		if(found == false)
			cout<<"Product Not Found"<<endl;
		
		cout<<"\nPress 1 to Generate Reciept \nPress Any Number to Add Another Product: ";
		int choice; cin >> choice;
		if (choice == 1)
		{
			generateReceipt();
			break;	
		}
		fin.close();
			
	}while(1);
	
	
}

void cashier()
{
	system("cls");
	int choice = 0;
	while (true)
	{
		time_t now = time(0);
		char dt[26];
		strftime(dt, sizeof(dt), "%Y-%m-%d %H:%M:%S", localtime(&now));
	    string str(dt);
		cout << "\n\n\tCashier Menu        "  << dt << endl;
		cout << "1. Sale Transaction\n2. Display All Products\n3. View Sales Record\n4. Exit" << endl;
		
		cout << "\tChoose: ";	cin >> choice;

		if (choice == 1)
			saleTransaction();
			
		else if (choice == 2)
			readFile();

		else if (choice == 3)
			viewSalesRecords();

		else if (choice == 4)
			break;
	}
}

int main()
{
	string adminId = "admin";
	string adminPassword = "admin";
	string checkId;
	string checkPassword;


	int user = 0;
	time_t now = time(0);
	char dt[26];
	strftime(dt, sizeof(dt), "%Y-%m-%d %H:%M:%S", localtime(&now));
    string str(dt);


	while (true)
	{
		system("cls");
		cout << "\n\n\tWelcome to POS System\t\t" << dt << endl;
		cout << "\t1-Admin\n\t2-Casheir\n\t3- Any key to exit" << endl;
		cout << "\tChoose: ";
		cin >> user;
		if (user == 1)
		{
			while (true) {
				cout << "\tPlease enter your Admin Id and Password" << endl;
				cout << "\tAdmin Id = ";
				cin >> checkId;

				cout << "\tPassword = ";
				cin >> checkPassword;

				if (adminId == checkId && adminPassword == checkPassword)
				{
					system("cls");
					admin();
					break;
				}
				else
				{
					cout<<"\tWrong ID or Password"<<endl;
					continue;
				}
			}
			
		}
		else if (user == 2)
		{
			cashier();	
		}
		else
			return 0;
	}

	return 0;
}

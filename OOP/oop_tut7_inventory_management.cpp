#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class Inventory{
    public:
        string ItemName;
        int ItemCode;
        int Price;
        int QuantityAvailable;
        // static double AccBalance;
        
    public:
        Inventory(){    // null values
            ItemName = "NULL";
            ItemCode = -1;
            Price = -1;
            QuantityAvailable = -1;
        }
        
        Inventory (string name, int code, int price, int quan){
            ItemName = name;
            ItemCode  = code;
            Price = price;
            QuantityAvailable = quan;
            
            cout << "\n" <<ItemName << " successfully registered!" << endl;
        }
};

// double Inventory::AccBalance = 0;

int main(){
    int choice;
    string line;
    
    do{
        cout << "\n--- Inventory Menu ---\n";
        cout << "1. Display All Records\n";
        cout << "2. Add New Item\n"; 
        //cout << "3. Dispense Item\n"; 
        cout << "3. Exit\n";
        cout << "Enter choice: "; cin >> choice;
        cout << endl;
        
        switch(choice){
            case 1:
                {
                    fstream file1("DataBase.txt", ios::in);
                
                    if (!file1){
                        cout << "Error opening the file!" << endl;
                        break;
                    }
                    
                    while(getline(file1, line)){
                        cout << line << endl;
                    }
                
                    file1.close();
                    
                    cout << endl;
                }
                break;
            
            case 2:
                {
                    Inventory *item = new Inventory;
                    fstream file2("DataBase.txt", ios::app);
                    
                    if (!file2){
                        cout << "Error opening the file!" << endl;
                        break;
                    }
                    
                    cout << "Enter Item Name: "; cin >> item->ItemName;
                    cout << "Enter Item Code: "; cin >> item->ItemCode;
                    cout << "Enter Item's price': "; cin >> item->Price;
                    cout << "Enter no. of items in stock: "; cin >> item->QuantityAvailable;
                    
                    file2 << "Item Name: "  << item->ItemName << endl;
                    file2 << "Item Code: " << item->ItemCode << endl;
                    file2 << "Item Code: " << item->Price << endl;
                    file2 << "In stock: " << item->QuantityAvailable << endl;
                    file2 << " -------- " << endl;
                    file2 << endl;
                    
                    cout << "Successfully updated new data!" << endl;
                    file2.close();
                    delete item;
                    
                    cout << endl;
                }
                break;
        }
    } while (choice != 3);
    
    return 0;
}

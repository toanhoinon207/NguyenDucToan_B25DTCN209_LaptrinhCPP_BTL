#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee{
private:
    int id;
    string name;
    float salary;
public:
    Employee(){
        id=0;
        name="";
        salary=0;
    }

    Employee(int id,string name,float salary){
        this->id=id;
        this->name=name;
        this->salary=salary;
    }

    void input(int id){
        this->id=id;
        cout<<"Nhap ten nhan vien: ";
        getline(cin,name);
        cout<<"Nhap luong: ";
        cin>>salary;
        cin.ignore();
    }

    void printInfo(){
        cout<<"ID: "<<id
            <<" - Ten: "<<name
            <<" - Luong: "<< salary<<endl;
    }

    int getId(){
        return id;
    }

    void setSalary(float salary){
        this->salary=salary;
    }
};

class EmployeeManager {
private:
    vector<Employee> list;
    int nextId;
public:
    EmployeeManager(){
        nextId=3001;
        Employee nvien(3001,"Nguyen Duc Toan",12000000);
    	list.push_back(nvien);
    	nextId++;
    }

    void addEmployee(){
        Employee nvien;
        cin.ignore();
        nvien.input(nextId);
        list.push_back(nvien);
        nextId++;
        cout<<"Them nhan vien thanh cong!!\n";
    }

    void showAll(){
        if(list.empty()){
            cout<<"Danh sach nhan vien rong!!\n";
            return;
        }
        for(int i=0;i<list.size();i++){
            list[i].printInfo();
        }
    }

    void updateSalaryById(){
        int id;
        cout<<"Nhap ID can cap nhat: ";
        cin>>id;
        for(int i=0;i<list.size();i++){
            if (list[i].getId() == id){
                float newSalary;
                cout<<"Nhap luong moi: ";
                cin>>newSalary;
                list[i].setSalary(newSalary);
                cout<<"Cap nhat thanh cong!!\n";
                return;
            }
        }
        cout<<"Khong tim thay nhan vien!!\n";
    }

    void deleteById(){
        int id;
        cout<<"Nhap ID can xoa: ";
        cin>>id;
        for(int i=0;i<list.size();i++){
            if(list[i].getId()==id){
                list.erase(list.begin()+i);
                cout<<"Xoa thanh cong!!\n";
                return;
            }
        }
        cout<<"Khong tim thay nhan vien!!\n";
    }

    void menu(){
        int choice;
        do{
            cout<<"+----------MENU----------+\n";
            cout<<"|1. Them nhan vien       |\n";
            cout<<"|2. Hien thi danh sach   |\n";
            cout<<"|3. Cap nhat luong       |\n";
            cout<<"|4. Xoa nhan vien        |\n";
            cout<<"|5. Thoat                |\n";
            cout<<"+------------------------+\n";
            cout<<"Nhap lua chon: ";
            cin>>choice;
            switch(choice){
                case 1:
                    addEmployee();
                    break;
                case 2:
                    showAll();
                    break;
                case 3:
                    updateSalaryById();
                    break;
                case 4:
                    deleteById();
                    break;
                case 5:
                    cout<<"Thoat chuong trinh!!\n";
                    break;
                default:
                    cout<<"Lua chon khong hop le!!\n";
            }
        } while(choice!=5);
    }
};

int main(){
    EmployeeManager manager;
    manager.menu();
    return 0;
}


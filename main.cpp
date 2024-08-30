#include<iostream>

using namespace std;

typedef struct bank_data bank;
struct bank_data{
    string username;
    string password;
    float ballance;
    bank *next;
};
bank *first_account{NULL};

void badInput();
bool account_manager(bank *current_account);
void account_access_result(bool result);


class access_to_account{
	private:
		string usr{};
		string pass{};
	public:
		bank *register_(){
			cout <<" REGISTER \n";
			cout << "username:";
			cin >> usr;
			cout <<"password:";
			cin >> pass;
            bool exist{false}; 

			bank *new_account{NULL}, *current_account{NULL};
			new_account = new bank;	
			new_account->username = usr;
			new_account->password = pass;
			new_account->ballance = 0.00;
			new_account->next = NULL;

			if(first_account == NULL){
				first_account = new_account;
				return first_account;
			}
			else{
				current_account = first_account;
				while(current_account->next != NULL){
                    if(current_account->username == usr){
                        exist = true;
                        break;
                    }
					    current_account = current_account->next;
				}
                if(exist == false){
				    current_account->next = new_account;
				    new_account = NULL;
				    return current_account->next;
                }
                else{
                    delete(new_account);
                    new_account = NULL;
                    current_account =  NULL; 
                    return NULL;
                }
			}
		}
		bank *login(){
			cout << " LOGIN	\n";
			cout << "username:";
			cin >> usr;
			cout << "password:";
			cin >> pass;
            bool exist{false};
			bank *current_account{};
            if(first_account == NULL){
                return NULL;
            }
            current_account = first_account;
            while(current_account != NULL){
                if(current_account->username == usr){
                    exist = true;
                    break;
                }
            current_account = current_account->next;
            }
			if(exist == false){
				return NULL;
			}
			else{
				return current_account;
			}
		}
    };

int main(){
	string input{};
    access_to_account access;
	while(true){
		cout << "WELCOME TO THE GREAT BANK \n";
		cout << "you can (register) to create a new accoutn \n";
		cout << "you can (login) to an already existing account \n";
		cout << "or you can (exit) the bank \n";
		cout << "what would you like to do::";	
		cin >> input;

		if(input == "register"){
            account_access_result(account_manager(access.register_()));
		}
        else if(input == "login"){
            account_access_result(account_manager(access.login()));
        }
        else if(input == "exit"){
            //smol input 2
            char si{};
            while(true){
                cout << "you are about to exit THE GREAT BANK \n";
                cout << "are you sure (y/n):";
                cin >> si;
                if(si == 'y'){
                    return 0;
                }
                else if(si == 'n'){
                    break;
                }
                else{
                    badInput();
                }
            }
        }
	}
return 0;
}


bool account_manager(bank *current_account){	
	char input{};
	float money{};
	bool run{true};
	if(current_account == NULL){
		return false;
	}	
	else{
		while(run){
			cout << "YOU HAVE ACCECED YOU ACCOUNT SUCCESFULY \n";
			cout << "WHAT WOULD YOU LIKE TO DO \n";
			cout << "(s)how ballace \n";
			cout << "(a)dd money \n";
			cout << "(w)ithraw money \n";
			cout << "(q)uit account \n";
			cout << "press the character corespondente with what you would like to do:";
			cin >> input;

			if(input == 's'){
				cout << "your current ballance is:" << current_account->ballance << "DH \n";
			}
			else if(input == 'a'){
				cout << "how much would you like to add:";
				cin >> money;
				current_account->ballance += money;
				cout << "you have succesfully added:" << money << "DH \n";
				cout << "your current ballance is:" << current_account->ballance << "DH \n";
			}
			else if(input == 'w'){
				cout << "how much would you like to withdraw:";
				cin >> money;
				current_account->ballance -= money;
				cout << "you have succesfully withrew:" << money << "DH \n";
				cout << "your current ballance is:" << current_account->ballance << "DH \n";
			}
			else if(input == 'q'){
				//smoll input
				char si{};
				while(true){
					cout << "you are about to quit your account \n";
					cout << "are you sure (y/n):";
					cin >> si;
					if(si == 'y'){
						run = false;
						break;
					}
					else if(si == 'n'){
						break;
					}
					else{
						badInput();
						continue;
					}
				}
			}
			else{
				badInput();
				continue;
			}
		}
		return true;
	}
}

void account_access_result(bool result){
    if(result){
        cout << "YOU HAVE SUCCESFULLY EXISTED YOUR ACCOUNT :)\n"; }
    else{
        cout << "SOMETHING WENT WRONG PLS TRY AGAIN :( \n";
    }
}

void badInput(){
	cout << "INVALID INPUT ._.\n";
	cout << "try again";
}


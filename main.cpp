#include<iostream>


typedef struct bank_data bank;

struct bank_data{
    std::string username;
    std::string password;
    float ballance;
    bank *next;
};

bank *first_account{NULL};

void badInput();
bool account_manager(bank *current_account);
void account_access_result(bool result);
void cleanUp();


class access_to_account{
	private:
        std::string usr{};
        std::string pass{};
	public:
        bank *register_to_account();
        bank *login_to_account();
    };

int main(){
    std::string input{};
    access_to_account access;

	while(true){

        std::cout << "\tWELCOME TO THE GREAT BANK \n"
		<< "you can (register) to create a new accoutn \n"
		<< "you can (login) to an already existing account \n"
		<< "or you can (exit) the bank \n"
		<< "what would you like to do :";
		std::cin >> input;

		if(input == "register"){
            account_access_result(account_manager(access.register_to_account()));
		}
        else if(input == "login"){
            account_access_result(account_manager(access.login_to_account()));
        }
        else if(input == "exit"){
            //smol input 2
            char si{};
            while(true){
                std::cout << "you are about to exit THE GREAT BANK \n";
                std::cout << "are you sure (y/n):";
                std::cin >> si;
                if(si == 'y'){
                    cleanUp();
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
        else{
            badInput();
        }
	}
}


bool account_manager(bank *current_account){	
	char input{};
	float money{};
	bool run{true};
	if(current_account == NULL){
		return false;
	}	
	else{
			std::cout << "\tYOU HAVE ACCECED YOU ACCOUNT SUCCESFULY \n";
		while(run){
			std::cout << "WHAT WOULD YOU LIKE TO DO \n"
			<< "(s)how ballace \n"
			<< "(a)dd money \n"
			<< "(w)ithraw money \n"
			<< "(q)uit account \n"
			<< "press the character corespondente with what you would like to do:";
			std::cin >> input;

			if(input == 's'){
				std::cout << "your current ballance is:" << current_account->ballance << "DH \n";
			}
			else if(input == 'a'){
				std::cout << "how much would you like to add:";
				std::cin >> money;
				current_account->ballance += money;
				std::cout << "you have succesfully added:" << money << "DH \n";
				std::cout << "your current ballance is:" << current_account->ballance << "DH \n";
			}
			else if(input == 'w'){
				std::cout << "how much would you like to withdraw:";
				std::cin >> money;
				current_account->ballance -= money;
				std::cout << "you have succesfully withrew:" << money << "DH \n";
				std::cout << "your current ballance is:" << current_account->ballance << "DH \n";
			}
			else if(input == 'q'){
				//smoll input
				char si{};
				while(true){
					std::cout << "you are about to quit your account \n";
					std::cout << "are you sure (y/n):";
					std::cin >> si;
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
        std::cout << "YOU HAVE SUCCESFULLY EXISTED YOUR ACCOUNT :)\n"; }
    else{
        std::cout << "SOMETHING WENT WRONG PLS TRY AGAIN :( \n";
    }
}

void badInput(){
	std::cout << "INVALID INPUT ._.\n";
	std::cout << "try again\n";
}

bank *access_to_account::register_to_account(){
		std::cout <<" REGISTER\n";
		std::cout << "username:";
		std::cin >> usr;
		std::cout <<"password:";
		std::cin >> pass;
        bool exist{false}; 

		bank *new_account{NULL}, *current_account{NULL};
		new_account = new bank;	
        *new_account = { .username = usr,
                         .password = pass,
                         .ballance = 0.00,
                         .next = NULL
    };

		if(first_account == NULL){
			first_account = new_account;
			return first_account;
		}

		else{
			current_account = first_account;
			while(current_account != NULL){
                if(current_account->username == usr){
                    exist = true;
                    break;
                }
				    current_account = current_account->next;
			}
            if(exist == false){
			    current_account = new_account;
			    new_account = NULL;
			    return current_account;
            }
            else{
                delete new_account;
                new_account = NULL;
                current_account =  NULL; 
                return NULL;
            }
	}
}

bank *access_to_account::login_to_account(){

		std::cout << " LOGIN\n";
		std::cout << "username:";
		std::cin >> usr;
		std::cout << "password:";
		std::cin >> pass;

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
            if( current_account->password == pass){        
			    return current_account;
            }
            else{
            return NULL;
            }
		}
	}

void cleanUp(){
    bank *account = first_account;
    bank *tmp{};
    if ( account == NULL){
        std::cout << "there is no accounts\n";
    }
    else{
        while( account != NULL ){
        tmp = account;
        account = account->next;
        delete tmp;
        }
        std::cout << "all account has been deleted\n";
    }
}


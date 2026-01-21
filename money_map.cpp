//Budget Planner Program that helps a user determine  whether their  income is enough to
//cover the spending categories  they care about, and if not, what revisions  are necessary.
//

// Libaries  input
#include<iostream>
#include<cstring>
#include <limits>
#include<vector>
using namespace std;

// Function for menu display. Ask for confirm Yes/No
int menu(const string& prompt,int amount, bool allow_0)
{
//	Variable declare
	string choice {""};
	int output {-1};

	while (output == -1)
	 {
		if (allow_0 == true)
		{
	        cout << prompt << amount << " (Y/N)"<< endl; //Insert amount in the middle of message for clarify
	        cin >> choice;
	        cin.ignore(100,'\n');
	        }
	        else
	        {
	        cout << prompt << endl;
	        cin >> choice;
		cin.ignore(100,'\n');
	        }


//		Only accept Y/y/N/n
	        if (choice == "Y" || choice == "y") output = 1;
	        else if (choice == "N" || choice == "n") output = 0;
		else  cout << "Invalid entry. Please use Y or N." << endl; //Bad input case
	 }
return output;
}

// Function for verify user input is interger and >0 or >=0
int check_negative(const string& prompt,bool allow_0,bool allow_confirm)
{

//	Variable declare
	int input{0};
	int output{-1};
	bool check_logic {false};
	string confirm_prompt = "Please confirm your number is: ";

	while (check_logic == false)
	{
		cout << prompt;
		if (cin >> input) // Only take input is interger
	{
		if(allow_0 == false && input <= 0) cout << "Invalid entry. Please enter number greater than 0 (>0)." << endl;
		if(allow_0 == true && input < 0) cout << "Invalid entry. Please enter a non negative number(>=0)." << endl;

		if(input >= 0 && allow_0 == true) output=input;
		if(input > 0 && allow_0 == false) output=input;

		if (allow_confirm == true && output == input)
		{
			if (menu(confirm_prompt,output,true) == 1) check_logic = true;
		}
		else
		{
			if(output == input) check_logic = true;
		}
	}
		else //Bad input case, void break the program
        {
	            cout << "Invalid input. Please enter a whole number." << endl;

	            cin.clear(); // Reset the error flags
	            cin.ignore(100,'\n');
        }
	}
return output;
}


int main()
{

//	Constant values of Goals
	const double NEEDS_GOAL {50.00};
	const double WANTS_GOAL {30.00};
	const double SAVINGS_GOAL {20.00};
	const double TOLERANCE {5.00};

//	Will check for redo prompt at last
	bool check_redo {false};

	while (check_redo == false)
	{

//		Variable declare
		int monthly_income {0};
		int num_categories {0};
		int monthly_total {0};
		int monthly_balance {0};
		int period_balance {0};

		int num_months {0};

		int total_needs {0};
		int total_wants {0};
		int savings_gap {0};
		double wants_percent {0.00};
		double needs_percent {0.00};
		double savings_percent {0.00};

//		Lagest elements for report purpose
		int needs_max_value {0};
		string needs_max_name {""};
		double needs_max_percent {0.00};

		int wants_max_value {0};
		string wants_max_name {""};
		double wants_max_percent {0.00};

//		Size of wants and needs categories
		int size_wants {0};
		int size_needs {0};

//		Variable for wants and needs elements
		vector<string> wants_names;
		vector<int> wants_values;

		vector<string> needs_names;
		vector<int> needs_values;

//		Welcome message
		cout << "===================================================================================" << endl;
		cout << "                             WELCOME TO THE BUDGET PLANNER                              " << endl;
		cout << "===================================================================================" << endl;

		cout << "\n[ PROGRAM OVERVIEW ]" << endl;
		cout << "This tool helps you see where your money goes and where you want it to go." << endl;
		cout << "By comparing what you earn and what you spend, it gives clear tips to help" << endl;
		cout << "you manage your money better." << endl;
		cout << "\n-----------------------------------------------------------------------------------" << endl;
		cout << "[ THE FINANCIAL THEORY: THE 50/30/20 RULE ]" << endl;
		cout << "This program uses the simple 50/30/20 budget rule:" << endl;
		cout << " * 50% for NEEDS:    Fixed costs like rent, food, and bills." << endl;
		cout << " * 30% for WANTS:    Extra spending like eating out, fun, and trips." << endl;
		cout << " * 20% for SAVINGS:  Paying debt, saving for emergencies, and the future." << endl;

		cout << "\n-----------------------------------------------------------------------------------" << endl;
		cout << "Ready to take control of your finances? Let's begin." << endl;
		cout << "===================================================================================\n" << endl;

//		Instruction message
		string prompt = "\nDo you want to walk through detailed instruction? (Y/N)";
		if (menu(prompt,0,false) == 1)
		{
		cout << "=======================================================================================" << endl;
		cout << "                                     INSTRUCTION                                       " << endl;
		cout << "=======================================================================================" << endl;
		cout << "\n[ HOW TO USE THIS PROGRAM ]" << endl;
		cout << " 1. INPUT INCOME:  Enter your total monthly take-home pay." << endl;
		cout << " 2. CATEGORIZE:    Write down your 'Wants' and 'Needs'. Use simple names." << endl;
		cout << " 3. ANALYZE:       The program will calculate your percentages and identify which " << endl;
		cout << "                   specific categories are impacting your savings goals most." << endl;
		cout << " 4. ITERATE:       If you are overspending, the program will allow you to re-adjust " << endl;
		cout << "                   your numbers until your budget is balanced." << endl;
		cout << "=======================================================================================" << endl;

		}

//		Income input
		prompt = "\nPlease input your monthly income (>$0):  ";
		monthly_income = check_negative(prompt,false,true);

		prompt = "\nHow many months do you want to planing the budget for ? ";
		num_months = check_negative(prompt,false,false);

//		Categories input
		while (num_categories < 4)
		{

			cout <<"\nYou need at least 4 categories in total (Wants+Needs)\n"<<endl;
			num_categories = 0;
		    	prompt = "How many 'Needs' categories do you have (Rent,Utilities,Groceries,Transportation,...)?  ";
			int size_needs = check_negative(prompt,true,false);

			needs_names.resize(size_needs);
			needs_values.resize(size_needs);

			for (int i = 0; i < size_needs; i++)
			{
				cin.ignore(100,'\n');
			        cout << "\nCategory Needs#" << (i + 1) << " name: ";
			        getline(cin,needs_names[i]);

			        string prompt = "Budget for " + needs_names[i] + ": ";
			        needs_values[i] = check_negative(prompt,false,false);
			        if (needs_values[i] >= needs_max_value) //Lagest value store for report purpose
			        {
			        	needs_max_value = needs_values[i];
			        	needs_max_name = needs_names[i];
			        }
			        total_needs += needs_values[i];
		        }

			prompt = "\nHow many 'Wants' categories do you have (Dining,Subscriptions,Entertainment,Hobby,...)?  ";
			int size_wants = check_negative(prompt,true,false);

			wants_names.resize(size_wants);
			wants_values.resize(size_wants);

			for (int i = 0; i < size_wants; i++)
			{
				cin.ignore(100,'\n');
			        cout << "\nCategory Wants#" << (i + 1) << " name: ";
				getline(cin,wants_names[i]);

			        string prompt = "Budget for " + wants_names[i] + ": ";
			        wants_values[i] = check_negative(prompt,false,false);
			        if (wants_values[i] >= wants_max_value)
			        {
			        	wants_max_value = wants_values[i];
			        	wants_max_name = wants_names[i];
			        }
			        total_wants += wants_values[i];
		        }

		        num_categories = size_wants + size_needs;
		}

		// Calculation
		monthly_total = total_wants + total_needs;
		monthly_balance = monthly_income - monthly_total;
		period_balance = monthly_balance*num_months;
		savings_gap = (0.20 * monthly_income) - monthly_balance;

		wants_percent = (static_cast<float>(total_wants) / static_cast<float>(monthly_income)) * 100;
		needs_percent = (static_cast<float>(total_needs) / static_cast<float>(monthly_income)) * 100;
		savings_percent = (static_cast<float>(monthly_balance) / static_cast<float>(monthly_income)) * 100;

		wants_max_percent = (static_cast<float>(wants_max_value) / static_cast<float>(monthly_income)) * 100;
		needs_max_percent = (static_cast<float>(needs_max_value) / static_cast<float>(monthly_income)) * 100;

		//Print Report
		cout << "\n============================================================" << endl;
		cout << "                OFFICIAL BUDGET ANALYSIS REPORT             " << endl;
		cout << "============================================================" << endl;


		cout << "EXECUTIVE SUMMARY" << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "Total Monthly Income:    $" << monthly_income << endl;
		cout << "Total Monthly Expenses:  $" << monthly_total << endl;
		cout << "Net Monthly Savings:     $" << monthly_balance << " (" << savings_percent << "%)" << endl;
		cout << "Projected Savings over " << num_months << " months: $" << period_balance << endl;
		cout << "------------------------------------------------------------" << endl;


		cout << "\nSPENDING BREAKDOWN" << endl;
		cout << "* NEEDS: " << needs_percent << "% of income (Goal: 50%)" << endl;
		cout << "  - Largest Need: " << needs_max_name << " ($" << needs_max_value << ")" << endl;

		cout << "* WANTS: " << wants_percent << "% of income (Goal: 30%)" << endl;
		cout << "  - Largest Want: " << wants_max_name << " ($" << wants_max_value << ")" << endl;

		cout << "* SAVINGS: " << savings_percent << "% of income (Goal: 20%)" << endl;


		cout << "\nSTRATEGIC FEEDBACK & ADVICE" << endl;
		cout << "------------------------------------------------------------" << endl;


		if (monthly_balance < 0)
		{
			cout << "[!] CRITICAL: You are currently outspending your income by $" << abs(monthly_balance) 
			     << " every month. You are likely relying on debt." << endl;

			if (wants_percent > WANTS_GOAL)
			{
			        cout << ">>> ACTION: Your 'Wants' are at " << wants_percent << "%. Reduce spending on "
			             << wants_max_name << " immediately to balance your budget." << endl;
			}
			else
			{
			        cout << ">>> ACTION: Your 'Wants' are already low. You must find ways to reduce 'Needs' like "
			             << needs_max_name << " or increase your income." << endl;
			}
		}
		else if (savings_percent < SAVINGS_GOAL)
		{
			cout << "[!] WARNING: You are living within your means, but your savings rate is low." << endl;
			cout << ">>> ADVICE: To hit the 20% savings goal, try to saving $" << savings_gap << " more each month" << endl;

			if (wants_percent > WANTS_GOAL)
			{
			   	cout << "\nAnalysis: Your 'Wants' are at " << wants_percent << "%, exceeding the 30% limit." << endl;
			   	cout << ">>> ADVICE: You have high lifestyle spending. Immediate action:" << endl;
			   	cout << "    1. Trim " << wants_max_name << " (your biggest 'Want') by $" << savings_gap << "." << endl;
			   	cout << "    2. Audit your subscriptions and daily 'micro-spends' (coffee, apps, takeout)." << endl;
			}

			if (needs_percent > (NEEDS_GOAL+TOLERANCE))
			{
				cout << "\nAnalysis: Your 'Needs' are consuming " << needs_percent << "% of your income." << endl;
				cout << ">>> ADVICE: Your fixed costs are high. Look for 'Big Wins':" << endl;
				cout << "    1. Can you refinance or renegotiate your " << needs_max_name << "?" << endl;
				cout << "    2. Consider 'Needs' optimization: shop for cheaper insurance or utility providers." << endl;
			}
			if (needs_percent <= (NEEDS_GOAL+TOLERANCE) && wants_percent <= (WANTS_GOAL+TOLERANCE) && savings_percent > 0)
			{
				cout << "\nAnalysis: You are close! No single category is exploding, but you are slightly over in both." << endl;
				cout << ">>> ADVICE: Use the 1% Rule. Reduce every category by just 1-2% to bridge the $" << savings_gap << " gap." << endl;
			}
		}
		else
		{
		    cout << "[+] EXCELLENT: You are following a healthy financial plan!" << endl;
		    cout << ">>> ADVICE: Consider investing your monthly $" << monthly_balance << " surplus." << endl;
		}

		cout << "============================================================" << endl;

		prompt = "\n\nDo you want to re-try another sencenerio ? (Y/N)";
		if (menu(prompt,0,false) == 0) check_redo = true;
	}
return 0;
}


# Plan50/30/20

A C++ console-based program that helps users assess and balance their monthly budget using the 50/30/20 financial planning rule. The application allows users to input income, categorize spending into **Needs** and **Wants**, and receive actionable financial advice based on their input.

---

## 🧾 Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Example Walkthrough](#example-walkthrough)
- [Dependencies](#dependencies)
- [Troubleshooting](#troubleshooting)
- [Contributors](#contributors)

---
<a id="introduction"></a>
## 📘 Introduction

This tool provides personal budget analysis using the 50/30/20 rule:
- **50% Needs**: Rent, utilities, groceries, etc.
- **30% Wants**: Dining out, entertainment, hobbies, etc.
- **20% Savings**: Emergency fund, debt repayment, investments.

By categorizing expenses and evaluating them against income, the program delivers personalized advice to help users improve financial health.

---
<a id="features"></a>
## ✅ Features

- Input monthly income and budget period.
- Add customizable **Needs** and **Wants** categories.
- Visual breakdown of expenses with percentages.
- Strategic advice for savings, overspending, and optimization.
- Scenario-based budgeting for multiple months.
- Built-in input validation and user-friendly prompts.

---
<a id="installation"></a>
## 💾 Installation

### Requirements:
- C++ compiler (e.g., `g++`)
- C++11 standard or later

### Steps:
1. Clone or download this repository.
2. Compile the program:
   ```bash
   g++ -std=c++11 -o money_map money_map.cpp
   ```
3. Run the program:
   ```bash
   ./money_map
   ```
---
<a id="usage"></a>
## 🚀 Usage
When you run the program:

 1. **Overview & Instructions** – Optionally review how the program works.
2. **Income Input** – Enter your monthly take-home pay.
3. **Duration** – Enter the number of months you’re budgeting for.
4. **Categorize Spending** – Input categories for **Needs** and **Wants**, with custom names and values.
5. **Report** – Get a breakdown and analysis, including:
   - Spending vs. Goals
   - Largest expense categories
   - Personalized advice for adjustments
6. **Repeat** – Option to try another scenario.

---
<a id="example-walkthrough"></a>
## 🧪 Example Walkthrough

```bash
===================================================================================
                             WELCOME TO THE BUDGET PLANNER
===================================================================================

[ PROGRAM OVERVIEW ]
This tool helps you see where your money goes and where you want it to go.
By comparing what you earn and what you spend, it gives clear tips to help
you manage your money better.

-----------------------------------------------------------------------------------
[ THE FINANCIAL THEORY: THE 50/30/20 RULE ]
This program uses the simple 50/30/20 budget rule:
 * 50% for NEEDS:    Fixed costs like rent, food, and bills.
 * 30% for WANTS:    Extra spending like eating out, fun, and trips.
 * 20% for SAVINGS:  Paying debt, saving for emergencies, and the future.

-----------------------------------------------------------------------------------
Ready to take control of your finances? Let's begin.
===================================================================================


Do you want to walk through detailed instruction? (Y/N)
y
=======================================================================================
                                     INSTRUCTION
=======================================================================================

[ HOW TO USE THIS PROGRAM ]
 1. INPUT INCOME:  Enter your total monthly take-home pay.
 2. CATEGORIZE:    Write down your 'Wants' and 'Needs'. Use simple names.
 3. ANALYZE:       The program will calculate your percentages and identify which
                   specific categories are impacting your savings goals most.
 4. ITERATE:       If you are overspending, the program will allow you to re-adjust
                   your numbers until your budget is balanced.
=======================================================================================

Please input your monthly income (>$0):  1000
Please confirm your number is: 1000 (Y/N)
y

How many months do you want to planing the budget for ? 12

You need at least 4 categories in total (Wants+Needs)

How many 'Needs' categories do you have (Rent,Utilities,Groceries,Transportation,...)?  2

Category Needs#1 name: Rent
Budget for Rent: 650

Category Needs#2 name: Utilities
Budget for Utilities: 100

How many 'Wants' categories do you have (Dining,Subscriptions,Entertainment,Hobby,...)?  2

Category Wants#1 name: Eat out
Budget for Eat out: 100

Category Wants#2 name: Subscriptions
Budget for Subscriptions: 70

============================================================
                OFFICIAL BUDGET ANALYSIS REPORT
============================================================
EXECUTIVE SUMMARY
------------------------------------------------------------
Total Monthly Income:    $1000
Total Monthly Expenses:  $920
Net Monthly Savings:     $80 (8%)
Projected Savings over 12 months: $960
------------------------------------------------------------

SPENDING BREAKDOWN
* NEEDS: 75% of income (Goal: 50%)
  - Largest Need: Rent ($650)
* WANTS: 17% of income (Goal: 30%)
  - Largest Want: Eat out ($100)
* SAVINGS: 8% of income (Goal: 20%)

STRATEGIC FEEDBACK & ADVICE
------------------------------------------------------------
[!] WARNING: You are living within your means, but your savings rate is low.
>>> ADVICE: To hit the 20% savings goal, try to saving $120 more each month

Analysis: Your 'Needs' are consuming 75% of your income.
>>> ADVICE: Your fixed costs are high. Look for 'Big Wins':
    1. Can you refinance or renegotiate your Rent?
    2. Consider 'Needs' optimization: shop for cheaper insurance or utility providers.
============================================================


Do you want to re-try another sencenerio ? (Y/N)
```

---
<a id="dependencies"></a>
## 📦 Dependencies

C++ Library Used:
  - `iostream`
  - `vector`
  - `string`


---
<a id="troubleshooting"></a>
## 🛠️ Troubleshooting
| Issue                      | Solution                                                     |
| -------------------------- | ------------------------------------------------------------ |
| Input not accepted         | Ensure input is a whole number (no decimals or letters).     |
| Program exits unexpectedly | Use valid prompts (Y/N) when asked for confirmation.         |
| Can't compile              | Ensure you're using a compiler that supports C++11 or later. |

--- 
<a id="contributors"></a>
## 👨‍💻 Contributor

  - **Patrick Nguyen** - Developer and author of the Budget Planner
 
 >Feel free to contribute by opening issues or pull requests!


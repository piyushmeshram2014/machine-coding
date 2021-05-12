#include <bits/stdc++.h>
using namespace std;

struct Wallet
{
    int id;
    string name;
    int balance;
};

struct Statement
{
    Wallet wallet;
    
    int previousBalance;
    int currentBalance;
    
    int fromId;
    int toId;
    
    string typeOfTransfer;
};

//assuming number of wallet holders are 5;
map<int,vector<Statement>>statements;

//using dummy wallet to credit offer amount to wallet holders;
Wallet dummy = { .id = -1 };

void initializeWallet(Wallet* w1,int id,string name)
{
    Wallet w = *w1;
    
    //set wallet details
    w.id=id;
    w.name=name;
    w.balance=0;
    
    //create a Statement
    Statement statement;
    
    //store from , to account id 
    statement.fromId = -1;
    statement.toId = -1;
    
    statement.wallet = w;
    statement.previousBalance = w.balance;
    
    
    w.balance = w.balance + 100;
    statement.currentBalance = w.balance;
    statement.typeOfTransfer = "Cr";
    
    //lastly insert the statement into the wallet holder map;
    statements[w.id].push_back(statement);
    
    *w1 = w;
}

void activateOffer(Wallet* a1,int offerAmount)
{
    Wallet a = *a1;
    
    
    //create an entry in Statement
    Statement statementA;
    
    //store wallet info in statement
    statementA.wallet = a;
    
    //store from , to account id
    statementA.fromId = -1;
    statementA.toId = a.id;
    
    statementA.previousBalance = a.balance;
    a.balance = a.balance + offerAmount;
    statementA.currentBalance = a.balance;
    
    statementA.typeOfTransfer="Cr";
    
    statements[a.id].push_back(statementA);
    
    *a1=a;
}

void transfer(Wallet* a1, Wallet* b1,int amount)
{
    Wallet a = *a1;
    Wallet b = *b1;
    
    Statement statementA,statementB;
    
    //store wallet info in statement
    statementA.wallet = a;
    statementB.wallet = b;
    
    //store from , to account id 
    statementA.fromId = a.id;
    statementA.toId = b.id;
    statementB.fromId = a.id;
    statementB.toId = b.id;
    
    //store balance before transaction
    statementA.previousBalance=a.balance;
    statementB.previousBalance=b.balance;
    
    //Check if sender has sufficient funds to tranfer
    if(a.balance-amount < 0)
    {
        cout<<a.id<<" "<<a.balance<<" "<<amount<<" ";
        cout<<"Transaction Declined.Insufficient Funds"<<endl;
        return;
    }
    
    //Transaction Start : store balance after transaction
    statementA.currentBalance = a.balance - amount;
    a.balance = statementA.currentBalance;
    
    statementB.currentBalance = b.balance + amount;
    b.balance = statementB.currentBalance;
    
    //type of transfer
    statementA.typeOfTransfer="Dr";
    statementB.typeOfTransfer="Cr";
    
    statements[a.id].push_back(statementA);
    statements[b.id].push_back(statementB);
    
    //trigger applicable offer only once if balance are equal
    if(a.balance == b.balance)
    {
        // cout<<"offer"<<endl;
        activateOffer(&a,10);
        activateOffer(&b,10);
    }
    
    *a1=a;
    *b1=b;
}

void ViewStatement(Wallet a)
{
    vector<Statement>listOfTranactions = statements[a.id];
    
    
    cout<<"Waller Holder Name : "<<a.name<<endl;
    cout<<"============================================="<<endl;
    cout<<"From"<<"     "<<"To"<<"      "<<"Previous Balance"<<"        "<<"Current Balance"<<"     "<<"Type"<<"        "<<endl;
    for(auto transaction : listOfTranactions)
    {
        cout<<transaction.fromId<<"     "<<transaction.toId<<"      "<<transaction.previousBalance<<"        "<<transaction.currentBalance<<"        "<<transaction.typeOfTransfer<<endl;
    }
    cout<<"============================================="<<endl;
    cout<<endl;
}

//list current balance of all wallet holders
void overview()
{
    //map<int,vector<Statement>>statements;
    
    cout<<"Account Holder"<<"       "<<"Balance"<<"     "<<endl;
    for(auto it:statements)
    {
        vector<Statement>statements = it.second;
        Statement latestStatement = statements.back();
        Wallet wallet = latestStatement.wallet;
        cout<<wallet.name<<"       "<<wallet.balance<<endl;
    }
    
}
int main() {
	
	//initialize wallet
	Wallet ram,shyam;
	initializeWallet(&ram,1,"ram");
	initializeWallet(&shyam,2,"shyam");
	
	//transfer money from ram to shyam
	transfer(&ram,&shyam,10);
	transfer(&shyam,&ram,20);
	transfer(&ram,&shyam,10);
	//view statement for walletholder
	ViewStatement(ram);
    ViewStatement(shyam);
    
    overview();
}




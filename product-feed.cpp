#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct Product
{
    int id;
    string name;
    int price;
};

struct Seller
{
    int id;
    string name;
    vector<Product>products;
    
};

struct Buyer
{
    int id;
    string name;
    vector<Seller>subscribedSeller;
};

map<int,vector<int>>buyerMap;

map<int,vector<Product>>sellerMap;

//TODO
// void createUser(int type, String name)
// {
    
// }

void createBuyer(int id,string name)
{
    Buyer newBuyer;
    newBuyer.id = id;
    newBuyer.name=name;
}

void subscribeToSeller(int buyerId,int sellerId)
{
    buyerMap.insert(pair<int,int>(buyerId,sellerId));
}

void createSeller(int id,string name)
{
    Seller newSeller;
    newSeller.id=id;
    newSeller.name=name;
}

void deleteSellerFromBuyerSubscriptionList(int sellerId)
{
    for(auto it : buyerMap)
    {
        vector<int>sellerIdList = it.second;
        
        vector<int>::iterator i = find(sellerIdList.begin(), sellerIdList.end(), sellerId);
        sellerIdList.erase(i);
    }
}
void deleteSeller(int id)
{
    if(sellerMap.find(id) != sellerMap.end())
    {
        deleteSellerFromBuyerSubscriptionList(id);
        sellerMap.erase(id);
    }
}

void publishPost(int sellerId,int productId,string name,int price)
{
    Product product;
    product.id=productId;
    product.name=name;
    product.price=price;
    
    sellerMap[sellerId].push_back(product);
}


int main() {
	
	//create a buyer : Ram
	createBuyer(1,"Ram");
	
	//createSeller : Shyam
	createSeller(1,"Shyam");
	
	
	return 0;
}

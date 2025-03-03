/*
 * pizzaria.h
 *
 *  Created on: Oct 21, 2015
 *      Author: RRossetti
 */

#ifndef PIZZERIA_H_
#define PIZZERIA_H_

#include <string>
#include <vector>
#include <iostream>

#include "sequentialSearch.h"
#include "insertionSort.h"

class ExceptionIngredientsRepeated{
public:
    ExceptionIngredientsRepeated();
};

using namespace std;

template<class Comparable>
bool isSet(const vector<Comparable>& v1){
    for(int i = 0; i < v1.size()-1;i++){
        for(int j= i+1; j<v1.size();j++)
            if(v1[i] == v1[j])
                return false;
    }
    return true;
}

class Menu {
    static int idAux;
	int id;
	string name;
	int likes;
	vector<string> ingredients;
public:
    class ExceptionIngredientsRepeated{
    public:
        ExceptionIngredientsRepeated(){};
    };
	Menu();
	Menu(string n1, vector<string> is1);
	Menu(int id1, string n1, vector<string> is1, int lks1);
	int getId() const;
	void setId(int id1);
	string getName() const;
	void setName(string n1);
	vector<string> getIngredients() const;
	void addLike() { ++likes; }
	int getLikes() const { return likes; }
	void setIngredients(const vector<string> &is1);
    class ExceptionIngredientNotPresent{
        string ingredient;
    public:
        ExceptionIngredientNotPresent(string ingredient): ingredient(ingredient){};
        string getIngredient(){return ingredient;};
    };
};

class Customer {
	int nif;
	string name;
public:
	Customer(int nif1, string n1);
	int getNIF() const;
	string getName() const;
};

class Pizzeria {
	vector<Menu> menus;
	vector<Customer*> customers;
public:
	Pizzeria();
	Pizzeria(vector<Menu> ms1);
	vector<Menu> getMenus() const;
	vector<Customer*> getCustomers() const;
	int addCustomer(Customer* c1);
	vector<Menu> optionsWithinIngredientLimits(int i1, int i2) const;
	vector<Menu> popularityRank() const;
	Customer* chefCustomer();
	Menu& removeIngredient(vector<string> is1, string i1);
    class ExceptionInvalidIngredientLimits{
    public:
        ExceptionInvalidIngredientLimits(){};
    };
    class ExceptionInexistentMenu{
    public:
        ExceptionInexistentMenu(){};
    };

};



#endif /* PIZZERIA_H_ */

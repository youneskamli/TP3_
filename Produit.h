#include <iostream>

#ifndef PRODUIT_H
#define PRODUIT_H
class Produit
{
public:
	Produit();
	Produit(std::string titre, std::string description,int quantite, double prix);
	std::string getTitre();
	std::string getDesc();
	int getQuantite();
	double getPrix();
	void setQuantite(int quantite);
private:
	std::string _titre;
	std::string _description;
	int _quantite;
	double _prix;

};

std::ostream& operator<<(std::ostream& flux, Produit &produit);

#endif
#include "Produit.h"
Produit::Produit()
{
}

Produit::Produit(std::string titre, std::string description, int quantite, double prix): _titre(titre), _description(description), _quantite(quantite), _prix(prix)
{
	static int id=1;//Chaque produit aura un id différent
	_id=id++;
}

std::string Produit::getTitre()
{
	return _titre;
}

int Produit::getId()
{
	return _id;
}

std::string Produit::getDesc()
{
	return _description;
}

int Produit::getQuantite()
{
	return _quantite;
}

double Produit::getPrix()
{
	return _prix;
}

void Produit::setQuantite(int quantite)
{
	_quantite = quantite;
}


std::ostream& operator<<(std::ostream& flux, Produit &produit)
{
	flux <<"Id : "<< produit.getId() << " ; Nom : "<< produit.getTitre() << " ; Description : " << produit.getDesc() << " ; Quantite disponible : " << produit.getQuantite() << " ; Prix : " << produit.getPrix()<<std::endl;
	return flux;
}
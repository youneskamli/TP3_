#include <iostream>
#include<vector>
#include "Produit.h"
#include "Client.h"

#ifndef MAGASIN_H
#define MAGASIN_H
class Magasin {
public:
	Magasin();
	void addProduit(Produit produit);
	void afficheProduits();
	void ChercheProduit(std::string produit_cherche);
<<<<<<< HEAD
<<<<<<< Updated upstream
	void updateQuantity(std::string nom ,int quantite);
=======
	void updateQuant(std::string nom ,int quantite);
	void AddClient(Client client);
>>>>>>> Stashed changes
=======
	void updateQuant(std::string nom ,int quantite);
>>>>>>> test

private:
	std::vector<Produit> _produits;
	std::vector<Client> _clients;
	//std::vector<Order> _orders;


};

#endif
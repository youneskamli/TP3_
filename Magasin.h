#include <iostream>
#include<vector>
#include "Commande.h"

#ifndef MAGASIN_H
#define MAGASIN_H
class Magasin {
public:
	Magasin();
	void addProduit(Produit produit);
	void afficheProduits();
	void ChercheProduit(std::string produit_cherche);
	int getNbInStore(std::string produit_cherche);
	void updateQuant(std::string nom ,int quantite);
	std::vector<Client> getClients();
	void AddClient(Client client);
	void afficheClients();
	void ChercheClient(std::string client_cherche);
	void addToClientCart(Client &client,Produit &produit);
	void DelFromClientCart(Client &client, Produit &produit);
	void updateQuantFromClientCart(Client &client, Produit &produit, int quantite);
	void AddCommande(Commande commande);
	void ValiderCommande(Commande commande);
	void setStatutCommande(Commande commande,bool statut);
	void afficheCommandes();
	void ChercheCommande(Client client);


private:
	std::vector<Produit> _produits;
	std::vector<Client> _clients;
	std::vector<Commande> _commande;


};

#endif
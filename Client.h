#include <iostream>
#include <vector>
#include "Produit.h"
#ifndef CLIENT_H
#define CLIENT_H

class Client{
public:
    Client(std::string _prenom,std::string _nom,int _id);
    std::string getPrenom();
    std::string getNom();
    int getId();
    std::vector<Produit> getPanier();
    void addToPanier(Produit produit);
    void DeletePanier();
    void updateInCart(std::string nom,int quantite);
    void DeleteFromPanier(std::string nom);
    std::string AfficherPanier();

private:
    std::string _prenom;
    std::string _nom;
    int _id;
    std::vector<Produit> _panier;
    bool _validation=false;
    std::vector<int> _nbproduits;
};

std::ostream& operator<<(std::ostream& flux, Client &client);

#endif
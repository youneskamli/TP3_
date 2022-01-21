#include <iostream>
#include <vector>
#include "Client.h"
#ifndef COMMANDE_H
#define COMMANDE_H

class Commande
{
public:
    Commande(Client client);
    ~Commande();
    int getId();
    Client getClient();
    std::vector<Produit> getPanier();
    std::vector<int> getQuantitePanier();
    bool getStatut();
    void setStatut(bool statut);
    void setPanier(std::vector<Produit> NouveauPanier);
    void setQuantite(std::vector<int> quantite);


private:
    int _id;
    Client _client;
    std::vector<Produit> _panierAchat;
    std::vector<int> _quantiteAchat;
    bool _statut;
};

std::ostream& operator<<(std::ostream& flux, Commande &commande);

#endif
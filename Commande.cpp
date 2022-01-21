#include "Commande.h"

Commande::Commande(Client client):_client(client)
{
    static int ref=1;
	_id=ref++;
    _panierAchat=client.getPanier();
    _quantiteAchat=client.getNbInPanier();
    _statut=false;
}

Commande::~Commande(){}

int Commande::getId()
{
    return _id;
}

Client Commande::getClient()
{
    return _client;
}

std::vector<Produit> Commande::getPanier()
{
    return _panierAchat;
}

std::vector<int> Commande::getQuantitePanier()
{
    return _quantiteAchat;
}

bool Commande::getStatut()
{
    return _statut;
}

void Commande::setStatut(bool statut)
{
    _statut=statut;
}

void Commande::setPanier(std::vector<Produit> NouveauPanier)
{
    _panierAchat=NouveauPanier;
}

void Commande::setQuantite(std::vector<int> quantite)
{
    _quantiteAchat=quantite;
}

std::ostream& operator<<(std::ostream& flux, Commande &commande)
{
    if(commande.getStatut()==0)
        flux<<"Commande numero : "<<commande.getId()<<" ; Client :"<<(commande.getClient()).getNom()<<" ; Panier : "<<(commande.getClient()).AfficherPanier() <<"Commande en cours" <<std::endl;
    if(commande.getStatut()==1)
        flux<<"Commande numero : "<<commande.getId()<<" ; Client :"<<(commande.getClient()).getNom()<<" ; Panier : "<<(commande.getClient()).AfficherPanier() <<"Commande valide" <<std::endl;
    return flux;
}

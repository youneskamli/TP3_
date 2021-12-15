#include "Client.h"

Client::Client(std::string prenom,std::string nom,int id): _prenom(prenom), _nom(nom), _id(id)
{

}

std::string Client::getPrenom()
{
    return _prenom;
}

std::string Client::getNom()
{
    return _nom;
}

int Client::getId()
{
    return _id;
}

std::vector<Produit> Client::getPanier()
{
    for(int i=0;i<_panier.size();i++){
        return _panier;
    }
}


void Client::addToPanier(Produit produit)
{
    if(produit.getQuantite()>0)
        _panier.push_back(produit);
}

void Client::DeletePanier(){
    _panier.clear();

}

void updateCart(Produit produit,int quantite){


}
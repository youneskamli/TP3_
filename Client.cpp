#include "Client.h"
#include <sstream>

Client::Client(std::string prenom,std::string nom,int id): _prenom(prenom), _nom(nom), _id(id)
{
    static int ref=0;//Chaque client aura un id différent
	_id=ref++;
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
        return _panier;
    
}

//Ajouter un produit dans le panier 
void Client::addToPanier(Produit produit)
{
    if(produit.getQuantite()>0){
        _panier.push_back(produit);
        _nbproduits.push_back(1);// Dire par défaut  qu'on prend un seul produit
    }
    else 
        std::cout<<"Le produit n'est plus disponible"<<std::endl;
}

void Client::DeletePanier(){
    _panier.clear();
    _nbproduits.clear();

}

void Client::updateInCart(std::string nom,int quantite)
{
    bool find=0;
    for(int i=0;i<_panier.size(); i++ )
    {
        if(_panier[i].getTitre()==nom || std::to_string(_panier[i].getId())==nom)
        {
            _nbproduits[i]=quantite;
            find=1;
        }
    if (find==0)
        std::cout<<"Probleme : le produit n'est pas dans le panier. Veuillez l'ajouter ultérieurement."<<std::endl;
    }

}

void Client::DeleteFromPanier(std::string nom)
{
    bool find=0;
    for(int i=0;i<_panier.size(); i++ )
    {
        if(_panier[i].getTitre()==nom){
            find=1;
            _panier.erase(_panier.begin()+i);
            _nbproduits.erase(_nbproduits.begin()+i);
        }

    }
    if(find==0)
        std::cout<<"Le produit n'est pas dans le panier."<<std::endl;
}

std::string Client::AfficherPanier()
{
    std::stringstream flux ;
    std::string fin;
    for(int i=0;i<_panier.size(); i++ )
    {
        flux << "\n" << _panier[i].getTitre() << " Quantite : "<< _nbproduits[i]<<std::endl;
    }
    fin=flux.str();
    return fin;
}

std::ostream& operator<<(std::ostream& flux, Client &client)
{
    flux <<"Id du client: " << client.getId() << " Prenom : " << client.getPrenom() << " Nom : " << client.getNom() << " Panier : "<<client.AfficherPanier()<<std::endl;
}
    

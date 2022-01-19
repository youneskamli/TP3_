#include "Magasin.h"
Magasin::Magasin()
{
}

void Magasin::addProduit(Produit produit)
{
    _produits.push_back(produit);
}

void Magasin::afficheProduits()
{
    for(int i=0;i<_produits.size();i++)
    {
        std::cout<<"Produit numero "<<i<<" : "<<_produits[i].getTitre()<<"; ";
    }
}

void Magasin::ChercheProduit(std::string produit_cherche)
{
    std::cout<<"Produit cherche : "<<produit_cherche<<std::endl;
    for(int i=0;i<_produits.size();i++)
    {
        if (_produits[i].getTitre()==produit_cherche)
            std::cout<<_produits[i]<<std::endl;
    }

}

void Magasin::updateQuant(std::string nom,int quantite)
{
    std::cout<<"Produit : "<<nom<<std::endl;
    for(int i=0;i<_produits.size();i++)
    {
        if (_produits[i].getTitre()==nom){
            std::cout<<"Quantite avant modif : "<<_produits[i].getQuantite()<<" ; Quantite apres modif : "<<quantite<<std::endl;
            _produits[i].setQuantite(quantite);
        
        }
    }  
}

void Magasin::AddClient(Client client)
{
    _clients.push_back(client);

}
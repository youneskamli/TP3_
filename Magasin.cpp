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
        std::cout<<"Produit numero "<<i+1<<" : "<<_produits[i].getTitre()<<"; ";
    }
}

void Magasin::ChercheProduit(std::string produit_cherche)
{
    std::cout<<"Produit cherche : "<<produit_cherche<<std::endl;
    for(int i=0;i<_produits.size();i++)
    {
        if (_produits[i].getTitre()==produit_cherche ||std::to_string(_produits[i].getId())==produit_cherche)
            std::cout<<_produits[i]<<std::endl;
    }

}

int Magasin::getNbInStore(std::string produit_cherche)
{
    for(int i=0;i<_produits.size();i++)
    {
        if (_produits[i].getTitre()==produit_cherche ||std::to_string(_produits[i].getId())==produit_cherche)
            return _produits[i].getQuantite();
    }   
    std::cout<<"Erreur, ce produit n'est pas dans le magasin"<<std::endl;
    return 0;
}


void Magasin::updateQuant(std::string nom,int quantite)
{
    //std::cout<<"Produit : "<<nom<<std::endl;
    for(int i=0;i<_produits.size();i++)
    {
        if (_produits[i].getTitre()==nom){
            //std::cout<<"Quantite avant modif : "<<_produits[i].getQuantite()<<" ; Quantite apres modif : "<<quantite<<std::endl;
            _produits[i].setQuantite(quantite);
        
        }
    }  
}

std::vector<Client> Magasin::getClients(){return _clients;}



void Magasin::AddClient(Client client)
{
    _clients.push_back(client);

}

void Magasin::afficheClients()
{

    for(int i=0;i<_clients.size();i++)
    {
        std::cout<<"Client numero "<<i+1<<" : "<<_clients[i].getNom()<<" "<<_clients[i].getPrenom()<<" ; ";

    }
    std::cout<<"\n";
}

void Magasin::ChercheClient(std::string client_cherche)
{
    bool exist=0;
    std::cout<<"Client cherche : "<<client_cherche<<std::endl;
    for(int i=0;i<_clients.size();i++)
    {
        if (std::to_string(_clients[i].getId())==client_cherche || _clients[i].getNom()==client_cherche)
        {  
            std::cout<<_clients[i]<<std::endl;
            exist=1;
        }
    }
    if (exist==0)
        std::cout<<"Le client cherché n'est pas dans le magasin"<<std::endl;

}

void Magasin::addToClientCart(Client &client,Produit &produit)
{
    bool existClient=0;
    bool existProduit=0;
    for(int i=0;i<_clients.size();i++)
    {
        if(_clients[i].getId()==client.getId())
            {
                existClient=1;
                for(int j=0;j<_produits.size();j++)
                {
                    if (_produits[j].getId()==produit.getId())
                    {
                        existProduit=1;
                        _clients[i].addToPanier(produit);
                        _clients[i].updateInCart(produit.getTitre(),client.getNbInPanier()[j]);
                    }    
                }
            }
    }
    if (existClient==0)
        std::cout<<"Le client n'est pas dans le magasin"<<std::endl;
    if (existProduit==0)
        std::cout<<"Le produit n'est pas dans le magasin"<<std::endl;

}

void Magasin::DelFromClientCart(Client &client, Produit &produit)
{
    bool existClient=0;
    bool existProduit=0;
    for(int i=0;i<_clients.size();i++)
    {
        if(_clients[i].getId()==client.getId())
            {
                existClient=1;
                for(int j=0;j<_produits.size();j++)
                {
                    if (_produits[j].getId()==produit.getId())
                    {
                        existProduit=1;
                        _clients[i].DeleteFromPanier(produit.getTitre());
                        _clients[i].updateInCart(produit.getTitre(),client.getNbInPanier()[j]);
                    }    
                }
            }
    }
    if (existClient==0)
        std::cout<<"Le client n'est pas dans le magasin"<<std::endl;
    if (existProduit==0)
        std::cout<<"Le produit n'est pas dans le magasin"<<std::endl;

}
void Magasin::updateQuantFromClientCart(Client &client, Produit &produit, int quantite)
{
    bool existClient=0;
    bool existProduit=0;
    for(int i=0;i<_clients.size();i++)
    {
        if(_clients[i].getId()==client.getId())
            {
                existClient=1;
                for(int j=0;j<_produits.size();j++)
                {
                    if (_produits[j].getId()==produit.getId())
                    {
                        existProduit=1;
                        client.updateInCart(produit.getTitre(),quantite);
                        _clients[i].updateInCart(produit.getTitre(),quantite);
                    }    
                }
            }
    }
    if (existClient==0)
        std::cout<<"Le client n'est pas dans le magasin"<<std::endl;
    if (existProduit==0)
        std::cout<<"Le produit n'est pas dans le magasin"<<std::endl;
}

void Magasin::AddCommande(Commande commande)
{
    _commande.push_back(commande);
}


void Magasin::ValiderCommande(Commande commande)
{
    if((commande.getPanier()).size()==0)
        std::cout<<"Le panier est vide"<<std::endl;
        return;
    for(int i=0;i<commande.getPanier().size();i++)
    {
        if(commande.getQuantitePanier()[i] > getNbInStore(commande.getPanier()[i].getTitre()))
            std::cout<<"Quantite voulue indisponible, veuillez baisser le nombre de produits voulus"<<std::endl;
            return;
        updateQuant(commande.getPanier()[i].getTitre(), getNbInStore(commande.getPanier()[i].getTitre())-commande.getQuantitePanier()[i]);
    }
    commande.getClient().DeletePanier();
    commande.setStatut(true);//Faire avec la fonction de la question d'après
}

void Magasin::afficheCommandes()
{
    for(int i=0;i<_commande.size();i++)
    {
        std::cout<<_commande[i]<<std::endl;

    }
    std::cout<<"\n";
}
#include <iostream>
#include "Magasin.h"
int main() {
	Magasin EasyStore;
    Produit PS4("PS4", "Console de jeu de marque Sony", 10, 249.99);
    EasyStore.addProduit(PS4);
    Client c1("Omar","Amana");
    EasyStore.AddClient(c1);
    Client c2("Naofel","Le Thies");
    EasyStore.AddClient(c2);
    c1.addToPanier(PS4);
    c1.updateInCart("PS4",2);
    //std::cout<<PS4<<std::endl;
    c2.addToPanier(PS4);
    //EasyStore.ChercheProduit("PS4");
    EasyStore.addToClientCart(c1,PS4);
    EasyStore.ChercheClient("Amana");
    EasyStore.updateQuantFromClientCart(c1,PS4,1);
    EasyStore.ChercheClient("Amana");
    Commande commande1(c1);
    EasyStore.ValiderCommande(commande1);
    EasyStore.AddCommande(commande1);
    std::cout<<commande1<<std::endl;
    EasyStore.afficheCommandes();
}
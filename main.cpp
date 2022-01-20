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
    EasyStore.updateQuant("PS4",8);
    //std::cout<<PS4<<std::endl;
    c2.addToPanier(PS4);
    EasyStore.updateQuant("PS4",7);
    //EasyStore.ChercheProduit("PS4");
    EasyStore.afficheClients();
}
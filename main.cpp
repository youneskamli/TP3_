#include <iostream>
#include "Magasin.h"
int main() {
	Magasin EasyStore;
    Produit PS4("PS4", "Console de jeu de marque Sony", 10, 249.99);
    //std::cout<<PS4<<std::endl;
    Client c1("Omar","Amana",0001);
    c1.addToPanier(PS4);
    
}
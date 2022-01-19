#include <iostream>
#include "Magasin.h"
int main() {
	Magasin EasyStore;
    Produit PS4("PS4", "Console de jeu de marque Sony", 10, 249.99);
    EasyStore.addProduit(PS4);
<<<<<<< HEAD
<<<<<<< Updated upstream
    EasyStore.updateQuantity("PS4",8);
=======
=======
>>>>>>> test
    Client c1("Omar","Amana",0001);
    c1.addToPanier(PS4);
    c1.updateInCart("PS4",2);
    EasyStore.updateQuant("PS4",8);
<<<<<<< HEAD
    /*std::cout<<PS4<<std::endl;
    EasyStore.ChercheProduit("PS4");
    std::cout<<c1<<std::endl;*/
    EasyStore.AddClient(c1);



>>>>>>> Stashed changes
=======
    //std::cout<<PS4<<std::endl;
    EasyStore.ChercheProduit("PS4");
    std::cout<<c1<<std::endl;
>>>>>>> test
}
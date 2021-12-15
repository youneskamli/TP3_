#include <string>
#include "Magasin.h"
#include "Produit.h"

int main() {
	Magasin EasyStore;
    Produit PS4("PS4", "Console de jeu de marque Sony", 10, 249.99);
    EasyStore.addProduit(PS4);
    EasyStore.updateQuantity("PS4",8);
}
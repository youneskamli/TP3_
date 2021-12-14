#include <string>
#include "Magasin.h"
#include "Produit.h"
int main() {
	Magasin EasyStore();
    Produit PS4("PS4", "Console de jeu de marque Sony", 10, 299.99);
    std::cout << PS4 << std::endl;
}
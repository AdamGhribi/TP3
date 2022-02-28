/*
Fichier: ObjetMagique.h
Auteur(s): 
Date de creation: 
Date de modification: 
Description: La classe ObjetMagique correspond aux differents objets utilisable
			par le dresseur sur ses creatures
*/
#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>
#include <iostream>

using namespace std;

class ObjetMagique {
public:

	ObjetMagique(const string &nom ="", int bonus = 0);
	std::string obtenirNom() const;
	int obtenirBonus() const;

	void modifierNom(const string& nom);
	void modifierBonus(int bonus);

	void afficher() const;
	friend ostream& operator<<(ostream& os, const ObjetMagique& objet);

private:
	string nom_;
	int bonus_;
};

#endif

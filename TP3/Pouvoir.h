/*
Fichier: Pouvoir.h
Auteur(s): 
Date de creation: 
Date de modification: 
Description: La classe Pouvoir correspond aux differents attaques 
*/
#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <iostream>

using namespace std;

class Pouvoir {
public:
	Pouvoir(const string& nom = "", unsigned int nombreDeDegat = 0, unsigned int energieNecessaire = 0);
	
	unsigned int obtenirNombreDeDegat() const;
	unsigned int obtenirEnergieNecessaire() const;
	string obtenirNom() const;

	void modifierNombreDeDegat(unsigned int nombreDegat);
	void modifierEnergieNecessarie(unsigned int energieNecessaire);
	void modifierNom(const string& nom);
    void afficher() const;
	
	bool operator==(const Pouvoir& pouvoir) const;

	friend ostream& operator<<(ostream& os, const Pouvoir& pouvoir);
	
private:
	string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;

};

#endif
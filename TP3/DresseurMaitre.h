/*
Fichier: Dresseur.h
Auteur(s): 
Date de creation: 
Date de modification: 
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEURMAITRE_H
#define DRESSEURMAITRE_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "Dresseur.h"
#include "Experience.h"
#include "Creature.h"

using namespace std;

//const inline string ROUGE = "\033[1;91m", MAUVE = "\033[1;95m", BLEU = "\033[1;96m", VERT = "\u001b[32;1m", FIN = "\033[0m";
// cette classe répresente un dresseur expérimenté
class DresseurMaitre:  public Dresseur, public Experience
{
public:
	DresseurMaitre(const string& nom ="", const string & nomObjetMagique ="", int bonus = 0, int anneeExperience = 0);
	 ~DresseurMaitre() = default;
    
	void utiliserObjetMagique(shared_ptr<Creature> creature) override ;
    
    friend std::ostream& operator<<(std::ostream& os, const DresseurMaitre& dresseur);
    
    // todo: ajouter le mot clef override une fois que la classe
    // Experience contiendra la methode
	void afficher () const override;
    
    // todo: ajouter le mot clef override une fois que la classe
    // Experience contiendra la methode
	unsigned int obtenirExperience() const override;
    
    //
    string obtenirNomExperience()  const override;

private:
     // un dresseur  a des années d'expérience
	 unsigned int  anneeExperience_;

};
#endif

/*
Fichier: Dresseur.h
Auteur(s): 
Date de creation: 
Date de modification: 
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEURAPPRENTI_H
#define DRESSEURAPPRENTI_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "Dresseur.h"
#include "Creature.h"

using namespace std;

//const inline string ROUGE = "\033[1;91m", MAUVE = "\033[1;95m", BLEU = "\033[1;96m", VERT = "\u001b[32;1m", FIN = "\033[0m";

class DresseurApprenti:  public Dresseur
{
public:

	DresseurApprenti(const string& nom ="", const string & nomObjetMagique ="", int bonus = 0, float tauxEchec = 0 );
    ~DresseurApprenti() =default;	
	// méthode de la classe DresseurApprenti
    void utiliserObjetMagique(shared_ptr<Creature> creature) override;
    float obtenirTauxEchec() const;
	void modifierTauxEchec( float tx);
	// fonction globale pour  DresseurApprenti
    friend std::ostream& operator<<(std::ostream& os, const DresseurApprenti& dresseur);
private:
      // le dresseur apprenti a un taux d'echex lors de l'utilisation son 
	  // objet magique
	  float  tauxEchec_;
};

#endif
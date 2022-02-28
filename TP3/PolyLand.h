/*
Fichier: PolyLand.h
Auteur(s): 
Date de creation: 
Date de modification: 
Description: Polyland represente le pays que l'on va explorer, il va contenir les differents elements de jeu
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
#include <vector>
#include "Dresseur.h"
#include "Experience.h"
#include "DresseurApprenti.h"
#include "DresseurMaitre.h"
#include "Creature.h"
#include "CreatureMagique.h"
#include "CreatureExperience.h"

using namespace std;

class PolyLand
{
public:
	PolyLand();
	//todo
	bool ajouterDresseur(const shared_ptr<Dresseur>  & dresseur);
	//todo
	bool ajouterCreature(const shared_ptr<Creature> & creature);
     // todo
	bool retirerDresseur(const string& nom);
	// todo
	bool retirerCreature(const string& nom);

	shared_ptr<Creature> choisirCreatureAleatoire();

	shared_ptr<Dresseur> choisirDresseur(string nom);
	shared_ptr<Creature> choisirCreature(string nom);

	vector<shared_ptr<Dresseur>> obtenirDresseurs();
	vector<shared_ptr<Creature>> obtenirCreatures();

	bool attraperCreature(const shared_ptr<Dresseur> &dresseur, const shared_ptr <Creature> & creature);
	bool relacherCreature(shared_ptr<Dresseur> & dresseur, const  shared_ptr<Creature> & creature);
	
	void infoDresseur(const string& nom) const;
    
	 //todo
	void afficherExperience() const;
    
     // todo
	Experience * trouverPlusGrandeExperience ();

	PolyLand& operator+=(const shared_ptr<Dresseur> & dresseur);
	PolyLand& operator-=(const shared_ptr<Dresseur> & dresseur);
	PolyLand& operator+=(const shared_ptr<Creature> & creature);
	PolyLand& operator-=(const shared_ptr<Creature> & creature);
    
    vector<Experience*> obtenirExperience() const;
    
	friend ostream& operator<<(ostream& os, const PolyLand& poly);

private:
    vector<shared_ptr<Dresseur>> dresseurs_;
	vector<shared_ptr<Creature>> creatures_;
	// vector des personnages de  la classe  Interface
	vector<Experience *> personnagesExperimentes_;
	// todo
	void retirerExperience(const string& nom);

};
#endif

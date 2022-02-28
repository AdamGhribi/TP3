/*
Fichier: CreatureMagique.h
Auteur(s): 
Date de creation:
Description: 
*/
#ifndef CREATURE_MAGIQUE_H
#define CREATURE_MAGIQUE_H

//#include "AttaqueMagiqueConfusion.h"
//#include "AttaqueMagiquePoison.h"
#include "Creature.h"
class CreatureMagique : public Creature
{
public:
	CreatureMagique(const string& nom ="");
	CreatureMagique(const string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir, 
		unsigned int potionMagique);
	CreatureMagique(const Creature& creature, unsigned int potionMagique);
    CreatureMagique(const CreatureMagique& creature);

    ~CreatureMagique() = default; 

	CreatureMagique& operator= (const CreatureMagique &  creature);

	void attaquer(Creature& creature)override;
    
    void afficher() const;

    friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature); //  MODIFIER (si necessaire...)
	
	unsigned int obtenirPotionMagique() const;
	void modifierPotionMagique(unsigned int bonus);

private:
   // classe a une potion magique
    unsigned int potionMagique_;
};

#endif

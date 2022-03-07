/*
Fichier: CreatureExperience.h
Auteur(s): 
Date de creation:
Description: 
*/
#ifndef CREATURE_EXPERIENCE_H
#define CREATURE_EXPERIENCE_H

//#include "AttaqueExperienceConfusion.h"
//#include "AttaqueExperiencePoison.h"
#include "Creature.h"
#include "Experience.h"

class CreatureExperience : public Creature, public Experience
{
public:
	CreatureExperience(const string& nom ="");
	CreatureExperience(const string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir, 
		unsigned int forceExp);
    
	CreatureExperience(const Creature& creature, unsigned int forceExp);
    CreatureExperience(const CreatureExperience & creature);
    CreatureExperience &operator= (const CreatureExperience &  creature) ;
    
    ~CreatureExperience() = default;
    
    void attaquer(Creature& creature) override;
    
    // todo: ajouter override une fois que Experience sera cree
	void afficher() const override;
    
    // todo: ajouter override une fois que Experience sera cree
	unsigned int obtenirExperience () const override;

    //
    string obtenirNomExperience()  const override;

    // todo
    friend std::ostream& operator<<(std::ostream& os, const CreatureExperience& creature);
	
	unsigned int obtenirForceExperience() const;
	void modifierForceExperience(unsigned int bonus);

private:
    // les creatureExperience ont une force Experience
    unsigned int forceExperience_;

};

#endif

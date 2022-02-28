#include "CreatureExperience.h"

// todo:
// Faire l'initialisation de tout les attributs
CreatureExperience::CreatureExperience(const string& nom) : Creature (nom){}

// todo:
// Faire l'initialisation de tout les attributs
CreatureExperience::CreatureExperience(const string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir, 
		unsigned int forceExp) : Creature(nom, attaque, defense, pointDeVie, energie, pouvoir), forceExperience_(forceExp) {}

// todo:
// Faire l'initialisation de tout les attributs
CreatureExperience::CreatureExperience(const Creature& creature, unsigned int forceExp): Creature(creature), forceExperience_(forceExp){}

// todo:
// Faire l'initialisation de tout les attributs
CreatureExperience:: CreatureExperience(const CreatureExperience & creature): Creature(creature){}

// todo
// Faire la surcharge de l'opérateur = de maniere a ce que
// les attributs de la creatureExperience puisse etre copie
// dans l'objet courant.
CreatureExperience& CreatureExperience::operator= (const CreatureExperience &  creature)
{
	   return *this;
}

// todo
// energie de creatureExperience est additionné à la forceExperience
// l'attaque rate 1 fois sur 10
void CreatureExperience::attaquer(Creature& creature)
{
    // todo
    // 1. Modifier l'energie de l'objet courant pour qu'elle
    // devienne: (l'energie courante + la force Experience)
    
    
    // todo
    // 2. La méthode attaquer de la classe de base avait une
    // chance sur 6 de ne pas fonctionner. Dans cette classe
    // la creature a de l'experience. Ses attaques ne
    // fonctionnent pas uniquement 1 fois sur 10.
    // Son attaque ne fonctionnera pas si tentative est 5.
    
    // indice 1: Il s'agit d'une nouvelle implementation de la
    // methode attaquer. Par contre, elle est extremement
    // similaire a celle de la classe de base a quelque details
    // pres. Reutilisez le code de la methode attaquer de la
    // classe de base.
    
    // indice 2: Fiez-vous au test sur les attaques
    
    
}
// todo
// Se fier à l'affichage des tests->
// devrait dire que la creature {nom de la creature}
// est une creature d'experience et devrait afficher
// sa force experience.
void CreatureExperience::afficher() const
{

}

// todo
// Se fier à l'affichage des tests->
// 1. devrait utiliser la méthode afficher de l'objet courant
// 2. devrait faire appel à la surcharge de l'operateur <<
// de la classe parent.
std::ostream& operator<<(std::ostream & os, const CreatureExperience& creature)
{
	return os;
}

// todo
// doit retourner l'attribut forceExperience_ de l'objet courant
unsigned int CreatureExperience::obtenirExperience () const
{
    return 0;
}

unsigned int CreatureExperience::obtenirForceExperience() const
{
	return forceExperience_;
}

void CreatureExperience::modifierForceExperience(unsigned int forceExperience)
{
	forceExperience_ = forceExperience;
}

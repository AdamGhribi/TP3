#include "CreatureMagique.h"

// todo:
// Faire l'initialisation de tout les attributs  potionMagique = 0
CreatureMagique::CreatureMagique(const string& nom) : Creature(nom), potionMagique_(0)
{}

// todo:
// Faire l'initialisation de tout les attributs
CreatureMagique::CreatureMagique(const string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir, 
		unsigned int potionMagique): Creature(nom, attaque, defense, pointDeVie, energie, pouvoir), 
        potionMagique_(potionMagique){}

// todo:
// Faire l'initialisation de tout les attributs
CreatureMagique::CreatureMagique(const Creature& creature, unsigned int potionMagique): Creature(creature), 
    potionMagique_(potionMagique){}

// todo:
// Faire l'initialisation de tout les attributs
CreatureMagique::CreatureMagique(const CreatureMagique& creature): Creature(creature){}

// todo
// Faire la surcharge de l'opérateur = de maniere a ce que
// les attributs de la creatureExperience puisse etre copie
// dans l'objet courant.
CreatureMagique& CreatureMagique::operator= (const CreatureMagique&  creature) {

	   return * this;
}


// todo
//  la potion magique est additionnée aus PointDeVie de Creature
//  dans le cas d'un créature magique  l'attaque réussie une fois sur 4			  
void CreatureMagique::attaquer(Creature & creature)
{
    // todo
    // 1. L'objet courant (la creature magique) utilise
    // sa potion magique. Sa potion magique lui redonne
    // des points de vie. Attention, vérifiez avant
    // d'ajouter des points de vie à la créature que la
    // somme que vous ajoutez ne fait pas dépasser son
    // point de vie total.
    
    
    
    // todo
    // 2. La méthode attaquer de la classe de base avait une
    // chance sur 6 de ne pas fonctionner. Dans cette classe
    // la creature est magique, ce qui la rend mal habile.
    // Ses attaques ne fonctionnent pas uniquement 1 fois sur 4.
    // Son attaque ne fonctionnera pas si tentative est de 2.
    
    // indice 1: Il s'agit d'une nouvelle implementation de la
    // methode attaquer. Par contre, elle est extremement
    // similaire a celle de la classe de base a quelque details
    // pres. Reutilisez le code de la methode attaquer de la
    // classe de base.
    
    // indice 2: Fiez-vous au test sur les attaques
    

}

// todo: (arrivez au même affichage que ceux des tests)
// 1. affiche le nom de la creature et mentionne que c'est une
// creature magique
// 2. affiche la potion magique de la creature
void CreatureMagique::afficher() const
{

}

// todo
// Se fier à l'affichage des tests->
// 1. devrait utiliser la méthode afficher de l'objet courant
// 2. devrait faire appel à la surcharge de l'operateur <<
// de la classe parent.
std::ostream& operator<<(std::ostream & os, const CreatureMagique& creature)
{
	return os;
}


unsigned int CreatureMagique::obtenirPotionMagique() const
{
	return potionMagique_;
}

void CreatureMagique::modifierPotionMagique(unsigned int potionMagique)
{
	potionMagique_ = potionMagique;
}

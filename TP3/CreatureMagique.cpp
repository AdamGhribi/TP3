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
CreatureMagique::CreatureMagique(const CreatureMagique& creature): Creature(creature), potionMagique_(0) {}

// todo
// Faire la surcharge de l'opérateur = de maniere a ce que
// les attributs de la creatureExperience puisse etre copie
// dans l'objet courant.
CreatureMagique& CreatureMagique::operator= (const CreatureMagique&  creature) {
    if (this != &creature) {
        nom_ = creature.nom_;
        attaque_ = creature.attaque_;
        defense_ = creature.defense_;
        pointDeVie_ = creature.pointDeVie_;
        pointDeVieTotal_ = creature.pointDeVieTotal_;
        energie_ = creature.energie_;
        energieTotal_ = creature.energieTotal_;
        experience_ = creature.experience_;
        experienceNecessaire_ = creature.experienceNecessaire_;
        niveau_ = creature.niveau_;
        pouvoir_ = make_unique<Pouvoir>(*creature.pouvoir_);
        potionMagique_ = creature.potionMagique_;
    }
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
    if ((creature.obtenirPointDeVie() + potionMagique_) > creature.obtenirPointDeVieTotal()) 
        creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
    else{
        creature.modifierPointDeVie(creature.obtenirPointDeVie() + potionMagique_);
    }
    
    
    // todo
    // 2. La méthode attaquer de la classe de base avait une
    // chance sur 6 de ne pas fonctionner. Dans cette classe
    // la creature est magique, ce qui la rend mal habile.
    // Ses attaques ne fonctionnent pas uniquement 1 fois sur 4.
    // Son attaque ne fonctionnera pas si tentative est de 2.
    if (energie_ >= pouvoir_->obtenirEnergieNecessaire()) {
        if (creature.obtenirPointDeVie() >= 0) {

            int degat = 0;

            int degatPotentiel = static_cast<int>(pouvoir_->obtenirNombreDeDegat()) * (static_cast<int>(attaque_) / 2);

            // Determiner la defense restante de la creature
            int defenseRestante = static_cast<int>(creature.obtenirDefense()) - degatPotentiel;

            if (defenseRestante < 0)
            {
                degat = -defenseRestante;
                creature.modifierDefense(0);
            }
            else {
                creature.modifierDefense(defenseRestante);
            }

            // L'attaque rate une fois sur 4
            int tentative = rand() % 4;

            if (tentative != 2) {

                std::cout << nom_ << " lance " << pouvoir_->obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;

                if (degat > creature.obtenirPointDeVie()) {
                    creature.modifierPointDeVie(0);
                    int xp = experienceGagnee(creature);

                    cout << nom_ << " a gagne " << xp << " XP" << endl << endl;
                }
                else {
                    creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
                }

                cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
                energie_ -= pouvoir_->obtenirEnergieNecessaire();
            }
            else {
                std::cout << "Attaque " << pouvoir_->obtenirNom() << " a echouee" << endl;
            }
        }
        else {
            std::cout << "Vous deja avez vaincu " << creature.obtenirNom() << endl;
        }
    }
    else
    {
        cout << this->obtenirNom() << " n'as plus assez d'énergie pour se battre" << endl;
    }
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
    cout << "Creature magique: " << endl;
    cout << obtenirNom() << " a comme potion magique: " << obtenirPotionMagique() << endl;
}

// todo
// Se fier à l'affichage des tests->
// 1. devrait utiliser la méthode afficher de l'objet courant
// 2. devrait faire appel à la surcharge de l'operateur <<
// de la classe parent.
std::ostream& operator<<(std::ostream & os, const CreatureMagique& creature)
{
    os << creature;
    creature.afficher();
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

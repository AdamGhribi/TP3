/*
Fichier: DresseurMaitre.cpp
Auteur(s): 
Date de creation: 
Date de modification: 
*/
#include "DresseurMaitre.h"

// todo:
// Faire l'initialisation de tout les attributs
DresseurMaitre::DresseurMaitre(const string& nom, const string& nomObjetMagique,
                int bonus, int anneeExperience ) : Dresseur(nom,nomObjetMagique, bonus), anneeExperience_(anneeExperience){}


//todo
// méthode de la classe Interface
unsigned int DresseurMaitre::obtenirExperience() const  { return anneeExperience_;}

// méthode de la classe dérivée
// on ajoute les années d'expérience au bonus de l'objet magique
void DresseurMaitre::utiliserObjetMagique(shared_ptr<Creature> creature) {
    
    
    // todo:
    // 1. Permettre l'affichage decrivant comme quoi l'objet courant
    // (DresseurApprenti) est en train d'utiliser son objet magique.
    // (voir affichage)
    std::cout << this->obtenirNom() << " utilise son objet magique de dresseur" << std::endl;

    // superBonus
	int superBonus = this->obtenirObjetMagique().obtenirBonus() *anneeExperience_;
    
    
    // 2. Normalement, un bonus était ajouter à deux moments:
    
    // creature->modifierPointDeVie(creature->obtenirPointDeVie() +
    // objetMagique_.obtenirBonus());
    
    // On veut desormais que ce soit le superBonus qui soit ajoute
    // a la place de objetMagique_.obtenirBonus()
    
    // indice 1: Il s'agit d'une nouvelle implementation de la
    // methode utiliserObjetMagique. Par contre, elle est extremement
    // similaire a celle de la classe de base a quelque details
    // pres. Reutilisez le code de la methode utiliserObjetMagique de la
    // classe de base.
    
    // indice 2: Fiez-vous au test sur les objets magiques
    //WYM??
    if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {// bonusApprenti ou objetMagique?
        creature->modifierPointDeVie(creature->obtenirPointDeVie() + superBonus);
    }
    else {
        creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
    }
    if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus())
    {
        creature->modifierEnergie(creature->obtenirEnergie() + superBonus);
    }
    else {
        creature->modifierEnergie(creature->obtenirEnergieTotale());
    }
    
}

// todo
// 1. Indique que l'objet courant ( le DresseurMaitre )
// est un maitre dresseur
// 2. Fait l'affichage des annee d'experience qu'a le
// dresseur ( fiez-vous a l'affichage )
void DresseurMaitre::afficher() const
{
    std::cout << this->obtenirNom() << " est un Maitre Dresseur" << endl 
        << "et a comme annee d'experience : " << this->obtenirExperience()<< endl;
    
}

// todo
// 1. L'objet courant doit faire appel à sa methode afficher()
// 2. L'objet courant doit aussi faire l'affichage de ses
// attributs. ( Utilisez la surcharge de la classe parent )
ostream& operator<<(ostream& os, const DresseurMaitre& dresseur)
{
    dresseur.afficher();

    os << static_cast<Dresseur>(dresseur);

    //****
    
    return os;
}



 /*
Fichier: Dresseur.cpp
Auteur(s): 
Date de creation: 
Date de modification:  
Description:
*/
#include "PolyLand.h"

PolyLand::PolyLand() {}


bool PolyLand::ajouterDresseur(const shared_ptr<Dresseur> & dresseur) {
    
	for (unsigned int i = 0; i < dresseurs_.size(); i++) {
		if (dresseurs_[i]->obtenirNom() == dresseur->obtenirNom())
			return false;
	}
    
	dresseurs_.push_back(dresseur);
    
	if (dynamic_cast<Experience*>(dresseur.get())) {
		personnagesExperimentes_.push_back(dynamic_cast<DresseurMaitre*>(dresseur.get()));
	}
    // todo
    // Verifier si l'objet dresseur passe en parametre
    // est de type Experience. Si tel est le cas, ajouter
    // le au vecteur personnagesExperimentes_

    
    return true;
}


bool PolyLand::ajouterCreature(const shared_ptr<Creature>& creature) {
	for (unsigned int i = 0; i < creatures_.size(); i++) {
		if (creatures_[i]->obtenirNom() == creature->obtenirNom())
			return false;
	}
	creatures_.push_back(creature);

	if (dynamic_cast<Experience*>(creature.get())) {
		personnagesExperimentes_.push_back(dynamic_cast<CreatureExperience*>(creature.get()));
	}
    
    // todo
    // Verifier si l'objet creature passe en parametre
    // est de type Experience. Si tel est le cas, ajouter
    // le au vecteur personnagesExperimentes_
		   
	return true;
}

// todo:  retirer  dresseur dans le vector desseurs_ et le vector <Experience>
bool PolyLand::retirerDresseur(const string& nom) {

	
	for (unsigned int i = 0; i < dresseurs_.size(); i++) {
		if (dresseurs_[i]->obtenirNom() == nom) {

			if (dynamic_cast<Experience*>(dresseurs_[i].get()))
				retirerExperience(nom);

			// todo:
            // Verifier si l'objet ayant le nom passe en parametre
            // est bel et bien un objet de type experience
            // Si l'objet est de type experience, utiliser la
            // methode retirerExperience() de la classe courante.

            
			dresseurs_[i] = dresseurs_.back();
		    dresseurs_.pop_back();
			return true;
		}
	}
	return false;
}

// todo
// Retirer un personnage experience dans le vector <Experience>
void PolyLand::retirerExperience( const string& nom )
{
	for (unsigned int i = 0; i < personnagesExperimentes_.size(); i++) {
		if (personnagesExperimentes_[i]->obtenirNomExperience() == nom) {
			personnagesExperimentes_[i] = personnagesExperimentes_.back();
			personnagesExperimentes_.pop_back();
		}
	}
    // Faire l'iteration de tous les personnagesExperimentes
    // et verifier que le pointeur passe en parametre correspond
    // bien a l'un des pointeurs intelligent se retrouvant dans
    // le vecteur personnnagesExperimentes. Une fois trouver,
    // vous devez retirer le pointeur du vecteur.
	   	
}

// todo:
// Retirer dresseur dans le vector creatures_ et le vector <Experience>
bool PolyLand::retirerCreature(const string& nom) {
	for (unsigned int i = 0; i < creatures_.size(); i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			if (dynamic_cast<Experience*>(creatures_[i].get()))
				retirerExperience(nom);
            
            // todo:
            // Verifier si l'objet ayant le nom passe en parametre
            // est bel et bien un objet de type experience
            // Si l'objet est de type experience, utiliser la
            // methode retirerExperience() de la classe courante.

            
			creatures_[i] = creatures_.back(); 
			creatures_.pop_back();
			return true;
		}
	}
	return false;
}


shared_ptr<Creature> PolyLand::choisirCreatureAleatoire() {
	if (creatures_.size() > 0) {
		unsigned int indice = rand() % creatures_.size();
		return creatures_[indice];
	}
	else {
		return nullptr;
	}
}

shared_ptr<Dresseur> PolyLand::choisirDresseur(string nom) {
	for (unsigned int i = 0; i < dresseurs_.size(); i++) {
		if (dresseurs_[i]->obtenirNom() == nom) {
			return dresseurs_[i];
		}
	}
	return nullptr;
}

shared_ptr<Creature> PolyLand::choisirCreature(string nom) {
	for (unsigned int i = 0; i < creatures_.size(); i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			return creatures_[i];
		}
	}
	return nullptr;
}

vector<shared_ptr<Dresseur>> PolyLand::obtenirDresseurs() {
	return dresseurs_;
}

vector<shared_ptr<Creature>> PolyLand::obtenirCreatures() {
	return creatures_;
}

bool PolyLand::attraperCreature(const shared_ptr<Dresseur>& dresseur,const shared_ptr<Creature> & creature) {
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(shared_ptr<Dresseur> & dresseur, const shared_ptr<Creature>& creature) {
	return dresseur->supprimerCreature(creature->obtenirNom());
}

void PolyLand::infoDresseur(const string& nom) const {
	shared_ptr<Dresseur>  dresseur = nullptr;
	for (unsigned int i = 0; i < dresseurs_.size(); i++) {
		if (dresseurs_[i]->obtenirNom() == nom) {
			dresseur = dresseurs_[i];
			break;
		}
	}
	if (dresseur != nullptr) {
		std::cout << "Informations sur le dresseur: " << std::endl;
		cout << dresseur;
		for (unsigned int i = 0; i < dresseur->obtenirNombreCreatures(); i++) {
			cout << "- " << i + 1 << " - ";
			cout << dresseur->obtenirCreatures()[i]<<endl;;
		}
	}
	else {
		std::cout << "Dresseur introuvable!" << std::endl;
	}
}


PolyLand& PolyLand::operator+= (const shared_ptr<Dresseur> &dresseur) {
	ajouterDresseur(dresseur);
	return *this;
}

PolyLand& PolyLand::operator-=(const shared_ptr<Dresseur> & dresseur) {
	retirerDresseur(dresseur->obtenirNom());
	return *this;
}


PolyLand& PolyLand::operator+= (const shared_ptr<Creature>  &creature) {
	ajouterCreature(creature);
	return *this;
}

PolyLand& PolyLand::operator-=(const shared_ptr<Creature>  &creature) {
	retirerCreature(creature->obtenirNom());
	return *this;
}

ostream& operator<<(ostream& os, const PolyLand& poly) {
	os << "Dresseurs"<< endl;
	for (unsigned int i = 0; i < poly.dresseurs_.size(); i++) {
		os << endl << *(poly.dresseurs_[i]);
	}
    std::cout << std::endl;
	os << "Creatures"<< endl;
	for (unsigned int i = 0; i < poly.creatures_.size(); i++) {
		os << endl << *(poly.creatures_[i]);
	}
	return os;
}

// todo: Faire l'affichage des personnages experimentes
// a partir du vector personnagesExperimentes_ (voir l'affichage)
void PolyLand::afficherExperience() const
{
	cout << endl << "Personnages experimentes";
	cout << endl;
	cout << endl;
	
	for (auto& i : personnagesExperimentes_) {
		//cout << i << endl;
		i->afficher();
		cout << endl;
	}
	//*******lequel
}

vector<Experience *> PolyLand::obtenirExperience() const
{
    return personnagesExperimentes_;
}

// todo:
// trouver le personnage le plus experimente
// ( les classes qui heritent d'Experience ont
// des methodes propre a experience)
Experience* PolyLand::trouverPlusGrandeExperience(){
	int nombreMaxAnneeExperience = 0;
	Experience* pointeurMax = nullptr;
	for (const auto& i : personnagesExperimentes_) {
		if (nombreMaxAnneeExperience < i->obtenirExperience()) {
			nombreMaxAnneeExperience = i->obtenirExperience();
			pointeurMax = i;
		}
	}
    return pointeurMax;
	
}

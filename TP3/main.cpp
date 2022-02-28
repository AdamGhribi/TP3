#include <iostream>
#include "Creature.h"
#include "CreatureMagique.h"
#include "CreatureExperience.h"
#include "ObjetMagique.h"
#include "Dresseur.h"
#include "DresseurMaitre.h"
#include "DresseurApprenti.h"
#include "PolyLand.h"
#include "Pouvoir.h"

#include <vector>
#include <map>
#include <string>


int main() {

    std::map<std::string, int[2]> test;



    // Vérification des méthodes des classes de bases
    // Ne compte pas, devrait marcher par défaut | Ponderation: 1pts
    if (true)
    {
        test["TEST0"][0] = 1;
        test["TEST0"][1] = 1;


        std::cout << "==============================================" << std::endl;
        std::cout << "TEST 0: Verification des classes de bases" << std::endl;
        std::cout << "==============================================" << std::endl << std::endl;

        Pouvoir electricite("electricite", 4, 20);
        Creature* e1 = new Creature("Pikachu", 5, 10, 100, 30, electricite);

        std::cout << *e1 << std::endl << std::endl;

        Pouvoir P("feu", 4, 20);
        Creature* e2 = new Creature("Charizard", 5, 10, 100, 30, P);

        std::cout << *e2 << std::endl;
        std::cout << "première attaque" << std::endl;

        // l'attaque doit etre reussite
        e2->attaquer(*e1);

        if (e1->obtenirDefense() != 2 ||
            e1->obtenirPointDeVieTotal() != 100) {
            test["TEST0"][1] = 0;
        }

        std::cout << std::endl;

        if (test["TEST0"][1] > 0) {
            std::cout << "[X] Le test 0 a passe correctement" << std::endl;
        }
        else {
            std::cout << "[ ] Le test 0 n'as pas passe correctement" << std::endl;
        }

    }

    // TEST1: Construction creatures Magiques | Ponderation: 2pts
    if (true)
    {
        test["TEST1"][0] = 2;
        test["TEST1"][1] = 2;

        std::cout << std::endl;
        std::cout << "==============================================" << std::endl;
        std::cout << "TEST 1: Constructeurs Creatures magiques" << std::endl;
        std::cout << "==============================================" << std::endl << std::endl;

        Pouvoir pouvoirFeu("feu", 4, 20);
        Creature* charizard = new Creature("Charizard", 5, 10, 100, 30, pouvoirFeu);

        // Verification du constructeur par parametre de Creature magique
        std::shared_ptr<Creature> impenetrable = std::make_shared<CreatureMagique>("Impenetrable", 5, 10, 5, 30, pouvoirFeu, 20);

        std::shared_ptr<CreatureMagique> creatureMagique1 = std::make_shared<CreatureMagique>("Destructeur", 5, 10, 5, 30, pouvoirFeu, 20);
        std::shared_ptr<CreatureMagique> creatureMagique2 = std::make_shared<CreatureMagique>(*creatureMagique1);
        std::shared_ptr<CreatureMagique> creatureMagique3 = std::make_shared<CreatureMagique>("Cronium");
        std::shared_ptr<CreatureMagique> creatureMagique4 = std::make_shared<CreatureMagique>(*charizard, 4);


        // Verification: Constructeur par parametres
        if (creatureMagique1->obtenirNom() != "Destructeur" ||
            creatureMagique1->obtenirAttaque() != 5 ||
            creatureMagique1->obtenirDefense() != 10 ||
            creatureMagique1->obtenirPointDeVie() != 5 ||
            creatureMagique1->obtenirEnergie() != 30 ||
            creatureMagique1->obtenirPotionMagique() != 20)
        {
            test["TEST1"][1] = 0;
        }

        // Verification: Constructeur par copie
        if (creatureMagique2->obtenirNom() != "Destructeur" ||
            creatureMagique2->obtenirAttaque() != 5 ||
            creatureMagique2->obtenirDefense() != 10 ||
            creatureMagique2->obtenirPointDeVie() != 5 ||
            creatureMagique2->obtenirEnergie() != 30 ||
            creatureMagique2->obtenirPotionMagique() != 20)
        {
            test["TEST1"][1] = 0;
        }

        // Verification: Constructeur avec seulement string
        if (creatureMagique3->obtenirNom() != "Cronium" ||
            creatureMagique3->obtenirAttaque() != 0 ||
            creatureMagique3->obtenirDefense() != 0 ||
            creatureMagique3->obtenirPointDeVie() != 0 ||
            creatureMagique3->obtenirEnergie() != 0 ||
            creatureMagique3->obtenirPotionMagique() != 0)
        {
            test["TEST1"][1] = 0;
        }

        // Verification: Constructeur avec creature et potionMagique
        if (creatureMagique4->obtenirNom() != "Charizard" ||
            creatureMagique4->obtenirAttaque() != 5 ||
            creatureMagique4->obtenirDefense() != 10 ||
            creatureMagique4->obtenirPointDeVie() != 100 ||
            creatureMagique4->obtenirEnergie() != 30 ||
            creatureMagique4->obtenirPotionMagique() != 4)
        {
            test["TEST1"][1] = 0;
        }


        if (test["TEST1"][1] > 0) {
            std::cout << "[X] Le test 1 a passe correctement" << std::endl;
        }
        else {
            std::cout << "[ ] Le test 1 n'as pas passe correctement" << std::endl;
        }

    }

    // TEST2: Construction des creature Experience | Ponderation: 2pts
    if (true) {

        test["TEST2"][0] = 2;
        test["TEST2"][1] = 2;

        std::cout << std::endl;
        std::cout << "==============================================" << std::endl;
        std::cout << "TEST 2: Constructeurs Creature Experience" << std::endl;
        std::cout << "==============================================" << std::endl << std::endl;

        Pouvoir lave("lave", 4, 20);

        Creature monsterMigra("Impenetrable", 5, 10, 5, 30, lave);

        std::shared_ptr<CreatureExperience> creaExp1 = std::make_shared<CreatureExperience>("Chachacha");
        std::shared_ptr<CreatureExperience> creaExp2 = std::make_shared<CreatureExperience>("Impenetrable", 5, 10, 5, 30, lave, 20);
        std::shared_ptr<CreatureExperience> creaExp3 = std::make_shared<CreatureExperience>(monsterMigra, 20);
        std::shared_ptr<CreatureExperience> creaExp4 = std::make_shared<CreatureExperience>(*creaExp1);


        // Verification: Constructeur avec string uniquement
        if (creaExp1->obtenirNom() != "Chachacha" ||
            creaExp1->obtenirAttaque() != 0 ||
            creaExp1->obtenirDefense() != 0 ||
            creaExp1->obtenirPointDeVie() != 0 ||
            creaExp1->obtenirEnergie() != 0 ||
            creaExp1->obtenirForceExperience() != 0 ||
            creaExp1->obtenirExperience() != 0)
        {
            test["TEST2"][1] = 0;
        }

        // Verification: Constructeur avec parametres
        if (creaExp2->obtenirNom() != "Impenetrable" ||
            creaExp2->obtenirAttaque() != 5 ||
            creaExp2->obtenirDefense() != 10 ||
            creaExp2->obtenirPointDeVie() != 5 ||
            creaExp2->obtenirEnergie() != 30 ||
            creaExp2->obtenirForceExperience() != 20 ||
            creaExp2->obtenirExperience() != 20)
        {
            test["TEST2"][1] = 0;
        }

        // Verification: Constructeur par copie
        if (creaExp2->obtenirNom() != "Impenetrable" ||
            creaExp2->obtenirAttaque() != 5 ||
            creaExp2->obtenirDefense() != 10 ||
            creaExp2->obtenirPointDeVie() != 5 ||
            creaExp2->obtenirEnergie() != 30 ||
            creaExp2->obtenirForceExperience() != 20 ||
            creaExp2->obtenirExperience() != 20)
        {
            test["TEST2"][1] = 0;
        }

        // Verification: Constructeur Creature avec forceExperience
        if (creaExp3->obtenirNom() != "Impenetrable" ||
            creaExp3->obtenirAttaque() != 5 ||
            creaExp3->obtenirDefense() != 10 ||
            creaExp3->obtenirPointDeVie() != 5 ||
            creaExp3->obtenirEnergie() != 30 ||
            creaExp3->obtenirForceExperience() != 20 ||
            creaExp3->obtenirExperience() != 20)
        {
            test["TEST2"][1] = 0;
        }


        if (test["TEST2"][1] > 0) {
            std::cout << "[X] Le test 2 a passe correctement" << std::endl;
        }
        else {
            std::cout << "[ ] Le test 2 n'as pas passe correctement" << std::endl;
        }

    }

    // TEST3: Construction des dresseurs | Ponderation: 1pt
    if (true) {

        test["TEST3"][0] = 1;
        test["TEST3"][1] = 1;

        std::cout << std::endl;
        std::cout << "==============================================" << std::endl;
        std::cout << "TEST 3: Constructeurs Dresseurs" << std::endl;
        std::cout << "==============================================" << std::endl << std::endl;

        std::shared_ptr<DresseurMaitre> dreMaitre1 = std::make_shared<DresseurMaitre>("Hiker", "Saphire echante", 4, 4);
        std::shared_ptr<DresseurApprenti> dreApprenti = std::make_shared<DresseurApprenti>("Brig-the-big", "Carbone echante", 3, 3);


        // Verification: Constructeur et héritage
        if (dreMaitre1->obtenirNom() != "Hiker" ||
            dreMaitre1->obtenirExperience() != 4 ||
            dreMaitre1->obtenirObjetMagique().obtenirNom() != "Saphire echante" ||
            dreMaitre1->obtenirNombreCreatures() != 0)
        {
            test["TEST3"][1] = 0;
        }

        // Verification Constructeur
        if (dreApprenti->obtenirNom() != "Brig-the-big" ||
            dreApprenti->obtenirObjetMagique().obtenirNom() != "Carbone echante" ||
            dreApprenti->obtenirNombreCreatures() != 0 ||
            dreApprenti->obtenirTauxEchec() != 3)
        {
            test["TEST3"][1] = 0;
        }


        if (test["TEST3"][1] > 0) {
            std::cout << "[X] Le test 3 a passe correctement" << std::endl;
        }
        else {
            std::cout << "[ ] Le test 3 n'as pas passe correctement" << std::endl;
        }

    }

    // TEST4: Surcharges de l'operateur= et de l'operateur << | Ponderation: 4pts
    if (true) {

        test["TEST4"][0] = 4;
        test["TEST4"][1] = 4;

        std::cout << std::endl;
        std::cout << "==============================================" << std::endl;
        std::cout << "TEST 4: Surcharges << et =" << std::endl;
        std::cout << "==============================================" << std::endl << std::endl;

        // Surcharge <<

        Pouvoir lave("lave", 3, 20);
        std::shared_ptr<CreatureExperience> impenetrable = std::make_shared<CreatureExperience>("Impenetrable", 5, 9, 5, 30, lave, 20);

        Pouvoir pouvoirFeu("feu", 4, 20);
        std::shared_ptr<CreatureMagique> destructeur = std::make_shared<CreatureMagique>("Destructeur", 5, 8, 4, 28, pouvoirFeu, 18);

        Pouvoir champ("champ electromagnetique", 5, 20);
        std::shared_ptr<CreatureExperience> brainStorm = std::make_shared<CreatureExperience>("BrainStorm", 5, 10, 5, 34, champ, 17);

        Pouvoir roche("roche", 4, 19);
        std::shared_ptr<CreatureMagique> fireBoy = std::make_shared<CreatureMagique>("fireBoy", 5, 10, 5, 30, pouvoirFeu, 20);

        std::shared_ptr<DresseurMaitre> hiker = std::make_shared<DresseurMaitre>("Hiker", "Saphire echante", 4, 4);
        std::shared_ptr<DresseurApprenti> brig = std::make_shared<DresseurApprenti>("Brig-the-big", "Carbone echante", 3, 3);

        hiker->ajouterCreature(impenetrable);
        hiker->ajouterCreature(fireBoy);
        brig->ajouterCreature(destructeur);
        brig->ajouterCreature(brainStorm);

        std::string partyIsOn =
            "Ce soir! Une grande bataille aura lieu dans Polyland!\nDeux adversaires ayant des habiletees incroyables!\nVoicient les creatures choisient:";

        std::cout << partyIsOn << std::endl << std::endl;

        std::cout << "Premier dresseur:" << std::endl;
        std::cout << *hiker << std::endl;
        std::cout << std::endl << "Deuxieme dresseur:" << std::endl;
        std::cout << *brig << std::endl;

        if (!hiker->supprimerCreature("Impenetrable") &&
            !hiker->supprimerCreature("fireBoy") &&
            !brig->supprimerCreature("Destructeur") &&
            !brig->supprimerCreature("BrainStorm"))
        {
            test["TEST4"][1] = 0;
        }



        // Surcharge = creatureMagique, creatureExperimente

        std::string partyIsDown =
            "Malheureusement, cela veut dire qu'une fois de plus,\nles créatures suivantes auraient vouluent être prisent:";

        std::cout << partyIsDown << std::endl << std::endl;

        Pouvoir eau("eau", 1, 10);
        CreatureMagique theGreatMagician("theGreatMagician", 5, 10, 5, 30, eau, 20);
        CreatureMagique prodige = theGreatMagician;
        prodige.modifierNom("prodige");

        Pouvoir plasma("plasma", 1, 9);
        CreatureExperience soldatBlanc("soldatBlanc", 5, 9, 5, 30, plasma, 20);
        CreatureExperience soldatRouge = soldatBlanc;
        soldatRouge.modifierNom("soldatRouge");

        if (theGreatMagician.obtenirExperience() != prodige.obtenirExperience() ||
            theGreatMagician.obtenirEnergie() != prodige.obtenirEnergie() ||
            theGreatMagician.obtenirAttaque() != prodige.obtenirAttaque() ||
            theGreatMagician.obtenirDefense() != prodige.obtenirDefense() ||
            theGreatMagician.obtenirPotionMagique() != prodige.obtenirPotionMagique())
        {
            test["TEST4"][1] = 0;
        }

        if (soldatBlanc.obtenirExperience() != soldatRouge.obtenirExperience() ||
            soldatBlanc.obtenirEnergie() != soldatRouge.obtenirEnergie() ||
            soldatBlanc.obtenirAttaque() != soldatRouge.obtenirAttaque() ||
            soldatBlanc.obtenirDefense() != soldatRouge.obtenirDefense() ||
            soldatBlanc.obtenirForceExperience() != soldatRouge.obtenirForceExperience())
        {
            test["TEST4"][1] = 0;
        }


        std::cout << soldatBlanc << std::endl;
        std::cout << theGreatMagician << std::endl;


        if (test["TEST4"][1] > 0) {
            std::cout << "[X] Le test 4 a passe correctement" << std::endl;
        }
        else {
            std::cout << "[ ] Le test 4 n'as pas passe correctement" << std::endl;
        }

    }


    // TEST5: Verification de la methode attaquer de chaque creature et
    // de la methode utiliserObjetMagique | Ponderation: 2 pts
    if (true) {

        test["TEST5"][0] = 2;
        test["TEST5"][1] = 2;

        std::cout << std::endl;
        std::cout << "==============================================" << std::endl;
        std::cout << "TEST 5: attaquer() et utiliserObjetMagique()" << std::endl;
        std::cout << "==============================================" << std::endl << std::endl;



        Pouvoir pluie("pluie", 4, 18);
        Pouvoir lave("lave", 3, 20);
        Pouvoir roche("roche", 4, 19);
        Pouvoir pouvoirFeu("feu", 4, 20);
        Pouvoir champ("champ electromagnetique", 5, 20);


        std::shared_ptr<Creature> bouleNormale = std::make_shared<Creature>("Boule Normale", 4, 10, 60, 100, pluie);
        std::shared_ptr<CreatureMagique> destructeur = std::make_shared<CreatureMagique>("Destructeur", 5, 8, 60, 100, pouvoirFeu, 18);
        std::shared_ptr<CreatureExperience> brainStorm = std::make_shared<CreatureExperience>("BrainStorm", 5, 10, 60, 100, champ, 17);

        std::shared_ptr<Dresseur> nick = std::make_shared<Dresseur>("Nick", "Velo echante", 4);
        std::shared_ptr<DresseurMaitre> hiker = std::make_shared<DresseurMaitre>("Hiker", "Saphire echante", 4, 4);
        std::shared_ptr<DresseurApprenti> brig = std::make_shared<DresseurApprenti>("Brig-the-big", "Carbone echante", 3, 3);

        std::cout << "Un premier combat commence entre " << hiker->obtenirNom() << ", " << brig->obtenirNom() << " et " << nick->obtenirNom() << std::endl << std::endl;

        nick->ajouterCreature(bouleNormale);
        hiker->ajouterCreature(destructeur);
        brig->ajouterCreature(brainStorm);


        for (unsigned int i = 0; i < 5; i++) {

            std::cout << std::endl << "Maintenant au tour de " << nick->obtenirNom() << std::endl;
            if (hiker->obtenirCreatures()[0]->obtenirPointDeVie() > brig->obtenirCreatures()[0]->obtenirPointDeVie()) {
                nick->obtenirCreatures()[0]->attaquer(*hiker->obtenirCreatures()[0]);
            }
            else {
                nick->obtenirCreatures()[0]->attaquer(*brig->obtenirCreatures()[0]);
            }
            if (i % 2) {
                nick->utiliserObjetMagique(nick->obtenirCreatures()[0]);
            }

            std::cout << std::endl << "Maintenant au tour de " << hiker->obtenirNom() << std::endl;
            if (nick->obtenirCreatures()[0]->obtenirPointDeVie() > brig->obtenirCreatures()[0]->obtenirPointDeVie()) {
                hiker->obtenirCreatures()[0]->attaquer(*nick->obtenirCreatures()[0]);
            }
            else {
                hiker->obtenirCreatures()[0]->attaquer(*brig->obtenirCreatures()[0]);
            }
            if (i % 2) {
                hiker->utiliserObjetMagique(nick->obtenirCreatures()[0]);
            }


            std::cout << std::endl << "Maintenant au tour de " << brig->obtenirNom() << std::endl;
            if (nick->obtenirCreatures()[0]->obtenirPointDeVie() > hiker->obtenirCreatures()[0]->obtenirPointDeVie()) {
                brig->obtenirCreatures()[0]->attaquer(*nick->obtenirCreatures()[0]);
            }
            else {
                brig->obtenirCreatures()[0]->attaquer(*hiker->obtenirCreatures()[0]);
            }
            if (i % 2) {
                brig->utiliserObjetMagique(nick->obtenirCreatures()[0]);
            }
        }

        std::cout << std::endl << "Ce fut un combat incroyable!" << std::endl;

        // Le test 5 passe automatiquement, le but est d'avoir un affichage similaire
        std::cout << std::endl << "[X] Le test 5 a passe correctement" << std::endl;

    }

    // TEST6: Verification du polymorphisme dans Polyland | Ponderation: 1pt

    if (true) {

        test["TEST6"][0] = 1;
        test["TEST6"][1] = 1;


        std::cout << std::endl;
        std::cout << "==============================================" << std::endl;
        std::cout << "TEST 6: Polymorphisme avec Experience" << std::endl;
        std::cout << "==============================================" << std::endl << std::endl;


        PolyLand poly;

        Pouvoir pluie("pluie", 4, 18);
        Pouvoir pouvoirFeu("feu", 4, 20);
        Pouvoir champ("champ electromagnetique", 5, 20);

        std::shared_ptr<Creature> bouleNormale = std::make_shared<Creature>("Boule Normale", 4, 10, 60, 100, pluie);
        std::shared_ptr<CreatureMagique> destructeur = std::make_shared<CreatureMagique>("Destructeur", 5, 8, 60, 100, pouvoirFeu, 18);
        std::shared_ptr<CreatureExperience> brainStorm = std::make_shared<CreatureExperience>("BrainStorm", 5, 10, 60, 100, champ, 17);

        poly += bouleNormale;
        poly += destructeur;
        poly += brainStorm;

        std::shared_ptr<Dresseur> nick = std::make_shared<Dresseur>("Nick", "Velo echante", 4);
        std::shared_ptr<DresseurMaitre> hiker = std::make_shared<DresseurMaitre>("Hiker", "Saphire echante", 4, 10);
        std::shared_ptr<DresseurApprenti> brig = std::make_shared<DresseurApprenti>("Brig-the-big", "Carbone echante", 3, 3);

        poly += nick;
        poly += hiker;
        poly += brig;

        cout << poly;

        poly.afficherExperience();

        // TODO: Decommenter une fois l'implementation de Experience et de ces classes enfant est terminee
        //if (hiker->obtenirExperience() != poly.trouverPlusGrandeExperience()->obtenirExperience()) {
        //    test["TEST6"][1] = 0;
        //}


        poly.retirerDresseur("Nick");
        poly.retirerDresseur("Hiker");
        poly.retirerDresseur("Brig-the-big");

        if (poly.choisirDresseur("Nick") != nullptr || poly.choisirDresseur("Hiker") != nullptr ||
            poly.choisirDresseur("Brig-the-big") != nullptr) {
            test["TEST6"][1] = 0;
        }

        poly.retirerCreature("Boule Normale");
        poly.retirerCreature("Destructeur");
        poly.retirerCreature("BrainStorm");

        if (poly.choisirCreature("Boule Normale") != nullptr || poly.choisirCreature("Destructeur") != nullptr ||
            poly.choisirCreature("BrainStorm") != nullptr) {
            test["TEST6"][1] = 0;
        }

        if (poly.obtenirExperience().size() != 0) {
            test["TEST6"][1] = 0;
        }

    }

    std::cout << std::endl;
    std::cout << "==============================================" << std::endl;
    std::cout << "Retour sur les test " << std::endl;
    std::cout << "==============================================" << std::endl << std::endl;

    int sum = 0;
    int resultat = 0;

    for (auto p : test) {
        sum += p.second[0];
    }

    for (auto p : test) {
        std::cout << p.first << ": " << p.second[1] << "/" << p.second[0] << std::endl;
        resultat += p.second[1];
    }


    std::cout << std::endl << "RESULTAT: " << resultat << "/" << sum << std::endl;


    return 0;
}
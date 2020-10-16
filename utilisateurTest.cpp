/*
 * utilisateurTest.cpp
 *
 *  Created on: 2020-10-11
 *      Author: etudiant
 */

#include "Utilisateur.h"
#include <iostream>

using namespace std;

int main()
{
	vector<lab7::Utilisateur> liste = {

			lab7::Utilisateur("pascal", "charpentier"),
			lab7::Utilisateur("patrick", "cormier"),
			lab7::Utilisateur("Philippe", "Charbonneau"),
			lab7::Utilisateur("Daniel", "Gagnon"),
			lab7::Utilisateur("mark", "skarzynski"),
			lab7::Utilisateur("pierre", "chagnon"),
			lab7::Utilisateur("denis", "gingras")
	};

	string userId;

	// Afficher les utilisateurs
	for (auto user: liste) cout << user.reqUtilisateurFormatte() << endl;
	cout << lab7::Utilisateur::reqListeDesNomsUtilisateursFormattee() << endl;

	// Recherche par ID
	cout << "Veuillez saisir un nom d'utilisateur : ";
	cin >> userId;

	bool trouve = false;
	for (auto user: liste)
	{
		if (user.estUtilisateurRecherche(userId))
		{
			cout << "Utilisateur localisé:  " << user.reqUtilisateurFormatte() << endl;
			trouve = true;
		}
	}
	if (!trouve) cout << "Cet utilisateur n'a pas été localisé dans la liste." << endl;
	cout << "Programme terminé, au revoir!" << endl;

	return 0;
}





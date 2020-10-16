/*
 *  Utilisateur.h
 *
 *  Created on: 2020-10-11
 *      Author: etudiant
 */

#ifndef UTILISATEUR_H_
#define UTILISATEUR_H_

#include <vector>
#include <string>

namespace lab7 {

class Utilisateur
{

private:

    static std::vector<std::string> nomsUtilisateurs;

	std::string m_nom;
	std::string m_prenom;
	std::string m_nomUtilisateur;


	bool listeDesNomsUtilisateursEstValide();

public:
	Utilisateur(const std::string& p_prenom, const std::string& p_nom);

	const std::string& reqPrenom() const;
	const std::string& reqNom() const;
	const std::string& reqNomUtilisateur() const;

	bool estUtilisateurRecherche(const std::string& p_userId) const;

	std::string reqUtilisateurFormatte() const ;

	static std::string creerInitiales(const std::string& p_prenom, const std::string& p_nom);
	static bool lesInitialesSontDansLaListe(const std::string& p_initiales);
	static int compterLesInitialesDansLaListe(const std::string& p_initiales);
	static std::string reqListeDesNomsUtilisateursFormattee();

};

} /* namespace lab7 */

#endif /* UTILISATEUR_H_ */

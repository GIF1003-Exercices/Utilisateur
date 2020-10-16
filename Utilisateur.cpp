/*
 * Utilisateur.cpp
 *
 *  Created on: 2020-10-11
 *      Author: etudiant
 */

#include "Utilisateur.h"
#include <sstream>
#include <string>
#include <cassert>
#include <iomanip>

namespace lab7 {

std::vector<std::string> Utilisateur::nomsUtilisateurs = {};

Utilisateur::Utilisateur(const std::string& p_prenom, const std::string& p_nom) : m_nom(p_nom), m_prenom(p_prenom), m_nomUtilisateur(creerInitiales(p_prenom, p_nom))
{
    m_nomUtilisateur += std::to_string(compterLesInitialesDansLaListe(m_nomUtilisateur));
    nomsUtilisateurs.push_back(m_nomUtilisateur);

    assert(listeDesNomsUtilisateursEstValide());
}

const std::string& Utilisateur::reqPrenom() const
{
	return m_prenom;
}

const std::string& Utilisateur::reqNom() const
{
	return m_nom;
}

const std::string& Utilisateur::reqNomUtilisateur() const
{
	return m_nomUtilisateur;
}

bool Utilisateur::estUtilisateurRecherche(const std::string& p_userId) const
{
	return (p_userId == m_nomUtilisateur);
}

bool Utilisateur::listeDesNomsUtilisateursEstValide()
{
	size_t longueur = nomsUtilisateurs.size();

	for (size_t i = 0; i < longueur; ++i)
	{
		for (size_t j = i + 1; j < longueur; ++j)
		{
			if (nomsUtilisateurs[i] == nomsUtilisateurs[j]) return false;
		}
	}
	return true;
}

std::string Utilisateur::creerInitiales(const std::string& p_prenom, const std::string& p_nom)
{
	std::ostringstream s;

	s << (char) toupper(p_prenom[0]) << (char) toupper(p_nom[0]) ;
    return s.str();
}



int Utilisateur::compterLesInitialesDansLaListe(const std::string& p_initiales)
{
	int decompte = 0;

	for (std::string nomUtilisateur: nomsUtilisateurs)
	{
		if ( (p_initiales[0] == nomUtilisateur[0]) and (p_initiales[1] == nomUtilisateur[1]) )
		{
			++decompte;
		}
	}
	return decompte;
}

bool Utilisateur::lesInitialesSontDansLaListe(const std::string& p_initiales)
{
	return (compterLesInitialesDansLaListe(p_initiales) != 0);
}

std::string Utilisateur::reqListeDesNomsUtilisateursFormattee()
{
	std::ostringstream os;

	for (auto nom: nomsUtilisateurs)
	{
		os << nom << std::endl;
	}
	return os.str();
}

std::string Utilisateur::reqUtilisateurFormatte() const
{
	std::ostringstream os;
	os <<  std::setw(20) << m_nom << "  " << std::setw(20) << m_prenom << std::setw(20) << m_nomUtilisateur;
	return os.str();
}

} /* namespace lab7 */

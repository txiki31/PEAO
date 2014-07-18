/******************************************************************************
 *   Société      : EXPANSIA PCAS - route d'Aramon 30390 Aramon (FRANCE)      *
 *   Projet       : PEAO                                                      *
 ******************************************************************************
 *   Module           :                    *
 *   Fichier          : peao.hpp                                              *
 *   Classe           : PEAO                                                  *
 *   Date de création : 17/07/2014                                            *
 *   Auteur           : Cyril Charbonneau                                     *
 *   Langage          : C++                                                   *
 ******************************************************************************
 *   Logiciel                   : Qt 5.3                                      *
 *   Options de compilation     :                                             *
 *   Options d'édition de liens :                                             *
 ******************************************************************************/

#ifndef PEAO_HPP
#define PEAO_HPP

#include "gestionnairefenetre.hpp"

/**
 * @class PEAO
 * @brief Classe de base du logiciel.
 *
 * Cette classe instancie toutes les classes nécéssaires au démarrage du logiciel.
 * Elle transmet les instructions aux autres classes durant le fonctionnement du logiciel.
 * Elle sert également d'intermédiaire lors de la transmission de
 * données d'un module à un autre.
 *
 * exemple:
 * peao.bfnLancerProgrammePrincipal()
 * //Lancement du programme et affichage de la fenetre principale
 *
 */
class PEAO
{
private:
    bool mb_OperationEnCours;
    GestionnaireFenetre *mGF_gestFenetre;
public:
    PEAO();
    bool bfnLancerProgrammePrincipal();
    void fninitialiserOperation();
    void fnQuitterOperation();
    bool bfnOperationEnCours();
    ~PEAO();
};

#endif // PEAO_HPP
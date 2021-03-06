#include "f_article.hpp"
#include "ui_f_article.h"
#include "gestionnairefenetre.hpp"
#include <QMessageBox>

/**
* @brief Constructeur de la classe F_Article.
* Liaison du composant avec l'arborescence Qt.
* Création de l'interface graphique pour éditer la fenêtre.
* @param parent: Objet auquel le composant(de Qt) sera lié.
*/
F_Article::F_Article( GestionnaireFenetre *gf,  QWidget * parent ) :
    QDialog( parent ),
    ui( new Ui::F_Article )
{
    mptrGestionnaireFenetre = gf;
    if( ui )ui->setupUi(this);
}

/**
* @brief Reception du signal du bouton d'annulation du formulaire Article.
* La fenetre se ferme.
*/
void F_Article::on_btAnnulerArt_clicked()
{
    close();
}

/**
* @brief Reception de l'evenement de femeture de la fenetre.
* Les champs sont vides.
*/
void F_Article::closeEvent ( QCloseEvent * e )
{
    ui->leNumArt->clear();
    ui->leLibArt->clear();}

/**
* @brief Reception du signal du bouton de soumission du formulaire Article.
* Dans un premier temps la fonction va vérifier si tous les champs ont bien été remplis.
* Si tel est le cas ces données vont être envoyées à l'objet
* GestionnaireFenetre.
*/
void F_Article::on_btValiderArt_clicked()
{
    QString textErreur="", receptNumeroArticle, receptLibelleArticle;
    if( ui && ui->leNumArt )receptNumeroArticle = ui->leNumArt->text();
    //recuperation du numéro d'e lot'article du formulaire
    if( ui && ui->leLibArt )receptLibelleArticle = ui->leLibArt->text();
    //recuperation du libelle de l'article du formulaire
    if( receptNumeroArticle.size() == 0 )//si champ numéro de lot vide
    {
        textErreur += "Erreur: numéro d'article non entré \n";
        //Stock du message d'erreur dans la chaine à afficher dans la fenetre de résultat
    }
    if( receptLibelleArticle.size() == 0 )//si champ libelle vide
    {
        textErreur += "Erreur: Libelle non entré";
    }
    if( textErreur.size() != 0 )//si message d'erreur
    {
        QMessageBox::information( this, "Formulaire Article", textErreur );
        //fenetre pour signaler l'erreur
        return;
    }
        if( mptrGestionnaireFenetre )mptrGestionnaireFenetre->fnCreerArticle(
                        receptNumeroArticle.toStdString(),  receptLibelleArticle.toStdString() );

        close();
}

/**
* @brief Destructeur de la classe F_Article.
* Supression de l'interface d'édition de la fenêtre.
*/
F_Article::~F_Article()
{
    delete ui;
}


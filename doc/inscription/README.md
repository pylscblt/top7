## Liste des étapes de l'inscription d'une équipe

###    Formulaire inscription
* Equipe + 7 joueurs (Pseudos/Emails), 1er joueur=capitaine
* Tant que le formulaire n'est pas complet il est renvoyé
* Le formulaire pour inscrire l'équipe est remplie par le capitaine

###    Insertion dans database et envoie email
* insertion nom équipe
* Pour chaque joueur : insertion joueur + envoie email
* joueur status = waiting (password par défaut)
* équipe status = disabled
* table password avec date
* envoie email avec lien new_password?key
* Ecran retour Capitaine

###    Validation inscription
* Chaque joueur a reçu un mail avec un lien qui le renvoie sur une page où il définit son password
* joueur status = enabled

###    Validation équipe
* A chaque fois qu'un joueur valide son inscription, tester si l'ensemble de l'équipe est complète
* Si équipe complète : équipe status = enabled

###    Login joueur
* Si équipe complète, allez sur page Top7/journée
* Si équipe non complète, allez sur page Top7/Equipe et afficher liste des joueurs avec status (valider/en attente)

###    Modification équipe, pseudo, email
* Chaque joueur peut changer son pseudo
* Seul le capitaine peut changer le nom de l'équipe
* Les emails ne peuvent être changer que par le capitaine et que pour un joueur status=en attente. Un changement d'email relance un email de validation d'inscription.




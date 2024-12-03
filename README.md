# so_long

**so_long** est un projet de développement de jeu vidéo en 2D réalisé dans le cadre de la formation à l'école 42. Il consiste en la création d'un jeu où le joueur doit collecter des objets tout en évitant des obstacles et en atteignant un objectif, le tout dans un environnement graphique 2D basé sur une carte statique.

## Fonctionnalités

- **Affichage d'une carte 2D** : Le jeu est basé sur une carte statique composée de différentes cellules, chacune représentant un élément du jeu (sol, mur, porte, objet à collecter, etc.).
- **Déplacement du joueur** : Le joueur peut se déplacer sur la carte avec les touches fléchées ou `WASD`.
- **Collecte d'objets** : Le joueur doit collecter des objets spécifiques (souvent des clés ou des pièces) pour avancer dans le jeu.
- **Objectif de fin de niveau** : Le joueur doit atteindre un objectif (par exemple, une porte) pour passer à un autre niveau ou terminer le jeu.
- **Gestion des collisions** : Le joueur peut rencontrer des murs et ne pourra pas passer à travers.
- **Graphismes simples** : Utilisation de la bibliothèque graphique **MiniLibX** pour afficher les éléments du jeu à l'écran.
- **Vérifications de validité** : Le projet inclut des vérifications pour s'assurer que le fichier de carte est valide (existence de points de départ et d'arrivée, accessibilité des objets, etc.).

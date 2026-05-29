# Wake-Up-Eva
Le Wake Up Eva (WUE) est un boitier qui permet à ceux qui ont un souci d'attention de réaliser une série de tache sans se perdre. 
Il s'agit principalement d'une aide pour les enfants TDAH.

Il se présente sous la forme d'un boitier composé d'un module programmable (ESP32C3mini) avec un ecran simple de deux lignes (2*16) de deux boutons et un bipper.
Lors de la mise en marche, le premier écran propose deux option (selectionnable par les boutons) :
"Normal" ou "Sbs" (Step by Step)
Le programme "Normal" va simplement faire bipper et clignotter l'écran avec un message de rappel identique. Il faut que l'enfant appuie sur le bouon blanc pour faire cesser le bip et relancer la tempo.

Le mode Sbs lance des étapess, ici ce sont les étapes necessaires pour la toilette/habillage du matin que j'ai créé pour ma fille qui n'arrive pas à suivre cette série d'actes sans être en permanence déconcentré.
Chaque étape a un temps donné, après lequel le WUE se met à bipper et demande si l'etape est effectué. Si oui -> passage à l'étape suivante.
Si non -> reboucle la tempo.

Il suffit de suivre le shema de cablage (à venir) et de flasher l'esp avec le programme.
Il est possible de modifier les etapes et temps selon vos besoins.

Matériel: ESP32, ecran LCD 2 lignes 16 caractères (I2C) , 2 boutons poussoir, buzzer actif

Tout parents ou proche d'enfants ayant des difficultées peut le réaliser avec le matériel requis et le mettre à disposition des familles en ayant besoin.
J'ai beaucoup d'idée pour développer le projet et le rendre plus accessible à ceux qui en ont besoin.

IL EST HORS DE QUESTION QUE CE PROJET SERVE AU PUR PROFIT D'INDUSTRIELS OU DE COLLECTE DE DONNEES QUELS QU'ELLES SOIENT !

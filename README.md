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


Edit 29-05-2026:

Un Wake Up Eva 2.1 est finalisé !
Je mettrai les détailes plus tard, mais voici quelques indications:
Problème: sur le premier modèle, l'appuis sur le bouton necessite de rester appuyé le temps de la scrutation des bouton entre deux série de bips. Pour mon plus jeune enfant qui ne sais pas lire, il faut qu'il connaisse les etapes par coeur... Dernier point: l'ecran ne permet pas d'afficher des images.

Sur ce nouveau modèle, j'ai utilisé les interruptions pour rendre les boutons plus réactifs. 
J'ai remplacé l'écran pour un modèle TFT en interface SPI (resolution 76*284).
J'ai ajouté un module de lecture MP3 "DFPlayerMini", avec une micro SD et j'ai réalisé les enregistrements des consignes à la voix.
J'ai ajouté un module "LX-LCBST" pour la gestion de la batterie: un element 18650 Li-ion.

J'ai donc revu tout le programme pour adapter celui qui est déja fonctionnel (toilette matin) avec les consignes vocales.
J'ai également créé un nouveau programme pour le lavage des dents.

Le cablage est plus complexe (presque toutes les pin de l'ESP32C3 sont prises).
Je ferai un shema de cable et diffuserai le programme plus tard.

Une video est prévu pour la présentation du programme, elle sera difusé sur PeerTube.

Projet d'évolution: Passer sur une carte avec un STM32F411CEU6 afin d'avoir une meilleure gestion de l'ensemble et utiliser un module lecteur de micro-sd pour stocker les fichier audios et images, remplacer le DFPlayerMini par un simple amplificateur.

Donc.... à suivre ! :)

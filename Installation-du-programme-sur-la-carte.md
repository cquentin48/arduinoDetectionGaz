# 1. Configurer le logiciel
* Aller dans "Outils/Types de carte/Gestionnaire de cartes/" et rechercher "ESP8266".
Prendre la version 2.4.2 de la carte ESP8266.
* Penser à inclure la librairie suivante : aller dans "gérer les bibliothèques/" et rechercher "adafruit mqtt" pour prendre la librairie "Adafruit MQTT Library"

# 2. Configurer le programme
* Télécharger le programme
* Aller dans le fichier appliDetectionGaz.ino et changer les variables ssid et password par respectivement le nom du réseau et celui du mot de passe
* Créer un compte sur io.adafruit.com
* Créer un feed
![](https://cdn-learn.adafruit.com/assets/assets/000/039/200/medium800/adafruit_io_04_feed_list.png?1487005834)
![](https://cdn-learn.adafruit.com/assets/assets/000/039/194/medium800/adafruit_io_00_action_menu.png?1487005199)
![](https://cdn-learn.adafruit.com/assets/assets/000/039/201/medium800/adafruit_io_Screen_Shot_2017-02-13_at_12.11.32_PM.png?1487005928)
![](https://cdn-learn.adafruit.com/assets/assets/000/039/196/medium800/adafruit_io_01_new_feed.png?1487005503)

* Penser à générer un id
![](https://cdn-learn.adafruit.com/assets/assets/000/027/962/medium800/adafruit_products_Feeds.png?1443832073)

* Créer une jauge en passant par triggers avec les paramètres suivants :
        *  Nom : celui que vous voulez
        *  Valeur minimale : 0
        *  Valeur maximale : 1025
![](https://cdn-learn.adafruit.com/assets/assets/000/027/963/medium800/adafruit_products_Gauge.png?1443832219)
# YouTube Abonnenten Anzeige <!-- omit in toc -->

![GitHub license](https://img.shields.io/github/license/rays-projekt/youtube-subcounter?style=flat-square)
![Maintenance](https://img.shields.io/maintenance/yes/2020?style=flat-square)

![YouTube Abonnenten Anzeige an French Cleat](https://user-images.githubusercontent.com/39838608/86521701-7eacb700-be54-11ea-8d58-bd03c38d949f.png)

Einfache Echtzeit-Anzeige der YouTube-Abonnentenzahl unter Verwendung eines ESP8266-Wifi-Board und einer MAX7219 LED Modul 8 Bit 7-Segmentanzeige.

## Inhaltsverzeichniss <!-- omit in toc -->

- [Vorraussetzungen](#vorraussetzungen)
- [Materialien](#materialien)
- [Bibliotheken](#bibliotheken)
- [Boardkonfiguration](#boardkonfiguration)
- [Schaltplan](#schaltplan)
  - [Übersicht](#übersicht)
  - [Anschlüsse](#anschlüsse)

## Vorraussetzungen

- [Google API key](https://support.google.com/cloud/answer/6158862)
- [YouTube Channel ID](https://support.google.com/youtube/answer/3250431?hl=en)
- Wi-Fi Netzwerk SSID und Passwort

## Materialien

- NodeMCU ESP8266 Modul - [Amazon Link](https://www.amazon.de/dp/B06Y1LZLLY/ref=cm_sw_em_r_mt_dp_U_0E1.EbYG35X52)
- MAX7219 Led Modul 8 Bit 7-Segmentanzeige - [Amazon Link](https://www.amazon.de/dp/B07D8ZC7Q3/ref=cm_sw_em_r_mt_dp_U_Xy1.Eb7TR0N1C)

## Bibliotheken

- [YouTubeApi](https://github.com/witnessmenow/arduino-youtube-api) - *getestet mit v. 2.0.0*
- [ArduinoJson](https://github.com/bblanchon/ArduinoJson) - *getestet mit v. 6.15.2*
- [LedControl](https://github.com/wayoda/LedControl) - *getestet mit v. 1.0.6*

Installiere die Bibliotheken einfach über den [Bibliotheksverwalter]((https://www.arduino.cc/en/Guide/Libraries#toc3)) unter **Werkzeuge ➔ Bibliotheken verwalten...** oder [manuell](https://www.arduino.cc/en/Guide/Libraries#toc4) per `.zip` von GitHub.

## Boardkonfiguration

Bevor du dich in dieses Projekt stürzt, solltest du dich zunächst vergewissern, dass deine Arduino-Software richtig eingerichtet ist, um das von dir verwendete Board zu programmieren.

1. Begebe dich zu den Voreinstellungen über **Datei ➔ Voreinstellungen** oder durch die Tastenkombination `Strg + Komma`
2. Suche das Textfeld mit der Bezeichnung **Zusätzliche Boardverwalter URLs:** und füge den folgenden URL in das Feld ein *(mehre URLs mit Kommas trennen, falls zutreffend)*: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
3. Bestätige mit OK
4. Dann begebe dich zum Bordverwalter über **Werkzeuge ➔ Board ➔ Boardverwalter...**
5. Hier suchst du jetzt nach `esp8266` und installierst das Paket von **ESP8266 Community**
6. Schließe nach erfolgreicher Installation dein Arduino an deinen Computer über das USB-Kabel und Konfiguriere Einstellungen über **Werkzeuge** wie folgt:
  
- Board: NodeMCU 1.0
- Upload Speed: 115200
- CPU Frequency: 80MHz
- Flash Size: 4M

## Schaltplan

### Übersicht

![Boardübersicht mit Anschlüssen](https://user-images.githubusercontent.com/39838608/86521736-ee22a680-be54-11ea-82f6-144f4c919686.png)

### Anschlüsse

|ESP8266|MAX7219|
|-------|-------|
|`3V`   |`VCC`  |
|`G`    |`GND`  |
|`D6`   |`LOAD` |
|`D7`   |`CLK`  |
|`D8`   |`DIN`  |

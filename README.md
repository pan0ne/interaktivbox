# InterAktivBox
## Sensorgesteuerter Audioplayer 
#### Vergleichbares Projekt:  https://echokammerinterventions.wordpress.com/
#### (Hier eine Version mit Radar- und IR- Sensoren)

### Elektronische Bauteile

- ESP32-Wroom-32
- AMP Modul [GF1002](https://naltronic.de/business-industrie/elektronik-messtechnik/elektronische-bauelemente/halbleiter-aktive-elemente/platinen-entwicklungskits/357/pam8403-digitale-verstaerkerplatine-gf1002-2x3-watt-5vdc)
- [Serial MP3 Player Modul V1.2](https://www.makershop.de/module/audio/yx5300-mp3/)
- Radar Sensor [HLK-LD2410](https://de.aliexpress.com/item/1005004351593073.html)
- [PIR Bewegungssensor AM312](https://www.christians-shop.de/Mini-IR-AM312-Bewegungsmelder-PIR-Motion-Bewegungssensor-27-to-12V)
- Latch Modul [KY002](http://www.icstation.com/single-button-bistable-switch-module-flip-flop-latch-falling-edge-trigger-switch-ky002-p-9309.html)
- [Speaker 8 Ohm](https://eckstein-shop.de/Speaker-8-Ohm-05W-50mm-Lautsprecher-fuer-jedes-Audioprojekt)
- Kabel
- 1x 18650 LiPo Batterien + [Batterieboard](https://www.segor.de/INFO/weitere-produkte/389-18650-battery-shield.shtml)
- 1x SD Karte

### Programmierumgebung

- Arduino IDE

### Bibliotheken

- https://github.com/salvadorrueda/SerialMP3Player
- https://github.com/ncmreynolds/ld2410
- https://github.com/plerup/espsoftwareserial

### Funktionsweise

Die InteraktivBox soll Personen, die an ihr vorbei laufen, Geschichten von Menschen erzählen die aus Kriegsgebieten geflohen sind. Ein ESP32 steuert das Abspielen von Audiodaten im MP3 Format, welche bei Erkennung von Bewegung automatisch und in zufälliger Reihenfolge abgespielt werden. Wird keine Bewegung durch Personen erkannt, wird der Abspielprozess gestoppt und das Latch Modul (KY002) schaltet den MP3 Player, das Verstärkermodul und den Radarsensor aus um Energie zu sparen. Der ESP32 geht danach in den DeepSleep Modus. Der PIR Bewgungssensor weckt die MCU im Bedarfsfall wieder auf.
Der Radarsensor eigenet sich für diese Projekt insofern, als das dieser auch Personen erkennt, wenn diese sich nicht bewegen.  Ein Vorteil, den ein normaler PIR Bewegungssensor nicht hat. Dadurch bleibt der Abspielprozess bestehen wenn eine Person vor der InterAktivbox steht sich aber nicht bewegt.

*Schaltungsaufbau: siehe Schaltplan.




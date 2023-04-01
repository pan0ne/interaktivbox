# InterAktivBox
Sensorgesteuerter Audioplayer spielt Audiodateien ab wenn sich Personen in der Nähe befinden

*Elektronische Bauteile:*

- ESP32-Wroom-32
- AMP Modul GF1002
- Serial MP3 Player Modul V1.2
- Radar Sensor HLK-LD2410
- PIR Bewegungssensor
- Latch Modul TLP5110
- Speaker 8 Ohm
- Kabel
- 2x 18650 LiPo Batterien

*Programmierumgebung:*

- Arduino IDE

*Bibliotheken:*

*Funktionsweise:*

Die InteraktivBox soll Geschichten von Menschen erzählen, die aus Kriegsgebieten geflohen sind. Ein ESP32 steuert das Abspielen von Audiodaten im MP3 Format, welche bei Erkennung von Bewegung automatisch und in zufälliger Reihenfolge abgespielt werden. Wird keine Bewegung durch Personen erkannt, wird der Abspielprozess gestoppt und das Latch Modul schaltet den MP3 Player, das Verstärkermodul und den Radarsensor aus um Energie zu sparen. Der ESP32 geht danach in den DeepSleep Modus. Der PIR Bewgungssensor weckt die MCU im Bedarfsfall wieder auf.
Der Radarsensor eigenet sich für diese Projekt insofern, als das dieser auch Personen erkennt, wenn diese sich nicht bewegen.  Ein Vorteil, den ein normaler PIR Bewegungssensor nicht hat.
Dadurch bleibt der Abspielprozess bestehen wenn eine Person vor der InterAktivbox steht sich aber nicht bewegt.

*Schaltungsaufbau:*




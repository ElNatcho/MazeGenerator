# MazeGenerator

Ein einfaches Programm, dass ein Labyrinth in einer beliebigen Größe generiert und als monochromes Bild in einer Datei speichert.

Es wird mithilfe von Kommandozeilenparametern gestartet:

MazeGenerator x y img_path  
"x": Breite des Labyrinths  
"y": Höhe des Labyrinths  
"img_path": Datei in der das erzeugte Labyrinth abgespeichert werden soll  

Beispiel: 50 x 30  
![50x30](https://cloud.githubusercontent.com/assets/21142935/25276882/9b936b6e-269c-11e7-9312-327091b00dbe.png)

# AStar

Ebenfalls ein einfaches Programm, dass den effizientesten Weg durch ein mit dem MazeGenerator generiertes Labyrinth findet.
Ist das Programm fertig speichert es das Labyrinth-Bild mit dem eingezeichneten Lösungsweg (gelb) und den "abgegangenen" Wegen (rot).

Es wird mithilfe von Kommandozeilenparametern gestartet:

AStar.exe img_path
"img_path" Pfad zum/Name des Labyrinth-Bildes

bzw. es wird via Drag and Drop der Bilddatei auf die Exe gestartet.

Beispiel: 275 x 275
![275x275_solved](https://cloud.githubusercontent.com/assets/21142935/25305181/f5b6bcb0-2776-11e7-9e3e-f8b03fff425f.png)

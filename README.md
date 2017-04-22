# MazeGenerator

Ein einfaches Programm, dass ein Labyrinth in einer beliebigen Größe generiert und als monochromes Bild in einer Datei speichert.

Es wird mithilfe von Kommandozeilenparametern gestartet:

MazeGenerator x y img_path [conProbability]
"x": Breite des Labyrinths  
"y": Höhe des Labyrinths  
"img_path": Datei in der das erzeugte Labyrinth abgespeichert werden soll  
"conProbability" (Optional): Wahrscheinlichkeit für das Generieren von zufälligen Verbindungen zwischen Wegen

Beispiel: 50 x 30  
![50x30](https://cloud.githubusercontent.com/assets/21142935/25306511/b1c3ff96-278e-11e7-8b22-31a48e31181e.png)

# AStar

Ebenfalls ein einfaches Programm, dass den effizientesten Weg durch ein mit dem MazeGenerator generiertes Labyrinth findet.
Ist das Programm fertig speichert es das Labyrinth-Bild mit dem eingezeichneten Lösungsweg (gelb) und den "abgegangenen" Wegen (rot).

Es wird mithilfe von Kommandozeilenparametern gestartet:

AStar.exe img_path  
"img_path" Pfad zum/Name des Labyrinth-Bildes

bzw. es wird via Drag and Drop der Bilddatei auf die Exe gestartet.

Beispiel: 200 x 200  
![200x200_solved](https://cloud.githubusercontent.com/assets/21142935/25306502/5f7573b4-278e-11e7-86e7-9fe83b1b3165.png)

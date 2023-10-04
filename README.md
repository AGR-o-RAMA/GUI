# AGR-o-RAMA-GUI

Welcome to the AGR-o-RAMA User Interface Usage Documentation. This guide provides detailed instructions on how to install and use the user interface effectively.

## Table of Contents

- [Install](#install)
- [Projects](#projects)
  - [New Project](#new-project)
  - [Open Project](#open-project)
  - [Settings](#settings) 
- [Map](#map)
- [Control Panel](#control-panel)
  - [Mission Planning](#mission-planning)
  - [Results Visualization](#results-visualization)
- [UI Elements](#ui-elements)

## Install

To satisfy the user interface dependencies, follow these steps:

1. **Install Qt 6.5.1 (or higher)**: metti link e roba varia. Se diventa corposo, facciamo una sotto sezione ###

2. **Install ArcGIS**: link all'installazione e due parole su come installarlo.

## Projects
When the program is launched, the API key for ArcGIS is requested. If it is correct, the main window with the map will be showm. Otherwise, the main window will be shown, but the map will not be loaded.
The API keythat is inserted is saved in a file in the $arcgis$ folder, so the next times the porgeam is launched, the key is automatically recovered from the file.


### New Project
To create a new project, click **Project** > **New** and fill all required informations.
### Open Project
To open a project, click **Project** > **Open** and choose a YAML file to open,
### Settings 
To change the information fields will be written in the YAML file, click **Configure** > **Settings**.
## Map

Spiegare tutti gli shortcut. Alcuni che mi ricordo sono: 
- a->ruota a dx
- d->ruota a sx
- doppio click con il sinistro -> zoom in
- doppio click con il sinistro -> zoom out
- \+ da tastiera -> zoom in
- \- da tasitera -> zoom out
- Gesture con due dita == rotella mouse -> zoom 

## Control Panel

### Mission Planning
The right order of steps from the creation of a project to the generation of the orthomap is the following one:
1. Create a new project (or open an existing one)
2. (Optional) Load a KML file
3. Zoom in/out according to the desired size of the map
4. Activate the Edit Mode
5. Resize the size of the tiles as you want, through the slider on the right side of the screen
6. Select the desired tiles
   (**N.B.** If you increase/decrease the tiles size while the edit mode is activated, the previous selected tiles will be deleted)
7. (Optional) Change settings
8. (Optional) Activate $use$ $cuda$ flag, clicking on **Options** > **use cuda**
9. Click **Generate** to generate CSV and YAML files
10. Click **Orthomap** to render images
11. Wait until the process is ended

### Results Visualization
Spiegare come visualizzare i risultati ecc..

## UI Elements
Spiegare tutte le cose che rimangono (boh tipo light/dark mode e la sezione Help>About). Se trovate un titolo migliore cambiatelo pure.

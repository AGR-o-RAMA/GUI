# AGR-o-RAMA-GUI

Welcome to the AGR-o-RAMA User Interface Usage Documentation. This guide provides detailed instructions on how to install and use the ui effectively.  

## Table of Contents

- [AGR-o-RAMA-GUI](#agr-o-rama-gui)
  - [Install](#install)
  - [Run](#run)
  - [Overview](#overview)
  - [Projects](#projects)
    - [New Project](#new-project)
    - [Open Project](#open-project)
    - [Settings](#settings)
  - [Map](#map)
    - [Normal mode](#normal-mode)
    - [Edit mode](#edit-mode)
  - [Control Panel](#control-panel)
    - [Mission Planning](#mission-planning)
    - [Results Visualization](#results-visualization)

## Install

To satisfy the user interface dependencies, follow these steps:

**Install Qt 6.5 (or higher)**:

- [Download the installer at this link](https://www.qt.io/download-qt-installer-oss?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4)
- Run the downloaded file:
  - Select the downloaded file and open its properties with <kbd>Ctrl</kbd> + <kbd>i</kbd>
  - Go to permissions and select **Allow executing file as a program**
  - Execute the file either with double-click or by terminal
- Select custom installation and select any Qt version above 6.5
- **Important** : don't change the installation folder
- Install other dependencies with the following command
```  
sudo apt install '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev libxkbcommon-dev libxkbcommon-x11-dev libyaml-cpp-dev 
```

## Run

- Download the release and execute the script agrorama.sh in the build folder


## Overview

The user interface lets you interact asynchronously with the drones, sending requests in the form of waypoints selected on a map, in order to adequately record the field from different points of view and ultimately reconstruct a 3D view of it and identify features of interest. After that, you can visualize the reconstructed orthomap on top of the map. The graphical interface is made of three main parts: the menu bar at the top (for projects and settings), the control panel on the left and, finally, the map.
![edit-mode](images/edit-mode.png)  

## Projects

When the program is launched, the API key for ArcGIS is requested. If it is correct, the main window with the map will be shown. Otherwise, the main window will still be shown, but the map will not be loaded.
The API key is saved in a file in the $arcgis$ folder, so that the next time the program is launched, the key is automatically retrieved from that file.

### New Project

To create a new project, click **Project** > **New** and fill in all the required information.

### Open Project

To open a project, click **Project** > **Open** and choose a YAML file to open.

### Settings

To change the information fields will populate the YAML file, click **Configure** > **Settings**.

## Map

It can be in two modes: normal mode or edit mode. In the latter, you can select the tiles to be used as waypoints for the drone. The controls in one mode are not choosable in the other mode.

### Normal mode

- <kbd>a</kbd> &rarr; rotate left
- <kbd>d</kbd> &rarr; rotate right
- <kbd>+</kbd> &rarr; zoom in
- <kbd>-</kbd> &rarr; zoom out
- You can also zoom in by using left and right double click of the mouse, respectively for zooming in and out, or also the mouse wheel/trackpad.
- You can jump to arbitrary coordinates (longitude latitude) by the top button

### Edit mode

- <kbd>left mouse click</kbd> &rarr; select a tile
- <kbd>right mouse click</kbd> &rarr; deselect a tile
- Slider on the right to increase (knob up) or decrease (knob down) the tile size.


## Control Panel

### Mission Planning

The right order of steps from the creation of a project to the generation of the orthomap is the following one:

1. Create a new project by selecting the file paths of your choice (or open an existing one)
2. (Optional) Load a KML file
3. Activate the Edit Mode
4. Select the desired tiles
   (**Disclaimer:** If you increase/decrease the tiles size while the edit mode is activated, the previous selected tiles will be deleted)
5. (Optional) Change settings
6. (Optional) Activate $use$ $cuda$ flag, clicking on **Options** > **use cuda**
7. Click **Generate** to generate CSV and YAML files
8. Click **Orthomap** to render images
9. Wait until the process is ended (during this process the GUI is locked and there is the following animation until the orthomaps are generated)

![waiting](images/crop.gif)


### Results Visualization

- Once the orthomap has been generated, it can be visualized on top of the map and also on top of the .kml layer. When clicking on the TIF button, the $output$ folder will be opened and the images can be selected. Only one tif at a time can be visualized on the map.
- The orthomap can also be colored, to show altitude features, through the switch
- Through the slider at the bottom, you can adjust the opacity of the .tif image, to check if the reconstruction is accurate based on the underlying data.


![tif-kml](https://github.com/Lab-RoCoCo-Sapienza/AGR-o-RAMA-GUI/assets/38572113/d03ce605-0221-413f-9319-47ea4a04bde4)

  


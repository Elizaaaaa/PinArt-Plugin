# Pin Art 

Plugin for Unreal 4.18.3

### Installing

Create a new Unreal project using C++ Basic Code templet.
It should also work with an existing Unreal C++ project.

Create a folder "Plugins" inside the project file.
Copy the whole PinArt folder and paste inside the Plugins folder.

```
MyUnrealProject/Plugins/PinArt
```
Build the Unreal project and open the Unreal Editor.
Close the Visual Studio.
File -> Refresh Visual Studio Project
File -> Open Visual Studio
Then close the Unreal Editor and press ctrl+f5 to build the Visual Studio project.
Now the Pin Art Plugin can be found at Window -> Pin Art

## Running the tests

Click Window -> Pin Art to open the plugin window.
Set values to parameters. For Example:

```
X Dimension : 40
Y Dimension : 40
Z Dimension : 30
Cylinder Radius : 20
Height Percent : 40
Spacing : 5

```
Then Click Build button to run it.
The cylinders will be created around position (0, 0, 0), please make sure there is nothing to block them.

## Authors

* **Eliza Zhang** 



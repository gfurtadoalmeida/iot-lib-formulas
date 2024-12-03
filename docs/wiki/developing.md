# Developing

## Building

### On VS Code

For a better experience it's highly recommended to install the [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) extension.

```ctrl+shif+p -> CMake Build```

### With the Provided Script

Run the ```project.ps1 generate``` then ```project.ps1 build``` commands on the root folder.

## Testing

### On VS Code

1. Build the project.
2. Run the project.

### With the Provided Script

All commands must be run on the test runner folder.  
Change the COM port to the one you're using.  

1. Build the project.
2. Run the ```project.ps1 test``` commands.

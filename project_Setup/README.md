



# **C++ Graphics Project Setup**  

## **Directory Structure**  

```cmd  
D:.
├───.vscode  
|___ File-to-copy
└───GraphicsProject  
    ├───bin  
    └───source  
```  

### Key Folders:  
- **`source`**: Contains all the C++ source files for your project.  
- **`bin`**: Contains the executable file generated after building the project.  
- **`.vscode`**: Includes `tasks.json` and `launch.json` for build and debug configurations.  

## **How to Build**  

1. Open the project folder in VS Code.  
2. Press **`Ctrl+Shift+B`** to run the build task.  
3. The executable file will be generated in the `bin` folder.  

## **Important Notes**  

- Ensure the `graphics.h`, `winbgim.h`, and `libbgi.a` files are correctly placed in the appropriate TDM-GCC folders (`include` and `lib`).  
- Modify `.vscode/tasks.json` and `.vscode/c_cpp_properties.json` to match your system's compiler path and configurations.  

Happy coding! 🚀  


**Moritat - Your Compiling Best Friend**

Moritat is a simple command-line tool designed to assist with compiling and running programs written in Ada, (kinda) Python, C, and C++. It aims to provide a user-friendly interface for common development tasks such as compilation and directory navigation.

### Features:

1. **Supported File Formats:**
   - Moritat supports Ada (.adb), Python (.py), C (.c), and C++ (.cpp) file formats.

2. **Compile and Run:**
   - The `compile` command allows you to compile and run programs based on their file extension.
   - For Ada files, Moritat uses `gnatmake` to compile and provides instructions for running the Ada project.
   - For Python files, Moritat suggests using `python` to run the script.
   - For C and C++ files, Moritat uses `gcc` for compilation and provides instructions for running the executable.

3. **List Files in Current Directory:**
   - The `ls` command lists all files in the current directory.

4. **Change Directory:**
   - The `cd` command allows you to change the current directory.

5. **Help Command:**
   - The `help` command displays a list of available commands and their usage.

6. **Exit:**
   - The `exit` command terminates the Moritat program.

### How to Use:

1. **Compile and Run:**
   - To compile and run a program, use the `compile` command followed by the file name.
     ```
     compile filename.adb
     ```

2. **List Files in Current Directory:**
   - To list files in the current directory, use the `ls` command.
     ```
     ls
     ```

3. **Change Directory:**
   - To change the current directory, use the `cd` command followed by the desired directory.
     ```
     cd /path/to/directory
     ```

4. **Display Help:**
   - To view a list of available commands and their usage, use the `help` command.
     ```
     help
     ```

5. **Exit Program:**
   - To exit Moritat, use the `exit` command.

### Supported Platforms:

Moritat is written in standard C and should work on various platforms with a C compiler and standard libraries. It has been tested on Linux Arch system.

### Building Moritat:

Moritat can be compiled using a standard C compiler such as `gcc`. No additional dependencies are required.

### Contributors:
Feel free to contribute to the project by submitting bug reports, feature requests, or pull requests on the GitHub repository.


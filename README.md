# Moritat - Ada Development Assistant

## Introduction
Welcome to Moritat, your Ada best friend! Moritat is a command-line tool designed to assist developers working with the Ada programming language. Ada is a statically typed, high-level programming language known for its reliability and safety features. While not as widely used as some other languages, Ada is especially popular in safety-critical systems, aerospace, and military applications.

Moritat aims to simplify and streamline the Ada development process, providing essential commands for compilation, file management, and project navigation. Whether you are a seasoned Ada developer or just starting with the language, Moritat can be a helpful companion in your Ada development journey.

## Getting Started

### Prerequisites
Before using Moritat, ensure you have the following installed on your system:
- Ada Compiler (GNAT)
- CMake

### Building Moritat
To build Moritat, follow these steps:

1. Clone the Moritat GitHub repository:
   ```bash
   git clone https://github.com/dominikstas/Moritat.git
   cd moritat
   ```

2. Create a build directory and navigate into it:
   ```bash
   mkdir build
   cd build
   ```

3. Generate build files using CMake:
   ```bash
   cmake ..
   ```

4. Build the Moritat executable:
   ```bash
   make
   ```

5. Run Moritat:
   ```bash
   ./moritat
   ```

## Features and Commands

### Welcome Message
Upon launching Moritat, you will be greeted with a welcome message indicating that Moritat is ready to assist you in your Ada development.

```plaintext
Welcome to Moritat - Your Ada best friend!
```

### Changing Directory
Moritat allows you to change the current working directory using the `cd` command. Simply provide the desired directory as an argument.

```plaintext
Moritat> cd /path/to/directory
```

### Listing Files
The `ls` command displays the files in the current working directory.

```plaintext
Moritat> ls
Files in current directory:
file1.adb
file2.adb
...

```

### Compiling Ada Files
Moritat provides a convenient way to compile Ada files using the `compile` command. Specify the Ada file you want to compile, and Moritat will handle the compilation process.

```plaintext
Moritat> compile filename.adb
```

Moritat checks for the `.adb` extension and uses the GNAT compiler to compile the specified Ada file. Upon successful compilation, Moritat provides instructions on how to run the compiled project.

### Help Command
The `help` command displays a list of available commands and their descriptions to assist you in using Moritat effectively.

```plaintext
Moritat> help
Available commands:
  compile <filename.adb> - Compile Ada file
  ls - List files in the current directory
  cd <directory> - Change current directory
  help - Display this help message
  exit - Exit Moritat
```

### Exiting Moritat
To exit Moritat, simply use the `exit` command.

```plaintext
Moritat> exit
```


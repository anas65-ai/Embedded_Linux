## Table of Contents:
  - **Libraries**
    - **Static Library**
      - ***How to create static library in C***
      - ***Example (Calculator Application)***
    - **Dynamic Library**
      - ***How to create dynamic library in C***
      - ***Example (Calculator Application)***
    - **The difference between Dynamic and Static Linking**
    - **References**
# Libraries 

A library is like a treasure trove of ready-made code, including functions, variables, and more. It's like a handy toolkit that programmers can use to save time and avoid redoing common tasks and instead of reinventing the wheel. Simply, there is a collection of pre-compiled code which forms a package called library. There are two types of libraries: 

## 1. Static Library 

It is a group of objects files (*.o) that link with the application during linking phase of build process.  The linker copies the code inside the library and merges it to main application to generate executable file and making the program self-contained and not dependent on external libraries at runtime.
![Untitled Diagram](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/4bb0dc7e-d6ee-458c-8b0f-7a68586b73e0)


### 1.1. How to create static library in C

- Select your compiler in my case **gcc**.
- Compile the source files and generate object files (*.o) but do not link them.

```c
gcc -c -Wall -Werror -Wextra *.c
```

> Let's explain the command: 
>
> - ***gcc***  specify your complier.
>
> - ***c***   flag tells the compiler to generate object files (.o) from the  source files (.c) without linking them. Object files contain compiled  code but are not yet executable. 
>
> - ***Wall***  flag enables a set of common warning messages. The "Wall" stands for "all Warnings".
>
> - ***Werror***  flag treats warning messages as errors. If the compiler encounters  any warnings, it will stop the compilation process and report an error to enforce the developer to follow the standard.
>
> - ***Wextra***  flag activates additional warning messages that are not included in the `-Wall` set.
>
>   > we can neglect -Wall, -Werror and Wextra flags but they are useful in compilation to enhance code quality  and improve the bugs.  
>   >
>   > ```
>   > gcc -c file.c
>   > ```
>   >
>   > or 
>   >
>   > ```
>   > gcc -c *.c  
>   > ```
>
> - **(*.c)** : this is a wildcard that specifies all C source files (`*.c`) in the current directory.

- Create static library by run this command: 

  ```c
  ar -rcs libName.a *.o		    
  ```

  or

  ```c
   ar -rcs libName.a file1.o file2.o file3.o  
  ```

  > We make archive file contains all object files of the functions to merges it with the main application 
  >
  > - **ar** :  archive command to create archive file.
  >
  > - **r**   :  insert or replace the object file if exist to the archive .
  >
  > - **c**   : create the archive file if not exist.
  >
  > - **s**   : add symbol table to the archive.
  >
  > - **libName.a**: the static library file  
  >
  >   > (**lib** for standard , **Name** is the name of static library, **a** stand for any static library)   
  >
  > - **(*.o)** : this is a wildcard that specifies all object files (`*.o`) in the current directory.
  >
  >   

- To show the object files (*.o) included in the library : 

  ```
  ar t libName.a
  ```

  

### 1.2. Example (Calculator Application)

- We have some functions that be used in the main program (add, sub, multi, div, mod).

- Create a directory and files for functions in any location on Home directory :

  ```
  mkdir calculator
  ```

  ```
  cd calculator
  touch main.c
  ```

  ```
  mkdir Lib_Src
  cd Lib_Src
  ```

  ```
  touch add.c sub.c multi.c div.c mod.c
  ```

  ```
  
  mkdir ~/calculator/includes
  cd includes
  ```

  ```
  touch add.h sub.h multi.h div.h mod.h
  ```

- The Project hierarchy becomes like that:
![Untitled Diagram(1)](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/858aadbd-13b3-47c7-90f6-268938aad333)


- You can open the file using vim and write the code

  ```
  vim file.c
  ```

  - ##### Addition function  (add.c , add.h)

    ```c
    /*This is the header file of addition function*/
    float add_fun(float Number1,float Number2); // function prototype (decleration)
    ```

    ```c
    /*This is the source file of addition function*/
    #include "add.h"
    float add_fun(float Number1,float Number2)
    {
    	return (Number1+Number2);
    }
    ```

  - Subtraction function (sub.c , sub.h).


  ```c
  /*This is the header file of subtraction function*/
  float sub_fun(float Number1,float Number2); // function prototype (decleration)
  ```

  ```c
  /*This is the source file of subtraction function*/
  #include "sub.h"
  float sub_fun(float Number1,float Number2)
  {
  	return (Number1-Number2);
  }
  ```

  - Division function (div.c , div.h).


  ```c
  /*This is the header file of division function*/
  float div_fun(float Number1,float Number2); // function prototype (decleration)
  ```

  ```c
  /*This is the source file of division function*/
  #include "div.h"
  float div_fun(float Number1,float Number2)
  {
  	return (Number1/Number2);
  }
  ```

  - Multiplication function (multi.c , multi.h).


  ```c
  /*This is the header file of multiplication function*/
  float multi_fun(float Number1,float Number2); // function prototype (decleration)
  ```

  ```c
  /*This is the source file of multiplication function*/
  #include "multi.h"
  float div_fun(float Number1,float Number2)
  {
  	return (Number1/Number2);
  }
  ```

  - Modulus function (mod.c , mod.h).


  ```c
  /*This is the header file of modulus function*/
  int mod_fun(int Number1,int Number2); // function prototype (decleration)
  ```

  ```c
  /*This is the source file of modulus function*/
  #include "mod.h"
  int mod_fun(int Number1,int Number2)
  {
  	return (Number1%Number2);
  }
  ```

- main function (main.c)

  ```c
  /*this is the main application (calculator)*/
  #include "includes/add.h"
  #include "includes/div.h"
  #include "includes/mod.h"
  #include "includes/multi.h"
  #include "includes/sub.h"
  #include <stdio.h>
  
  int main(void)
  {
    printf("Add operation 5 + 5  =  %f\n",add_fun(5,5));
    printf("Sub operation 10 - 5 =  %f\n",sub_fun(10,5));
    printf("Multi operation 4 * 4=  %f\n",multi_fun(4,4));
      
     return 0;
  }
  ```

  

- Let's compile the source files and generate object files: 

  ```
  cd ~/calculator/Lib_Src
  gcc -c -Wall -Werror -Wextra *.c
  ```
![Screenshot from 2023-12-27 18-39-12](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/58853cea-6792-484d-b568-2773dd5e9fef)


- Creating Static Library (its name **operation**) using the object files :

  ```
  ar -rcs liboperation.a *.o		    
  ```
![Screenshot from 2023-12-27 18-41-50](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/3821737f-37b3-4caf-8bac-b5489d7c8187)


- Show the object files included in the static library:
![Screenshot from 2023-12-27 18-45-56](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/f3d0ac5c-7885-49d4-97c3-9f9497ece1b5)


- Link the static library **(liboperation.a)** with the **main.c** to generate executable application. 

```
gcc -static main.c  -o Calculator -loperation -L./Lib_Src  -I ./includes
```

> - **static** flag	: to linking the library statically (we must use this flag because libraries linked 			    dynamically by default .
> - **-o Calculator** : the name of executable output.
> - **-l**(L small)        : specify the name of your library after **l** flag without the prefix "lib" and postfix "".a".
> - **-L** flag              : specify the path of the function source files of the library.
> - **-I** ( capital)     : specify the path of the header files of the library.
![Screenshot from 2023-12-27 19-11-00](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/769d45bf-8bb2-434d-94a5-ee6f425382b2)


- Run the application (Calculator)

![Screenshot from 2023-12-27 22-33-34](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/78aa128f-d85e-488c-8a48-140879a0fc98)



## 2. Dynamic Libraries

Dynamic libraries are  shared object files that contain functions, variables and so on.
The linking with the application occurs at runtime in the RAM, thanks to the dynamic loader. This system loader resolves symbols (references to functions or variables) dynamically, allowing the application to use the library's functionality.

![c++ - Is dynamic library necessary while compiling - Stack Overflow](https://i.stack.imgur.com/ZWg39.png)

### 2.1. How to make Dynamic Library

- Compile the source files and generate position independent object files (*.o)

  ```
  gcc -c -fPIC -Wall -Werror *.c
  ```

  >- ***c*** 	: compile and assemble but don't link.
  >- ***fPIC***   : Position Independent Code flag is a compiler options that generate code suitable for use in shared libraries ,PIC is a feature that allows a compiled library to be loaded into memory at any address. This is essential for shared libraries because the exact memory location where a library is loaded can vary between different programs and is determined at run time.
![Screenshot from 2023-12-27 23-56-23](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/4ce38dd5-d258-4045-853c-7ff38114a615)


- Create Dynamic Library using the object files (*.o)

  ```
  gcc -shared -o liboperation.so *.o
  ```

  > - **shared **       :  this option tells the linker to generate shared library instead of executable file.
  > - ***o***  flag          :  to specify the name of the library.
  > - **lib**                :  postfix to follow the standard.
  > - **operation** : the name of the shared library.
  > - **so**                : postfix stand for **shared object** .

![Screenshot from 2023-12-28 00-01-30](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/a46c5fea-a505-48c8-849d-a6d36977783f)

```
file liboperation.so
```
![Screenshot from 2023-12-28 00-40-59](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/9420aa0b-7a20-4215-a728-b00911001662)


- To show the symbol table of the shared library :

  ```
  objdump -T liboperation.so 
  ```
![Screenshot from 2023-12-28 00-24-07](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/77dbf14b-2ae6-4c2d-b5ff-2bcbc77ddf11)


- You need to  add the location of your dynamic library into the environmental variable **LD_LIBRARY_PATH** so the compiler knows where is  the object codes of the functions you use.

  ```
  export LD_LIBRARY_PATH= your/path/of/library
  ```

  > > Open the terminal in the directory of the dynamic library and run PWD, then copy the path and paste it in LD_LIBRARY_PATH

  - If you want to ensure that the current directory is always included in `LD_LIBRARY_PATH`, you can add the export command to your shell configuration file .

    ```
     vim ~/.bashrc
    ```

    - In the tail of the file write this : export LD_LIBRARY_PATH= your/path/of/library, then save.
![Screenshot from 2023-12-28 01-37-24](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/453de81c-498e-4537-b75c-cc3d4febae39)


    ```
    source ~/.bashrc
    ```

### 2.2. Example (Calculator Application)

- Link the dynamic Library with the  main.c (calculator):

  ```
  gcc main.c -o CalculatorDynamic -L ./Lib_Src -loperation -I ./includes
  ```

- Run the application (CalculatorDynamic)

```
./CalculatorDynamic
```
![Screenshot from 2023-12-28 01-41-58](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/df368cc5-0965-486e-9b04-0e42396849d5)

![Screenshot from 2023-12-28 01-44-33](https://github.com/anaskhamees/Embedded_Linux/assets/52020047/2ee1d836-6ee2-44b5-b27d-695ed0a8bfd4)



## 3. The difference between Dynamic and Static Linking



![Dynamic and Static Libraries in C | by Julija Lee | Medium](https://miro.medium.com/v2/resize:fit:628/1*pURY0S7FKaaGn-N_3AWFNw.png)




|               |                       Static Libraries                       |                      Dynamic Libraries                       |
| :-----------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
|   **Size**    | Object codes are bigger because including the actual code not an address | binary files is smaller because including the addresses of functions |
|  **Update**   | If there is any change in the code, it must be compile again |  The shared objects can be replaced without compiling again  |
|   **Time**    | It is faster because does not need additional time to load the library in run time |        consumes more time loading the shared objects         |
| **Execution** |           does not dependent on any external files           | dependent on the shared library, if not exist ,the execution fails |




![img](https://miro.medium.com/v2/resize:fit:700/1*R42c8GN6sltJY4hU-SqlWg.png)

## 4. References 

1. https://omaryahia4444.medium.com/static-library-vs-dynamic-library-210f740fc014
2. https://dev.to/iamkhalil42/all-you-need-to-know-about-c-static-libraries-1o0b
3. https://www.linkedin.com/pulse/dynamic-libraries-c-linux-agustin-flom/

**Hi, and welcome to explore ARM M4 architecture MCU, under the hardware provided by ST microelectronics the STM32F4 Discovery Board.!**

## **The following tools are required to be installed:** <br/>
  **ARM GNU toolchain to compile ARM based CPUs':** <br/>
  [ARM GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)<br/>
  **Editor of your preference: VSCode is used for this project** <br/>
    **[Hints]** Make sure to install extensions for compile arm based processors (CPP extension for VSCode)
            Map properly the toolchain path in the file: c_cpp_properties.jason
            As well as map preprocessor directives needed for compilation: STM32F407xx <br/>
  **GNU Make tools for build system:** <br/>
  [GNU Makefile tools](http://gnuwin32.sourceforge.net/packages/make.html) <br/>
  **Since GNU is a UNIX Based tool, the Makefile approach for build the project requires the CYGWIN installation:** <br/>
  [CYGWIN](https://www.cygwin.com/). <br/>
  Dont forget to map the corresponding envionment var!!!  <br/>
  **STM32CUBEProgrammer:** <br/>
  Allows us to download our sw image through stlink with the already built binary. <br/> Dont forget to map the corresponding envionment var!!!  <br/>
    **[makefile target]** In order to burned the SW into the chip, through the command line, we just need to type in the Build_sys directory level:<br/>
      Build_sys> make flash
    
  
  

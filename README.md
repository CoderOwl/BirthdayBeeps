# BirthdayBeeps
A c++ code playing the happy birthday tune using system beeps on Windows. Simultaneously, a message is typed on the window.

### Requisites
Windows, g++.

### How to run?
Download and compile `new.cpp` file on  Windows with g++ and run the exe file generated.

### Documentation
* The program uses  [`Beep(f, t)`](https://msdn.microsoft.com/en-us/library/windows/desktop/ms679277(v=vs.85).aspx) function available in `windows.h` to make a sound of frequency `f` for `t milliseconds`.  

* Instead of simply printing out a string on the window with `cout`, individual charactars are typed separately and [`Sleep()`](https://msdn.microsoft.com/en-us/library/windows/desktop/ms686298(v=vs.85).aspx) is used after each of them to create the illusion of typing. 

* To avoid the `Sleep()` usage creating holes in the tune, the typing of each message string is run on different [threads in Windows]( https://msdn.microsoft.com/en-us/library/windows/desktop/ms682516(v=vs.85).aspx ).  

### Development
The tune isn't perfect.

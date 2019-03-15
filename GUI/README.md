# QT_GUI Implementation 

* This is the GUI implementation process of my project. 
* My codes are divided into two parts in QT, core and gui versions. 

## Learning process for QT_GUI part 
* **QTile** class is inherited both from the Tile class and the QLabel class because after reading the links, I figured out that QLabel class is the most suitable one 
    > https://doc.qt.io/archives/qt-4.8/qlabel.html 
    > https://doc.qt.io/archives/qt-4.8/stylesheet-examples.html
    > https://www.mobileread.com/forums/showthread.php?t=224605

    Moreover, I gained ideas about how to change colors of these tiles, but they were still not working. However, I decided to first implement other parts and then go back to fix the error.

* Start to implement **QGamebaord** class, **STUCK** for really a long time because I cannot find the logic in my implementation
    * Every time I move the board, several checks should be done at the same time, including whether it is full, the player has won, or just draw the board again. 
    * Thinking about the implementing in the main function, but as it is a QT project, the main function should also deal with the window->show thing, and I don’t want to mess my algorithms up. 
    * Also, I remembered earlier that my pic 10b professor said that the advanced version of programming is to implement almost everything in class, but not in the main function. 
    * So I searched online for ways to implement and also asked TA for help. 
    * **Finally**, I figured out that I could implement my project with Observer and Subject pattern, which allowed me to deal with the one-to-many dependency relation. Following are the links that TA suggested or I searched online. 
    > https://en.wikipedia.org/wiki/Observer_pattern
    > https://www.geeksforgeeks.org/observer-pattern-set-1-introduction/
    > https://www.oodesign.com/observer-pattern.html
    
    I added two more classes for this patter, subject and observer.
    
* Learn about **QT-related tools** 
    * Research and compare different layouts to find the most suitable for matrix and overall windows
    * Choose grid layout for the matrix
    > https://doc.qt.io/archives/qt-4.8/qgridlayout.html
    > https://doc.qt.io/archives/qt-4.8/qt-tutorials-widgets-windowlayout-example.html
    * Learn the keyboard press event, namely how to connect keyboard signals to the movements
    > https://stackoverflow.com/questions/23137187/qt-is-there-a-way-to-emit-a-signal-when-a-particular-key-is-typed

* **Debugging proces**
    * **Stuck** for a long time when try to compile due to the error: 
    non-virtual thunk to <method name>”, referenced from: Vtable for <classname>in <objectfile.o>
        * Looked online, the error should be that I didn’t implement all the member functions defined in the header files. 
        * Although the error is trivial, but when examining the code, I figured out that I didn’t implement the big four for the board class, which deals with heap memory management. 
    * **Stuck** for another long time 
        * though the program works, it doesn’t work in the way 2048 should work, which means LEFT and RIGHT are not the right pattern, but UP and DOWN are. 
        * Confused because UP and DOWN were built based on LEFT and RIGHT 
        * So, there must be something wrong with the keyboard press 
        * After using the debugging tools that I discovered in the core implementation process, I **figured out** the problem is because I used if instead of else if, which may caused double actions
    * Now after searching more online about setstylesheet, I can show my game **in color**. 
        * But one more thing is left with the game over window. The program didn’t pop up the window, but quited unexpectedly. 
        * Reading the report, figured out there is something wrong with the random function, when there is only one position left, the random function doesn’t work, therefore, the program quits and the pop up window doesn’t show up.

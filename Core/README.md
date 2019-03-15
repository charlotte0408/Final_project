# QT_CORE Implementation 

* This is the Core implementation process of my project. 

## Learning process for QT_Core part 
* Starting from implementing the **Tile**
    * These two classes are easy because tile is a class with a private data field: int and qtile inherits from the tile class by adding a draw function
    * Implement the board class: The most essential one and it is the class where the core algorithm lives
    * **QVector** 
        * Choose between Vector class and QVector class 
        * It is a difference between STL and QTL 
        > https://web.archive.org/web/20160902015144/http://blog.codeimproved.net/posts/qtl-stl.html
        * The above link suggested QTL because QTL can perform all the functions supported by QT because after all it is a program in QT environment. 
        > https://doc.qt.io/qt-5/qvector.html
        * From the above documenation I learned the qvector 
    * Implement the **general move** function
        * I learned the use of keyword enum to make the codes more neat when handling the move directions. 
        > https://en.cppreference.com/w/cpp/language/enum
        * In class, we talked about private member class (that node class is implement as a private member field in list class), and I was thinking about whether I could implement private member functions. The reason I want to do this because the actual LEFT, RIGHT, UP, DOWN functions do not need to accessible by the public, but only the helper function move should be accessible to other classes
        > https://stackoverflow.com/questions/4505938/when-why-to-make-function-private-in-class
        * Able to implement private member functions and make the implementation safer
   
     * The other functions are the **same** as those implemented in the c++ core algorithm 

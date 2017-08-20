# ACJudge
A Complex Judge, designed for ACOJ.  
Currently it's Linux only. But it will soon be available on Windows.  
Mac? Huh? What are you talking about?  
   
This project will support ANSI C no more. Now it is **C++1x only**.  

### [Judge]
Scoring users' submissions.  
With ACPL script, problem designers can set their own, unique judging procedure. (Comming soon!)

### [Sandbox]
The warden that protects the system from being damaged by user codes.  
The executable file should (better) be in folder "Container/XXX", while XXX is the name of the Sandbox object.

### [Supports]
Including /*database, */ network, file and management interfaces.  
// Database interface will get queueing submissions from database, send them to the judge, collect the results and restore to databse.  
// **↑No, there is no more database!! :(**
Network interface can fetch submissions from ACOJ Web Server, and return the results back.
File interface will prepare data, source code and things like that for the judge.  
Management interface is the connection between web server (script) and judge.  
When ACOJ Server is started, this module will be automatically started, but without it, the judge can also be used offline.  
  
-----------------------

## Update

**[ACJudge 1.4] Link Start**  
ACJudge Online is OK!  
You only need a mysql DBMS to make it run.  
Maybe you also want a web server (classic ones like Apache or lovely ones like nodejs).   

## License

**GPL v3.**
To avoid disputes, the license of this program was switched to GPL.  
Notice that WTFPL is not in use anymore!!!!!  
  
Thanks to [QingDaoU](https://github.com/QingdaoU/Judger) for offering such a sample of sandbox on Linux!  
Thanks to [ContestHunter](https://contesthunter.org) for default comparer!
Thanks to [mrtazz](https://github.com/mrtazz/restclient-cpp) for http clients!
Thanks to [rapidjson](https://github.com/miloyip/rapidjson/) for JSON loader!
*ContestHunter is OK now! Awesome!*
  
-----------------------

## Build & Run

### For Linux User:

Before build, please make sure you have installed libseccomp, as it is the main part of the sandbox. You may have to install autoconf, automake and libtool first, then follow the instructions here: https://github.com/seccomp/libseccomp.  
You need libperl and restclient-cpp for HTTP, and rapidjson for JSON read/write.
Finally, after switching to the direction where the project is placed, follow these steps:  

```
    # build default compairer
    cd Container
    make
    make clean
    cd ..
    # build main part
    make
    make clean
    cd Release
    # run
    ./acjudge
```
  
If it shows the usage of the program...  
Voila! You've done it!  

### For Windows User:

You may straightly switch to /Release/ folder (for the code has already been built) and run ACJudge.exe!  
Solution for MS - Visual Studio 2015 is in folder Visual studio. You may need this if you wish to deal some changes.  
Before building, you should edit /Definations/platform.h to switch the platform, that is, from
    
    // #define WINDOWS
    #define _NIX

to

    #define WINDOWS
    // #define _NIX 

Tip: The pronounciation of word "Windows" is similar with "Wen Dao Si" in Chinese, which means "Plague to Death".   

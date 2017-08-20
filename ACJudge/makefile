objs = Sandbox/sandbox.o Support/filesys.o Judge/judge.o Judge/oijudge.o Judge/acmjudge.o Main/main.o
CPPFLAGS = -s -O2 -Wall -Wextra -std=c++11 -I/usr/include/mysql -I/usr/include -I/usr/local/boost_1_64_0
Release/acjudge : $(objs)
	g++ -o Release/offline $(objs) -lseccomp
clean:
	rm $(objs)
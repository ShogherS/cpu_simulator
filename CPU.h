Last login: Mon Sep 11 11:34:45 on ttys002
sh@Ss-MacBook-Air ~ % pwd
/Users/sh
sh@Ss-MacBook-Air ~ % ls -a 
.					.zprofile
..					.zsh_history
.CFUserTextEncoding			.zsh_sessions
.DS_Store				.zshrc
.Trash					Desktop
.bash_history				Documents
.bash_profile				Downloads
.bashrc					Library
.lesshst				Movies
.oh-my-zsh				Music
.viminfo				Pictures
.vimrc					Public
.zcompdump-S’s MacBook Air-5.9
sh@Ss-MacBook-Air ~ % cd Documents/CPU
sh@Ss-MacBook-Air CPU % ls -a
.		.git		code.txt	main.cpp
..		CPU.h		instructions.h	registers.h
sh@Ss-MacBook-Air CPU % git add .
sh@Ss-MacBook-Air CPU % git status
On branch main
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	new file:   main.cpp

sh@Ss-MacBook-Air CPU % git pull
There is no tracking information for the current branch.
Please specify which branch you want to merge with.
See git-pull(1) for details.

    git pull <remote> <branch>

If you wish to set tracking information for this branch you can do so with:

    git branch --set-upstream-to=origin/<branch> main

sh@Ss-MacBook-Air CPU % git pull main
fatal: 'main' does not appear to be a git repository
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
sh@Ss-MacBook-Air CPU % git pull remote main
fatal: 'remote' does not appear to be a git repository
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
sh@Ss-MacBook-Air CPU % git pull --help     
Unknown locale, assuming C
sh@Ss-MacBook-Air CPU % 
sh@Ss-MacBook-Air CPU % git add .
sh@Ss-MacBook-Air CPU % gir status
zsh: command not found: gir
sh@Ss-MacBook-Air CPU % git status
On branch main
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	new file:   main.cpp

sh@Ss-MacBook-Air CPU % git add . 
sh@Ss-MacBook-Air CPU % git status
On branch main
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	new file:   main.cpp

sh@Ss-MacBook-Air CPU % git restore --staged main.cpp
sh@Ss-MacBook-Air CPU % git status
On branch main
Untracked files:
  (use "git add <file>..." to include in what will be committed)
	main.cpp

nothing added to commit but untracked files present (use "git add" to track)
sh@Ss-MacBook-Air CPU % git add
Nothing specified, nothing added.
hint: Maybe you wanted to say 'git add .'?
hint: Turn this message off by running
hint: "git config advice.addEmptyPathspec false"
sh@Ss-MacBook-Air CPU % git add .
sh@Ss-MacBook-Air CPU % git status
On branch main
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	new file:   main.cpp

sh@Ss-MacBook-Air CPU % ls -a
.		.git		code.txt	main.cpp
..		CPU.h		instructions.h	registers.h
sh@Ss-MacBook-Air CPU % git commit -m main
[main 05d9504] main
 Committer: S H <sh@Ss-MacBook-Air.local>
Your name and email address were configured automatically based
on your username and hostname. Please check that they are accurate.
You can suppress this message by setting them explicitly. Run the
following command and follow the instructions in your editor to edit
your configuration file:

    git config --global --edit

After doing this, you may fix the identity used for this commit with:

    git commit --amend --reset-author

 1 file changed, 19 insertions(+)
 create mode 100644 main.cpp
sh@Ss-MacBook-Air CPU % git restore --staged main.cpp
sh@Ss-MacBook-Air CPU % git status
On branch main
nothing to commit, working tree clean
sh@Ss-MacBook-Air CPU % git reset                    
sh@Ss-MacBook-Air CPU % git status
On branch main
nothing to commit, working tree clean
sh@Ss-MacBook-Air CPU % git add .
sh@Ss-MacBook-Air CPU % git status
On branch main
nothing to commit, working tree clean
sh@Ss-MacBook-Air CPU % git reset 
sh@Ss-MacBook-Air CPU % git status
On branch main
nothing to commit, working tree clean
sh@Ss-MacBook-Air CPU % git add .
sh@Ss-MacBook-Air CPU % git status
On branch main
nothing to commit, working tree clean
sh@Ss-MacBook-Air CPU % git branch
* main
sh@Ss-MacBook-Air CPU % ls
CPU.h		code.txt	instructions.h	main.cpp	registers.h
sh@Ss-MacBook-Air CPU % cd ..
sh@Ss-MacBook-Air Documents % mkdir CPU_2
sh@Ss-MacBook-Air Documents % cd CPU_2 
sh@Ss-MacBook-Air CPU_2 % cd ..
sh@Ss-MacBook-Air Documents % cd C'
quote> 
sh@Ss-MacBook-Air Documents % cd CPU
sh@Ss-MacBook-Air CPU % ls
CPU.h		code.txt	instructions.h	main.cpp	registers.h
sh@Ss-MacBook-Air CPU % git init
Initialized empty Git repository in /Users/sh/Documents/CPU/.git/
sh@Ss-MacBook-Air CPU % vim CPU.h 

  1 #ifndef CPU_H
  2 #define CPU_H
  3 #include <map>
  4 #include <string>
  5 #include <fstream>
  6 #include <stdexcept>
  7 #include <sstream>
  8 
  9 #include "instructions.h"
 10 #include "registers.h"
 11 
 12 class CPU
 13 {
 14         public:
 15         void decode();                                  //excecutes the current program counters     instructions
 16         void excecute();                                //excecutes the entire assembly code
 17         void print();                                   //The current state of memory and regist    ers     
 18         void fetch(const std::string&);                 //Loades the code from the file to the m    emory   
 19         private:
 20         Registers registers;                            // registers
 21         std::vector<std::vector<std::string>> data;     //an instance of Instructions class, it     containss all the instructions  
 22         Instructions instructions;                      //instructions set
 23         std::map<std::string, int> lables;              //lables for jump
 24         bool isRegister(const std::string&);            //helper functions checkes if the input     is registers name
    @                                                                                               
CPU.h [+]                                                                                           
"CPU.h" 161L, 4698B

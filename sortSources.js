'use strict'

let obj = {
  "books": [
    "Фейнмановские лекции по физике 4",
    "Operating System Concepts 2",
    "Systems Performance: Enterprise and the Cloud 3",
    "Командная строка Linux. Полное руководство - Уильям Шоттс 1",
    "Linux. Системное программирование - Роберт Лав 3",
    "Bash. Карманный справочник системного администратора - Арнольд Роббинс 3",
    "Linux глазами хакера - Михаил Фленов 2",
    "Computer Networks - Andrew S. Tanenbaum, David J. Wetherall 1",
    "DNS and BIND - Cricket Liu, Paul Albitz 1",
    "Applied Cryptography: Protocols, Algorithms, and Source Code in C - Bruce Schneier 2",
    "OpenSSH, PuTTY, Tunnels and Keys - Michael W. Lucas 2",
    "SSH, The Secure Shell - Daniel J. Barrett, Richard E. Silverman, Robert G. Byrnes 2",
    "Implementing SSL/TLS Using Cryptography and PKI - Davie 2",
    "Unix Network Programming, Volume 1 - W. Richard Stephens, Bill Fenner, Andrew M. Rudoff 2",
    "Unix Shell Programming - Stephen G. Kochan 3",
    "The UNIX Programming Environment - Bran W. Kernighan, Rob Pike 3",
    "Using Samba 3",
    "The C Programming Language - Brian W. Kernighan, Dennis M. Ritchie 1",
    "Linkers and Loaders - John R. Levine 2",
    "Debugging with GDB - Richard M. Stallman 3",
    "The Art of Debugging - Norman Matloff, Peter Jay Salzma 2",
    "Python Essential Reference - David M. Beazley 3",
    "Learning Perl - Randal L. Schwartz, Brian D. Foy, Tom Phoenix 3",
    "Modern Perl - Chromatic 3",
    "The Art of R Programming - Norman Matloff 3",
    "Compilers: Principles, Techniques and Tools - Alfred V. Aho 2",
    "Modern Compiler Design - Dick Grune 2",
    "Autotools - John Calcote 2"
  ],
  "articles": [
    "The Inside Story on Shared Libraries and Dynamic Loading - David M. Beazley, Brian D. Ward, Ian R. Cooke 3"
  ],
  "sites": [
    "http://dwheeler.com/program-library/ - Program Library HOWTO 2",
    "http://valgrind.org/ - выявление проблем в памяти и запуск профильных тестов 2",
    "http://llvm.org/ 2",
    "http://www.sans.org/ - безопасность 1",
    "http://www.cert.org/ - безопасность 1",
    "http://www.insecure.org/ - безопасность 1"
  ]
}

for (let key of Object.keys(obj)) {
  obj[key] = obj[key].sort((a, b) => a[a.length - 1] - b[b.length - 1]);
}


console.log(obj);

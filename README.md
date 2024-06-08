CVE-2024-4577 PoC Exploit
This project contains a Proof of Concept (PoC) exploit for CVE-2024-4577. It demonstrates a vulnerability exploitation technique using crafted PHP code to execute arbitrary commands on vulnerable targets.

Description
The exploit leverages a vulnerability that allows for remote code execution (RCE) on affected systems. By sending specially crafted requests to a target, an attacker can execute arbitrary code. This PoC specifically demonstrates how to trigger the vulnerability and execute a command (calc) on the target system.

Versions vulnerable
- PHP 8.3 < 8.3.8
- PHP 8.2 < 8.2.20
- PHP 8.1 < 8.1.29

Installation
1.
Install libcurl: Ensure that you have the libcurl development package installed on your system. This can typically be done through your system's package manager. For example, on Ubuntu, you can install it by running:
sudo apt-get install libcurl4-openssl-dev
2.
Compile the Code: Navigate to the directory containing the exploit code and compile it using a C++ compiler. For example, using g++:
g++ -o exploit PHP-RCE-4577.cpp -lcurl

Replace exploit.cpp with the actual name of the source file if different.


Usage
To use the exploit, you need to provide a target list file and the PHP code to execute as command-line arguments:
./exploit --target-list targets.txt -c "<?php system('calc')?>"

--target-list targets.txt: Specifies the file containing a list of targets, one per line.
-c "<?php system('calc')?>': The PHP code to be executed on the target system. In this example, it attempts to open the calculator application.

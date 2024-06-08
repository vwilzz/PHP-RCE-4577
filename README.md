CVE-2024-4577 PoC Exploit
Welcome to the official repository for the CVE-2024-4577 Proof of Concept (PoC) exploit. This project showcases a sophisticated vulnerability exploitation technique that leverages crafted PHP code to execute arbitrary commands on systems vulnerable to CVE-2024-4577.

📜 Description
This exploit takes advantage of a critical vulnerability allowing for Remote Code Execution (RCE) on affected systems. By dispatching specially crafted requests, an attacker can execute arbitrary code on the target system. This PoC is designed to demonstrate the process of triggering the vulnerability and executing a command (calc) on the target system, showcasing the potential severity of the exploit.

🚨 Versions Vulnerable
PHP 8.3 < 8.3.8
PHP 8.2 < 8.2.20
PHP 8.1 < 8.1.29


🛠 Installation
Step 1: Install libcurl
Ensure the libcurl development package is installed on your system. This is a prerequisite for compiling the exploit code. Installation can typically be done through your system's package manager. For Ubuntu:
sudo apt-get install libcurl4-openssl-dev

Step 2: Compile the Code
Navigate to the directory containing the exploit code. Compile the code using a C++ compiler, such as g++:
g++ -o exploit PHP-RCE-4577.cpp -lcurl

Note: Replace `PHP-RCE-4577.cpp` with the actual name of your source file.

📖 Usage
To deploy the exploit, you must provide a target list file and the PHP code to execute as command-line arguments:
./exploit --target-list targets.txt -c "<?php system('calc')?>"

--target-list targets.txt: Specifies the path to the file containing a list of targets, one per line.
-c "<?php system('calc')?>": The PHP code to be executed on the target system. This example attempts to open the calculator application on the target machine.


⚠️ Disclaimer
This tool is designed for educational and ethical testing purposes only. Any use of this software for illegal activities is strictly prohibited. The developer assumes no liability for misuse or damage caused by this program.

🤝 Contributing
Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated. Please ensure your contributions adhere to ethical guidelines and project goals.

📄 License
Distributed under the MIT License. See LICENSE for more information.

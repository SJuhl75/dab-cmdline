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

// External mutex declaration
extern std::mutex data_mutex;

// Hand-over output of Reed-Solomon decoding from main.cpp
void ssrz_listener(std::vector<uint8_t> buffer) {
    std::lock_guard<std::mutex> lock(data_mutex);  // Ensure thread-safety
    std::cout << "ssrz_listener::in[" << buffer.size() << "]" << std::endl;
    // Add your specific data handling logic here
}

#pragma once

#include <chrono>		// getting current time
#include <iostream>
#include <format>		// time formatting

class Timer
{
public:
    // Starts a timer
    // must call stopTimer after using start
    void startTimer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    // stops the timer
    void stopTimer()
    {
        end = std::chrono::high_resolution_clock::now();
    }

    // outputs time taken in microseconds
    void outputTimeTaken()
    {
        std::cout << "took " << duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << "\n\n";
    }

    // For log messages with timestamps
    std::string getCurrentTime() {
        const auto timeUTC = std::chrono::system_clock::now();
        const auto localTime = std::chrono::current_zone()->to_local(timeUTC);

        return std::format("[{:%Y-%m-%d %X}]", localTime);
    }

private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
};
//============================================================================
// Name        : vinson_concurrency_counter.cpp
// Author      : David Vinson
// Description : Program initiates 2 distinct threads, one for each separate
//				 function, one to cycle through a loop counting up from 1 to
//				 20, and the other to count back down from 20 to 1. The count
//				 down function also has coding to lock down the thread until
//				 the first thread is completed before starting its loop.
// Date Created: 08-30-2025
//============================================================================

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool firstDone = false;  // Flag to signal when thread 1 is finished

// Thread 1: Count up from 1 to 20
void countUp() {
    for (int i = 1; i <= 20; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulate work
        std::cout << "Thread 1 (count up): " << i << std::endl;
    }

    // Signal that Thread 1 is finished
    {
        std::lock_guard<std::mutex> lock(mtx);
        firstDone = true;
    }
    cv.notify_one();
}

// Thread 2: Count down from 20 to 0
void countDown() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return firstDone; }); // Wait until thread 1 is done

    for (int i = 20; i >= 0; i--) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Thread 2 (count down): " << i << std::endl;
    }
}

int main() {
    std::thread t1(countUp);
    std::thread t2(countDown);

    t1.join();
    t2.join();

    std::cout << "Both threads finished execution." << std::endl;
    return 0;
}




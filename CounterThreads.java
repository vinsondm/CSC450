//============================================================================
// Name        : CounterThreads.java
// Author      : David Vinson
// Description : Program initiates 2 distinct threads, one for each separate
//				 function, one to cycle through a loop counting up from 1 to
//				 20, and the other to count back down from 20 to 1. The count
//				 down function also has coding to lock down the thread until
//				 the first thread is completed before starting its loop.
// Date Created: 09-06-2025
//============================================================================

package vinson_CSC450_PortfolioProject;

public class CounterThreads {

	public static void main(String[] args) {
		 // Thread 1: Counts up from 1 to 20
        Thread countUp = new Thread(() -> {
            for (int i = 1; i <= 20; i++) {
                System.out.println("Count Up: " + i);
                try {
                    Thread.sleep(200); // pause to simulate work
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        });

        // Thread 2: Counts down from 20 to 0
        Thread countDown = new Thread(() -> {
            for (int i = 20; i >= 0; i--) {
                System.out.println("Count Down: " + i);
                try {
                    Thread.sleep(200); // pause to simulate work
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        });

        try {
            // Start first thread
            countUp.start();
            // Wait for it to finish before starting the second
            countUp.join();
            // Start second thread
            countDown.start();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
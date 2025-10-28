#include <stdio.h>
#include <time.h>

// Include appropriate sleep function header based on the OS
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

// Function to pause execution for a second
void delay_one_second() {
    #ifdef _WIN32
        Sleep(1000); // Windows uses Sleep() in milliseconds
    #else
        sleep(1);    // Unix/Linux/macOS uses sleep() in seconds
    #endif
}

int main() {
    time_t current_time_sec;
    struct tm *local_time;
    
    printf("--- Console Digital Clock ---\n");

    while (1) {
        // 1. Get the current time in seconds since the Epoch
        current_time_sec = time(NULL);

        // 2. Convert the raw time to local time structure
        local_time = localtime(&current_time_sec);

        // 3. Clear the previous time display (using an ANSI escape sequence)
        // \r moves the cursor to the beginning of the line.
        printf("\r");
        
        // 4. Print the formatted time (HH:MM:SS)
        // %02d ensures two digits are displayed, padded with a leading zero if needed.
        printf("Current Time: %02d:%02d:%02d",
               local_time->tm_hour,      // Hours (0-23)
               local_time->tm_min,       // Minutes (0-59)
               local_time->tm_sec);      // Seconds (0-59)

        // 5. Force the output buffer to be written to the screen
        fflush(stdout);

        // 6. Wait for one second before updating the display
        delay_one_second();
    }
    
    return 0; 
}

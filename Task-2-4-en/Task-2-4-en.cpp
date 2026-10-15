#include <iostream>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
    // Maximum length of a sequence
    // where each wave is longer than the previous one
	unsigned int max_len = 0;
    // Current length of a sequence
    // where each wave is longer than the previous one
    unsigned int current_len = 0;
    unsigned int prev_wave = 0; // Previous value in the input data sequence.
    bool b_done = false; // Flag to control the loop execution.
    // Data input
    std::cout << "Enter weather station data (0 to end input).\r\n";
    while (!b_done)  // Start of the loop
    {
        unsigned int wave; // Variable for data
        std::cin >> wave; // Input a new data value
        b_done = (wave == 0); // Loop termination condition: inputting 0
        if (current_len == 0)
        {
            current_len = 1; // Initialize length counter to 1
        }
        // If the current wave is longer than the previous one
        else if (wave > prev_wave)
        {
            current_len += 1; // Increment the sequence length counter
        }
        else
        {
            if (current_len > max_len)  // Otherwise, calculate
            {
                max_len = current_len; // the maximum sequence length
            }
            // Reset length counter to 1
            // and reset the counter for the current segment length
            current_len = 1;
        }
        prev_wave = wave; // Replace the previous value with the new one
    }
    // Maximum length of a segment
    // where each wave is longer than the preceding one. Final answer
    if (current_len > max_len)
    {
        max_len = current_len;
    }
    std::cout << "Maximum segment length: " << max_len;
    // Pause the output until the "Enter" key is pressed
    std::cin.ignore();
    std::cin.get();
    return 0;
}

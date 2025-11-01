#include "game.hpp"
#include <exception>
#include <iostream>

int main()
{
    Game mne16ksta; // Its normal!
    try { mne16ksta.Start(); }
    catch (std::exception& err_) { std::cout << err_.what() << '\n'; return 1; }
    return 0;
}
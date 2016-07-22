#include <string>
#include <iostream>

void UpdateStatus(std::string update)
{
  std::cout << update << "\n";
}

void ShowTitleScreen()
{
  std::string title = "==============================\n     Game Engine Prototype\n==============================\n";
  std::cout << title;
}

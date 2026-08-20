#ifndef CONSOLE_HPP
#define CONSOLE_HPP

void ClearScreen();
void ShowMenu();
void Pause();
void EndProgram();

int Read_Option();
long double Read_Number(const char* message);

#endif
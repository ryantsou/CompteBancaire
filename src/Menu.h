#ifndef MENU_H
#define MENU_H

#include <string>
class Banque;

void menuClient(Banque& banque, const std::string& numeroCompte, const std::string& loginClient);

#endif

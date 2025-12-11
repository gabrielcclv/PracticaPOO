#include "journal.hpp"
#include <iostream>

using namespace std;

string Journal::info() const {
  return "Journal (ID: " + to_string(id) + "): " + titulo + " by " + autor +
         ", Genre: " + genero + ", Year: " + to_string(year) +
         ", Editorial: " + editorial + ", ISSN: " + to_string(issn);
}

void Journal::printJournal() {
 cout << info() << endl;
}

int Journal::getIssn() {
  return issn;
}
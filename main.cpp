#include <iostream>
#include <string>

using namespace std;

int GetNumOfNonWSCharacters(string input) {
   unsigned int i;
   int numChars;
   numChars = 0;

   for (i = 0; i < input.size(); ++i) {
      if (input.at(i) != ' ') {
         ++numChars;
      }
   }

   return numChars;
}

int GetNumOfWords(string input) {
   unsigned int i;
   int numWords;
   numWords = 1;

   for (i = 0; i < input.size(); ++i) {
      if (input.at(i) == ' ' && input.at(i + 1) != ' ') {
         ++numWords;
      }
   }
   return numWords;
}

int FindText(string desiredWord, string userText) {
   unsigned int i;
   unsigned int j;
   int occurances;
   occurances = 0;
   j = 0;

   for (i = 0; i < userText.size(); ++i) {
      if (userText.at(i) == desiredWord.at(j)) {
         ++j;
         if (j == desiredWord.size()) {
            ++occurances;
            j = 0;
         }
      }
      else {
         j = 0;
      }
   }
   return occurances;
}

void ReplaceExclamation(string& input) {
   unsigned int i;
   for (i = 0; i < input.size(); ++i) {
      if (input.at(i) == '!') {
         input.at(i) = '.';
      }
   }
}

void ShortenSpace(string& input) {
   int i;
   string newSentence;
   newSentence = "";
   for (i = 0; i < input.size(); ++i) {
      if ((input.at(i) == ' ') && (input.at(i + 1) == ' ')) {
         continue;
      }
      else {
         newSentence.push_back(input.at(i));
      }
   }
   input = newSentence;
}

void PrintMenu(string userText) {
   string userChoice;

   while (userChoice != "q") {
      cout << "MENU" << endl;
      cout << "c - Number of non-whitespace characters" << endl;
      cout << "w - Number of words" << endl;
      cout << "f - Find text" << endl;
      cout << "r - Replace all !'s" << endl;
      cout << "s - Shorten spaces" << endl;
      cout << "q - Quit" << endl << endl;
      cout << "Choose an option:" << endl;
      cin >> userChoice;

      if (userChoice == "q") {
         break;
      }
      else if (userChoice == "c") {
         cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(userText) << endl << endl;
      }
      else if (userChoice == "w") {
         cout << "Number of words: " << GetNumOfWords(userText) << endl << endl;
      }
      else if (userChoice == "f") {
         cin.ignore();
         cout << "Enter a word or phrase to be found:" << endl;
         string desiredText;
         getline(cin, desiredText);
         cout << "\"" << desiredText << "\" instances: " << FindText(desiredText, userText) << endl << endl;
      }
      else if (userChoice == "r") {
         ReplaceExclamation(userText);
         cout << "Edited text: " << userText << endl << endl;
      }
      else if (userChoice == "s") {
         ShortenSpace(userText);
         cout << "Edited text: " << userText << endl << endl;
      }
   }
}

int main() {
   string originalSentence;
   string userChoice;

   cout << "Enter a sample text:" << endl;
   getline(cin, originalSentence);
   cout << endl;
   cout << "You entered: " << originalSentence << endl;
   cout << endl;
   PrintMenu(originalSentence);

   return 0;
}

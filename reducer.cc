#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace rapidjson;
using namespace std;

int main(int argc, char const *argv[]) {
  string line;
  string old = "";
  int count = 0;
  while (!cin.eof()) {
    getline(cin,line);
    if (!cin.fail()) {
      istringstream in(line);
      string tag;
      int c;
      in >> tag;
      in >> c;

      // set old-tag to current tag
      if (old.length() == 0) {
        old = tag;
      }

      // done reducing common tags
      // output reduced tag and count + reinitalize
      if (old != tag) {
        cout << old << "\t" << count << endl;
        old = tag;
        count = c;
      } else {
        count += c;
      }
    }
  }
  if (old.length() != 0) {
    cout << old << "\t" << count << endl;
  }

}

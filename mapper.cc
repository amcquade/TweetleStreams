// Aaron McQuade
// Tweetle-streams
// mapper.cc


#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <string>
#include <sstream>
#include <locale>
#include <algorithm>
#include <vector>
using namespace rapidjson;
using namespace std;

char easytolower(char in);

int main(int argc, char const *argv[]) {
  bool ignoreCase = false;
  vector<string> search_terms;
  string search_term;

  // default option - case sensitive
  if(argc == 2){
    search_term = argv[1];
  }else if(argc == 3){
    search_term = argv[2];
    string c = argv[1];
    char cmd = c[1];
    if(cmd == 'I') ignoreCase = true;
  }else{
    cout << "incorrect number of arguments" << endl;
    return 0;
  }

  // split up search terms into vector
  istringstream in(search_term);
  string word;
  int i = 0;
  while(!in.eof()){
    in >> word;
    if(!in.fail()){
      // make search terms lowercase too
      if(ignoreCase){
        std::transform(word.begin(), word.end(), word.begin(), easytolower);
      }
      search_terms.push_back(word);
      ++i;
    }
  }
  search_terms.resize(i);

  // read tweet
  while (!cin.eof()) {
    string line;
    getline(cin,line);
    if (!cin.fail()) {
      // each document is a line of json tweet
      Document d;
      d.Parse(line.c_str());

      // entites can be media, hashtags, urls, mentions, symbols
      if (d.HasMember("entities")) {
        //cout << "Has entities" << endl;
        Value& a = d["entities"];

        // check if any of the entities are hashtags
        if (a.HasMember("hashtags")) {
          //cout << "Has hashtags" << endl;
          Value& a1 = a["hashtags"];

          // if there are more than one hash tag
          if (a1.IsArray()) {
            for (SizeType j = 0; j < a1.Size(); j++) {
              if (a1[j].HasMember("text")) {
                Value& a2 = a1[j]["text"];

                if (a2.IsString()){
                  // original tag
                  string tag, orginal_tag;
                  orginal_tag = a2.GetString();
                  tag = a2.GetString();

                  // case doesnt matter, output all instances of tagh
                  if(ignoreCase){
                    std::transform(tag.begin(), tag.end(), tag.begin(), easytolower);
                    for (size_t x = 0; x < search_terms.size(); x++) {
                      // case doesnt matter print original tag
                      if(tag.find(search_terms[x]) != string::npos ){
                        cout << orginal_tag << " 1" << endl;
                      }
                    }
                  }else{
                    for (size_t x = 0; x < search_terms.size(); x++) {
                      if(tag.find(search_terms[x]) != string::npos)
                      cout << tag << " 1" << endl;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

char easytolower(char in){
  if(in<='Z' && in>='A') return in-('Z'-'z');
  return in;
}

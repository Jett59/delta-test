#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;
using std::vector;

void encode(vector<unsigned char>& content);
void decode(vector<unsigned char>& content);

int main(int argc, char** argv) {
  if (argc < 3) {
    cerr << "Usage: " << argv[0] << " <encode | decode> <File>" << endl;
    cerr << "Encodes or decodes a delta encoded file" << endl;
    return 0;
  }
  string command = string(argv[1]);
  string file = string(argv[2]);
  try {
    ifstream input;
    input.open(file, ios::binary);
    vector<unsigned char> fileContent;
    while (!input.eof()) {
      fileContent.push_back(input.get());
    }
    fileContent.pop_back();
    input.close();
    if (command == "encode") {
      encode(fileContent);
    } else if (command == "decode") {
      decode(fileContent);
    }
    ofstream output;
    output.open(file, ios::binary);
    for (int i = 0; i < fileContent.size(); i++) {
      output.put(fileContent[i]);
    }
    output.close();
  } catch (exception e) {
    cerr << e.what() << endl;
  }
  return 0;
}

void encode(vector<unsigned char>& content) {
  unsigned char previous = 0;
  for (int i = 0; i < content.size(); i++) {
    unsigned char temp = content[i];
    content[i] -= previous;
    previous = temp;
  }
}

void decode(vector<unsigned char>& content) {
  unsigned previous = 0;
  for (int i = 0; i < content.size(); i++) {
    content[i] += previous;
    previous = content[i];
  }
}

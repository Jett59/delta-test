#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv) {
  if (argc < 3) {
    cerr << "Usage: " << argv[0] << " <encode | decode> <File>" << endl;
    cerr << "Encodes or decodes a delta encoded file" << endl;
    return 0;
  }
  string command = string(argv[1]);
  return 0;
}

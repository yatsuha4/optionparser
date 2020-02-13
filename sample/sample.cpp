﻿#include "OptionParser.hpp"

int main(int argc, const char** argv) {
  optionparser::OptionParser option;
  std::string output;
  try {
    option.append('o', "output", "FILE", "出力ファイルを指定する", 
                  [&](const char* arg) {
                    output.assign(arg);
                  });
    option.append('h', "help", nullptr, "このメッセージを表示する", 
                  [&](const char*) {
                    std::cerr << option.help();
                    exit(-1);
                  });
    option.parse(argc, argv);
  }
  catch(const optionparser::OptionParser::Error& e) {
    std::cerr << e.message << std::endl;
    exit(-1);
  }
  std::cout << output;
  for(const char* file : option) {
    std::cout << " << " << file;
  }
  std::cout << std::endl;
  return 0;
}

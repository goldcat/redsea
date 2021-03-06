#include "src/ascii_in.h"

#include <iostream>
#include <stdexcept>
#include <string>

#include "src/groups.h"
#include "src/util.h"

namespace redsea {

AsciiBits::AsciiBits(bool feed_thru) : is_eof_(false), feed_thru_(feed_thru) {
}

AsciiBits::~AsciiBits() {
}

int AsciiBits::getNextBit() {
  int result = 0;
  while (result != '0' && result != '1' && result != EOF) {
    result = getchar();
    if (feed_thru_)
      putchar(result);
  }

  if (result == EOF) {
    is_eof_ = true;
    return 0;
  }

  return (result == '1');
}

bool AsciiBits::isEOF() const {
  return is_eof_;
}

Group getNextGroupRSpy(bool feed_thru) {
  Group group;

  bool finished = false;

  while (!(finished || std::cin.eof())) {
    std::string line;
    std::getline(std::cin, line);
    if (feed_thru)
      std::cout << line << std::endl;

    if (line.length() < 16)
      continue;

    for (eBlockNumber block_num : {BLOCK1, BLOCK2, BLOCK3, BLOCK4}) {
      uint16_t block_data = 0;
      bool block_still_valid = true;

      int nyb = 0;
      while (nyb < 4) {
        if (line.length() < 1) {
          finished = true;
          break;
        }

        std::string single = line.substr(0, 1);

        if (single.compare(" ") != 0) {
          try {
            int nval = std::stoi(std::string(single), nullptr, 16);
            block_data = (block_data << 4) + nval;
          } catch (std::invalid_argument) {
            block_still_valid = false;
          }
          nyb++;
        }
        line = line.substr(1);
      }

      if (block_still_valid)
        group.set(block_num, block_data);

      if (block_num == BLOCK4)
        finished = true;
    }
  }

  return group;
}

}  // namespace redsea

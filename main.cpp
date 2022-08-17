
#include "Runner.h"
// source for reading binary file: https://cplusplus.com/forum/beginner/21548/

using std::string;

int main(int argc, char** argv) {
    Runner r;
    r.run(argv[1], argv[2], argv[3]); //argv[1] test.txt, [2] tree.txt, [3] bits.txt
    return 0;
}
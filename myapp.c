
#include "appui.h"
#include "appio.h"

int main(int argc, char ** argv) {


  for (int i=0;i<argc;i++) {
    appio(*argv);
    appui(*argv);
    argv++;
  }
  return 0;
}


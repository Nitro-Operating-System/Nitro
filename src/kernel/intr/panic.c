#include "../headers/kernel.h"
#include "../headers/panic.h"
#include <stdlib.h>
void onPanic(char* data) {
  term_init();
  kprint(data);
  kprint(" {PANIC EXECP} ");
  //exit(EXIT_SUCCESS);
}

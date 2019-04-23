#include "../headers/kernel.h"
#include "../headers/panic.h"
void onPanic(char* data) {
  term_init();
  kprint(data);
  kprint(" {PANIC EXECP} ");
}

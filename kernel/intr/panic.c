#include "../headers/kernel.h"
#include "../headers/panic.h"
void onPanic(char* data) {
  kprint(data);
  kprint(" {PANIC EXECP} ");
}

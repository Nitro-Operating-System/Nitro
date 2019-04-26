#include "../headers/kernel.h"
#include "../headers/panic.h"
void onPanic(char* data) {
  kprint(" :: [KERNEL PANIC] ");
  kprint(data);
}

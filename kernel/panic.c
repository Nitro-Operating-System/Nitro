#include "headers/kernel.h"
#include "headers/panic.h"
void onPanic(char* data) {
  kprint(" :: [KERNEL PANIC] ");
  kprint(data); kprint("\n");
}
void panic(int panicCode) {
  if(panicCode == 0) {
	kprint("Panic Handler detected no needed panic");
  }
  else {
	onPanic("System Exec");
  }
}

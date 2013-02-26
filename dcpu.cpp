/*
 * DCPU-16 Emulator
 *
 * Author: Austin Hendrix
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#include "dcpu.h"

#include "dcpu_instruction.h"

#define MEM_SZ (1 << 16)

int main(int argc, char ** argv) {
  uint16_t * mem;

  mem = (uint16_t*)malloc(MEM_SZ*sizeof(uint16_t));

  if( argc != 2 ) {
    printf("Usage: dcpu <memory image>\n");
    return 0;
  }

  int memfile = open(argv[1], O_RDONLY);

  if( memfile < 0 ) {
    perror(argv[1]);
    return 1;
  }

  read(memfile, mem, MEM_SZ*sizeof(uint16_t));
  
  if( close(memfile) ) {
    perror("Problem closing memory file");
    return 1;
  }

  dcpu_state state = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, mem };

  while(1) {
    dcpu_step(&state);
  }
}

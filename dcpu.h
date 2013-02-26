/*
 * DCPU-16 emulator
 *
 * Data structures and function definitions
 *
 * Author: Austin Hendrix
 */

#ifndef DCPU_H
#define DCPU_H

#include <stdint.h>

typedef struct {
  uint16_t a, b, c, x, y, z, i ,j;
  uint16_t sp, pc, ex;
  uint16_t * mem;
} dcpu_state;

#endif

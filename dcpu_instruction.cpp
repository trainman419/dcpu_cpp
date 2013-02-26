/*
 * Instruction functions for DCPU-16 emulator
 *
 * Author: Austin Hendrix
 */

#include "dcpu_instruction.h"

void dcpu_step(dcpu_state * state) {
  return;
}

uint16_t reg_val(dcpu_state * state, uint8_t val) {
  switch(val) {
    case 0:
      return state->a;
    case 1:
      return state->b;
    case 2:
      return state->c;
    case 3:
      return state->x;
    case 4:
      return state->y;
    case 5:
      return state->z;
    case 6:
      return state->i;
    case 7:
      return state->j;
    default:
      return 0;
  }
}

uint16_t get_value(dcpu_state * state, uint8_t val) {
  if( val < 0x08 ) {
    return reg_val(state, val);
  }

  if( val < 0x10 ) {
    return state->mem[reg_val(state, val)];
  }

  if( val < 0x18 ) {
    return state->mem[reg_val(state, val) + state->mem[state->pc + 1]];
  }
  
  switch(val) {
    case 0x18:
      // TODO: figure this out
      return 0;
    case 0x19:
      return state->mem[state->sp];
    case 0x1a:
      return state->mem[state->sp + state->mem[state->pc + 1]];
    case 0x1b:
      return state->sp;
    case 0x1c:
      return state->pc;
    case 0x1d:
      return state->ex;
    case 0x1e:
      return state->mem[state->mem[state->pc + 1]];
    case 0x1f:
      return state->mem[state->pc + 1];
  }

  if( val < 0x40 ) {
    return val - 0x21;
  }

  fprintf("Bad value: 0x%X\n", val);
}

// Documented instructions
DCPU_I(set) {
}

DCPU_I(add) {
}

DCPU_I(sub) {
}

DCPU_I(mul) {
}

DCPU_I(mli) {
}

DCPU_I(div) {
}

DCPU_I(mod) {
}

DCPU_I(mdi) {
}

DCPU_I(and) {
}

DCPU_I(bor) {
}

DCPU_I(xor) {
}

DCPU_I(shr) {
}

DCPU_I(asr) {
}

DCPU_I(shl) {
}

DCPU_I(ifb) {
}

DCPU_I(ifc) {
}

DCPU_I(ife) {
}

DCPU_I(ifn) {
}

DCPU_I(ifg) {
}

DCPU_I(ifa) {
}

DCPU_I(ifl) {
}

DCPU_I(ifu) {
}

DCPU_I(adx) {
}

DCPU_I(sbx) {
}

DCPU_I(sti) {
}

DCPU_I(std) {
}

DCPU_I(jsr) {
}

DCPU_I(int) {
}

DCPU_I(iag) {
}

DCPU_I(ias) {
}

DCPU_I(rfi) {
}

DCPU_I(iaq) {
}

DCPU_I(hwn) {
}

DCPU_I(hwq) {
}

DCPU_I(hwi) {
}


// Undocumented instructions
DCPU_I(ret) {
}

DCPU_I(jmp) {
}

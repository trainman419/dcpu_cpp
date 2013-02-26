/*
 * Instruction functions for DCPU-16 emulator
 *
 * Author: Austin Hendrix
 */

#include "dcpu.h"

void dcpu_step(dcpu_state * state);

#define DCPU_I(NAME) void dcpu_ ## NAME(dcpu_state * state)

// Documented instructions
DCPU_I(set);
DCPU_I(add);
DCPU_I(sub);
DCPU_I(mul);
DCPU_I(mli);
DCPU_I(div);
DCPU_I(mod);
DCPU_I(mdi);
DCPU_I(and);
DCPU_I(bor);
DCPU_I(xor);
DCPU_I(shr);
DCPU_I(asr);
DCPU_I(shl);
DCPU_I(ifb);
DCPU_I(ifc);
DCPU_I(ife);
DCPU_I(ifn);
DCPU_I(ifg);
DCPU_I(ifa);
DCPU_I(ifl);
DCPU_I(ifu);
DCPU_I(adx);
DCPU_I(sbx);
DCPU_I(sti);
DCPU_I(std);
DCPU_I(jsr);
DCPU_I(int);
DCPU_I(iag);
DCPU_I(ias);
DCPU_I(rfi);
DCPU_I(iaq);
DCPU_I(hwn);
DCPU_I(hwq);
DCPU_I(hwi);

// Undocumented instructions
DCPU_I(ret);
DCPU_I(jmp);

/*
 * file:     unit_02066ABC.c
 * unit:     no
 * function: func_02066ABC
 * address:  0x02066ABC
 * packet:   pkt_02066ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../../matched/include/Obj08903.h"

extern unsigned char *func_02066878(unsigned int i);
int func_02066ABC(int a0, int a1, int a2){ int t0; t0 = (int)func_02066878(a0); ((struct Obj08903 *)((char *)(t0)))->f24 = (int)~0; ((struct Obj08903 *)((char *)(t0)))->f28 = (int)a1; ((struct Obj08903 *)((char *)(t0)))->f2C = (int)a2; return t0; }

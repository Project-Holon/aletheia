/*
 * function: func_021FB594
 * address: 0x021FB594
 * packet: pkt_ov186_021FB594
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B838 0x0204B838 arm
 */
#include "../include/Obj24826.h"
/* Callee's complete leaf reads only r0; legacy r1-r3 are unused, unforwarded. */
extern int func_0204B838(int);
int func_021FB594(char *p) { return func_0204B838(((struct Obj24826 *)p)->f0); }

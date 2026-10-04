/*
 * function: func_021B9DDC
 * address: 0x021B9DDC
 * packet: pkt_ov181_021B9DDC
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x021B9E12.
 * symbols:
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj06587.h"
struct Descriptor;
extern void func_02045334(struct Descriptor *);
void func_021B9DDC(char *p){if(((struct Obj06587 *)p)->f2CC&1)func_02045334((struct Descriptor *)((struct Obj06587 *)p)->f2BC);if(((struct Obj06587 *)p)->f2CC&2)func_02045334((struct Descriptor *)((struct Obj06587 *)p)->f2C4);((struct Obj06587 *)p)->f2CC=0;}

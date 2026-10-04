/*
 * function: func_021BA7D4
 * address: 0x021BA7D4
 * packet: pkt_ov072_021BA7D4
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAE44 0x021BAE44 thumb ov072
 */
#include "../include/Obj13200.h"
typedef unsigned int u32;
extern void func_021BAE44(void *p);
void func_021BA7D4(char *p) { u32 i; for(i=0;i<((struct Obj13200 *)p)->fC;i++) func_021BAE44((void *)(((struct Obj13200 *)p)->f8+i*0x44)); }

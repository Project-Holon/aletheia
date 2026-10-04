/*
 * function: func_021D9FB0
 * address: 0x021D9FB0
 * packet: pkt_ov123_021D9FB0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: A named unsigned cursor q preserves counter r4 and cursor r5.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../include/Obj10454.h"
struct Obj;
extern void func_0204B3B4(struct Obj *p);
void func_021D9FB0(unsigned int p) { int i; unsigned int q; for(i=0;i<13;i++) { q=p+(unsigned)i*4; if(((struct Obj10454 *)q)->f9B0) { func_0204B3B4(((struct Obj10454 *)q)->f9B0); ((struct Obj10454 *)q)->f9B0=0; } } }

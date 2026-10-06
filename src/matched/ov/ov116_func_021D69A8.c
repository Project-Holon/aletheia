/*
 * function: func_021D69A8
 * address: 0x021D69A8
 * packet: pkt_ov116_021D69A8
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two bytes zero alignment padding follow the compiled function.
 * symbols:
 *   func_021C941C 0x021C941C arm ov114
 *   func_021D70E4 0x021D70E4 thumb ov116
 */
#include "../include/Obj22615.h"
extern void func_021C941C(unsigned x);
extern void func_021D70E4(unsigned char *);
void func_021D69A8(unsigned char *a,unsigned char *b,unsigned short c) { ((struct Obj22615 *)a)->f8=c; func_021C941C((unsigned char)c); func_021D70E4(b); }

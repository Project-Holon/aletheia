/*
 * function: func_021BA8F4
 * address: 0x021BA8F4
 * packet: pkt_ov213_021BA8F4
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The original truncates the second call argument to u16; the extern preserves that width.
 * symbols:
 *   func_021BA8E8 0x021BA8E8 thumb ov213
 */
#include "../include/Obj25710.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021BA8E8(char *p, int b, int c);
void func_021BA8F4(char *p,int v) { int i; for(i=0;i<((struct Obj25710 *)p)->f4814;i++) func_021BA8E8(p,(u16)i,v); }

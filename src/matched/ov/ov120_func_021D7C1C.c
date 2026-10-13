/*
 * function: func_021D7C1C
 * address: 0x021D7C1C
 * packet: pkt_ov120_021D7C1C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 */
#include "../include/Obj10402.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
void func_021D7C1C(char *p) { int i; char *q; for(i=0;i<12;i++) { q=(char *)((u32)p+(u32)i*4); if(((struct Obj10402 *)q)->f38) { func_020452E8(((struct Obj10402 *)q)->f38); ((struct Obj10402 *)q)->f38=0; } } GF_FONT_SetTextColor(1,2,0); }

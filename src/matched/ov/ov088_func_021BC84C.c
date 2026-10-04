/*
 * function: func_021BC84C
 * address: 0x021BC84C
 * packet: pkt_ov088_021BC84C
 * region: ov088
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj02128.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
void func_021BC84C(u8 *p) { u8 i; func_020452E8(((struct Obj02128 *)p)->fC); for(i=0;i<2;i++) func_020452E8(*(void **)((u32)p+((u32)i*4)+16)); }

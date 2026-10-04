/*
 * function: func_021D60D4
 * address: 0x021D60D4
 * packet: pkt_ov115_021D60D4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5A9C 0x021D5A9C thumb ov115
 *   func_021D4E04 0x021D4E04 thumb ov115
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj10336.h"
#include "../include/Obj22603.h"
typedef unsigned char u8;typedef unsigned int u32;
struct S020315D4;
extern void func_021D5D3C(void *),func_021D5A9C(u8 *),func_021D4E04(u8 *),func_020315D4(struct S020315D4 *),func_020306F0(u32);
int func_021D60D4(void *a,int b,u8 *c,u8 *p) { if(!((struct Obj22603 *)c)->f4)func_021D5D3C(((struct Obj10336 *)p)->f8);func_021D5A9C(*(u8 * *)&((struct Obj10336 *)p)->f8);func_021D4E04(*(u8 * *)&((struct Obj10336 *)p)->f4);func_020315D4(a);func_020306F0(121);return 1; }

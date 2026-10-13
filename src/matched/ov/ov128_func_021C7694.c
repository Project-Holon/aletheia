/*
 * function: func_021C7694
 * address: 0x021C7694
 * packet: pkt_ov128_021C7694
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021CA3E8 0x021CA3E8 thumb ov128
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj14037.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021CA3E8(int);
extern void func_0201F7A8(void *,u32);
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
void func_021C7694(u8 *p, void *ctx) {void *q;func_021CA3E8(1);func_0201F7A8(((struct Obj14037 *)p)->f1C,0);q=((struct Obj14037 *)p)->f1C;BMP_WIN_ClearScreen(q);func_02041B6C(func_02045730(q));}

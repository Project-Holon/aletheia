/*
 * function: func_021C875C
 * address: 0x021C875C
 * packet: pkt_ov128_021C875C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_021CA42C 0x021CA42C thumb ov128
 *   func_021CA2DC 0x021CA2DC thumb ov128
 *   func_021CA3E8 0x021CA3E8 thumb ov128
 */
#include "../include/Obj23088.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0201F7A8(void *,u32);
extern void func_021CA42C(char *);
extern void func_021CA2DC(char *);
extern void func_021CA3E8(int);
void func_021C875C(char *p,char *q) {func_0201F7A8(((struct Obj23088 *)p)->f108,1);func_021CA42C(q);func_021CA2DC(p);func_021CA3E8(1);}

/*
 * function: func_021C6664
 * address: 0x021C6664
 * packet: pkt_ov128_021C6664
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CA10C 0x021CA10C thumb ov128
 *   func_021C6DAC 0x021C6DAC thumb ov128
 *   func_021C6AC0 0x021C6AC0 thumb ov128
 *   func_021C6A5C 0x021C6A5C thumb ov128
 *   func_021C6980 0x021C6980 thumb ov128
 *   func_021C68C4 0x021C68C4 thumb ov128
 *   func_021C6790 0x021C6790 thumb ov128
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj00725.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021CA10C(u8 *);
extern void func_021C6DAC(u8 *);
extern void func_021C6AC0(u8 *);
extern void func_021C6A5C(u8 *);
extern void func_021C6980(u8 *);
extern void func_021C68C4(char *p);
extern void func_021C6790(u8 *);
extern void func_02049238(void *);
void func_021C6664(u8 *p) {func_021CA10C(p);func_021C6DAC(p);func_021C6AC0(p);func_021C6A5C(p);func_021C6980(p);func_021C68C4((char *)p);func_021C6790(p);func_02049238(((struct Obj00725 *)p)->f8);}

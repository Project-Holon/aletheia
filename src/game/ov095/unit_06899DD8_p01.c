/*
 * function: func_06899DD8
 * address: 0x06899DD8
 * packet: pkt_ov095_06899DD8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_06899DFC 0x06899DFC thumb ov095
 *   func_06899E0C 0x06899E0C arm ov095
 *   func_06899E14 0x06899E14 thumb ov095
 *   func_06899E24 0x06899E24 arm ov095
 */
#include "../../matched/include/Obj10162.h"
typedef unsigned int u32;
extern void func_06899DFC(u32);
extern void func_06899E0C(u32);
extern void func_06899E14(u32);
extern void func_06899E24(void *);
void func_06899DD8(unsigned char *p) {
 func_06899DFC(((struct Obj10162 *)p)->f14);
 func_06899E0C(((struct Obj10162 *)p)->fC);
 func_06899E14(((struct Obj10162 *)p)->fB0);
 func_06899E24(p);
}

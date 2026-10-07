/*
 * function: func_02178DE0
 * address: 0x02178DE0
 * packet: pkt_ov014_02178DE0
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A8 0x021797A8 data a4
 *   func_02178138 0x02178138 thumb ov014
 */
#include "../include/Obj12477.h"
#include "../include/G_S.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*Cb)(int);
extern struct S *g_021797A8;
extern void func_02178138(int);
void func_02178DE0(u8 *p) {
 Cb cb = *(Cb *)(((u8 *)g_021797A8) + 0x1E64);
 if (cb != 0) cb(((struct Obj12477 *)p)->f2 == 0 ? 1 : 0);
 if (((struct Obj12477 *)p)->f2 != 0) func_02178138(10); else func_02178138(0);
}

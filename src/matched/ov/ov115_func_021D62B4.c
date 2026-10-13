/*
 * function: func_021D62B4
 * address: 0x021D62B4
 * packet: pkt_ov115_021D62B4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D630C 0x021D630C thumb ov115
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 */
#include "../include/Obj13856.h"
#include "../include/Obj13857.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void GFL_USE_FadeOutBgm(u32);
extern void func_021D6134(void *a0, int a1, int a2);
extern void func_021D630C(void *a0);
void func_021D62B4(u8 *p) {
    int color;
    u8 *q = *(u8 * *)&((struct Obj13856 *)p)->f10;
    if (((struct Obj13857 *)q)->f10 & 16) color = 0x7fff;
    else color = 0;
    if (((struct Obj13857 *)q)->fC == 0) GFL_USE_FadeOutBgm(6);
    func_0202208C(0, 0, 0, (u16)color, 6, 1, ((struct Obj13856 *)p)->f14);
    func_021D6134(p, (int)((void (*)(void))func_021D630C), 0x213);
}

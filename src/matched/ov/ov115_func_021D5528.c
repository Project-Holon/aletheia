/*
 * function: WIFILOGIN_DISP_UpdatePalette
 * address: 0x021D5528
 * packet: pkt_ov115_021D5528
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 02040618 has three explicitly prepared argument registers here;
 *       there is no r3 setup after the two SDK copy calls.
 * symbols:
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 */
#include "../include/Obj03251.h"
typedef unsigned char u8;
typedef short s16;
extern void GX_LoadBGPltt(void *, int, int);
extern void func_0207E468(void *, int, int);
typedef unsigned int   u32;
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
void WIFILOGIN_DISP_UpdatePalette(void *unused, u8 *p) {
    if (((struct Obj03251 *)p)->f4 == 0) return;
    ((struct Obj03251 *)p)->f96B ^= 1;
    if (((struct Obj03251 *)p)->f96B & 1) return;
    GX_LoadBGPltt(p + 0x1f0 + ((struct Obj03251 *)p)->f968 * 32, 40, 14);
    func_0207E468(p + 0x1f0 + ((struct Obj03251 *)p)->f968 * 32, 40, 14);
    ++((struct Obj03251 *)p)->f968;
    if (((struct Obj03251 *)p)->f968 >= 60) ((struct Obj03251 *)p)->f968 = 0;
    BG_SYS_ChangeScrollImmediate(((struct Obj03251 *)p)->f96C, 2, 7);
}

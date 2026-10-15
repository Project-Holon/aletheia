/*
 * function: POKETRADE_PROC_SetupBoxCounts
 * address: 0x021DC5F0
 * packet: pkt_ov119_021DC5F0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020076A4 0x020076A4 thumb
 */
#include "../include/Obj06424.h"
typedef unsigned char  u8;
extern u8 func_020076A4(void *save);
void POKETRADE_PROC_SetupBoxCounts(char *p)
{
    int v = func_020076A4((void *)(((struct Obj06424 *)p)->f828));
    ((struct Obj06424 *)p)->f634 = v * 6 + 2;
    ((struct Obj06424 *)p)->f630 = v;
    ((struct Obj06424 *)p)->f638 = v * 0x14 + 0xC;
    ((struct Obj06424 *)p)->f63C = v * 0xA0 + 0x60;
}

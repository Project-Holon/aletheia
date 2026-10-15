/*
 * function: BR_UTIL_CreateTextWin
 * address: 0x021FD12C
 * packet: pkt_ov186_021FD12C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 */
#include "../include/Obj02901.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void *BR_UTIL_Create(u16,u32,u16,u16,u8,u8,void *,u16);
void *BR_UTIL_CreateTextWin(int a,void *owner,u16 heap)
{
    u8 *p;
    BR_RES_LoadBgGraphics((void *)a,2,heap);
    p=BR_UTIL_Create(0,1,19,30,4,2,owner,heap);
    ((struct Obj02901 *)p)->f14=12;
    return p;
}

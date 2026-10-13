/*
 * function: BTL_CLIENT_FlushSlotLinkWord
 * address: 0x021CF3B8
 * packet: pkt_ov093_021CF3B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: BTL_MAIN_SubItemFromBag consumes the live r2 halfword as its third argument;
 * its matched body forwards it to func_02007E50.
 * symbols:
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_MAIN_SubItemFromBag 0x021B90BC thumb ov093
 */
#include "../include/Obj05200.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
extern u8 BTL_MAIN_GetOwnClientId(u8 *p);
extern void BTL_MAIN_SubItemFromBag(u8 *p, u8 k, u32 v);
void BTL_CLIENT_FlushSlotLinkWord(u8 *p, u32 i)
{
    if (p[0x1aa] == 0) {
        if (p[0x1a6] == BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj05200 *)p)->f0)) {
            u16 *a = (u16 *)(p + 0x1a0);
            u32 v = a[i];
            if (v != 0) {
                a[i] = 0;
                BTL_MAIN_SubItemFromBag(*(u8 * *)&((struct Obj05200 *)p)->f0, p[0x1a6], v);
            }
        }
    }
}

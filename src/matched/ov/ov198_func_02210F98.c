/*
 * function: B_PLIST_MAIN_IsIndexInParty
 * address: 0x02210F98
 * packet: pkt_ov198_02210F98
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_IsInSelection 0x022110B8 thumb ov198
 */
#include "../include/Obj10852.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *, int);
extern unsigned B_PLIST_MAIN_IsInSelection(u8 **, unsigned);
unsigned B_PLIST_MAIN_IsIndexInParty(u8 *p, int index)
{
    unsigned selected = B_PLIST_MAIN_GetOrderIndex(p, index);
    u8 *q = *(u8 * *)&((struct Obj10852 *)p)->f0;
    if (q[0x22] != 1) {
        if (selected == q[0x1d] || selected == q[0x1e]) return 1;
        return B_PLIST_MAIN_IsInSelection((u8 **)p, selected);
    }
    return 0;
}

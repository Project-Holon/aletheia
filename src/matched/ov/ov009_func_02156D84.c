/*
 * unit:     yes
 * function: DWC_RAP_IsDisconnected
 * address:  0x02156D84
 * packet:   pkt_ov009_02156D84
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two functions: 0x02156D84, 0x02156DB0.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 */
#include "../include/Obj18658.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;

int DWC_RAP_IsDisconnected(void)
{
    u8 *g = g_021A8264;
    if (g == 0) {
        return 1;
    }
    {
        u32 s = ((struct Obj18658 *)g)->f754;
        if (s == 0x13 || s == 0x10 || s == 0x14) {
            return 1;
        }
    }
    return 0;
}

void DWC_RAP_StoreErrorOnDisconnect(u32 v)
{
    g_021A8264[0x7a3] = v;
}

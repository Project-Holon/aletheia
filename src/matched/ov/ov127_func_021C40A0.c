/*
 * function: WIFI_2DCHAR_RegisterBmp
 * address:  0x021C40A0
 * packet:   pkt_021C40A0
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFI_2DCHAR_RegisterBmpHandles  0x021C4494  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03277.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void WIFI_2DCHAR_RegisterBmpHandles(u8 *p, u32 a, u32 heap);

void WIFI_2DCHAR_RegisterBmp(u8 *p, int a, int b, int c)
{
    WIFI_2DCHAR_RegisterBmpHandles(p, a, c);
    ((struct Obj03277 *)p)->f2F0 = b;
}

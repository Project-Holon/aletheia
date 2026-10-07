/*
 * function: func_0217873C
 * address:  0x0217873C
 * packet:   pkt_ov014_0217873C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 */
#include "../../../matched/include/Obj05924.h"
#include "../../../matched/include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *g_021797A8;

int func_0217873C(u8 *p)
{
    u32 v = ((struct Obj05924 *)p)->f3C;

    if (v < 0x10 || v > 0x80 || v != (u32)p[0x4A] + 0x10 || ((struct Obj05924 *)p)->f40 != 1 || v < 8
        || ((struct Obj05924 *)p)->f44 != *(u32 *)(((u8 *)g_021797A8) + 8))
        return 0;
    if ((p[0x4B] & 3) == 1)
        return 1;
    return 0;
}

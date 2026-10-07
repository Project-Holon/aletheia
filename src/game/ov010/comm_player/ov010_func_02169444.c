/*
 * function: func_02169444
 * address:  0x02169444
 * packet:   pkt_ov010_02169444
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (blocker of ov021 func_0218C4A0).  Returns the 0x14-byte
 * entry idx of the table at +0x9C, or 0 if idx is out of range or the
 * entry is unused (first word -1).
 */
#include "../../../matched/include/Obj05901.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 *func_02169444(u8 *base, u32 idx)
{
    u32 *e;

    if (idx >= ((struct Obj05901 *)base)->fA4)
        return 0;
    e = (u32 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14);
    if (e[0] == -1)
        return 0;
    return e;
}

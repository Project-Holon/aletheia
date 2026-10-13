/*
 * function: FLDMMDL_BLACT_ReserveRes
 * address:  0x0219CD68
 * packet:   pkt_ov021_0219CD68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fills the first free 0xC-byte entry (tag 0xFFFF... see pool) of the table.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00429.h"
#include "../include/Obj12672.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FLDMMDL_BLACT_ReserveRes(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e)
{
    u8 *ctx = *(u8 * *)&((struct Obj00429 *)o)->f1C;
    u32 i;
    u32 n = ((struct Obj12672 *)ctx)->f4;
    o = *(u8 * *)&((struct Obj12672 *)ctx)->fC;
    for (i = 0; i < n; i++, o += 0xc) {
        if (((struct Obj00429 *)o)->f0 == 0xFFFF) {
            ((struct Obj00429 *)o)->f0 = a;
            *(u8 *)&((struct Obj00429 *)o)->f4 = b;
            *(u8 *)(o + 5) = c;
            ((struct Obj00429 *)o)->f2 = d;
            ((struct Obj00429 *)o)->f8 = e;
            return;
        }
    }
}

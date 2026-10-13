/*
 * function: EVENTDATA_SYSTEM_DisableConnect
 * address:  0x0216245C
 * packet:   pkt_ov010_0216245C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: when idx is below the halfword count at +0x16, marks the
 * first two halfwords of the 0x14-byte record idx in the table at +0x24 as
 * 0xFFFF.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12335.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u16 a;
    u16 b;
    u8 rest[0x10];
} Rec14;

void EVENTDATA_SYSTEM_DisableConnect(u8 *o, u16 idx)
{
    Rec14 *t = *(Rec14 * *)&((struct Obj12335 *)o)->f24;

    if (((struct Obj12335 *)o)->f16 > idx) {
        t[idx].a = 0xFFFF;
        t[idx].b = 0xFFFF;
    }
}

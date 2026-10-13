/*
 * function: UNION_COMM_SetChatPms
 * address:  0x021736A0
 * packet:   pkt_ov012_021736A0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save), called from ov019 UNION_ONESELF_ChatInputMain. The two
 * trailing halfwords are both loaded before either is stored, in source
 * order; only a volatile source pointer keeps the scheduler from hoisting
 * s[3]'s load above s[2]'s (plain temporaries swap r1/r2).
 */
#include "../include/Obj04170.h"

typedef unsigned char u8;
typedef unsigned short u16;

void UNION_COMM_SetChatPms(u8 *a, volatile u16 *s)
{
    u8 *p = a + 0x2830;
    u16 x, y;
    ((struct Obj04170 *)p)->f4 = s[0];
    ((struct Obj04170 *)p)->f6 = s[1];
    x = s[2];
    y = s[3];
    ((struct Obj04170 *)p)->f8 = x;
    ((struct Obj04170 *)p)->fA = y;
    p[0xf] = 0;
    (((struct Obj04170 *)p)->fC)++;
    p[0xe] = 1;
}

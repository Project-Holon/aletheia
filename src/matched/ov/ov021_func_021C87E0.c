/*
 * function: PLEASURE_BOAT_GetTimeEvent
 * address:  0x021C87E0
 * packet:   pkt_ov021_021C87E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT

 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { u32 f0; s16 f4; s16 f6; int f8; } P;
int PLEASURE_BOAT_GetTimeEvent(P *p)
{
    if (p->f4 >= 5400 && p->f8 >= 4)
        return 2;
    return p->f4 % 1350 == 0;
}

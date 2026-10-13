/*
 * function: FIELD_MSGBG_LoadWindowGraphics
 * address:  0x021902A4
 * packet:   pkt_02190270
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_MSGBG_LoadWindowGraphicsAll with no argument change.
 *
 * symbols:
 *   FIELD_MSGBG_LoadWindowGraphicsAll  0x02192FA4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_MSGBG_LoadWindowGraphicsAll(int a, int b);

void FIELD_MSGBG_LoadWindowGraphics(u32 a0, u32 a1)
{
    FIELD_MSGBG_LoadWindowGraphicsAll(a0, a1);
}

/*
 * function: CircleGraph_HoldUpdate
 * address:  0x021C118C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to CircleGraph_StartHold.
 *
 * symbols:
 *   CircleGraph_StartHold  0x021C1A5C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void CircleGraph_StartHold(void *h, u32 v);

void CircleGraph_HoldUpdate(u8 *h, u32 v)
{
    CircleGraph_StartHold(h, v);
}


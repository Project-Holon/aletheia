/*
 * function: CircleGraph_Update
 * address:  0x021C1124
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to CircleGraph_UpdateState.
 *
 * symbols:
 *   CircleGraph_UpdateState  0x021C15B8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void CircleGraph_UpdateState(u8 *p);

void CircleGraph_Update(u8 *p)
{
    CircleGraph_UpdateState(p);
}

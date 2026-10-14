/*
 * function: CircleGraph_QueueCommand
 * address:  0x021C16DC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Word at +0xc forwarded to RingQueue_Push.
 *
 * symbols:
 *   RingQueue_Push  0x021C0E4C  thumb  ov217

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void RingQueue_Push(u32, u32);
void CircleGraph_QueueCommand(u32 *p, u32 a1)
{
    RingQueue_Push(p[3], a1);
}


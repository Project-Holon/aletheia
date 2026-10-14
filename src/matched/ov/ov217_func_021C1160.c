/*
 * function: CircleGraph_QueueDrawFast
 * address:  0x021C1160
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) a0, 2 to CircleGraph_QueueCommand.
 *
 * symbols:
 *   CircleGraph_QueueCommand  0x021C16DC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void CircleGraph_QueueCommand(u32 *p, u32 a1);

void CircleGraph_QueueDrawFast(u8 *h)
{
    CircleGraph_QueueCommand((u32 *)h, 2);
}



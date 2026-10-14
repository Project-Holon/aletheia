/*
 * function: CircleGraph_DestroyQueueImpl
 * address:  0x021C1D74
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to CircleGraph_DestroyQueue.
 *
 * symbols:
 *   CircleGraph_DestroyQueue  0x021C1E00  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void CircleGraph_DestroyQueue(void *);

void CircleGraph_DestroyQueueImpl(u32 a0)
{
    CircleGraph_DestroyQueue((void *)a0);
}

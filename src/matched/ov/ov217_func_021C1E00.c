/*
 * function: CircleGraph_DestroyQueue
 * address:  0x021C1E00
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer with one argument load: passes the word at offset 0xc on
 * to RingQueue_Destroy.  Reached from CircleGraph_DestroyQueueImpl's veneer.
 *
 * symbols:
 *   RingQueue_Destroy  0x021C0E3C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 w[3];
    u32 a;
} Rec;

extern void RingQueue_Destroy(void *p);

void CircleGraph_DestroyQueue(Rec *p)
{
    RingQueue_Destroy((void *)p->a);
}

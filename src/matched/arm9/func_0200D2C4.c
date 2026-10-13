/*
 * function: ZUKAN_SAVE_IsRegionalSeenComplete
 * address:  0x0200D2C4
 * packet:   pkt_0200D144
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_SAVE_CountSeenRegionalCounted  0x0200D368  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
struct Blk37;
extern u16 ZUKAN_SAVE_CountSeenRegionalCounted(struct Blk37 *p, u32 heap);
int ZUKAN_SAVE_IsRegionalSeenComplete(void *p, unsigned int heap)
{
    return ZUKAN_SAVE_CountSeenRegionalCounted(p, heap) >= 0x96;
}

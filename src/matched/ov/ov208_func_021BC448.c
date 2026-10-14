/*
 * function: ZUKAN_DETAIL_COMMON_AllocBlendWork
 * address: 0x021BC448
 * packet: pkt_ov208_021BC448
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C8D98 0x021C8D98 data a1
 */
typedef unsigned int u32;
extern const char d_021C8D98[];
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void *ZUKAN_DETAIL_COMMON_AllocBlendWork(u32 heap)
{
    return func_02030734(heap, 20, 1, d_021C8D98, 0x113);
}

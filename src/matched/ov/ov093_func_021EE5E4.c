/*
 * function: func_021EE5E4
 * address:  0x021EE5E4
 * packet:   pkt_ov093_021EE5E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021F3ADC  0x021F3ADC  data  a4
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021F3ADC[];

void *func_021EE5E4(u32 heap)
{
    return func_02030734(heap, 0xC08, 1, d_021F3ADC, 0x6b);
}

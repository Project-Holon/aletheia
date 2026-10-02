/*
 * function: func_021BC448
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
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
void *func_021BC448(u32 heap)
{
    return func_02030734(heap, 20, 1, d_021C8D98, 0x113);
}

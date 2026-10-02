/*
 * function: func_021BB930
 * address: 0x021BB930
 * packet: pkt_ov093_021BB930
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: left-associated pointer addition p + count + 0xcb4 preserves
 * the base-plus-count computation before the incrementing byte store.
 */
typedef unsigned char u8;
typedef unsigned int u32;
void func_021BB930(u8 *p, u32 value)
{
    u32 i;
    u32 count = p[0xcba];
    for (i = 0; i < count; i++) {
        if (value == p[0xcb4 + i]) return;
    }
    p[0xcba]++;
    *(p + count + 0xcb4) = value;
}

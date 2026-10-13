/*
 * function: BEACON_VIEW_PopHistoryId
 * address:  0x021F07D4
 * packet:   pkt_ov032_021F07D4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8   0x02082D44  arm
 *   d_021F3554    0x021F3554  data  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 d_021F3554[];

u32 BEACON_VIEW_PopHistoryId(u8 *p)
{
    u32 n = p[0x8d];

    if (n == 0)
        return 0x30;
    p[0x8c] = p[0x8c] - 1;
    MI_CpuCopy8(p + 0x8e, p + 0x8d, p[0x8c]);
    (p + p[0x8c])[0x8d] = 0;
    return d_021F3554[n - 1];
}

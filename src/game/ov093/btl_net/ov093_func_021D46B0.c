/*
 * function: func_021D46B0
 * address:  0x021D46B0
 * packet:   pkt_ov093_021D46B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   d_021F3B88     0x021F3B88  data  ov093
 *   d_021F3A98     0x021F3A98  data  ov093  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u16 f04;
    u8 pad06[0x3b0e];
    void *f3b14;
};

extern struct S *d_021F3B88;
extern const char d_021F3A98[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void *func_021D46B0(int a, int b, u32 size)
{
    if (d_021F3B88->f3b14 == 0)
        d_021F3B88->f3b14 = sub_02030734((u16)((d_021F3B88->f04 & 0x7fff) | 0x8000), size, 1, d_021F3A98, 0x279);
    return d_021F3B88->f3b14;
}

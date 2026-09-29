/*
 * function: func_021D4838
 * address:  0x021D4838
 * packet:   pkt_ov093_021D4838
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
    u8 pad06[0x3ade];
    void *tblA[4];
};

extern struct S *d_021F3B88;
extern const char d_021F3A98[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void *func_021D4838(int idx, int unused, u32 size)
{
    d_021F3B88->tblA[idx] = sub_02030734((u16)((d_021F3B88->f04 & 0x7fff) | 0x8000), size, 1, d_021F3A98, 0x2d4);
    return d_021F3B88->tblA[idx];
}

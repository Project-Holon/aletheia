/*
 * function: func_021F0684
 * address:  0x021F0684
 * packet:   pkt_ov032_021F0684
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02165AC4  0x02165AC4  thumb  ov010
 *   func_02165D08  0x02165D08  thumb  ov010
 *   func_02165C48  0x02165C48  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02165AC4(u32 q, u32 rec, u16 *tag, int delta);
extern u8 func_02165D08(u32 rec);
extern u32 func_02165C48(u32 rec);

void func_021F0684(u8 *p, u8 *a, u8 *b)
{
    int i = 0;
    u16 tag;

    *a = 0;
    *b = 0;
    for (; i < p[0x7b]; i++) {
        func_02165AC4(*(u32 *)(p + 0x3c), *(u32 *)(p + 0x44), &tag, i);
        if (p[0x30] != func_02165D08(*(u32 *)(p + 0x44)))
            (*a)++;
        if (p[0x32] != func_02165C48(*(u32 *)(p + 0x44)))
            (*b)++;
    }
}

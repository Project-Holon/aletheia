/*
 * function: func_021BB594
 * address:  0x021BB594
 * packet:   pkt_ov091_021BB594
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   sub_0203101C   0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   d_021BED28     0x021BED28  data  ov091  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 d_021BED28[];
extern void *func_02030734(u32 heap, u32 size, int align, const char *file, u16 line);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
struct Tcbl;
extern struct Tcbl *sub_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(int a, int b, int c, u16 d);
extern u32 func_0201C440(void *p);

u32 *func_021BB594(u16 *h)
{
    u32 *r;
    u32 z;

    r = func_02030734(*h, 0x38, 0, (const char *)d_021BED28, 0x64);
    z = 0;
    func_0201F5BC(0, 1, 0xc, 0, *h);
    r[2] = (u32)sub_0203101C(*h, *h, 1, 0);
    r[3] = z;
    r[0] = 4;
    r[9] = z;
    r[8] = z;
    r[11] = z;
    r[13] = z;
    r[12] = z;
    r[5] = func_02028590(0xf, 1, 1, *h);
    r[10] = func_0201C440((void *)(*h));
    return r;
}

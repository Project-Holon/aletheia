/*
 * function: ov208_func_021C7EF8
 * address:  0x021C7EF8
 * packet:   pkt_ov208_021C7EF8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B688  0x0204B688  arm
 *   func_021BC518  0x021BC518  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0204B688(u32 obj, u32 on);
extern void func_021BC518(u32 fade);

#define W(o) (*(u32 *)(p + (o)))

void ov208_func_021C7EF8(void *a0, u8 *p)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(u32 *)(p + i * 4 + 0x13c) != 0)
            func_0204B688(*(u32 *)(p + i * 4 + 0x13c), 1);
    }
    func_0204B688(W(0x5e4), 1);
    func_0204B688(W(0x5e8), 1);
    for (i = 0; i < 4; i++)
        func_0204B688(*(u32 *)(p + i * 0x28 + 0x618), 1);
    func_021BC518(W(0x6a4));
    func_021BC518(W(0x6a8));
}

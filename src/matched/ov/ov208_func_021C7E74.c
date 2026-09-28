/*
 * function: ov208_func_021C7E74
 * address:  0x021C7E74
 * packet:   pkt_ov208_021C7E74
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B688  0x0204B688  arm
 *   func_0207D63C  0x0207D63C  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0204B688(u32 obj, u32 on);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);

#define W(o) (*(u32 *)(p + (o)))

void ov208_func_021C7E74(void *a0, u8 *p)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(u32 *)(p + i * 4 + 0x13c) != 0)
            func_0204B688(*(u32 *)(p + i * 4 + 0x13c), 0);
    }
    func_0204B688(W(0x5e4), 0);
    func_0204B688(W(0x5e8), 0);
    for (i = 0; i < 4; i++)
        func_0204B688(*(u32 *)(p + i * 0x28 + 0x618), 0);
    func_0207D63C(0x04000050, 0, 0x3f, 0xc, 4);
    func_0207D63C(0x04001050, 8, 0x3f, 0xc, 4);
}

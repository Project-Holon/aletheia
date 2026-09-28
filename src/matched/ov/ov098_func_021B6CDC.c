/*
 * function: func_021B6CDC
 * address:  0x021B6CDC
 * packet:   pkt_ov098_021B6CDC
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_0207D63C(u32, u32, u32, u32, u32);

int func_021B6CDC(u8 *p, u32 a1, u32 a2)
{
    switch (p[0x14]) {
    case 2:
        return 1;
    case 0:
        return 1;
    case 4:
        p[0x14] = 3;
        return 0;
    case 3:
        if (p[0x15] != 0) {
            *(u32 *)(p + 4) += *(u32 *)(p + 0xc);
            *(u32 *)(p + 8) += *(u32 *)(p + 0x10);
            p[0x15]--;
        } else {
            *(u32 *)(p + 4) = 0x1f000;
            *(u32 *)(p + 8) = 0x7000;
            p[0x14] = 0;
        }
        break;
    case 1:
        if (p[0x15] != 0) {
            *(u32 *)(p + 4) += *(u32 *)(p + 0xc);
            *(u32 *)(p + 8) += *(u32 *)(p + 0x10);
            p[0x15]--;
        } else {
            *(u32 *)(p + 4) = 0;
            *(u32 *)(p + 8) = 0x10000;
            p[0x14] = 2;
        }
        break;
    }

    func_0207D63C(0x04000050, 2, 0x3d,
                  (u8)(*(int *)(p + 4) >> 12), (u8)(*(int *)(p + 8) >> 12));
    return 0;
}

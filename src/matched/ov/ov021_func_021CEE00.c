/*
 * function: func_021CEE00
 * address:  0x021CEE00
 * packet:   pkt_ov021_021CEE00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CEF08  0x021CEF08  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef short          s16;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021CEF08(u8 *p, int i);

void func_021CEE00(u8 *p)
{
    u8 *q = p + 0x13c;
    int i;

    for (i = 0; i < 16; i++) {
        u8 *e = q + i * 0x2c;

        if (e[0x2e] == 1) {
            *(s16 *)(e + 0x30) -= 1;
            if (*(s16 *)(e + 0x30) <= 0) {
                func_021CEF08(p, i);
                q[0x2d1] = 1;
            }
        }
    }
}

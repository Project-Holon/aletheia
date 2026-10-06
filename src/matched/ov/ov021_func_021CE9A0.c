/*
 * function: func_021CE9A0
 * address:  0x021CE9A0
 * packet:   pkt_ov021_021CE9A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CE984  0x021CE984  thumb  ov021
 *   func_021CE934  0x021CE934  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021CE984(u32 *p, u32 n);
extern void func_021CE934(u8 *p, u8 *q, u32 c);

void func_021CE9A0(u8 *p)
{
    int i;

    if (p[0x518] != 0) {
        p[0x518] = 0;
        for (i = 0; i < 4; i++) {
            func_021CE984((u32 *)p, i);
            if (p[0x514] & (1 << i))
                func_021CE934(p, p + 0x494 + i * 32, (u8)i);
        }
    }
}

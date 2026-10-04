/*
 * function: func_0218C4A0
 * address:  0x0218C4A0
 * packet:   pkt_ov021_0218C4A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Claims the first free 16-byte entry of the table at +0x1F8.
 *
 * symbols:
 *   func_021693D4  0x021693D4  thumb  ov010
 *   func_02169444  0x02169444  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021693D4(u8 *base, u8 *src, u32 idx);
extern u32 *func_02169444(u8 *base, u32 idx);

u32 *func_0218C4A0(u8 *base, u32 a, u32 b, u16 c)
{
    u32 *e = (u32 *)(base + 0x1F8);
    u32 i;

    for (i = 0; i < 0x120; i++) {
        e = (u32 *)(base + 0x1F8 + i * 16);
        if (e[0] == 0) {
            func_021693D4((u8 *)a, (u8 *)b, c);
            e[0] = a;
            e[1] = -1;
            *(u16 *)(e + 2) = c;
            *((u16 *)(e + 2) + 1) = 1;
            e[3] = (u32)func_02169444((u8 *)a, c);
            return e;
        }
    }
    return 0;
}

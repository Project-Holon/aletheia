/*
 * function: func_021C9E8C
 * address:  0x021C9E8C
 * packet:   pkt_ov021_021C9E8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fills the +0x32 halfword list with distinct draws: 14 for kinds 2, 3, 7, 8, else 7.
 *
 * symbols:
 *   func_021CA234  0x021CA234  thumb
 *   func_021CA2CC  0x021CA2CC  thumb
 *   func_021CBD90  0x021CBD90  thumb
 *   func_021CA2A4  0x021CA2A4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_021CA234(u8 *p);
extern u16 func_021CA2CC(u16 v);
extern u16 func_021CBD90(u8 *p, u32 x, u32 y, u32 kind, u8 alt);
extern int func_021CA2A4(const u16 *arr, u16 val, u16 n);

void func_021C9E8C(u8 *p)
{
    u8 kind = p[9];
    u16 lim = func_021CA2CC(func_021CA234(p));
    int i;
    u16 v;

    if (kind == 2 || kind == 3 || kind == 7 || kind == 8) {
        if (lim < *(u16 *)(p + 0x18))
            lim = *(u16 *)(p + 0x18);
        for (i = 0; i < 14; i++) {
            do {
                v = func_021CBD90(p, lim, (u8)(i / 2), kind, (u8)(i & 1));
            } while (func_021CA2A4((u16 *)(p + 0x32), v, i));
            ((u16 *)(p + 0x32))[i] = v;
        }
    } else {
        for (i = 0; i < 7; i++) {
            do {
                v = func_021CBD90(p, lim, (u8)i, p[9], 0);
            } while (func_021CA2A4((u16 *)(p + 0x32), v, i));
            ((u16 *)(p + 0x32))[i] = v;
        }
    }
}

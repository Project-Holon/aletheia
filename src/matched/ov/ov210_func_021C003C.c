/*
 * function: func_021C003C
 * address:  0x021C003C
 * packet:   pkt_ov210_021C003C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021BFF30 0x021BFF30 thumb ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021BFF30(int p, unsigned a, unsigned b);

void func_021C003C(int p, unsigned b)
{
    int *q = (int *)p;

    func_021BFF30(p, func_020260E0((struct Sound *)q[0xac]), 1);
    func_021BFF30(p, b, 3);
    func_020260E4((struct Sound *)q[0xac], (unsigned char)b);
}

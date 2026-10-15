/*
 * function: func_021C00D8
 * address:  0x021C00D8
 * packet:   pkt_ov210_021C00D8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BFF30 0x021BFF30 thumb ov210
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 * Addresses are Black-image addresses.
 */

extern void func_021BFF30(int p, unsigned a, unsigned b);
typedef unsigned char  u8;
struct Sound;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);

void func_021C00D8(int p, unsigned a, unsigned b)
{
    func_021BFF30(p, b, 1);
    if (a == 7)
        CURSOR_MOVE_SetCurrent((struct Sound *)(((int *)p)[0xac]), (unsigned char)b);
}

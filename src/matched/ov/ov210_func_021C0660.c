/*
 * function: func_021C0660
 * address:  0x021C0660
 * packet:   pkt_ov210_021C0660
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BFBF8 0x021BFBF8 thumb ov210
 *   func_021BF728 0x021BF728 thumb ov210
 * Addresses are Black-image addresses.
 */

extern void func_021BFBF8(int p, signed char v);
typedef unsigned char  u8;
extern void func_021BF728(u8 *p, int a);

void func_021C0660(int p, int v)
{
    func_021BFBF8(p, -v);
    func_021BF728((u8 *)p, 1);
}

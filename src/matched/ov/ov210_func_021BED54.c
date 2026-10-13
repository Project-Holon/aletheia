/*
 * function: func_021BED54
 * address:  0x021BED54
 * packet:   pkt_ov210_021BED54
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF370 0x021BF370 thumb ov210
 *   func_021BF080 0x021BF080 thumb ov210
 *   CLACT_ExitSystem 0x0204A5AC arm
 * Addresses are Black-image addresses.
 */

extern void func_021BF370(int p);
typedef unsigned char  u8;
extern void func_021BF080(u8 *p);
extern void CLACT_ExitSystem(void);

void func_021BED54(int p)
{
    func_021BF370(p);
    func_021BF080((u8 *)p);
    CLACT_ExitSystem();
}

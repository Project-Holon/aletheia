/*
 * function: func_021BEE94
 * address:  0x021BEE94
 * packet:   pkt_ov210_021BEE94
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Local 7-word table copied to the stack (data at 0x021C0990, 28 bytes), then
 * passed to 0x0204A48C with func_021BC3E8().
 * 2026-10-02: byte-exact; the only open item is the ABS32 pool word for the
 * compiler template (@8) of the local initialiser, which has no witness.
 *
 * symbols:
 *   func_021BC3E8 0x021BC3E8 thumb ov210
 *   func_0204A48C 0x0204A48C arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_021BC3E8(void);
extern void func_0204A48C(void *dst, u32 src, int n);

void func_021BEE94(void)
{
    u32 tbl[7] = { 0x00000000, 0x02000000, 0x7c047c04, 0x00000000, 0x00060006, 0x00000004, 0x00100010 };

    func_0204A48C(tbl, func_021BC3E8(), 0x7b);
}

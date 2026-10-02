/*
 * function: func_021EF8B8
 * address:  0x021EF8B8
 * packet:   pkt_ov093_021EF8B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * 2026-10-02: byte-correct, capped at MATCH. Tail call into the unlabelled
 * thumb leaf at 0x021EF9D0 (34 bytes, outside this lane's range, no witness
 * filed). The leaf is: v = p[0]; if (v != 0 && p[1] != 0xff && --p[1] == 0)
 * { p[0] = 0; return (u8)v; } return 0. Our C for it matches except that
 * the original converts (u8)v into r2 before the p[0] = 0 store (17 bytes
 * differ); tried u8 local, u32 local, cast at top, return type u8/u32.
 *
 * symbols:
 *   func_021EF9D0  0x021EF9D0  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 */

extern char d_021F63F4;
extern int func_021EF9D0(void *mem);

int func_021EF8B8(void)
{
    return func_021EF9D0(&d_021F63F4);
}

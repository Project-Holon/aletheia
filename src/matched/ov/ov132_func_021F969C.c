/*
 * function: func_021F969C
 * address:  0x021F969C
 * packet:   pkt_ov132_021F969C
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: The matched 020064B8 body reads four arguments; incoming r3 is
 * forwarded unchanged, preventing the erroneous three-argument tail call.
 *
 * symbols:
 *   func_020064B8  0x020064B8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern int func_020064B8(u32, u32, u32, u32);

int func_021F969C(char *p, u32 a, u32 b, u32 d)
{
    return func_020064B8(a, b, *(u32 *)(p + 0x1e4), d);
}

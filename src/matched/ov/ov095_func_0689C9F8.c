/*
 * function: func_0689C9F8
 * address: 0x0689C9F8
 * packet: pkt_ov095_0689C9F8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov095/unit_0689C888.c and filed here.
 *
 * symbols:
 *   d_0689E4C0 0x0689E4C0 data a4
 */

unsigned int func_0689C9F8(unsigned a);
extern const unsigned int d_0689E4C0[];

unsigned int func_0689C9F8(unsigned a)
{
    if (a < 0x23) return d_0689E4C0[a];
    return 0;
}

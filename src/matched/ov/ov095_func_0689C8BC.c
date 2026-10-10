/*
 * function: func_0689C8BC
 * address: 0x0689C8BC
 * packet: pkt_ov095_0689C8BC
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
 *   d_0689E31C 0x0689E31C data a2
 *   func_0689C888 0x0689C888 thumb
 */

int func_0689C888(unsigned a, unsigned short *b, unsigned n);
int func_0689C8BC(unsigned a);
extern unsigned short d_0689E31C[];

int func_0689C8BC(unsigned a)
{
    return func_0689C888(a, d_0689E31C, 10);
}

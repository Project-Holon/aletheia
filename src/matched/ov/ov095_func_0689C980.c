/*
 * function: func_0689C980
 * address: 0x0689C980
 * packet: pkt_ov095_0689C980
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
 *   d_0689E38C 0x0689E38C data a2
 *   func_0689C888 0x0689C888 thumb
 */

int func_0689C888(unsigned a, unsigned short *b, unsigned n);
int func_0689C980(unsigned a);
extern unsigned short d_0689E38C[];

int func_0689C980(unsigned a)
{
    return func_0689C888(a, d_0689E38C, 16);
}

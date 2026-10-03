/*
 * function: func_0689C954
 * address: 0x0689C954
 * packet: pkt_ov095_0689C954
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0689C974 0x0689C974 thumb ov095
 *   func_0689C888 0x0689C888 thumb ov095
 *   d_0689E2A4 0x0689E2A4 data a2
 */

extern int func_0689C974(int a);
extern int func_0689C888(unsigned a, unsigned short *b, unsigned n);
extern unsigned short d_0689E2A4[];
int func_0689C954(unsigned a)
{
    if (func_0689C974(a)) return 1;
    return func_0689C888(a, d_0689E2A4, 3);
}

/*
 * function: func_021BFBA0
 * address: 0x021BFBA0
 * packet: pkt_ov204_021BFBA0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note 2026-10-05 (wD6 lane10): the call f(p, p[10]) is written in each if/else arm; tail merging
 *   rebuilds one store+call block and r0 keeps p, so the temporaries take r1.
 * symbols:
 *   func_021BFBC8 0x021BFBC8 thumb ov204
 */

extern void func_021BFBC8(char *p, unsigned value);

int func_021BFBA0(int *p)
{
    if (p[7] == 3) {
        p[10] = p[10] + 1;
        func_021BFBC8((char *)p, p[10]);
    } else {
        p[10] = p[10] - 1;
        func_021BFBC8((char *)p, p[10]);
    }
    return p[10] == 60;
}

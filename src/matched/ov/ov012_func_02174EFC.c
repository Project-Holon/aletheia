/*
 * function: func_02174EFC
 * address: 0x02174EFC
 * packet: pkt_ov012_02174EFC
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov012/colosseum.c and filed here.
 */

typedef unsigned char u8;
void func_02174EFC(int a, int b, int c, u8 *p);

void func_02174EFC(int a, int b, int c, u8 *p)
{
    u8 *w = *(u8 **)(p + 0x355c);
    if (w != 0)
        w[0x161]++;
}

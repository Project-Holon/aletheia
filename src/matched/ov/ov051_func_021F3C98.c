/*
 * function: func_021F3C98
 * address: 0x021F3C98
 * packet: pkt_ov051_021F3C98
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F3BC4 0x021F3BC4 thumb ov051
 */

extern int func_021F3BC4(int *, int *, int, unsigned short, unsigned *);

int func_021F3C98(int *a, int *b)
{
    unsigned short i = 0;
    unsigned out;
    do {
        if (func_021F3BC4(a, b, i, 1, &out) == 1)
            return 1;
        i++;
    } while (i < 4);
    return 0;
}

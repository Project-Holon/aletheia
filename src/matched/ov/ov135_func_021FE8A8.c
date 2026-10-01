/*
 * function: func_021FE8A8
 * address: 0x021FE8A8
 * packet: pkt_ov135_021FE8A8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 */
extern void func_021FF318(char *, int, int, int, int);
extern void func_021F4E98(char *, unsigned, unsigned);
int func_021FE8A8(char *p)
{
    if (++*(int *)(p + 0xdfc) > 45) {
        func_021FF318(p, 38, 1, 0, 0xf0f);
        func_021F4E98(p, 23, 1);
        *(unsigned short *)(p + 0xe1a) = 1;
    }
    return 2;
}

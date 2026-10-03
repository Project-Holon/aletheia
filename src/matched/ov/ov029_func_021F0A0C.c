/*
 * function: func_021F0A0C
 * address: 0x021F0A0C
 * packet: pkt_ov029_021F0A0C
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F0AC8 0x021F0AC8 thumb ov029
 */
extern void func_021F0AC8(unsigned char *p, int a, int b);
void func_021F0A0C(unsigned char *p)
{
    int i, j;
    unsigned char *base;
    i = 0;
    base = p + 0x2d0;
    for (; i < 9; i++) {
        for (j = 0; j < 4; j++) func_021F0AC8(base + i * 32 + j * 8, i, j);
    }
}

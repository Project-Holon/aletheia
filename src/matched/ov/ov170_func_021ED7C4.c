/*
 * function: func_021ED7C4
 * address:  0x021ED7C4
 * packet:   pkt_ov170_021ED7C4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   d_021EFCD0 0x021EFCD0 data a1
 *   d_021EFCC8 0x021EFCC8 data a1
 */

extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern const signed char d_021EFCD0[];
extern const signed char d_021EFCC8[];

void func_021ED7C4(char *p, int i)
{
    short xy[2];
    int j;
    if (i == 0xFF)
        return;
    j = 0;
    func_021EC0B0(p, *(unsigned char *)(p + i + 0x3DD2), &xy[1], &xy[0], j);
    for (; j < 8u; j++)
        func_021EC08C(p, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
}

/*
 * function: func_021ED310
 * address:  0x021ED310
 * packet:   pkt_ov170_021ED310
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
extern void func_021EC08C(char *p, int i, short a, short b, short c);
extern const signed char d_021EFCD0[];
extern const signed char d_021EFCC8[];

void func_021ED310(char *w)
{
    short xy[2];
    unsigned i;
    if (*(void **)(w + 0x9FD4) != 0) {
        i = 0;
        func_021EC0B0(w, 0xA, &xy[1], &xy[0], 0);
        for (; i < 8; i++)
            func_021EC08C(w, i + 0x58, xy[1] + d_021EFCD0[i], xy[0] + d_021EFCC8[i], 0);
    }
}

/*
 * function: func_021EDF5C
 * address:  0x021EDF5C
 * packet:   pkt_ov170_021EDF5C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DEB14 0x021DEB14 thumb
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021EC000 0x021EC000 thumb
 */

extern unsigned char func_021DEB14(unsigned char *p, signed char a);
extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, short a, short b, short c);
extern void func_021EC000(char *p, int i, int v);

void func_021EDF5C(unsigned char *p)
{
    unsigned i;
    short xy[2];
    for (i = 0; i < 6; i++) {
        if (p[0x14] == func_021DEB14(p, i - 1)) {
            func_021EC0B0(*(char **)(p + 0x2C), 2, &xy[1], &xy[0], 0);
            func_021EC08C(*(char **)(p + 0x2C), 2, xy[1], i * 0x22, 0);
            func_021EC000(*(char **)(p + 0x2C), 2, 1);
            return;
        }
    }
    func_021EC000(*(char **)(p + 0x2C), 2, 0);
}

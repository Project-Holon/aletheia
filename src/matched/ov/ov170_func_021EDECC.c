/*
 * function: func_021EDECC
 * address: 0x021EDECC
 * packet: pkt_ov170_021EDECC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DEB14 0x021DEB14 thumb ov170
 *   func_021EC0B0 0x021EC0B0 thumb ov170
 *   func_021EC08C 0x021EC08C thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 */
extern unsigned char func_021DEB14(unsigned char *, signed char);
extern void func_021EC0B0(char *, int, short *, short *, unsigned short);
extern void func_021EC08C(char *, int, short, short, short);
extern void func_021EC000(char *, int, int);
void func_021EDECC(unsigned char *p, int d)
{
    short t[2];
    if (d < 0 && p[0x14] == func_021DEB14(p, -1)) {
        func_021EC0B0(*(char **)(p + 0x2c), 2, &t[1], &t[0], 0);
        func_021EC08C(*(char **)(p + 0x2c), 2, t[1], -0x22, 0);
        func_021EC000(*(char **)(p + 0x2c), 2, 1);
        return;
    }
    if (d > 0 && p[0x14] == func_021DEB14(p, 4)) {
        func_021EC0B0(*(char **)(p + 0x2c), 2, &t[1], &t[0], 0);
        func_021EC08C(*(char **)(p + 0x2c), 2, t[1], 0xcc, 0);
        func_021EC000(*(char **)(p + 0x2c), 2, 1);
    }
}

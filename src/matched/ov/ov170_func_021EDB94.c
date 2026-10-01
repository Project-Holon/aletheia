/*
 * function: func_021EDB94
 * address: 0x021EDB94
 * packet: pkt_ov170_021EDB94
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two trailing zero bytes at 0x021EDBE6 are alignment padding.
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb ov170
 *   func_021EDB64 0x021EDB64 thumb ov170
 *   func_021EB874 0x021EB874 thumb ov170
 */
extern void func_021EC0B0(char *, int, short *, short *, unsigned short);
extern void func_021EDB64(char *, int, int);
extern void func_021EB874(char **, unsigned, int);
void func_021EDB94(char *p, int a, int b)
{
    short t[2];
    int i = 0;
    b *= 0x22;
    for (; i < 6u; i++) {
        func_021EC0B0(*(char **)(p + 0x2c), i + 0x2d, &t[1], &t[0], 0);
        if (b == t[0]) {
            func_021EDB64(p, a, i + 0x2d);
            func_021EB874((char **)p, a, i + 1);
            return;
        }
    }
}

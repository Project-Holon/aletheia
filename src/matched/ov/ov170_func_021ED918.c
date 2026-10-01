/*
 * function: func_021ED918
 * address: 0x021ED918
 * packet: pkt_ov170_021ED918
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two trailing zero bytes at 0x021ED9B2 are alignment padding.
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb ov170
 *   func_021EC08C 0x021EC08C thumb ov170
 *   func_020258E8 0x020258E8 thumb
 *   func_0202590C 0x0202590C thumb
 */
extern void func_021EC0B0(char *, int, short *, short *, unsigned short);
extern void func_021EC08C(char *, int, short, short, short);
extern void func_020258E8(void *, short *, short *);
extern void func_0202590C(void *, short, short);
void func_021ED918(char *p, int d)
{
    short t[2];
    int i = 0;
    func_021EC0B0(*(char **)(p + 0x2c), 2, &t[1], &t[0], 0);
    func_021EC08C(*(char **)(p + 0x2c), 2, t[1] - d, t[0], 0);
    for (; i < 6u; i++) {
        func_021EC0B0(*(char **)(p + 0x2c), i + 0x2d, &t[1], &t[0], 0);
        func_021EC08C(*(char **)(p + 0x2c), i + 0x2d, t[1] - d, t[0], 0);
        func_020258E8(*(void **)(*(char **)(p + 0x2c) + i * 8 + 0xc), &t[1], &t[0]);
        func_0202590C(*(void **)(*(char **)(p + 0x2c) + i * 8 + 0xc), t[1] - d, t[0]);
    }
}

/*
 * function: func_021DF43C
 * address:  0x021DF43C
 * packet:   pkt_ov170_021DF43C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC08C 0x021EC08C thumb
 *   func_021ED7C4 0x021ED7C4 thumb
 */

extern void func_021EC08C(char *p, int i, short a, short b, short c);
extern void func_021ED7C4(char *p, int i);

void func_021DF43C(char *p, int x, int y)
{
    func_021EC08C(*(char **)(p + 0x2C), *(unsigned char *)(*(char **)(p + 0x2C) + 0x3DF6), x, (short)y - 8, 0);
    func_021ED7C4(*(char **)(p + 0x2C), 0x24);
    *(int *)(*(char **)(p + 0x2C) + 0xA180) = x;
    *(int *)(*(char **)(p + 0x2C) + 0xA184) = y;
}

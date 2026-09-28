/*
 * function: func_021DD16C
 * address:  0x021DD16C
 * packet:   pkt_ov170_021DD16C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 */

extern void func_021EBFA8(char *p, int i, int v);
extern void func_021EC35C(unsigned char *p, int box);
extern int func_021DEDCC(unsigned char *p, int box);
extern void func_021DEC98(unsigned char *p, int a, int dir);

void func_021DD16C(unsigned char *p, int dir)
{
    if (dir == 0) {
        p[0x14] = p[0x14] == 0 ? p[0x15] - 1 : p[0x14] - 1;
        func_021EBFA8(*(char **)(p + 0x2C), 0, 2);
    } else {
        p[0x14] = p[0x14] == p[0x15] - 1 ? 0 : p[0x14] + 1;
        func_021EBFA8(*(char **)(p + 0x2C), 1, 4);
    }
    func_021EC35C(p, p[0x14]);
    func_021DEC98(p, func_021DEDCC(p, p[0x14]), dir);
}

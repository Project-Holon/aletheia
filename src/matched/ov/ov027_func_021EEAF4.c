/*
 * function: func_021EEAF4
 * address:  0x021EEAF4
 * packet:   pkt_ov027_021EEAF4
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The handed 332-byte extent is 82 bytes of code followed by the ov027
 * data tables (0x021EEB48 onward).
 *
 * symbols:
 *   func_021A244C  0x021A244C  thumb  ov021
 *   func_021A2564  0x021A2564  thumb  ov021
 *   func_021A2190  0x021A2190  thumb  ov021
 *   func_021A21A0  0x021A21A0  thumb  ov021
 */

typedef signed int     s32;
typedef unsigned char  u8;
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern void func_021A2190(unsigned char *o, unsigned int v, int i);
extern void func_021A21A0(unsigned char *o, unsigned int v, int i);

void func_021EEAF4(int a, int *s)
{
    int x;
    int y;

    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    s[2] = (s[2] + 6) % 256;
    func_021A2190((unsigned char *)a, -s[2] * 2 - x, 0);
    func_021A21A0((unsigned char *)a, y + -s[2] * 2, 0);
}

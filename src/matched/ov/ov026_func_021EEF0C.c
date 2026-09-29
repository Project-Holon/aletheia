/*
 * function: func_021EEF0C
 * address:  0x021EEF0C
 * packet:   pkt_ov026_021EEF0C
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEF0C 0x021EEF0C thumb ov026
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_021A2190 0x021A2190 thumb ov021
 *   func_021A21A0 0x021A21A0 thumb ov021
 */

extern void func_021A244C(int, int *, int *);
extern void func_021A2564(int, int, int);
extern void func_021A2190(int, int, int);
extern void func_021A21A0(int, int, int);

void func_021EEF0C(int a, int *b)
{
    int x;
    int y;

    func_021A244C(a, &x, &y);
    func_021A2564(a, x, y);
    b[1] = (b[1] + 9) % 256;
    func_021A2190(a, -(b[1] + x), 0);
    func_021A21A0(a, y - b[1], 0);
}

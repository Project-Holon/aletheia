/*
 * function: func_02075274
 * address:  0x2075274
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0x020896CC and 0x0208A38C each have no witness outside this range: their only caller is this function (0x020751F4 itself is witnessed from pkt_02074A6C's other members)
 *
 * Every concrete byte reproduces; both sites are label-class refusals.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020751F4(int, int, int);
extern void func_020896CC(int, int);
extern void func_0208A38C(int);

void func_02075274(int a, int b, int c, int d)
{
    func_020751F4(a, c, d);
    func_020896CC(a, a + b);
    func_0208A38C(a);
}

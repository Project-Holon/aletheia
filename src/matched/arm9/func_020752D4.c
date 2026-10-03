/*
 * function: func_020752D4
 * address:  0x020752D4
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * See src/matched/func_020752A4.c: the pair is deliberately not one unit.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020751F4(u32 a, u32 b, u32 c);
extern void func_0208A424(int);

void func_020752D4(int a, int b, int c, int d)
{
    func_020751F4(a, c, d);
    func_0208A424(a);
}

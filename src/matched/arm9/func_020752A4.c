/*
 * function: func_020752A4
 * address:  0x020752A4
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Kept as its own file rather than folded with func_020752D4, its immediate
 *  * neighbour: the two are the only callers of 0x0208A424 anywhere in the image,
 *  * so any range holding both has no witness left for that site and caps at
 *  * MATCH. Split, each file is the other's witness.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020751F4(u32 a, u32 b, u32 c);
extern void func_020896EC(int, int);
extern void func_0208A424(int);

void func_020752A4(int a, int b, int c, int d)
{
    func_020751F4(a, c, d);
    func_020896EC(a, a + b);
    func_0208A424(a);
}

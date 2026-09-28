/*
 * function: func_0200A0E4
 * address:  0x0200A0E4
 * packet:   pkt_02009EDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200A0E4.c \\
 *       --func func_0200A0E4 --addr 0x0200A0E4 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0200A49C(u8 *p);
extern u32  func_02009F50(u8 *p, u32 a);
extern void func_0200A480(u8 *p);

u32 func_0200A0E4(u8 *p, u32 a)
{
    u32 r;

    func_0200A49C(p);
    r = func_02009F50(p, a);
    func_0200A480(p);
    return r;
}

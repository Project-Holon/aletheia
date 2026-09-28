/*
 * function: func_0200A13C
 * address:  0x0200A13C
 * packet:   pkt_02009EDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200A13C.c \\
 *       --func func_0200A13C --addr 0x0200A13C --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_0200A400(u8 *p);
extern void func_0200A49C(u8 *p);
extern u8  *func_0200A43C(u8 *p, u32 i);
extern void func_0200A480(u8 *p);
extern u32  func_02009F50(u8 *p, u32 i);

void func_0200A13C(u8 *p, u32 i)
{
    u32 n = func_0200A400(p);
    u8 *q;

    func_0200A49C(p);
    if (i < n) {
        q = func_0200A43C(p, i);
        q[0xb4] |= 2;
    }
    func_0200A480(p);
}

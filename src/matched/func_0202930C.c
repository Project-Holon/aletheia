/*
 * function: func_0202930C
 * address:  0x0202930C
 * packet:   pkt_0202918C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202930C.c \\
 *       --func func_0202930C --addr 0x0202930C --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_02005E50(u8 *p);
extern void func_02029344(u8 *p, u32 v);

void func_0202930C(u8 *p)
{
    if (func_02005E50(p) != 0) {
        return;
    }
    func_02029344(p, 0xe);
}

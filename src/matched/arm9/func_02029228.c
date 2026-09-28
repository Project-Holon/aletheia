/*
 * function: func_02029228
 * address:  0x02029228
 * packet:   pkt_0202918C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02029228.c \\
 *       --func func_02029228 --addr 0x02029228 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_02005E50(u8 *p);
extern u32  func_0202947C(u8 *p);
extern void func_02029408(u8 *p);
extern void func_02029344(u8 *p, u32 v);

void func_02029228(u8 *p)
{
    if (func_02005E50(p) != 0) {
        return;
    }
    if (func_0202947C(p) != 0) {
        return;
    }
    func_02029408(p);
    func_02029344(p, 9);
}

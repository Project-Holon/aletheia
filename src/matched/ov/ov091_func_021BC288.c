/*
 * function: func_021BC288
 * address:  0x021BC288
 * packet:   pkt_ov091_021BC288
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02019D00  0x02019D00  thumb
 *   func_02017988  0x02017988  thumb
 */

typedef unsigned short u16;

extern int func_02017E1C(int, int, int);
typedef unsigned int   u32;
extern u32 func_02019D00(u32 id);
extern void func_02017988(int, u16);

void func_021BC288(int unused, int a, int b)
{
    int t = 0;
    int r;
    if (func_02017E1C(a, 5, 0) == 0x289) {
        t = func_02017E1C(a, 0x6f, t);
        r = func_02019D00(b);
        if (t != r) {
            func_02017988(a, r);
        }
    }
}

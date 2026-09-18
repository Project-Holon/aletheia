/*
 * function: func_02029FF8
 * address:  0x02029FF8
 * packet:   pkt_02029F6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02006224  0x02006224  thumb
 *   func_0200616C  0x0200616C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int  func_02006224(int a);
extern void func_0200616C(u32 a, int b);

void func_02029FF8(u16 *p)
{
    if (func_02006224(4) == 0) {
        func_0200616C(0x662, 4);
    }
    p[2] = 0x384;
}

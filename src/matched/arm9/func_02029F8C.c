/*
 * function: func_02029F8C
 * address:  0x02029F8C
 * packet:   pkt_02029F6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02006224  0x02006224  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_0200616C  0x0200616C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_02006224(u32 a0);
extern void func_020061F8(int a);
extern void func_0200616C(u32 a, int b);

int func_02029F8C(u16 *p)
{
    if (p[2] != 0) {
        p[2] = p[2] - 1;
    }
    if (p[2] == 0) {
        if (func_02006224(4) == 1) {
            func_020061F8(4);
        }
        return 0;
    }
    if (func_02006224(4) == 0) {
        func_0200616C(0x662, 4);
    }
    return 1;
}

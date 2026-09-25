/*
 * function: func_0218A3F4
 * address:  0x0218A3F4
 * packet:   pkt_ov096_0218A3F4
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  register scheduling, 10 bytes.  Original keeps c in r5 up front
 *           (`adds r5,r2,#0`) and reads the u16 field into r2; the compiler
 *           insists on deferring the r5 move and loading the halfword into
 *           r1.  Pure allocation, no source spelling tried changes it.
 * symbols:
 *   func_02020F20  0x02020F20  thumb
 *   func_02021014  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_02020F20(int, u16);
extern int func_02021014(int, int);
extern void func_020307B0(int);

int func_0218A3F4(int a, int b, int c) {
    u16 h;
    int p;
    int q;
    h = *(u16 *)(a + 0xa0);
    p = func_02020F20(*(int *)(a + 0xa8), h);
    q = func_02021014(p, c);
    func_020307B0(p);
    return q;
}

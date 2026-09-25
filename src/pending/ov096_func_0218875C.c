/*
 * function: func_0218875C
 * address:  0x0218875C
 * packet:   pkt_ov096_0218875C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  callsite arg2 is built as ((0 << 8) | (v >> 24)); the literal 0
 *           folds away in every spelling tried, losing movs r3,#0 + lsls +
 *           orrs (and the early str of the 5th arg). 6 bytes short.
 * symbols:
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u8 *func_02011324(u8 *);
extern u32 func_0203F0A8(void);
extern void func_0218A0F4(u8 *, int, u32, int, int);

void func_0218875C(u8 *a, int unused, int c) {
    u8 *p;
    u32 v;
    int r;
    int z = 0;
    p = func_02011324(a);
    r = (int)func_02011324(a);
    v = func_0203F0A8();
    func_0218A0F4(a, c, ((z << 8) | (v >> 24)), (int)p, r);
}

/*
 * function: func_02189758
 * address:  0x02189758
 * packet:   pkt_ov096_02189758
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D5B40  0x021D5B40  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(int);
extern void func_020113B0(int, int);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_021D5B40(void *);

int func_02189758(int a, int b) {
    int r0;
    int r6;
    int r7;
    u8 *t;
    u8 s;
    r0 = func_0201134C(a);
    r6 = func_0201134C(a);
    r7 = func_0201134C(a);
    s = func_0218A160((u8 *)b, r0);
    t = func_0218A2FC((u8 *)b, s);
    if (r6 == func_021D5B40(t)) {
        func_020113B0(a, *(int *)(a + 0x14) + r7);
    }
    return *(int *)(b + 0xc4);
}

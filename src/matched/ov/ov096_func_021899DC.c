/*
 * function: func_021899DC
 * address:  0x021899DC
 * packet:   pkt_ov096_021899DC
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
 *   func_021D5478  0x021D5478  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
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
extern u32 func_021D5478(void *);
extern u32 func_021D5448(void *);

int func_021899DC(int a, int b) {
    int r4;
    int r7;
    u8 t;
    u8 *s;
    r4 = func_0201134C(a);
    r7 = func_0201134C(a);
    t = func_0218A160((u8 *)b, r4);
    s = func_0218A2FC((u8 *)b, t);
    if (func_021D5478(s) >= func_021D5448(s) && func_021D5448(s) > 1) {
        func_020113B0(a, *(int *)(a + 0x14) + r7);
    }
    return *(int *)(b + 0xc4);
}

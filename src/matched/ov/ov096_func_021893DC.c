/*
 * function: func_021893DC
 * address:  0x021893DC
 * packet:   pkt_ov096_021893DC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_0201134C  0x0201134C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(int);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
struct QI;
extern u16 func_021D5B40(struct QI *p);

int func_021893DC(int a, int b) {
    int t;
    u8 s;
    t = func_0201134C(a);
    s = func_0218A160((u8 *)b, t);
    t = func_021D5B40((struct QI *)func_0218A2FC((u8 *)b, s));
    *(int *)(b + 0x38) = t;
    return *(int *)(b + 0xc4);
}

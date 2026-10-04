/*
 * function: func_02189A44
 * address:  0x02189A44
 * packet:   pkt_ov096_02189A44
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0218A378  0x0218A378  thumb  ov096
 *   func_021D67A8  0x021D67A8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0218A378(int, int, int);
struct QL;
extern u16 func_021D67A8(struct QL *p);

int func_02189A44(int a, int b) {
    int t;
    t = func_021D67A8((struct QL *)(*(u8 **)(b + 0xc0)));
    if (t != 0) {
        t = func_0218A378(b, t, 2);
    } else {
        t = 0;
    }
    *(int *)(b + 0x38) = t;
    return *(int *)(b + 0xc4);
}

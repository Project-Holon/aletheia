/*
 * function: func_02189A9C
 * address:  0x02189A9C
 * packet:   pkt_ov096_02189A9C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  call to func_021D5BA4 (0x021D5BA4).  That address is an
 *           unlabelled Thumb leaf in ov093 (it sits in a .word run in the
 *           ov093 listing), so neither `label` nor `sole-ref/code` can attest
 *           it, and the call at 0x02189AB4 is its only referrer image-wide.
 * symbols:
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D5BA4  0x021D5BA4  thumb  ov093
 *   func_0201134C  0x0201134C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(int);
extern int func_0218A160(int, int);
extern int func_0218A2FC(int, int);
extern int func_021D5BA4(int);

int func_02189A9C(int a, int b) {
    int t;
    t = func_0201134C(a);
    t = func_0218A160(b, t);
    t = func_0218A2FC(b, t);
    t = func_021D5BA4(t);
    *(int *)(b + 0x38) = t;
    return *(int *)(b + 0xc4);
}

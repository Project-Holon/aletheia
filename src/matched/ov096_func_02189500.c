/*
 * function: func_02189500
 * address:  0x02189500
 * packet:   pkt_ov096_02189500
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0218A378  0x0218A378  thumb  ov096
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0218A378(int, u16, int);

int func_02189500(int a, int b) {
    int t;
    if (*(int *)(b + 0x38) != 0) {
        t = func_0218A378(b, (u16)*(int *)(b + 0x38), 3);
    } else {
        t = 0;
    }
    *(int *)(b + 0x38) = t;
    return *(int *)(b + 0xc4);
}

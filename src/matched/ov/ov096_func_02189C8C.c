/*
 * function: func_02189C8C
 * address:  0x02189C8C
 * packet:   pkt_ov096_02189C8C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   d_0218A58C     0x0218A58C  data   ov096  a4
 *
 * Lever: the second parameter is a struct pointer (fields at 0x38, 0xc4);
 * with an int base and a local `int *p = b + 0x38` the store/adds order and
 * the r4/r5 roles were wrong.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct { int v[7]; } Seven;
typedef struct { u8 p0[0x38]; int f38; u8 p1[0x88]; int fc4; } Obj;

extern const Seven d_0218A58C;
extern int func_0201134C(int);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_021D59B4(u8 *p, int k);

int func_02189C8C(int a, Obj *b) {
    u8 s;
    int v;
    u32 i;
    Seven t;
    s = func_0218A160((u8 *)b, func_0201134C(a));
    t = d_0218A58C;
    i = 0;
    b->f38 = 0;
    for (; i < 7; i++) {
        v = func_021D59B4(func_0218A2FC((u8 *)b, s), t.v[i]);
        if (v > 6) {
            b->f38 += v - 6;
        }
    }
    return b->fc4;
}

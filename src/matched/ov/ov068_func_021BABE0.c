/*
 * function: func_021BABE0
 * address:  0x021BABE0
 * packet:   pkt_ov068_021BABE0
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The clamp of the +0x34 field is a nested ternary (if/else-if reallocates
 * registers); the first call result goes through a local so the sum is
 * `adds r7, r0, r1`.
 *
 * symbols:
 *   func_02040804  0x02040804  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_0204B404  0x0204B404  arm
 *   d_021BB704     0x021BB704  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 x; u16 y; } Pt;

extern int  func_02040804(u32 a);
extern void func_02041EE4(u32 a, u32 b, int c);
extern void func_0204B404(u32 a, Pt *b, u32 c);
extern u32  d_021BB704[][6];

void func_021BABE0(u8 *p, int a1, int a2, int a3)
{
    int i;
    int v;
    int t;
    Pt pt;

    t = func_02040804(*(u16 *)(p + 2));
    v = t + a1;
    if (v > a3) {
        v = a3;
    } else if (v < a2) {
        v = a2;
    }
    func_02041EE4((u8)*(u16 *)p, 3, v + 0x14);
    func_02041EE4((u8)*(u16 *)(p + 2), 3, v);
    t = *(int *)(p + 0x34) - a1;
    *(int *)(p + 0x34) = t;
    *(int *)(p + 0x34) = t > 0x10 - a2 ? 0x10 - a2 : (t < 0x10 - a3 ? 0x10 - a3 : t);
    for (i = 0; i < 11; i++) {
        pt.x = d_021BB704[i][2];
        pt.y = *(int *)(p + 0x34) + d_021BB704[i][3];
        func_0204B404(*(u32 *)(p + i * 4 + 8), &pt, 0);
    }
}

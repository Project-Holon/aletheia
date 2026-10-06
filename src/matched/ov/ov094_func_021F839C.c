/*
 * function: func_021F839C
 * address:  0x021F839C
 * packet:   pkt_ov094_021F839C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   func_021F6A28  0x021F6A28  thumb  ov094
 *   func_021F6E2C  0x021F6E2C  thumb  ov094
 *   func_02040588  0x02040588  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern char *d_0220AF20;
extern void func_021F6A28(u32 obj, u32 mode, u32 b);
extern void func_021F6E2C(u32 obj, u32 b);
extern void func_02040588(u32 which, unsigned char enable);

void func_021F839C(u32 a, u32 b)
{
    switch (a) {
    case 0:
        func_021F6A28(*(u32 *)(d_0220AF20 + 0x194), 2, b);
        break;
    case 1:
        func_021F6E2C(*(u32 *)(d_0220AF20 + 0x198), b);
        break;
    case 2:
        func_02040588(3, (u8)(b ^ 1));
        break;
    case 3:
        func_021F6A28(*(u32 *)(d_0220AF20 + 0x194), 0, b);
        break;
    case 4:
        func_021F6A28(*(u32 *)(d_0220AF20 + 0x194), 1, b);
        break;
    }
}

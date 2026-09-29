/*
 * function: func_021F0F74
 * address:  0x021F0F74
 * packet:   pkt_ov032_021F0F74
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0F74  0x021F0F74  thumb
 *   func_02165CE8  0x02165CE8  thumb  ov010
 *   func_0204A9D0  0x0204A9D0  arm
 *   func_020215BC  0x020215BC  thumb
 *   d_021F3541     0x021F3541  data  ov032  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02165CE8(int a);
extern void func_0204A9D0(int a, int b);
extern void func_020215BC(int slots, int src, u32 idx, u32 off, u16 size);
extern u8 d_021F3541[];

void func_021F0F74(char *p, u8 *q, int r)
{
    int x;

    x = func_02165CE8(r);
    func_0204A9D0(*(int *)(*(int *)(p + 0x158) + q[0] * 4), *(int *)(p + x * 8 + 0x338));
    func_020215BC(*(int *)(p + 0xac),
                  *(int *)(p + 0x3bc) + ((d_021F3541[x] & 0xf) << 5), 3,
                  (u16)((q[0] + 9) << 4), 0x20);
}

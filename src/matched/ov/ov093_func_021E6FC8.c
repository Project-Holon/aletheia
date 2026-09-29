/*
 * function: func_021E6FC8
 * address:  0x021E6FC8
 * packet:   pkt_ov093_021E6FC8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
extern int func_021D62C4(void *m, int k);
extern void func_021D7704(int a, int b);

void func_021E6FC8(int x, int a, int c)
{
    int t = 4;

    if (c == func_021D775C(3)) {
        if (func_021D62C4(func_021C7CF4(a, (u8)func_021D775C(4)), 5) != 0) {
            func_021D7704(0x31, t << 11);
        }
    }
}

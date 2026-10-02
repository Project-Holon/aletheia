/*
 * function: func_021E5D24
 * address:  0x021E5D24
 * packet:   pkt_ov093_021E5D24
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D5B40(void *p);
extern u32 func_021D805C(u32 v, int k);
extern int func_021D76BC(int a, int b);

void func_021E5D24(int a, void *b, int c)
{
    if (c == func_021D775C(3)) {
        u16 n = func_021D5B40(func_021C7CF4(b, c));
        func_021D76BC(0x30, func_021D805C(n, 10));
    }
}

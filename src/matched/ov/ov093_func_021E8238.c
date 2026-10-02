/*
 * function: func_021E8238
 * address:  0x021E8238
 * packet:   pkt_ov093_021E8238
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021E8B28  0x021E8B28  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D76BC(int a, int b);
extern void func_021E8B28(u32 *p, u16 v);

void func_021E8238(int a, int b, int c)
{
    u32 v;

    if (c == func_021D775C(3)) {
        v = func_021D775C(0x1e);
        func_021E8B28(&v, 0x10);
        func_021D76BC(0x1e, v);
    }
}

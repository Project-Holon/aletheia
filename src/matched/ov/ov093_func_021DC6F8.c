/*
 * function: func_021DC6F8
 * address:  0x021DC6F8
 * packet:   pkt_ov093_021DC6F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C8288(u8 *p);
extern void func_021D7704(int a, int b);

void func_021DC6F8(int a, void *p, int v)
{
    u8 k;

    if (v == func_021D775C(3) && func_021C8288(p) == 4) {
        k = func_021D775C(0x16);
        if (k == 4 || k == 5 || k == 8)
            func_021D7704(0x31, 0x14cd);
    }
}

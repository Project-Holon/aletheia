/*
 * function: func_021DCAE8
 * address:  0x021DCAE8
 * packet:   pkt_ov093_021DCAE8
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
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021E8804  0x021E8804  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D76BC(int a, int b);
extern void func_021C88B4(void *a, int k, int b);
extern void func_021E8804(int a, void *b, int c, int d);

void func_021DCAE8(int a, void *b, int c, int d)
{
    if (c == func_021D775C(2) && func_021D76BC(0x51, 1) != 0) {
        func_021C88B4(b, 2, c);
        func_021E8804(a, b, c, d);
        func_021C88B4(b, 3, c);
    }
}

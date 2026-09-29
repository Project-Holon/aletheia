/*
 * function: func_021DE9D4
 * address:  0x021DE9D4
 * packet:   pkt_ov093_021DE9D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021E89D4  0x021E89D4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern u32 func_021E89D4(u16 v);

void func_021DE9D4(int a, void *b, int c)
{
    u16 v;
    u8 *r;

    if (c == func_021D775C(3)) {
        v = func_021D775C(0x12);
        if (v != 0xa5) {
            r = (u8 *)func_021C88A4(b, 12, c);
            r[0xf] = c;
            *(u32 *)(r + 4) = 0x1b;
            *(u32 *)(r + 8) = func_021E89D4(v);
            r[0x10] = 2;
            func_021C88C8(b, r);
        }
    }
}

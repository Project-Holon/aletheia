/*
 * function: func_021E0284
 * address:  0x021E0284
 * packet:   pkt_ov093_021E0284
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 */

typedef unsigned char u8;

extern int func_021D775C(int key);
extern void func_021D7704(int key, int m);
typedef unsigned int   u32;
extern u32 func_021C7EC4(u8 *p);

void func_021E0284(int a, void *b, int c, int *d, u8 e)
{
    if (c == func_021D775C(3) && e == func_021D775C(22)) {
        if (*d == 1 || func_021C7EC4(b))
            func_021D7704(49, 6 << 10);
    }
}

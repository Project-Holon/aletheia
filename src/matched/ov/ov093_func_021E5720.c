/*
 * function: func_021E5720
 * address:  0x021E5720
 * packet:   pkt_ov093_021E5720
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021E5784  0x021E5784  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void func_021E5784(void *a, void *b, int c, int d);

void func_021E5720(void *a, void *b, int c)
{
    u8 k;

    if (c == func_021D775C(3)) {
        k = func_021D775C(0xd);
        func_021E5784(a, b, c, k);
    }
}

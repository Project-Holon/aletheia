/*
 * function: func_021E0818
 * address:  0x021E0818
 * packet:   pkt_ov093_021E0818
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7320  0x021D7320  thumb  ov093
 *   func_021E0900  0x021E0900  thumb  ov093
 */

extern int func_021D775C(int key);
extern void func_021D7320(char *, int (*)(int, int, int, int, unsigned short));
extern int func_021E0900(int, int, int, int, unsigned short);

void func_021E0818(char *a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D7320(a, func_021E0900);
}

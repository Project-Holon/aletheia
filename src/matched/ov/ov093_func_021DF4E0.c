/*
 * function: func_021DF4E0
 * address:  0x021DF4E0
 * packet:   pkt_ov093_021DF4E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8;
extern int func_021D775C(int);
extern int func_021DCFF8(void *, int);
extern void func_021D76BC(int, int);
void func_021DF4E0(void *a, int b, int c, int d)
{
    if (c == func_021D775C(3) && d == func_021D775C(0x39))
        func_021D76BC(0x24, func_021DCFF8(a, 2));
}

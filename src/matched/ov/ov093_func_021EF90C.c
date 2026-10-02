/*
 * function: func_021EF90C
 * address:  0x021EF90C
 * packet:   pkt_ov093_021EF90C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EFB34  0x021EFB34  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 */

extern char d_021F63F4;
extern int func_021EFB34(void *mem, int a);

int func_021EF90C(int a)
{
    return func_021EFB34(&d_021F63F4, a);
}

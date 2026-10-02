/*
 * function: func_021EF874
 * address:  0x021EF874
 * packet:   pkt_ov093_021EF874
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF988  0x021EF988  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 */

extern char d_021F63F4;
extern int func_021EF988(void *mem, int a);

int func_021EF874(int a)
{
    return func_021EF988(&d_021F63F4, a);
}

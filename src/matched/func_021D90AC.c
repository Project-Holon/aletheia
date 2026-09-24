/*
 * function: func_021D90AC
 * address:  0x021D90AC
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * DWCi_EncSessionGetAsync: sixth argument is zero.
 *
 * symbols:
 *   func_021D9038  0x021D9038  thumb  ov119
 */

extern int func_021D9038(int a, int b, int c, int d, int e, int f);

int func_021D90AC(int a, int b, int c, int d, int e)
{
    return func_021D9038(a, b, c, d, e, 0);
}


/*
 * function: nan
 * address:  0x02091374
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   __float_nan     0x020A8818  data
 *   func_0209BD38  0x0209BD38  arm
 */

extern int __float_nan;
extern int func_0209BD38(int x);

int nan(void)
{
    return func_0209BD38(__float_nan);
}

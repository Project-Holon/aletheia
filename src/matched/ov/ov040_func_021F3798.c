/*
 * function: func_021F3798
 * address:  0x021F3798
 * packet:   pkt_021F3798
 * region:   ov040
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F3798 0x021F3798 thumb
 *   func_02188D2C 0x02188D2C thumb  ov021
 *   func_021BE580 0x021BE580 thumb ov021
*/

extern int func_02188D2C(int *p);
extern void func_021BE580(void *p);

void func_021F3798(int *p)
{
    func_021BE580((void *)func_02188D2C(p));
}

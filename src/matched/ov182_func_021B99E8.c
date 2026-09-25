/*
 * function: func_021B99E8
 * address:  0x021B99E8
 * packet:   pkt_ov182_021B99E8
 * region:   ov182
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B10  0x021B9B10  thumb  ov182
 *   func_021B9AA8  0x021B9AA8  thumb  ov182
 */

extern void func_021B9B10(void *);
extern void func_021B9AA8(void *);

void func_021B99E8(char *p)
{
    func_021B9B10(p + 4);
    func_021B9AA8(p);
}

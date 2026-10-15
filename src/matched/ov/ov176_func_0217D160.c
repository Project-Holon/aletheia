/*
 * function: func_0217D160
 * address:  0x0217D160
 * packet:   pkt_0217D160
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217D028  0x0217D028  thumb  ov176
 *   func_0217D188  0x0217D188  thumb  ov176
 */

typedef unsigned char  u8;
extern void func_0217D028(u8 *p);
extern int func_0217D188(u8 *p);

void func_0217D160(int *p)
{
    func_0217D028((u8 *)p);
    while (func_0217D188((u8 *)p) == 0)
        ;
}

/*
 * unit:     yes
 * function: func_021B9FEC, func_021B9FF8
 * address:  0x021B9FEC
 * packet:   pkt_ov071_021B9FEC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two thunks passing a constant third argument.
 *
 * symbols:
 *   func_021B9F74  0x021B9F74  thumb  ov071
 */

typedef unsigned char  u8;
void func_021B9FEC(void *p, int a)
{
    void func_021B9F74(u8 *p, int i, int v);
    func_021B9F74(p, a, 3);
}

void func_021B9FF8(void *p, int a)
{
    void func_021B9F74(u8 *p, int i, int v);
    func_021B9F74(p, a, 0);
}

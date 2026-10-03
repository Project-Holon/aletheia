/*
 * function: func_021EA83C
 * address:  0x021EA83C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD1E8  0x021DD1E8  thumb  ov170
 *   func_021E8FC0  0x021E8FC0  thumb  ov170
 *
 * Reset the entry then store the field with the dispatcher
 *   thumb-pointer 0x021E01C5 as its second argument.
 */


extern void func_021DD1E8(char *);
extern int func_021E8FC0(char *p, int a, int b);
void func_021EA83C(char *p, int a)
{
    func_021DD1E8(p);
    func_021E8FC0(p, 0x021E01C5, a);
}

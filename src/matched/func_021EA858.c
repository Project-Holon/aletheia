/*
 * function: func_021EA858
 * address:  0x021EA858
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF75C  0x021EF75C  thumb  ov170
 *   func_021E8FC0  0x021E8FC0  thumb  ov170
 *
 * Same forward as func_021EA83C but after restarting the queue.
 */


extern void func_021EF75C(int);
extern void func_021E8FC0(char *, int, int);
void func_021EA858(char *p, int a)
{
    func_021EF75C(*(int *)(*(int *)(p + 0x2c) + 0x74));
    func_021E8FC0(p, 0x021E01E1, a);
}

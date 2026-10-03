/*
 * function: func_021639C0
 * address:  0x021639C0
 * packet:   pkt_ov010_021639C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02163994  0x02163994  thumb  ov010
 */

typedef short s16;

extern int func_0216D83C();
extern int func_021641E8(int a);
extern int func_0216D854();
extern int func_0216D86C();
extern int func_021641F8(int a);
extern void func_02163994();

void func_021639C0(int a, int b)
{
    s16 x, z;
    int y;

    x = func_0216D83C(a) + func_021641E8(b);
    y = func_0216D854(a);
    z = func_0216D86C(a) + func_021641F8(b);
    func_02163994(a, x, y, z, b);
}

/*
 * function: func_02158A34
 * address:  0x02158A34
 * packet:   pkt_ov010_02158A34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * Narrow parameter c matches func_02158E7C's stored halfword and restores
 * spill/call scheduling. The remaining two bytes are zero alignment padding.
 *
 * symbols:
 *   func_02158E7C  0x02158E7C  thumb
 *   func_021588D0  0x021588D0  thumb
 *   func_02158BFC  0x02158BFC  thumb
 *   func_02011298  0x02011298  thumb
 *   func_02158CB4  0x02158CB4  thumb
 *   func_02158F18  0x02158F18  thumb
 */

typedef unsigned short u16;
struct ScriptVm;
extern int *func_02158E7C(u16 a, int b, int c, int d, int e, int f);
extern int func_021588D0(int);
extern int *func_02158BFC(int a0, int a1, int a2, int a3, int a4);
extern int func_02011298(struct ScriptVm *vm);
extern int func_02158CB4(int a0);
extern int func_02158F18(int a0);

void func_02158A34(int a, int b, u16 c, int d)
{
    int t = 0;
    int r;
    if (b == 0) {
        t = (int)func_02158E7C(4, a, t, c, t, d);
        b = t;
    }
    r = (int)func_02158BFC(4, b, func_021588D0(a), c, d);
    while (func_02011298((struct ScriptVm *)r) == 1)
        ;
    func_02158CB4(r);
    if (t != 0)
        func_02158F18(t);
}

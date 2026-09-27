/*
 * function: func_021DEF58
 * address:  0x021DEF58
 * packet:   pkt_ov175_021DEF58
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: DWC_ScShutdown (TwlDWC/libdwcsc.TWL.HYB.a, dwc_sc.o),
 * ov175.  Process the session once, log a pending result, then tear the
 * cleanup list down and wait for the async queue to drain.
 *
 * symbols:
 *   g_021E4D08     0x021E4D08  data
 *   func_021DF5E4  0x021DF5E4  arm  ov175
 *   func_021DEFC4  0x021DEFC4  arm  ov175
 */

typedef unsigned int u32;

extern u32 g_021E4D08[];
extern int func_021DFA3C(void *);
extern int func_021DF5E4(void);
extern int func_021DF644(int, int);
extern void func_02059F54(int, int);
extern void func_021DEFC4(void);
extern void func_0217CD94(void);
extern void func_0217CCCC(int);
extern int func_0217CE1C(void);

int func_021DEF58(void)
{
    int r;

    r = func_021DFA3C((void *)g_021E4D08[1]);
    if (r != 0)
        func_02059F54(func_021DF5E4(), func_021DF644(3, r));
    func_021DEFC4();
    func_0217CD94();
    func_0217CCCC(0);
    if (func_0217CE1C() != 2)
        func_0217CCCC(0);
    return r;
}

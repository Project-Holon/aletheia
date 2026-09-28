/*
 * function: func_021BA988
 * address:  0x021BA988
 * packet:   pkt_ov114_021BA988
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF  (parked; codegen order of v4/r4)
 *
 * Fleet object teardown for a ZigBee-like baTransport object.  Gets two
 * handles from the object (EF3C -> v5, EF50 -> v4), resets it (9C1C(1),
 * BBAAC), wires the two handles (9BD4(v4,v5)), frees and clears field 0x1c,
 * calls EFC8, clears field 8, invokes the callback, calls EC48, and if the
 * count at +0xc is non-negative decrements it via 9CFC(0,0)-1.
 *
 * BLOCKER (codegen, ordering): the original schedules the `mov r1,#1;
 * mov r4,r0` (capturing EF50's return) *before* the 9C1C call, i.e. it
 * keeps EF50's result in r4 across the 9C1C and BBAAC calls; this front end
 * either sinks `r4 = EF50(...)` after those calls (causing all downstream
 * register numbers/offsets to shift by 4, 111 bytes) or, when the locals are
 * spelled in the exact original order, drops the r4/r7 distinction and the
 * function comes out 144 vs 140 bytes (86 bytes differ, missing r3 push).
 * Tried: explicit r5/r4 locals, reordering EF50 before/after 9C1C, and
 * storing a0 in an explicit r7 local.  All relocations resolve (label/sdk);
 * the cap is argument scheduling of the EF50 call, same family as
 * docs/notes on varargs ordering.  Left parked as a documented near miss.
 *
 * symbols:
 *   func_021BEF3C  0x021BEF3C  arm  ov114
 *   func_021BEF50  0x021BEF50  arm  ov114
 *   func_021B9C1C  0x021B9C1C  arm  ov114
 *   func_021BBAAC  0x021BBAAC  arm  ov114
 *   func_021B9BD4  0x021B9BD4  arm  ov114
 *   func_021BA850  0x021BA850  arm  ov114
 *   func_021BEFC8  0x021BEFC8  arm  ov114
 *   func_021BEC48  0x021BEC48  arm  ov114
 *   func_021B9CFC  0x021B9CFC  arm  ov114
 */

extern int func_021BEF3C(int x);
extern int func_021BEF50(int x);
extern void func_021B9C1C(int a, int b);
extern void func_021BBAAC(int a);
extern void func_021B9BD4(int a, int b);
extern void func_021BA850(int a);
extern void func_021BEFC8(void);
extern void func_021BEC48(void);
extern int func_021B9CFC(int a, int b);

int func_021BA988(int a0, int cb)
{
    int v5;
    int v4;

    v5 = func_021BEF3C(a0);
    v4 = func_021BEF50(a0);
    func_021B9C1C(a0, 1);
    func_021BBAAC(a0);
    func_021B9BD4(v4, v5);
    func_021BA850(*(int *)(v5 + 0x1c));
    v4 = 0;
    *(int *)(v5 + 0x1c) = v4;
    func_021BEFC8();
    *(int *)(v5 + 8) = v4;
    if (cb) ((void (*)(void))cb)();
    func_021BEC48();
    if (*(int *)(v5 + 0xc) < 0) return 0;
    *(int *)(v5 + 0xc) = func_021B9CFC(0, 0) - 1;
    return 0;
}
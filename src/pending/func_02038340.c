/*
 * function: func_02038340
 * address:  0x02038340
 * packet:   pkt_02037F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * PARKED AT MATCH.  All 64 concrete bytes are right and five of the six
 * relocation sites resolve; the one open site is the PC24 at +0x0038, the
 * `bl` to func_02037E60.  That address has exactly one branch reference in
 * the whole image and it is this one, so no cut of a one-function file frees
 * it: the `label` class needs a second caller and there is none.
 *   blocker: `bl` to 0x02037E60 has no witness outside 02038340..02038380
 *            (fan-in 1); it closes the day 0x02037E60 is matched itself.
 * The other five sites are all attested and resolve: func_0203D798 (label
 * x357), func_0203D788 (label x500), func_02039338 (label x115),
 * func_02039160 (label x45) and func_02037D98 (label x10).
 *
 * The reading: refresh the UI object, ask its +0x340 owner's +0x70 virtual
 * whether the session is still up, then let the two teardown probes decide
 * whether func_02037D98(1) and func_02037E60 are reached.  The first
 * func_0203D798() result is discarded - the image overwrites r0 with
 * func_0203D788()'s answer immediately - which is why the call stands on its
 * own statement rather than as an initialiser.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_0203D788  0x0203D788  arm
 *   func_02039338  0x02039338  arm
 *   func_02039160  0x02039160  arm
 *   func_02037D98  0x02037D98  arm
 *   func_02037E60  0x02037E60  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02038340.c \
 *       --func func_02038340 --addr 0x02038340 --cc 1.1p1 --arm
 */

extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern void  func_02039338(void);
extern int   func_02039160(void);
extern void  func_02037D98(int a);
extern void  func_02037E60(void);

void func_02038340(void)
{
    void *p;

    func_0203D798();
    p = func_0203D788();
    if (((int (*)(void))*(unsigned int *)(*(unsigned int *)((char *)p + 0x340) + 0x70))() == 0)
        return;
    func_02039338();
    if (func_02039160() == 0)
        return;
    func_02037D98(1);
    func_02037E60();
}

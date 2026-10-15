/*
 * function: DWC_ScShutdown
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
 *   gDwcScControl     0x021E4D08  data
 *   DWCi_DWCScResultToDWCError  0x021DF5E4  arm  ov175
 *   DWCi_ScCleanupRootCAList  0x021DEFC4  arm  ov175
 *   DWCi_ScGetRequestErrorCode  0x021DF644  arm
 *   scShutdown  0x021DFA3C  arm
 *   gsCoreThink  0x0217CCCC  arm  ov009
 *   gsCoreShutdown  0x0217CD94  arm  ov009
 *   gsCoreIsShutdown  0x0217CE1C  arm  ov009
 */

typedef unsigned int u32;

extern u32 gDwcScControl[];
extern int scShutdown(void *);
extern int DWCi_DWCScResultToDWCError(void);
extern int DWCi_ScGetRequestErrorCode(int, int);
extern void func_02059F54(int, int);
extern void DWCi_ScCleanupRootCAList(void);
extern void gsCoreShutdown(void);
extern void gsCoreThink(int);
extern int gsCoreIsShutdown(void);

int DWC_ScShutdown(void)
{
    int r;

    r = scShutdown((void *)gDwcScControl[1]);
    if (r != 0)
        func_02059F54(DWCi_DWCScResultToDWCError(), DWCi_ScGetRequestErrorCode(3, r));
    DWCi_ScCleanupRootCAList();
    gsCoreShutdown();
    gsCoreThink(0);
    if (gsCoreIsShutdown() != 2)
        gsCoreThink(0);
    return r;
}

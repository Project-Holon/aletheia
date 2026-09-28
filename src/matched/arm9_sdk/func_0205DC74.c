/*
 * function: func_0205DC74
 * address:  0x0205DC74
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * SDK symbol: DWC_AC_CleanupGetWDSInfo (nintendospot.o, libdwcac.TWL.HYB.a)
 *
 * symbols:
 *   DWC_Free      0x0205A1B0  arm
 *   gDwcWdsWork   0x02146ADC  data
 */

struct DWCWDSWork {
    void *f0;
    void *f4;
};

extern void DWC_Free(int name, void *ptr, int flag);
extern struct DWCWDSWork gDwcWdsWork;

void func_0205DC74(void)
{
    if (gDwcWdsWork.f4 != 0) {
        DWC_Free(1, gDwcWdsWork.f4, 0);
        gDwcWdsWork.f4 = 0;
    }
    if (gDwcWdsWork.f0 != 0) {
        DWC_Free(1, gDwcWdsWork.f0, 0);
        gDwcWdsWork.f0 = 0;
    }
}

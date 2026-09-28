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
 * sdk:      DWC_AC_CleanupGetWDSInfo (nintendospot.o)
 *
 * symbols:
 *   DWC_Free                         0x0205a1b0 arm
 *   gDwcWdsWork                      0x02146adc data
 *   .bss                             0x02146adc data
 */

#define NULL ((void *)0)
typedef struct DWCWDSWork DWCWDSWork;

extern void DWC_Free(int name, void *ptr, long size);

static DWCWDSWork *gDwcWdsWork = NULL;
static void *wdsSysBuf = NULL;

void func_0205DC74(void)
{
    if (wdsSysBuf != NULL) {
        DWC_Free(1, wdsSysBuf, 0);
        wdsSysBuf = NULL;
    }
    if (gDwcWdsWork != NULL) {
        DWC_Free(1, gDwcWdsWork, 0);
        gDwcWdsWork = NULL;
    }
}

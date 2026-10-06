/*
 * file:     unit_0205D91C_p02.c
 * unit:     yes
 * function: func_0205DC58, func_0205DC74
 * address:  0x0205DC58
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146ADC 0x02146ADC data
 *   DWC_Free                         0x0205a1b0 arm
 *   gDwcWdsWork                      0x02146adc data
 *   .bss                             0x02146adc data
 */
typedef struct DWCWDSWork DWCWDSWork;

extern void g_02146ADC(void);
extern void DWC_Free(int name, void *ptr, long size);
asm void DWC_AC_CancelGetWDSInfo(void);
void func_0205DC74(void);


asm void DWC_AC_CancelGetWDSInfo(void)
{
    ldr r0, =g_02146ADC
    ldr	r1, [r0, #8]
    cmp	r1, #4
    moveq	r1, #5
    streq	r1, [r0, #8]
    bx	lr
}

#define NULL ((void *)0)


static DWCWDSWork *gDwcWdsWork = NULL;

static void *wdsSysBuf = NULL;


/*
 * sdk:      DWC_AC_CleanupGetWDSInfo (nintendospot.o)
 */
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

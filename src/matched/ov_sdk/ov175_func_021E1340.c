/*
 * function: DWC_GdbShutdown
 * address:  0x021E1340
 * packet:   pkt_ov175_021E1340
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GdbShutdown (dwc_gdb.o)
 *
 * symbols:
 *   DWCi_GdbPrintf  0x021E17D8  arm  ov175
 *   DWCi_GdbCleanupRootCAList  0x021E13BC  arm  ov175
 *   DWC_ShutdownGHTTP  0x021BF57C  arm  ov114
 *   sakeShutdown  0x021DD250  arm  ov175
 *   DWCi_GdbShutdownGsCore  0x021E191C  arm  ov175
 *   gDwcGdbEntity     0x021E5334  data
 *   sDwcGdbNotInitialized     0x021E4594  data
 *   sDwcGdbInAsyncProcess     0x021E45A8  data
 */

typedef struct {
    int unk0;
    void *sake;
    int state;
} Tbl;
extern Tbl gDwcGdbEntity;
extern char sDwcGdbNotInitialized[];
extern char sDwcGdbInAsyncProcess[];
extern void DWCi_GdbPrintf(int line, char *fmt, ...);
extern void DWCi_GdbCleanupRootCAList(void);
extern int DWC_ShutdownGHTTP(void);
extern void sakeShutdown(void *sake);
extern void DWCi_GdbShutdownGsCore(void);

int DWC_GdbShutdown(void)
{
    if (gDwcGdbEntity.state == 0) {
        DWCi_GdbPrintf(0x1a6, sDwcGdbNotInitialized);
        return 0x13;
    }
    if (gDwcGdbEntity.state == 2) {
        DWCi_GdbPrintf(0x1ab, sDwcGdbInAsyncProcess);
        return 0x14;
    }
    DWCi_GdbCleanupRootCAList();
    gDwcGdbEntity.state = 0;
    DWC_ShutdownGHTTP();
    sakeShutdown(gDwcGdbEntity.sake);
    DWCi_GdbShutdownGsCore();
    return 0;
}

/*
 * function: DWCi_GdbCheckStateForAsyncProcess
 * address:  0x021E1830
 * packet:   pkt_ov175_021E1830
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GdbCheckStateForAsyncProcess (dwc_gdb.o)
 *
 * symbols:
 *   DWCi_IsError      0x02059F38  arm
 *   DWC_GetLastError  0x02059E18  arm
 *   DWCi_GdbPrintf     0x021E17D8  arm  ov175
 *   sDwcGdbInDwcError        0x021E464C  data
 *   gDwcGdbEntity        0x021E5334  data
 *   sDwcGdbNotInitialized        0x021E4594  data
 *   sDwcGdbInAsyncProcess        0x021E45A8  data
 *   sDwcGdbInCancelProcess        0x021E4660  data
 */

typedef struct {
    int unk0;
    void *sake;
    int state;
} Tbl;
extern char sDwcGdbInDwcError[];
extern Tbl gDwcGdbEntity;
extern char sDwcGdbNotInitialized[];
extern char sDwcGdbInAsyncProcess[];
extern char sDwcGdbInCancelProcess[];
extern int DWCi_IsError(void);
extern int DWC_GetLastError(int *errorCode);
extern void DWCi_GdbPrintf(int line, char *fmt, ...);

int DWCi_GdbCheckStateForAsyncProcess(int *result)
{
    if (DWCi_IsError()) {
        DWCi_GdbPrintf(0x568, sDwcGdbInDwcError, DWC_GetLastError(0));
        if (result != 0) {
            *result = 0x16;
        }
        return 1;
    }
    switch (gDwcGdbEntity.state) {
    case 0:
        DWCi_GdbPrintf(0x570, sDwcGdbNotInitialized);
        if (result != 0) {
            *result = 0x13;
        }
        return 1;
    case 2:
        DWCi_GdbPrintf(0x575, sDwcGdbInAsyncProcess);
        if (result != 0) {
            *result = 0x14;
        }
        return 1;
    case 3:
        DWCi_GdbPrintf(0x57a, sDwcGdbInCancelProcess);
        if (result != 0) {
            *result = 0x17;
        }
        return 1;
    }
    return 0;
}

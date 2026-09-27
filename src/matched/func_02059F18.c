/*
 * function: DWC_ClearError
 * address:  0x02059F18
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   stDwcError  0x02146AA4  data  a4
 *
 * TwlDWC libdwccommon dwc_error.o.
 * Same merged .bss pair as DWC_GetLastError.
 */
typedef struct {
    int lastError;
    int errorCode;
} DWCErrorState;

static DWCErrorState stDwcError;

void DWC_ClearError(void)
{
    if (stDwcError.lastError != 9) {
        stDwcError.lastError = 0;
        stDwcError.errorCode = 0;
    }
}

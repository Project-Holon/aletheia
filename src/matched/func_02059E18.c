/*
 * function: DWC_GetLastError
 * address:  0x02059E18
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
 * Two file-local .bss words are merged into one base object so the pair shares a single pool word.
 */
typedef struct {
    int lastError;
    int errorCode;
} DWCErrorState;

static DWCErrorState stDwcError;

int DWC_GetLastError(int *errorCode)
{
    if (errorCode != 0) {
        *errorCode = stDwcError.errorCode;
    }
    return stDwcError.lastError;
}

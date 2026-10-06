/*
 * function: DWCi_SetError
 * address:  0x02059F54
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
 * The paired store is an inline stm.
 */
typedef struct {
    int lastError;
    int errorCode;
} DWCErrorState;

static DWCErrorState stDwcError;

void DWCi_SetError(int error, int errorCode)
{
    if (stDwcError.lastError != 9) {
        stDwcError.lastError = error;
        stDwcError.errorCode = errorCode;
    }
}

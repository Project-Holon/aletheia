/*
 * function: DWCi_GdbHandleRequestResult
 * address:  0x021E20D4
 * packet:   pkt_ov175_021E20D4
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GdbHandleRequestResult (dwc_gdb.o)
 *
 * symbols:
 *   DWCi_GdbRequestResultToAsyncResult  0x021E1F6C  arm  ov175
 *   DWCi_GdbPrintf  0x021E17D8  arm  ov175
 *   DWCi_GdbGetRequestResultErrorCode  0x021E20B8  arm  ov175
 *   DWCi_SetError  0x02059F54  arm
 *   sDwcGdbAsyncResultFormat     0x021E47C4  data
 */

extern char sDwcGdbAsyncResultFormat[];
extern int DWCi_GdbRequestResultToAsyncResult(int result, int *dwc_error);
extern void DWCi_GdbPrintf(int line, char *fmt, ...);
extern int DWCi_GdbGetRequestResultErrorCode(int process, int result);
extern void DWCi_SetError(int error, int errorCode);

int DWCi_GdbHandleRequestResult(int process, int result)
{
    int error_code;
    int dwc_error;
    int retval;

    retval = DWCi_GdbRequestResultToAsyncResult(result, &dwc_error);
    if (retval != 1) {
        DWCi_GdbPrintf(0x75b, sDwcGdbAsyncResultFormat, retval);
        error_code = DWCi_GdbGetRequestResultErrorCode(process, retval);
        DWCi_SetError(dwc_error, error_code);
    }
    return retval;
}

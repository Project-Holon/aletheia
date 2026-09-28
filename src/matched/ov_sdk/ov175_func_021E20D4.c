/*
 * function: func_021E20D4
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
 *   func_021E1F6C  0x021E1F6C  arm  ov175
 *   func_021E17D8  0x021E17D8  arm  ov175
 *   func_021E20B8  0x021E20B8  arm  ov175
 *   DWCi_SetError  0x02059F54  arm
 *   g_021E47C4     0x021E47C4  data
 */

extern char g_021E47C4[];
extern int func_021E1F6C(int result, int *dwc_error);
extern void func_021E17D8(int line, char *fmt, ...);
extern int func_021E20B8(int process, int result);
extern void DWCi_SetError(int error, int errorCode);

int func_021E20D4(int process, int result)
{
    int error_code;
    int dwc_error;
    int retval;

    retval = func_021E1F6C(result, &dwc_error);
    if (retval != 1) {
        func_021E17D8(0x75b, g_021E47C4, retval);
        error_code = func_021E20B8(process, retval);
        DWCi_SetError(dwc_error, error_code);
    }
    return retval;
}

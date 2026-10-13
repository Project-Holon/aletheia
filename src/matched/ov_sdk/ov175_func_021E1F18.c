/*
 * function: DWCi_GdbHandleStartRequestResult
 * address:  0x021E1F18
 * packet:   pkt_021E1F18
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sDwcGdbErrorFormat   0x021E47B0  data
 *   DWCi_GdbPrintf  0x021E17D8  arm
 *   DWCi_GdbStartRequestResultToError  0x021E1DD0  arm
 *   DWCi_GdbGetStartRequestErrorCode  0x021E1EAC  arm
 *
 * DWCi_GdbHandleStartupResult's sibling with the selector in the second argument: the first
 * argument survives the acquire and is handed to the sub-id allocator.
 */

typedef unsigned int u32;

extern int  DWCi_GdbStartRequestResultToError(int mode, int *out);
extern void DWCi_GdbPrintf(int line, char *fmt, ...);
extern int  DWCi_GdbGetStartRequestErrorCode(int a, int b);
extern void func_02059F54(int a, int b);
extern u32  sDwcGdbErrorFormat[];

int DWCi_GdbHandleStartRequestResult(int a, int mode)
{
    int local;
    int h = DWCi_GdbStartRequestResultToError(mode, &local);

    if (h != 0) {
        DWCi_GdbPrintf(0x6ec, (char *)((int)sDwcGdbErrorFormat), h);
        func_02059F54(local, DWCi_GdbGetStartRequestErrorCode(a, h));
    }
    return h;
}

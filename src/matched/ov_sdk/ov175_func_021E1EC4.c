/*
 * function: DWCi_GdbHandleStartupResult
 * address:  0x021E1EC4
 * packet:   pkt_021E1EC4
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
 *   DWCi_GdbStartupResultToError  0x021E1D70  arm
 *   DWCi_GdbGetStartRequestErrorCode  0x021E1EAC  arm
 *
 * Acquire-by-mode wrapper: the mode the caller passed picks a handle; on
 * success the handle is announced (message 0x6db), a sub-id is allocated and
 * the pair is released.
 */

typedef unsigned int u32;

extern int  DWCi_GdbStartupResultToError(int mode, int *out);
extern void DWCi_GdbPrintf(int line, char *fmt, ...);
extern int  DWCi_GdbGetStartRequestErrorCode(int a, int b);
extern void func_02059F54(int a, int b);
extern u32  sDwcGdbErrorFormat[];

int DWCi_GdbHandleStartupResult(int mode)
{
    int local;
    int h = DWCi_GdbStartupResultToError(mode, &local);

    if (h != 0) {
        DWCi_GdbPrintf(0x6db, (char *)((int)sDwcGdbErrorFormat), h);
        func_02059F54(local, DWCi_GdbGetStartRequestErrorCode(1, h));
    }
    return h;
}

/*
 * file:     unit_021E10CC_p08.c
 * unit:     yes
 * function: func_021E20D4, func_021E212C
 * address:  0x021E20D4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E1F6C  0x021E1F6C  arm  ov175
 *   func_021E17D8  0x021E17D8  arm  ov175
 *   func_021E20B8  0x021E20B8  arm  ov175
 *   DWCi_SetError  0x02059F54  arm
 *   g_021E47C4     0x021E47C4  data
 */
typedef unsigned long u32;

extern int func_021E1F6C(int result, int *dwc_error);
extern void func_021E17D8(int line, char *fmt, ...);
extern int func_021E20B8(int process, int result);
extern void DWCi_SetError(int error, int errorCode);
int func_021E20D4(int process, int result);
void func_021E212C(u32 v);
extern char g_021E47C4[];


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


/*
 * Leaf: writes the triple (2, argument, 0) into the ov175 bss descriptor
 *  *  at 0x021E5334 and reports success.  No lr save: no calls at all.
 */
void func_021E212C(u32 v)
{
    u32 *p = (u32 *)0x021E5334;
    p[2] = 2;
    p[3] = v;
    p[4] = 0;
}

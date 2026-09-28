/*
 * function: func_0205F298
 * address:  0x0205F298
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: ConnectTestCreate (test.o, libdwcac.TWL.HYB.a)
 *
 * symbols:
 *   DWCi_AC_GetMemPtr     0x0205C214  arm
 *   DWC_Netcheck_Create   0x0217A880  arm
 *   DWCi_AC_SetError      0x0205C2E4  arm
 */

extern void *DWCi_AC_GetMemPtr(unsigned long name);
extern int DWC_Netcheck_Create(void *param);
extern void DWCi_AC_SetError(int error);

unsigned char func_0205F298(void)
{
    void *nc = DWCi_AC_GetMemPtr(8);

    if (DWC_Netcheck_Create(nc) == 0)
        return 0xe;
    DWCi_AC_SetError(3);
    return 0x11;
}

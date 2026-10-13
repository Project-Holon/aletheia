/*
 * function: DWCi_IsServerSuspendEnabled
 * address:  0x02175EB4
 * packet:   pkt_ov009_02175EB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_IsServerSuspendEnabled (dwc_match.o)
 *
 * symbols:
 *   DWC_IsServerMyself  0x0216BA08  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

extern int DWC_IsServerMyself(void);
extern int func_02175F3C(void);

int DWCi_IsServerSuspendEnabled(void)
{
    if (DWC_IsServerMyself()) {
        if (*(int *)(func_02175F3C() + 0x61c) == 13 || *(int *)(func_02175F3C() + 0x61c) == 22)
            return 1;
        return 0;
    }
    return 1;
}

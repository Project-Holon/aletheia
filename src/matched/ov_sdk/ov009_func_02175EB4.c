/*
 * function: func_02175EB4
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
 *   func_0216BA08  0x0216BA08  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

extern int func_0216BA08(void);
extern char *func_02175F3C(void);

int func_02175EB4(void)
{
    if (func_0216BA08()) {
        if (*(int *)(func_02175F3C() + 0x61c) == 13 || *(int *)(func_02175F3C() + 0x61c) == 22)
            return 1;
        return 0;
    }
    return 1;
}

/*
 * function: func_021767F4
 * address:  0x021767F4
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Whether this host is the server of a running match that has not been the first server.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWC_IsServerMyself  0x0216BA08  arm  ov009
 *   func_021767E4  0x021767E4  arm  ov009
 */

extern int func_02175F3C(void);
extern int DWC_IsServerMyself(void);
extern int func_021767E4(void);

int func_021767F4(void)
{
    if (*(int *)(func_02175F3C() + 0x7d4) == 0) {
        return 0;
    }
    if (DWC_IsServerMyself() != 0 &&
        (*(unsigned char *)(func_02175F3C() + 0x15) == 1 || *(unsigned char *)(func_02175F3C() + 0x15) == 3 || *(unsigned char *)(func_02175F3C() + 0x15) == 2) &&
        func_021767E4() == 0) {
        return 1;
    }
    return 0;
}

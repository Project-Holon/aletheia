/*
 * function: func_02176410
 * address:  0x02176410
 * packet:   pkt_ov009_02176410
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NodeInfoList_GetNodeInfoForAID (dwc_match.o)
 *
 * Extra open callee of DWCi_DeleteAID (0x0216BCA4).
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

extern char *func_02175F3C(void);

char *func_02176410(unsigned char aid)
{
    int i;

    for (i = 0; i < *(int *)(func_02175F3C() + 0x50); i++) {
        if (aid == *(unsigned char *)(func_02175F3C() + i * 0x28 + 0x6a))
            return func_02175F3C() + 0x54 + i * 0x28;
    }
    return 0;
}

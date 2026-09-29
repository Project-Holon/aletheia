/*
 * function: func_02176474
 * address:  0x02176474
 * packet:   pkt_ov009_02176474
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NodeInfoList_GetFreeAID (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

extern char *func_02175F3C(void);

unsigned char func_02176474(void)
{
    unsigned char i;
    int j;

    if (*(int *)(func_02175F3C() + 0x50) == 32)
        return 0xff;
    for (i = 0; i < 32; i++) {
        for (j = 0; j < *(int *)(func_02175F3C() + 0x50); j++) {
            if (i == *(unsigned char *)(func_02175F3C() + j * 40 + 0x6a))
                break;
        }
        if (j == *(int *)(func_02175F3C() + 0x50))
            return i;
    }
    return 0xff;
}

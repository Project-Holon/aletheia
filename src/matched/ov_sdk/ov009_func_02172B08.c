/*
 * function: DWCi_InvalidateReservation
 * address:  0x02172B08
 * packet:   pkt_ov009_02172B08
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_InvalidateReservation (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_SendMatchCommand  0x0216FF2C  arm  ov009
 *   DWCi_TempNewNodeInfo_Clear  0x0217653C  arm  ov009
 */

extern int func_02175F3C(void);
extern int DWCi_SendMatchCommand(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern void DWCi_TempNewNodeInfo_Clear(void);

int DWCi_InvalidateReservation(void)
{
    int result;
    unsigned long senddata = 0;

    result = 0;
    if (*(unsigned char *)(func_02175F3C() + 0x18) != 0 && *(int *)(func_02175F3C() + 0x5dc) != 0
        && *(int *)(func_02175F3C() + 0x5dc) != *(int *)(func_02175F3C() + 0x678)) {
        result = DWCi_SendMatchCommand(12, *(int *)(func_02175F3C() + 0x5dc), *(int *)(func_02175F3C() + 0x558), *(unsigned short *)(func_02175F3C() + 0x560), (const unsigned int *)(&senddata), 1);
        *(unsigned char *)(func_02175F3C() + 0x18) = 0;
        *(int *)(func_02175F3C() + 0x5dc) = 0;
        DWCi_TempNewNodeInfo_Clear();
    }
    return result;
}

/*
 * function: DWCi_CancelReservation
 * address:  0x02171F68
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sends command 5 to the new node recorded in the temporary node info.
 *
 * symbols:
 *   DWCi_TempNewNodeInfo_IsValid  0x02176554  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_SendMatchCommand  0x0216FF2C  arm  ov009
 */

extern int DWCi_TempNewNodeInfo_IsValid(void);
extern int func_02175F3C(void);
extern int DWCi_SendMatchCommand(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);

int DWCi_CancelReservation(int arg)
{
    int result;

    if (DWCi_TempNewNodeInfo_IsValid() == 0) {
        return 0;
    }
    result = DWCi_SendMatchCommand(5, *(int *)(func_02175F3C() + 0x554), *(unsigned int *)(func_02175F3C() + 0x558),
                           *(unsigned short *)(func_02175F3C() + 0x560), 0, 0);
    *(int *)(func_02175F3C() + 0x67c) = 0;
    return result;
}

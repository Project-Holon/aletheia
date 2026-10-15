/*
 * function: GTSNEGO_DISP_CheckNegotiation
 * address: 0x021D48F0
 * packet: pkt_ov120_021D48F0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_WaitNegotiation 0x021D4864 thumb ov120
 */
extern int GFL_NET_GetRunState(void);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
typedef unsigned char  u8;
extern void GTSNEGO_DISP_WaitNegotiation(u8 *p);
void GTSNEGO_DISP_CheckNegotiation(int *a)
{
    if (GFL_NET_GetRunState() == 0) {
        GTSNEGO_DISP_SetStateCallback(a, (int)((void (*)(int))GTSNEGO_DISP_WaitNegotiation), 0x31d);
        return;
    }
    if (GFL_NET_HANDLE_GetNegotiationNum() != 0 && GFL_NET_HANDLE_CheckNegotiation() != 0)
        GTSNEGO_DISP_SetStateCallback(a, (int)((void (*)(int))GTSNEGO_DISP_WaitNegotiation), 0x322);
}

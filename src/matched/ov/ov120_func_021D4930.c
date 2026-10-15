/*
 * function: GTSNEGO_DISP_WaitPartnerReady
 * address: 0x021D4930
 * packet: pkt_ov120_021D4930
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_UpdatePrintStream 0x021D7AF4 thumb ov120
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_WaitNegotiation 0x021D4864 thumb ov120
 *   GTSNEGO_DISP_CheckNegotiation 0x021D48F0 thumb ov120
 */
#include "../include/Obj05342.h"
typedef unsigned char u8;
extern int GTSNEGO_MSG_UpdatePrintStream(char *p);
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_WaitNegotiation(u8 *p);
extern void GTSNEGO_DISP_CheckNegotiation(int *a);
void GTSNEGO_DISP_WaitPartnerReady(u8 *a)
{
    if (GTSNEGO_MSG_UpdatePrintStream((char *)(((struct Obj05342 *)a)->f40)) != 0) {
        if (((struct Obj05342 *)a)->f14 > 0) {
            ((struct Obj05342 *)a)->f14 = ((struct Obj05342 *)a)->f14 - 1;
            return;
        }
        if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
            if (GFL_NET_HANDLE_CheckNegotiation() != 0) {
                ((struct Obj05342 *)a)->f14 = 0xb4;
                GTSNEGO_DISP_SetStateCallback((int *)a, (int)((void (*)(int))GTSNEGO_DISP_WaitNegotiation), 0x33f);
                return;
            }
        } else {
            ((struct Obj05342 *)a)->f14 = 0xb4;
            GTSNEGO_DISP_SetStateCallback((int *)a, (int)GTSNEGO_DISP_CheckNegotiation, 0x344);
        }
    }
}

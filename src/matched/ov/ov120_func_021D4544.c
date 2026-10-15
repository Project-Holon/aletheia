/*
 * function: GTSNEGO_DISP_WaitTradeStart
 * address: 0x021D4544
 * packet: pkt_ov120_021D4544
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_PrintWindowB 0x021D7A74 thumb ov120
 *   GTSNEGO_MSG_PrintTooltip 0x021D7F5C thumb ov120
 *   GTSNEGO_MSG_DeleteEntryWindow 0x021D80D4 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_ShowTradeReady 0x021D44EC thumb ov120
 */
#include "../include/Obj05340.h"
typedef unsigned short u16;
typedef unsigned char  u8;
extern void GTSNEGO_MSG_PrintWindowB(u8 *p, int n);
extern void GTSNEGO_MSG_PrintTooltip(char *p, u16 n);
extern void GTSNEGO_MSG_DeleteEntryWindow(char *p);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_ShowTradeReady(int);
void GTSNEGO_DISP_WaitTradeStart(int *a)
{
    --((struct Obj05340 *)a)->f14;
    if (((struct Obj05340 *)a)->f14 == 20)
        GTSNEGO_MSG_PrintWindowB((u8 *)(((struct Obj05340 *)a)->f40), 0x27);
    if (((struct Obj05340 *)a)->f14 == 0) {
        GTSNEGO_MSG_PrintTooltip((char *)(((struct Obj05340 *)a)->f40), 0x23);
        GTSNEGO_MSG_DeleteEntryWindow((char *)(((struct Obj05340 *)a)->f40));
        GTSNEGO_DISP_SetStateCallback(a, (int)GTSNEGO_DISP_ShowTradeReady, 0x241);
    }
}

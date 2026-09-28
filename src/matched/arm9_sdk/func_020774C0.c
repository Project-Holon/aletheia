/*
 * function: func_020774C0
 * address:  0x020774C0
 * packet:   pkt_020774C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARD_TerminateForPulledOut (libcard.TWL.HYB.a card_pullout.o)
 *
 * symbols:
 *   PM_ForceToPowerOff  0x0208BEA4  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   PMi_ExecutePostExitCallbackList  0x027315A8  arm
 *   CARDi_SendtoPxi  0x02077568  arm
 *   MI_StopAllDma  0x02082658  arm
 *   MI_StopAllNDma  0x0272FD18  arm
 *   OS_Terminate  0x02088234  arm
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern u32 PM_ForceToPowerOff(void);
extern BOOL OS_IsRunOnTwl(void);
extern void PMi_ExecutePostExitCallbackList(void);
extern void CARDi_SendtoPxi(u32 data, u32 wait);
extern void MI_StopAllDma(void);
extern void MI_StopAllNDma(void);
extern void OS_Terminate(void);

void func_020774C0(void)
{
    if ((*(u16 *)0x02FFFFA8 & 0x8000) >> 15)
    {
        (void)PM_ForceToPowerOff();
    }
    if (OS_IsRunOnTwl())
    {
        PMi_ExecutePostExitCallbackList();
    }
    CARDi_SendtoPxi(1, 1);
    MI_StopAllDma();
    if (OS_IsRunOnTwl())
    {
        MI_StopAllNDma();
    }
    OS_Terminate();
}

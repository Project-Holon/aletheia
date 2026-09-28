/*
 * function: func_02087BCC
 * address:  0x02087BCC
 * packet:   pkt_02087BCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_ResetSystem (os_reset.o)
 *
 * symbols:
 *   OS_IsRunOnTwl                    0x02085D3C  arm
 *   OS_Terminate                     0x02088234  arm
 *   PMi_ExecutePostExitCallbackList  0x027315A8  arm
 *   OS_GetLockID                     0x02084EB8  arm
 *   CARD_LockRom                     0x02075E10  arm
 *   OS_SetIrqMask                    0x0208493C  arm
 *   OS_ResetRequestIrqMask           0x020849C8  arm
 *   MI_StopAllDma                    0x02082658  arm
 *   MI_StopAllNDma                   0x0272FD18  arm
 *   OSi_SendToPxi                    0x02084A84  arm
 *   OSi_DoResetSystem                0x01FF8414  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

typedef long s32;

extern BOOL OS_IsRunOnTwl(void);
extern void OS_Terminate(void);
extern void PMi_ExecutePostExitCallbackList(void);
extern s32 OS_GetLockID(void);
extern void CARD_LockRom(u16 lockID);
extern u32 OS_SetIrqMask(u32 intr);
extern u32 OS_ResetRequestIrqMask(u32 intr);
extern void MI_StopAllDma(void);
extern void MI_StopAllNDma(void);
extern void OSi_SendToPxi(u16 data);
extern void OSi_DoResetSystem(void);

void func_02087BCC(u32 parameter)
{
    if (*(u16 *)0x02FFFC40 == 2
        || (OS_IsRunOnTwl() == 1 && (*(u32 *)0x02FFE234 & 4))) {
        OS_Terminate();
    }

    if (OS_IsRunOnTwl()) {
        PMi_ExecutePostExitCallbackList();
    }

    CARD_LockRom((u16)OS_GetLockID());

    (void)OS_SetIrqMask(0x40000);
    (void)OS_ResetRequestIrqMask((u32)~0);

    MI_StopAllDma();
    if (OS_IsRunOnTwl()) {
        MI_StopAllNDma();
    }

    *(u32 *)0x02FFFC20 = parameter;
    OSi_SendToPxi(0x10);
    OSi_DoResetSystem();
}

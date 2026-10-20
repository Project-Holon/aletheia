/*
 * file:     pm.c
 * unit:     yes
 * function: PMi_GetBatteryLevelCore, PMi_PreSleepForNdma, PMi_ProceedToExit, PM_ReadyToExit, PMi_FinalizeDebugger, PM_GetExitFactor, PM_AppendPreExitCallback, PMi_InsertPostExitCallbackEx, PM_DeletePostExitCallback, PMi_ExecutePostExitCallbackList, PM_SetAutoExit, PM_GetAutoExit, PMi_CallPostExitCallbackAndReset, PMi_TryLockForReset
 * address:  0x027313AC
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      libspi.TWL.HYB.a pm.o
 *
 * symbols:
 *   MI_WaitNDma  0x0272FCB0  arm
 *   MI_StopNDma  0x0272FCE0  arm
 *   MI_StopAllNDma  0x0272FD18  arm
 *   OSi_DisableInterruptsAndHalt  0x020882C0  arm  arm9
 *   GX_DispOff  0x0207D42C  arm  arm9
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   OS_SpinWaitSysCycles  0x02087A04  arm  arm9
 *   MI_StopAllDma  0x02082658  arm  arm9
 *   OSi_SyncWithOtherProc  0x02084AB0  arm  arm9
 *   PMi_InsertList  0x0208C6FC  arm  arm9
 *   PM_SendUtilityCommand  0x0208BC8C  arm  arm9
 *   PMi_PostExitCallbackList  0x02732FAC  data
 *   PMi_ResetLocked  0x02732FA8  data
 */

#include "../types.h"
typedef struct PMiGenCallbackInfo PMiGenCallbackInfo;

typedef struct {
    u32 src;
    u32 dest;
    u32 total;
    u32 wcnt;
    u32 blen;
    u32 fcnt;
    u32 cnt;
} NDmaCh;
#define NDMA ((volatile NDmaCh *)0x04004104)

typedef struct {
    u8 pad[0x14];
    u32 exitFactor;
} S2153;
extern S2153 d_02153000;
#define G2153 (&d_02153000)

extern int PM_SendUtilityCommand(u32 cmd, u32 a, u16 *buf);
extern void MI_WaitNDma(int ch);
extern void MI_StopNDma(int ch);
extern void PMi_ExecuteList(PMiGenCallbackInfo *listp);
extern void PMi_DeleteList(PMiGenCallbackInfo **listp, PMiGenCallbackInfo *info);
extern u32 d_020A8724[];
extern PMiGenCallbackInfo *d_02732FA4;
extern PMiGenCallbackInfo *PMi_PostExitCallbackList;
extern u32 PMi_ResetLocked;
extern void OSi_SyncWithOtherProc(int direction, volatile u8 *p);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 state);
extern void PMi_InsertList(PMiGenCallbackInfo **listp, PMiGenCallbackInfo *info, int priority, int method);
extern void GX_DispOff(void);
extern void OS_SpinWaitSysCycles(u32 n);
extern void MI_StopAllDma(void);
extern void MI_StopAllNDma(void);
extern void OSi_DisableInterruptsAndHalt(void);

void PM_ReadyToExit(void);
void PMi_FinalizeDebugger(void);
void PMi_CallPostExitCallbackAndReset(int flag);
int PMi_TryLockForReset(void);

u32 PMi_GetBatteryLevelCore(u16 *levelBuf)
{
    u16 v;
    int r = PM_SendUtilityCommand(15, 1, &v);
    if (r == 0 && levelBuf != 0) {
        *levelBuf = v;
    }
    return r;
}

void PMi_PreSleepForNdma(int ch)
{
    if (NDMA[ch].cnt & 0x10000000) {
        MI_WaitNDma(ch);
        return;
    }
    switch (NDMA[ch].cnt & 0x0F000000) {
    case 0x04000000:
        while (*(volatile u32 *)0x040001A4 & 0x80000000) {
        }
        return;
    case 0x08000000:
    case 0x09000000:
        MI_WaitNDma(ch);
    case 0x0B000000:
        MI_StopNDma(ch);
        return;
    default:
        if (!(NDMA[ch].cnt & 0x20000000)) {
            MI_WaitNDma(ch);
        } else {
            MI_StopNDma(ch);
        }
        return;
    }
}

void PMi_ProceedToExit(u32 factor)
{
    PMiGenCallbackInfo *list;
    if (PMi_TryLockForReset() == 0) {
        return;
    }
    list = *(PMiGenCallbackInfo **)0x02732FA4;
    G2153->exitFactor = factor;
    PMi_ExecuteList(list);
    if (d_020A8724[1] != 0) {
        PM_ReadyToExit();
    }
}

void PM_ReadyToExit(void)
{
    PMi_CallPostExitCallbackAndReset(1);
}

void PMi_FinalizeDebugger(void)
{
    volatile u8 *a = (volatile u8 *)0x02FFFFF0;
    *(volatile u8 *)0x02FFFFF4 = 0;
    OSi_SyncWithOtherProc(0, a);
    OSi_SyncWithOtherProc(1, a);
    OS_DisableInterrupts();
    *(volatile u8 *)0x02FFFFF4 = 1;
}

u32 PM_GetExitFactor(void)
{
    return G2153->exitFactor;
}

void PM_AppendPreExitCallback(PMiGenCallbackInfo *info)
{
    PMi_InsertList(&d_02732FA4, info, 0xFF, 0);
}

void PMi_InsertPostExitCallbackEx(PMiGenCallbackInfo *info, int priority)
{
    PMi_InsertList(&PMi_PostExitCallbackList, info, priority, 0);
}

void PM_DeletePostExitCallback(PMiGenCallbackInfo *info)
{
    PMi_DeleteList(&PMi_PostExitCallbackList, info);
}

/* sdk: PMi_ExecutePostExitCallbackList (pm.o, .ltdmain; no catalogue row) */
void PMi_ExecutePostExitCallbackList(void)
{
    PMi_ExecuteList(PMi_PostExitCallbackList);
}

void PM_SetAutoExit(u32 enable)
{
    d_020A8724[1] = enable;
}

u32 PM_GetAutoExit(void)
{
    return d_020A8724[1];
}

/* power-off sequence (callbacks, wait three ticks, request until the status word reads zero, shutdown calls) */
void PMi_CallPostExitCallbackAndReset(int flag)
{
    u32 cmd;
    int i;
    int sel;
    u16 buf;

    PMi_ExecuteList(PMi_PostExitCallbackList);
    GX_DispOff();
    *(volatile u32 *)0x04001000 &= ~0x10000;
    *(volatile u16 *)0x04000204 |= 0x8000;
    for (i = 0; i < 3; i++) {
        u32 t = *(volatile u32 *)0x02FFFC3C;
        while (t == *(volatile u32 *)0x02FFFC3C)
            OS_SpinWaitSysCycles(0x32);
    }
    sel = (flag != 0);
    for (;;) {
        cmd = sel ? 0x14 : 0x13;
        if (*(volatile u32 *)0x02FFF684 == 1) {
            cmd = 0x14;
            *(volatile u32 *)0x02000300 = 0;
        }
        if (PM_SendUtilityCommand(cmd, 0, &buf) != 0) {
            do {
                OS_SpinWaitSysCycles(0x51D23);
            } while (PM_SendUtilityCommand(cmd, 0, &buf) != 0);
        }
        if (buf == 0)
            break;
        OS_SpinWaitSysCycles(0x51D23);
    }
    OS_DisableInterrupts();
    MI_StopAllDma();
    MI_StopAllNDma();
    PMi_FinalizeDebugger();
    OSi_DisableInterruptsAndHalt();
}

int PMi_TryLockForReset(void)
{
    u32 state = OS_DisableInterrupts();
    if (PMi_ResetLocked != 0) {
        OS_RestoreInterrupts(state);
        return 0;
    }
    PMi_ResetLocked = 1;
    OS_RestoreInterrupts(state);
    return 1;
}

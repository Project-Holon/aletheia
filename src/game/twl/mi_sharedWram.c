/*
 * file:     mi_sharedWram.c
 * unit:     yes
 * function: MIi_GetWramBank_A, MIi_GetWramBank_B, MIi_GetWramBank_C, MIi_SetWramBankMaster_A, MIi_SetWramBankMaster_B, MIi_SetWramBankMaster_C, MIi_SetWramBankMaster, MIi_SetWramBankEnable_A, MIi_SetWramBankEnable_B, MIi_SetWramBankEnable_C, MIi_SetWramBankEnable, MI_GetWramBankMaster_A, MI_GetWramBankMaster_B, MI_GetWramBankMaster_C, MI_GetWramBankMaster, MI_GetWramMapStart_A, MI_GetWramMapStart_B, MI_GetWramMapStart_C, MI_GetWramMapStart, MIi_GetAddress_A, MIi_GetAddress_B, MIi_GetAddress_C, MIi_InitWramManager, MIi_CallbackForPxi, MIi_DoAllocWram, MI_AllocWramSlot, MIi_DoAllocWramSlot, MI_FreeWram, MIi_DoFreeWram, MI_FreeWramSlot, MIi_DoFreeWramSlot, MIi_DoSwitchWram, MIi_DoSwitchWramSlot, MIi_DoReserveWram, MIi_DoReserveWramSlot, MI_CancelWram, MIi_DoCancelWram, MIi_DoCancelWramSlot, MIi_DoGetAllocatableWramSlot, MI_IsWramSlotUsed, MIi_SendToPxi, MIi_TakeApartData, MI_LockWramManager, MI_UnlockWramManager, MIi_LockWramManagerDI, MIi_UnlockWramManagerRI
 * address:  0x02730210
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      libmi.TWL.HYB.a mi_sharedwram.o
 *
 * symbols:
 *   SVC_WaitByLoop  0x02004490  thumb  arm9
 *   OS_GetLockID  0x02084EB8  arm  arm9
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   PXI_SendWordByFifo  0x02088610  arm  arm9
 *   OS_LockByWord  0x02084C68  arm  arm9
 *   OS_UnlockByWord  0x02084CEC  arm  arm9
 *   OS_ReleaseLockID  0x02084F10  arm  arm9
 *   PXI_SetFifoRecvCallback  0x020885A0  arm  arm9
 *   MIi_GetWramBankMasterFuncs                0x027301E0  data
 *   MIi_GetWramMapStartFuncs                0x027301EC  data
 *   MIi_SetWramBankEnableFuncs                0x027301F8  data
 *   MIi_SetWramBankMasterFuncs                0x02730204  data
 *   data_02732F5C                0x02732F5C  data
 *   data_02732F60                0x02732F60  data
 *   data_02732F64                0x02732F64  data
 *   data_02732F68                0x02732F68  data
 *   data_02732F6C                0x02732F6C  data
 */

#include "../types.h"

#define PIN(g, i) (((volatile u16 (*)[8])data_02732F6C)[g][i])

extern void (*const MIi_SetWramBankMasterFuncs[])(u32, u32);
extern void (*const MIi_SetWramBankEnableFuncs[])(u32, u32);
extern u32 (*const MIi_GetWramBankMasterFuncs[])(u32);
extern u32 (*const MIi_GetWramMapStartFuncs[])(void);

typedef unsigned int OSIntrMode;
#include "../arm9/os_system.h"
#ifdef __MWERKS__
extern u32 OS_GetLockID(void);
extern void OS_LockByWord(u32, void *, void *); /* original prototype; the definition differs in argument width, pointer type, return type, type */
extern void OS_UnlockByWord(u32, void *, void *); /* original prototype; the definition differs in argument width, pointer type, return type, type */
extern void OS_ReleaseLockID(u32);
#else
#include "../arm9/os_spinlock.h"
#endif
#include "../arm9/pxi_fifo.h"
#include "../arm9/svc_wait_by_loop.h"
#include "../arm9/pxi_fifo.h"
extern int data_02732F5C;
extern int *data_02732F60;
extern u32 *data_02732F64;
extern int data_02732F68;
extern u16 data_02732F6C[3][8];

u32 MIi_GetAddress_A(u32 a);
static u32 MIi_GetAddress_B(u32 a);
static u32 MIi_GetAddress_C(u32 a);
void MIi_InitWramManager(void);
void MIi_CallbackForPxi(int tag, u32 data, BOOL err);
u32 MIi_DoAllocWram(u32 ch, int n, u32 val);
u32 MI_AllocWramSlot(u32 ch, int start, int n, u32 val);
u32 MIi_DoAllocWramSlot(u32 ch, int start, int n, u32 val);
u32 MI_FreeWram(u32 ch, u32 val);
u32 MIi_DoFreeWram(u32 ch, u32 val);
u32 MI_FreeWramSlot(u32 ch, int start, int n, u32 val);
u32 MIi_DoFreeWramSlot(u32 ch, int start, int n, u32 val);
u32 MIi_DoSwitchWram(u32 ch, u32 val, u32 newval);
u32 MIi_DoSwitchWramSlot(u32 ch, int start, int n, u32 val, u32 newval);
u32 MIi_DoReserveWram(u32 ch, int n, u32 val);
u32 MIi_DoReserveWramSlot(u32 ch, int start, int n, u32 val);
u32 MI_CancelWram(u32 ch, u32 val);
u32 MIi_DoCancelWram(u32 ch, u32 val);
u32 MIi_DoCancelWramSlot(u32 ch, int start, int n, u32 val);
u32 MIi_DoGetAllocatableWramSlot(u32 ch, u32 val);
u32 MI_IsWramSlotUsed(u32 ch, u32 idx);
void MIi_SendToPxi(u32 a, u32 b);
void MIi_TakeApartData(u32 data, u32 *cmd, u32 *ch, u32 *sub, u32 *arg);
void MI_LockWramManager(u16 *p);
void MI_UnlockWramManager(u32 id);
u32 MIi_LockWramManagerDI(u16 *p);
void MIi_UnlockWramManagerRI(u32 id, u32 irq);

/* Register accessors: the argument is a register-block base. */
u32 MIi_GetWramBank_A(u32 bank)
{
    return *(u8 *)(bank + 0x04004040);
}

u32 MIi_GetWramBank_B(u32 bank)
{
    return *(u8 *)(bank + 0x04004044);
}

u32 MIi_GetWramBank_C(u32 bank)
{
    return *(u8 *)(bank + 0x0400404C);
}

void MIi_SetWramBankMaster_A(u32 bank, u32 master)
{
    *(u8 *)(bank + 0x04004040) = (*(u8 *)(bank + 0x04004040) & ~1) | master;
}

void MIi_SetWramBankMaster_B(u32 bank, u32 master)
{
    *(u8 *)(bank + 0x04004044) = (*(u8 *)(bank + 0x04004044) & ~3) | master;
}

void MIi_SetWramBankMaster_C(u32 bank, u32 master)
{
    *(u8 *)(bank + 0x0400404C) = (*(u8 *)(bank + 0x0400404C) & ~3) | master;
}

void MIi_SetWramBankMaster(u32 type, u32 bank, u32 master)
{
    MIi_SetWramBankMasterFuncs[type](bank, master);
}

/* Register field writers: bit 7 of a byte register set or cleared by a flag. */
void MIi_SetWramBankEnable_A(u32 bank, u32 enable)
{
    volatile u8 *p = (volatile u8 *)(bank + 0x04004040);
    u32 v = enable ? 0x80 : 0;
    *p = (*p & ~0x80) | v;
}

void MIi_SetWramBankEnable_B(u32 bank, u32 enable)
{
    volatile u8 *p = (volatile u8 *)(bank + 0x04004044);
    u32 v = enable ? 0x80 : 0;
    *p = (*p & ~0x80) | v;
}

void MIi_SetWramBankEnable_C(u32 bank, u32 enable)
{
    volatile u8 *p = (volatile u8 *)(bank + 0x0400404C);
    u32 v = enable ? 0x80 : 0;
    *p = (*p & ~0x80) | v;
}

void MIi_SetWramBankEnable(u32 type, u32 bank, u32 enable)
{
    MIi_SetWramBankEnableFuncs[type](bank, enable);
}

/* Register readers: the argument is a register-block base, the mask picks the field. */
u32 MI_GetWramBankMaster_A(u32 bank)
{
    return *(u8 *)(bank + 0x04004040) & 1;
}

u32 MI_GetWramBankMaster_B(u32 bank)
{
    return *(u8 *)(bank + 0x04004044) & 3;
}

u32 MI_GetWramBankMaster_C(u32 bank)
{
    return *(u8 *)(bank + 0x0400404C) & 3;
}

u32 MI_GetWramBankMaster(u32 type, u32 bank)
{
    return MIi_GetWramBankMasterFuncs[type](bank);
}

u32 MI_GetWramMapStart_A(void)
{
    return ((((*(volatile u32 *)0x04004054) & 0xFF0) >> 4) << 16) + 0x03000000;
}

u32 MI_GetWramMapStart_B(void)
{
    return ((((*(volatile u32 *)0x04004058) & 0xFF8) >> 3) << 15) + 0x03000000;
}

u32 MI_GetWramMapStart_C(void)
{
    return ((((*(volatile u32 *)0x0400405C) & 0xFF8) >> 3) << 15) + 0x03000000;
}

u32 MI_GetWramMapStart(u32 type)
{
    return MIi_GetWramMapStartFuncs[type]();
}

u32 MIi_GetAddress_A(u32 bank)
{
    return MI_GetWramMapStart_A() + (bank << 16);
}

static u32 MIi_GetAddress_B(u32 bank)
{
    return MI_GetWramMapStart_B() + (bank << 15);
}

static u32 MIi_GetAddress_C(u32 bank)
{
    return MI_GetWramMapStart_C() + (bank << 15);
}

void MIi_InitWramManager(void)
{
    int i;
    if (data_02732F5C != 0) {
        return;
    }
    data_02732F5C = 1;
    for (i = 0; i < 4; i++) {
        switch (MIi_GetWramBank_A(i) & 1) {
        case 0:
            PIN(0, i) = PIN(0, i) & ~0x300;
            PIN(0, i) = PIN(0, i) & ~3;
            break;
        case 1:
            PIN(0, i) = (PIN(0, i) & ~0x300) | 0x100;
            PIN(0, i) = (PIN(0, i) & ~3) | 1;
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        switch (MIi_GetWramBank_B(i) & 3) {
        case 0:
            PIN(1, i) = PIN(1, i) & ~0x300;
            PIN(1, i) = PIN(1, i) & ~3;
            break;
        case 1:
            PIN(1, i) = (PIN(1, i) & ~0x300) | 0x100;
            PIN(1, i) = (PIN(1, i) & ~3) | 1;
            break;
        default:
            PIN(1, i) = (PIN(1, i) & ~0x300) | 0x200;
            PIN(1, i) = (PIN(1, i) & ~3) | 2;
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        switch (MIi_GetWramBank_C(i) & 3) {
        case 0:
            PIN(2, i) = PIN(2, i) & ~0x300;
            PIN(2, i) = PIN(2, i) & ~3;
            break;
        case 1:
            PIN(2, i) = (PIN(2, i) & ~0x300) | 0x100;
            PIN(2, i) = (PIN(2, i) & ~3) | 1;
            break;
        default:
            PIN(2, i) = (PIN(2, i) & ~0x300) | 0x200;
            PIN(2, i) = (PIN(2, i) & ~3) | 2;
            break;
        }
    }
    PXI_SetFifoRecvCallback(0x12, MIi_CallbackForPxi);
}

void MIi_CallbackForPxi(int tag, u32 data, BOOL err)
{
    u32 cmd, arg, ch, sub;
    u32 result;

    if (err == 0) {
    result = 0;

    MIi_TakeApartData(data, &cmd, &ch, &sub, &arg);
    switch (cmd) {
    case 1:
        result = MIi_DoAllocWram(ch, (arg >> 8) & 0xFF, sub);
        break;
    case 2:
        result = MIi_DoAllocWramSlot(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 3:
        result = MIi_DoFreeWram(ch, sub);
        break;
    case 4:
        result = MIi_DoFreeWramSlot(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 5:
        result = MIi_DoSwitchWram(ch, sub, (arg >> 12) & 3);
        break;
    case 6:
        result = MIi_DoSwitchWramSlot(ch, (arg >> 8) & 0xF, arg & 0xFF, sub, (arg >> 12) & 3);
        break;
    case 7:
        result = MIi_DoReserveWram(ch, arg & 0xFF, sub);
        break;
    case 8:
        result = MIi_DoReserveWramSlot(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 9:
        result = MIi_DoCancelWram(ch, sub);
        break;
    case 10:
        result = MIi_DoCancelWramSlot(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 11:
        result = (data_02732F6C[ch][arg] & 0x300) >> 8;
        break;
    case 14:
        result = MIi_DoGetAllocatableWramSlot(ch, sub) & 0xFF;
        break;
    }
    MIi_SendToPxi(1, result);
    } else {
        if (data_02732F64 != 0) {
            *data_02732F64 = data;
        }
        if (data_02732F60 != 0) {
            *data_02732F60 = 1;
        }
        data_02732F68 = 0;
    }
}

u32 MIi_DoAllocWram(u32 ch, int num, u32 proc)
{
    int run, start, i, lim;

    if (ch == 0) {
        num = num / 2;
    }
    run = 0;
    lim = 4;
    if (ch != 0) {
        lim = 8;
    }
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        u32 cur = (v & 0x300) >> 8;
        if ((v & 3) == 3 && (cur == proc || cur == 3)) {
            if (run == 0) {
                start = i;
            }
            run++;
            if (run >= num) {
                break;
            }
        } else {
            run = 0;
        }
    }
    if (run < num) {
        return 0;
    }
    for (i = 0; i < num; i++) {
        data_02732F6C[ch][start + i] = (data_02732F6C[ch][start + i] & ~3) | proc;
        MIi_SetWramBankMaster(ch, start + i, proc);
        MIi_SetWramBankEnable(ch, start + i, 1);
    }
    if (ch == 0) {
        return MIi_GetAddress_A(start);
    }
    if (ch == 1) {
        return MIi_GetAddress_B(start);
    }
    if (ch == 2) {
        return MIi_GetAddress_C(start);
    }
    return 0;
}

u32 MI_AllocWramSlot(u32 ch, int start, int num, u32 proc)
{
    u16 sv;
    u32 irq, r;

    irq = MIi_LockWramManagerDI(&sv);
    r = MIi_DoAllocWramSlot(ch, start, num, proc);
    MIi_UnlockWramManagerRI(sv, irq);
    return r;
}

u32 MIi_DoAllocWramSlot(u32 ch, int start, int num, u32 proc)
{
    int end, i;

    if (ch == 0) {
        num = num / 2;
    }
    end = start + num;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][i];
        u32 cur = (v & 0x300) >> 8;
        if ((v & 3) != 3 || (cur != proc && cur != 3)) {
            return 0;
        }
    }
    for (i = start; i < end; i++) {
        data_02732F6C[ch][i] = (data_02732F6C[ch][i] & ~3) | proc;
        MIi_SetWramBankMaster(ch, i, proc);
        MIi_SetWramBankEnable(ch, i, 1);
    }
    if (ch == 0) {
        return MIi_GetAddress_A(start);
    }
    if (ch == 1) {
        return MIi_GetAddress_B(start);
    }
    if (ch == 2) {
        return MIi_GetAddress_C(start);
    }
    return 0;
}

u32 MI_FreeWram(u32 ch, u32 proc)
{
    u16 sv;
    u32 irq, r;

    irq = MIi_LockWramManagerDI(&sv);
    r = MIi_DoFreeWram(ch, proc);
    MIi_UnlockWramManagerRI(sv, irq);
    return r;
}

u32 MIi_DoFreeWram(u32 ch, u32 proc)
{
    int lim, i, count;

    count = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        if ((v & 3) == proc) {
            data_02732F6C[ch][i] = (v & ~3) | 3;
            MIi_SetWramBankMaster(ch, i, 1);
            MIi_SetWramBankEnable(ch, i, 0);
            count++;
        }
    }
    return count;
}

u32 MI_FreeWramSlot(u32 ch, int start, int num, u32 proc)
{
    u16 sv;
    u32 irq, r;

    irq = MIi_LockWramManagerDI(&sv);
    r = MIi_DoFreeWramSlot(ch, start, num, proc);
    MIi_UnlockWramManagerRI(sv, irq);
    return r;
}

u32 MIi_DoFreeWramSlot(u32 ch, int start, int num, u32 proc)
{
    int count, i, end;

    if (ch == 0) {
        num = num / 2;
    }
    end = start + num;
    count = 0;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][i];
        if ((v & 3) == proc) {
            data_02732F6C[ch][i] = (v & ~3) | 3;
            MIi_SetWramBankMaster(ch, i, 1);
            MIi_SetWramBankEnable(ch, i, 0);
            count++;
        }
    }
    return count;
}

u32 MIi_DoSwitchWram(u32 ch, u32 proc, u32 newProc)
{
    int lim, i, count;

    count = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        if ((v & 3) == proc) {
            data_02732F6C[ch][i] = newProc | (v & ~3);
            MIi_SetWramBankMaster(ch, i, newProc);
            MIi_SetWramBankEnable(ch, i, 1);
            count++;
        }
    }
    return count;
}

u32 MIi_DoSwitchWramSlot(u32 ch, int start, int num, u32 proc, u32 newProc)
{
    int count, i, end;

    if (ch == 0) {
        num = num / 2;
    }
    end = start + num;
    count = 0;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][i];
        if ((v & 3) == proc) {
            data_02732F6C[ch][i] = newProc | (v & ~3);
            MIi_SetWramBankMaster(ch, i, newProc);
            MIi_SetWramBankEnable(ch, i, 1);
            count++;
        }
    }
    return count;
}

u32 MIi_DoReserveWram(u32 ch, int num, u32 proc)
{
    int run, start, i, lim;

    if (ch == 0) {
        num = num / 2;
    }
    run = 0;
    lim = 4;
    if (ch != 0) {
        lim = 8;
    }
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        u32 cur = (v & 0x300) >> 8;
        if ((v & 3) == 3 && cur == 3) {
            if (run == 0) {
                start = i;
            }
            run++;
            if (run >= num) {
                break;
            }
        } else {
            run = 0;
        }
    }
    if (run < num) {
        return 0;
    }
    for (i = 0; i < num; i++) {
        data_02732F6C[ch][start + i] = (data_02732F6C[ch][start + i] & ~0x300) | (proc << 8);
    }
    if (ch == 0) {
        return MIi_GetAddress_A(start);
    }
    if (ch == 1) {
        return MIi_GetAddress_B(start);
    }
    if (ch == 2) {
        return MIi_GetAddress_C(start);
    }
    return 0;
}

u32 MIi_DoReserveWramSlot(u32 ch, int start, int num, u32 proc)
{
    int i, end;

    if (ch == 0) {
        num = num / 2;
    }
    end = start + num;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][start];
        int hi = v & 0x300;
        if ((v & 3) != 3 || (hi >> 8) != 3) {
            return 0;
        }
    }
    for (i = start; i < end; i++) {
        data_02732F6C[ch][i] = (data_02732F6C[ch][i] & ~0x300) | (proc << 8);
    }
    if (ch == 0) {
        return MIi_GetAddress_A(start);
    }
    if (ch == 1) {
        return MIi_GetAddress_B(start);
    }
    if (ch == 2) {
        return MIi_GetAddress_C(start);
    }
    return 0;
}

u32 MI_CancelWram(u32 ch, u32 proc)
{
    u16 sv;
    u32 irq, r;

    irq = MIi_LockWramManagerDI(&sv);
    r = MIi_DoCancelWram(ch, proc);
    MIi_UnlockWramManagerRI(sv, irq);
    return r;
}

u32 MIi_DoCancelWram(u32 ch, u32 proc)
{
    int count, i, lim;

    count = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        if (proc == ((v & 0x300) >> 8)) {
            data_02732F6C[ch][i] = (v & ~0x300) | 0x300;
            count++;
        }
    }
    return count;
}

u32 MIi_DoCancelWramSlot(u32 ch, int start, int num, u32 proc)
{
    int count, i, end;

    if (ch == 0) {
        num = num / 2;
    }
    end = start + num;
    count = 0;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][i];
        if (proc == ((v & 0x300) >> 8)) {
            data_02732F6C[ch][i] = (v & ~0x300) | 0x300;
            count++;
        }
    }
    return count;
}

u32 MIi_DoGetAllocatableWramSlot(u32 ch, u32 proc)
{
    u32 mask;
    int i, lim;

    mask = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        u32 cur = (v & 0x300) >> 8;
        if ((v & 3) == 3 && (cur == proc || cur == 3)) {
            mask |= 1 << i;
        }
    }
    return mask;
}

u32 MI_IsWramSlotUsed(u32 ch, u32 idx)
{
    return (data_02732F6C[ch][idx] & 3) != 3;
}

void MIi_SendToPxi(u32 err, u32 data)
{
    while (PXI_SendWordByFifo(0x12, data, err) != 0) {
        SVC_WaitByLoop(1);
    }
}

void MIi_TakeApartData(u32 data, u32 *cmd, u32 *ch, u32 *sub, u32 *arg)
{
    if (cmd != 0) {
        *cmd = (data >> 20) & 0xF;
    }
    if (ch != 0) {
        *ch = (data >> 18) & 3;
    }
    if (sub != 0) {
        *sub = (data >> 16) & 3;
    }
    if (arg != 0) {
        *arg = (u16)data;
    }
}

void MI_LockWramManager(u16 *id)
{
    *id = OS_GetLockID();
    OS_LockByWord(*id, (void *)0x02FFF680, 0);
}

void MI_UnlockWramManager(u32 id)
{
    OS_UnlockByWord(id, (void *)0x02FFF680, 0);
    OS_ReleaseLockID(id);
}

u32 MIi_LockWramManagerDI(u16 *id)
{
    u32 irq = OS_DisableInterrupts();
    MI_LockWramManager(id);
    return irq;
}

void MIi_UnlockWramManagerRI(u32 id, u32 irq)
{
    MI_UnlockWramManager(id);
    OS_RestoreInterrupts(irq);
}

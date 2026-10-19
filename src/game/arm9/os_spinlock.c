/*
 * file:     os_spinlock.c
 * unit:     yes
 * function: OSi_SyncWithOtherProc, OS_InitLock, OSi_DoLockByWord, OS_LockByWord, OSi_DoUnlockByWord, OS_UnlockByWord, OSi_DoTryLockByWord, OS_TryLockByWord, OS_UnlockCartridge, OS_UnLockCartridge, OS_TryLockCartridge, OSi_AllocateCartridgeBus, OSi_FreeCartridgeBus, OS_LockCard, OS_UnlockCard, OS_UnLockCard, OS_TryLockCard, OSi_AllocateCardBus, OSi_FreeCardBus, OS_ReadOwnerOfLockWord, OS_GetLockID, OS_ReleaseLockID
 * address:  0x02084AB0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * note:     hand-written SDK asm stub: `ldr r1, =target; bx r1` (a compiled
 *           tail call spends ip in ARM, never r1), wave 17 lane untried_small
 *
 * symbols:
 *   SVC_WaitByLoop  0x02004490  thumb
 *   MIi_CpuClear32         0x02082A7C  arm
 *   OSi_SyncWithOtherProc  0x02084AB0  arm
 *   OSi_DoLockByWord  0x02084C1C  arm
 *   OS_DisableInterrupts            0x02087988  arm
 *   OS_RestoreInterrupts            0x0208799C  arm
 *   OS_DisableInterrupts_IrqAndFiq  0x020879B4  arm
 *   OS_RestoreInterrupts_IrqAndFiq  0x020879C8  arm
 *   MI_SwapWord                     0x020834B8  arm
 *   OSi_DoUnlockByWord    0x02084C78  arm
 *   OSi_FreeCartridgeBus  0x02084DDC  arm
 *   .bss                   0x02150FCC  data
 *   OS_LockByWord        0x02084C68  arm
 *   OSi_AllocateCardBus  0x02084E54  arm
 */
#include "../types.h"

#include "../sdk_os.h"

typedef struct OSLockWord {
    volatile u32 lockFlag;
    volatile u16 ownerID;
    volatile u16 extension;
} OSLockWord;

extern void SVC_WaitByLoop(int v);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
extern OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void OSi_SyncWithOtherProc(int direction, volatile u8 *regs);
extern u32 MI_SwapWord(u32 setData, volatile u32 *destp);
extern s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
extern void OSi_FreeCartridgeBus(void);
int OS_LockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
void OSi_AllocateCardBus(void);
void OS_InitLock(void);
void OSi_DoLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
s32 OS_UnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32 OSi_DoTryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
s32 OS_TryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32 OS_UnlockCartridge(u16 lockID);
asm void OS_UnLockCartridge(int lockID);
s32 OS_TryLockCartridge(u16 lockID);
void OSi_AllocateCartridgeBus(void);
int OS_LockCard(unsigned short lockID);
s32 OS_UnlockCard(u16 lockID);
asm void OS_UnLockCard(void);
s32 OS_TryLockCard(u16 lockID);
void OSi_FreeCardBus(void);
unsigned short OS_ReadOwnerOfLockWord(char *lock);
asm s32 OS_GetLockID(void);
asm void OS_ReleaseLockID(u16 lockID);

/*
 * Bit-banged ack protocol over a four-byte register window.  direction == 0
 * selects the send direction: the window is walked with the nibble counter in
 * the top bit, and the loop only advances when the peer answers regs[2].
 * direction != 0 is the receive direction: regs[1] mirrors regs[0] and the
 * mirrored bytes are accumulated until the sum passes 0x300, then the window is
 * re-armed and the final handshake waits for regs[3].
 *
 * The window pointer is `volatile`: every store is followed by a fresh load of
 * the same byte in the image (strb r0,[r5] then ldrb r1,[r5]; strb r6,[r5,#1]
 * then ldrb r1,[r5,#1]), which a non-volatile pointer would let the compiler
 * forward.
 */
void OSi_SyncWithOtherProc(int direction, volatile u8 *regs)
{
    if (direction == 0) {
        int nibble = 0;

        regs[2] = 0;
        do {
            regs[0] = (u8)((nibble & 0xf) | 0x80);
            while (regs[0] != regs[1] && regs[2] == 0) {
                SVC_WaitByLoop(0x400);
            }
            nibble++;
        } while (regs[2] == 0);
        regs[3] = 1;
    } else {
        int sum = 0;

        regs[1] = 0;
        while (sum < 0x300) {
            if (regs[1] != regs[0]) {
                regs[1] = regs[0];
                sum += regs[1];
            } else {
                SVC_WaitByLoop(0x400);
            }
        }
        regs[3] = 0;
        regs[2] = 1;
        while (regs[3] == 0) {
            SVC_WaitByLoop(0x400);
        }
    }
}

/*
 * sdk:      OS_InitLock (os_spinlock.o)
 *
 * notes:    code bytes identical with isInitialized as a function-local static.
 *           Both the vendor object and this compile relocate that pool word
 *           against the .bss section symbol with addend 0; the symbols: line
 *           `.bss 0x02150FCC data` names the member's .bss base, accepted by
 *           the section-relative rule (the witness is sole-ref/self).
 */
void OS_InitLock(void)
{
    static BOOL isInitialized;
    OSLockWord *lockp = (OSLockWord *)0x02FFFFB0;

    if (isInitialized) {
        return;
    }
    isInitialized = 1;

    ((u32 *)lockp)[0] = 0xFFFFFFFF;
    ((u32 *)lockp)[1] = 0xFFFF0000;
    MIi_CpuClear32(0, (void *)(0x02FFFFB0 + 0x10), 0x28);

    *(volatile u16 *)0x04000204 = (u16)(*(volatile u16 *)0x04000204 | 0x800);
    *(volatile u16 *)0x04000204 = (u16)(*(volatile u16 *)0x04000204 | 0x80);

    OSi_SyncWithOtherProc(0, (void *)(0x02FFFFB0 + 0x40));
    OSi_SyncWithOtherProc(1, (void *)(0x02FFFFB0 + 0x40));
}

void OSi_DoLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
{
    if (OSi_DoTryLockByWord(lockID, lockp, ctrlFuncp, disableFIQ) <= 0)
        return;
    do {
        SVC_WaitByLoop(0x400);
    } while (OSi_DoTryLockByWord(lockID, lockp, ctrlFuncp, disableFIQ) > 0);
}

/*
 * sdk:      OS_LockByWord (os_spinlock.o), the FIQ-disabled wrapper of OSi_DoLockByWord
 */
int OS_LockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void))
{
    OSi_DoLockByWord(lockID, lockp, ctrlFuncp, 0);
}

/*
 * sdk:      OSi_DoUnlockByWord (os_spinlock.o)
 */
s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
{
    OSIntrMode enabled;

    if (lockID != lockp->ownerID) {
        return -2;
    }

    if (disableFIQ) {
        enabled = OS_DisableInterrupts_IrqAndFiq();
    } else {
        enabled = OS_DisableInterrupts();
    }

    lockp->ownerID = 0;
    if (ctrlFuncp) {
        ctrlFuncp();
    }
    lockp->lockFlag = 0;

    if (disableFIQ) {
        (void)OS_RestoreInterrupts_IrqAndFiq(enabled);
    } else {
        (void)OS_RestoreInterrupts(enabled);
    }
    return 0;
}

s32 OS_UnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void))
{
    return OSi_DoUnlockByWord(lockID, lockp, ctrlFuncp, 0);
}

/*
 * sdk:      OSi_DoTryLockByWord (os_spinlock.o)
 */
s32 OSi_DoTryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
{
    s32 lastLockFlag;
    OSIntrMode enabled;

    if (disableFIQ) {
        enabled = OS_DisableInterrupts_IrqAndFiq();
    } else {
        enabled = OS_DisableInterrupts();
    }

    lastLockFlag = (s32)MI_SwapWord(lockID, &lockp->lockFlag);

    if (!lastLockFlag) {
        if (ctrlFuncp) {
            ctrlFuncp();
        }
        lockp->ownerID = lockID;
    }

    if (disableFIQ) {
        (void)OS_RestoreInterrupts_IrqAndFiq(enabled);
    } else {
        (void)OS_RestoreInterrupts(enabled);
    }
    return lastLockFlag;
}

s32 OS_TryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void))
{
    return OSi_DoTryLockByWord(lockID, lockp, ctrlFuncp, 0);
}

/*
 * sdk:      OS_UnlockCartridge (os_spinlock.o); catalogued as OS_LockCartridge, see note
 * note:     the image's pool words name OSi_FreeCartridgeBus (0x02084DDC) and
 *           OSi_DoUnlockByWord (0x02084C78), so this row is OS_UnlockCartridge,
 *           not the catalogue's OS_LockCartridge (same 32-byte shape).
 */
s32 OS_UnlockCartridge(u16 lockID)
{
    return OSi_DoUnlockByWord(lockID, (OSLockWord *)0x02FFFFE8, OSi_FreeCartridgeBus, 1);
}

/* hand-written in the original: ldr r1, =target; bx r1 stub, a compiled tail call uses ip */
asm void OS_UnLockCartridge(int lockID)
{
    ldr r1, =OS_UnlockCartridge
    bx r1
}

s32 OS_TryLockCartridge(u16 lockID)
{
    return OSi_DoTryLockByWord(lockID, (struct OSLockWord *)0x02FFFFE8, OSi_AllocateCartridgeBus, 1);
}

/*
 * note:     os_spinLock.o OSi_AllocateCartridgeBus (EXMEMCNT bit7 -> ARM9).
 */
void OSi_AllocateCartridgeBus(void)
{
    unsigned int v = *(volatile unsigned short *)0x04000204;

    v &= ~0x80u;
    *(volatile unsigned short *)0x04000204 = (unsigned short)v;
}

/*
 * note:     os_spinLock.o OSi_FreeCartridgeBus (EXMEMCNT bit7 -> ARM7).
 */
void OSi_FreeCartridgeBus(void)
{
    *(volatile unsigned short *)0x04000204 |= 0x80;
}

/*
 * note:     os_spinLock.o OS_LockCard; HW_CARD_LOCK_BUF = 0x02FFFFE0.
 */
int OS_LockCard(unsigned short lockID)
{
    return OS_LockByWord(lockID, (OSLockWord *)0x02FFFFE0, OSi_AllocateCardBus);
}

s32 OS_UnlockCard(u16 lockID)
{
    return OS_UnlockByWord(lockID, (struct OSLockWord *)0x02FFFFE0, OSi_FreeCardBus);
}

/* hand-written in the original: ldr r1, =target; bx r1 stub, a compiled tail call uses ip */
asm void OS_UnLockCard(void)
{
    ldr r1, =OS_UnlockCard
    bx	r1
}

s32 OS_TryLockCard(u16 lockID)
{
    return OS_TryLockByWord(lockID, (OSLockWord *)0x02FFFFE0, OSi_AllocateCardBus);
}

/*
 * sdk:      OSi_AllocateCardBus (os_spinlock.o)
 */
void OSi_AllocateCardBus(void)
{
    if (((*(volatile u16 *)0x04004010 & 0xC) >> 2) == 2) {
        *(volatile u32 *)0x040001A4 |= 0x20000000;
    }
    *(volatile u16 *)0x04000204 = (u16)(*(volatile u16 *)0x04000204 & ~0x800);
}

/*
 * note:     os_spinLock.o OSi_FreeCardBus (EXMEMCNT bit11 -> ARM7).
 */
void OSi_FreeCardBus(void)
{
    *(volatile unsigned short *)0x04000204 |= 0x800;
}

unsigned short OS_ReadOwnerOfLockWord(char *lock)
{
    return ((OSLockWord *)lock)->ownerID;
}

/*
 * sdk:      OS_GetLockID (os_spinlock.o)
 * asm:      hand-written in the object: needs clz, the subprogram has no
 *           DW_TAG_variable, and .debug_line gives each instruction its own
 *           strictly increasing line (836..898), the asm-function pattern.
 */
/* hand-written in the original: clz and a lock-bit scan across two words, the asm OS_GetLockID shape */
asm s32 OS_GetLockID(void)
{
    ldr     r3, =0x02FFFFB0
    ldr     r1, [r3, #0]
    clz     r2, r1
    cmp     r2, #32
    movne   r0, #0x40
    bne     _1
    add     r3, r3, #4
    ldr     r1, [r3, #0]
    clz     r2, r1
    cmp     r2, #32
    ldr     r0, =0xFFFFFFFD
    bxeq    lr
    mov     r0, #0x60
_1:
    add     r0, r0, r2
    mov     r1, #0x80000000
    mov     r1, r1, lsr r2
    ldr     r2, [r3, #0]
    bic     r2, r2, r1
    str     r2, [r3, #0]
    bx      lr
}

/*
 * sdk:      OS_ReleaseLockID (os_spinlock.o)
 * asm:      hand-written in the object: the subprogram has no DW_TAG_variable
 *           and .debug_line gives each instruction its own strictly
 *           increasing line (914..929), the asm-function pattern; the body
 *           selects its word with flag-conditional addpl/subpl/submi.
 */
/*
 * hand-written in the original: the os_spinlock.o DWARF has the asm-function
 * pattern (above). mwccarm does emit pl/mi, but only after a flag-setting
 * subs (`if ((s32)(id - 0x60) >= 0)` gives subs/addpl/submi); a cmp it
 * predicates with ge/lt. It also folds the mask shift into the orr (orr
 * rX, rY, rZ, lsr rW) and loads the word first. Here cmp is followed by a
 * recomputing subpl, a separate mov/lsr and a late ldr: not compiler output.
 */
asm void OS_ReleaseLockID(u16 lockID)
{
    ldr     r3, =0x02FFFFB0
    cmp     r0, #0x60
    addpl   r3, r3, #4
    subpl   r0, r0, #0x60
    submi   r0, r0, #0x40
    mov     r1, #0x80000000
    mov     r1, r1, lsr r0
    ldr     r2, [r3, #0]
    orr     r2, r2, r1
    str     r2, [r3, #0]
    bx      lr
}

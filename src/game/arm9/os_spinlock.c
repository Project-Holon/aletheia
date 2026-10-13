/*
 * file:     os_spinlock.c
 * unit:     yes
 * function: func_02084AB0, func_02084B90, func_02084C1C, func_02084C68, func_02084C78, func_02084CEC, func_02084CFC, func_02084D68, func_02084D78, OS_UnLockCartridge, func_02084DA4, func_02084DC4, func_02084DDC, func_02084DF4, func_02084E10, OS_UnLockCard, func_02084E38, func_02084E54, func_02084E98, OS_ReadOwnerOfLockWord, OS_GetLockID, func_02084F10
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
 *   FSi_HasEnoughSpaceInFreeArea  0x02084C1C  arm
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
#include "../../matched/include/Obj16691.h"

struct _FSFreeAreaSize;
struct OSLockWord;
typedef unsigned char u8;

typedef unsigned long u32;

typedef long s32_02084AB0;

typedef unsigned short u16;

typedef int BOOL;

typedef u32 OSIntrMode;

typedef struct OSLockWord {
    volatile u32 lockFlag;
    volatile u16 ownerID;
    volatile u16 extension;
} OSLockWord;

typedef signed int     s32_02084D98;

typedef signed int     s32_02084DA4;

typedef long s32_02084E38;

typedef long s32_02084EB8;

extern void SVC_WaitByLoop(int v);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
extern OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void OSi_SyncWithOtherProc(int type, void *syncBuf);
extern u32 MI_SwapWord(u32 setData, volatile u32 *destp);
extern s32_02084AB0 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
extern void OSi_FreeCartridgeBus(void);
int OS_LockByWord(unsigned short lockID, void *lockBuf, void (*ctrlFuncp)(void));
void OSi_AllocateCardBus(void);
void func_02084AB0(int a0, volatile u8 *p);
void func_02084B90(void);
void func_02084C1C(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
void func_02084C68(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32_02084AB0 func_02084C78(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
s32_02084AB0 func_02084CEC(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32_02084AB0 func_02084CFC(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
s32_02084AB0 func_02084D68(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32_02084AB0 func_02084D78(u16 lockID);
asm void OS_UnLockCartridge(int lockID);
s32_02084DA4 OS_TryLockCartridge(u16 lockID);
void func_02084DC4(void);
void func_02084DDC(void);
int func_02084DF4(unsigned short lockID);
s32_02084DA4 func_02084E10(u16 lockID);
asm void OS_UnLockCard(void);
s32_02084E38 OS_TryLockCard(u16 lockID);
void func_02084E54(void);
void func_02084E98(void);
unsigned short OS_ReadOwnerOfLockWord(char *lock);
asm s32_02084EB8 OS_GetLockID(void);
asm void func_02084F10(u16 lockID);







/*
 * Bit-banged ack protocol over a four-byte register window.  a0 == 0 selects
 * the send direction: the window is walked with the nibble counter in the top
 * bit, and the loop only advances when the peer answers p[2].  a0 != 0 is the
 * receive direction: p[1] mirrors p[0] and the mirrored bytes are accumulated
 * until the sum passes 0x300, then the window is re-armed and the final handshake
 * waits for p[3].
 *
 * The window pointer is `volatile`: every store is followed by a fresh load of
 * the same byte in the image (strb r0,[r5] then ldrb r1,[r5]; strb r6,[r5,#1]
 * then ldrb r1,[r5,#1]), which a non-volatile pointer would let the compiler
 * forward.
 */
void func_02084AB0(int a0, volatile u8 *p)
{
    if (a0 == 0) {
        int i = 0;

        p[2] = 0;
        do {
            p[0] = (u8)((i & 0xf) | 0x80);
            while (p[0] != p[1] && p[2] == 0) {
                SVC_WaitByLoop(0x400);
            }
            i++;
        } while (p[2] == 0);
        p[3] = 1;
    } else {
        int sum = 0;

        p[1] = 0;
        while (sum < 0x300) {
            if (p[1] != p[0]) {
                p[1] = p[0];
                sum += p[1];
            } else {
                SVC_WaitByLoop(0x400);
            }
        }
        p[3] = 0;
        p[2] = 1;
        while (p[3] == 0) {
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
void func_02084B90(void)
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





void func_02084C1C(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
{
    if (func_02084CFC(lockID, lockp, ctrlFuncp, disableFIQ) <= 0)
        return;
    do {
        SVC_WaitByLoop(0x400);
    } while (func_02084CFC(lockID, lockp, ctrlFuncp, disableFIQ) > 0);
}






/*
 * sdk:      FSi_HasEnoughSpaceToCreateUserFile (libfs.TWL.HYB.a fs_sysareaex.o)
 */
void func_02084C68(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void))
{
    func_02084C1C(lockID, lockp, ctrlFuncp, 0);
}






/*
 * sdk:      OSi_DoUnlockByWord (os_spinlock.o)
 */
s32_02084AB0 func_02084C78(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
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





s32_02084AB0 func_02084CEC(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void))
{
    return func_02084C78(lockID, lockp, ctrlFuncp, 0);
}





/*
 * sdk:      OSi_DoTryLockByWord (os_spinlock.o)
 */
s32_02084AB0 func_02084CFC(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
{
    s32_02084AB0 lastLockFlag;
    OSIntrMode enabled;

    if (disableFIQ) {
        enabled = OS_DisableInterrupts_IrqAndFiq();
    } else {
        enabled = OS_DisableInterrupts();
    }

    lastLockFlag = (s32_02084AB0)MI_SwapWord(lockID, &lockp->lockFlag);

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




s32_02084AB0 func_02084D68(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void))
{
    return func_02084CFC(lockID, lockp, ctrlFuncp, 0);
}




/*
 * sdk:      OS_UnlockCartridge (os_spinlock.o); catalogued as OS_LockCartridge, see note
 * note:     the image's pool words name OSi_FreeCartridgeBus (0x02084DDC) and
 *           OSi_DoUnlockByWord (0x02084C78), so this row is OS_UnlockCartridge,
 *           not the catalogue's OS_LockCartridge (same 32-byte shape).
 */
s32_02084AB0 func_02084D78(u16 lockID)
{
    return OSi_DoUnlockByWord(lockID, (OSLockWord *)0x02FFFFE8, OSi_FreeCartridgeBus, 1);
}


/* hand-written in the original: ldr r1, =target; bx r1 stub, a compiled tail call uses ip */
asm void OS_UnLockCartridge(int lockID)
{
    ldr r1, =func_02084D78
    bx r1
}



s32_02084DA4 OS_TryLockCartridge(u16 lockID)
{
    return func_02084CFC(lockID, (struct OSLockWord *)0x02FFFFE8, func_02084DC4, 1);
}


/*
 * note:     os_spinLock.o OSi_AllocateCartridgeBus (EXMEMCNT bit7 -> ARM9).
 */
void func_02084DC4(void)
{
    unsigned int v = *(volatile unsigned short *)0x04000204;

    v &= ~0x80u;
    *(volatile unsigned short *)0x04000204 = (unsigned short)v;
}


/*
 * note:     os_spinLock.o OSi_FreeCartridgeBus (EXMEMCNT bit7 -> ARM7).
 */
void func_02084DDC(void)
{
    *(volatile unsigned short *)0x04000204 |= 0x80;
}



/*
 * note:     os_spinLock.o OS_LockCard; HW_CARD_LOCK_BUF = 0x02FFFFE0.
 */
int func_02084DF4(unsigned short lockID)
{
    return OS_LockByWord(lockID, (void *)0x02FFFFE0, OSi_AllocateCardBus);
}



s32_02084DA4 func_02084E10(u16 lockID)
{
    return func_02084CEC(lockID, (struct OSLockWord *)0x02FFFFE0, func_02084E98);
}


/* hand-written in the original: ldr r1, =target; bx r1 stub, a compiled tail call uses ip */
asm void OS_UnLockCard(void)
{
    ldr r1, =func_02084E10
    bx	r1
}



s32_02084E38 OS_TryLockCard(u16 lockID)
{
    return func_02084D68(lockID, (OSLockWord *)0x02FFFFE0, func_02084E54);
}



/*
 * sdk:      OSi_AllocateCardBus (os_spinlock.o)
 */
void func_02084E54(void)
{
    if (((*(volatile u16 *)0x04004010 & 0xC) >> 2) == 2) {
        *(volatile u32 *)0x040001A4 |= 0x20000000;
    }
    *(volatile u16 *)0x04000204 = (u16)(*(volatile u16 *)0x04000204 & ~0x800);
}


/*
 * note:     os_spinLock.o OSi_FreeCardBus (EXMEMCNT bit11 -> ARM7).
 */
void func_02084E98(void)
{
    *(volatile unsigned short *)0x04000204 |= 0x800;
}


unsigned short OS_ReadOwnerOfLockWord(char *lock)
{
    return ((struct Obj16691 *)lock)->f4;
}



/*
 * sdk:      OS_GetLockID (os_spinlock.o)
 * asm:      hand-written in the object: needs clz, the subprogram has no
 *           DW_TAG_variable, and .debug_line gives each instruction its own
 *           strictly increasing line (836..898), the asm-function pattern.
 */
/* hand-written in the original: clz and a lock-bit scan across two words, the asm OS_GetLockID shape */
asm s32_02084EB8 OS_GetLockID(void)
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
 * subs (`if ((s32_02084EB8)(id - 0x60) >= 0)` gives subs/addpl/submi); a cmp it
 * predicates with ge/lt. It also folds the mask shift into the orr (orr
 * rX, rY, rZ, lsr rW) and loads the word first. Here cmp is followed by a
 * recomputing subpl, a separate mov/lsr and a late ldr: not compiler output.
 */
asm void func_02084F10(u16 lockID)
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

/*
 * file:     unit_02084AB0.c
 * unit:     yes
 * function: func_02084AB0, func_02084B90, func_02084C1C, func_02084C68, func_02084C78, func_02084CEC, func_02084CFC, func_02084D68, func_02084D78
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
 * symbols:
 *   func_02004490  0x02004490  thumb
 *   MIi_CpuClear32         0x02082A7C  arm
 *   OSi_SyncWithOtherProc  0x02084AB0  arm
 *   .bss                   0x02150FCC  data
 *   FSi_HasEnoughSpaceInFreeArea  0x02084C1C  arm
 *   OS_DisableInterrupts            0x02087988  arm
 *   OS_RestoreInterrupts            0x0208799C  arm
 *   OS_DisableInterrupts_IrqAndFiq  0x020879B4  arm
 *   OS_RestoreInterrupts_IrqAndFiq  0x020879C8  arm
 *   MI_SwapWord                     0x020834B8  arm
 *   OSi_DoUnlockByWord    0x02084C78  arm
 *   OSi_FreeCartridgeBus  0x02084DDC  arm
 */
struct _FSFreeAreaSize;
typedef unsigned char u8;

typedef unsigned long u32;

typedef long s32;

typedef unsigned short u16;

typedef int BOOL;

typedef u32 OSIntrMode;

typedef struct OSLockWord {
    volatile u32 lockFlag;
    volatile u16 ownerID;
    volatile u16 extension;
} OSLockWord;

extern void func_02004490(int v);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
extern OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void OSi_SyncWithOtherProc(int type, void *syncBuf);
extern u32 MI_SwapWord(u32 setData, volatile u32 *destp);
extern s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
extern void OSi_FreeCartridgeBus(void);
void func_02084AB0(int a0, volatile u8 *p);
void func_02084B90(void);
void func_02084C1C(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
void func_02084C68(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32 func_02084C78(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
s32 func_02084CEC(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32 func_02084CFC(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
s32 func_02084D68(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32 func_02084D78(u16 lockID);






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
                func_02004490(0x400);
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
                func_02004490(0x400);
            }
        }
        p[3] = 0;
        p[2] = 1;
        while (p[3] == 0) {
            func_02004490(0x400);
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
        func_02004490(0x400);
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
s32 func_02084C78(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
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




s32 func_02084CEC(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void))
{
    return func_02084C78(lockID, lockp, ctrlFuncp, 0);
}




/*
 * sdk:      OSi_DoTryLockByWord (os_spinlock.o)
 */
s32 func_02084CFC(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
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



s32 func_02084D68(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void))
{
    return func_02084CFC(lockID, lockp, ctrlFuncp, 0);
}



/*
 * sdk:      OS_UnlockCartridge (os_spinlock.o); catalogued as OS_LockCartridge, see note
 * note:     the image's pool words name OSi_FreeCartridgeBus (0x02084DDC) and
 *           OSi_DoUnlockByWord (0x02084C78), so this row is OS_UnlockCartridge,
 *           not the catalogue's OS_LockCartridge (same 32-byte shape).
 */
s32 func_02084D78(u16 lockID)
{
    return OSi_DoUnlockByWord(lockID, (OSLockWord *)0x02FFFFE8, OSi_FreeCartridgeBus, 1);
}

/*
 * function: OS_UnlockCartridge
 * address:  0x02084D78
 * packet:   pkt_02084D78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_UnlockCartridge (os_spinlock.o); catalogued as OS_LockCartridge, see note
 * note:     the image's pool words name OSi_FreeCartridgeBus (0x02084DDC) and
 *           OSi_DoUnlockByWord (0x02084C78), so this row is OS_UnlockCartridge,
 *           not the catalogue's OS_LockCartridge (same 32-byte shape).
 *
 * symbols:
 *   OSi_DoUnlockByWord    0x02084C78  arm
 *   OSi_FreeCartridgeBus  0x02084DDC  arm
 */

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

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
extern OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);

extern s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
extern void OSi_FreeCartridgeBus(void);

s32 OS_UnlockCartridge(u16 lockID)
{
    return OSi_DoUnlockByWord(lockID, (OSLockWord *)0x02FFFFE8, OSi_FreeCartridgeBus, 1);
}

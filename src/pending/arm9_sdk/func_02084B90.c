/*
 * function: func_02084B90
 * address:  0x02084B90
 * packet:   pkt_02084B90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      OS_InitLock (os_spinlock.o)
 *
 * notes:    code bytes identical with isInitialized as a function-local static; its
 *           .bss relocation (image 0x02150FCC, object symbol _ZZ11OS_InitLockvE13isInitialized)
 *           cannot be named, so it stays wildcarded.  Declared as an extern at that address
 *           the compiler no longer hoists the lock-word store above the flag store (DIFF);
 *           400-round permuter run (seed 12402) found nothing.
 *
 * symbols:
 *   MIi_CpuClear32         0x02082A7C  arm
 *   OSi_SyncWithOtherProc  0x02084AB0  arm
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

extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void OSi_SyncWithOtherProc(int type, void *syncBuf);

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

/*
 * file:     unit_02084E38.c
 * unit:     yes
 * function: func_02084E38, func_02084E54, func_02084E98
 * address:  0x02084E38
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
 *   func_02084D68 0x02084D68 arm
 */
struct _FSFreeAreaSize;
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

extern int func_02084D68(struct _FSFreeAreaSize *freesize, char *path, unsigned long size);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
extern OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);
asm void OS_LockCard(void);
void func_02084E54(void);
void func_02084E98(void);


asm void OS_LockCard(void)
{
    ldr r1, =0x02FFFFE0
    ldr r2, =func_02084E54
    ldr ip, =func_02084D68
    bx	ip
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

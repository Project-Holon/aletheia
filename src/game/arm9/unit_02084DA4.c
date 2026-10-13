/*
 * file:     unit_02084DA4.c
 * unit:     yes
 * function: func_02084DA4, func_02084DC4, func_02084DDC, func_02084DF4, func_02084E10
 * address:  0x02084DA4
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
 *   func_02084CFC 0x02084CFC arm
 *   OS_LockByWord        0x02084C68  arm
 *   OSi_AllocateCardBus  0x02084E54  arm
 *   func_02084CEC 0x02084CEC arm
 *   func_02084E98 0x02084E98 arm
 */
struct OSLockWord;
struct _FSFreeAreaSize;
typedef signed int     s32;

typedef unsigned short u16;

extern s32 func_02084CFC(u16 lockID, struct OSLockWord *lockp, void (*ctrlFuncp)(void), int disableFIQ);
int OS_LockByWord(unsigned short lockID, void *lockBuf, void (*ctrlFuncp)(void));
void OSi_AllocateCardBus(void);
extern s32 func_02084CEC(u16 lockID, struct OSLockWord *lockp, void (*ctrlFuncp)(void));
extern void func_02084E98(void);
s32 OS_TryLockCartridge(u16 lockID);
void func_02084DC4(void);
void func_02084DDC(void);
int func_02084DF4(unsigned short lockID);
s32 func_02084E10(u16 lockID);


s32 OS_TryLockCartridge(u16 lockID)
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


s32 func_02084E10(u16 lockID)
{
    return func_02084CEC(lockID, (struct OSLockWord *)0x02FFFFE0, func_02084E98);
}

#ifndef GAME_ARM9_OS_SPINLOCK_H
#define GAME_ARM9_OS_SPINLOCK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_spinlock.c, prototypes copied from their definitions. */

struct OSLockWord;
typedef struct OSLockWord OSLockWord;

#include "../types.h"

void OSi_SyncWithOtherProc(int direction, volatile u8 *regs);
void OS_InitLock(void);
void OSi_DoLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
int OS_LockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
s32 OS_UnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32 OSi_DoTryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
s32 OS_TryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32 OS_UnlockCartridge(u16 lockID);
void OS_UnLockCartridge(u16 lockID);
s32 OS_TryLockCartridge(u16 lockID);
void OSi_AllocateCartridgeBus(void);
void OSi_FreeCartridgeBus(void);
int OS_LockCard(unsigned short lockID);
s32 OS_UnlockCard(u16 lockID);
void OS_UnLockCard(u16 lockID);
s32 OS_TryLockCard(u16 lockID);
void OSi_AllocateCardBus(void);
void OSi_FreeCardBus(void);
unsigned short OS_ReadOwnerOfLockWord(char *lock);
s32 OS_GetLockID(void);
void OS_ReleaseLockID(u16 lockID);
/* END mkheaders: generated region */

typedef struct OSLockWord OSLockWord;

#endif

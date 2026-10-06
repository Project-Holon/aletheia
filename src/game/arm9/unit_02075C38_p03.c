/*
 * file:     unit_02075C38_p03.c
 * unit:     yes
 * function: func_02075DEC, func_02075DF8, func_02075E04, func_02075E10, func_02075E80, func_02075E9C, func_02075EAC
 * address:  0x02075DEC
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
 *   .word 0x02FFFA80
 *
 *   CARDi_LockResource  0x02075ED4  arm
 *   OS_InitEvent  0x020882DC  arm
 *   OS_CreateVAlarm  0x020876A4  arm
 *   CARDi_PeekEventListener  0x02075C38  arm
 *   OS_WaitEventEx  0x020882F0  arm
 *   CARDi_LockBusCondition  0x02075C90  arm
 *   func_02084E10   0x02084E10  arm
 *   func_02075F4C   0x02075F4C  arm
 *   func_02075ED4 0x02075ED4 arm
 *   CARD_TryWaitBackupAsync  0x02076B8C  arm
 *   CARD_WaitBackupAsync  0x02076B80  arm
 *   CARDi_UnlockResource  0x02075F4C  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef long s32_02075E10;

typedef int BOOL;

typedef struct OSEvent
{
    u8 data[0xC];
} OSEvent;

typedef struct OSiVAlarm
{
    u8 data[0x28];
} OSiVAlarm;

typedef struct CARDEventListener
{
    OSEvent event[1];
    OSiVAlarm alarm[1];
    BOOL (*func)(void *);
    void *arg;
    u16 lockID;
    u8 padding[2];
} CARDEventListener;

typedef signed int     s32_4;

typedef signed int     s32_5;

typedef long s32_02075EAC;

extern void CARDi_LockResource(s32_02075E10 owner, int target);
extern void OS_InitEvent(OSEvent *event);
extern void OS_CreateVAlarm(OSiVAlarm *alarm);
extern void CARDi_PeekEventListener(void *arg);
extern u32 OS_WaitEventEx(OSEvent *event, u32 pattern, int mode, u32 clearBit);
extern BOOL CARDi_LockBusCondition(void *userdata);
extern int func_02084E10(unsigned int id);
extern void func_02075F4C(s32_4 owner, int target);
extern void func_02075ED4(s32_5 owner, int target);
extern BOOL CARD_TryWaitBackupAsync(void);
extern BOOL CARD_WaitBackupAsync(void);
extern void CARDi_UnlockResource(s32_02075EAC owner, int target);
void *CARD_GetRomHeader(void);
void *CARD_GetOwnRomHeader(void);
void *CARD_GetOwnRomHeaderTWL(void);
void func_02075E10(u16 lock_id);
void CARD_UnlockRom(unsigned int id);
asm void CARD_LockBackup(void);
void func_02075EAC(u16 lock_id);

void *CARD_GetRomHeader(void)
{
    return (void *)0x02FFFA80;
}

void *CARD_GetOwnRomHeader(void)
{
    return (void *)0x02FFFE00;
}

void *CARD_GetOwnRomHeaderTWL(void)
{
    return (void *)0x02FFE000;
}


/*
 * sdk:      CARD_LockRom (libcard.TWL.HYB.a card_api.o)
 */
void func_02075E10(u16 lock_id)
{
    CARDEventListener el[1];

    CARDi_LockResource(lock_id, 1);
    OS_InitEvent(el->event);
    OS_CreateVAlarm(el->alarm);
    el->func = CARDi_LockBusCondition;
    el->arg = &lock_id;
    CARDi_PeekEventListener(el);
    (void)OS_WaitEventEx(el->event, 1, 0, 1);
}


void CARD_UnlockRom(unsigned int id)
{
    func_02084E10(id);
    func_02075F4C(id, 1);
}

asm void CARD_LockBackup(void)
{
    ldr ip, =func_02075ED4
    mov r1, #2
    bx ip
}


/*
 * sdk:      CARD_UnlockBackup (libcard.TWL.HYB.a card_api.o)
 */
void func_02075EAC(u16 lock_id)
{
    if (!CARD_TryWaitBackupAsync())
    {
        (void)CARD_WaitBackupAsync();
    }
    CARDi_UnlockResource(lock_id, 2);
}

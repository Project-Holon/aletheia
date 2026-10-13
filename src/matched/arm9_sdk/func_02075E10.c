/*
 * function: CARD_LockRom
 * address:  0x02075E10
 * packet:   pkt_02075E10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARD_LockRom (libcard.TWL.HYB.a card_api.o)
 *
 * symbols:
 *   CARDi_LockResource  0x02075ED4  arm
 *   OS_InitEvent  0x020882DC  arm
 *   OS_CreateVAlarm  0x020876A4  arm
 *   CARDi_PeekEventListener  0x02075C38  arm
 *   OS_WaitEventEx  0x020882F0  arm
 *   CARDi_LockBusCondition  0x02075C90  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
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

extern void CARDi_LockResource(s32 owner, int target);
extern void OS_InitEvent(OSEvent *event);
extern void OS_CreateVAlarm(OSiVAlarm *alarm);
extern void CARDi_PeekEventListener(void *arg);
extern u32 OS_WaitEventEx(OSEvent *event, u32 pattern, int mode, u32 clearBit);
extern BOOL CARDi_LockBusCondition(void *userdata);

void CARD_LockRom(u16 lock_id)
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

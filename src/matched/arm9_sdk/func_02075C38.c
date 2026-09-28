/*
 * function: func_02075C38
 * address:  0x02075C38
 * packet:   pkt_02075C38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_PeekEventListener (libcard.TWL.HYB.a card_api.o)
 *
 * symbols:
 *   OS_SignalEvent  0x02088398  arm
 *   OS_SetVAlarm  0x020876B8  arm
 *   CARDi_PeekEventListener  0x02075C38  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef short s16;
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
} CARDEventListener;

extern void OS_SignalEvent(OSEvent *event, u32 setPattern);
extern void OS_SetVAlarm(OSiVAlarm *alarm, s16 count, s16 delay, void (*handler)(void *), void *arg);

void func_02075C38(void *arg)
{
    CARDEventListener *el = (CARDEventListener *)arg;

    if ((*el->func)(el->arg))
    {
        OS_SignalEvent(el->event, 1);
    }
    else
    {
        OS_SetVAlarm(el->alarm, 192, 263, func_02075C38, el);
    }
}

/*
 * function: func_02089540
 * address:  0x02089540
 * packet:   pkt_02089540
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_SetupAlarm (snd_interface.o)
 *
 * symbols:
 *   SNDi_SetAlarmHandler  0x02089FE0  arm
 *   PushCommand_impl      0x02089804  arm
 */

typedef unsigned long u32;
typedef void (*SNDAlarmHandler)(void *arg);

extern unsigned char SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg);
extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void func_02089540(int alarmNo, u32 tick, u32 period, SNDAlarmHandler handler, void *arg)
{
    unsigned char id = SNDi_SetAlarmHandler(alarmNo, handler, arg);

    PushCommand_impl(0x12, (u32)alarmNo, tick, period, id);
}

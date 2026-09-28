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
 * symbols:
 *   SNDi_SetAlarmHandler 0x02089FE0 arm
 *   PushCommand_impl     0x02089804 arm
 *
 * snd_interface.o SND_SetupAlarm.
 */

extern int SNDi_SetAlarmHandler(void *handler, int arg);
extern void PushCommand_impl(int id, int arg0, int arg1, int arg2, int arg3);

void func_02089540(int alarmNo, int tick, int period, void *handler, int arg)
{
    int id = SNDi_SetAlarmHandler(handler, arg);

    PushCommand_impl(18, alarmNo, tick, period, id);
}

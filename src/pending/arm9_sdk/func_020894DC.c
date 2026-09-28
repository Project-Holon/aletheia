/*
 * function: func_020894DC
 * address:  0x020894DC
 * packet:   pkt_020894DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SNDi_IncAlarmId  0x02089FC0 arm
 *   PushCommand_impl 0x02089804 arm
 *
 * snd_interface.o SND_StopTimer.  Walk the alarm bit mask, bumping every
 * standing alarm id, then issue command 13.
 */

extern void SNDi_IncAlarmId(int alarmNo);
extern void PushCommand_impl(int id, int arg0, int arg1, int arg2, int arg3);

void func_020894DC(int chBitMask, int capBitMask, int alarmBitMask, int flags)
{
    int mask;
    int alarmNo;

    for (mask = alarmBitMask, alarmNo = 0; alarmNo < 8 && mask != 0;
         alarmNo++, mask >>= 1) {
        if (mask & 1) {
            SNDi_IncAlarmId(alarmNo);
        }
    }
    PushCommand_impl(13, chBitMask, capBitMask, alarmBitMask, flags);
}

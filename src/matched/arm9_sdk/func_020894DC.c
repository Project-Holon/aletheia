/*
 * function: SND_StopTimer
 * address:  0x020894DC
 * packet:   pkt_020894DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_StopTimer (snd_interface.o)
 *
 * symbols:
 *   SNDi_IncAlarmId   0x02089FC0  arm
 *   PushCommand_impl  0x02089804  arm
 */

typedef unsigned long u32;

extern void SNDi_IncAlarmId(int alarmNo);
extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void SND_StopTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags)
{
    int alarmNo;
    u32 mask;

    mask = alarmBitMask;
    for (alarmNo = 0; alarmNo < 8 && mask != 0; alarmNo++, mask >>= 1) {
        if (mask & 1) {
            SNDi_IncAlarmId(alarmNo);
        }
    }
    PushCommand_impl(0xd, chBitMask, capBitMask, alarmBitMask, flags);
}

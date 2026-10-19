/*
 * file:     snd_interface.c
 * unit:     yes
 * function: SND_StopSeq, SND_PrepareSeq, SND_StartPreparedSeq, SND_PauseSeq, SND_SetPlayerTempoRatio, SND_SetPlayerVolume, SND_SetPlayerChannelPriority, SND_SetTrackVolume, SND_SetTrackPitch, SND_SetTrackPan, SND_SetTrackModDepth, SND_SetTrackModSpeed, SND_SetTrackAllocatableChannel, SND_StartTimer, SND_StopTimer, SND_SetupAlarm, SND_SetTrackMute, SND_SetTrackMuteEx, SND_LockChannel, SND_UnlockChannel, SND_SetChannelTimer, SND_SetChannelVolume, SND_SetupChannelPcm, SND_InvalidateSeqData, SND_InvalidateBankData, SND_InvalidateWaveData, SND_SetMasterVolume, SND_SetOutputSelector, SND_SetMasterPan, SND_ResetMasterPan, SND_ReadDriverInfo, SNDi_SetPlayerParam, SNDi_SetTrackParam, PushCommand_impl
 * address:  0x02089330
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
 *   PushCommand_impl  0x02089804  arm
 *   SNDi_IncAlarmId   0x02089FC0  arm
 *   SNDi_SetAlarmHandler  0x02089FE0  arm
 *   SND_AllocCommand  0x02089A78  arm
 *   SND_PushCommand   0x02089B00  arm
 */
struct SNDBankData;
struct SNDDriverInfo;
typedef void (*SNDAlarmHandler)(void *arg);

typedef unsigned long u32;

typedef struct SNDCommand {
    struct SNDCommand *next;
    int id;
    u32 arg[4];
} SNDCommand;

extern void PushCommand_impl(int id, u32 value0, u32 value1, u32 value2, u32 value3);
extern void SNDi_IncAlarmId(int alarmNo);
extern unsigned char SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg);
extern SNDCommand *SND_AllocCommand(u32 flags);
extern void SND_PushCommand(SNDCommand *command);
void SND_StopSeq(int playerNo);
void SND_PrepareSeq(int playerNo, const void *base, u32 offset, struct SNDBankData *bank);
void SND_StartPreparedSeq(u32 playerNo);
void SND_PauseSeq(int playerNo, int flag);
void SND_SetPlayerTempoRatio(int playerNo, int ratio);
void SND_SetPlayerVolume(int playerNo, int volume);
void SND_SetPlayerChannelPriority(int playerNo, int prio);
void SND_SetTrackVolume(int playerNo, u32 trackBitMask, int volume);
void SND_SetTrackPitch(int playerNo, u32 trackBitMask, int pitch);
void SND_SetTrackPan(int playerNo, u32 trackBitMask, int pan);
void SND_SetTrackModDepth(int playerNo, u32 trackBitMask, u32 depth);
void SND_SetTrackModSpeed(int playerNo, u32 trackBitMask, u32 speed);
void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask);
void SND_StartTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void SND_StopTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void SND_SetupAlarm(int alarmNo, u32 tick, u32 period, SNDAlarmHandler handler, void *arg);
void SND_SetTrackMute(int playerNo, u32 trackBitMask, int flag);
void SND_SetTrackMuteEx(int playerNo, u32 trackBitMask, int mute);
void SND_LockChannel(u32 chBitMask, u32 flags);
void SND_UnlockChannel(u32 chBitMask, u32 flags);
void SND_SetChannelTimer(u32 chBitMask, int timer);
void SND_SetChannelVolume(u32 chBitMask, int volume, int shift);
void SND_SetupChannelPcm(int chNo, int format, const void *dataaddr, int loop, int loopStart, int loopLen, int volume, int shift, int timer, int pan);
void SND_InvalidateSeqData(const void *start, const void *end);
void SND_InvalidateBankData(const void *start, const void *end);
void SND_InvalidateWaveData(const void *start, const void *end);
void SND_SetMasterVolume(int volume);
void SND_SetOutputSelector(int left, int right, int channel1, int channel3);
void SND_SetMasterPan(int pan);
void SND_ResetMasterPan(void);
void SND_ReadDriverInfo(struct SNDDriverInfo *info);
void SNDi_SetPlayerParam(int playerNo, u32 offset, u32 data, int size);
void SNDi_SetTrackParam(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size);



/*
 * sdk:      SND_StopSeq (snd_interface.o)
 */
void SND_StopSeq(int playerNo)
{
    PushCommand_impl(1, (u32)playerNo, 0, 0, 0);
}



/*
 * sdk:      SND_PrepareSeq (snd_interface.o)
 */
void SND_PrepareSeq(int playerNo, const void *base, u32 offset, struct SNDBankData *bank)
{
    PushCommand_impl(2, (u32)playerNo, (u32)base, offset, (u32)bank);
}



void SND_StartPreparedSeq(u32 playerNo)
{
    u32 zero = 0;

    PushCommand_impl(3, playerNo, zero, zero, zero);
}



/*
 * sdk:      SND_PauseSeq (snd_interface.o)
 */
void SND_PauseSeq(int playerNo, int flag)
{
    PushCommand_impl(4, (u32)playerNo, (u32)flag, 0, 0);
}



void SND_SetPlayerTempoRatio(int playerNo, int ratio)
{
    SNDi_SetPlayerParam(playerNo, 0x1a, (u32)ratio, 2);
}



void SND_SetPlayerVolume(int playerNo, int volume)
{
    SNDi_SetPlayerParam(playerNo, 0x6, (u32)volume, 2);
}



void SND_SetPlayerChannelPriority(int playerNo, int prio)
{
    SNDi_SetPlayerParam(playerNo, 0x4, (u32)prio, 1);
}



void SND_SetTrackVolume(int playerNo, u32 trackBitMask, int volume)
{
    SNDi_SetTrackParam(playerNo, trackBitMask, 0xa, (u32)volume, 2);
}



void SND_SetTrackPitch(int playerNo, u32 trackBitMask, int pitch)
{
    SNDi_SetTrackParam(playerNo, trackBitMask, 0xc, (u32)pitch, 2);
}



void SND_SetTrackPan(int playerNo, u32 trackBitMask, int pan)
{
    SNDi_SetTrackParam(playerNo, trackBitMask, 0x9, (u32)pan, 1);
}



void SND_SetTrackModDepth(int playerNo, u32 trackBitMask, u32 depth)
{
    SNDi_SetTrackParam(playerNo, trackBitMask, 0x1a, (u32)depth, 1);
}



void SND_SetTrackModSpeed(int playerNo, u32 trackBitMask, u32 speed)
{
    SNDi_SetTrackParam(playerNo, trackBitMask, 0x19, (u32)speed, 1);
}



/*
 * sdk:      SND_SetTrackAllocatableChannel (snd_interface.o)
 */
void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask)
{
    PushCommand_impl(9, (u32)playerNo, trackBitMask, chBitMask, 0);
}



/*
 * sdk:      SND_StartTimer (snd_interface.o)
 */
void SND_StartTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags)
{
    PushCommand_impl(0xc, chBitMask, capBitMask, alarmBitMask, flags);
}



/*
 * sdk:      SND_StopTimer (snd_interface.o)
 */
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



/*
 * sdk:      SND_SetupAlarm (snd_interface.o)
 */
void SND_SetupAlarm(int alarmNo, u32 tick, u32 period, SNDAlarmHandler handler, void *arg)
{
    unsigned char id = SNDi_SetAlarmHandler(alarmNo, handler, arg);

    PushCommand_impl(0x12, (u32)alarmNo, tick, period, id);
}



/*
 * sdk:      SND_SetTrackMute (snd_interface.o)
 */
void SND_SetTrackMute(int playerNo, u32 trackBitMask, int flag)
{
    PushCommand_impl(8, (u32)playerNo, trackBitMask, flag ? 3 : 0, 0);
}



/*
 * sdk:      SND_SetTrackMuteEx (snd_interface.o)
 */
void SND_SetTrackMuteEx(int playerNo, u32 trackBitMask, int mute)
{
    PushCommand_impl(8, (u32)playerNo, trackBitMask, (u32)mute, 0);
}



/*
 * sdk:      SND_LockChannel (snd_interface.o)
 */
void SND_LockChannel(u32 chBitMask, u32 flags)
{
    PushCommand_impl(0x1a, chBitMask, flags, 0, 0);
}



/*
 * sdk:      SND_UnlockChannel (snd_interface.o)
 */
void SND_UnlockChannel(u32 chBitMask, u32 flags)
{
    PushCommand_impl(0x1b, chBitMask, flags, 0, 0);
}



/*
 * sdk:      SND_SetChannelTimer (snd_interface.o)
 */
void SND_SetChannelTimer(u32 chBitMask, int timer)
{
    PushCommand_impl(0x13, chBitMask, (u32)timer, 0, 0);
}



/*
 * sdk:      SND_SetChannelVolume (snd_interface.o)
 */
void SND_SetChannelVolume(u32 chBitMask, int volume, int shift)
{
    PushCommand_impl(0x14, chBitMask, (u32)volume, (u32)shift, 0);
}



/*
 * sdk:      SND_SetupChannelPcm (snd_interface.o)
 */
void SND_SetupChannelPcm(int chNo, int format, const void *dataaddr, int loop, int loopStart, int loopLen, int volume, int shift, int timer, int pan)
{
    PushCommand_impl(0xe, (u32)(chNo | (timer << 16)), (u32)dataaddr, (u32)((volume << 24) | (shift << 22) | loopLen), (u32)((loop << 26) | (format << 24) | (pan << 16) | loopStart));
}



/*
 * sdk:      SND_InvalidateSeqData (snd_interface.o)
 */
void SND_InvalidateSeqData(const void *start, const void *end)
{
    PushCommand_impl(0x1e, (u32)start, (u32)end, 0, 0);
}



/*
 * sdk:      SND_InvalidateBankData (snd_interface.o)
 */
void SND_InvalidateBankData(const void *start, const void *end)
{
    PushCommand_impl(0x1f, (u32)start, (u32)end, 0, 0);
}



/*
 * sdk:      SND_InvalidateWaveData (snd_interface.o)
 */
void SND_InvalidateWaveData(const void *start, const void *end)
{
    PushCommand_impl(0x20, (u32)start, (u32)end, 0, 0);
}



/*
 * sdk:      SND_SetMasterVolume (snd_interface.o)
 */
void SND_SetMasterVolume(int volume)
{
    PushCommand_impl(0x17, (u32)volume, 0, 0, 0);
}



/*
 * sdk:      SND_SetOutputSelector (snd_interface.o)
 */
void SND_SetOutputSelector(int left, int right, int channel1, int channel3)
{
    PushCommand_impl(0x19, (u32)left, (u32)right, (u32)channel1, (u32)channel3);
}



/*
 * sdk:      SND_SetMasterPan (snd_interface.o)
 */
void SND_SetMasterPan(int pan)
{
    PushCommand_impl(0x18, (u32)pan, 0, 0, 0);
}



/*
 * sdk:      SND_ResetMasterPan (snd_interface.o)
 */
void SND_ResetMasterPan(void)
{
    PushCommand_impl(0x18, (u32)-1, 0, 0, 0);
}



/*
 * sdk:      SND_ReadDriverInfo (snd_interface.o)
 */
void SND_ReadDriverInfo(struct SNDDriverInfo *info)
{
    PushCommand_impl(0x21, (u32)info, 0, 0, 0);
}



/*
 * sdk:      SNDi_SetPlayerParam (snd_interface.o)
 */
void SNDi_SetPlayerParam(int playerNo, u32 offset, u32 data, int size)
{
    PushCommand_impl(6, (u32)playerNo, offset, data, (u32)size);
}



/*
 * sdk:      SNDi_SetTrackParam (snd_interface.o)
 */
void SNDi_SetTrackParam(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size)
{
    PushCommand_impl(7, (u32)(playerNo | (size << 24)), trackBitMask, offset, data);
}



/*
 * sdk:      PushCommand_impl (snd_interface.o)
 */
void PushCommand_impl(int id, u32 value0, u32 value1, u32 value2, u32 value3)
{
    SNDCommand *command = SND_AllocCommand(1);

    if (command == 0) {
        return;
    }
    command->id = id;
    command->arg[0] = value0;
    command->arg[1] = value1;
    command->arg[2] = value2;
    command->arg[3] = value3;
    SND_PushCommand(command);
}

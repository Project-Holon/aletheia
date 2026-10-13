/*
 * file:     unit_02089330.c
 * unit:     yes
 * function: func_02089330, func_02089350, func_02089378, func_02089398, func_020893B8, func_020893D0, func_020893E8, func_02089400, func_0208941C, func_02089438, func_02089454, func_02089470, func_0208948C, func_020894B4, func_020894DC, func_02089540, func_02089580, func_020895B0, func_020895D8, func_020895F8, func_02089618, func_02089638, func_02089660, func_020896AC, func_020896CC, func_020896EC, func_0208970C, func_0208972C, func_02089754, func_02089774, func_02089794, func_020897B4, func_020897DC, func_02089804
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

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void SNDi_IncAlarmId(int alarmNo);
extern unsigned char SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg);
extern SNDCommand *SND_AllocCommand(u32 flags);
extern void SND_PushCommand(SNDCommand *command);
void func_02089330(int playerNo);
void func_02089350(int playerNo, const void *base, u32 offset, struct SNDBankData *bank);
void func_02089378(u32 a);
void func_02089398(int playerNo, int flag);
void SND_SetPlayerTempoRatio(int playerNo, int ratio);
void SND_SetPlayerVolume(int playerNo, int volume);
void SND_SetPlayerChannelPriority(int playerNo, int prio);
void SND_SetTrackVolume(int playerNo, u32 trackBitMask, int volume);
void SND_SetTrackPitch(int playerNo, u32 trackBitMask, int pitch);
void SND_SetTrackPan(int playerNo, u32 trackBitMask, int pan);
void SND_SetTrackModDepth(int playerNo, u32 trackBitMask, u32 depth);
void SND_SetTrackModSpeed(int playerNo, u32 trackBitMask, u32 speed);
void func_0208948C(int playerNo, u32 trackBitMask, u32 chBitMask);
void func_020894B4(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void func_020894DC(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void func_02089540(int alarmNo, u32 tick, u32 period, SNDAlarmHandler handler, void *arg);
void func_02089580(int playerNo, u32 trackBitMask, int flag);
void func_020895B0(int playerNo, u32 trackBitMask, int mute);
void func_020895D8(u32 chBitMask, u32 flags);
void func_020895F8(u32 chBitMask, u32 flags);
void func_02089618(u32 chBitMask, int timer);
void func_02089638(u32 chBitMask, int volume, int shift);
void func_02089660(int chNo, int format, const void *dataaddr, int loop, int loopStart, int loopLen, int volume, int shift, int timer, int pan);
void func_020896AC(const void *start, const void *end);
void func_020896CC(const void *start, const void *end);
void func_020896EC(const void *start, const void *end);
void func_0208970C(int volume);
void func_0208972C(int left, int right, int channel1, int channel3);
void func_02089754(int pan);
void func_02089774(void);
void func_02089794(struct SNDDriverInfo *info);
void func_020897B4(int playerNo, u32 offset, u32 data, int size);
void func_020897DC(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size);
void func_02089804(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);



/*
 * sdk:      SND_StopSeq (snd_interface.o)
 */
void func_02089330(int playerNo)
{
    PushCommand_impl(1, (u32)playerNo, 0, 0, 0);
}



/*
 * sdk:      SND_PrepareSeq (snd_interface.o)
 */
void func_02089350(int playerNo, const void *base, u32 offset, struct SNDBankData *bank)
{
    PushCommand_impl(2, (u32)playerNo, (u32)base, offset, (u32)bank);
}



void func_02089378(u32 a)
{
    u32 z = 0;

    func_02089804(3, a, z, z, z);
}



/*
 * sdk:      SND_PauseSeq (snd_interface.o)
 */
void func_02089398(int playerNo, int flag)
{
    PushCommand_impl(4, (u32)playerNo, (u32)flag, 0, 0);
}



void SND_SetPlayerTempoRatio(int playerNo, int ratio)
{
    func_020897B4(playerNo, 0x1a, (u32)ratio, 2);
}



void SND_SetPlayerVolume(int playerNo, int volume)
{
    func_020897B4(playerNo, 0x6, (u32)volume, 2);
}



void SND_SetPlayerChannelPriority(int playerNo, int prio)
{
    func_020897B4(playerNo, 0x4, (u32)prio, 1);
}



void SND_SetTrackVolume(int playerNo, u32 trackBitMask, int volume)
{
    func_020897DC(playerNo, trackBitMask, 0xa, (u32)volume, 2);
}



void SND_SetTrackPitch(int playerNo, u32 trackBitMask, int pitch)
{
    func_020897DC(playerNo, trackBitMask, 0xc, (u32)pitch, 2);
}



void SND_SetTrackPan(int playerNo, u32 trackBitMask, int pan)
{
    func_020897DC(playerNo, trackBitMask, 0x9, (u32)pan, 1);
}



void SND_SetTrackModDepth(int playerNo, u32 trackBitMask, u32 depth)
{
    func_020897DC(playerNo, trackBitMask, 0x1a, (u32)depth, 1);
}



void SND_SetTrackModSpeed(int playerNo, u32 trackBitMask, u32 speed)
{
    func_020897DC(playerNo, trackBitMask, 0x19, (u32)speed, 1);
}



/*
 * sdk:      SND_SetTrackAllocatableChannel (snd_interface.o)
 */
void func_0208948C(int playerNo, u32 trackBitMask, u32 chBitMask)
{
    PushCommand_impl(9, (u32)playerNo, trackBitMask, chBitMask, 0);
}



/*
 * sdk:      SND_StartTimer (snd_interface.o)
 */
void func_020894B4(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags)
{
    PushCommand_impl(0xc, chBitMask, capBitMask, alarmBitMask, flags);
}



/*
 * sdk:      SND_StopTimer (snd_interface.o)
 */
void func_020894DC(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags)
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
void func_02089540(int alarmNo, u32 tick, u32 period, SNDAlarmHandler handler, void *arg)
{
    unsigned char id = SNDi_SetAlarmHandler(alarmNo, handler, arg);

    PushCommand_impl(0x12, (u32)alarmNo, tick, period, id);
}



/*
 * sdk:      SND_SetTrackMute (snd_interface.o)
 */
void func_02089580(int playerNo, u32 trackBitMask, int flag)
{
    PushCommand_impl(8, (u32)playerNo, trackBitMask, flag ? 3 : 0, 0);
}



/*
 * sdk:      SND_SetTrackMuteEx (snd_interface.o)
 */
void func_020895B0(int playerNo, u32 trackBitMask, int mute)
{
    PushCommand_impl(8, (u32)playerNo, trackBitMask, (u32)mute, 0);
}



/*
 * sdk:      SND_LockChannel (snd_interface.o)
 */
void func_020895D8(u32 chBitMask, u32 flags)
{
    PushCommand_impl(0x1a, chBitMask, flags, 0, 0);
}



/*
 * sdk:      SND_UnlockChannel (snd_interface.o)
 */
void func_020895F8(u32 chBitMask, u32 flags)
{
    PushCommand_impl(0x1b, chBitMask, flags, 0, 0);
}



/*
 * sdk:      SND_SetChannelTimer (snd_interface.o)
 */
void func_02089618(u32 chBitMask, int timer)
{
    PushCommand_impl(0x13, chBitMask, (u32)timer, 0, 0);
}



/*
 * sdk:      SND_SetChannelVolume (snd_interface.o)
 */
void func_02089638(u32 chBitMask, int volume, int shift)
{
    PushCommand_impl(0x14, chBitMask, (u32)volume, (u32)shift, 0);
}



/*
 * sdk:      SND_SetupChannelPcm (snd_interface.o)
 */
void func_02089660(int chNo, int format, const void *dataaddr, int loop, int loopStart, int loopLen, int volume, int shift, int timer, int pan)
{
    PushCommand_impl(0xe, (u32)(chNo | (timer << 16)), (u32)dataaddr, (u32)((volume << 24) | (shift << 22) | loopLen), (u32)((loop << 26) | (format << 24) | (pan << 16) | loopStart));
}



/*
 * sdk:      SND_InvalidateSeqData (snd_interface.o)
 */
void func_020896AC(const void *start, const void *end)
{
    PushCommand_impl(0x1e, (u32)start, (u32)end, 0, 0);
}



/*
 * sdk:      SND_InvalidateBankData (snd_interface.o)
 */
void func_020896CC(const void *start, const void *end)
{
    PushCommand_impl(0x1f, (u32)start, (u32)end, 0, 0);
}



/*
 * sdk:      SND_InvalidateWaveData (snd_interface.o)
 */
void func_020896EC(const void *start, const void *end)
{
    PushCommand_impl(0x20, (u32)start, (u32)end, 0, 0);
}



/*
 * sdk:      SND_SetMasterVolume (snd_interface.o)
 */
void func_0208970C(int volume)
{
    PushCommand_impl(0x17, (u32)volume, 0, 0, 0);
}



/*
 * sdk:      SND_SetOutputSelector (snd_interface.o)
 */
void func_0208972C(int left, int right, int channel1, int channel3)
{
    PushCommand_impl(0x19, (u32)left, (u32)right, (u32)channel1, (u32)channel3);
}



/*
 * sdk:      SND_SetMasterPan (snd_interface.o)
 */
void func_02089754(int pan)
{
    PushCommand_impl(0x18, (u32)pan, 0, 0, 0);
}



/*
 * sdk:      SND_ResetMasterPan (snd_interface.o)
 */
void func_02089774(void)
{
    PushCommand_impl(0x18, (u32)-1, 0, 0, 0);
}



/*
 * sdk:      SND_ReadDriverInfo (snd_interface.o)
 */
void func_02089794(struct SNDDriverInfo *info)
{
    PushCommand_impl(0x21, (u32)info, 0, 0, 0);
}



/*
 * sdk:      SNDi_SetPlayerParam (snd_interface.o)
 */
void func_020897B4(int playerNo, u32 offset, u32 data, int size)
{
    PushCommand_impl(6, (u32)playerNo, offset, data, (u32)size);
}



/*
 * sdk:      SNDi_SetTrackParam (snd_interface.o)
 */
void func_020897DC(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size)
{
    PushCommand_impl(7, (u32)(playerNo | (size << 24)), trackBitMask, offset, data);
}



/*
 * sdk:      PushCommand_impl (snd_interface.o)
 */
void func_02089804(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
    SNDCommand *command = SND_AllocCommand(1);

    if (command == 0) {
        return;
    }
    command->id = id;
    command->arg[0] = arg0;
    command->arg[1] = arg1;
    command->arg[2] = arg2;
    command->arg[3] = arg3;
    SND_PushCommand(command);
}

/*
 * file:     unit_02089330_p02.c
 * unit:     yes
 * function: func_020895B0, func_020895D8, func_020895F8, func_02089618, func_02089638, func_02089660, func_020896AC, func_020896CC, func_020896EC, func_0208970C, func_0208972C, func_02089754, func_02089774, func_02089794, func_020897B4, func_020897DC, func_02089804
 * address:  0x020895B0
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
 *   SND_AllocCommand  0x02089A78  arm
 *   SND_PushCommand   0x02089B00  arm
 */
struct SNDDriverInfo;
typedef unsigned long u32;

typedef struct SNDCommand {
    struct SNDCommand *next;
    int id;
    u32 arg[4];
} SNDCommand;

extern void PushCommand_impl(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern SNDCommand *SND_AllocCommand(u32 flags);
extern void SND_PushCommand(SNDCommand *command);
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
void func_020897B4(int playerNo, u32 offset, u32 data, int size);
void func_020897DC(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size);
void func_02089804(int id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);


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

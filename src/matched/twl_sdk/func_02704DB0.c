/*
 * function: WaitResetSoundCallback
 * address:  0x02704DB0
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_02734450   0x02734450  data twl
 *   WaitResetSoundCallback  0x02704DB0  arm twl
 *   SNDEXi_SetVolumeExAsync  0x027044C0  arm twl
 *   WaitIirFilterSetting  0x02704D74  arm
 *   ResetTempVolume  0x02704E04  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct TwlSyncState {
    u8 chan;
    u8 pad[7];
    s32 retries;
    u8 pad2[4];
    u32 count;
    u32 active;
    u32 waiting;
} TwlSyncState;

extern void func_02087A04(u32);
extern void func_02088688(void);
extern u32 SNDEXi_SetVolumeExAsync(u32, u32, u32);
void WaitIirFilterSetting(void);
void WaitResetSoundCallback(u32 a0);
void ResetTempVolume(void);
extern TwlSyncState DAT_02734450;

void WaitResetSoundCallback(u32 a0) {
    if (a0 != 0 && DAT_02734450.count < 5) {
        SNDEXi_SetVolumeExAsync(DAT_02734450.chan, (u32)WaitResetSoundCallback, 0);
        DAT_02734450.count++;
        return;
    }
    DAT_02734450.active = 0;
}

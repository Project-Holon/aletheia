/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005CA4
 * packet:   pkt_02005924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_SetPlayersAudible, GFL_USE_SetPlayerVolumes, GFL_USE_IsSeqStartAllowed, GFL_USE_SetSeqStartFilter,
 *           GFL_USE_StopBgm, GFL_USE_CancelChangeAndStopBgm
 *
 * symbols:
 *   sub_02005CE0_State  0x020AA260  data
 *   GFL_USE_GetCurrentSndHandle        0x0200590C  thumb
 *   GFL_USE_UnloadBgmData        0x020059C8  thumb
 *   GFL_USE_IsLoaderBusy        0x02005C64  thumb
 *   GFL_USE_CancelBgmChange        0x02005F90  thumb
 *   NNS_SndPlayerSetPlayerVolume       0x02072D98  arm
 *   NNS_SndHandleStopSeq       0x02072E7C  arm
 *
 * A bit-per-channel broadcast and the callback hook that goes with it.
 *
 * GFL_USE_SetPlayersAudible forwards its second argument without ever mentioning it: the
 * original never touches r1 between entry and either call, which is what a
 * parameter that is only ever passed on looks like.  The one thing to get
 * right is that both arms call the same function with a different first
 * argument rather than computing the argument and calling once; written as
 * `GFL_USE_SetPlayerVolumes(a == 1 ? 0x7F : 0, b)` the compiler folds the two calls into
 * one and the function is four bytes shorter.
 */

typedef unsigned int u32;

struct Sub02005CE0State {
    u32   unk00;
    int (*unk04)(void *arg);
};

extern struct Sub02005CE0State sub_02005CE0_State;

extern u32 *GFL_USE_GetCurrentSndHandle(void);
extern void GFL_USE_UnloadBgmData(void);
extern int  GFL_USE_IsLoaderBusy(void);
extern void GFL_USE_CancelBgmChange(void);
extern void NNS_SndPlayerSetPlayerVolume(u32 idx, u32 val);
extern void NNS_SndHandleStopSeq(void **r0, int fadeFrame);

void GFL_USE_SetPlayerVolumes(u32 value, u32 mask);
void GFL_USE_StopBgm(void);

void GFL_USE_SetPlayersAudible(int a, u32 mask)
{
    if (a == 1) {
        GFL_USE_SetPlayerVolumes(0x7F, mask);
    } else {
        GFL_USE_SetPlayerVolumes(0, mask);
    }
}

void GFL_USE_SetPlayerVolumes(u32 value, u32 mask)
{
    int i;

    for (i = 0; i < 5; i++) {
        if ((1 << i) & mask) {
            NNS_SndPlayerSetPlayerVolume(i, value);
        }
    }
}

int GFL_USE_IsSeqStartAllowed(void *arg)
{
    if (GFL_USE_IsLoaderBusy() == 0) {
        return 1;
    }
    if (sub_02005CE0_State.unk04 == 0) {
        return 0;
    }
    return sub_02005CE0_State.unk04(arg);
}

void GFL_USE_SetSeqStartFilter(int (*hook)(void *arg))
{
    sub_02005CE0_State.unk04 = hook;
}

void GFL_USE_StopBgm(void)
{
    NNS_SndHandleStopSeq((void **)GFL_USE_GetCurrentSndHandle(), 0);
    GFL_USE_UnloadBgmData();
}

void GFL_USE_CancelChangeAndStopBgm(void)
{
    GFL_USE_CancelBgmChange();
    GFL_USE_StopBgm();
}

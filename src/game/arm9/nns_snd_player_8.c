/*
 * file:     nns_snd_player_8.c
 * unit:     yes
 * function: NNS_SndHandleSetSeqPriority, NNS_SndHandleSetPlayerPriority, NNS_SndHandleMoveVolume, NNS_SndHandlePause, NNS_SndHandleSetTrackPause, NNS_SndHandleSetTrackMute, NNS_SndHandleSetTrackVolume, NNS_SndHandleSetTrackPitch, NNS_SndHandleSetTrackPan, NNS_SndHandleSetTrackModDepth, NNS_SndHandleSetTrackModSpeed, NNS_SndHandleStop
 * address:  0x02072F34
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
 *   func_02075BAC  0x02075BAC  arm
 *   g_020A5D08       0x20A5D08  data
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int s32;

typedef struct SndFader {
    s32 start;
    s32 target;
    s32 step;
    s32 duration;
} SndFader;

struct SNDTrackInfo;

typedef struct SndSeqPlayer {
    u8 pad00[0x1c];
    SndFader volumeFader;
    u8 state;
    u8 pad2d[0x3c - 0x2d];
    u8 playerNo;
    u8 pad3d[0x40 - 0x3d];
    u8 playerPriority;
    u8 seqPriority;
} SndSeqPlayer;

typedef struct SndHandle { SndSeqPlayer * volatile player; } SndHandle;

extern void func_02075BAC(SndFader *fader, s32 target, u32 frames);
extern void func_020893E8(u8, u32);
extern void func_02089580(int playerNo, u32 trackBitMask, int flag);
extern void func_020895B0(int playerNo, u32 trackBitMask, int mute);
extern void func_02089400(u8, u32, int);
extern void func_0208941C(u8, u32, u32);
extern void func_02089438(u8, u32, u32);
extern void func_02089454(u8, u32, u32);
extern void func_02089470(u8, u32, u32);
extern void func_020893B8(u8, u32);
extern int func_02072894(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);
void NNS_SndHandleSetSeqPriority(SndHandle *handle, u8 priority);
void NNS_SndHandleSetPlayerPriority(SndHandle *handle, u8 priority);
void NNS_SndHandleMoveVolume(SndSeqPlayer *volatile *handle, u32 volume, u32 frames);
void NNS_SndHandlePause(SndHandle *handle, u32 value);
void NNS_SndHandleSetTrackPause(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackMute(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackVolume(SndHandle *handle, u32 trackMask, int volumeIndex);
void NNS_SndHandleSetTrackPitch(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackPan(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackModDepth(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackModSpeed(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleStop(SndHandle *handle, u32 value);
extern short g_020A5D08[];


void NNS_SndHandleSetSeqPriority(SndHandle *handle, u8 priority)
{
    if (handle->player) handle->player->seqPriority = priority;
}


void NNS_SndHandleSetPlayerPriority(SndHandle *handle, u8 priority)
{
    if (handle->player) handle->player->playerPriority = priority;
}



/*
 * Wave 17 lane untried_small. Callee arity read from func_02075BAC's body
 * (three parameters, r2 stored to +0x0C): the wrapper forwards its own third
 * parameter untouched, so r0..r2 are all live and the null test's load lands
 * in r3, the register the earlier two-parameter spellings could not reach.
 * The re-load after the null test is the volatile slot.
 */
void NNS_SndHandleMoveVolume(SndSeqPlayer *volatile *handle, u32 volume, u32 frames)
{
    SndSeqPlayer *player;

    if (*handle == 0) {
        return;
    }
    player = *handle;
    if (player->state == 2) {
        return;
    }
    func_02075BAC(&player->volumeFader, volume << 8, frames);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * Nine members of one dispatch family: a null guard on o->p, then a call that
 *  * passes the object's byte at +0x3c plus the member's own leftover argument
 *  * registers.
 *  *
 *  * The arity is read off the guard's scratch register, which is the only thing
 *  * that distinguishes the members: a two-argument member (r1 live) loads the
 *  * guard into r2, a three-argument one (r1 and r2 live) into r3. Writing the
 *  * unused parameters is what buys the byte:
 *  *
 *  *   struct Obj * volatile p  -> the guard's load and the use's load are two
 *  *   loads; a plain field folds them into one and the member is four bytes
 *  *   short.
 *  *
 *  * func_020730B8 (0x020730B8), an otherwise identical two-statement member of
 *  * the same family, is NOT in this unit: this front end if-converts a
 *  * two-statement arm and the original used `bxeq lr`, so it stays a DIFF near
 *  * miss. See docs/notes/pkt_02072EA8.c.txt.
 *  *
 *  * Verified with:
 *  *   python tools/match.py tu --src src/pending/unit_02072F88.c --addr 0x02072F88 --arm
 */
void NNS_SndHandlePause(SndHandle *handle, u32 value)
{
    if (handle->player == 0) return;
    func_020893E8(handle->player->playerNo, value);
}


void NNS_SndHandleSetTrackPause(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    func_02089580(handle->player->playerNo, trackMask, value);
}


void NNS_SndHandleSetTrackMute(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    func_020895B0(handle->player->playerNo, trackMask, value);
}


void NNS_SndHandleSetTrackVolume(SndHandle *handle, u32 trackMask, int volumeIndex)
{
    if (handle->player == 0) return;
    func_02089400(handle->player->playerNo, trackMask, g_020A5D08[volumeIndex]);
}


void NNS_SndHandleSetTrackPitch(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    func_0208941C(handle->player->playerNo, trackMask, value);
}


void NNS_SndHandleSetTrackPan(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    func_02089438(handle->player->playerNo, trackMask, value);
}


void NNS_SndHandleSetTrackModDepth(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    func_02089454(handle->player->playerNo, trackMask, value);
}


void NNS_SndHandleSetTrackModSpeed(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    func_02089470(handle->player->playerNo, trackMask, value);
}


void NNS_SndHandleStop(SndHandle *handle, u32 value)
{
    if (handle->player == 0) return;
    func_020893B8(handle->player->playerNo, value);
}

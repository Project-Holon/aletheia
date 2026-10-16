/*
 * file:     nns_snd_player.c
 * unit:     yes
 * function: NNS_SndPlayerSetPlayerVolume, NNS_SndPlayerSetPlayableSeqCount, NNS_SndPlayerSetAllocatableChannel, NNS_SndPlayerCreateHeap, NNS_SndHandleStopSeq, NNS_SndHandlePauseSeq, NNS_SndHandleInit, NNS_SndHandleReleaseSeq, NNS_SndPlayerGetActiveSeqCount, NNS_SndPlayerCountPlayingSeqBySeqNo, NNS_SndHandleSetVolume, NNS_SndHandleSetInitialVolume, NNS_SndHandleMoveVolume, NNS_SndHandlePause, NNS_SndHandleSetTrackPause, NNS_SndHandleSetTrackMute, NNS_SndHandleSetTrackVolume, NNS_SndHandleSetTrackPitch, NNS_SndHandleSetTrackPan, NNS_SndHandleSetTrackModDepth, NNS_SndHandleSetTrackModSpeed, NNS_SndHandleStop, NNSi_SndHandleSetSeqNo, NNSi_SndHandleSetSeqArc, NNS_SndHandleReadTrackInfo, NNS_SndPlayerInit, NNS_SndPlayerMain, NNSi_SndPlayerAllocSeqPlayer, NNSi_SndPlayerFreeSeqPlayer, NNSi_SndPlayerStartSeqPlayer, NNSi_SndSeqPlayerStop, NNSi_SndSeqPlayerPause, NNSi_SndPlayerAllocHeap, NNSi_SndSeqPlayerResetState, NNSi_SndPlayerInsertSeqPlayer, NNSi_SndInsertActiveSeqPlayer, NNSi_SndSeqPlayerStopNow, NNSi_SndAllocFreeSeqPlayer, NNSi_SndSeqPlayerRelease, NNSi_SndPlayerHeapDisposeCallback, NNSi_SndSeqPlayerSetPriority
 * address:  0x02072D98
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gSndPlayers       0x0214E464  data
 *   NNS_SndHeapAlloc  0x0207482C  arm
 *   NNS_SndHeapCreate  0x020746E8  arm
 *   NNS_FndAppendListObject  0x020604AC  arm
 *   gSndActiveSeqList  0x0214E018  data
 *   NNS_FndGetNextListObject  0x02060614  arm
 *   NNSi_SndFaderSet  0x02075BAC  arm
 *   g_020A5D08     0x020A5D08  data
 *   NNS_SndReadTrackInfo  0x02072894  arm
 *   gSndFreeSeqList  0x0214E00C  data
 *   gSndSeqPlayers  0x0214E024  data
 *   NNS_FndInitList  0x02060468  arm
 *   SND_GetPlayerStatus  0x0208A054  arm
 *   SND_IsFinishedCommandTag  0x02089D6C  arm
 *   NNS_SndFaderUpdate  0x02075C08  arm
 *   NNS_SndFaderGet  0x02075BD4  arm
 *   SND_SetPlayerVolume  0x020893D0  arm
 *   NNS_SndFaderIsFinished  0x02075C20  arm
 *   SND_StartPreparedSeq  0x02089378  arm
 *   SND_PrepareSeq                  0x02089350  arm
 *   SND_SetTrackAllocatableChannel  0x0208948C  arm
 *   SND_GetCurrentCommandTag        0x02089D40  arm
 *   NNSi_SndFaderReset  0x02075B94  arm
 *   SND_PauseSeq    0x02089398  arm
 *   NNS_FndRemoveListObject  0x020605B4  arm
 *   NNS_SndHeapClear  0x02074770  arm
 *   NNS_SndHeapDestroy  0x02074758  arm
 *   NNS_FndInsertListObject  0x02060550  arm
 *   SND_StopSeq    0x02089330  arm
 *   SND_SetTrackMute  0x02089580  arm
 *   SND_SetTrackMuteEx  0x020895B0  arm
 *   SND_SetPlayerTempoRatio  0x020893B8  arm
 *   SND_SetPlayerChannelPriority  0x020893E8  arm
 *   SND_SetTrackVolume  0x02089400  arm
 *   SND_SetTrackPitch  0x0208941C  arm
 *   SND_SetTrackPan  0x02089438  arm
 *   SND_SetTrackModDepth  0x02089454  arm
 *   SND_SetTrackModSpeed  0x02089470  arm
 */
#include "nns_snd_types.h"

struct SNDTrackInfo;
extern NNSSndHeap *NNS_SndHeapCreate(u32 start, u32 size);
extern void *NNS_SndHeapAlloc(NNSSndHeap *heap, u32 size, NNSSndHeapDisposeCallback callback, u32 data1, u32 data2);
extern void NNS_FndAppendListObject(NNSFndList *list, void *object);
extern void *NNS_FndGetNextListObject(NNSFndList *list, void *object);
extern void NNSi_SndFaderSet(SndFader *fader, s32 target, u32 frames);
extern void SND_SetPlayerChannelPriority(u8 playerNo, u32 value);
extern void SND_SetTrackMute(int playerNo, u32 trackBitMask, int flag);
extern void SND_SetTrackMuteEx(int playerNo, u32 trackBitMask, int mute);
extern void SND_SetTrackVolume(u8 playerNo, u32 trackBitMask, int volume);
extern void SND_SetTrackPitch(u8 playerNo, u32 trackBitMask, u32 pitch);
extern void SND_SetTrackPan(u8 playerNo, u32 trackBitMask, u32 pan);
extern void SND_SetTrackModDepth(u8 playerNo, u32 trackBitMask, u32 depth);
extern void SND_SetTrackModSpeed(u8 playerNo, u32 trackBitMask, u32 speed);
extern void SND_SetPlayerTempoRatio(u8 playerNo, u32 value);
extern int NNS_SndReadTrackInfo(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);
extern void NNS_FndRemoveListObject(volatile NNSFndList *list, void *object);
extern void NNS_FndInitList(NNSFndList *list, int offset);
extern void NNS_FndInsertListObject(volatile NNSFndList *list, void *before, void *object);
extern void NNS_SndHeapClear(NNSSndHeap *heap);
extern void NNS_SndHeapDestroy(NNSSndHeap *heap);
extern u32 SND_GetPlayerStatus(void);
extern int SND_IsFinishedCommandTag(u32 tag);
extern void NNS_SndFaderUpdate(SndFader *fader);
extern s32 NNS_SndFaderGet(SndFader *fader);
extern int NNS_SndFaderIsFinished(SndFader *fader);
extern int NNSi_SndFaderReset(SndFader *fader, int value);
extern void SND_SetPlayerVolume(u32 playerNo, int volume);
extern void SND_StartPreparedSeq(u32 playerNo);
extern void SND_StopSeq(int playerNo);
extern void SND_PauseSeq(int playerNo, int flag);
extern void SND_PrepareSeq(int playerNo, const void *seqBase, u32 seqOffset, const void *bankData);
extern void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask);
extern u32  SND_GetCurrentCommandTag(void);
void NNS_SndPlayerSetPlayerVolume(u32 playerNo, u32 volume);
void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int playableSeqCount);
void NNS_SndPlayerSetAllocatableChannel(u32 playerNo, u32 channelMask);
u32 NNS_SndPlayerCreateHeap(int playerNo, NNSSndHeap *heap, u32 size);
void NNS_SndHandleStopSeq(SndHandle *handle, int fadeFrame);
void NNS_SndHandlePauseSeq(SndHandle *handle, unsigned char flag);
void NNS_SndHandleInit(SndHandle *handle);
void NNS_SndHandleReleaseSeq(SndHandle *handle);
u16 NNS_SndPlayerGetActiveSeqCount(u32 playerNo);
s32 NNS_SndPlayerCountPlayingSeqBySeqNo(u32 seqNo);
void NNS_SndHandleSetVolume(SndHandle *handle, u8 volume);
void NNS_SndHandleSetInitialVolume(SndHandle *handle, u8 volume);
void NNS_SndHandleMoveVolume(SndHandle *handle, u32 volume, u32 frames);
void NNS_SndHandlePause(SndHandle *handle, u32 value);
void NNS_SndHandleSetTrackPause(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackMute(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackVolume(SndHandle *handle, u32 trackMask, int volumeIndex);
void NNS_SndHandleSetTrackPitch(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackPan(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackModDepth(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleSetTrackModSpeed(SndHandle *handle, u32 trackMask, u32 value);
void NNS_SndHandleStop(SndHandle *handle, u32 value);
void NNSi_SndHandleSetSeqNo(SndHandle *handle, u16 seqNo);
void NNSi_SndHandleSetSeqArc(SndHandle *handle, u32 seqArcNo, u32 seqArcIndex);
int NNS_SndHandleReadTrackInfo(SndHandle *handle, int trackNo, struct SNDTrackInfo *trackInfo);
void NNS_SndPlayerInit(void);
void NNS_SndPlayerMain(void);
SndSeqPlayer *NNSi_SndPlayerAllocSeqPlayer(SndHandle *handle, s32 playerNo, s32 priority);
void NNSi_SndPlayerFreeSeqPlayer(SndSeqPlayer *seqPlayer);
void NNSi_SndPlayerStartSeqPlayer(SndSeqPlayer *seqPlayer, const void *seqBase, u32 seqOffset, const void *bankData);
void NNSi_SndSeqPlayerStop(SndSeqPlayer *seqPlayer, int fadeFrame);
void NNSi_SndSeqPlayerPause(SndSeqPlayer *seqPlayer, u8 flag);
NNSSndHeap *NNSi_SndPlayerAllocHeap(s32 playerNo, SndSeqPlayer *seqPlayer);
void NNSi_SndSeqPlayerResetState(SndSeqPlayer *seqPlayer);
void NNSi_SndPlayerInsertSeqPlayer(SndPlayer *player, SndSeqPlayer *seqPlayer);
void NNSi_SndInsertActiveSeqPlayer(SndSeqPlayer *seqPlayer);
void NNSi_SndSeqPlayerStopNow(SndSeqPlayer *seqPlayer);
SndSeqPlayer *NNSi_SndAllocFreeSeqPlayer(s32 priority);
void NNSi_SndSeqPlayerRelease(SndSeqPlayer *seqPlayer);
void NNSi_SndPlayerHeapDisposeCallback(SndPlayerHeap *pPlayerHeap);
void NNSi_SndSeqPlayerSetPriority(SndSeqPlayer *seqPlayer, u32 priority);
/* The player slot table, 32 entries. */
extern SndPlayer gSndPlayers[];
/* The active sequence player list. */
extern NNSFndList gSndActiveSeqList;
/* Volume index to decibel table. */
extern s16 g_020A5D08[];
/* Free sequence players and playing ones (sorted by priority). */
extern NNSFndList gSndFreeSeqList;
/* The pool of 16 sequence players. */
extern SndSeqPlayer gSndSeqPlayers[];


void NNS_SndPlayerSetPlayerVolume(u32 playerNo, u32 volume)
{
    gSndPlayers[playerNo].volume = volume;
}


void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int playableSeqCount)
{
    gSndPlayers[playerNo].playableSeqCount = (unsigned short)playableSeqCount;
}


void NNS_SndPlayerSetAllocatableChannel(u32 playerNo, u32 channelMask)
{
    gSndPlayers[playerNo].allocatableChannelMask = channelMask;
}


/* Bytes of a player heap block in front of its buffer. */
#define SND_PLAYER_HEAP_HEADER_SIZE 0x14


/*
 * Creates a heap of `size` bytes for player playerNo: allocates a block from
 * the sound heap `heap` with NNSi_SndPlayerHeapDisposeCallback as its dispose callback, builds a
 * sub-heap inside the block, and links the block into the player's heap list.
 * Either failure returns 0.
 *
 * ARGUMENT ORDER of the allocator is (heap, size + 0x14, callback, 0, 0): the
 * image does `mov r0, r1` at 0x02072DF8 and loads the pool word into r2 at
 * 0x02072E00, so the FUNCTION POINTER is the third argument and the size the
 * second.  The player table stride is 0x24 with the heap list head at +0x0c;
 * the padding to 0x24 has to be written out or the offset folds into the
 * multiply.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md).  The image
 * materialises the zeros SEPARATELY (`mov r3, #0` for the allocator's stacked
 * fifth argument, `mov r2, #0` for the owner/sub-heap pair, and a fresh
 * `moveq r0, #0` at each failure exit) and keeps a bare four-register push
 * with an explicit `sub sp, sp, #4` frame.  1.1p1 -O4,p CSEs all four into one
 * hoisted `mov r5, #0`, which costs a fifth callee-saved register: 132 bytes
 * against the original's 148.  Under the pin the same C is 148 bytes.
 */
u32 NNS_SndPlayerCreateHeap(int playerNo, NNSSndHeap *heap, u32 size)
{
    SndPlayerHeap *pPlayerHeap;
    NNSSndHeap *subHeap;

    pPlayerHeap = (SndPlayerHeap *)NNS_SndHeapAlloc(heap, size + SND_PLAYER_HEAP_HEADER_SIZE,
                                                 (NNSSndHeapDisposeCallback)NNSi_SndPlayerHeapDisposeCallback, 0, 0);
    if (pPlayerHeap == 0) {
        return 0;
    }
    pPlayerHeap->pOwner = 0;
    pPlayerHeap->playerNo = playerNo;
    pPlayerHeap->heap = 0;
    subHeap = NNS_SndHeapCreate((u32)pPlayerHeap->buffer, size);
    if (subHeap == 0) {
        return 0;
    }
    pPlayerHeap->heap = subHeap;
    NNS_FndAppendListObject(&gSndPlayers[playerNo].heapList, pPlayerHeap);
    return 1;
}


/* Stops the handle's sequence, fading out over fadeFrame frames (tail call). */
void NNS_SndHandleStopSeq(SndHandle *handle, int fadeFrame)
{
    NNSi_SndSeqPlayerStop(handle->player, fadeFrame);
}


/* Pauses or resumes the handle's sequence (tail call). */
void NNS_SndHandlePauseSeq(SndHandle *handle, unsigned char flag)
{
    NNSi_SndSeqPlayerPause(handle->player, flag);
}


void NNS_SndHandleInit(SndHandle *handle)
{
    handle->player = 0;
}


/* Detaches the handle from its sequence player, if it has one. */
void NNS_SndHandleReleaseSeq(SndHandle *handle)
{
    if (handle->player == 0) {
        return;
    }
    handle->player->pHandle = 0;
    handle->player = 0;
}


u16 NNS_SndPlayerGetActiveSeqCount(u32 playerNo)
{
    return gSndPlayers[playerNo].seqList.numObjects;
}


/* Counts the playing sequence players that run the plain sequence seqNo. */
s32 NNS_SndPlayerCountPlayingSeqBySeqNo(u32 seqNo)
{
    SndSeqPlayer *seqPlayer;
    s32 count;

    count = 0;
    seqPlayer = NNS_FndGetNextListObject(&gSndActiveSeqList, 0);
    while (seqPlayer != 0) {
        if (seqPlayer->seqType == SND_SEQ_TYPE_SEQ && seqPlayer->seqNo == seqNo) {
            count++;
        }
        seqPlayer = NNS_FndGetNextListObject(&gSndActiveSeqList, seqPlayer);
    }
    return count;
}


/* Sets the sequence's own volume (index into the decibel table). */
void NNS_SndHandleSetVolume(SndHandle *handle, u8 volume)
{
    if (handle->player) handle->player->volume = volume;
}


/* Sets the initial volume the sequence info gave it (index into the decibel table). */
void NNS_SndHandleSetInitialVolume(SndHandle *handle, u8 volume)
{
    if (handle->player) handle->player->initialVolume = volume;
}


/*
 * Fades the sequence volume to volume (8.8 fixed point in the fader) over
 * frames.  The callee takes three parameters, so r0..r2 are all live and the
 * null test's load lands in r3; the re-load after the null test is the
 * volatile slot.
 */
void NNS_SndHandleMoveVolume(SndHandle *handle, u32 volume, u32 frames)
{
    SndSeqPlayer *player;

    if (handle->player == 0) {
        return;
    }
    player = handle->player;
    if (player->state == SND_SEQ_STATE_STOPPING) {
        return;
    }
    NNSi_SndFaderSet(&player->volumeFader, volume << 8, frames);
}


/*
 * The handle commands below form one dispatch family: a null guard on the
 * handle's player, then a call that passes the player number plus the member's
 * own leftover argument registers.  The arity is read off the guard's scratch
 * register (a two-argument member loads the guard into r2, a three-argument
 * one into r3), and the `volatile` player slot keeps the guard's load and the
 * use's load apart; a plain field folds them into one and the member is four
 * bytes short.  NNSi_SndHandleSetSeqNo is an otherwise identical two-statement member
 * that is not in this family: the front end if-converts a two-statement arm
 * where the original used `bxeq lr`.
 */
void NNS_SndHandlePause(SndHandle *handle, u32 value)
{
    if (handle->player == 0) return;
    SND_SetPlayerChannelPriority(handle->player->playerNo, value);
}



void NNS_SndHandleSetTrackPause(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    SND_SetTrackMute(handle->player->playerNo, trackMask, value);
}



void NNS_SndHandleSetTrackMute(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    SND_SetTrackMuteEx(handle->player->playerNo, trackMask, value);
}



void NNS_SndHandleSetTrackVolume(SndHandle *handle, u32 trackMask, int volumeIndex)
{
    if (handle->player == 0) return;
    SND_SetTrackVolume(handle->player->playerNo, trackMask, g_020A5D08[volumeIndex]);
}



void NNS_SndHandleSetTrackPitch(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    SND_SetTrackPitch(handle->player->playerNo, trackMask, value);
}



void NNS_SndHandleSetTrackPan(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    SND_SetTrackPan(handle->player->playerNo, trackMask, value);
}



void NNS_SndHandleSetTrackModDepth(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    SND_SetTrackModDepth(handle->player->playerNo, trackMask, value);
}



void NNS_SndHandleSetTrackModSpeed(SndHandle *handle, u32 trackMask, u32 value)
{
    if (handle->player == 0) return;
    SND_SetTrackModSpeed(handle->player->playerNo, trackMask, value);
}



void NNS_SndHandleStop(SndHandle *handle, u32 value)
{
    if (handle->player == 0) return;
    SND_SetPlayerTempoRatio(handle->player->playerNo, value);
}


/* Records that the handle's sequence player plays the plain sequence seqNo. */
void NNSi_SndHandleSetSeqNo(SndHandle *handle, u16 seqNo)
{
    if (handle->player != 0) {
        handle->player->seqType = SND_SEQ_TYPE_SEQ;
        handle->player->seqNo = seqNo;
    }
}


/*
 * Records that the handle's sequence player plays entry seqArcIndex of the
 * sequence archive seqArcNo.  Three statements that each re-read the player,
 * so `volatile` on the handle's pointer is load-bearing here too: it is what
 * keeps the three loads.  The three statements also keep the early `bxeq lr`;
 * the two-statement sibling NNSi_SndHandleSetSeqNo is if-converted instead.
 */
void NNSi_SndHandleSetSeqArc(SndHandle *handle, u32 seqArcNo, u32 seqArcIndex)
{
    if (handle->player == 0) return;
    handle->player->seqType = SND_SEQ_TYPE_SEQARC;
    handle->player->seqNo = seqArcNo;
    handle->player->seqArcIndex = seqArcIndex;
}


/*
 * Returns 0 when the handle has no sequence player; otherwise forwards trackNo
 * and trackInfo untouched to the reader (they are already in r1 and r2, so
 * the call sets only r0).
 */
int NNS_SndHandleReadTrackInfo(SndHandle *handle, int trackNo, struct SNDTrackInfo *trackInfo)
{
    if (handle->player == 0) return 0;
    return NNS_SndReadTrackInfo(handle->player->playerNo, trackNo, trackInfo);
}


/* Volume of a stopped sequence, in the decibel scale of the volume curve. */
#define SND_VOLUME_SILENT (-723)


/*
 * Initialises the sequence player lists, puts the 16 pooled sequence players
 * on the free list, and sets up the 32 player slots (a sequence list and a heap
 * list each, full volume, one playable sequence, no channel mask).
 *
 * Pinned ../2.0/sp2 on the documented "kept constants" tell.  The image
 * materialises the list offset 0x14 TWICE; 1.1p1 -O4,p CSEs the pair into one
 * hoisted register, which costs a further callee-saved register (180 bytes with
 * 128 concrete bytes out).  The indexed-subscript spelling of the two loops
 * additionally leaves an `mla` cursor under both front ends; the pointer-cursor
 * form reproduces the original's strength reduction.
 *
 * Note seqPlayer->playerNo is the loop INDEX, not zero: the counter is stored
 * before the increment, while seqPlayer->state takes the separate hoisted zero.
 * Writing both as 0 leaves exactly one byte out.
 */
void NNS_SndPlayerInit(void)
{
    s32 i;
    SndSeqPlayer *seqPlayer;
    SndPlayer *player;

    NNS_FndInitList(&gSndActiveSeqList, 0x14);
    NNS_FndInitList(&gSndFreeSeqList, 0x14);

    for (i = 0, seqPlayer = gSndSeqPlayers; i < 0x10; i++, seqPlayer++) {
        seqPlayer->state = SND_SEQ_STATE_FREE;
        seqPlayer->playerNo = (u8)i;
        NNS_FndAppendListObject(&gSndFreeSeqList, seqPlayer);
    }

    for (i = 0, player = gSndPlayers; i < 0x20; i++, player++) {
        NNS_FndInitList(&player->seqList, 0xc);
        NNS_FndInitList(&player->heapList, 0);
        player->volume = 0x7f;
        player->playableSeqCount = 1;
        player->allocatableChannelMask = 0;
    }
}


/*
 * Per-frame update of the playing sequences.  Takes the mask of hardware
 * players still running; a sequence that has been prepared but whose player is
 * no longer running is released.  Otherwise it steps the volume fader, sums the
 * four volume curves (sequence volume, initial volume, player volume, fader)
 * clamped to the s16 range, sends the volume when it changed, finishes a
 * stopping sequence whose fade ended, and starts a sequence whose start is
 * pending.
 *
 * Levers, all under 1.1p1:
 *  - The three sound-curve indices are PLAIN s16 subscripts.  Spelling any of
 *    them with an arithmetic round-trip emits a signed-division fixup the
 *    image does not have.
 *  - The guard is `(mask & (1 << playerNo)) == 0`, not `!= 0`: the image's
 *    branch skips the release arm.
 *  - Declaration order is the whole register allocation: `tbl` is declared
 *    BEFORE the sequence player (tbl->r5, seqPlayer->r6, next->r7), and `tbl`
 *    and `lo` are ASSIGNED after the early-return guard, not at their
 *    declarations, or they hoist above it.
 *  - The volume sum is `e + (c + (b + a))` with the curve read bound to its
 *    own local `e`: the accumulator is the second operand.
 */
void NNS_SndPlayerMain(void)
{
    u32 mask;
    s16 *tbl;
    s32 lo;
    SndSeqPlayer *seqPlayer;
    SndSeqPlayer *next;
    s32 volume;

    mask = SND_GetPlayerStatus();
    seqPlayer = NNS_FndGetNextListObject(&gSndActiveSeqList, 0);
    if (seqPlayer == 0) {
        return;
    }
    lo = -0x8000;
    tbl = g_020A5D08;
    do {
        next = NNS_FndGetNextListObject(&gSndActiveSeqList, seqPlayer);
        if (seqPlayer->isPrepared == 0) {
            if (SND_IsFinishedCommandTag(seqPlayer->commandTag) != 0) {
                seqPlayer->isPrepared = 1;
            }
        }
        if (seqPlayer->isPrepared != 0 && (mask & (1 << seqPlayer->playerNo)) == 0) {
            NNSi_SndSeqPlayerRelease(seqPlayer);
        } else {
            s32 a, b, c;
            NNS_SndFaderUpdate(&seqPlayer->volumeFader);
            a = tbl[seqPlayer->volume];
            b = tbl[seqPlayer->initialVolume];
            c = tbl[seqPlayer->pPlayer->volume];
            {
                s32 e = tbl[NNS_SndFaderGet(&seqPlayer->volumeFader) >> 8];
                volume = e + (c + (b + a));
            }
            if (volume < lo) {
                volume = lo;
            } else if (volume > 0x7fff) {
                volume = 0x7fff;
            }
            if (volume != seqPlayer->appliedVolume) {
                SND_SetPlayerVolume(seqPlayer->playerNo, volume);
                seqPlayer->appliedVolume = (s16)volume;
            }
            if (seqPlayer->state == SND_SEQ_STATE_STOPPING && NNS_SndFaderIsFinished(&seqPlayer->volumeFader) != 0) {
                NNSi_SndSeqPlayerStopNow(seqPlayer);
            }
            if (seqPlayer->startPending != 0) {
                SND_StartPreparedSeq(seqPlayer->playerNo);
                seqPlayer->startPending = 0;
            }
        }
        seqPlayer = next;
    } while (next != 0);
}


/*
 * Binds a free sequence player to the handle for player slot playerNo.  Drops
 * the handle's previous sequence first.  When the slot is already at its
 * playable sequence count it takes over the lowest-priority sequence on the
 * slot, or fails when that one outranks priority.  Returns the sequence player,
 * linked into the slot's sequence list, or 0.
 */
SndSeqPlayer *NNSi_SndPlayerAllocSeqPlayer(SndHandle *handle, s32 playerNo, s32 priority)
{
    SndPlayer *player = &gSndPlayers[playerNo];
    SndSeqPlayer *seqPlayer = handle->player;

    if (seqPlayer != 0) {
        NNS_SndHandleReleaseSeq(handle);
    }
    if (player->seqList.numObjects >= player->playableSeqCount) {
        seqPlayer = NNS_FndGetNextListObject(&player->seqList, 0);
        if (seqPlayer == 0) {
            return 0;
        }
        if (priority < seqPlayer->priority) {
            return 0;
        }
        NNSi_SndSeqPlayerStopNow(seqPlayer);
    }
    seqPlayer = NNSi_SndAllocFreeSeqPlayer(priority);
    if (seqPlayer == 0) {
        return 0;
    }
    NNSi_SndPlayerInsertSeqPlayer(player, seqPlayer);
    seqPlayer->pHandle = handle;
    handle->player = seqPlayer;
    return seqPlayer;
}


/* Releases a sequence player without the stop command. */
void NNSi_SndPlayerFreeSeqPlayer(SndSeqPlayer *seqPlayer)
{
    NNSi_SndSeqPlayerRelease(seqPlayer);
}


/*
 * Prepares sequence data on the hardware player and marks the sequence
 * playing with its start pending.  Applies the slot's channel mask to all 16
 * tracks when it has one.
 */
void NNSi_SndPlayerStartSeqPlayer(SndSeqPlayer *seqPlayer, const void *seqBase, u32 seqOffset, const void *bankData)
{
    SndPlayer *player = seqPlayer->pPlayer;

    SND_PrepareSeq(seqPlayer->playerNo, seqBase, seqOffset, bankData);
    if (player->allocatableChannelMask != 0) {
        SND_SetTrackAllocatableChannel(seqPlayer->playerNo, 0xFFFF, player->allocatableChannelMask);
    }
    NNSi_SndSeqPlayerResetState(seqPlayer);
    seqPlayer->commandTag = SND_GetCurrentCommandTag();
    seqPlayer->startPending = 1;
    seqPlayer->state = SND_SEQ_STATE_PLAYING;
}


/*
 * Stops a playing sequence: at once when fadeFrame is 0, else fades it out
 * over fadeFrame frames, demotes its priority to 0 and marks it stopping.
 */
void NNSi_SndSeqPlayerStop(SndSeqPlayer *seqPlayer, int fadeFrame)
{
    if (seqPlayer == 0) return;
    if (seqPlayer->state == SND_SEQ_STATE_FREE) return;
    if (fadeFrame == 0) {
        NNSi_SndSeqPlayerStopNow(seqPlayer);
        return;
    }
    NNSi_SndFaderSet(&seqPlayer->volumeFader, 0, fadeFrame);
    NNSi_SndSeqPlayerSetPriority(seqPlayer, 0);
    seqPlayer->state = SND_SEQ_STATE_STOPPING;
}


/* Pauses (nonzero) or resumes (zero) the sequence, once per change. */
void NNSi_SndSeqPlayerPause(SndSeqPlayer *seqPlayer, u8 flag)
{
    if (seqPlayer != 0 && flag != seqPlayer->isPaused) {
        SND_PauseSeq(seqPlayer->playerNo, flag);
        seqPlayer->isPaused = flag;
    }
}


/*
 * Takes the first free heap block off the slot's heap list, hands it to the
 * sequence player, clears the heap and returns it.  Returns 0 when the slot
 * has no heap.
 */
NNSSndHeap *NNSi_SndPlayerAllocHeap(s32 playerNo, SndSeqPlayer *seqPlayer)
{
    SndPlayer *player = &gSndPlayers[playerNo];
    SndPlayerHeap *pPlayerHeap = NNS_FndGetNextListObject(&player->heapList, 0);

    if (pPlayerHeap == 0) return 0;
    NNS_FndRemoveListObject(&player->heapList, pPlayerHeap);
    pPlayerHeap->pOwner = seqPlayer;
    seqPlayer->pPlayerHeap = pPlayerHeap;
    NNS_SndHeapClear(pPlayerHeap->heap);
    return pPlayerHeap->heap;
}


/* Resets the per-sequence state of a freshly started sequence and snaps its fader to full volume. */
void NNSi_SndSeqPlayerResetState(SndSeqPlayer *seqPlayer)
{
    seqPlayer->isPaused = 0;
    seqPlayer->isPrepared = 0;
    seqPlayer->startPending = 0;
    seqPlayer->seqType = 0;
    seqPlayer->appliedVolume = 0;
    seqPlayer->initialVolume = 0x7f;
    seqPlayer->volume = 0x7f;
    NNSi_SndFaderReset(&seqPlayer->volumeFader, 0x7f);
    NNSi_SndFaderSet(&seqPlayer->volumeFader, 0x7f00, 1);
}


/* Inserts the sequence player into the slot's sequence list, sorted by priority, and records the slot. */
void NNSi_SndPlayerInsertSeqPlayer(SndPlayer *player, SndSeqPlayer *seqPlayer)
{
    SndSeqPlayer *curr = (SndSeqPlayer *)NNS_FndGetNextListObject(&player->seqList, 0);
    while (curr != 0) {
        if (seqPlayer->priority < curr->priority) {
            break;
        }
        curr = (SndSeqPlayer *)NNS_FndGetNextListObject(&player->seqList, curr);
    }
    NNS_FndInsertListObject(&player->seqList, curr, seqPlayer);
    seqPlayer->pPlayer = player;
}


/* Inserts the sequence player into the active list, sorted by priority. */
void NNSi_SndInsertActiveSeqPlayer(SndSeqPlayer *seqPlayer)
{
    SndSeqPlayer *curr = NNS_FndGetNextListObject(&gSndActiveSeqList, 0);
    while (curr != 0) {
        if (seqPlayer->priority < curr->priority) {
            break;
        }
        curr = NNS_FndGetNextListObject(&gSndActiveSeqList, curr);
    }
    NNS_FndInsertListObject(&gSndActiveSeqList, curr, seqPlayer);
}


/* Stops the sequence at once: silences a fading one, stops the hardware player, releases it. */
void NNSi_SndSeqPlayerStopNow(SndSeqPlayer *seqPlayer)
{
    if (seqPlayer->state == SND_SEQ_STATE_STOPPING) {
        SND_SetPlayerVolume(seqPlayer->playerNo, SND_VOLUME_SILENT);
    }
    SND_StopSeq(seqPlayer->playerNo);
    NNSi_SndSeqPlayerRelease(seqPlayer);
}


/*
 * Takes a sequence player from the free list for a sequence of the given
 * priority.  When none is free it steals the lowest-priority playing one, or
 * fails when that one outranks priority.  The new player enters the active
 * list.
 */
SndSeqPlayer *NNSi_SndAllocFreeSeqPlayer(s32 priority)
{
    SndSeqPlayer *seqPlayer;
    seqPlayer = NNS_FndGetNextListObject(&gSndFreeSeqList, 0);
    if (seqPlayer == 0) {
        seqPlayer = NNS_FndGetNextListObject(&gSndActiveSeqList, 0);
        if (priority < seqPlayer->priority) {
            return 0;
        }
        NNSi_SndSeqPlayerStopNow(seqPlayer);
    }
    NNS_FndRemoveListObject(&gSndFreeSeqList, seqPlayer);
    seqPlayer->priority = (u8)priority;
    NNSi_SndInsertActiveSeqPlayer(seqPlayer);
    return seqPlayer;
}


/*
 * Releases a sequence player: detaches its handle, takes it off its slot's
 * list, returns its heap block to the slot, takes it off the active list and
 * puts it back on the free list.
 */
void NNSi_SndSeqPlayerRelease(SndSeqPlayer *seqPlayer)
{
    SndPlayer *player;
    if (seqPlayer->pHandle != 0) {
        seqPlayer->pHandle->player = 0;
        seqPlayer->pHandle = 0;
    }
    player = seqPlayer->pPlayer;
    NNS_FndRemoveListObject(&player->seqList, seqPlayer);
    seqPlayer->pPlayer = 0;
    if (seqPlayer->pPlayerHeap != 0) {
        NNS_FndAppendListObject(&player->heapList, seqPlayer->pPlayerHeap);
        seqPlayer->pPlayerHeap->pOwner = 0;
        seqPlayer->pPlayerHeap = 0;
    }
    NNS_FndRemoveListObject(&gSndActiveSeqList, seqPlayer);
    NNS_FndAppendListObject(&gSndFreeSeqList, seqPlayer);
    seqPlayer->state = SND_SEQ_STATE_FREE;
}


/*
 * Dispose callback of a player heap block: destroys the sub-heap, then either
 * detaches the block from its owning sequence player or, when it has none,
 * takes it off its player's heap list.
 */
void NNSi_SndPlayerHeapDisposeCallback(SndPlayerHeap *pPlayerHeap)
{
    if (pPlayerHeap->heap == 0) return;
    NNS_SndHeapDestroy(pPlayerHeap->heap);
    if (pPlayerHeap->pOwner != 0) { pPlayerHeap->pOwner->pPlayerHeap = 0; return; }
    NNS_FndRemoveListObject(&gSndPlayers[pPlayerHeap->playerNo].heapList, pPlayerHeap);
}


/* Changes the priority of a sequence player and re-sorts it in both lists. */
void NNSi_SndSeqPlayerSetPriority(SndSeqPlayer *seqPlayer, u32 priority)
{
    SndPlayer *player = seqPlayer->pPlayer;
    if (player != 0) { NNS_FndRemoveListObject(&player->seqList, seqPlayer); seqPlayer->pPlayer = 0; }
    NNS_FndRemoveListObject(&gSndActiveSeqList, seqPlayer);
    seqPlayer->priority = (u8)priority;
    if (player != 0) NNSi_SndPlayerInsertSeqPlayer(player, seqPlayer);
    NNSi_SndInsertActiveSeqPlayer(seqPlayer);
}

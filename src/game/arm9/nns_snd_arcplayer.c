/*
 * file:     nns_snd_arcplayer.c
 * unit:     yes
 * function: NNS_SndArcPlayerStartSeq, NNS_SndArcPlayerStartSeqEx, NNS_SndArcPlayerStartSeqArc, NNSi_SndArcPlayerStartSeq, NNSi_SndArcPlayerStartSeqArc, NNSi_SndArcPlayerUpdate, NNSi_SndTrackDetachObject, NNSi_SndTrackStop, NNSi_SndTrackClose, NNSi_SndTrackReleaseRef, NNSi_SndTrackListUnlinkByValue, NNSi_SndTrackListUnlinkElem, NNSi_SndArcGetSeqEntry, NNSi_SndFaderReset
 * address:  0x02075560
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NNS_SndArcGetSeqArcInfo  0x02074388  arm
 *   NNS_SndArcGetFileAddress  0x0207466C  arm
 *   NNSi_SndPlayerAllocSeqPlayer  0x02073344  arm
 *   NNSi_SndPlayerAllocHeap  0x020734AC  arm
 *   NNSi_SndArcLoadBank  0x02074CD0  arm
 *   NNSi_SndArcLoadSeq  0x02074BEC  arm
 *   NNSi_SndPlayerFreeSeqPlayer  0x020733DC  arm
 *   NNSi_SndPlayerStartSeqPlayer  0x020733E8  arm
 *   NNS_SndHandleSetInitialVolume  0x02072F48  arm
 *   NNS_SndHandlePause  0x02072F88  arm
 *   NNSi_SndHandleSetSeqNo  0x020730B8  arm
 *   NNSi_SndHandleSetSeqArc  0x020730DC  arm
 *   data_0214EAC0  0x0214EAC0  data
 *   data_020A5D08  0x020A5D08  data
 *   NNS_SndStrmStart  0x02073A60  arm
 *   NNS_SndStrmSetVolume  0x02073AD0  arm
 *   NNS_SndFaderGet  0x02075BD4  arm
 *   NNS_SndFaderUpdate  0x02075C08  arm
 *   NNS_SndFaderIsFinished  0x02075C20  arm
 *   g_02150178  0x02150178  data
 *   g_0214EA90  0x0214EA90  data
 *   g_02150190  0x02150190  data
 *   NNS_SndStrmFreeChannel  0x02073898  arm
 *   OS_DisableInterrupts 0x02087988  arm
 *   OS_RestoreInterrupts 0x0208799C  arm
 *   NNS_FndGetNextListObject 0x02060614  arm
 *   NNS_FndRemoveListObject 0x020605B4  arm
 *   NNS_FndAppendListObject 0x020604AC  arm
 *   NNS_SndArcGetSeqInfo  0x02074324  arm
 *   NNSi_SndStrmStopIfSetup  0x02073AB4  arm
 *   OS_LockMutex  0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 */

struct Entry;
#include "nns_snd_types.h"

struct Table;
struct Node;
struct SndTrack;
struct DList;

/*
 * One of the four sound-track slots at data_0214EAC0 (0x17C bytes each): the
 * NNSSndStrm state that nns_snd_strm.c fills in, then the volume fader and the
 * callbacks this file drives.
 */
struct SndTrack {
    SndStrm stream;          /* 0x000: the stream object (nns_snd_strm.c) */
    u8  pad058[0x98];        /* 0x058: rest of the slot; never read here */
    SndFader fader;          /* 0x0f0: volume ramp */
    u8  pad100[0x18];        /* 0x100 */
    s32 active : 1;          /* 0x118: slot carries a sequence */
    s32 followFader : 1;     /* the fade drives the stream volume */
    s32 startPending : 1;    /* a start is waiting for the slot */
    s32 stopPending : 1;     /* stop once the fader has finished */
    s32 reservedBits : 28;
    s32 seqNo;               /* 0x11c: running sequence, 0 = idle */
    s32 pendingSeqNo;        /* 0x120: sequence of a pending start */
    u8  pad124[4];
    int refCount;            /* 0x128 */
    u8  pad12c[0x28];
    u32 *attachedObject;     /* 0x154: object whose first word is cleared */
    u8  pad158[4];
    s32 volumeIndex;         /* 0x15c: index into the dB table data_020A5D08 */
    s32 playerVolumeIndex;   /* 0x160: index into data_020A5D08 */
    s32 appliedVolume;       /* 0x164: volume last sent to the stream */
    u8  pad168[8];
    void (*stopCallback)(struct SndTrack *o);      /* 0x170 */
    u8  pad174[4];
    void (*releaseCallback)(struct SndTrack *o);   /* 0x178 */
};

/* The seq-arc record NNS_SndArcGetSeqArcInfo returns; only its file id is used. */
struct SndMedia { u32 fileId; };

/* A loaded sequence file: a 0x18-byte header, then the sequence data. */
struct SndBlock {
    u8  pad00[0x18];
    u32 dataOffset;
};

/* One node of the track list: an 8-byte link then the track it carries. */
struct DListElem {
    u8  pad00[8];
    u32 value;
};

/* One record of the archive's sequence info table (0xC bytes each). */
struct Entry {
    u32 seqOffset;      /* 0x0: FAT offset, 0xffffffff marks a free record */
    u16 bankNo;         /* 0x4 */
    u8  initialVolume;  /* 0x6 */
    u8  pauseFlag;      /* 0x7 */
    u8  priority;       /* 0x8 */
    u8  playerNo;       /* 0x9 */
    u8  padA[2];
};

struct Table { u8 pad00[0x1c]; u32 count; struct Entry arr[]; };

extern void *NNS_SndArcGetSeqInfo(int index);
extern void *NNS_SndArcGetSeqArcInfo(int index);
extern u32   NNS_SndArcGetFileAddress(u32 a);
struct SndHandle;
struct SndSeqPlayer;
extern struct SndSeqPlayer *NNSi_SndPlayerAllocSeqPlayer(struct SndHandle *handle, s32 playerNo, s32 priority);
struct NNSSndHeap;
extern struct NNSSndHeap *NNSi_SndPlayerAllocHeap(s32 playerNo, struct SndSeqPlayer *seqPlayer);
extern u32   NNSi_SndArcLoadBank(u32 bankNo, u32 loadFlag, struct NNSSndHeap *heap, u32 isSetAddress, u32 *outAddress);
extern u32 NNSi_SndArcLoadSeq(u32 seqNo, u32 loadFlag, struct NNSSndHeap *heap, u32 isSetAddress, u32 *outAddress);
extern void  NNSi_SndPlayerFreeSeqPlayer(struct SndSeqPlayer *seqPlayer);
extern void NNSi_SndPlayerStartSeqPlayer(struct SndSeqPlayer *seqPlayer, void *seqBase, u32 seqOffset, void *bankData);
extern void NNS_SndHandleSetInitialVolume(struct SndHandle *handle, u8 volume);
extern void NNS_SndHandlePause(struct SndHandle *handle, u32 value);
extern void  NNSi_SndHandleSetSeqNo(u32 a, u32 b);
extern void NNSi_SndHandleSetSeqArc(struct SndHandle *handle, u32 seqArcNo, u32 seqArcIndex);
extern void NNS_SndStrmStart(SndStrm *a);
extern void NNS_SndStrmSetVolume(SndStrm *, s32);
extern s32 NNS_SndFaderGet(SndFader *o);
extern void NNS_SndFaderUpdate(SndFader *obj);
extern int NNS_SndFaderIsFinished(SndFader *obj);
#include "../sdk_os.h"

extern void OS_LockMutex(struct OSMutex *mutex);
extern void OS_UnlockMutex(struct OSMutex *mutex);
extern void NNSi_SndStrmStopIfSetup(SndStrm *o);
extern void NNS_SndStrmFreeChannel(SndStrm *x);
struct NNSFndList;
extern void NNS_FndAppendListObject(struct NNSFndList *list, void *object);
extern u32  OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void *NNS_FndGetNextListObject(struct DList *list, void *elem);
extern void NNS_FndRemoveListObject(volatile struct DList *list, void *elem);
u32 NNS_SndArcPlayerStartSeq(u32 handle, u32 seqNo);
u32 NNS_SndArcPlayerStartSeqEx(u32 handle, int playerNo, int bankNo, int priority, u32 seqNo);
u32 NNS_SndArcPlayerStartSeqArc(u32 handle, u32 arcIndex, u32 index);
u32 NNSi_SndArcPlayerStartSeq(u32 handle, u32 playerNo, u32 bankNo, u32 priority, struct Entry *entry, u32 seqNo);
u32 NNSi_SndArcPlayerStartSeqArc(u32 handle, u32 playerNo, u32 bankNo, u32 priority, struct Entry *entry, struct SndBlock *block, u32 arcIndex, u32 index);
void NNSi_SndArcPlayerUpdate(void);
void NNSi_SndTrackDetachObject(struct SndTrack *track);
void NNSi_SndTrackStop(struct SndTrack *track);
void NNSi_SndTrackClose(struct SndTrack *track);
void NNSi_SndTrackReleaseRef(struct SndTrack *track);
void NNSi_SndTrackListUnlinkByValue(void *list, u32 value);
void NNSi_SndTrackListUnlinkElem(void *elem);
struct Entry *NNSi_SndArcGetSeqEntry(struct Table *table, int index);
void NNSi_SndFaderReset(SndFader *fader);
extern struct SndTrack data_0214EAC0[4];
extern const s16 data_020A5D08[];
extern u8  g_02150178[];
extern u8  g_0214EA90[];
extern u8  g_02150190[];




u32 NNS_SndArcPlayerStartSeq(u32 handle, u32 seqNo)
{
    struct Entry *entry = NNS_SndArcGetSeqInfo(seqNo);

    if (entry == 0) return 0;
    return NNSi_SndArcPlayerStartSeq(handle, (entry)->playerNo, (entry)->bankNo, (entry)->priority,
                         entry, seqNo);
}




u32 NNS_SndArcPlayerStartSeqEx(u32 handle, int playerNo, int bankNo, int priority, u32 seqNo)
{
    struct Entry *entry = NNS_SndArcGetSeqInfo(seqNo);

    if (entry == 0) return 0;
    if (priority < 0) priority = entry->priority;
    if (bankNo < 0) bankNo = entry->bankNo;
    if (playerNo < 0) playerNo = entry->playerNo;
    return NNSi_SndArcPlayerStartSeq(handle, (u32)playerNo, (u32)bankNo, (u32)priority, entry, seqNo);
}




/*
 * Four-step open path, each step gated on its predecessor's result and each
 * early exit answering 0: resolve the media handle (NNS_SndArcGetSeqArcInfo), take the
 * object the handle points at and look up its record (NNS_SndArcGetFileAddress), bind the
 * record to the caller's key (NNSi_SndArcGetSeqEntry), then hand seven values to
 * NNSi_SndArcPlayerStartSeqArc - the caller's first argument, three fields of the record
 * (bytes at +9 and +8, the halfword at +4) and four words parked on the stack
 * (the record itself, the looked-up object, and the caller's second and third
 * arguments).
 *
 * UNBLOCKED 2026-09-22 (wave 7, pkt_02075404).  This file was previously capped
 * at MATCH on the `matched` class: NNSi_SndArcPlayerStartSeqArc (the PC24 at +0x0074) has no
 * branch outside 02075618..02075698, and the callee was left DIFF at 200 vs 196
 * bytes by an earlier lane (docs/notes/NNSi_SndArcPlayerStartSeqArc.c.txt), so it could not be
 * filed and could not attest this call.  That DIFF was a compiler question, not
 * a source one: the same body is byte-exact under `--cc ../2.0/sp2` and is now
 * src/matched/NNSi_SndArcPlayerStartSeqArc.c, so this site resolves as `matched` and all four
 * of this file's relocations resolve.  Compiled 128 bytes, original 128 bytes.
 * This file itself stays on the project default 1.1p1; the cluster is mixed,
 * see docs/families/cluster_02074A34.h.
 */
u32 NNS_SndArcPlayerStartSeqArc(u32 handle, u32 arcIndex, u32 index)
{
    struct SndMedia *media;
    u32 blockAddr;
    struct Entry *entry;

    media = NNS_SndArcGetSeqArcInfo(arcIndex);
    if (media == 0) {
        return 0;
    }

    blockAddr = NNS_SndArcGetFileAddress(media->fileId);
    if (blockAddr == 0) {
        return 0;
    }

    entry = NNSi_SndArcGetSeqEntry((struct Table *)blockAddr, index);
    if (entry == 0) {
        return 0;
    }

    return NNSi_SndArcPlayerStartSeqArc(handle, entry->playerNo, entry->bankNo, entry->priority, entry, (struct SndBlock *)blockAddr, arcIndex, index);
}






/*
 * Sibling of src/matched/NNSi_SndArcPlayerStartSeqArc.c (same open / bind / release shape):
 * open a handle with NNSi_SndPlayerAllocSeqPlayer, bind a slot through NNSi_SndArcLoadBank (kind
 * 6) and a block through NNSi_SndArcLoadSeq (kind 1, keyed by the sixth argument),
 * releasing the handle on either failure; then attach the block's +0x18
 * payload to the handle and apply the descriptor's bytes 6 and 7.  Called by
 * NNS_SndArcPlayerStartSeq and NNS_SndArcPlayerStartSeqEx with the record pointer as s0 and the
 * record id as s1.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_SndArcPlayerStartSeq.c \
 *       --func NNSi_SndArcPlayerStartSeq --addr 0x02075698 --arm --cc ../2.0/sp2
 *   EXACT, 252 bytes, 10 of 10 relocation sites resolved (sp2p2 EXACT too,
 *   dsi/1.1p1 260 bytes DIFF).
 */
u32 NNSi_SndArcPlayerStartSeq(u32 handle, u32 playerNo, u32 bankNo, u32 priority, struct Entry *entry, u32 seqNo)
{
    void *seqPlayer;
    u32 heap;
    struct SndBlock *block;
    u32 slot;

    seqPlayer = NNSi_SndPlayerAllocSeqPlayer((struct SndHandle *)handle, playerNo, priority);
    if (seqPlayer == 0) {
        return 0;
    }
    heap = (u32)NNSi_SndPlayerAllocHeap(playerNo, seqPlayer);
    if ((struct NNSSndHeap *)NNSi_SndArcLoadBank(bankNo, 6, (struct NNSSndHeap *)heap, 0, &slot) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(seqPlayer);
        return 0;
    }
    if ((struct NNSSndHeap *)NNSi_SndArcLoadSeq(seqNo, 1, (struct NNSSndHeap *)heap, 0, (u32 *)(&block)) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(seqPlayer);
        return 0;
    }
    NNSi_SndPlayerStartSeqPlayer(seqPlayer, (void *)((u8 *)block + block->dataOffset), 0, (void *)slot);
    NNS_SndHandleSetInitialVolume((struct SndHandle *)handle, entry->initialVolume);
    NNS_SndHandlePause((struct SndHandle *)handle, entry->pauseFlag);
    NNSi_SndHandleSetSeqNo(handle, seqNo);
    return 1;
}






/*
 * The four-step open/bind path behind NNS_SndArcPlayerStartSeqArc and NNSi_SndArcPlayerStartSeq: take a
 * voice handle (NNSi_SndPlayerAllocSeqPlayer), read its slot (NNSi_SndPlayerAllocHeap), load the wave
 * data through NNSi_SndArcLoadBank and release the handle if that fails, then bind
 * the loaded data and push the three per-voice parameters.  Eight arguments,
 * four in registers and four on the stack.
 *
 * THE BODY IS docs/notes/NNSi_SndArcPlayerStartSeqArc.c.txt's BODY, UNCHANGED.  That note
 * measured it at 200 bytes against the original's 196 and recorded seven
 * rejected spellings, diagnosing a callee-saved permutation:
 *
 *     slot   original   that C
 *     a1     r8         r5
 *     a2     r7         r8
 *     s0     r6         r7
 *     h      r5         r6
 *
 * with the extra instruction being `mov r5, #0; mov r3, r5` for NNSi_SndArcLoadBank's
 * fourth argument where the image emits `mov r3, #0` directly.  That is
 * verbatim the "kept constants" tell of docs/FRONTEND-PINS.md, and the note
 * measured every one of its seven spellings under the project default 1.1p1.
 * Under the cluster's ../2.0/sp2 pin the SAME C is 196 bytes, 0 mismatches,
 * first compile, with the image's register assignment: the residue was the
 * front end, not the source, exactly as docs/families/cluster_020737C0.h warns
 * for this address range.
 *
 * FILING THIS UNBLOCKS src/pending/NNS_SndArcPlayerStartSeqArc.c, whose header names the
 * PC24 at +0x0074 (this address, single caller image-wide) as the one site
 * keeping it at MATCH; with this entry EXACT the site resolves as `matched`.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_SndArcPlayerStartSeqArc.c \
 *       --func NNSi_SndArcPlayerStartSeqArc --addr 0x02075794 --arm --cc ../2.0/sp2
 */
u32 NNSi_SndArcPlayerStartSeqArc(u32 handle, u32 playerNo, u32 bankNo, u32 priority, struct Entry *entry, struct SndBlock *block, u32 arcIndex, u32 index)
{
    void *seqPlayer;
    u32 heap;
    u32 slot;

    seqPlayer = NNSi_SndPlayerAllocSeqPlayer((struct SndHandle *)handle, playerNo, priority);
    if (seqPlayer == 0) {
        return 0;
    }

    heap = (u32)NNSi_SndPlayerAllocHeap(playerNo, seqPlayer);

    if ((struct NNSSndHeap *)NNSi_SndArcLoadBank(bankNo, 6, (struct NNSSndHeap *)heap, 0, &slot) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(seqPlayer);
        return 0;
    }

    NNSi_SndPlayerStartSeqPlayer(seqPlayer, (void *)((u8 *)block + block->dataOffset), entry->seqOffset, (void *)slot);
    NNS_SndHandleSetInitialVolume((struct SndHandle *)handle, entry->initialVolume);
    NNS_SndHandlePause((struct SndHandle *)handle, entry->pauseFlag);
    NNSi_SndHandleSetSeqArc((struct SndHandle *)handle, arcIndex, index);
    return 1;
}





/*
 * The per-slot tick of the four 0x17c-byte entries of data_0214EAC0: bit 0
 * gates the slot, bit 2 + f120 runs the reconfigure and flips the pending
 * bits, bit 1 steps the lerp and recomputes the f164 sum out of the s16
 * table data_020A5D08, and bit 3 polls for completion.
 *
 * PINNED ../2.0/sp2 on the "kept branches" tell (docs/FRONTEND-PINS.md),
 * cross-jump form. The image writes the f11c == 0 arm's tail out in full --
 * `mov r0, r7` (`07 00 a0 e1`) at 0x02075884 / `bl NNSi_SndTrackStop` at
 * 0x02075888 / `b 0x0207594c` (`2e 00 00 ea`) at 0x0207588C -- although the
 * bit-3 completion arm ends in a byte-identical `mov r0, r7` / `bl
 * NNSi_SndTrackStop` pair at 0x02075944/0x02075948. dsi/1.1p1 -O4,p cross-jumps
 * the two, branching the f11c arm straight into the completion arm's pair,
 * giving 264 bytes against the original's 272 with everything after
 * 0x02075884 shifted by eight. An explicit `goto` past the else, the
 * if/else chain and the early-continue spelling all fold the same way.
 * Under the pin the same C is 272 bytes, 0 mismatches: BYTE-CORRECT.
 *
 * CAPPED AT MATCH for lack of an outside witness, not for codegen. Three
 * sites are unattested: the two PC24 to NNSi_SndTrackStop, whose only branches
 * image-wide are these two `bl`s inside this function, and the ABS32 at
 * +0x108, whose only pool word image-wide is this function's own at
 * 0x02075960 (inside the 272-byte compared range), so `literal` refuses it.
 * Filing NNSi_SndTrackStop EXACT clears the two PC24 sites but not the ABS32.
 *
 * NOTE for src/pending/NNS_SndBoot.c: that file names 0x02075858 as one
 * of its three blocking PC24 sites. This file is byte-correct but stays
 * MATCH, so it does NOT promote NNS_SndBoot -- only a `matched` entry can.
 */
void NNSi_SndArcPlayerUpdate(void)
{
    s32 slot;
    s32 volume;
    s32 trackVolume, faderIndex, playerVolume, faderVolume;
    struct SndTrack *track = data_0214EAC0;

    for (slot = 0; slot < 4; slot++) {
        if (track->active) {
            if (track->seqNo == 0) {
                NNSi_SndTrackStop(track);
                goto next;
            } else {
                if (track->startPending && track->pendingSeqNo != 0) {
                    NNS_SndStrmStart(&track->stream);
                    track->followFader = 1;
                    track->startPending = 0;
                }
                if (track->followFader) {
                    NNS_SndFaderUpdate(&track->fader);
                    trackVolume = data_020A5D08[track->volumeIndex];
                    faderIndex = NNS_SndFaderGet(&track->fader) >> 8;
                    playerVolume = track->playerVolumeIndex;
                    faderVolume = data_020A5D08[faderIndex];
                    volume = data_020A5D08[playerVolume] + (faderVolume + trackVolume);

                    if (volume != track->appliedVolume) {
                        NNS_SndStrmSetVolume(&track->stream, volume);
                        track->appliedVolume = volume;
                    }
                    if (track->stopPending) {
                        if (NNS_SndFaderIsFinished(&track->fader) != 0) {
                            NNSi_SndTrackStop(track);
                        }
                    }
                }
            }
        }
next:
        track++;
    }
}




/*
 * Release the object's attached cell (+0x154: clear what it points at, then
 * the pointer) and clear flag bits 0, 2 and 1 of the word at +0x118, in that
 * order.  The +0x118 word is the signed one-bit bitfield set its callers
 * 0x02075A2C and 0x02075994 test with lsl/asrs (docs/notes/pkt_02075794.c.txt).
 *
 * Front end: ../2.0/sp2.  The tell is the first clear writing a FRESH
 * register (`bic r2, r1, #1` then `bic r1, r2, #4`): 1.1p1 coalesces it
 * (`bic r1, r1, #1`, 2 bytes out under every spelling and a 2000-compile
 * anneal); ../2.0/sp2 and sp2p2 give the image's allocation for both the
 * bitfield and the three-statement mask spelling.
 */
void NNSi_SndTrackDetachObject(struct SndTrack *track)
{
    if (track->attachedObject != 0) {
        *track->attachedObject = 0;
        track->attachedObject = 0;
    }
    track->active = 0;
    track->startPending = 0;
    track->followFader = 0;
}





/*
 * Symbols:
 *   g_02150178  0x02150178  data
 *   g_0214EA90  0x0214EA90  data
 *
 * Two relocation sites stay wildcarded, neither for want of C:
 *   +0064  bl NNSi_SndTrackClose   `label`: 0x02075A2C's only branch image-wide is
 *                             this function's own call (asm, single caller).
 *                             It is inside THIS packet; the callee is parked
 *                             (byte-correct MATCH, its own `bl 0x02075968`
 *                             site has the same defect), so filing it does not
 *                             attest this site either.
 *   +0090  ABS32 g_02150178   `literal`: the only pool word naming 0x02150178
 *                             anywhere in the image, so own-pool-only.
 * The remaining six sites resolve (`label` x20/x20/x5/x20/x20, `literal` x5).
 * Spelled with the two bitfields at +0x118 as signed 1-bit fields; an
 * unsigned field emits `lsrs r0, r0, #0x1f` where the image has `asrs`, a
 * concrete two-byte diff.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNSi_SndTrackStop.c \
 *       --func NNSi_SndTrackStop --addr 0x02075994 --arm --cc 1.1p1
 */
void NNSi_SndTrackStop(struct SndTrack *track)
{
    u8 *p;

    OS_LockMutex((struct OSMutex *)g_02150178);
    p = *(u8 **)(g_0214EA90 + 4);
    if (p != 0)
        OS_LockMutex((struct OSMutex *)(p + 0x10c8));
    if (track->followFader != 0)
        NNSi_SndStrmStopIfSetup(&track->stream);
    if (track->active != 0)
        track->releaseCallback(track);
    NNSi_SndTrackClose(track);
    OS_UnlockMutex((struct OSMutex *)g_02150178);
    p = *(u8 **)(g_0214EA90 + 4);
    if (p == 0)
        return;
    OS_UnlockMutex((struct OSMutex *)(p + 0x10c8));
}




/*
 *           branch anywhere in the image outside 02075A2C..02075A94, so
 *           `label` refuses it - and 0x02075968 is itself only 8 bytes from
 *           EXACT (two BIC destinations), see docs/notes/pkt_02075794.c.txt.
 *           (2) ABS32 g_02150190: the data address is named by exactly one
 *           pool word in the image, this function's own, so `literal` has no
 *           second occurrence either.  The other four sites resolve
 *           (NNSi_SndTrackReleaseRef and NNSi_SndTrackListUnlinkByValue as `matched`, g_0214EA90 as
 *           `literal x5`).  The body is byte-correct.
 */
void NNSi_SndTrackClose(struct SndTrack *track)
{
    u8 *p;

    if (track->active == 0) return;
    NNSi_SndTrackReleaseRef(track);
    track->stopCallback(track);
    NNSi_SndTrackListUnlinkByValue(g_02150190, (u32)track);
    p = *(u8 **)(g_0214EA90 + 4);
    if (p != 0) NNSi_SndTrackListUnlinkByValue(p + 0x10e0, (u32)track);
    NNSi_SndTrackDetachObject(track);
}




void NNSi_SndTrackReleaseRef(struct SndTrack *track)
{
    if (track->refCount != 0) {
        if (--track->refCount == 0) {
            NNS_SndStrmFreeChannel(&track->stream);
        }
    }
}




/*
 * The unlink walk holds the interrupt state in the lowest callee-saved
 * register and the next link in r6, so the state survives the two calls in
 * the body; declaring `n` inside the loop (rather than hoisting it) is what
 * keeps r6 out of the prologue's push.
 */
void NNSi_SndTrackListUnlinkByValue(void *list, u32 value)
{
    u32 intrState = OS_DisableInterrupts();
    void *elem = NNS_FndGetNextListObject(list, 0);

    while (elem != 0) {
        void *nextElem = NNS_FndGetNextListObject(list, elem);

        if (((struct DListElem *)elem)->value == value) {
            NNS_FndRemoveListObject(list, elem);
            NNSi_SndTrackListUnlinkElem(elem);
        }
        elem = nextElem;
    }
    OS_RestoreInterrupts(intrState);
}


void NNSi_SndTrackListUnlinkElem(void *elem)
{
    u32 intrState = OS_DisableInterrupts();
    NNS_FndAppendListObject((struct NNSFndList *)(g_0214EA90 + 0xc), elem);
    OS_RestoreInterrupts(intrState);
}



/*
 * Signed compare against zero for the negative index (`movlt`/`bxlt`) but an
 *  * unsigned `>=` for the bound (`movhs`/`bxhs`), which is what an `int` index
 *  * compared against a `u32` count gives; the -1 element test is the
 *  * R_ARM_ABS32-free third guard the tail ends on. No relocations at all.
 */
struct Entry *NNSi_SndArcGetSeqEntry(struct Table *table, int index)
{
    struct Entry *entry;

    if (index < 0) return 0;
    if (index >= table->count) return 0;
    entry = &table->arr[index];
    if (entry->seqOffset == -1) return 0;
    return entry;
}




void NNSi_SndFaderReset(SndFader *fader)
{
    fader->target = 0;
    fader->start = 0;
    fader->duration = 0;
    fader->step = 0;
}

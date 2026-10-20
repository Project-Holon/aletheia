#ifndef GAME_ARM9_NNS_SND_ARCPLAYER_H
#define GAME_ARM9_NNS_SND_ARCPLAYER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_snd_arcplayer.c, prototypes copied from their definitions. */

struct SndArcPlayerEntry;
struct SndBlock;
struct SndTrack;
struct Table;

#include "../types.h"
#include "../arm9/nns_snd_types.h"

u32 NNS_SndArcPlayerStartSeq(u32 handle, u32 seqNo);
u32 NNS_SndArcPlayerStartSeqEx(u32 handle, int playerNo, int bankNo, int priority, u32 seqNo);
u32 NNS_SndArcPlayerStartSeqArc(u32 handle, u32 arcIndex, u32 index);
u32 NNSi_SndArcPlayerStartSeq(u32 handle, u32 playerNo, u32 bankNo, u32 priority, struct SndArcPlayerEntry *entry, u32 seqNo);
u32 NNSi_SndArcPlayerStartSeqArc(u32 handle, u32 playerNo, u32 bankNo, u32 priority, struct SndArcPlayerEntry *entry, struct SndBlock *block, u32 arcIndex, u32 index);
void NNSi_SndArcPlayerUpdate(void);
void NNSi_SndTrackDetachObject(struct SndTrack *track);
void NNSi_SndTrackStop(struct SndTrack *track);
void NNSi_SndTrackClose(struct SndTrack *track);
void NNSi_SndTrackReleaseRef(struct SndTrack *track);
void NNSi_SndTrackListUnlinkByValue(void *list, u32 value);
void NNSi_SndTrackListUnlinkElem(void *elem);
struct SndArcPlayerEntry *NNSi_SndArcGetSeqEntry(struct Table *table, int index);
void NNSi_SndFaderReset(SndFader *fader);
/* END mkheaders: generated region */

#endif

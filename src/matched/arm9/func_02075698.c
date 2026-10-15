/*
 * function: NNSi_SndArcPlayerStartSeq
 * address:  0x02075698
 * packet:   pkt_02075404
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   NNSi_SndPlayerAllocSeqPlayer  0x02073344  arm
 *   NNSi_SndPlayerAllocHeap  0x020734AC  arm
 *   NNSi_SndArcLoadBank  0x02074CD0  arm
 *   NNSi_SndArcLoadSeq  0x02074BEC  arm
 *   NNSi_SndPlayerFreeSeqPlayer  0x020733DC  arm
 *   NNSi_SndPlayerStartSeqPlayer  0x020733E8  arm
 *   NNS_SndHandleSetInitialVolume  0x02072F48  arm
 *   NNS_SndHandlePause  0x02072F88  arm
 *   NNSi_SndHandleSetSeqNo  0x020730B8  arm
 */
#include "../include/Obj16686.h"
typedef unsigned char u8;
typedef unsigned int  u32;

typedef signed int     s32;
struct Node;
struct Obj;
extern struct Node *NNSi_SndPlayerAllocSeqPlayer(struct Obj *o, s32 idx, s32 pri);
extern void *NNSi_SndPlayerAllocHeap(s32 idx, void *owner);
extern u32   NNSi_SndArcLoadBank(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern u32 NNSi_SndArcLoadSeq(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern void  NNSi_SndPlayerFreeSeqPlayer(void *h);
extern void NNSi_SndPlayerStartSeqPlayer(struct Obj *o, const void *seqBase, u32 seqOffset, const void *bankData);
extern void NNS_SndHandleSetInitialVolume(struct Obj *o, u8 v);
extern void NNS_SndHandlePause(struct Obj *o, u32 v);
extern void  NNSi_SndHandleSetSeqNo(u32 a, u32 b);

u32 NNSi_SndArcPlayerStartSeq(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u32 s1)
{
    void *h;
    u32 v;
    u8 *blk;
    u32 slot;

    h = NNSi_SndPlayerAllocSeqPlayer((struct Obj *)a0, a1, a3);
    if (h == 0) {
        return 0;
    }
    v = (u32)NNSi_SndPlayerAllocHeap(a1, h);
    if (NNSi_SndArcLoadBank(a2, 6, v, 0, &slot) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(h);
        return 0;
    }
    if (NNSi_SndArcLoadSeq(s1, 1, v, 0, (u32 *)(&blk)) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(h);
        return 0;
    }
    NNSi_SndPlayerStartSeqPlayer(h, (u32 *)(blk + ((struct Obj16686 *)blk)->f18), 0, (const void *)slot);
    NNS_SndHandleSetInitialVolume((struct Obj *)a0, s0[6]);
    NNS_SndHandlePause((struct Obj *)a0, s0[7]);
    NNSi_SndHandleSetSeqNo(a0, s1);
    return 1;
}

/*
 * function: func_02075794
 * address:  0x02075794
 * packet:   pkt_02075404
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   NNSi_SndPlayerAllocSeqPlayer  0x02073344  arm
 *   NNSi_SndPlayerAllocHeap  0x020734AC  arm
 *   NNSi_SndArcLoadBank  0x02074CD0  arm
 *   NNSi_SndPlayerFreeSeqPlayer  0x020733DC  arm
 *   NNSi_SndPlayerStartSeqPlayer  0x020733E8  arm
 *   NNS_SndHandleSetInitialVolume  0x02072F48  arm
 *   NNS_SndHandlePause  0x02072F88  arm
 *   NNSi_SndHandleSetSeqArc  0x020730DC  arm
 *
 * The four-step open/bind path behind func_02075618 and func_02075698: take a
 * voice handle (NNSi_SndPlayerAllocSeqPlayer), read its slot (NNSi_SndPlayerAllocHeap), load the wave
 * data through NNSi_SndArcLoadBank and release the handle if that fails, then bind
 * the loaded data and push the three per-voice parameters.  Eight arguments,
 * four in registers and four on the stack.
 *
 * THE BODY IS docs/notes/func_02075794.c.txt's BODY, UNCHANGED.  That note
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
 * FILING THIS UNBLOCKS src/pending/func_02075618.c, whose header names the
 * PC24 at +0x0074 (this address, single caller image-wide) as the one site
 * keeping it at MATCH; with this entry EXACT the site resolves as `matched`.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02075794.c \
 *       --func func_02075794 --addr 0x02075794 --arm --cc ../2.0/sp2
 */
#include "../include/Obj08953.h"
#include "../include/Obj16687.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef signed int     s32;
struct Node;
struct Obj;
extern struct Node *NNSi_SndPlayerAllocSeqPlayer(struct Obj *o, s32 idx, s32 pri);
extern void *NNSi_SndPlayerAllocHeap(s32 idx, void *owner);
extern u32   NNSi_SndArcLoadBank(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern void  NNSi_SndPlayerFreeSeqPlayer(void *h);
extern void NNSi_SndPlayerStartSeqPlayer(struct Obj *o, const void *seqBase, u32 seqOffset, const void *bankData);
extern void NNS_SndHandleSetInitialVolume(struct Obj *o, u8 v);
extern void NNS_SndHandlePause(struct Obj *o, u32 v);
extern void NNSi_SndHandleSetSeqArc(struct Obj *o, u32 a, u32 b);

u32 func_02075794(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u8 *s1, u32 s2, u32 s3)
{
    void *h;
    u32 v;
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

    NNSi_SndPlayerStartSeqPlayer(h, (u32 *)(s1 + ((struct Obj16687 *)s1)->f18), ((struct Obj08953 *)s0)->f0, (const void *)slot);
    NNS_SndHandleSetInitialVolume((struct Obj *)a0, s0[6]);
    NNS_SndHandlePause((struct Obj *)a0, s0[7]);
    NNSi_SndHandleSetSeqArc((struct Obj *)a0, s2, s3);
    return 1;
}

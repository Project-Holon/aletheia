/*
 * function: NNS_SndHeapCreate
 * address:  0x020746E8
 * packet:   pkt_020737C0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Carves one sub-allocation out of an (offset, size) window: round the offset
 * up to four, refuse the window if the rounded offset already ran past its end
 * or if fewer than 0x10 bytes remain, then allocate through NNS_FndCreateFrmHeap with
 * a 0x10-byte header reserved and register the block with NNSi_SndHeapInit. A
 * failed registration frees the block again and answers 0; success answers the
 * aligned offset.
 *
 * PINNED ../2.0/sp2, the pin five cluster siblings carry (NNS_SndStrmInit,
 * NNS_SndStrmSetVolume, NNS_SndStrmStop, NNSi_SndStrmAlarmHandler, NNS_SndHeapSaveState).
 * docs/notes/pkt_020746E8.c.txt recorded this body as 116 bytes against 112
 * with 77 concrete bytes out under dsi/1.1p1, which pools the constant 0 into
 * a callee-saved register and shifts every subsequent register by one
 * (docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md).
 * Under the pin the note's own C is size-exact at 112 bytes with only 8 bytes
 * out, and no register substitution at all -- one swapped instruction pair at
 * +0008.
 *
 * The last 8 bytes came from tools/permuter.py (hill, 200 compiles): the
 * mutation `temp(tmp = off + size)` closes it. Written out, that is simply
 * computing the window end BEFORE the rounded start, which is the order the
 * original source declared them in; writing `aligned` first makes mwcc emit
 * the `bic` before the `add`.
 *
 * The note's third finding, that NNS_FndCreateFrmHeap has no branch witness outside
 * this range, no longer caps the file: the 2026-09-21 sole-ref/code widening
 * attests it at its own function start.
 *
 * symbols:
 *   NNS_FndCreateFrmHeap  0x020610E0  arm
 *   NNSi_SndHeapInit  0x020749C4  arm
 *   NNS_FndDestroyFrmHeap  0x02061118  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_SndHeapCreate.c \
 *       --func NNS_SndHeapCreate --addr 0x020746E8 --cc ../2.0/sp2 --arm
 */

typedef unsigned int u32;

struct Table;
extern void *NNS_FndCreateFrmHeap(void *mem, u32 size, u32 opt);
extern int NNSi_SndHeapInit(struct Table *t, void *heap);
extern void  NNS_FndDestroyFrmHeap(void *p);

u32 NNS_SndHeapCreate(u32 off, u32 size)
{
    u32 end;
    u32 aligned;
    u32 rest;
    void *p;

    end     = off + size;
    aligned = (off + 3) & ~3u;

    if (aligned > end) return 0;
    rest = end - aligned;
    if (rest < 0x10) return 0;

    p = NNS_FndCreateFrmHeap((void *)(aligned + 0x10), rest - 0x10, 0);
    if (p == 0) return 0;
    if (NNSi_SndHeapInit((struct Table *)aligned, p) != 0) return aligned;

    NNS_FndDestroyFrmHeap(p);
    return 0;
}

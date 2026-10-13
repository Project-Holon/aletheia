/*
 * function: GFL_USE_LoadWaveArcSet
 * address:  0x02005A98
 * packet:   pkt_02005A98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * promoted: from src/pending 2026-09-19, no C change: blocker 0x02074A6C is filed in layout/matched/arm9/pkt_02074A6C.json and every site resolves (gate: manifest --verify --shard layout/matched/arm9/pkt_02005A98.json, then 0 rewritten).
 * blocker (RESOLVED 2026-09-19):  02074A6C - the `blx` inside this function is the only branch to
 *           it anywhere in the image, so `label` has no witness outside the
 *           compared range and the callee is not matched.  Closes when
 *           0x02074A6C's own shard is written.  All 100 concrete bytes and
 *           every other site are right.
 *
 * symbols:
 *   _SndStack    0x020AA1AC  data
 *   _SndSlots  0x020AA1B8  data
 *   GFL_USE_EndSndSlot        0x02005858  thumb
 *   GFL_USE_BeginSndSlot        0x02005834  thumb
 *   NNS_SndHeapAlloc       0x0207482C  arm
 *   NNS_SndArcLoadSeq       0x02074A6C  arm
 *   NNS_SndHeapSaveState       0x02074894  arm
 *
 * Push one connection slot onto the stack unit_02005A4C.c pops from: take
 * the current slot's field at +0xC as the saved status word, close the
 * current slot, allocate an 8-byte-plus header block, copy `a1` handles in,
 * stamp the count and the saved word, and finally reset the current index.
 * The loop is a `for` rotated by the compiler (the entry test is on the
 * bound, the back edge on the counter), and `a1` is unsigned because the
 * skid test is `bls`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_USE_LoadWaveArcSet.c \
 *       --func GFL_USE_LoadWaveArcSet --addr 0x02005A98 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02005A98Slot {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

struct Sub02005A98Cur {
    u16   unk00;
    u16   unk02;
    int   index;
    u32 **unk08;
};

struct Sub02005A98Hdr {
    u32 n;
    u32 status;
};

extern struct Sub02005A98Cur  _SndStack;
extern struct Sub02005A98Slot _SndSlots[];

extern void  GFL_USE_EndSndSlot(void);
extern void  GFL_USE_BeginSndSlot(u32 v);
extern u32 NNS_SndHeapAlloc(u32 *a, u32 b, u32 c, u32 d, u32 e);
extern u32   NNS_SndArcLoadSeq(u32 a, u32 b);
struct S;
extern int   NNS_SndHeapSaveState(struct S *a);

struct Sub02005A98Hdr *GFL_USE_LoadWaveArcSet(const u32 *a0, u32 a1)
{
    struct Sub02005A98Slot *slot;
    struct Sub02005A98Hdr *p;
    u32 saved;
    u32 i;

    slot = &_SndSlots[_SndStack.index];
    saved = slot->unk0C;
    GFL_USE_EndSndSlot();
    i = 0;
    p = (struct Sub02005A98Hdr *)NNS_SndHeapAlloc(*_SndStack.unk08, 8, 0, 0, 0);
    for (i = 0; i < a1; i++) {
        NNS_SndArcLoadSeq(a0[i], (u32)*_SndStack.unk08);
    }
    p->n = a1;
    p->status = saved;
    GFL_USE_BeginSndSlot(NNS_SndHeapSaveState((struct S *)*_SndStack.unk08));
    return p;
}

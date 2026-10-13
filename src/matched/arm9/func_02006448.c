/*
 * function: GFL_USE_InstallBgmBuffers
 * address:  0x02006448
 * packet:   pkt_020063B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * promoted: from src/pending 2026-09-19, no C change: blocker 0x02074A98 is filed in layout/matched/arm9/pkt_02074A6C.json and every site resolves (gate: manifest --verify --shard layout/matched/arm9/pkt_020063B4.json, then 0 rewritten).
 * blocker (RESOLVED 2026-09-19):  02074A98 - reached from the identical `blx` in
 *           src/matched/GFL_USE_InstallBgmBuffers.c's loop only, so `label` has no
 *           witness outside the compared range and the callee is not
 *           matched.  All 102 concrete bytes and every other site are right.
 *
 * symbols:
 *   _SndState     0x020AA260  data
 *   NNS_SndArcGetSeqInfo  0x02074324  arm
 *   NNS_SndArcGetBankInfo  0x020743EC  arm
 *   GFL_USE_SaveSeqBankState   0x0200597C  thumb
 *   NNS_SndArcLoadWaveArc  0x02074A98  arm
 *   NNS_SndArcSetFileAddress  0x02074694  arm
 *   GFL_USE_FinishBgmLoad   0x020059A0  thumb
 *
 * The four-voice "open with these handles" path: resolve the handle block,
 * split its header word and its halfword, and rebuild the table from it;
 * then check every one of the four 16-bit entries against 0xFFFF and bail
 * with 0 the first time a registration call fails (the loop counter is the
 * only thing the failure arm does not need, which is why the zero is
 * rematerialised rather than loaded from a local).
 *
 * The header word and the halfword at +4 are two separate loads before the
 * second call, and the *first* one goes to the stack slot the tail uses -
 * so the source read them in that order and passed them to NNS_SndArcGetBankInfo
 * swapped (`NNS_SndArcGetBankInfo(halfword, word)`).  The word at +0 of the returned
 * block is a full 32-bit load: it is the same field family as the four
 * halfwords at +4, but the first member is a `u32`, and spelling it as one
 * changes `ldrh` to `ldr` and nothing else.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_USE_InstallBgmBuffers.c \
 *       --func GFL_USE_InstallBgmBuffers --addr 0x02006448 --cc 1.1p1 --thumb
 */
#include "../include/Obj11220.h"

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02006448Pair {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u16 unk08;
    u16 unk0A;
};

extern char _SndState[];

extern void *NNS_SndArcGetSeqInfo(int index);
extern void *NNS_SndArcGetBankInfo(int index);
extern void   GFL_USE_SaveSeqBankState(void);
extern u32 NNS_SndArcLoadWaveArc(u32 a, u32 b);
extern void   NNS_SndArcSetFileAddress(u32 a, u32 b);
extern int GFL_USE_FinishBgmLoad(u32 a);

int GFL_USE_InstallBgmBuffers(u32 a0, u32 a1, u32 a2)
{
    u32 *hdr;
    struct Sub02006448Pair *q;
    u32 word;
    u16 half;
    u32 v;
    int i;

    hdr = NNS_SndArcGetSeqInfo(a2);
    word = hdr[0];
    half = ((struct Obj11220 *)hdr)->f4;
    q = NNS_SndArcGetBankInfo(half);
    v = q->unk00;
    GFL_USE_SaveSeqBankState();
    for (i = 0; i < 4; i++) {
        if (*(u16 *)((char *)q + 4 + i * 2) != 0xFFFF) {
            if (NNS_SndArcLoadWaveArc(*(u16 *)((char *)q + 4 + i * 2),
                              *(u32 *)(_SndState + 0x10)) == 0) {
                return 0;
            }
        }
    }
    NNS_SndArcSetFileAddress(v, a1);
    NNS_SndArcSetFileAddress(word, a0);
    GFL_USE_FinishBgmLoad(a2);
    return 1;
}

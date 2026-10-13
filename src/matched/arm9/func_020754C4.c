/*
 * function: NNS_SndArcPlayerSetup
 * address:  0x020754C4
 * packet:   pkt_02075404
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * Walk the 32 slots of the current archive (NNS_SndArcGetCurrent is called for its
 * side effect only): for every slot record NNS_SndArcGetPlayerInfo hands back, apply
 * its count byte and +2 halfword (NNS_SndPlayerSetPlayableSeqCount / NNS_SndPlayerSetAllocatableChannel), and when
 * both the record's +4 payload and the argument are non-null, register the
 * payload count times with NNS_SndPlayerCreateHeap, failing out on the first refusal.
 *
 * Levers (permuter hill found the first, the second is a prototype read):
 *   - declaration order i, e, j (register r6 / r7 / r8);
 *   - the slot index is `int` in the CALLEE PROTOTYPES as well as the loop
 *     (NNS_SndPlayerCreateHeap's first parameter above all).  With the callee declared
 *     u32 the implicit conversion reshuffles r4-r7 (14 bytes out); the loop
 *     compare is `blt`, so the index itself is signed.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_SndArcPlayerSetup.c \
 *       --func NNS_SndArcPlayerSetup --addr 0x020754C4 --arm --cc ../2.0/sp2
 *   EXACT, 156 bytes, 5 of 5 relocation sites resolved (sp2p2 the same,
 *   dsi/1.1p1 152 bytes DIFF).
 *
 * symbols:
 *   NNS_SndArcGetCurrent  0x020742FC  arm
 *   NNS_SndArcGetPlayerInfo  0x020744B4  arm
 *   NNS_SndPlayerSetPlayableSeqCount  0x02072DB0  arm
 *   NNS_SndPlayerSetAllocatableChannel  0x02072DD0  arm
 *   NNS_SndPlayerCreateHeap  0x02072DE8  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  count;
    u8  pad01;
    u16 h2;
    void *data;
} Ent;

struct Global;
extern struct Global *NNS_SndArcGetCurrent(void);
extern void *NNS_SndArcGetPlayerInfo(int index);
extern void  NNS_SndPlayerSetPlayableSeqCount(int idx, int v);
extern void NNS_SndPlayerSetAllocatableChannel(u32 idx, u32 val);
extern u32   NNS_SndPlayerCreateHeap(int idx, u32 a, void *src);

u32 NNS_SndArcPlayerSetup(u32 a)
{
    int i;
    Ent *e;
    int j;

    NNS_SndArcGetCurrent();
    for (i = 0; i < 32; i++) {
        e = NNS_SndArcGetPlayerInfo(i);
        if (e == 0)
            continue;
        NNS_SndPlayerSetPlayableSeqCount(i, e->count);
        NNS_SndPlayerSetAllocatableChannel(i, e->h2);
        if (e->data != 0 && a != 0) {
            for (j = 0; j < e->count; j++) {
                if (NNS_SndPlayerCreateHeap(i, a, e->data) == 0)
                    return 0;
            }
        }
    }
    return 1;
}

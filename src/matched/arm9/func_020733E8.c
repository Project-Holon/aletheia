/*
 * function: NNSi_SndPlayerStartSeqPlayer
 * address:  0x020733E8
 * packet:   pkt_02073098
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SND_PrepareSeq                  0x02089350  arm
 *   SND_SetTrackAllocatableChannel  0x0208948C  arm
 *   SND_GetCurrentCommandTag        0x02089D40  arm
 *   NNSi_SndSeqPlayerResetState                   0x02073500  arm
 *
 * Start a sequence on a voice (the NitroSystem sound-player layer over the
 * TwlSDK SND driver): prepare the sequence on the voice's player number,
 * restrict its allocatable channels when the owning player object has a
 * channel mask at +0x1c, reset the voice, record the current command tag and
 * mark it prepared/playing.
 *
 * The 2-byte residue of docs/notes/pkt_020733E8.c.txt (the guard load in r2
 * where the compile used r0) was an ARITY, as that note suspected, but on
 * both callees at once: SND_PrepareSeq takes FOUR arguments (playerNo,
 * seqBase, seqOffset, bankData), so this function forwards its own r1..r3
 * untouched; and SND_SetTrackAllocatableChannel takes THREE (playerNo,
 * trackBitMask, chBitMask), so the guard value in r2 is the channel mask
 * being passed on.  The callers NNSi_SndArcPlayerStartSeq / NNSi_SndArcPlayerStartSeqArc already pass
 * four arguments.  The pin is ../2.0/sp2 (1.1p1: 9 bytes out).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_SndPlayerStartSeqPlayer.c \
 *       --func NNSi_SndPlayerStartSeqPlayer --addr 0x020733E8 --arm --cc ../2.0/sp2
 */
typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub { u8 pad00[0x1c]; u32 f1c; };

struct Obj {
    u8  pad00[4];
    struct Sub *f4;
    u8  pad08[0x2c - 8];
    u8  b2c;
    u8  pad2d[2];
    u8  b2f;
    u32 f30;
    u8  pad34[0x3c - 0x34];
    u8  b3c;
};

extern void SND_PrepareSeq(int playerNo, const void *seqBase, u32 seqOffset, const void *bankData);
extern void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask);
extern int NNSi_SndSeqPlayerResetState(int a0);
extern u32  SND_GetCurrentCommandTag(void);

void NNSi_SndPlayerStartSeqPlayer(struct Obj *o, const void *seqBase, u32 seqOffset, const void *bankData)
{
    struct Sub *s = o->f4;
    SND_PrepareSeq(o->b3c, seqBase, seqOffset, bankData);
    if (s->f1c != 0) {
        SND_SetTrackAllocatableChannel(o->b3c, 0xFFFF, s->f1c);
    }
    NNSi_SndSeqPlayerResetState((int)o);
    o->f30 = SND_GetCurrentCommandTag();
    o->b2f = 1;
    o->b2c = 1;
}

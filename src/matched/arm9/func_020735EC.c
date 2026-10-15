/*
 * function: NNSi_SndSeqPlayerStopNow
 * address:  0x020735EC
 * packet:   pkt_02073548
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0024 PC24 SND_StopSeq           -> unresolved: 02089330 (arm, from header) has no witness outside 020735EC..02073624
 *
 * symbols:
 *   func_020893D0    0x020893D0  arm
 *   SND_StopSeq    0x02089330  arm
 *   NNSi_SndSeqPlayerRelease    0x0207368C  arm
 *
 * Tears the player down: in state 2 first sets the volume to -723, then stops
 * the sequence and calls the state machine again.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_SndSeqPlayerStopNow.c \
 *       --func NNSi_SndSeqPlayerStopNow --addr 0x020735EC --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u8 unk00[0x2c];
    u8 unk2c;
    u8 unk2d[0x3c - 0x2d];
    u8 unk3c;
} Obj020735EC;

extern void func_020893D0(u32 player, int vol);
extern void SND_StopSeq(int playerNo);
struct Voice;
extern void NNSi_SndSeqPlayerRelease(struct Voice *v);

void NNSi_SndSeqPlayerStopNow(Obj020735EC *p)
{
    if (p->unk2c == 2) {
        func_020893D0(p->unk3c, -723);
    }
    SND_StopSeq(p->unk3c);
    NNSi_SndSeqPlayerRelease((struct Voice *)p);
}

/*
 * function: NNSi_SndStrmStopIfSetup
 * address:  0x02073AB4
 * packet:   pkt_02073AB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0014 PC24 NNS_SndStrmStop           -> unresolved: 02073B3C (arm, from header) has no witness outside 02073AB4..02073AD0
 *
 * symbols:
 *   NNS_SndStrmStop    0x02073B3C  arm
 *
 * Guards the call on bit 0 of the flags word at +0x2C, which the original reads
 * as a signed one-bit field (lsl #31 / asrs #31).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_SndStrmStopIfSetup.c \
 *       --func NNSi_SndStrmStopIfSetup --addr 0x02073AB4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef struct {
    u32 unk00[0xb];
    int unk2c : 1;
} Obj02073AB4;

struct Obj;
extern void NNS_SndStrmStop(struct Obj *o);

void NNSi_SndStrmStopIfSetup(Obj02073AB4 *p)
{
    if (p->unk2c != 0) {
        NNS_SndStrmStop((struct Obj *)p);
    }
}

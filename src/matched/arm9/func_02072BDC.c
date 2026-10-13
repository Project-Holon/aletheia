/*
 * function: NNS_SndWaveOutStop
 * address:  0x02072BDC
 * packet:   pkt_02072A44
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020894DC  0x020894DC  arm
 *
 * Guards on the slot's +8 word, then calls func_020894DC(1 << s->unk00, 0, 0, 0)
 * and clears the guard.
 *
 * Built by the 2.0 front end, on the "kept constants" tell: the image
 * materialises both the shift operand and the three zero arguments as
 * immediates (`mov r2, #1` / `mov r1, #0` / `lsl r0, r2, r0` / `mov r2, r1` /
 * `mov r3, r1`) and keeps the object in r4 with a two-register push.  dsi/1.1p1
 * rematerialises the zero from the pool into a callee-saved register, moves the
 * object to r5 and grows the push to {r3, r4, r5, lr} -- 23 concrete bytes of
 * diff, and the same residue ../1.2/sp2 gives 39 bytes of.  ../2.0/sp2
 * reproduces the image byte for byte.  Same tell and family as
 * src/matched/NNS_SndArcLoadSeq.c and src/pending/NNS_G3dDraw.c.
 *
 * Evidence recorded in docs/notes/pkt_02072A44.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_SndWaveOutStop.c \
 *       --func NNS_SndWaveOutStop --addr 0x02072BDC --arm --cc ../2.0/sp2
 */

typedef unsigned int u32;

typedef struct {
    u32 unk00;
    u32 unk04;
    u32 unk08;
} Slot02072BDC;

extern void func_020894DC(u32 chan, u32 a, u32 b, u32 c);

void NNS_SndWaveOutStop(Slot02072BDC *s)
{
    if (s->unk08 == 0) {
        return;
    }
    func_020894DC(1 << s->unk00, 0, 0, 0);
    s->unk08 = 0;
}

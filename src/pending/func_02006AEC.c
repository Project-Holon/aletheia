/*
 * function: func_02006AEC
 * address:  0x02006AEC
 * packet:   pkt_02006948
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * blocker:  02072C40 (arm) reached only by the two `blx` inside this function
 *
 * symbols:
 *   g_02140488  0x02140488  data
 *   func_02072C40  0x02072C40  arm
 *
 * Advance a voice's sample cursor by `delta`: the sum is stored first and
 * the stored value is what is passed to the first call, so the source kept
 * it in a local and stored through the pointer before the call.  The second
 * call re-reads both the cursor and the length, which is why it is written
 * as the same pointed-to additions again rather than reusing the local.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006AEC.c \
 *       --func func_02006AEC --addr 0x02006AEC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Sub02006AECVoice {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
};

extern struct Sub02006AECVoice g_02140488[];
extern void func_02072C40(u32 a, u32 b);

void func_02006AEC(u32 idx, u32 delta)
{
    struct Sub02006AECVoice *p;
    u32 v;

    p = &g_02140488[idx];
    if (p->unk00 == 0) {
        return;
    }
    v = p->unk20 + delta;
    p->unk20 = v;
    func_02072C40(p->unk14, v);
    if (p->unk2C == 1) {
        func_02072C40(p->unk18, p->unk20 + p->unk24);
    }
}

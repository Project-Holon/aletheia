/*
 * function: PM_VOICE_AddVolume
 * address:  0x02006A8C
 * packet:   pkt_02006948
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02140488  0x02140488  data
 *   PM_VOICE_ScaleVolume  0x0200674C  thumb
 *   NNS_SndWaveOutSetVolume  0x02072C18  arm
 *
 * Pan two voices by a signed delta: both fields at +0x1C and +0x1D are
 * `s8` (the loads are `ldrsb`, see
 * docs/idioms/ldrsh-register-offset-is-signedness.md), each is clamped to
 * [0, 0x7F] with what is written as two separate `if`s - the `bpl`/`ble`
 * pair is a signed compare on the *sum*, which is why the clamp is on the
 * int-typed result rather than on the byte.  The second field's value is
 * re-narrowed to a byte before it is passed on, so the call takes a u8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PM_VOICE_AddVolume.c \
 *       --func PM_VOICE_AddVolume --addr 0x02006A8C --cc 1.1p1 --thumb
 */

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02006A8CVoice {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u8  unk1C;
    u8  unk1D;
    u8  unk1E;
    u8  unk1F;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
};

extern struct Sub02006A8CVoice g_02140488[];
extern u8 PM_VOICE_ScaleVolume(u8 volume);
struct S;
extern void NNS_SndWaveOutSetVolume(struct S *s, u32 v);

void PM_VOICE_AddVolume(u32 idx, int delta)
{
    struct Sub02006A8CVoice *p;
    int v;

    p = &g_02140488[idx];
    if (p->unk00 == 0) {
        return;
    }
    v = *(signed char *)&p->unk1C + delta;
    if (v < 0) {
        v = 0;
    }
    if (v > 0x7F) {
        v = 0x7F;
    }
    p->unk1C = (u8)v;
    NNS_SndWaveOutSetVolume((struct S *)p->unk14, PM_VOICE_ScaleVolume(p->unk1C));
    if (p->unk2C == 1) {
        v = *(signed char *)&p->unk1C + *(signed char *)&p->unk1D;
        if (v < 0) {
            v = 0;
        }
        if (v > 0x7F) {
            v = 0x7F;
        }
        NNS_SndWaveOutSetVolume((struct S *)p->unk14, PM_VOICE_ScaleVolume((u8)v));
    }
}

/*
 * unit:     yes
 * address:  0x0202878C
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PLAYER_VOLUME_FADER_Update, PLAYER_VOLUME_FADER_SetTarget, PLAYER_VOLUME_FADER_SetMute, PLAYER_VOLUME_FADER_Init,
 *           PLAYER_VOLUME_FADER_StartFade, PLAYER_VOLUME_FADER_SetLevel, PLAYER_VOLUME_FADER_Tick, PLAYER_VOLUME_FADER_GetLevel,
 *           PLAYER_VOLUME_FADER_Apply
 *
 * The tail of player_volume_fader.c (its file string is carried by
 * PLAYER_VOLUME_FADER_Create, outside this packet): a nine byte record holding a channel
 * id, a start and a target level, a duration and an elapsed count, and the
 * eight entry points that drive it.  PLAYER_VOLUME_FADER_GetLevel is the interpolation,
 * PLAYER_VOLUME_FADER_Apply is the "push the current level at the mixer" step every
 * mutator ends with, and PLAYER_VOLUME_FADER_Tick is the per-frame tick.
 *
 * The nine functions are one file because five of them are reached only from
 * inside it and two of those five are reached only through a tail call's pool
 * word, which is not a branch and therefore not a `label` witness
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  In one object they are
 * `local` and need no image evidence.  Nothing outside the file loses a
 * witness by the merge: the two externally called entry points, PLAYER_VOLUME_FADER_SetMute
 * and PLAYER_VOLUME_FADER_Init, are called with real branches from outside the packet
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).
 *
 * PLAYER_VOLUME_FADER_GetLevel's division is the compiler's signed helper at 0x0209C0A4 and
 * not a shift, which is what says the operands are `int` rather than unsigned
 * (docs/idioms/runtime-helper-reloc.md).  The difference of the two levels is
 * the multiply's destination register, so the level pair is the left operand
 * of the multiply and the elapsed count the right
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *
 * Its four locals also need their declaration order and their initialisation
 * order to disagree: declared elapsed, from, to, frames but assigned from, to,
 * elapsed, frames.  Declaration order picks the registers and initialisation
 * order picks the order of the four loads, and no single order gives both
 * (docs/idioms/declaration-order-picks-the-register-initialisation-order-picks-the-load.md).
 *
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   NNS_SndPlayerSetPlayerVolume  0x02072D98  arm
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202878C.c \
 *       --addr 0x0202878C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Fader {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u16 unk04;
    u16 unk06;
    u8  unk08;
};

extern void NNS_SndPlayerSetPlayerVolume(u32 channel, u32 level);

void PLAYER_VOLUME_FADER_Tick(struct Fader *s);
void PLAYER_VOLUME_FADER_StartFade(struct Fader *s, u8 target, u16 frames);
void PLAYER_VOLUME_FADER_SetLevel(struct Fader *s, u8 level);
u32  PLAYER_VOLUME_FADER_GetLevel(struct Fader *s);
void PLAYER_VOLUME_FADER_Apply(struct Fader *s);

void PLAYER_VOLUME_FADER_Update(struct Fader *s)
{
    PLAYER_VOLUME_FADER_Tick(s);
}

void PLAYER_VOLUME_FADER_SetTarget(struct Fader *s, u8 level, u16 frames)
{
    if (frames == 0) {
        PLAYER_VOLUME_FADER_SetLevel(s, level);
    } else {
        PLAYER_VOLUME_FADER_StartFade(s, level, frames);
    }
}

void PLAYER_VOLUME_FADER_SetMute(struct Fader *s, u8 mute)
{
    s->unk08 = mute;
    PLAYER_VOLUME_FADER_Apply(s);
}

void PLAYER_VOLUME_FADER_Init(struct Fader *s)
{
    s->unk00 = 0;
    s->unk01 = 0x7F;
    s->unk02 = 0x7F;
    s->unk04 = 0;
    s->unk06 = 0;
    s->unk08 = 0;
    PLAYER_VOLUME_FADER_Apply(s);
}

void PLAYER_VOLUME_FADER_StartFade(struct Fader *s, u8 target, u16 frames)
{
    s->unk01 = PLAYER_VOLUME_FADER_GetLevel(s);
    s->unk02 = target;
    s->unk04 = frames;
    s->unk06 = 0;
}

void PLAYER_VOLUME_FADER_SetLevel(struct Fader *s, u8 level)
{
    s->unk01 = level;
    s->unk02 = level;
    s->unk04 = 0;
    s->unk06 = 0;
    PLAYER_VOLUME_FADER_Apply(s);
}

void PLAYER_VOLUME_FADER_Tick(struct Fader *s)
{
    if (s->unk06 < s->unk04) {
        s->unk06 = s->unk06 + 1;
        PLAYER_VOLUME_FADER_Apply(s);
    }
}

u32 PLAYER_VOLUME_FADER_GetLevel(struct Fader *s)
{
    u16 elapsed;
    u8 from;
    u8 to;
    u16 frames;
    u32 level;

    from = s->unk01;
    to = s->unk02;
    elapsed = s->unk06;
    frames = s->unk04;
    level = from;
    if (elapsed != 0) {
        level = from + (to - from) * elapsed / frames;
    }
    return level;
}

void PLAYER_VOLUME_FADER_Apply(struct Fader *s)
{
    u32 level = PLAYER_VOLUME_FADER_GetLevel(s);

    if (s->unk08 != 0) {
        level = 0;
    }
    NNS_SndPlayerSetPlayerVolume(s->unk00, level);
}

/*
 * file:     player_volume_fader.c
 * unit:     yes
 * function: PLAYER_VOLUME_FADER_Create, PLAYER_VOLUME_FADER_Delete, PLAYER_VOLUME_FADER_Update, PLAYER_VOLUME_FADER_SetTarget, PLAYER_VOLUME_FADER_SetMute, PLAYER_VOLUME_FADER_Init, PLAYER_VOLUME_FADER_StartFade, PLAYER_VOLUME_FADER_SetLevel, PLAYER_VOLUME_FADER_Tick, PLAYER_VOLUME_FADER_GetLevel, PLAYER_VOLUME_FADER_Apply
 * address:  0x02028760
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from app_keycursor.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734      0x02030734  arm
 *   player_volume_fader_File 0x020A7500  data
 *   func_020307B0  0x020307B0  arm
 *   NNS_SndPlayerSetPlayerVolume  0x02072D98  arm
 */
#include "app_keycursor_shared_types.h"

/* Nine bytes of mixer state: channel, current and target level, fade length
 * and elapsed frames, mute. */
struct Fader {
    u8  channel;
    u8  from;
    u8  to;
    u8  pad03;
    u16 frames;
    u16 elapsed;
    u8  mute;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void NNS_SndPlayerSetPlayerVolume(u32 channel, u32 level);

struct Fader *PLAYER_VOLUME_FADER_Create(void *a, int v);

void PLAYER_VOLUME_FADER_Delete(void *ptr);

void PLAYER_VOLUME_FADER_Update(struct Fader *s);

void PLAYER_VOLUME_FADER_SetTarget(struct Fader *s, u8 level, u16 frames);

void PLAYER_VOLUME_FADER_SetMute(struct Fader *s, u8 mute);

void PLAYER_VOLUME_FADER_Init(struct Fader *s);

void PLAYER_VOLUME_FADER_StartFade(struct Fader *s, u8 target, u16 frames);

void PLAYER_VOLUME_FADER_SetLevel(struct Fader *s, u8 level);

void PLAYER_VOLUME_FADER_Tick(struct Fader *s);

u32 PLAYER_VOLUME_FADER_GetLevel(struct Fader *s);

void PLAYER_VOLUME_FADER_Apply(struct Fader *s);

extern const char player_volume_fader_File[];

/*
 * TU: player_volume_fader.c (__FILE__ 0x020A7500, line 66).
 *
 * The file is a nine byte record holding a channel id, a start and a target
 * level, a duration and an elapsed count, and the entry points that drive it.
 * PLAYER_VOLUME_FADER_GetLevel is the interpolation, PLAYER_VOLUME_FADER_Apply is the "push the current
 * level at the mixer" step every mutator ends with, and PLAYER_VOLUME_FADER_Tick is the
 * per-frame tick.  The division in PLAYER_VOLUME_FADER_GetLevel is the compiler's signed
 * helper (0x0209C0A4), so the operands are `int` and not unsigned.  Its four
 * locals need their declaration order and their initialisation order to
 * disagree (declaration order picks the registers, initialisation order picks
 * the load order).
 */
struct Fader *PLAYER_VOLUME_FADER_Create(void *a, int v)
{
    struct Fader *p = func_02030734((unsigned int)a, sizeof(struct Fader), 0,
                                    player_volume_fader_File, 0x42);
    PLAYER_VOLUME_FADER_Init(p);
    p->channel = v;
    return p;
}

void PLAYER_VOLUME_FADER_Delete(void *ptr)
{
    func_020307B0(ptr);
}

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
    s->mute = mute;
    PLAYER_VOLUME_FADER_Apply(s);
}

void PLAYER_VOLUME_FADER_Init(struct Fader *s)
{
    s->channel = 0;
    s->from = 0x7F;
    s->to = 0x7F;
    s->frames = 0;
    s->elapsed = 0;
    s->mute = 0;
    PLAYER_VOLUME_FADER_Apply(s);
}

void PLAYER_VOLUME_FADER_StartFade(struct Fader *s, u8 target, u16 frames)
{
    s->from = PLAYER_VOLUME_FADER_GetLevel(s);
    s->to = target;
    s->frames = frames;
    s->elapsed = 0;
}

void PLAYER_VOLUME_FADER_SetLevel(struct Fader *s, u8 level)
{
    s->from = level;
    s->to = level;
    s->frames = 0;
    s->elapsed = 0;
    PLAYER_VOLUME_FADER_Apply(s);
}

void PLAYER_VOLUME_FADER_Tick(struct Fader *s)
{
    if (s->elapsed < s->frames) {
        s->elapsed = s->elapsed + 1;
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

    from = s->from;
    to = s->to;
    elapsed = s->elapsed;
    frames = s->frames;
    level = from;
    if (elapsed != 0) {
        level = from + (to - from) * elapsed / frames;
    }
    return level;
}

void PLAYER_VOLUME_FADER_Apply(struct Fader *s)
{
    u32 level = PLAYER_VOLUME_FADER_GetLevel(s);

    if (s->mute != 0) {
        level = 0;
    }
    NNS_SndPlayerSetPlayerVolume(s->channel, level);
}

/*
 * function: SHINKA_DEMO_EFFECT_UpdateParticle
 * address:  0x022089A4
 * packet:   pkt_022089A4
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   PARTICLE_KillAllEffects 0x02051620 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct Cue {
    u16 frame;
    u8 emit;
    u8 id;
} Cue;

typedef struct Emit {
    u8 work[0x4800];
    void *spl;
    u8 res;
    u8 pad[3];
} Emit;

typedef struct Ptc {
    u16 frame;
    u16 cue;
    u16 ncue;
    u16 pad06;
    Cue *cues;
    Emit emit[1];
    u32 active;
    s32 timer;
} Ptc;

extern int PARTICLE_StartEffect(void *p, int b, int c);
extern void PARTICLE_KillAllEffects(void *spl);

void SHINKA_DEMO_EFFECT_UpdateParticle(Ptc *p)
{
    if (p->active != 0) {
        VecFx32 v = {0, 0, 0};
        Cue *c;

        for (; p->cue < p->ncue; p->cue++) {
            if (p->frame != p->cues[(int)p->cue].frame)
                break;
            c = &p->cues[p->cue];
            PARTICLE_StartEffect(p->emit[c->emit].spl, c->id, (int)(&v));
        }
        p->frame++;
    }
    if (p->timer >= 0) {
        if (p->timer == 0)
            PARTICLE_KillAllEffects(p->emit[0].spl);
        p->timer--;
    }
}

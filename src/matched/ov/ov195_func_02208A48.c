/*
 * function: SHINKA_DEMO_EFFECT_SetParticleTimerRaw
 * address:  0x02208A48
 * packet:   pkt_02208A48
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (saves no lr), seeded by address.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

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
    void *cues;
    Emit emit[1];
    u32 active;
    s32 timer;
} Ptc;

void SHINKA_DEMO_EFFECT_SetParticleTimerRaw(Ptc *p, s32 timer)
{
    p->timer = timer;
}

/*
 * function: SHINKA_DEMO_EFFECT_Main
 * address:  0x0220878C
 * packet:   pkt_0220878C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SHINKA_DEMO_EFFECT_AnimSetState1 0x02208C10 thumb ov195
 *   SHINKA_DEMO_EFFECT_AnimIsState2 0x02208C18 thumb ov195
 *   SHINKA_DEMO_EFFECT_AnimSetState3 0x02208C28 thumb ov195
 *   SHINKA_DEMO_EFFECT_AnimIsState0 0x02208C30 thumb ov195
 *   SHINKA_DEMO_EFFECT_SetParticleTimerRaw 0x02208A48 thumb ov195
 *   SHINKA_DEMO_EFFECT_UpdateAnime 0x02208B6C thumb ov195
 *   SHINKA_DEMO_EFFECT_UpdateParticle 0x022089A4 thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Anim {
    u16 heap;
    u16 pad02;
    u32 f04;
    u32 state;
    u32 wait;
    void *ptc;
} Anim;

extern void SHINKA_DEMO_EFFECT_AnimSetState1(Anim *p);
extern int SHINKA_DEMO_EFFECT_AnimIsState2(Anim *p);
extern void SHINKA_DEMO_EFFECT_AnimSetState3(Anim *p);
extern int SHINKA_DEMO_EFFECT_AnimIsState0(Anim *p);
struct Ptc;
extern void SHINKA_DEMO_EFFECT_SetParticleTimerRaw(struct Ptc *p, s32 timer);
extern void SHINKA_DEMO_EFFECT_UpdateAnime(char *p);
extern void SHINKA_DEMO_EFFECT_UpdateParticle(struct Ptc *p);

void SHINKA_DEMO_EFFECT_Main(Anim *p)
{
    switch (p->state) {
    case 0:
    case 1:
        break;
    case 2:
        SHINKA_DEMO_EFFECT_AnimSetState1(p);
        p->state = 3;
        break;
    case 3:
        if (SHINKA_DEMO_EFFECT_AnimIsState2(p)) {
            p->state = 4;
            p->wait = 3;
            SHINKA_DEMO_EFFECT_SetParticleTimerRaw(p->ptc, 0);
        }
        break;
    case 4:
        if (p->wait == 0) {
            SHINKA_DEMO_EFFECT_AnimSetState3(p);
            p->state = 5;
        } else {
            p->wait = p->wait - 1;
        }
        break;
    case 5:
        if (SHINKA_DEMO_EFFECT_AnimIsState0(p))
            p->state = 6;
        break;
    case 6:
    case 7:
        break;
    }
    SHINKA_DEMO_EFFECT_UpdateAnime((char *)p);
    SHINKA_DEMO_EFFECT_UpdateParticle(p->ptc);
}

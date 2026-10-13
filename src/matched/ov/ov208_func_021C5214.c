/*
 * function: ov208_func_021C5214
 * address:  0x021C5214
 * packet:   pkt_ov208_021C5214
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MCSS_GetAnimCtrl  0x02015EE8  thumb
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   NNS_G2dRestartMCAnimation  0x02064CBC  arm
 */

typedef unsigned int u32;

struct Ov208AnmState {
    u32 f0;
    u32 f4;
    u32 f8;
    int active;
};

struct Ov208Anm {
    u32 obj;
    struct Ov208AnmState *state;
};

extern void *MCSS_GetAnimCtrl(void *p);
extern void MCSS_SetAnmStopFlag(void *p);
struct Obj;
extern void NNS_G2dRestartMCAnimation(struct Obj *x);

void ov208_func_021C5214(struct Ov208Anm *p)
{
    void *anm;

    if (p->obj != 0 && p->state != 0) {
        anm = MCSS_GetAnimCtrl((void *)p->obj);
        if (p->state->active != 0) {
            MCSS_SetAnmStopFlag((void *)p->obj);
            NNS_G2dRestartMCAnimation(anm);
            p->state->active = 0;
        }
    }
}

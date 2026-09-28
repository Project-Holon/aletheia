/*
 * function: func_022089A4
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
 *   func_020515B4 0x020515B4 arm
 *   func_02051620 0x02051620 arm
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

extern void func_020515B4(void *spl, u32 id, VecFx32 *pos);
extern void func_02051620(void *spl);

void func_022089A4(Ptc *p)
{
    if (p->active != 0) {
        VecFx32 v = {0, 0, 0};
        Cue *c;

        for (; p->cue < p->ncue; p->cue++) {
            if (p->frame != p->cues[(int)p->cue].frame)
                break;
            c = &p->cues[p->cue];
            func_020515B4(p->emit[c->emit].spl, c->id, &v);
        }
        p->frame++;
    }
    if (p->timer >= 0) {
        if (p->timer == 0)
            func_02051620(p->emit[0].spl);
        p->timer--;
    }
}

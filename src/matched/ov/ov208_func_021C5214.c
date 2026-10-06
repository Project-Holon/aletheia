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
 *   func_02015EE8  0x02015EE8  thumb
 *   func_02015E04  0x02015E04  thumb
 *   func_02064CBC  0x02064CBC  arm
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

extern void *func_02015EE8(void *p);
extern void func_02015E04(void *p);
struct Obj;
extern void func_02064CBC(struct Obj *x);

void ov208_func_021C5214(struct Ov208Anm *p)
{
    void *anm;

    if (p->obj != 0 && p->state != 0) {
        anm = func_02015EE8((void *)p->obj);
        if (p->state->active != 0) {
            func_02015E04((void *)p->obj);
            func_02064CBC(anm);
            p->state->active = 0;
        }
    }
}

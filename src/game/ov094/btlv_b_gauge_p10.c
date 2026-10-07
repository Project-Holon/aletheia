/*
 * file:     btlv_b_gauge_p10.c
 * unit:     yes
 * function: func_02209068, func_022090A4, func_022090B4, func_02209214
 * address:  0x02209068
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0200616C 0x0200616C thumb
 *   func_021F89BC 0x021F89BC thumb ov094
 */
struct Bank;
struct Obj;
struct Vec2;
typedef unsigned int u32;

typedef struct {
    int h0;
    int h4;
    int h8;
    int hc;
    struct { int f10; char pad[0x18]; } e[7];
} W_02209068;

typedef unsigned short u16;

typedef short s16;

typedef struct { s16 x, y; } Vec2;

typedef struct { void *h; int goal, home, step, frame, wait; Vec2 pos; } Entry;

typedef struct { char pad[0x10]; Entry entries[7]; int state, active, sound; u16 heap; } Work;

typedef struct { Work *owner; } Context;

typedef struct { char pad[0xd8]; int fd8; } W_02209214;

extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_020307B0(void *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0200616C(void *, int);
extern void func_021F89BC(void *);
extern W_02209214 **func_02030EE8(void *h);
void func_02209068(W_02209068 *w);
int func_022090A4(int *p);
void func_022090B4(void *task, Context *c);
void func_02209214(void *h);


void func_02209068(W_02209068 *w)
{
    int i;

    for (i = 0; i < 7; i++)
        func_0204B3B4((struct Obj *)w->e[i].f10);
    func_0204A8D4(w->h4);
    func_0204ADA4(w->hc);
    func_0204AFD8(w->h8);
    func_0204B1CC((struct Bank *)w->h0);
    func_020307B0(w);
}


int func_022090A4(int *p)
{
    if (p[0xd8 / 4 + 0] != 0)
        return 1;
    return 0;
}

/*
 * lever: set busy before decrementing the delay; reversed statements
 *   interchange the movs and str at +002C/+002E.
 */
void func_022090B4(void *task, Context *c)
{
    int i;
    int busy = 0;
    int sound;
    switch (c->owner->state) {
    case 0:
        for (i = 0; i < 7; i++) {
            if (c->owner->entries[i].wait != 0) {
                busy = 1;
                c->owner->entries[i].wait--;
            } else if (c->owner->entries[i].step != 0) {
                c->owner->entries[i].pos.x += (s16)c->owner->entries[i].step;
                busy = 1;
                if (c->owner->entries[i].step > 0) {
                    if (c->owner->entries[i].pos.x >= c->owner->entries[i].goal) {
                        c->owner->entries[i].pos.x = c->owner->entries[i].goal;
                        c->owner->entries[i].step = 0;
                    }
                } else {
                    if (c->owner->entries[i].pos.x <= c->owner->entries[i].goal) {
                        c->owner->entries[i].pos.x = c->owner->entries[i].goal;
                        c->owner->entries[i].step = 0;
                    }
                }
                func_0204B404(c->owner->entries[i].h, (const struct Vec2 *)(&c->owner->entries[i].pos), 0);
                if (c->owner->entries[i].step == 0) {
                    func_0204B878(c->owner->entries[i].h, c->owner->entries[i].frame);
                    switch (c->owner->entries[i].frame) {
                    case 9: sound = 0x572; break;
                    case 10:
                    case 11: sound = 0; break;
                    default: sound = 0x571; break;
                    }
                    if (sound != 0) {
                        func_0200616C((void *)sound, c->owner->sound);
                        c->owner->sound ^= 1;
                    }
                }
            }
        }
        if (!busy) c->owner->state++;
        break;
    case 1:
        for (i = 0; i < 7; i++) {
            if (c->owner->entries[i].pos.x < c->owner->entries[i].home) {
                c->owner->entries[i].pos.x += 2;
                if (c->owner->entries[i].pos.x >= c->owner->entries[i].home)
                    c->owner->entries[i].pos.x = c->owner->entries[i].home;
                busy = 1;
            } else if (c->owner->entries[i].pos.x > c->owner->entries[i].home) {
                c->owner->entries[i].pos.x -= 2;
                if (c->owner->entries[i].pos.x <= c->owner->entries[i].home)
                    c->owner->entries[i].pos.x = c->owner->entries[i].home;
                busy = 1;
            }
            func_0204B404(c->owner->entries[i].h, (const struct Vec2 *)(&c->owner->entries[i].pos), 0);
        }
        if (!busy) func_021F89BC(task);
        break;
    }
}


void func_02209214(void *h)
{
    (*func_02030EE8(h))->fd8 = 0;
}

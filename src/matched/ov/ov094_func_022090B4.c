/*
 * function: func_022090B4
 * address: 0x022090B4
 * packet: pkt_ov094_022090B4
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: set busy before decrementing the delay; reversed statements
 *   interchange the movs and str at +002C/+002E.
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0200616C 0x0200616C thumb
 *   func_021F89BC 0x021F89BC thumb ov094
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;
typedef struct { s16 x, y; } Vec2;
typedef struct { void *h; int goal, home, step, frame, wait; Vec2 pos; } Entry;
typedef struct { char pad[0x10]; Entry entries[7]; int state, active, sound; u16 heap; } Work;
typedef struct { Work *owner; } Context;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_0200616C(void *, int);
extern void func_021F89BC(void *);
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
                    CLACT_SetActorAnimSeq(c->owner->entries[i].h, c->owner->entries[i].frame);
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

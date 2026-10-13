/*
 * function: WIPE_SUB_BoxStep
 * address:  0x02023568
 * packet:   pkt_02022F60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIPE_SUB_AddRect  0x0202291C  thumb
 *   WIPE_SUB_RequestWindowRect  0x02023D60  thumb
 *
 * One tick of the wipe object.  +0x40 is a frame counter compared against
 * the step length at +0x3c: until it reaches the step, nothing happens
 * and the answer is 0.  On a step boundary the counter resets and the
 * remaining-step count at +0x38 is decremented; while steps remain the
 * interpolator at +0x10 is advanced (WIPE_SUB_AddRect) and the current
 * position is pushed to WIPE_SUB_RequestWindowRect with each of the three 1/128
 * fixed-point coordinates at +0x00, +0x04, +0x08 rounded toward zero
 * (`(v + (v >> 6 >> 25)) >> 7`, the compiler's signed /128), plus the
 * 1/128 scalar at +0x0c.  When the last step is used up the object jumps
 * straight to its final values (+0x2c, +0x20, +0x24, +0x28) and answers
 * 1, which is what WIPE_SUB_BoxMain waits for.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_BoxStep.c \
 *       --func WIPE_SUB_BoxStep --addr 0x02023568 --cc 1.1p1 --thumb
 */

typedef int          s32;
typedef unsigned int u32;

struct Obj {
    s32 x;       /* 0x00 */
    s32 y;       /* 0x04 */
    s32 z;       /* 0x08 */
    s32 w;       /* 0x0c */
    u32 pad10[4];
    u32 f20;     /* 0x20 */
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    s32 steps;   /* 0x38 */
    s32 period;  /* 0x3c */
    s32 tick;    /* 0x40 */
    u32 f44;
    u32 f48;     /* 0x48 */
};

struct Quad;
extern void WIPE_SUB_AddRect(struct Quad *dst, struct Quad *src);
typedef unsigned char  u8;
extern void WIPE_SUB_RequestWindowRect(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);

u32 WIPE_SUB_BoxStep(struct Obj *o)
{
    s32 n;

    n = o->tick + 1;
    o->tick = n;
    if (n >= o->period) {
        o->tick = 0;
        n = o->steps - 1;
        if (n > 0) {
            o->steps = n;
            WIPE_SUB_AddRect((struct Quad *)o, (struct Quad *)((char *)o + 0x10));
            goto step;
        }

        WIPE_SUB_RequestWindowRect((u8 *)o->f48, o->f20, o->f24, o->f28, o->f2c, o->f34,
                      o->f30);
        return 1;

    step:
        WIPE_SUB_RequestWindowRect((u8 *)o->f48, o->x / 128, o->y / 128, o->z / 128,
                      o->w / 128, o->f34, o->f30);
    }

    return 0;
}

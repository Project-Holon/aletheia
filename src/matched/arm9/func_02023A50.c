/*
 * function: func_02023A50
 * address:  0x02023A50
 * packet:   pkt_02023A50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02023AB0  0x02023AB0  thumb
 *   func_02022EF4  0x02022EF4  thumb
 *   func_02022F24  0x02022F24  thumb
 *
 * The per-frame poll of the 0x334-byte wipe object built by
 * func_020238B4: it ticks the frame counter at +0x320 against the frame
 * limit at +0x31c, and on expiry advances the step index at +0x318
 * against the bound at +0x314.
 *
 * THE COMPARISON IS `<=`, NOT `>`, and it is the function's only real
 * decision.  Written `if (w->step + 1 > w->step_bound)` the function is
 * 92 bytes with every other byte right and ONE wrong: the branch at
 * +0x2a comes out `ble` where the image has `bgt`.  The image branches to
 * the redraw block when step+1 is GREATER than the +0x314 bound, so the
 * fall-through -- the source's first arm -- is the `<=` case, which is
 * the one that calls func_02023AB0/func_02022EF4 and answers 0
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  That makes
 * +0x314 a floor rather than a ceiling: the object is retired while the
 * step index is still inside it and keeps redrawing once it is past,
 * which reads backwards until you notice func_02023AB0 is what pushes
 * the NEXT step in, so "inside the bound" here means "there is another
 * step to load".
 *
 * Every field is past the Thumb immediate reach, so the whole group is
 * addressed off ONE register offset (movs #0x32 / lsls #4 = 0x320) that
 * the compiler then bumps by -4, -8, -0xc and +0x10 per access
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Declaring the
 * fields as members of one struct is what keeps that single base; four
 * separate far offsets would each cost their own pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023A50.c \
 *       --func func_02023A50 --addr 0x02023A50 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef signed int     s32;
typedef unsigned int   u32;

struct Wipe {
    u8  pad000[0x314];
    s32 step_bound;   /* 0x314  see the note above: a floor, not a ceiling */
    s32 step;         /* 0x318 */
    s32 frame_limit;  /* 0x31c */
    s32 frame;        /* 0x320 */
    s32 f324;         /* 0x324 */
    s32 f328;         /* 0x328 */
    s32 f32c;
    s32 f330;         /* 0x330 */
};

extern void func_02023AB0(void *p);
extern u32  func_02022EF4(void *p);
extern void func_02022F24(u32 a0, void *a1, u32 a2);

u32 func_02023A50(struct Wipe *w)
{
    s32 f;

    f = w->frame + 1;
    w->frame = f;
    if (f >= w->frame_limit) {
        w->frame = 0;
        if (w->step + 1 <= w->step_bound) {
            w->step = w->step + 1;
            func_02023AB0(w);
            func_02022EF4(w);
        } else {
            func_02022F24(w->f330, w, w->f328);
            return 1;
        }
    }

    return 0;
}

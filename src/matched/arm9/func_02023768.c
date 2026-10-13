/*
 * function: WIPE_SUB_CircleStep
 * address:  0x02023768
 * packet:   pkt_02023768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SUB_CalcCircleLines  0x0202384C  thumb
 *   GFL_USE_AddMainTask   0x020056A0  thumb
 *   WIPE_RequestClearHBlankSlot  0x02022568  thumb
 *   WIPE_SUB_FlipLineBuffersTask  0x02022D98  thumb
 *
 * The per-frame poll of the wipe object built at 0x02023464, and the near
 * twin of WIPE_SUB_ShutterStep at the other end of the family: tick the frame
 * counter at +0x24 against the limit at +0x20, and on expiry step the
 * countdown at +0x1c.  A countdown still above zero advances the running
 * offset at +0x0c by the stride at +0x18, redraws through WIPE_SUB_CalcCircleLines
 * and re-arms the callback WIPE_SUB_FlipLineBuffersTask at priority 0x3FF; a countdown
 * that has reached zero finishes through WIPE_RequestClearHBlankSlot and is the only
 * path that answers 1.
 *
 * The countdown is decremented into a LOCAL and only stored back on the
 * arm that keeps going: `n = w->left - 1; if (n > 0) { w->left = n; ... }`.
 * Written as a compound `w->left -= 1` followed by a test of the field the
 * store lands before the branch and the `ldr`/`subs`/`cmp` triple at
 * +0x1c..+0x22 becomes four instructions
 * (docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md).
 *
 * Like WIPE_SUB_ShutterStep this has exactly two exits sharing one `movs r0, #0;
 * pop {r4, pc}` tail, which is what the single trailing `return 0` after
 * the whole nest buys; a `return 0` in each arm duplicates the epilogue
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_CircleStep.c \
 *       --func WIPE_SUB_CircleStep --addr 0x02023768 --cc 1.1p1 --thumb
 */

typedef signed int   s32;
typedef unsigned int u32;

struct Wipe {
    u32 f00;
    u32 f04;
    u32 f08;
    s32 f0c;          /* 0x0c  running offset */
    u32 f10;
    u32 f14;
    s32 f18;          /* 0x18  stride */
    s32 left;         /* 0x1c  countdown */
    s32 frame_limit;  /* 0x20 */
    s32 frame;        /* 0x24 */
    u32 f28;          /* 0x28 */
    u32 f2c;
    u32 f30;
    u32 f34;          /* 0x34 */
};

extern void  WIPE_SUB_CalcCircleLines(struct Wipe *w);
extern void *GFL_USE_AddMainTask(void *fn, void *arg, u32 prio);
extern void  WIPE_RequestClearHBlankSlot(u32 a0, u32 a1, u32 a2);
struct Container;
extern void WIPE_SUB_FlipLineBuffersTask(void *p, struct Container *c);

u32 WIPE_SUB_CircleStep(struct Wipe *w)
{
    s32 f;
    s32 n;

    f = w->frame + 1;
    w->frame = f;
    if (f >= w->frame_limit) {
        w->frame = 0;
        n = w->left - 1;
        if (n > 0) {
            w->left = n;
            w->f0c = w->f0c + w->f18;
            WIPE_SUB_CalcCircleLines(w);
            GFL_USE_AddMainTask((void *)WIPE_SUB_FlipLineBuffersTask, w, 0x3FF);
        } else {
            WIPE_RequestClearHBlankSlot(w->f34, w->f08, w->f28);
            return 1;
        }
    }

    return 0;
}

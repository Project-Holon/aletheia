/*
 * function: func_02023768
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
 *   func_0202384C  0x0202384C  thumb
 *   sub_020056A0   0x020056A0  thumb
 *   func_02022568  0x02022568  thumb
 *   func_02022D98  0x02022D98  thumb
 *
 * The per-frame poll of the wipe object built at 0x02023464, and the near
 * twin of func_02023A50 at the other end of the family: tick the frame
 * counter at +0x24 against the limit at +0x20, and on expiry step the
 * countdown at +0x1c.  A countdown still above zero advances the running
 * offset at +0x0c by the stride at +0x18, redraws through func_0202384C
 * and re-arms the callback func_02022D98 at priority 0x3FF; a countdown
 * that has reached zero finishes through func_02022568 and is the only
 * path that answers 1.
 *
 * The countdown is decremented into a LOCAL and only stored back on the
 * arm that keeps going: `n = w->left - 1; if (n > 0) { w->left = n; ... }`.
 * Written as a compound `w->left -= 1` followed by a test of the field the
 * store lands before the branch and the `ldr`/`subs`/`cmp` triple at
 * +0x1c..+0x22 becomes four instructions
 * (docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md).
 *
 * Like func_02023A50 this has exactly two exits sharing one `movs r0, #0;
 * pop {r4, pc}` tail, which is what the single trailing `return 0` after
 * the whole nest buys; a `return 0` in each arm duplicates the epilogue
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023768.c \
 *       --func func_02023768 --addr 0x02023768 --cc 1.1p1 --thumb
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

extern void  func_0202384C(struct Wipe *w);
extern void *sub_020056A0(void *fn, void *arg, u32 prio);
extern void  func_02022568(u32 a0, u32 a1, u32 a2);
extern void  func_02022D98(void);

u32 func_02023768(struct Wipe *w)
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
            func_0202384C(w);
            sub_020056A0((void *)func_02022D98, w, 0x3FF);
        } else {
            func_02022568(w->f34, w->f08, w->f28);
            return 1;
        }
    }

    return 0;
}

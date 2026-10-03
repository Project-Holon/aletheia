/*
 * function: func_02014628
 * address:  0x02014628
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The shared tail of the three working cases sits INSIDE case 0's arm (a
 * label a later arm jumps back to is what makes 0x02014658 fall out of case 0
 * with no branch) and the default arm's `return 0` is reached by a `goto`
 * rather than copied, which is what puts the single `movs r0, #0` epilogue at
 * 0x02014692.  `u32 a0 = p[0];` before the switch is load-bearing: without it
 * each arm reloads p[0] and the whole dispatch shifts.
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */

typedef unsigned int u32;

extern u32  func_021BE8D4(u32 a, u32 b, u32 c, u32 d);
extern u32  func_021BE92C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32  func_02014728(u32 a, u32 b, u32 c, u32 d, u32 e);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);

u32 func_02014628(void *obj, u32 *mode, u32 *p)
{
    u32 a0 = p[0];
    void *r;

    switch (*mode) {
    case 0:
        r = (void *)func_021BE8D4(a0, p[1], 0, 0);
    tail:
        func_02012374(obj, r);
        (*mode)++;
        goto ret0;
    case 1:
        r = (void *)func_02014728(a0, p[1], p[2], p[3], p[4]);
        goto tail;
    case 2:
        r = (void *)func_021BE92C(a0, p[1], 0, 0, 1, 0, 0);
        goto tail;
    case 3:
        return 1;
    default:
    ret0:
        return 0;
    }
}

/*
 * function: func_021B69F8
 * address:  0x021B69F8
 * packet:   pkt_021B69F8
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * BLOCKER: shape, not register names.  The original stores p[0x24]=0 then
 * `bl func_02015F2C` and `pop`; every spelling tried either tail-calls
 * (pool + `bx r3`, no frame) when the call is last, or moves the store after
 * the call and adds a callee-saved r4 frame.  The original keeps a `bl` and
 * the store before it; not reproduced.
 *
 * symbols:
 *   func_02015F2C  0x02015F2C  thumb
 *   func_021B69E8  0x021B69E8  thumb  ov180
 */

extern void func_02015F2C(int, void *, void *);
extern void func_021B69E8(void);

void func_021B69F8(char *p)
{
    func_02015F2C(*(int *)(p + 0x1c), p, (void *)func_021B69E8);
    *(int *)(p + 0x24) = 0;
}

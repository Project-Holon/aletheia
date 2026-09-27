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
 * `bl func_02015F2C` and `pop {r3, pc}`; every spelling tried either tail-calls
 * (pool + `bx r3`, no frame) with the store first, or emits the store after the
 * call and adds a callee-saved r4 frame.  Re-verified 2026-09-27: call-first
 * (store after) gives a full `bl`, but mwcc always schedules the store after
 * the call and builds the r4 frame; store-first always becomes a `bx r3` tail
 * call.  No C form yet gives `bl` + store-before-call with the r3-only frame.
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

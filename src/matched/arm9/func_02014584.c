/*
 * function: func_02014584
 * address:  0x02014584
 * packet:   pkt_02014584
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188BE8  0x02188BE8  thumb ov021
 *
 * blocker:  020120C0 - unresolved (thumb, from name): no witness outside
 *           02014584..020145CA.  This is the chain class of the band brief:
 *           0x020120C0's only callers are inside this range, so `label` has
 *           nothing to point at.  It is NOT a lane-2 row (it lives in
 *           pkt_020120B4 and is a chain row of the 0-64 band list), so this
 *           file cannot be finished from inside the lane.  Filing
 *           0x020120C0's own EXACT entry converts the site to `matched` and
 *           this file prints EXACT with no change to the C below.
 *
 * Byte-correct at all 70 concrete bytes; 3 of 4 relocation sites resolved.
 *
 * Two spelling points that were needed to get this far:
 *   - func_02188BE8 lives in ov021 and is THUMB.  Left to the name-based
 *     fallback it is inferred `arm` and match.py stops with an ISA conflict
 *     ("the source declares arm, the image says thumb"), which reads like a
 *     compile failure but is a symbols: block omission.  Naming the region
 *     (`func_02188BE8  0x02188BE8  thumb ov021`) resolves the site through
 *     `label` (9 outside branches, e.g. 0x02012078).
 *   - `switch (*a1)` with `break` in the arms, not `return 0`: the original
 *     has exactly one `movs r0,#0 / pop` epilogue, shared by the arms and by
 *     the fall-through.  Writing `return 0` in each arm duplicates it and
 *     costs 36 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02014584.c \
 *       --func func_02014584 --addr 0x02014584 --cc 1.1p1 --thumb
 */

extern int  func_020120F0(int v);
extern void func_020120C0(int v);
extern void *func_0201210C(void *p);
extern int  func_02188BE8(void *v);

int func_02014584(int a0, int *a1, int *a2)
{
    int v = *a2;

    switch (*a1) {
    case 0:
        if (func_020120F0(v) == 0) {
            func_020120C0(v);
            *a1 = *a1 + 1;
        }
        break;
    case 1:
        if (func_02188BE8(func_0201210C((void *)v)) != 0) {
            *a1 = *a1 + 1;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

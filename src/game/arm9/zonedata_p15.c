/*
 * file:     zonedata_p15.c
 * unit:     yes
 * function: func_02014584, func_020145CC
 * address:  0x02014584
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188BE8  0x02188BE8  thumb ov021
 *   func_0215FA34  0x0215FA34  thumb  ov010
 */
struct Ctx;
struct IcaAnime;
struct Desc;
struct Obj;
typedef unsigned int   u32;

extern u32 func_020120F0(const struct Ctx *p);
extern void func_020120C0(struct IcaAnime *p);
extern void *func_0201210C(const struct Ctx *p);
extern int  func_02188BE8(void *v);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_0215FA34(void);
int func_02014584(int a0, int *a1, int *a2);
void *func_020145CC(void *a0);


/*
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
int func_02014584(int a0, int *a1, int *a2)
{
    int v = *a2;

    switch (*a1) {
    case 0:
        if (func_020120F0((const struct Ctx *)v) == 0) {
            func_020120C0((struct IcaAnime *)v);
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


/*
 * promoted: seed round 9, EXACT (fresh match.py one) once the ov010 callees
 *           0x0215FA34 and 0x0215FA44 were seeded in layout/function_starts.txt
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c): still
 *           MATCH, 3 of 4 sites resolved, no change to the C.  The single
 *           blocker 0x0215FA34 is the same overlay-export class as the
 *           two in sub_02014488.c: ov009 and ov010 both cover it and
 *           neither labels a function there, so no region hint helps.
 * wave15:   overlay callees are unlabelled Thumb starts: 0x0215FA34 and
 *           0x0215FA44 in ov010 (.word 0x4B024801, ldr r0/ldr r3 thunks),
 *           0x02188BD8 in ov021; need seeds in those overlays' listings.
 */
void *func_020145CC(void *a0)
{
    void *r6 = func_020122C0(a0, 0, (void *)0x02014585, 0x10);
    u32 *r4 = func_020124E8(r6);

    r4[0] = (u32)a0;
    r4[1] = 0;
    r4[2] = (u32)func_020120F4(a0);
    func_0215FA34();
    return r6;
}

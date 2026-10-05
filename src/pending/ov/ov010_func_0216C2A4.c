/*
 * function: func_0216C2A4
 * address:  0x0216C2A4
 * packet:   pkt_ov010_0216C2A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * checks: 1 current matched interfaces retain live r1 through 021A3044;
 * 2 C0E8/C2FC family has no exact snap twin; 3 full-range signed Coord
 * enum locals give28/88, raw-offset signed loads retain27/88;
 * 4 enum/grid/local-storage idioms reread; 5 directory/neighbours refreshed,
 * VecFx32 is a real local with correct sp offsets, no new shape lever.
 * permuter: prior seed 9603 consumed; not repeated in renewed wave75 pass.
 * wave75: enum bias/inline setter did not improve 27-byte register/schedule residue.
 * wave76 final retry: unsigned z candidate gives45/80 but changes signed
 * division and is rejected. Enum coordinates and raw loads do not improve
 * the retained27/88. Three fixed one runs; renewed manual pass exhausted,
 * consumed seed9603 search never repeated.
 * Arithmetic uses modular unsigned addition and shifts before signed consumption.
 * recoup 2026-10-05 (P19L3): size now 88/88, 27 bytes differ (register colours
 * and load order only). Callees checked: func_021BE480 is int in its matched
 * file (declared as pointer here, as in matched ov010 func_0216C0E8); func_021A3044
 * is a thunk, two arguments as in the sibling. Plain signed literals
 * (z + 0x20000, +0x8000) fold the constant to 2<<14 and give 86 B; so does a
 * signed or unsigned constant local, an unsigned z local, and an inline Snap with
 * a signed add. Only (unsigned)z + 0x20000u keeps 2<<16 shared with >>2 (88 B).
 * Load order: source order x,z,y or y,z,x gives hardware order z,y,x or y,z,x;
 * the image has x,z,y with y in r5 and the constant in r2. Pragmas
 * opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, peephole
 * off: no change (28 B). Idioms read: two-long-lived-values-in-each-others-registers,
 * a-repeated-small-constant-takes-a-callee-saved-register, a-small-constant-is-
 * rematerialised-off-a-zero-register, a-getter-declared-void-changes-constant-hoisting,
 * a-self-recompute-pins-an-operand, a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie
 * (this residue fits the last one: loads dying before any call or join).
 *
 * Snap the actor's position to the 16-unit grid (z biased by 32) and
 * write it to the ov021 map object. Size-exact, 27 bytes out: the image
 * loads x, z, y in that order and stores x, z, y; hoisting the call into
 * q, locals for the three coordinates and storing y last got here from
 * 65. An inline Snap(), a struct copy, and permuter seed 9603 (best 15,
 * only by an unnatural temp) do not close it.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 */

typedef unsigned char u8;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Work {
    u8 pad00[8];
    void *field;        /* 0x08 */
} Work;

extern void *func_02188D2C(void *field);
extern VecFx32 *func_021BE480(void *p, int a, int b);
extern void *func_02188CB4(void *field);
extern void func_021A3044(void *q, const VecFx32 *pos);

void func_0216C2A4(Work *w)
{
    VecFx32 v;
    const VecFx32 *pos;
    void *q;
    fx32 x;
    fx32 y;
    fx32 z;

    pos = func_021BE480(func_02188D2C(w->field), 0, 0);
    q = func_02188CB4(w->field);
    y = pos->y;
    z = pos->z;
    x = pos->x;
    z = (int)((unsigned)z + 0x20000u);
    v.x = ((unsigned)((x >> 12) / 16) << 16) + 0x8000;
    v.z = ((unsigned)((z >> 12) / 16) << 16) + 0x8000;
    v.y = y;
    func_021A3044(q, &v);
}

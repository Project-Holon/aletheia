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
 * final push 2026-10-05 G6L9: 25 of 88 bytes differ (was 27). New lever:
 * #pragma opt_propagation off with a named bias local k = 0x20000 set after
 * the three loads and z = z + k keeps 2<<16 shared with >>2 with plain signed
 * types and no (unsigned) casts. K now lands in r2 as in the image. Left:
 * x raw in r5 (image r3), y in r3 (image r5), x>>12 in r5 (image r4), movs r2
 * after the first load (image first). k set before the loads gives 28; load
 * order in source, local declaration order, x/z/y read inline, a SetCell inline
 * helper (43), gx/gz locals (42), struct copy (72), int-returning callee
 * with cast, non-const pos, u32 y, z store before x store, and pragmas
 * opt_lifetimes/common_subs/dead_assignments/peephole off on top: all 25 to 43.
 * Residue is the colour pair x/y (x born first gets the higher register here,
 * the image has y higher). 40 compiles used.
 *
 * pass 2 2026-10-06 P2L36: 20 of 88 bytes differ (was 25). Stores in field
 * order v.x, v.y, v.z (y stored before z) under the same pragma give the
 * image's head: movs k first, then ldr x, ldr z, ldr y. Left: x and y swap
 * roles (image keeps y to the end in r5 and stores x at +0x38; here x's
 * result is kept in r4 and stored last, y in r3 stored at +0x38), and lsls k
 * sits right after the loads (image +0x2C). Tried (bytes off): store orders
 * x,z,y 25 / z,x,y 36 / y,x,z 44 / z,y,x 37 / y,z,x 46; VEC_Set inline with
 * body x,y,z 20, body x,z,y 25; VEC_Set with fields read in the arguments 40
 * (args evaluate right to left; no pragma gives the same 88 B, base 0x20000);
 * no-pragma locals with the bias at the use 86 B but the image's head and
 * colours for x; x read inline 25; y read inline 48; sx/sz locals 46/47;
 * x = pos->x >> 12 at the load 29; literal bias without k 29; k before the
 * loads 30; z = pos->z + k 35; loads y,z,x 21; local declaration order 20;
 * non-const pos 20; pragma scheduling off: no change; a tall dummy function
 * earlier in the TU: no change. 40 compiles.
 *
 * pass 3 2026-10-06 P3L16: no better form, best stays 20 of 88. Under the
 * pragma the first computed chain (textually) gets its load hoisted; other
 * loads keep source order. Named-local copies coalesce and add no height.
 * Near forms (bytes off): loads z,y,x then gx = (x >> 12) / 16, gz =
 * ((z + k) >> 12) / 16, field-order stores: 35, head, tail and r4/r5
 * colours as image, but the z chain interleaves into the x snap and k/x
 * take r3/r2. Same with v.x written before gz: 38, middle as image but
 * loads stay z,y,x. Loads x,z,y with v.x before gz and v.y last: 29
 * (ldr x, movs, asrs x). Without the pragma, gz computed before the first
 * 0x8000 use keeps the 0x20000 base (88 B) but the z chain goes first
 * (41-48). Stores x,z,y with direct snaps: 25. gx in two statements: no
 * change. A vx temp before gz with v.y last: 30, schedule nearly the
 * image's (stand-in temp, not kept). 40 compiles.
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

#pragma opt_propagation off
void func_0216C2A4(Work *w)
{
    VecFx32 v;
    const VecFx32 *pos;
    void *q;
    fx32 x;
    fx32 y;
    fx32 z;
    fx32 k;

    pos = func_021BE480(func_02188D2C(w->field), 0, 0);
    q = func_02188CB4(w->field);
    x = pos->x;
    z = pos->z;
    y = pos->y;
    k = 0x20000;
    z = z + k;
    v.x = (((x >> 12) / 16) << 16) + 0x8000;
    v.y = y;
    v.z = (((z >> 12) / 16) << 16) + 0x8000;
    func_021A3044(q, &v);
}
#pragma opt_propagation reset

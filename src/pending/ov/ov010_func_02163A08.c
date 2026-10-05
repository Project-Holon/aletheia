/*
 * function: func_02163A08
 * address: 0x02163A08
 * packet: pkt_ov010_02163A08
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: 2026-10-05 recoup wave P22 lane 5: still DIFF 6 B of 54 (extent 56 with 2 alignment bytes). Only residue: x and y
 *   params sit in each other's callee-saved registers (original x r6, y r5; build x r5, y r6); size, calls, branches and
 *   store order are identical. Callee types checked: func_0216D91C/D924 are matched as int f(int); caller func_02163AF0
 *   passes (a, c, e, v1), arity fine. Tried (one compile each): all six per-function pragmas (6 B each); int w/h with if
 *   clamp and s16 casts (14 B, then 6 B); s16 locals with if clamp (6 B); x0/y1 copies (propagated, 6 B); x0 store before
 *   x1 (7 B); y1 store first (39 B); w + x operand order (7 B); extra s16 result local reused (6 B).
 *   Idioms checked: two-long-lived-values-in-each-others-registers (no join local or missing arg, 6 B);
 *   a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off (6 B); a-result-computed-in-a-dying-local-takes-that-locals-register
 *   (no dying local, n/a); a-field-read-into-its-own-local-before-a-getter-subtraction-sets-the-colour-order (6 B);
 *   array-bases-as-pointer-locals-reopen-a-flat-declaration-order (n/a). No twin: only 02163D04 and ov021 021C0D08 call both getters.
 *   Round 4: mixed param types int x/s16 y and s16 x/int y (matching caller 02163AF0 passing s16 e as y) (6 each). Listing scan for small functions with the same copies and two calls plus strh stores: none.
 *   pass 2 2026-10-06 P2L11: still 6 B. 40 compiles, 3 rounds. Diagnostics: the swap is positional (signature with y before x
 *   gives r1 param r5 again); y lifetime shorter or x lifetime longer does not move it; y passed as an extra getter
 *   argument flips the colours (one more use and phys neighbour for y) but adds a copy. Tried (bytes off): block per axis 6;
 *   one shared local 6; getter returns s16/u16/u8 6; s16 params with s16 copies 6; int copies with init 6; pragmas
 *   opt_dead_assignments, opt_strength_reduction, opt_dead_code off 6, optimization_level 3/2 6, 1 9; inline SetY, SetX,
 *   both 6; opt_propagation off alone, with an int y copy, with inline SetY, plus opt_lifetimes off 6; struct-by-value x/y 44;
 *   --w clamp 44; register y 6; unprototyped getters 6; K&R int params 6; K&R s16 params 49; inline SetY with s16 y 18.
 *   Idioms checked: as above plus mwcc_ref Coloring.c (jam break by spill_cost/degree) and ALLOCATOR_CASEBOOK web numbering.
 * symbols:
 *   func_0216D91C 0x0216D91C thumb ov010
 *   func_0216D924 0x0216D924 thumb ov010
 */
typedef short s16;
extern int func_0216D91C(int p);
extern int func_0216D924(int p);
typedef struct { s16 x0, y0, x1, y1; } Rect;
void func_02163A08(int p, int x, int y, Rect *out)
{
    s16 w;
    s16 h;
    w = func_0216D91C(p) - 1;
    if (w < 0) w = 0;
    out->x1 = x + w;
    out->x0 = x;
    h = func_0216D924(p) - 1;
    if (h < 0) h = 0;
    out->y0 = y - h;
    out->y1 = y;
}

/*
 * function: func_021DF22C
 * address: 0x021DF22C
 * packet: pkt_ov137_021DF22C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * checks: 1 own matched 021E19C0 and 021E15DC definitions reread, each two arguments; 2 DEE4C table twin reread; 3 const Obj parameter worsens29 in wave78; 4 int-row/unsigned-long-column and distinct-arithmetic-types idioms read, mixed arithmetic39/int step26/local order26; 5 fresh idiom directory and E0570/DEE4C reread, no ov138 sources; declared stack struct matches sp-relative read. No further sweep: retry exhausted.
 * retry: wave78 FINAL 3 iteration + 1 check, three nonshrinks; wave77 three iteration + check3 + check4, stopped at three nonshrinks. Recorded C remains the best26 spelling.
 * permuter: earlier 300 types search consumed, unchanged26; not repeated.
 * residual: 26 concrete bytes at 116/116, r4/r5/r6 rotation and table-index load scheduling.
 * symbols:
 *   d_021E1FDC 0x021E1FDC data a2
 *   func_021E19C0 0x021E19C0 thumb ov137
 *   func_021E15DC 0x021E15DC thumb ov137
 * note 2026-10-05 (wave P17 L7): plain int locals and literals compile to the same 26 B as the Step/long draft, so the enum and long were not needed. Tried (about 22 compiles): 2D table d[count][index] (103 B off), d[count*5+index] (34), row pointer local (26), index read into a local first (26), byte-offset form with and without unsigned casts (26 / 39 for swapped order), static inline Degrees(obj) (26), step assigned first or after target (26 / 101), selected pointer local with address-taken angle (103), pragmas opt_lifetimes, opt_common_subs, scheduling, peephole off (26 each), opt_propagation and opt_dead_assignments off (101 / 104). Residue is unchanged: original colours obj r6, target r4, step r5 (ours obj r5, step r4, target r6) and loads index (0x2c) into r3 before the movs/muls (ours loads it after). Callees func_021E19C0 and func_021E15DC are void with two parameters in matched definitions; no arity problem.
 * note final push 2026-10-05 G6L7: 38 more compiles, still 26 B off (116 B). Residue is pure colouring (orig obj r6, step r5, target r4; ours obj r5, step r4, target r6) plus index load order. Tried: declaration orders of sel/count/index/current/step/target (26; target declared before step adds a copy of count, 101), const u16 [][5] table as in matched 021DEDAC, ternary step forms, done/goal/cap locals, a pointer copy, u8 *p struct-view form, inline Degrees(count,index), opt_propagation off with and without named locals (26 / 100), opt_lifetimes off, a goal local (36). The count*10/index*2 shape is already right; no source form found that raises target cost above step or lowers obj cost.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u8 pad[28]; int angle;} Selected;
typedef struct { int state; u8 pad[36]; Selected *selected; int index, count; } Obj;
extern u16 d_021E1FDC[];
extern void func_021E19C0(Obj *, int);
extern void func_021E15DC(int *, int);
int func_021DF22C(Obj *obj)
{
    int current = obj->selected->angle;
    int degrees = *(u16 *)((unsigned)d_021E1FDC + (unsigned)obj->count * 10 + (unsigned)obj->index * 2);
    int step = 0x4000;
    int target = degrees << 12;
    int angle = current;
    int delta = target - current;
    if (delta < 0) delta = target + 0x168000 - current;
    if (delta <= 0x10000) step >>= 1;
    if (delta < step) step = delta;
    func_021E19C0(obj, step);
    func_021E15DC(&angle, step);
    if (angle / 4096 == target / 4096) obj->state = 31;
    return 0;
}

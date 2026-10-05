/*
 * function: func_021E56F4
 * address: 0x021E56F4
 * packet: pkt_ov178_021E56F4
 * region: ov178
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 *  * note 2026-10-05 (wave P12 A7): DIFF 12/236 B, one residue: src and the record pointer
 * swap callee-saved registers (original src r6, record r5; build src r5, record r6).
 * Twin: ov134 021DCB48 (same typed Args/Output shape, matched; there src r5, record r6 is correct).
 * Tried, all 12 B: twin struct shape, int* params, typed record struct, const params (28 B),
 * b-before-a (18 B), save in local, declaration orders of a/b/i, block-local i, and each of
 * opt_lifetimes/opt_common_subs/opt_dead_assignments/scheduling/peephole off (12 B),
 * opt_propagation off (113 B). Callee returns: 02012EBC void*, 0200873C pointer, 02034AC4 int.
 * Difference to the twin: here the second parameter stays live across the first call.
 * final push 2026-10-05 G4L3: still DIFF 12/236 B (same swap), 40 compiles, 3 rounds. New tries, all 12 B:
 * initializer decl for a, raw offsets for p, restrict out, party/mode/save locals, a via
 * inline getter or AView struct view, p copy local (arg, block-scope, q), whole body or tail in a
 * static inline, o as Args or const, u8* p with struct casts, a as u32 or const u8*, callee decls
 * u32 (02012EBC/0200873C), do-while marks loop, default: break, -lang c, opt_strength_reduction,
 * opt_loop_invariants, opt_unroll_loops off. Dead ends: no local a (78 B), b-before-a (18 B), int i (111 B).
 * Finding: moving the three p reads (f10,f8,fC) before the switch (p dies earlier) gives the original
 * colours (p r6, a r5) but changes the code (125 B), so the swap is p's live range / degree against
 * the colouring threshold, not source order of p and a. mwcc Coloring.c (inspiredrobot/mwcc): nodes of
 * degree >= K are chosen by spill_cost/degree and p wins the lower register here. The original p
 * has the same live range in the listing, so the lever must change cost or degree without code.
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200873C 0x0200873C thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_021B6100 0x021B6100 thumb ov090
 *   ov90_id 0x0000005A data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 *a; void *party; u32 f8; u8 fC, padD[3]; u32 f10; void *save; u8 tail[20]; } Args;
typedef struct { u8 pad[4]; void *party; } Other;
typedef struct {
    void *party;
    u32 f4, f8, fC, f10;
    u8 *a;
    u8 pad18[24];
    u16 f30, pad32;
    u32 f34, f38, f3C, f40;
    u16 f44, f46;
    u8 f48, marks[6], pad4F;
    u32 f50;
    u16 f54, pad56;
    u32 f58, pad5C;
    u16 f60, pad62;
    u32 f64;
    u8 pad68[12];
    u32 f74, f78;
    u8 f7C, pad7D[15];
    u32 f8C, f90;
} Output;
struct Big;
extern void *func_02012EBC(struct Big *p);
struct Sub02008700Obj;
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_02034AC4(int);
extern void func_021B6100(u8 *);
extern const char ov90_id[];
void func_021E56F4(Args *p, Other *o, Output *out)
{
    u8 *a;
    void *b;
    u8 i;
    a = p->a;
    b = func_02012EBC(p->save);
    out->party = o->party;
    out->f4 = 0;
    out->f8 = 0;
    out->fC = (u32)func_0200873C(b);
    out->f34 = 26;
    out->f10 = 0;
    out->a = a;
    out->f30 = 0;
    switch (a[0xba]) {
    case 0: out->f38 = 0; out->f64 = 1; break;
    case 1: out->f38 = 1; out->f64 = 1; break;
    case 2: out->f38 = 1; out->f64 = 1; break;
    case 3: out->f38 = 1; out->f64 = 1; break;
    case 4: out->f38 = 2; out->f64 = 2; break;
    }
    out->f44 = 0;
    out->f46 = 0;
    out->f48 = 0;
    out->f3C = 0;
    out->f40 = 0;
    for (i = 0; i < 6; i++) out->marks[i] = 0;
    out->f50 = 0;
    out->f58 = 0;
    out->f54 = 0;
    out->f74 = p->f10;
    out->f78 = p->f8;
    out->f7C = p->fC;
    out->f8C = a[184];
    if (a[185] != 0) {
        out->f90 = 1;
        out->f60 = a[185];
    } else {
        out->f90 = 0;
        out->f60 = 0;
    }
    func_02034AC4((int)ov90_id);
    func_021B6100((u8 *)out);
}

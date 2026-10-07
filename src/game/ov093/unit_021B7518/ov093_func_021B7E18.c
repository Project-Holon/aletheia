/*
 * function: func_021B7E18
 * address: 0x021B7E18
 * packet: pkt_ov093_021B7E18
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAACC 0x021BAACC thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B6994 0x021B6994 thumb ov093
 *   func_021BAB10 0x021BAB10 thumb ov093
 *   func_021CD960 0x021CD960 thumb ov093
 *   func_021B9010 0x021B9010 thumb ov093
 * note 2026-10-05 (wave P3 R5): twin shape of ov093 021B8070 / 021B7CB4 (same callees). The
 *   0x46e flag is a local `k = 0x46e` (p[0x46e], p[k-3], p[k-6], p+(k-0x7e)), spilled to [sp,#0x38]
 *   like the original. f9010 result is a u8 (no truncation before f_BAACC). 69 bytes differ,
 *   all pure instruction ORDER inside the argument setup of the first f9C8 / f6F0 calls and the
 *   else-branch f6F0 call (str [sp] vs lsls r2; adds r1,r4,#0 early vs late). Same 600 bytes of
 *   content. Tried without effect: const u8 *q, const callee prototype params, u32 k,
 *   scheduling off, peephole off (identical 69 B), opt_lifetimes off (123 B), opt_propagation off (574 B).
 *   2026-10-05 (wave P3 R5b): the k = 0x46e local is not needed: plain literals (p[0x46e], p + 0x3f0,
 *   *(u16 *)(p + 0x468), p[0x46b]) give the same 69 bytes, so the file now uses literals. The compiler
 *   itself spills the 0x46e pool word to [sp,#0x38] (no free callee-saved register: p r4, q r6, mode r7,
 *   zero r5, idx spilled). Twin 021B8070 has idx in r4 and a base r6 = 0x46c, so its schedule differs
 *   and cannot be read across. New tries, all worse or equal: u16 local h assigned per site before each
 *   call (143 B); static inline u16 accessor for the heap read (69 B, no change); u32 idx (477 B), u32 mode
 *   (562 B), u32 x (268 B); static inline wrappers for func_021BA9C8 (69 B) and func_021CD6F0 (452 B);
 *   opt_common_subs off (460 B), opt_dead_assignments off (99 B). Residue unchanged: stack-store vs
 *   register-argument order in the first func_021BA9C8 call and the two func_021CD6F0 calls (+0x5C, +0x86..+0xA0,
 *   +0x1C0..+0x1D8). Needs a different IR order for the arguments; no human form found.
 *   final push 2026-10-05 G7L10: still 69 B (same residue, argument-setup order of f9C8 #1/#else and f6F0 idx calls; the
 *   idx==2 arm calls already match). 38 compiles, no change or worse: local struct views for p (f8, fC, f468, f10[]) and q
 *   (f1C/f20/f22) (69/477); named slots pointer (254); idx u16 (410), mode u16 (561); f6F0 prototype widths (idx u8, mode int,
 *   idx int, flag/9th int, arg3 u8) and const params (69 each); f9C8 heap int, const b/c (69); f6818(u8 *) (69); BAACC with an
 *   int 4th parameter as in its definition (202); result into a local before the slot store (452/463); zero locals (69);
 *   0x1b0 as a 27-record index (69); volatile t probe (101); u32 t, u32 f6818 result (69); decl orders (69); swapped arms (479);
 *   p[0x10] as add-order variants (69/477); mode via if/else (544); x int (268); early i = 0 (95); all-const q and callees (69).
 *   scheduling off leaves the 69 B unchanged and opt_lifetimes off keeps the same order residue (plus r4/r5 swap), so the order
 *   comes from IR emission, not the scheduler. Twins 021B8070/021B7CB4/021B81DC differ (idx in a register, no spilled k), and no
 *   other ov093 function contains subs #0x7e, so no asm twin exists. No human form found.
 *   pass 2 2026-10-06 P2L49: EXACT. t is a u8 local and func_021B6818 is declared returning u8 (it returns
 *   only 0 or 1, so the callee code is the same). mwcc keeps the reload of a spilled narrow local below the
 *   outgoing stack stores (docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md); with
 *   int t it hoisted the reload and the argument setup order differed (69 B).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;
extern u8 func_021B6818(int *);
extern int func_021D4270(void);
struct Copy24;
struct QB;
extern u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
struct S;
extern u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
extern u32 func_021CD978(struct QB *p);
extern void func_021BAA94(char *p, int b, u8 c, u8 d);
extern void func_021BAACC(char *p, int a, int b, int c, u8 d);
extern int func_021B8B9C(u8 *, u8);
extern int func_021B6994(struct S **pp, u32 b);
extern void func_021BAB10(int, u8, int);
extern void func_021CD960(u8 *p, u32 v);
extern u8 func_021B9010(u8 *, u8);
int func_021B7E18(u8 *p)
{
    u8 *q;
    u8 idx;
    u8 mode;
    u8 t;
    u32 i;
    u8 x;
    q = *(u8 **)p;
    idx = p[0x46c];
    t = func_021B6818((int *)q);
    mode = (q[0x22] == 0) ? 2 : 1;
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    if (p[0x46e]) {
        *(int *)(p + 8) = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, *(u16 *)(p + 0x468));
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), idx, (u8)mode, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), *(u16 *)(p + 0x468));
        func_021BAA94((char *)(*(int *)(p + 8)), func_021CD978((struct QB *)(((int *)(p + 0x10))[idx])), idx, mode);
        if (q[0x22] == 2) {
            x = func_021B9010(p, idx);
            *(int *)(p + 0x14) = (int)func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), 1, (u8)mode, 1, t, (u8)0, (struct Copy24 *)(p + 0x3f0), *(u16 *)(p + 0x468));
            func_021BAA94((char *)(*(int *)(p + 8)), func_021CD978((struct QB *)(*(int *)(p + 0x14))), 1, mode);
            *(int *)(p + 0x1c) = (int)func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), 3, (u8)mode, 1, t, (u8)0, (struct Copy24 *)(p + 0x3f0), *(u16 *)(p + 0x468));
            func_021BAA94((char *)(*(int *)(p + 8)), func_021CD978((struct QB *)(*(int *)(p + 0x1c))), 3, mode);
            func_021BAACC((char *)(*(int *)(p + 8)), q[0x20], *(int *)(q + 0x1c), (u8)x, mode);
        } else {
            for (i = 0; i < p[0x46b]; i++) {
                if (i != idx)
                    func_021BAACC((char *)(*(int *)(p + 8)), q[0x20], *(int *)(q + 0x1c), (u8)i, mode);
            }
        }
    } else {
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), idx, (u8)mode, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), *(u16 *)(p + 0x468));
        *(int *)(p + 0xc) = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, *(u16 *)(p + 0x468));
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i))
                func_021BAB10(*(int *)(p + 0xc), i, func_021B6994((struct S **)p, (u8)i));
        }
        func_021CD960((u8 *)(((int *)(p + 0x10))[idx]), (int)(*(int *)(p + 0xc)));
    }
    return 1;
}

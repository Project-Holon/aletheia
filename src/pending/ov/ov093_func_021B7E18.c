/*
 * function: func_021B7E18
 * address: 0x021B7E18
 * packet: pkt_ov093_021B7E18
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
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
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;
extern int func_021B6818(int *);
extern int func_021D4270(void);
struct Copy24;
struct QB;
extern u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
extern int func_021CD6F0(void *, void *, int, int, u16, u8, u8, int, u8, void *, u16);
extern u32 func_021CD978(struct QB *p);
extern void func_021BAA94(char *p, int b, int c, u8 d);
extern void func_021BAACC(int, int, int, u8, u8);
extern int func_021B8B9C(u8 *, u8);
extern int func_021B6994(u8 *, u8);
extern void func_021BAB10(int, u8, int);
extern void func_021CD960(int, int);
extern u8 func_021B9010(u8 *, u8);
int func_021B7E18(u8 *p)
{
    u8 *q;
    u8 idx;
    u8 mode;
    int t;
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
        ((int *)(p + 0x10))[idx] = func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), idx, mode, 0, t, 0, p + 0x3f0, *(u16 *)(p + 0x468));
        func_021BAA94((char *)(*(int *)(p + 8)), func_021CD978((struct QB *)(((int *)(p + 0x10))[idx])), idx, mode);
        if (q[0x22] == 2) {
            x = func_021B9010(p, idx);
            *(int *)(p + 0x14) = func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), 1, mode, 1, t, 0, p + 0x3f0, *(u16 *)(p + 0x468));
            func_021BAA94((char *)(*(int *)(p + 8)), func_021CD978((struct QB *)(*(int *)(p + 0x14))), 1, mode);
            *(int *)(p + 0x1c) = func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), 3, mode, 1, t, 0, p + 0x3f0, *(u16 *)(p + 0x468));
            func_021BAA94((char *)(*(int *)(p + 8)), func_021CD978((struct QB *)(*(int *)(p + 0x1c))), 3, mode);
            func_021BAACC(*(int *)(p + 8), q[0x20], *(int *)(q + 0x1c), x, mode);
        } else {
            for (i = 0; i < p[0x46b]; i++) {
                if (i != idx)
                    func_021BAACC(*(int *)(p + 8), q[0x20], *(int *)(q + 0x1c), i, mode);
            }
        }
    } else {
        ((int *)(p + 0x10))[idx] = func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), idx, mode, 0, t, 0, p + 0x3f0, *(u16 *)(p + 0x468));
        *(int *)(p + 0xc) = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, *(u16 *)(p + 0x468));
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i))
                func_021BAB10(*(int *)(p + 0xc), i, func_021B6994(p, i));
        }
        func_021CD960(((int *)(p + 0x10))[idx], *(int *)(p + 0xc));
    }
    return 1;
}

/*
 * function: func_021B0508
 * address: 0x021B0508
 * packet: pkt_ov013_021B0508
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * Initialize TCV session state, six counters and three request slots.
 * residual: DIFF 248/248 bytes, 45 concrete bytes differ; all 13 relocations resolved.
 * evidence: pairValue inline preserved 45; delayed f24 through reused k gave 46, enum zero/counter initialization gave 86; enum mode and long counter stayed 45. Callee 021B19BC corrected to char*, int, int from its matched source.
 * permuter: first typed budget-300 pass emitted baseline/best 45; no improvement. Search consumed.
 * prior evidence: ternary loop condition and Pair pointer fix loop rotation/pool count. Mode if/else gave 59, early i=0 gave 58 or tied; temporary value and stored ternary mode did not help. Remaining f1C/table/zero/0x440 scheduling is one basic block.
 * checks: 1 own 021B3250/021B16E4/021B19BC/021B12FC/021B3364 definitions rederive arities 0/1/3/0/0; 02087170 reads hardware halfword with no inputs; 2 same-overlay session neighbours reread, no exact twin; 3 const mode-context pointer, enum size and u16 mode all unchanged 248/45; 4 inline-argument/enum-zero/store-order idioms read; 5 unfiltered idiom directory and ov013 neighbours refreshed, scalar frame has no addressed stack aggregate. Next unrun hypothesis: typed inline wrapper around the f24 field store.
 * Final wave76 retry: explicit Ctx3C84 pointer store sequence worsens to
 * 244/172; typed spellings tie 248/45. Best global-field C retained.
 * All 13 relocations resolve; consumed once-300 search not repeated.
 * recoup 2026-10-05 (lane Z2, wave P11): best stays 248/248 bytes, 45 differ. The only residue
 * is scheduling of one block: the original stores f1C through the FIRST base load (r2), then reads the
 * table, then reloads 3C84 into r1 just before the f24/fC stores; ours stores f1C through the second
 * load and hoists it above the cmp. Callee types rechecked from matched definitions (all void except
 * func_02087170 u16, arities 0/1/3/0/0). Tried, all 45 or worse: fC store in a static inline setter (45);
 * f1C re-read for pairValue (45); fC computed in a local before f24 (46); fC stored before f24 (46);
 * Ctx pointer local for f0..f1C (71), for f24/fC (45), assigned after the call (50); inline getMode with
 * early returns (45); stores in each arm of k==4 (174, size 256); non-const table (80, reorders the head);
 * each of opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole off (45).
 * Twin 021B0614 (matched, opt_lifetimes off) gives struct types only. Idioms read: global-struct-member-is-reread,
 * duplicated-pool-word (here one pool word, loaded twice, so one extern), base-address-in-a-u32-local,
 * load-scheduled-above-an-unrelated-store (const), local-declared-at-first-use, field-reload-after-sibling-store.
 * symbols:
 *   d_021B3C84     0x021B3C84  data  ov013  a4
 *   d_021B3C24     0x021B3C24  data  ov013  a4
 *   d_021B60D8     0x021B60D8  data  ov013  a4
 *   d_021B3AD0     0x021B3AD0  data  ov013  a1
 *   d_021B42C0     0x021B42C0  data  ov013  a4
 *   d_021B3CB0     0x021B3CB0  data  ov013  a4
 *   d_021B3CBC     0x021B3CBC  data  ov013  a4
 *   func_02087170  0x02087170  arm
 *   func_021B3250  0x021B3250  arm  ov013
 *   func_021B16E4  0x021B16E4  arm  ov013
 *   func_021B19BC  0x021B19BC  arm  ov013
 *   func_021B12FC  0x021B12FC  arm  ov013
 *   func_021B3364  0x021B3364  arm  ov013
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    u8 pad8[4];
    u32 fC;
    u8 pad10[0xC];
    u32 f1C;
    int f20;
    u32 f24;
} Ctx3C84;

typedef struct {
    u8 pad0[0x8c0];
    int f8C0;
    u32 f8C4;
    u32 f8C8;
    u32 f8CC;
    int f8D0;
    int f8D4;
} Ctx42C0;

typedef struct {
    u8 pad0[0x10];
    int f10;
} Ctx60D8;

typedef struct {
    u8 raw[0x94];
} Slot;

extern Ctx3C84 d_021B3C84;
extern int d_021B3C24;
extern Ctx60D8 d_021B60D8;
typedef struct {
    u8 a;
    u8 b;
} Pair;

extern const Pair d_021B3AD0[];
extern Ctx42C0 d_021B42C0;
extern void *d_021B3CB0[3];
extern Slot d_021B3CBC[3];

extern u16 func_02087170(void);
extern void func_021B3250(void);
extern void func_021B16E4(u32 i);
extern void func_021B19BC(char *p, int i, int a2);
extern void func_021B12FC(void);
extern void func_021B3364(void);

static inline u32 pairValue(u32 k)
{
    const Pair *p;
    p = &d_021B3AD0[k];
    return p->a * 0x44 + p->b + 0xC;
}
int func_021B0508(void)
{
    u32 i;
    u32 k;
    const Pair *pair;

    d_021B3C84.f0 = func_02087170();
    d_021B3C24 = 1;
    d_021B3C84.f20 = 0;
    d_021B3C84.f4 = 0;
    k = 0;
    if (d_021B60D8.f10 != 1) {
        k = 4;
    }
    d_021B3C84.f1C = k;
    d_021B3C84.f24 = 0x440;
    d_021B3C84.fC = pairValue(k);
    d_021B42C0.f8C0 = 0;
    d_021B42C0.f8C4 = 0;
    d_021B42C0.f8CC = 0;
    d_021B42C0.f8C8 = 0;
    d_021B42C0.f8D0 = 0;
    d_021B42C0.f8D4 = 0;
    func_021B3250();
    for (i = 0; (i < 3) ? 1 : 0; i++) {
        d_021B3CB0[i] = 0;
        func_021B16E4(i);
        func_021B19BC((char *)&d_021B3CBC[i], i, -1);
    }
    func_021B12FC();
    func_021B3364();
    return 1;
}

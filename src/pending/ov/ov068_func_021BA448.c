/*
 * function: func_021BA448
 * address:  0x021BA448
 * packet:   pkt_ov068_021BA448
 * hint:     both of lane B9's levers measured by lane R1 (unprototyped/int callee, inline returning the id): the case-8 residue is the pair-or-merge trade in the retry paragraph; look for a spelling that makes the two calls differ in the IR (a call whose result is used on one path) rather than a type
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * final retry: Wave76 R17, four fixed-flag one compiles, no sweeps/permuter.
 *   Stored-fC-dependent else sound gives 508/233; comma-expression flag
 *   arm retains 508/5; enum command 508/5; signed-short sound formal 508/5.
 *   Checks 1 own BA194/BA9DC/ov067 getters and current BA7C0/BA03C callers
 *   re-derive three/one/two arities, sound is one void-returning call;
 *   2 BA7C0 lacks two-path sound; 3 command enum/short sound measured,
 *   mutable object not const; 4 cross-jump idioms refreshed; 5 idioms refreshed.
 *   Retain baseline 508/5, 27/28 relocs, exhausted this authorized retry.
 *   Need evidence-backed IR asymmetry of the two sound paths; invented sound
 *   aliases and old permuter searches remain prohibited/consumed.
 * checks:   1 arity from matched files (func_021BA9DC (p) and func_021BA194 (p, int, int *) from their ov068 matched files; ov067 021B63D0/6470/6448 (int) and 021B65A8 (int,int) from their callers; 020355C4/020355D8 from ov068_func_021BA03C, EXACT this lane); 2 no twin (no other ov068 handler with this case-8 sound pick); 3 sound id u16 (best, 5 bytes), int (4 bytes short, 245-byte shifted diff), flag/f10 store order in case 8, snd local, (u16) cast of the ternary: no gain; 4 cross-jump idioms read (a-labelled-function-and-the-unlabelled-store-and-return-address-leaf..., an-argument-bound-through-an-inline-wrapper...): a static inline sound helper tried, no gain; 5 re-listed docs/idioms (ls -t), nothing new fits; retry R1: 1 every other matched caller (ov064/065/067/068/069) declares func_020061E4 with one 32-bit parameter, so u16 here is only a lever; 2 ov068_func_021BA7C0 shares 021BA194/020355C4/D8/020061E4 but has no two-path sound call; 3 sound id int/unprototyped/u16 local/inline u16 return measured (above); 4 cross-jump idioms (a-shared-bl-b-tail..., a-call-before-a-goto..., a-flag-dispatch-four-bytes-short...) read: the if/else arm order they suggest does not unmerge it; 5 ls -t docs/idioms again, nothing new
 * runs:     12 + 2x permuter (permuter on this draft and on the int-param draft, seed 7: no candidate beat either)
 *   wave75 R28: 5 one calls (3 iteration, 2 check-3), no sweeps/permuter.
 *   Renewed checks: 1 own files/callers re-derived all arities, including
 *   BA190 one, BA9DC one, BA194 three, BB508 two, sound one; 2 no twin
 *   retains two case-8 sound calls; 3 enum sound formal/local and one-site
 *   int call cast give 504 bytes / 245-byte shifted DIFF; enum fC and flag
 *   each retain 508 bytes / 5-byte DIFF; 4 cross-jump idioms still fit but
 *   their existing levers were consumed; 5 idiom directory refreshed.
 *   Best stays this draft. Both prior permuter searches remain consumed.
 * residue:  508 vs 492 bytes of code (the extent's 492 plus the 16-byte pool at
 *   0x021BA634, which the listing labels as a phantom func_021BA634), 5 bytes differ, all in
 *   case 8. The image keeps two separate calls:
 *     cmp r0,#1; bne; ldr r0,=0x551; b; ldr r0,=0x54c; bl func_020061E4; b A55E
 *     A554: movs r0,#0; str r0,[r4,#0xc]; ldr r0,=0x54c; bl func_020061E4
 *     A55E: movs r5,#1; b A56C
 *   This C cross-jumps the two bls: after the ternary it emits lsls/lsrs #16 and branches
 *   into the else-arm's bl. Every other byte (the switch table, case 3's rectangles, the
 *   f34[fC] / f34[fC^1] block, the nested r != 0 / r == 6 tests) matches.
 *   Tried for case 8: nested ifs calling in each arm (worse), switch (p->fC) with default /
 *   case 1 (worse), break inside the arm, (u16) cast on the ternary, a static inline helper,
 *   a snd local then one call. Structure fixes that did shrink it: switch (v) for cases
 *   4..11, the nested r != 0 { r == 6 } else layout for 6470/6448, the ternary sound id.
 *   Data: d_021BB550 prints "ov068 hint contested" (another overlay starts an object
 *   there); recheck its evidence once the function matches.
 *   Next: source-level asymmetry between the two call paths supported by
 *   image evidence, without invented aliases; integer and enum parameter
 *   webs alone cannot preserve separate calls without the truncation pair.
 *   Retry (lane R1, 9 runs): the image's case 8 has no truncation pair AND no cross-jump;
 *   every spelling gives one or the other. Pair, not merged (this draft's 5 bytes): u16
 *   param with the ternary, a u16 snd = ternary, a static inline u16 SndId(p) returning
 *   the ternary. No pair but the bl cross-jumped (504 bytes, 4 short): int or unprototyped
 *   `func_020061E4()`, a u16 snd set in if/else, the == 3 arm first, an early break out of
 *   the != 3 arm, nested if/else with a call per arm (then the 0x551 call jumps into case
 *   9's). u8 is impossible (0x551). a-flag-dispatch-four-bytes-short-is-the-front-end-
 *   tail-merging-the-arms.md describes this 1.1p1 merge (2.0/sp2 keeps both arms), but the
 *   flags are pinned, so it stays a DIFF.
 *   EXACT* found but NOT filed (needs the orchestrator's ruling): declare the callee
 *   `extern void func_020061E4(int id);` plus a second name for the same address,
 *   `extern void func_020061E4_2(int id);` with the symbols line
 *   `func_020061E4_2  0x020061E4  thumb`, call the second name only in case 8's
 *   ternary arm, and drop the ov068 token from d_021BB550 (`data  a4`, then it resolves
 *   as sole-ref).  match.py one: EXACT* (492 of the 508 compiled bytes; the tail is the
 *   16-byte pool the listing labels func_021BA634), every relocation resolved, the two
 *   case-8 calls label-attested at 0x020061E4.  Two symbols stop the 1.1p1 cross-jump;
 *   it is the function analogue of
 *   a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md, but it
 *   invents a second name for one arm9 function, which no rule here sanctions.
 *
 * recoup 2026-10-05 (lane X5): 1 callee types re-read from matched definitions: 021BA190 int(const int*), 021BA9DC int, 021BA194 void(p,int,int*), 021B65A8 unsigned(u8*,unsigned), 020355C4 u8, 020355D8 void(u8), 02028218/0202822C void, 02012BE0 void; func_020061E4 is a veneer into arm9 020061A4 whose return is not used, so void stays; no void-return problem found. Calls and arities unchanged. 2 sound id as u32 (the width in matched callers): 504 bytes, 245 differ (cross-jumped bl). 3 declaration order: spill slots follow the draft already. 4 case 8 with flag and the stores written in each arm, fC==3 arm first: 508 bytes, 28 differ. 7 all six pragmas (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole, each off): all stay 508 / 5 differ. Residue unchanged: 5 bytes in case 8, the original keeps two un-merged bl func_020061E4 calls with no truncation pair. Only the second-name trick (EXACT*, see above) closes it. Idioms: a-flag-dispatch-four-bytes-short-is-the-front-end-tail-merging-the-arms.md (the 1.1p1 merge, no source lever).
 * recoup 2026-10-05 P29R7: case 8 respelled three ways, no lever beyond the second-name trick: if/else-if/else with 0x551 and 0x54c calls (504 bytes, 247 differ), fC==3 fixup then one ternary call through a local (508, 243 differ), flag and f10 stores before the arms (512, 259 differ). Baseline stays 508 / 5 differ. Callee types and pragmas not repeated (see X5 note).
 *
 * symbols:
 *   func_021BA190  0x021BA190  thumb  ov068
 *   func_021BA9DC  0x021BA9DC  thumb  ov068
 *   func_021BA194  0x021BA194  thumb  ov068
 *   func_021BB508  0x021BB508  thumb  ov068
 *   func_02040588  0x02040588  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020355C4  0x020355C4  arm
 *   func_020355D8  0x020355D8  arm
 *   func_02028218  0x02028218  thumb
 *   func_0202822C  0x0202822C  thumb
 *   func_021B63D0  0x021B63D0  thumb  ov067
 *   func_021B6470  0x021B6470  thumb  ov067
 *   func_021B6448  0x021B6448  thumb  ov067
 *   func_021B65A8  0x021B65A8  thumb  ov067
 *   func_02012BE0  0x02012BE0  thumb
 *   d_021BB550     0x021BB550  data  ov068  a4
 *   d_021BB560     0x021BB560  data  ov068  a4
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[8];
    int f8;
    int fC;
    int f10;
    u8 pad14[0x20];
    int f34[2];
    int f3C;
    int f40;
} W;

extern int d_021BB550[];
extern int d_021BB560[];

extern int  func_021BA190(void *p);
extern int  func_021BA9DC(void *p);
extern void func_021BA194(void *p, int which, int *out);
extern int  func_021BB508(int *rect, void *b);
extern void func_02040588(int a, int b);
extern void func_020061E4(unsigned short id);
extern int  func_020355C4(void);
extern void func_020355D8(int v);
extern void func_02028218(u32 a, u32 b);
extern void func_0202822C(u32 a, u32 b);
extern void func_021B63D0(int a);
extern int  func_021B6470(int a);
extern int  func_021B6448(int a);
extern int  func_021B65A8(int a, int b);
extern void func_02012BE0(int a, int b, int c);

void func_021BA448(W *p, void *obj, void *arg)
{
    int cmd;
    int flag;
    int v;
    int r;
    int pt[2];

    flag = 0;
    p->f40 = 0;
    if (p->f10 != 0)
        cmd = 0;
    else
        cmd = func_021BA190(obj);
    v = func_021BA9DC(arg);
    switch (cmd) {
    case 0:
    case 1:
    case 2:
    case 12:
    case 13:
        break;
    case 14:
        return;
    case 3:
        func_021BA194(obj, 0, pt);
        if (func_021BB508(d_021BB550, pt) && p->fC != 0) {
            func_02040588(4, 0);
            func_020061E4(0x54c);
            p->fC = 0;
            p->f10 = 1;
            p->f40 = 1;
            if (func_020355C4() == 0)
                func_020355D8(1);
        } else if (func_021BB508(d_021BB560, pt) && p->fC != 1) {
            func_02040588(4, 0);
            func_020061E4(0x551);
            p->fC = 1;
            p->f10 = 1;
            p->f40 = 1;
            if (func_020355C4() == 0)
                func_020355D8(1);
        } else if (p->fC != 3) {
            p->fC = 3;
        }
        flag = 1;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
        switch (v) {
        case 5:
            p->fC = 0;
            break;
        case 6:
            p->fC = 1;
            break;
        default:
            p->fC = 3;
            break;
        }
        flag = 1;
        break;
    case 8:
        if (p->fC != 3) {
            func_020061E4(p->fC == 1 ? 0x551 : 0x54c);
        } else {
            p->fC = 0;
            func_020061E4(0x54c);
        }
        flag = 1;
        p->f10 = 1;
        break;
    case 9:
        func_020061E4(0x551);
        flag = 1;
        p->fC = 1;
        p->f10 = 1;
        break;
    }
    if (flag) {
        if (p->fC == 3) {
            func_02028218(p->f34[0], 0);
            func_02028218(p->f34[1], 0);
        } else if (p->f10 != 0) {
            func_02028218(p->f34[p->fC], 0);
            func_0202822C(p->f34[p->fC], 1);
            func_02028218(p->f34[p->fC ^ 1], 0);
        } else {
            func_02028218(p->f34[p->fC], 1);
            func_02028218(p->f34[p->fC ^ 1], 0);
        }
    }
    if (p->f10 == 0) {
        func_021B63D0(p->f8);
        r = func_021B6470(p->f8);
        if (r != 0) {
            if (r == 6 && func_020355C4() == 1)
                p->f40 = 1;
        } else {
            if (func_020355C4() == 1)
                p->f40 = 1;
        }
        r = func_021B6448(p->f8);
        if (r != 0) {
            if (r == 6) {
                if (func_021B65A8(p->f8, 6))
                    func_02012BE0(p->f3C, 0x18, 1);
                else
                    func_02012BE0(p->f3C, 0x18, 0);
                p->fC = 3;
            }
        } else {
            p->fC = 2;
            p->f10 = 1;
        }
    }
}

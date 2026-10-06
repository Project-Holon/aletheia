/*
 * function: func_021BB0C4
 * address: 0x021BB0C4
 * packet: pkt_ov091_021BB0C4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * retry: Wave77 final retry: boolean zero220/2, point-call wrapper220/2, initialized point-return helper228/154; iteration stopped after three nonshrinking changes. Check3 const p220/32; strict own-pointer prototypes check1 restores220/2. Five fixed-flag one runs; original body retained with current strict declarations.
 * residue: none since pass 2 (was: 220 bytes, two concrete bytes at +0046/+0048: zero spill uses r0 instead of r1).
 * witness: ARM9 func_0204B09C current EXACT source src/matched/arm9/func_0204B09C.c and shard pkt_0204B09C read before caller compilation; all11 relocations now resolve.
 * checks: 1 exact own arity/types refreshed: 02045780(void*,u8),0204B09C(void*,int,void*),410D0 ten,413B0 six,45374(void*),41B6C(u32); file-local struct pointer types substituted by void*; 2 BB1A0/D218 and pending BA6A0/BB200 refreshed; 3 const p worsens to220/32, width/truncation evidence retained; 4 inline-bound-argument, enum-zero and declared-stack-object idioms read; 5 fresh plain directory and neighbours refreshed. Prior types300 permuter consumed; final retry exhausted.
 * note 2026-10-05 (wave P12 lane A4): no source existed in src/pending; filed from docs/notes/pkt_ov091_021BB0C4.c.txt (re-read pool and arguments: correct, 2 bytes DIFF). Callees checked: 0204B09C is void(Owner*,idx,Vec16*) per matched arm9 file; 02045780/02045374/02041B6C have no matched source. Twin: ov091_func_021BA6A0 (same d_021BEC6C selector pattern, `int zero = 0` + enum selector). Residue unchanged: zero spill at +0046/+0048 is `movs r0,#0; str r0` instead of `movs r1,#0; str r1`. Tried (all stay 2 B unless noted): zero as u8/u16/unsigned/char/int/enum, zero declared first, point removed (pt.x/pt.y), arg as named idx copy, literal arg; zero moved before the first call (133 B), before point stores (13-20 B), `int zero = 0` at declaration (51 B), selector as int (13 B), y as int (44 B), x as u8 (111 B), six per-function pragmas (lifetimes, scheduling, peephole: 2 B; dead_assignments 6 B; propagation, common_subs: 120+ B). Idioms read: a-narrow-flag-local-is-spilled-not-constant-propagated, a-loop-counter-zero-before-an-offset-assignment-schedules-before-its-spill, a-named-zero-argument-pins-the-callers-truncation, a-second-zero-must-be-spelled-as-a-copy-of-the-first, a-hoisted-loop-invariant-zero-takes-the-freshly-dead-register-from-the-scratch, a-selector-ternary-first-in-a-sum-keeps-the-selector-in-its-scratch-register. The enum zero/selector locals are stand-in suspects; the plain int forms give the same 2 B.
 * note recoup 2026-10-05 P29R1: still DIFF 2 B (220/220 size, +0046/+0048 zero spill r0 vs r1). 20 compiles: callee prototypes from matched twins (02045780 u8, 410D0 (u32,u8,u32,u32,u8,void*,...) as BA6A0, 413B0, 41B6C, 45374 checked, all return void), point local dropped (pt.x/pt.y, short[2], Rect), zero between x and y stores (13 B), zero as scratch for the -(x+d)*8 / -y*8 values, zero as int/u32 with u32 callee idx, callee idx u8 (138 B), callee (int,int,short*), non-const s, struct {int zero; Pt pt;} (132 B, wrong layout), selector/zero as int (13 B), field read via local i (164 B), pt declared first. All 2 B except as noted. Idioms checked: two-long-lived-values-in-each-others-registers, a-callee-declared-void-that-returns-a-value-changes-later-constant-copies (all callees really void), a-named-zero-argument-pins-the-callers-truncation, a-width-stored-in-the-handle-temp-it-replaces-keeps-the-original-colours (scratch form, 2 B). Pragmas not retried (header lists six, 2 B or worse). Current file uses the twin-style 410D0 prototype with the bare d argument.
 * note final push 2026-10-05 G1L3: still DIFF 2 B (220/220, +0046/+0048). 16 compiles, all 2 B unless noted: zero assigned inside the call argument; pt.y stored before pt.x (14 B); inline SetPt helper; zero as plain int; selector declared before zero; pt block-scoped with the call; px/py int locals; x as u32; non-const tables; literal 0 argument; callee (void*,u32,Pt*); zero stored before pt stores (20 B); zero between the two pt stores (allocation flips, r0/r1 swapped, large diff); Pt pt={x,y} initialiser (2 B) and zero before the initialiser (20 B); zero=ZERO. Reading: original has &pt live in r0 when the zero is materialised in r1, ours frees r0 first; likely post-RA scheduling moved the y store above the zero store. Idioms read: a-spilled-zero-init-store-schedules-independently-of-the-guards-loads (calls such a tie not source-reachable), a-dead-store-to-a-spilled-local-survives-when-the-second-assignment-recomputes, a-bool-field-set-from-a-compare-in-if-else-arms-keeps-the-zero-first, a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero, a-flag-zeroed-after-a-nested-argument-call-frees-a-callee-saved-register-for-a-long-lived-local. Twins read: ov091_func_021BA6A0, ov091_func_021BB200.
 * note final push 2026-10-05 G1R3: still DIFF 2 B (220/220, +0046/+0048). 28 compiles, all 2 B unless noted: Pt pointer local q->x/q->y and pp=&pt (also passed to the call); zero assigned inside the call argument; W(0x24) read into a local before zero=0 (alone, with opt_lifetimes off, with scheduling off, and read before the pt stores: 8 B); y as int (44 B); int scratch t for both pt stores; zero as unsigned; callee takes Pt *; zero declared in an inner block with the rest of the function (int zero=0, arg zero or literal 0), also with pt in the block (20 B); zero before pt stores (20 B), between pt stores (flips x temp and pt address registers). Listing search over asm/overlays and asm/arm9 for the sequence (add r0,sp / strh [r0,#2] / movs r1,#0 / str r1,[sp,#N] / ldr r0 / movs r1,#0 / add r2,sp) found only this function; no matched twin. Reading: the original zero temp avoids r0 while the pt address web is still allocated, which needs the zero def inside the x/y store window, yet the stores come out in the order y then zero; no human source form found that gives both.
 * note final push 2026-10-05 G1R3 round 4 (callee-type lead from ov039 021F41A8): grepped every matched caller declaration of the six callees and read arm9 func_0204B09C (Owner*, int, Vec16*). 9 compiles: 0204B09C as (void*,u32,Pt*) 2 B, (int,int,short*) 2 B, (void*,u8,Pt*) 138 B, (void*,u16,Pt*) 138 B, u8 with u8 zero local 2 B; 02045780 (void*,u32) 161 B; 020413B0 and 020410D0 with u8 index 2 B; 020410D0 second arg u32 69 B; 02041B6C(int) and 02045374(int) 2 B. No change to the zero spill register.
 * note pass 2 2026-10-06 P2L02: EXACT in --lang c99 and --lang c. Lever: `zero = 0;` written AFTER the
 *   func_0204B09C call (which takes a literal 0), not before it. mwcc still places the spilled zero store
 *   before the call argument setup, but the temp now takes r1 like the original. Found by a listing search for
 *   `movs r1,#0; str r1,[sp,#N]; <r0 redefined>`: matched ov208 021C3840 has the same shape from `k = 0;`
 *   written after a call with a literal 0 argument. zero is now a plain int (as in twin 021BA6A0); the enum
 *   selector stays (int selector gives 6 B, the twin uses the same enum).
 * symbols:
 *   func_02045780 0x02045780 arm
 *   func_0204B09C 0x0204B09C arm
 *   func_020410D0 0x020410D0 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   d_021BEC74 0x021BEC74 data ov091 a1
 *   d_021BEC75 0x021BEC75 data ov091 a1
 *   d_021BEC6C 0x021BEC6C data ov091 a1
 *   d_021BEC6D 0x021BEC6D data ov091 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x,y; } Pt;
typedef struct { Pt point; short width,height; } Rect;
struct Cfg;
struct Descriptor;
extern void func_02045780(struct Descriptor *p, u8 v);
extern void func_0204B09C(void *,int,void *);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern const u8 d_021BEC74[],d_021BEC75[],d_021BEC6C[],d_021BEC6D[];
#define W(k) (*(u32 *)(s+(k)))
void func_021BB0C4(u8 *p,const u8 *s,int d)
{
    int i=s[4];
    int x=d_021BEC74[i*2];
    u8 y=d_021BEC75[i*2];
    Pt pt;
    int zero;
    enum Selector {SEL_ZERO,SEL_ONE} selector;
    if (i % 2 == 0) d=-d;
    func_02045780((void *)W(0x20),d+(x+16));
    pt.x=-(x+d)*8;
    pt.y=-y*8;
    func_0204B09C((void *)W(0x24),0,&pt);
    zero=0;
    if (s[4] != 0) zero=1;
    selector=s[4] != 0;
    x+=16;
    d=(unsigned)x+d;
    func_020410D0(2,(u8)d,y,16,6,(u32)(*(u8 **)(p+0x15c)+12),d_021BEC6C[selector*2],d_021BEC6D[zero*2],32,32);
    func_020413B0(2,d,y,16,6,5);
    func_02045374((void *)W(0x20));
    func_02041B6C(1);
    func_02041B6C(2);
}

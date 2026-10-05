/*
 * function: func_021BB0C4
 * address: 0x021BB0C4
 * packet: pkt_ov091_021BB0C4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * retry: Wave77 final retry: boolean zero220/2, point-call wrapper220/2, initialized point-return helper228/154; iteration stopped after three nonshrinking changes. Check3 const p220/32; strict own-pointer prototypes check1 restores220/2. Five fixed-flag one runs; original body retained with current strict declarations.
 * residue: 220 bytes, two concrete bytes at +0046/+0048: zero spill uses r0 instead of r1.
 * witness: ARM9 func_0204B09C current EXACT source src/matched/arm9/func_0204B09C.c and shard pkt_0204B09C read before caller compilation; all11 relocations now resolve.
 * checks: 1 exact own arity/types refreshed: 02045780(void*,u8),0204B09C(void*,int,void*),410D0 ten,413B0 six,45374(void*),41B6C(u32); file-local struct pointer types substituted by void*; 2 BB1A0/D218 and pending BA6A0/BB200 refreshed; 3 const p worsens to220/32, width/truncation evidence retained; 4 inline-bound-argument, enum-zero and declared-stack-object idioms read; 5 fresh plain directory and neighbours refreshed. Prior types300 permuter consumed; final retry exhausted.
 * note 2026-10-05 (wave P12 lane A4): no source existed in src/pending; filed from docs/notes/pkt_ov091_021BB0C4.c.txt (re-read pool and arguments: correct, 2 bytes DIFF). Callees checked: 0204B09C is void(Owner*,idx,Vec16*) per matched arm9 file; 02045780/02045374/02041B6C have no matched source. Twin: ov091_func_021BA6A0 (same d_021BEC6C selector pattern, `int zero = 0` + enum selector). Residue unchanged: zero spill at +0046/+0048 is `movs r0,#0; str r0` instead of `movs r1,#0; str r1`. Tried (all stay 2 B unless noted): zero as u8/u16/unsigned/char/int/enum, zero declared first, point removed (pt.x/pt.y), arg as named idx copy, literal arg; zero moved before the first call (133 B), before point stores (13-20 B), `int zero = 0` at declaration (51 B), selector as int (13 B), y as int (44 B), x as u8 (111 B), six per-function pragmas (lifetimes, scheduling, peephole: 2 B; dead_assignments 6 B; propagation, common_subs: 120+ B). Idioms read: a-narrow-flag-local-is-spilled-not-constant-propagated, a-loop-counter-zero-before-an-offset-assignment-schedules-before-its-spill, a-named-zero-argument-pins-the-callers-truncation, a-second-zero-must-be-spelled-as-a-copy-of-the-first, a-hoisted-loop-invariant-zero-takes-the-freshly-dead-register-from-the-scratch, a-selector-ternary-first-in-a-sum-keeps-the-selector-in-its-scratch-register. The enum zero/selector locals are stand-in suspects; the plain int forms give the same 2 B.
 * note recoup 2026-10-05 P29R1: still DIFF 2 B (220/220 size, +0046/+0048 zero spill r0 vs r1). 20 compiles: callee prototypes from matched twins (02045780 u8, 410D0 (u32,u8,u32,u32,u8,void*,...) as BA6A0, 413B0, 41B6C, 45374 checked, all return void), point local dropped (pt.x/pt.y, short[2], Rect), zero between x and y stores (13 B), zero as scratch for the -(x+d)*8 / -y*8 values, zero as int/u32 with u32 callee idx, callee idx u8 (138 B), callee (int,int,short*), non-const s, struct {int zero; Pt pt;} (132 B, wrong layout), selector/zero as int (13 B), field read via local i (164 B), pt declared first. All 2 B except as noted. Idioms checked: two-long-lived-values-in-each-others-registers, a-callee-declared-void-that-returns-a-value-changes-later-constant-copies (all callees really void), a-named-zero-argument-pins-the-callers-truncation, a-width-stored-in-the-handle-temp-it-replaces-keeps-the-original-colours (scratch form, 2 B). Pragmas not retried (header lists six, 2 B or worse). Current file uses the twin-style 410D0 prototype with the bare d argument.
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
extern void func_02045780(void *,u8);
extern void func_0204B09C(void *,int,void *);
extern void func_020410D0(u32,u8,u32,u32,u8,void *,u8,u8,u8,u8);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern void func_02045374(void *);
extern void func_02041B6C(u32);
extern const u8 d_021BEC74[],d_021BEC75[],d_021BEC6C[],d_021BEC6D[];
#define W(k) (*(u32 *)(s+(k)))
void func_021BB0C4(u8 *p,const u8 *s,int d)
{
    int i=s[4];
    int x=d_021BEC74[i*2];
    u8 y=d_021BEC75[i*2];
    Pt pt;
    enum Zero {ZERO,ONE} zero;
    enum Selector {SEL_ZERO,SEL_ONE} selector;
    if (i % 2 == 0) d=-d;
    func_02045780((void *)W(0x20),d+(x+16));
    pt.x=-(x+d)*8;
    pt.y=-y*8;
    zero=0;
    func_0204B09C((void *)W(0x24),zero,&pt);
    if (s[4] != 0) zero=1;
    selector=s[4] != 0;
    x+=16;
    d=(unsigned)x+d;
    func_020410D0(2,d,y,16,6,*(u8 **)(p+0x15c)+12,d_021BEC6C[selector*2],d_021BEC6D[zero*2],32,32);
    func_020413B0(2,d,y,16,6,5);
    func_02045374((void *)W(0x20));
    func_02041B6C(1);
    func_02041B6C(2);
}

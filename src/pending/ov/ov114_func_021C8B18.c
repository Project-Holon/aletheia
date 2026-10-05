/*
 * function: func_021C8B18
 * address: 0x021C8B18
 * packet: pkt_ov114_021C8B18
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: DIFF
 * residual: 16 concrete bytes, first pool base load (state) is delayed after the six byte loads
 * owner-blocker: Ilias SDK ov114 0x021CA470; matched ov_sdk definition
 *   void func_021CA470(int,int,int,int,int) conflicts with caller return use.
 *   021C8B84: bl 021CA470; 021C8B88: cmp r0,#0.
 *   021CA488: bl 021CA240; 021CA48C: add sp,sp,#8; 021CA490: pop {r3,pc}
 *   preserve r0 from SDK 021CA240's int return. Definition remains untouched.
 *   The C below is the historically compiled recovery sketch, not eligible
 *   for a new caller retry until the owner's prototype is corrected.
 * renewed-pass: wave77 R11; signed six-byte locals 30, local state 50, long state 30; u16 x check 30; once-only permuter 300 retained 172/30 with identical baseline.
 * checks: 1 own SDK definitions audited 2/5/0, void-return discrepancy above stops matching; 2 live 87FC/8C68/8DA0 twins reread, their declarations also predate SDK definitions; 3 u16 x compiled unchanged 30; emitted permuter baseline agrees 172/30, 300 candidates no improvement; 4 scheduling/global-base/aggregate-copy idioms read; 5 unfiltered idiom directory refreshed and neighbours reread, no stack aggregate in best C.
 * recoup 2026-10-05 (wave P15 D2): DIFF 30/172 (same residue). Callee prototypes taken from the matched siblings 021C8C68/021C8DA0 (int server, char *initdata; int return of 021CA470): no change. Twin search: grep -l func_021C9EE4 src/matched/ov (12 hits, all ov114 siblings); no sibling has a 6-byte copy. Tried: struct copy d = *p (interleaved ldrb/strb, 48 B); local Six copy (208 B); u8 locals in natural store order (42 B); state pointer local (48 B); out pointer local before or after the u8 locals (30 B); both pointer locals (48 B); u8 x parameter (30 B); u8 array and u8 *p (30 B); y store first with late loads (54 B); x byte store first (55 B); six per-function pragmas (30 B each). Residue: output base r4 and state base r5 are swapped, and the original loads the state pool word before the six byte loads while ours loads it after them. Idioms checked: two-long-lived-values-in-each-others-registers (no missing arg, no join local: 30), a-spilled-offset-derived-at-the-top (n/a), the-block-constant-in-a-callee-saved-register (n/a), a-const-source-pointer-hoists-the-last-load (const p: 48 B with struct copy), a-copy-and-a-pointer-step-hoisted-above-a-call (n/a), a-callee-declared-void (callee returns int already: 30).
 * final push 2026-10-05 G6L10: DIFF 16/172 (was 30/172), best form below. Found: with #pragma opt_propagation off, a named State pointer assigned late (after the byte loads and stores, here just before the if, used once for words[2]) gives the original colours (state r5, output r4); declared first or used for the early stores it flips them back (41 to 48 B). Only residue: the original loads the state pool word before the six byte loads (ours after them, 4 instructions shifted). Tried without gain: memcpy(d,p,6) (50 B), struct copy any layout (50 B, interleaved two-register copy), array-typed state (28 to 41 B), both pointers named (130+ B, extra r8), s assigned after the call or before it (16 B), x/y store first (44 to 55 B), x then y order (41 B), opt_lifetimes off and opt_common_subs off on the best form (16 B), extern int server instead of void* cast (no change), extern declaration order (30 B). Matched-assembly search for pool-ldr then four ldrb from an argument register: ov114 021C8B18 is the only hit in all overlays and arm9, no twin. Idioms: opt-propagation-off-with-named-locals, a-pair-copy-memcpy (not a pair copy here: 50 B), of-two-equal-temps-the-later-born-one-gets-the-lower-register (colour half applies).
 * symbols:
 * d_021D3D28 0x021D3D28 data a4
 * d_021D3D2C 0x021D3D2C data a4
 * d_021CF538 0x021CF538 data a4
 * d_021D3D40 0x021D3D40 data a4
 * func_021C9EE4 0x021C9EE4 arm ov114
 * func_021CA470 0x021CA470 arm ov114
 * func_021CA1B4 0x021CA1B4 arm ov114
 * d_021CF634 0x021CF634 data a4
 */
extern void *d_021D3D28;
typedef unsigned char u8;
typedef struct { unsigned int words[6]; unsigned char pad[2], byte; unsigned char gap[0x1c8-0x1b]; unsigned int x; } State;
typedef struct { u8 a,b,c,d,e,f; } Six;
extern State d_021D3D2C;
extern unsigned int d_021CF538[], d_021CF634[];
extern Six d_021D3D40;
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
#pragma opt_propagation off
void func_021C8B18(Six *p, int x, unsigned int y)
{
    State *s;
    u8 a = p->a, b = p->b, c = p->c, d = p->d, e = p->e, f = p->f;
    d_021D3D2C.x = y;
    d_021D3D40.f = f;
    d_021D3D40.a = a;
    d_021D3D40.b = b;
    d_021D3D40.c = c;
    d_021D3D40.d = d;
    d_021D3D40.e = e;
    d_021D3D2C.byte = x;
    func_021C9EE4((int)d_021D3D28, (char *)d_021CF538);
    s = &d_021D3D2C;
    if (func_021CA470(d_021CF634, s->words[2], &d_021D3D40, 7, 0) == 0) {
        d_021D3D2C.words[0] = 14;
        return;
    }
    d_021D3D2C.words[0] = 24;
    d_021D3D2C.words[1] = -13;
    func_021CA1B4();
}
#pragma opt_propagation reset

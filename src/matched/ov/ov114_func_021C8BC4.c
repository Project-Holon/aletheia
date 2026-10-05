/*
 * function: func_021C8BC4
 * address: 0x021C8BC4
 * packet: pkt_ov114_021C8BC4
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * recoup 2026-10-05 (wave P15 D6): residue 4 B (loop byte temps r1/r2 swapped: original
 *   b in r1, a in r2; ours b in r2, a in r1). Callees ov114 siblings return int
 *   (func_021CA470 int; func_021C9EE4 void, int server arg): declared as in matched
 *   ov114 021C87FC/021C8C68, no change in the residue. Tried: local order (b,a / a,b,
 *   function scope / block scope), assignment order, u8 vs int temps, const source,
 *   one shared temp, u8* instead of Pair, struct copy (adds mov), indexed form
 *   (strength reduced differently, 135 B off), stores a-then-b (loads reorder, 115 B off),
 *   each of the 6 per-function pragmas (opt_propagation off 117 B off, rest still 4 B).
 *   Idioms read: an-unsigned-counter-keeps-the-subs-bne-of-a-countdown-loop (kept
 *   unsigned countdown, loop shape matches), declaration-order-picks-the-register-
 *   initialisation-order-picks-the-load (no effect here), compute-a-stores-operands-
 *   before-the-store, a-byte-record-table-with-a-trailing-index-array-is-a-struct,
 *   post-increment-of-a-field-spends-a-copy. 26 compiles, over cap; stopped.
 *   Twin grep: func_021C9EE4/func_021CA470/func_021CA1B4 callers in ov114 only
 *   (87FC, 8C68, 8DA0 etc.), none copies 2-byte records in a loop.
 * recoup 2026-10-05 P29R4: still 4 B (b/a temps in r2/r1, original r1/r2). Tried (21 compiles):
 *   no temps with p++/q++ or q++/p++ (13 B, loads and subs reorder), temps with stores
 *   before p++ (115 B), do-while (4 B), while(i--) (134 B), for i<4 up-count (111 B),
 *   a loaded before b in each store order (115 B, loop loses the countdown shape),
 *   temps declared at function scope before/after q/i (10 B, 4 B), one `u8 a, b;` in the
 *   block (4 B), b temp only with direct p->a at the store (13 B), p++->a / q++->a
 *   post-increment forms (4 B), q = q + 1 (4 B). The callee declarations were
 *   re-checked against matched ov114 callers: no change. No stand-in kept.
 * final push 2026-10-05 G1L8: still 4 B (temps r2/r1, original r1/r2). Tried 8 compiles, new
 *   forms only: 8-byte char-array struct copy `*(Key8 *)d = *(Key8 *)p` (the compiler's own
 *   aggregate-copy loop, 168 B, loads [r0] before [r0,#1] plus a separate add, 115 B off);
 *   same with u8 array, with Pair[4] struct, with named d/s pointer locals (all 115 B off);
 *   char and unsigned short temps (4 B); q assigned after the x store (4 B); a block-local
 *   Pair temp struct (4 B). The matched twins at ov114 021C99D0 and 021C9B64 use this loop
 *   shape only for a 17-byte aggregate initialiser, not for a pointer-to-pointer copy.
 *   Idioms read: statement-order-of-scratch-temporaries, colour-swap-opt_lifetimes,
 *   byte-locals-signedness, masked-locals-width, dying-pointer-loads-allocator-tie,
 *   byte-record-table-struct. No stand-in kept.
 * final push 2026-10-05 G1R7: still 4 B (b r2 / a r1, original b r1 / a r2). 3 rounds, ~45 compiles.
 *   The memcpy lead: matched twins (ov175 021E05AC, ov009 02198A0C, ov172 021C2DC8, main
 *   0205EB30) are mwcc's inline memcpy loop; memcpy(d_021D3D40, p, 8) with libc string.h gives
 *   the other shape (ldrb [r0], ldrb [r0,#1], separate add, 115 B off) for any pointer or
 *   array typing of p; the post-inc shape with ascending temps appeared only when the memcpy
 *   source is a stack-array address (not reachable here). Explicit loop is therefore the form.
 *   Allocator (mwcc Coloring.c): nodes colored in descending vreg birth order, lowest free
 *   register first, so the later-born temp gets r1. Fused post-inc form (p++ before the
 *   stores) always births b first (b r2). Non-fused forms (p++ after stores) give b r1 / a r2
 *   but load [r0] first and an unfused add (115 B). Also tried: decl order/scope/dead
 *   initialisers, inline helpers and macro copy, named s/d pointers, (p++)->a, q[-1] forms,
 *   while with end pointer, int temps. No stand-in kept. Matched-asm hits: 38 sites of the
 *   loop; r1/r2 ones read: ov009 02198B2C, ov172 021C2DDC, ov175 021E06A8, main 0205EB48.
 * pass 2 2026-10-06 P2L05: the pair loop is mwcc's inline memcpy: memcpy(d_021D3D40, p, 8) with
 *   string.h and a const void * source parameter. With a u8 * source the expansion differs
 *   (104 B off with a u8 destination, 115 B with a word destination).
 * symbols:
 *   d_021D3D28   0x021D3D28  data  a4
 *   d_021D3D2C   0x021D3D2C  data  a4
 *   d_021CF538   0x021CF538  data  a4
 *   d_021CF634   0x021CF634  data  a4
 *   d_021D3D40   0x021D3D40  data  a4
 *   func_021C9EE4 0x021C9EE4  arm
 *   func_021CA470 0x021CA470  arm
 *   func_021CA1B4 0x021CA1B4  arm
 */
#include "../../matched/arm9_sdk/libc/string.h"
extern unsigned int *d_021D3D28;
extern unsigned int d_021D3D2C[];
extern unsigned int d_021CF538[];
extern unsigned int d_021CF634[];
extern unsigned int d_021D3D40[];
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned int, void *, unsigned int, unsigned int);
extern void func_021CA1B4(void);

void func_021C8BC4(const void *p, unsigned int x)
{
    d_021D3D2C[0x72] = x;
    memcpy(d_021D3D40, p, 8);
    func_021C9EE4((int)d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF634, d_021D3D2C[2], d_021D3D40, 8, 0) == 0) {
        d_021D3D2C[0] = 14;
        return;
    }
    d_021D3D2C[0] = 24;
    d_021D3D2C[1] = -13;
    func_021CA1B4();
}

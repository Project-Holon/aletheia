/*
 * function: func_0220C16C
 * address: 0x0220C16C
 * packet: pkt_ov198_0220C16C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wD9r lane164): EXACT in both --lang c99 and --lang c. The steering cast `(u32)n >> 1` is gone:
 *   the halving is a single-parameter helper `static inline u32 half(u32 w) { return w >> 1; }` (shape of
 *   ov097 021F6D70 center_x), so the u32 parameter gives lsrs. Plain `x0 - (n >> 1)` is DIFF. Locals are
 *   declared at the top in the same order (C89 form), assignments in place; same bytes.
 * 2026-10-05 (wD9r lane156): EXACT. n is a u8 local (`u8 n = func_0201D304(...)`), widened to u32 for the
 *   halving shift (`x0 - ((u32)n >> 1)`, keeps lsrs). mwcc keeps the reload of a spilled narrow local below the
 *   outgoing stack stores (docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md).
 * 2026-10-05 (wD9r lane138): still 22 bytes. Tried the matched ov198 sibling prototype (0220C694, 0220D628:
 *   `func_0201C724(void *, u32, u32, u32, u32, u32, u16)` with an (s16) cast at the call): 54, the ex reload
 *   then hoists above the stack stores in all three calls. Also (u32, u32, int, int): 327 (frame grows, slot
 *   spilled); (int, s16): 328; (s16, int): 54; (short, short): 22. Finding: with an s16 parameter the ex
 *   reload stays below the outgoing stores, with u32 or int it hoists, so the s16 prototype is right and the
 *   parameter type changes where a reload lands. The x0 + n add still heads the chain in every form.
 * 2026-10-05 (wD9r lane127): still 22 bytes. Tried two new forms of the 'n lives in memory' idea:
 *   n written through a static inline out-parameter helper `getw(text, font, &n)` (u32 and u8 n; mwcc
 *   promotes the inlined address-taken local, same 22 or 29 lines); and `y = x0 + n;` reusing the call 2
 *   s16 local for call 3 (same 22). Check of the hint: no register parameter here can be a homed narrow
 *   parameter (all four are used in registers at entry, no entry store), and a homed slot would add bytes
 *   (image is 396, ours 396). The 0xC slot is the narrow stack parameter `extra` copied to the frame.
 * 2026-10-05 (wD9r lane111): still 22 bytes. New finding (diagnostic): a reassigned NARROW real parameter
 *   (index declared u16, short or signed char, then `index = (u8)func_0201D304(...)` and `x0 + index` in call 3)
 *   is memory-homed by mwcc, and call 3 then has the image order exactly (three stack stores, ldr r2 n,
 *   ldr r0 ctx3, adds, lsls, ldr r3, asrs). But the home costs an entry store `str r2,[sp,#0xc]` and a reload
 *   for the first call, and the slot is the lowest one (image: no entry store, n at 0x28), so not the source.
 *   A u8 index is not homed (40, still hoisted). Also tried: the body after the 0201D304 call as a static
 *   inline `rest(..., u32/u16/short n)` with n as an inline parameter (328, slot param spilled; the n reload
 *   is still hoisted, inline parameters are not homed). So the image n has the alias class of a param home
 *   or escaped local (ov097 lane95), but no source form with neither an entry store nor an `add rX,sp` found.
 * 2026-10-05 (wD9r lane56): still 22 bytes. Tried: n as u16 (40, n >> 1 becomes asrs and slots shift); the
 *   third x through `static inline s16 xsum(u8 a, u32 b) { return a + b; }` (22, the sum is still evaluated
 *   before the outgoing stack stores). Reading: in this compiler a load does not pass an earlier store (see
 *   ov194 021F3FBC entry), so the original evaluates the stack arguments of call 3 before the x sum and ours
 *   evaluates the sum first; the argument evaluation order, not alias, is the residue.
 * 2026-10-05 (wD9r lane43): still 22 bytes. Tried n declared u8 with the callee result assigned directly
 *   (the narrow-parameter idiom applied to the spilled local): 40 bytes, slots shift and the n reload still hoists
 *   above the stack stores. Compared with the EXACT sibling 0220D494: its third call `x + w1` has u32 x, here x0
 *   is a u8 parameter; no source form found that blocks the hoist.
 * 2026-10-05 (wD9r lane26): still 22 bytes. Tried int return types on 0201EFA4, 0201F250, 02045808 and 0201C724
 *   (the lever that closed ov217 021B9920): same 22. In ov097 021F6D70 an early s16 local for the sum is sunk to
 *   the call by mwcc, so the chain position is decided at the use, not by where the sum is written.
 * 2026-10-05 (wD9r lane12): still 22 bytes. Tried: the 0201D304 result in a u32 local w, then n = (u8)w (two
 *   variables, same 22); the third x through a pointer round trip (stand-in probe only, same 22). Same residue
 *   as ov097 021F6D70: the n reload heads the r2 chain in ours and sits below the stack stores in the image.
 *
 * note: DIFF vs 2026-10-04: 22 bytes differ, only the last 201C724 call: original stores the three stack args first and loads n and adds x0+n late (ldr r2,[sp,#0x28] after the stack stores), ours hoists the n load and add before the stack stores. Everything else matches (declaration order sets slots; x0 param reassigned; ctx and A/B locals). Tried: (s16)(x0+n), n+x0, a y local assigned before the call.
 * note 2026-10-05 (wave D4 lane 10): still DIFF (22 bytes). Tried ctx3 inlined as P->f1EAC (115 bytes) and
 *   A/B locals for the third call as in the second (no change). The sibling 0220D494 (EXACT this wave)
 *   computes its x+w1 early like ours, so the late `ldr r2,[sp,#0x28]; adds` here hints the third x is a
 *   different expression or variable in the original; not found.
 * note 2026-10-05 (wave D5 lane 10): still DIFF (22 bytes). Tried: a static inline put helper for all three calls
 *   (s16 x: no change; int x: 334 bytes), the helper on the third call only with int x (122), u8/int/s16 n (23-40),
 *   `y = x0 + n` before or after ctx3 (no change). The original treats the n reload as if it may alias the outgoing
 *   stack stores; ours hoists it above them.
 * 2026-10-05 (wD6 lane07): still 22 bytes. Tried: the 02045770 result in a block local before the call, with and
 *   without `y = x0 + n` and B3/A3 locals for the stack arguments placed after it (no change: the scheduler, not the
 *   source order, places the n reload); volatile n (337); int prototype for x with (s16) casts (327). In the original
 *   the n reload is not moved above the outgoing stack stores; ours is.
 * 2026-10-05 (wD7 lane10): still DIFF, 22 bytes. Read the scheduling: in the original, every spill reload before
 *   the three 0201C724 calls stays below the outgoing stack stores (call 2 leaves the `ldr r0,[sp,#0x10]; str r0,[sp]`
 *   stall open), so the n reload is blocked by a dependence, not by priority. In ours the n reload heads a 5-instruction
 *   chain and fills the stalls. Tests: an int y in call 2 (needs a conversion) also hoists its reload above the
 *   stores, so chain length drives the hoist in our build. n as a one-element array, n passed by address to a
 *   static inline adder, n used alone as x (no add), u8 n: the reload still hoists. A new u8 local x for
 *   x0 - (n >> 1) instead of reassigning x0: 328. No ex local, no tab local: no change; ctx1 inlined: 314.
 *   Open: what makes the original x chain depend on the stack stores.
 * 2026-10-05 (wD8 lane09): still 22 bytes. Same scheduler residue as ov116 021D7D0C (a spill reload kept
 *   below the outgoing stack stores in the image, hoisted in ours). No new form tested beyond the listing check.
 * 2026-10-05 (wD9 lane20): still 22 bytes. Tested whether n lives in memory in the original (a reload that may alias
 *   the outgoing stores): n as a one-field local struct `struct { u32 v; } n;` is still promoted to a register and
 *   spilled; the reload still hoists above the stack stores (35 bytes, slots shift). Not a memory variable.
 * 2026-10-05 (wD9r lane79): still 22 bytes. Tried the sum as a reassignment before the call: `n = x0 + n;`
 *   then pass n (400 bytes, 99, n gets a new register and slot), and `x0 = x0 + n;` then pass x0 (23, adds a u8
 *   truncation). Neither keeps the n reload below the outgoing stack stores.
 * 2026-10-05 (wD9r lane87): still 22 bytes. Tried the house prototype of func_0201C724 with a u16 colour
 *   (ov021 021905C8, arm9 0202E1F0), with and without a const text pointer: same 22. The n reload still
 *   heads the x chain above the outgoing stack stores.
 * 2026-10-05 (wD9r lane98): still 22 bytes. Reading: in both builds the direct-move reloads (y, ex, ctx) sit
 *   below the outgoing stack stores and do not fill the `ldr; str [sp]` stalls, so reloads never pass those stores;
 *   ours therefore has the n reload (the x0 + n add) before the stores in its IR. Tried: a block u32 x3 = x0 + n and
 *   int x3 = n + x0 before ctx3 (22, sunk to the same place); the 02045770 result in a block local h3 with ctx3
 *   before it (22) and with P->f1EAC inline as the first argument (115). No new source form found.
 * 2026-10-05 (wD9r lane104): still 22 bytes. Tried the short idiom (ov116 021D7D0C): n as short or u16
 *   (40, n >> 1 becomes asrs and slots shift, reload still hoists), func_0201D304 returning short (22),
 *   x0 as a short parameter (24, the x0 truncation becomes 16-bit, reload still hoists), and the dead int
 *   parameter `index` reused for n as short/u16/u8 (40) or int/u32 (376). None keeps the n reload below the
 *   outgoing stack stores.
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Ov198P { char pad[0x1E9C]; u32 f1E9C; void *f1EA0; void *f1EA4; void *f1EA8; u32 f1EAC; };
#define P ((struct Ov198P *)p)
extern int func_022110D4(u8 *, int);
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(u32, u32, s16, s16, void *, u32, u32);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

static inline u32 half(u32 w) { return w >> 1; }

/*
 * 2026-10-05 (wD9r lane164): EXACT in both --lang c99 and --lang c. The steering cast `(u32)n >> 1` is gone:
 *   the halving is a single-parameter helper `static inline u32 half(u32 w) { return w >> 1; }` (shape of
 *   ov097 021F6D70 center_x), so the u32 parameter gives lsrs. Plain `x0 - (n >> 1)` is DIFF. Locals are
 *   declared at the top in the same order (C89 form), assignments in place; same bytes.
 * 2026-10-05 (wD9r lane156): EXACT. n is a u8 local (`u8 n = func_0201D304(...)`), widened to u32 for the
 *   halving shift (`x0 - ((u32)n >> 1)`, keeps lsrs). mwcc keeps the reload of a spilled narrow local below the
 *   outgoing stack stores (docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md).
 * 2026-10-05 (wD9r lane138): still 22 bytes. Tried the matched ov198 sibling prototype (0220C694, 0220D628:
 *   `func_0201C724(void *, u32, u32, u32, u32, u32, u16)` with an (s16) cast at the call): 54, the ex reload
 *   then hoists above the stack stores in all three calls. Also (u32, u32, int, int): 327 (frame grows, slot
 *   spilled); (int, s16): 328; (s16, int): 54; (short, short): 22. Finding: with an s16 parameter the ex
 *   reload stays below the outgoing stores, with u32 or int it hoists, so the s16 prototype is right and the
 *   parameter type changes where a reload lands. The x0 + n add still heads the chain in every form.
 * 2026-10-05 (wD9r lane127): still 22 bytes. Tried two new forms of the 'n lives in memory' idea:
 *   n written through a static inline out-parameter helper `getw(text, font, &n)` (u32 and u8 n; mwcc
 *   promotes the inlined address-taken local, same 22 or 29 lines); and `y = x0 + n;` reusing the call 2
 *   s16 local for call 3 (same 22). Check of the hint: no register parameter here can be a homed narrow
 *   parameter (all four are used in registers at entry, no entry store), and a homed slot would add bytes
 *   (image is 396, ours 396). The 0xC slot is the narrow stack parameter `extra` copied to the frame.
 * 2026-10-05 (wD9r lane111): still 22 bytes. New finding (diagnostic): a reassigned NARROW real parameter
 *   (index declared u16, short or signed char, then `index = (u8)func_0201D304(...)` and `x0 + index` in call 3)
 *   is memory-homed by mwcc, and call 3 then has the image order exactly (three stack stores, ldr r2 n,
 *   ldr r0 ctx3, adds, lsls, ldr r3, asrs). But the home costs an entry store `str r2,[sp,#0xc]` and a reload
 *   for the first call, and the slot is the lowest one (image: no entry store, n at 0x28), so not the source.
 *   A u8 index is not homed (40, still hoisted). Also tried: the body after the 0201D304 call as a static
 *   inline `rest(..., u32/u16/short n)` with n as an inline parameter (328, slot param spilled; the n reload
 *   is still hoisted, inline parameters are not homed). So the image n has the alias class of a param home
 *   or escaped local (ov097 lane95), but no source form with neither an entry store nor an `add rX,sp` found.
 * 2026-10-05 (wD9r lane56): still 22 bytes. Tried: n as u16 (40, n >> 1 becomes asrs and slots shift); the
 *   third x through `static inline s16 xsum(u8 a, u32 b) { return a + b; }` (22, the sum is still evaluated
 *   before the outgoing stack stores). Reading: in this compiler a load does not pass an earlier store (see
 *   ov194 021F3FBC entry), so the original evaluates the stack arguments of call 3 before the x sum and ours
 *   evaluates the sum first; the argument evaluation order, not alias, is the residue.
 * 2026-10-05 (wD9r lane43): still 22 bytes. Tried n declared u8 with the callee result assigned directly
 *   (the narrow-parameter idiom applied to the spilled local): 40 bytes, slots shift and the n reload still hoists
 *   above the stack stores. Compared with the EXACT sibling 0220D494: its third call `x + w1` has u32 x, here x0
 *   is a u8 parameter; no source form found that blocks the hoist.
 * 2026-10-05 (wD9r lane26): still 22 bytes. Tried int return types on 0201EFA4, 0201F250, 02045808 and 0201C724
 *   (the lever that closed ov217 021B9920): same 22. In ov097 021F6D70 an early s16 local for the sum is sunk to
 *   the call by mwcc, so the chain position is decided at the use, not by where the sum is written.
 * 2026-10-05 (wD9r lane12): still 22 bytes. Tried: the 0201D304 result in a u32 local w, then n = (u8)w (two
 *   variables, same 22); the third x through a pointer round trip (stand-in probe only, same 22). Same residue
 *   as ov097 021F6D70: the n reload heads the r2 chain in ours and sits below the stack stores in the image.
 *
 * note: DIFF vs 2026-10-04: 22 bytes differ, only the last 201C724 call: original stores the three stack args first and loads n and adds x0+n late (ldr r2,[sp,#0x28] after the stack stores), ours hoists the n load and add before the stack stores. Everything else matches (declaration order sets slots; x0 param reassigned; ctx and A/B locals). Tried: (s16)(x0+n), n+x0, a y local assigned before the call.
 * note 2026-10-05 (wave D4 lane 10): still DIFF (22 bytes). Tried ctx3 inlined as P->f1EAC (115 bytes) and
 *   A/B locals for the third call as in the second (no change). The sibling 0220D494 (EXACT this wave)
 *   computes its x+w1 early like ours, so the late `ldr r2,[sp,#0x28]; adds` here hints the third x is a
 *   different expression or variable in the original; not found.
 * note 2026-10-05 (wave D5 lane 10): still DIFF (22 bytes). Tried: a static inline put helper for all three calls
 *   (s16 x: no change; int x: 334 bytes), the helper on the third call only with int x (122), u8/int/s16 n (23-40),
 *   `y = x0 + n` before or after ctx3 (no change). The original treats the n reload as if it may alias the outgoing
 *   stack stores; ours hoists it above them.
 * 2026-10-05 (wD6 lane07): still 22 bytes. Tried: the 02045770 result in a block local before the call, with and
 *   without `y = x0 + n` and B3/A3 locals for the stack arguments placed after it (no change: the scheduler, not the
 *   source order, places the n reload); volatile n (337); int prototype for x with (s16) casts (327). In the original
 *   the n reload is not moved above the outgoing stack stores; ours is.
 * 2026-10-05 (wD7 lane10): still DIFF, 22 bytes. Read the scheduling: in the original, every spill reload before
 *   the three 0201C724 calls stays below the outgoing stack stores (call 2 leaves the `ldr r0,[sp,#0x10]; str r0,[sp]`
 *   stall open), so the n reload is blocked by a dependence, not by priority. In ours the n reload heads a 5-instruction
 *   chain and fills the stalls. Tests: an int y in call 2 (needs a conversion) also hoists its reload above the
 *   stores, so chain length drives the hoist in our build. n as a one-element array, n passed by address to a
 *   static inline adder, n used alone as x (no add), u8 n: the reload still hoists. A new u8 local x for
 *   x0 - (n >> 1) instead of reassigning x0: 328. No ex local, no tab local: no change; ctx1 inlined: 314.
 *   Open: what makes the original x chain depend on the stack stores.
 * 2026-10-05 (wD8 lane09): still 22 bytes. Same scheduler residue as ov116 021D7D0C (a spill reload kept
 *   below the outgoing stack stores in the image, hoisted in ours). No new form tested beyond the listing check.
 * 2026-10-05 (wD9 lane20): still 22 bytes. Tested whether n lives in memory in the original (a reload that may alias
 *   the outgoing stores): n as a one-field local struct `struct { u32 v; } n;` is still promoted to a register and
 *   spilled; the reload still hoists above the stack stores (35 bytes, slots shift). Not a memory variable.
 * 2026-10-05 (wD9r lane79): still 22 bytes. Tried the sum as a reassignment before the call: `n = x0 + n;`
 *   then pass n (400 bytes, 99, n gets a new register and slot), and `x0 = x0 + n;` then pass x0 (23, adds a u8
 *   truncation). Neither keeps the n reload below the outgoing stack stores.
 * 2026-10-05 (wD9r lane87): still 22 bytes. Tried the house prototype of func_0201C724 with a u16 colour
 *   (ov021 021905C8, arm9 0202E1F0), with and without a const text pointer: same 22. The n reload still
 *   heads the x chain above the outgoing stack stores.
 * 2026-10-05 (wD9r lane98): still 22 bytes. Reading: in both builds the direct-move reloads (y, ex, ctx) sit
 *   below the outgoing stack stores and do not fill the `ldr; str [sp]` stalls, so reloads never pass those stores;
 *   ours therefore has the n reload (the x0 + n add) before the stores in its IR. Tried: a block u32 x3 = x0 + n and
 *   int x3 = n + x0 before ctx3 (22, sunk to the same place); the 02045770 result in a block local h3 with ctx3
 *   before it (22) and with P->f1EAC inline as the first argument (115). No new source form found.
 * 2026-10-05 (wD9r lane104): still 22 bytes. Tried the short idiom (ov116 021D7D0C): n as short or u16
 *   (40, n >> 1 becomes asrs and slots shift, reload still hoists), func_0201D304 returning short (22),
 *   x0 as a short parameter (24, the x0 truncation becomes 16-bit, reload still hoists), and the dead int
 *   parameter `index` reused for n as short/u16/u8 (40) or int/u32 (376). None keeps the n reload below the
 *   outgoing stack stores.
 */
void func_0220C16C(u8 *p, int slot, int index, u8 x0, u8 extra)
{
    char *elem;
    void *text;
    u8 n;
    u32 ctx1;
    u8 ex;
    u8 *tab;
    u8 *fl;
    void *text2;
    void *text3;
    u32 ctx2;
    s16 y;
    u32 ctx3;
    u32 A;
    void *B;
    elem = (char *)(p + 4) + func_022110D4(p, index) * 0x4C;
    text = func_02045EC0(P->f1EA0, 12);
    n = func_0201D304(text, P->f1E9C, 0);
    x0 = x0 - half(n);
    ctx1 = P->f1EAC;
    ex = extra;
    slot = slot * 8;
    tab = p + 0x1F70;
    fl = p + 0x1F74;
    func_0201C724(ctx1, (u32)func_02045770(*(void **)(tab + slot)), x0, ex, text, P->f1E9C, 0x3DC0);
    fl[slot] = 1;
    func_02045808(text);
    text2 = func_02045EC0(P->f1EA0, 13);
    func_0201EFA4(P->f1EA4, 0, *(u16 *)(elem + 0x10), 3, 0, 1);
    func_0201F250(P->f1EA4, P->f1EA8, text2);
    A = P->f1E9C;
    B = P->f1EA8;
    y = x0 - func_0201D304(B, A, 0);
    ctx2 = P->f1EAC;
    func_0201C724(ctx2, (u32)func_02045770(*(void **)(tab + slot)), y, ex, B, A, 0x3DC0);
    fl[slot] = 1;
    func_02045808(text2);
    text3 = func_02045EC0(P->f1EA0, 13);
    func_0201EFA4(P->f1EA4, 0, *(u16 *)(elem + 0x12), 3, 0, 1);
    func_0201F250(P->f1EA4, P->f1EA8, text3);
    ctx3 = P->f1EAC;
    func_0201C724(ctx3, (u32)func_02045770(*(void **)(tab + slot)), x0 + n, ex, P->f1EA8, P->f1E9C, 0x3DC0);
    fl[slot] = 1;
    func_02045808(text3);
}

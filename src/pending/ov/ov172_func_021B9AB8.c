/*
 * function: func_021B9AB8
 * address: 0x021B9AB8
 * packet: pkt_ov172_021B9AB8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note (2026-10-05, wD4 lane17): DIFF, 186 -> 131 bytes. Lever: y0 is read in the loop pre-header as `yb = *(u8 *)&y0;` (stack u8 argument re-read from its home, address-taking is fine for stack args). The prologue now matches except x0/p: original stores r3,r2 to [sp,#4],[sp] first and reloads x0 for every use (ours copies x0 to r1), and holds y0 in r5 across the float calls. Slot order of stepx, stepy, yb also differs (original yb lowest). Tried yb declared first, stepy before stepx (132-133 bytes).
 * note 2026-10-04 wD2 lane01: still 186 bytes. Original spills r3 (x0) and r2 (p) first at entry and re-reads x0 from [sp,#4] at every use; ours copies x0 to r1. Tried `*(int *)&x0` at each use: forces a `push {r0-r3}` prologue (107 bytes diff, 214 bytes), so x0 is an allocator spill, not address-taken. Also `*(u8 **)&p` (worse).
 * note (2026-10-04): draft is logic-correct (186 byte diff, 206 vs 208 bytes). Residue: original keeps x0 and p
 *   purely on the stack (str r3,[sp,#4] first; x0 reloaded each use) and holds y1,y0 in r4,r5 across the
 *   float-round calls, re-reading y0 from the stack arg in the loop pre-header; mine copies x0 to r1 and
 *   spills y0 to [sp,#8] early. Tried: u8 vs one-field struct stack params, struct x0, ternary max,
 *   declaration order of accumulators, u8 callee params. None changed the allocation.
 * 2026-10-05 (wD5 lane20): 131 -> 27 bytes. Levers: y0 and y1 copied into locals `by = y1; ay = y0;` assigned AFTER the dx abs (original keeps y1 in r4, y0 in r5 across the float calls; declare ay before by, assign by first), and the loop-invariant read of the stack u8 `*(u8 *)&y0` written inline in the loop call so it hoists after the n>0 guard. Declaring stepy before stepx gives 27. Residue: (1) x0 is a pure memory spill in the original (str r3,[sp,#4] first, x0 reloaded at every use: `ldr r0,[sp,#4]` before `subs r2,r0,r1`); ours copies r3 to r1 first, so dx and d use r1/r0 swapped; (2) spill slot order of stepx/stepy/hoisted y temp (original 0x10/0xc/8, ours 8/0xc/0x10). Not tried: anything that forces x0 into memory without an address-taking cast.
 * note 2026-10-05 (wD6 lane06): 27 -> 13 bytes. Levers: x0 typed u8 (the image spills it whole and reloads it at each use; int x0 is copied to r1 first), abs written as a static inline ternary `a < 0 ? -a : a` (sets x1 in r1 and the dy temp in r0 as in the image; the if-negate form does not), and the y0 read placed before the loop body inside an explicit `if (n > 0)` guard with a do/while (fixes the stepx/stepy/yb slot order 0x10/0xc/8). Residue: only the entry spill order: image `str r3,[sp,#4]; ldr r0,[sp,#0x34]; str r2,[sp]; str r0,[sp,#0x34]`, ours `ldr r0,[sp,#0x34]; str r3,[sp,#4]; str r0,[sp,#0x34]` with `str r2,[sp]` sunk below the x0 reload. Tried without effect: x0 as u16/s8/short, p as void *, value u32, for-in-if loop (worse), plain y0 instead of the ay/by copies (worse).
 * note 2026-10-05 (wD7 lane03): still 13 bytes, same entry-order residue. Tried, all unchanged: a0/a1 as void *,
 *   value as u16 (worse, 0x18 frame), p received as void * / u32 / u16 * and copied to a u8 * local, x0 received
 *   as u8 and copied to an int local, value copied to a local before use; int x0 alone swaps the residue (str r2
 *   early, str r3 sunk). Reading: the image's initial order has the x0 spill store before the value load; ours
 *   puts the value load first, so the scheduler fills its stall with str r3 and sinks str r2.
 * note 2026-10-05 (wD9r lane03): still 13 bytes. Tried the loop call through a static inline wrapper
 *   with the parameters in a different order (value, y, x, p) and (p, value, x, y): unchanged, so the
 *   entry spill order does not follow the order of use. Survey of the overlay asm: this is the only
 *   function where the stack-parameter reload is not the first instruction while r0 is free; in every
 *   other prologue the `ldr rN,[sp,#K]` goes first or right after the spill that frees rN. So the image
 *   suggests that r0 is not free at entry (a0 live, or the value vreg ordered after the x0/p spills).
 * symbols:
 *   func_021B9B88 0x021B9B88 thumb ov172
 *   func_0209BDBC 0x0209BDBC arm
 *   func_0209C95C 0x0209C95C arm
 *   func_0209CB8C 0x0209CB8C arm
 *   func_0209C494 0x0209C494 arm
 *   func_0209C0A4 0x0209C0A4 arm
 * note 2026-10-05 (wD8 lane06): still 13 bytes. Tried: p copied to a local q used in the loop call; dx computed
 *   after the declarations; dy declared before dx. All unchanged (entry spill order only).
 * note 2026-10-05 (wD9 lane11): still 13 bytes. Tried x0 as u32: the residue flips (str r2 first, x0 copied
 *   to r0 and spilled after its first use), as int did. Only u8 x0 gives the reload-at-every-use shape; the
 *   entry order str r3 / ldr value / str r2 / str value is not reached by any parameter type tried.
 * note 2026-10-05 (wD9r lane24): still 13 bytes. Tried: `register` on value and on p (unchanged); long value
 *   (154, worse); an old-style (K&R) definition so the u8 parameters are promoted (222 bytes, worse); plain
 *   `yb = y0` without the address-taking read (entry order unchanged, 182 worse later). Reading kept: the
 *   image pre-order has the x0 spill store before the value load (str r2 fills the load stall); ours emits
 *   the value load first and str r2 fills the later x0 reload stall.
 * note 2026-10-05 (wD9r lane51): still 13 bytes. Tried the NitroSDK macro shape for the whole body
 *   (MATH_ABS, MATH_MAX, stepx = FX_F32_TO_FX32(x1 - x0) / n with int FX32_ONE, plain for loop, callee
 *   with int x/y as in the matched func_021B9B88): 143 bytes, the ternary merges the _fadd/_fsub tails
 *   differently and the entry order is unchanged. The draft's if/else rounding stays.
 * note 2026-10-05 (wD9r lane55): still 13 bytes. Tried r0/r1 as one 8-byte parameter (u64, double,
 *   two-int struct): unchanged. Tried `*(int *)&value` in the loop call: the entry ldr/str of value goes
 *   away but the frame grows (0x18, 152 bytes worse), so value is a real vreg spilled to its own home.
 *   int x0 gives `ldr value; str r2; str value; ... str r3` (still ldr first). Reading: the image keeps the
 *   value load after the x0 spill store, as ov116 021D7D0C (closed, `short heap`) kept the heap reload after the [sp] argument
 *   store; same residue kind in both, no source form found.
 * note 2026-10-05 (wD9r lane67): still 13 bytes. Tried value as `void *` (callee prototype too):
 *   unchanged. Tried the body as a static inline Line(p, x0, y0, x1, y1, value) under a one-line
 *   wrapper: with `*(u8 *)&y0` inside the inline the entry gives the image order exactly (str r3; ldr
 *   value; str r2; str value), but y0 then gets its own stack byte copy (push r3, 0x18 frame, 197 bytes);
 *   with plain y0, int inline parameters, or a `const u8 *py = &y0` parameter the order reverts (182).
 *   Reading: the image pre-order is x0 spill, value load, p spill; an extra entry memory copy reorders
 *   them in ours, but no form without the extra slot was found.
 * note 2026-10-05 (wD9r lane92): still 13 bytes. Tried the callee prototype from the matched definition
 *   func_021B9B88(u8 *, int, int, int) with (u8) casts at the call (unchanged, the casts give the same
 *   lsls/lsrs); value as short, signed char, unsigned short (154 to 196 bytes, frame grows to 0x18).
 *   Note: ov116 021D7D0C (same residue kind) closed with a `short` heap parameter, so a parameter type
 *   that changes the spill class is still the best lead here; x0/value types tried so far did not.
 * note 2026-10-05 (wD9r lane106): still 13 bytes. Followed the ov116 021D7D0C `short` lead on the
 *   parameters not tried before. The listing pins the stack widths: y0, x1, y1 are ldrb (u8; plain char
 *   is signed here and gives ldrsb), value is a word ldr/str home copy. Tried: y0, x1 or y1 as short
 *   (193 to 197 bytes, 210 long); y0 or y1 as u16 (14); x1 as u16 (13, unchanged); value as u8 (154,
 *   frame 0x18, the entry ldr/str of value goes away); const int value (154, value hoisted to a new
 *   slot); a0 or a1 as short, both as u8 (13, unchanged); u8 *const p, const u8 x0 (unchanged);
 *   `*(u8 *)&x1` / `*(u8 *)&y1` / `*(u8 *)&y0` reads in the abs and difference (178 worse or
 *   unchanged); yb as u8 (unchanged). No narrow parameter type moves the x0 home store ahead of the
 *   value load. Reading: str r2 always fills the first load stall after the value copy in the image
 *   and the x0 reload stall in ours, so the residue is the pre-schedule position of value's entry copy.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern int func_0209C0A4(int a, int b);
extern void func_021B9B88(u8 *p, u8 x, u8 y, int value);

static inline int Abs(int a)
{
    return a < 0 ? -a : a;
}

void func_021B9AB8(int a0, int a1, u8 *p, u8 x0, u8 y0, u8 x1, u8 y1, int value)
{
    int stepx, stepy;
    int dx = Abs(x0 - x1);
    int dy;
    int n, i;
    int accx, accy;
    int d, r;
    int ay; int by; int yb;
    by = y1; ay = y0; dy = Abs(ay - by);
    if (dx <= dy)
        dx = dy;
    n = dx + 1;
    d = x1 - x0;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepx = func_0209C0A4(func_0209C494(r), n);
    d = by - ay;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepy = func_0209C0A4(func_0209C494(r), n);
    accx = 0;
    accy = 0;
    i = 0;
    if (n > 0) {
        yb = *(u8 *)&y0;
        do {
            func_021B9B88(p, x0 + (accx >> 12), yb + (accy >> 12), value);
            accx += stepx;
            accy += stepy;
            i++;
        } while (i < n);
    }
}

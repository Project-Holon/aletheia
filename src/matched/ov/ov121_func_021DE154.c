/*
 * function: MYSTERY_ALBUM_PathAnimStep
 * address: 0x021DE154
 * packet: pkt_ov121_021DE154
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prior-checks: 1 runtime quotient helpers take two full-word arguments; no residual call setup; 2 ov121 search found no interpolation twin; 3 const char table reduced 13 to 9 bytes, State mutable and widths decoded from loads; 4 aggregate/cast/struct-copy idioms did not resolve residue; 5 fresh directory and ov121/ov122 neighbours reread, no stack aggregate residue.
 * budget: 8 iteration runs; first nonshrinking r3, 6 runs since, consecutive r6-r8=3; reorder/temporary cap 2/2; check 3 used 1/2; baseline emission check 1; once-only permuter 300 exhausted, no improvement.
 * residual: 332/332 bytes, 9 concrete bytes differ in scheduling at +0036..0040; seven relocations resolved by fixed one.
 * permuter: macro-free emitted baseline confirmed by fixed one; search best stayed 9 bytes, exit 1; no candidate accepted.
 * wave77-runs: const Pair table cast 9/332; const signed-byte tables 9/332; direct target member assignment 9/332; check3 State *const 9/332. Three consecutive nonshrinking changes; four fixed one runs; prior 300 search not repeated.
 * checks: 1 runtime helpers remain two word arguments; 2 DE308 and sibling table callers refreshed, no interpolation twin; 3 named u16 index and State *const compiled flat9; 4 long-index/coordinate-copy scheduling idioms read; 5 fresh full directory plus DE2F0/DE300 refreshed, no stack scratch-object residue. Next hypothesis: table-index shift scheduling tie, no sweep authorized.
 * wave78: FINAL retry exhausted; named signed-long index, unsigned-long index, u16 index and State *const all flat9/332, four runs. Three nonshrinking changes; prior once300 consumed, not repeated. Best prior C retained.
 * recoup 2026-10-05 (P21L9): 332 B real extent (lane size 60 was a label gap). Residue: only +0036..0040, the case-0 shift 'lsls r2,r0,#3' (index*8) is issued before 'ldr r1,[r4,#0x1c]' in ours, after 'ldrsb' direction in the original, so startx is in r2 instead of r1. Tried, all 9 B unless noted: six per-function pragmas (lifetimes, propagation, common_subs, dead_assignments, scheduling, peephole); const on the three small tables; __restrict on out/position; Pair-array extern with p->target = tbl[i] (13 B); Pair start struct copy p->start = p->target (17 B); target.x/.y as two table reads (16 B); non-const char table (13 B); source order startx,starty first (20 B) or direction,frames first (15 B); row pointer local with struct copy (9 B) or two field copies (22 B). Idioms read: a-load-scheduled-above-an-unrelated-store, a-const-source-pointer-pulls-field-loads-up, a-local-declared-at-its-first-use, a-data-pair-load-hoisted-into-locals, a-field-read-from-a-table-folds-the-field-offset. Twin search: grep -rl _s32_div_f src/matched/ov and grep -rl 021DF944 src/matched found no interpolation twin.
 * recoup 2026-10-05 P30R2: callees (_s32_div_f, _u32_div_f) are runtime helpers, no void/arity issue. Residue unchanged, 9 B at +0036..0040 (shift index*8 issued before ldr target.x). Tried, 11 compiles: byte-offset index (d + (index << 3)) with struct copy 9 B; two int-word reads 252 B; u64 copy 31 B; copy placed before direction/frames 33 B, between direction and frames 34 B, last with starty early 20 B; frame = 0 moved after the copy 29 B or after next 21 B; startx read into a local at case start 17 B, both start locals 40 B. Best honest form kept (9 B). Idioms read again: a-load-scheduled-above-an-unrelated-store, a-local-declared-at-its-first-use. Twin search: grep -rl _s32_div_f src/matched/ov (no interpolation twin).
 * final push 2026-10-05 G3L6: 33 compiles, still 9 B (+0036..0040). New: table as 'extern const Pair' with p->target = tbl[p->index] is 9 B and replaces the char cast; non-const int/u32/u8/u16/Pair tables 13 B (final two stores swap); memcpy for the pair 340 B; inline helpers (copy, whole case 0, row accessor) 9 B; Pair start member 9 B; p->start = p->target 19 B; row pointer or local Pair at case start 259-274 B; target pointer local 270 B. Finding: shift index*8 goes late only when startx/starty stores follow the dir/frames stores (p->start = p->target), which then moves str startx late; orig has str startx at +003C and shift after the dir load, so no source order tried gives both. Pre-RA scheduler (docs/SCHEDULER.md in inspiredrobot/mwcc): shift wins on height over the target.x load in ours. Matched-asm search for the adds/ldr[r,r]/ldr[r,#4] pair plus shift and ldrsb: no twin in any listing.
 * pass 2 2026-10-06 P2L20: 40 compiles, 3 rounds, best still 9 B (form kept). Finding: the late 'lsls r2,r0,#3' in the original is a register (WAR) wait on r2, which holds target.x until 'str startx'. Closest new shape: 'x = p->target.x;' read right after the next store, startx stored after the direction statement (10 B): ldr target.x lands at +0036 in r2 as in the original, but str startx comes after strb direction, so the shift waits to +0044. Tried, all worse or equal: x/y locals before next 38-40 B; temp for next 17 B; startx later 28-31 B; startx right after x 9 B (copy propagated); x read before next 17-19 B; s8 dir temp 16 B; comma 9 B; u32 start or Pair 9-10 B; u16 index local, opt_lifetimes/opt_propagation off, function-scope x, frame after previous 10 B; Pair pos[2] 9 B; int start[2] 9 B; fieldwise table copy 22 B; int target arrays 46 B; unused label 9 B; block split before the if 265 B; #pragma scheduling off identical. Research in scratchpad wD9r/p2_P2L20/research.md.
 * pass 3 2026-10-06 P3L10: EXACT. The direction table is read through a named const table pointer
 *   assigned after x = p->target.x and before the startx store, under opt_propagation off, with the
 *   direction table extern declared const. The live table pointer holds r1 at the startx store, so x
 *   takes r2 and the index*8 shift waits for the store. Non-const table or pointer: 8 B; no pointer: 9 B.
 * symbols:
 *   MYSTERY_ALBUM_PathFrameIds 0x021DF858 data a2
 *   MYSTERY_ALBUM_PathDirections 0x021DF822 data a1
 *   MYSTERY_ALBUM_PathDurations 0x021DF82D data a1
 *   MYSTERY_ALBUM_PathWaypoints 0x021DF944 data a4
 *   _s32_div_f 0x0209C0A4 arm
 *   _u32_div_f 0x0209C2B0 arm
 * division: explicit runtime quotient preserves admitted zero-delta division.
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y; } Pair;
typedef struct {
    u16 value, previous, next;
    s8 direction;
    u8 state;
    u16 index, count;
    u32 frame, frames;
    int startx, starty;
    Pair target, current;
} State;
extern u16 MYSTERY_ALBUM_PathFrameIds[];
extern const s8 MYSTERY_ALBUM_PathDirections[];
extern s8 MYSTERY_ALBUM_PathDurations[];
extern const Pair MYSTERY_ALBUM_PathWaypoints[];
extern int _s32_div_f(int, int);
extern u32 _u32_div_f(u32, u32);
#pragma opt_propagation off
int MYSTERY_ALBUM_PathAnimStep(State *p, u16 *out, Pair *position)
{
    int result = 0;
    switch (p->state) {
    case 0: {
        const s8 *t;
        int x;
        p->frame = 0;
        p->previous = p->next;
        p->next = MYSTERY_ALBUM_PathFrameIds[p->index];
        x = p->target.x;
        t = MYSTERY_ALBUM_PathDirections;
        p->startx = x;
        p->direction = t[p->index];
        p->frames = MYSTERY_ALBUM_PathDurations[p->index];
        p->starty = p->target.y;
        p->target = MYSTERY_ALBUM_PathWaypoints[p->index];
        if (p->direction > 0) {
            p->previous = p->previous == 0xffff ? 0 : p->previous;
            p->next = p->next == 0 ? 0xffff : p->next;
        } else {
            p->previous = p->previous == 0 ? 0xffff : p->previous;
            p->next = p->next == 0xffff ? 0 : p->next;
        }
        p->state++;
        break;
    }
    case 1: {
        int x = p->startx;
        int delta = p->target.x - x;
        int sign = _s32_div_f(delta < 0 ? -delta : delta, delta);
        int y, dy;
        if (delta < 0) delta = -delta;
        p->current.x = x + sign * _u32_div_f(p->frame * delta, p->frames);
        y = p->starty;
        dy = p->target.y - y;
        if (dy < 0) dy = -dy;
        p->current.y = y + sign * _u32_div_f(p->frame * dy, p->frames);
        if (p->frame++ >= p->frames) {
            p->value = p->next;
            p->current = p->target;
            p->state++;
        }
        break;
    }
    case 2:
        p->index++;
        if (p->index < p->count) p->state = 0;
        else p->state++;
        break;
    case 3:
        result = 1;
        break;
    }
    if (out) *out = p->value;
    if (position) *position = p->current;
    return result;
}
#pragma opt_propagation reset

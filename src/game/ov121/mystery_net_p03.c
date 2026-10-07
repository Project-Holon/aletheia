/*
 * file:     mystery_net_p03.c
 * unit:     yes
 * function: func_021DE0DC, func_021DE128, func_021DE154, func_021DE2A0, func_021DE2F0, func_021DE300
 * address:  0x021DE0DC
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_02040588 0x02040588 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021DF858 0x021DF858 data a2
 *   d_021DF822 0x021DF822 data a1
 *   d_021DF82D 0x021DF82D data a1
 *   d_021DF944 0x021DF944 data a4
 *   _s32_div_f 0x0209C0A4 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02030734 0x02030734 arm
 *   func_021DEE68 0x021DEE68 thumb ov121
 *   func_021DE618 0x021DE618 thumb ov121
 *   d_021DFBC0 0x021DFBC0 data ov121 a1
 *   func_021DEE84  0x021DEE84  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021DEE90 0x021DEE90 thumb ov121
 */
#include "../../matched/include/Obj08099.h"
#include "../../matched/include/Obj13959.h"

struct Obj;
typedef unsigned short u16;

typedef struct { u16 x,y; } Point;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed char s8;

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

typedef signed int     s32;

extern void func_020414EC(unsigned);
extern void func_020409B4(unsigned);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(void *,const Point *,u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02082BCC(void *,int,u32);
extern int _s32_div_f(int, int);
extern u32 _u32_div_f(u32, u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021DEE68(void *,int,void *);
extern void func_021DE618(void);
extern void func_021DEE84(void *);
extern u32 func_020307B0(void *p);
extern void func_021DEE90(char *);
void func_021DE0DC(char *p);
void func_021DE128(u8 *p,u16 b,int c,int d);
int func_021DE154(State *p, u16 *out, Pair *position);
void *func_021DE2A0(void *arg,int heap);
void func_021DE2F0(u8 *p);
void func_021DE300(char *p);
extern u16 d_021DF858[];
extern const s8 d_021DF822[];
extern s8 d_021DF82D[];
extern const Pair d_021DF944[];
extern const char d_021DFBC0[];

void func_021DE0DC(char *p)
{
    Point pt;
    func_020414EC(4);
    func_020409B4(4);
    func_0204B3DC(((struct Obj08099 *)p)->f1C,0);
    pt.x=184;
    pt.y=112;
    func_0204B404(((struct Obj08099 *)p)->f20,&pt,((struct Obj08099 *)p)->f98);
    func_0204B3DC(((struct Obj08099 *)p)->f20,0);
    func_02040588(6,0);
}

/*
 * note pass 2 2026-10-06 P2L16: closed from 7/44. The function returns void (the only
 *   caller, ov121 021DD9CC, declares it void) and the +0 halfword is a direct copy
 *   `*(u16 *)p = *(u16 *)(p+2)` at its store position; the scheduler hoists the ldrh.
 *   The 11 store after the two b stores gives the image colours (b r7, c r4, d r6).
 *   The earlier u16 t local and return form stayed at 7 for every variant.
 */
void func_021DE128(u8 *p,u16 b,int c,int d)
{
    func_02082BCC(p,0,44);
    *(u16 *)(p+2)=b;
    *(u16 *)(p+4)=b;
    *(u16 *)(p+10)=11;
    *(int *)(p+20)=c;
    *(int *)(p+24)=d;
    *(int *)(p+28)=c;
    *(int *)(p+32)=d;
    *(u16 *)p=*(u16 *)(p+2);
    *(int *)(p+36)=c;
    *(int *)(p+40)=d;
}

#pragma opt_propagation off

/*
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
 * division: explicit runtime quotient preserves admitted zero-delta division.
 */
int func_021DE154(State *p, u16 *out, Pair *position)
{
    int result = 0;
    switch (p->state) {
    case 0: {
        const s8 *t;
        int x;
        p->frame = 0;
        p->previous = p->next;
        p->next = d_021DF858[p->index];
        x = p->target.x;
        t = d_021DF822;
        p->startx = x;
        p->direction = t[p->index];
        p->frames = d_021DF82D[p->index];
        p->starty = p->target.y;
        p->target = d_021DF944[p->index];
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

void *func_021DE2A0(void *arg,int heap)
{
    char *p;
    p=func_02030734(heap,0x17a8,0,d_021DFBC0,315);
    func_02082BCC(p,0,0x17a8);
    ((struct Obj13959 *)p)->f58=heap;
    ((struct Obj13959 *)p)->f794=arg;
    func_021DEE68(p,(int)p,func_021DE618);
    return p;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021DE2F0(u8 *p)
{
    func_021DEE84(p);
    func_020307B0(p);
}

void func_021DE300(char *p) {func_021DEE90(p);}

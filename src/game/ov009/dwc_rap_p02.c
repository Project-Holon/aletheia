/*
 * file:     dwc_rap_p02.c
 * unit:     yes
 * function: func_02155F58, func_0215610C, func_0215615C, func_021561C0, func_021562EC, func_02156330, func_02156344, func_021563C0, func_021563D0, func_021563EC, func_02156400
 * address:  0x02155F58
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_02155374  0x02155374  thumb  ov009
 *   func_02059E38  0x02059E38  arm
 *   func_02059F18  0x02059F18  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0205CC20  0x0205CC20  arm
 *   func_020111E8  0x020111E8  thumb
 *   func_0216AD50  0x0216AD50  arm  ov009
 *   func_021C5B80  0x021C5B80  arm  ov114
 *   DWC_GdbShutdown  0x021E1340  arm
 *   func_0216B838  0x0216B838  arm  ov009
 *   func_0216B94C  0x0216B94C  arm  ov009
 *   func_02176DEC  0x02176DEC  arm  ov009
 *   func_0216B908  0x0216B908  arm  ov009
 *   func_02176FD4  0x02176FD4  arm  ov009
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   func_02156CF4  0x02156CF4  thumb  ov009
 *   func_0216AE88  0x0216AE88  arm
 *   func_021567B8  0x021567B8  thumb  ov009
 *   func_021AEE14  0x021AEE14  thumb  ov013
 *   func_021AF238  0x021AF238  thumb  ov013
 *   func_02155C70  0x02155C70  thumb  ov009
 *   func_021AEF6C  0x021AEF6C  thumb  ov013
 *   func_021AF18C  0x021AF18C  thumb  ov013
 *   func_021AF13C  0x021AF13C  thumb  ov013
 *   func_021AF1A0 0x021AF1A0 thumb ov013
 */
#include "../../matched/include/Obj18650.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int (*Cb)(u32, u32, u32, int);

typedef struct {
    char pad[0x754];
    int state;          /* 0x754 */
    char pad1[0x760 - 0x758];
    int f760;           /* 0x760 */
    int n;              /* 0x764 */
    int aid;            /* 0x768 */
    int f76c;           /* 0x76c */
    char pad2[0x782 - 0x770];
    short s782;         /* 0x782 */
    int cnt[3];         /* 0x784 */
    int f790;           /* 0x790 */
    u16 h794;           /* 0x794 */
    u16 h796;           /* 0x796 */
    char pad3[0x79f - 0x798];
    u8 b79f;            /* 0x79f */
} G;

typedef signed short   s16;

typedef signed char    s8;

typedef void (*RapRecvCb)(u32, u8 *, u16);

typedef struct DwcRapWork {
    union { int hdr; u8 b[4]; } pkt;    /* 0x000 */
    u8 pktdata[0xFC];                   /* 0x004 */
    u8 *friend_list;                    /* 0x100 */
    u8 pad104[4];
    void *userdata;                     /* 0x108 */
    u8 x10C[0x174 - 0x10C];             /* 0x10C */
    void *buf[2];                       /* 0x174 */
    int arr[32];                        /* 0x17C */
    int arr2[32];                       /* 0x1FC */
    RapRecvCb cb0;                      /* 0x27C */
    RapRecvCb cb1;                      /* 0x280 */
    void (*cb284)(u32, u32);            /* 0x284 */
    u32 arg288;                         /* 0x288 */
    int (*cb28C)(u32, u32, u32, int);   /* 0x28C */
    u32 arg290;                         /* 0x290 */
    int (*cb294)(u32, u32, u32, int);   /* 0x294 */
    u32 arg298;                         /* 0x298 */
    void (*cb29C)(int, int);            /* 0x29C */
    int arg2A0;                         /* 0x2A0 */
    int (*cb2A4)(int, u32);             /* 0x2A4 */
    void (*cb2A8)(void);                /* 0x2A8 */
    char name[0x80];                    /* 0x2AC */
    u8 bytes[32];                       /* 0x32C */
    u8 ent[32][0x20];                   /* 0x34C */
    u32 w74C;                           /* 0x74C */
    int w750;                           /* 0x750 */
    int state;                          /* 0x754 */
    int err;                            /* 0x758 */
    int mode;                           /* 0x75C */
    int f760;                           /* 0x760 */
    int n;                              /* 0x764 */
    int aid;                            /* 0x768 */
    int f76c;                           /* 0x76C */
    int idx;                            /* 0x770 */
    int f774;                           /* 0x774 */
    int f778;                           /* 0x778 */
    int w77C;                           /* 0x77C */
    short s780;                         /* 0x780 */
    short s782;                         /* 0x782 */
    int cnt[3];                         /* 0x784 */
    int f790;                           /* 0x790 */
    u16 h794;                           /* 0x794 */
    u16 h796;                           /* 0x796 */
    int f798;                           /* 0x798 */
    u8 seq;                             /* 0x79C */
    u8 b79d;
    u8 b79e;
    u8 b79f;
    u8 b7a0;
    u8 b7a1;
    u8 b7a2;
    u8 b7a3;
    u8 b7a4;
    u8 b7a5;
    u8 b7a6;
    u8 b7a7;
    u8 b7a8;
    u8 b7a9;
    u8 pad7AA[2];
} DwcRapWork;

extern void func_02155374(int v);
extern int func_02059E38(int *a, int *b);
extern void func_02059F18(void);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern void func_0205CC20(void);
extern u32 func_020111E8(void);
extern void func_0216AD50(void);
extern int func_021C5B80(void);
extern void DWC_GdbShutdown(void);
extern unsigned char func_0216B838(void);
extern int func_0216B94C(u8);
extern int func_02176DEC(int a);
extern int func_0216B908(void);
extern unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size);
void func_02156CF4(void);
void func_0216AE88(void);
void func_021567B8(void);
void func_021AEE14(int);
int func_021AF238(u32 mask, int n);
void func_02155C70(void);
extern void func_021AEF6C(void *, int, int);
extern void func_021AF18C(void (*cb)(void));
extern char *func_0203D798(int a);
extern void func_021AF1A0(void);
int func_02155F58(void);
int func_0215610C(void);
int func_0215615C(u32 idx);
int func_021561C0(void);
int func_021562EC(void);
void func_0215631C(void);
void func_02156330(void);
void func_02156344(void *a);
void func_021563C0(int a);
void func_021563D0(void);
int func_021563EC(void);
void func_02156400(void);
extern u8 *g_021A8264;
extern G *d_021A8264;




/*
 * 2026-10-05 (user decision): the goto into the case 4 if-body is accepted as real source.
 * 2026-10-05 (wD9r lane158): EXACT. Shape: `ret` has no initialiser; `v = 0` at the top is the value of
 *   the early callback return (`return v;`) and of the r == 0 path. `if (r == 0) goto L;` enters case 4,
 *   where `L: ret = v;` follows the DWC_GdbShutdown call. The copy at L is needed on the r == 0 path (ret
 *   has no other definition there), so it is not a redundant statement; on the DWC path it repeats the
 *   `ret = v;` before the switch. This copy survives branch threading, so the r == 0 beq lands on case 4's
 *   join `b` as in the original. Tried and not taken: the post-switch tail as a static inline
 *   `finish(a, b, r, ret)` (432 B, same bne/b).
 * 2026-10-05 (wD9r lane143): HIDDEN SECOND RESIDUE FOUND AND FIXED. The draft also had an extra lone `b` in the
 *   case 3/6 inner switch (the 0x7A9 if-join jumped to the shared func_0205CC20 call; bne landed on that b).
 *   The original falls through: the 0x7A9 arm has no func_0205CC20 call and no break, it falls into
 *   `case 0: case 1: case 2: func_0205CC20(); break;`. Applied here (real source form). Now only the r == 0
 *   bne/b remains (code 0x19C vs 0x19A; the size shows 436 because the original's 2-byte pad absorbs it).
 *   Probes with the fall-through (scratchpad wD9r/l143): (1) w2.c = lane125's goto mechanism with
 *   `ret = v;` BEFORE the switch, `if (r == 0) goto L;`, case 4 `if (range) { DWC_GdbShutdown(); L: ret = v;
 *   goto out; }`: EXACT. Not filed: the case 4 `ret = v` repeats a value ret already holds on that path (a
 *   redundant statement, stand-in rule) and the goto enters a case body. (2) w3.c = lane125's p3 (ret = v
 *   after the switch, so the case 4 copy is not redundant) plus fall-through: 436 B, only residue is the
 *   case 1/2 cross-jump flip (case 1 jumps into case 2's `movs r0,#6; bl` instead of the reverse); case
 *   order swap moves the layout (worse), declaration order and `if (!range) break;` form of case 4 do not
 *   change it. The flip comes from the post-switch `ret = v` join block. Open: a real form with a
 *   non-redundant copy on the r == 0 edge and after the DWC call, with no copy at the main switch exit.
 * 2026-10-05 (wD9r lane125): still 4 bytes (440 vs 436). Mechanism found by probe (scratchpad wD9r/l125/p3.c):
 *   a register copy in case 4's join block survives branch threading and is removed only after colouring,
 *   so a beq into that block stays a beq onto a lone `b end`. Probe: switch value in `v` (ret = 0, v = 0 at
 *   the top), `ret = v;` after the switch, `if (r == 0) goto L;`, case 4 `if (range) { DWC_GdbShutdown();
 *   L: ret = v; goto out; } break;`: 436 B, beq onto 02156022 exactly. Residue of the probe: two cross-jump
 *   directions flip (case 1 jumps into case 2's `movs r0,#6; bl` tail instead of the reverse; the case 3/6
 *   inner switch gets an extra `b` to the shared func_0205CC20 call). Not filed: goto into a case body is not
 *   a natural form. Without the goto, an r == 0 copy block of its own is constant-folded (ret = v = 0 ->
 *   movs r6,#0, 440 B). Inline tries: range test plus DWC call as a static inline in cases 2 and 4 (void,
 *   int-returning, and early-return forms): 440 B, r5/r6 swap; switch and r test in a static inline
 *   `handle(a, b, r)` with case 4 `return v;`: the r test is not threaded (two `cmp r5,#0`), 440 B.
 *   Next: find a natural construct that puts the same non-constant copy on the r == 0 edge and after the
 *   case 4 call (identical blocks would merge), and check which cross-jump order it keeps.
 * 2026-10-05 (wD9r lane105): still 4 bytes (440 vs 436). Rescan with a fixed parser (scratchpad wD9r/l105/an.py,
 *   reads match.py listings): 674 far Thumb cond branches land on a `b`: 468 on an expansion b, 110 on a b after
 *   a b or pop, 88 on a b after an unrelated cond branch, 2 after a store or move, only 6 right after a call. The 5 matched ones are loop latches (backward, for
 *   example ov093 021EC8C4 `bls` onto the `b loop` after a call); ov121 021DC734 shows the other real cause,
 *   a suffix cross-jump that turns a join block into a lone `b` while the branch into it is kept. Ours is the
 *   only forward after-call case in the game. Tried: `do { if (r == 0) continue; ... } while (0)` (same 440,
 *   bne/b); r == 0 as the empty first arm of an if / else-if chain with the callback test (same 440);
 *   probe: a goto into case 4 followed by a duplicated `if (g[0x79E])` test with gotos to the same arms
 *   (beq does land on 02156022, but mwcc does not cross-jump blocks that end in a conditional, 448 B);
 *   probe: the same dead store in the r == 0 path and after the DWC call (removed early, threaded, 440).
 *   Open idea: an identical statement in the r == 0 path and after the DWC call that survives cross-jumping
 *   and then vanishes (coalesced copy); no natural source found. Draft code unchanged.
 * 2026-10-05 (wD9r lane83): still 4 bytes (440 vs 436). Callee prototypes from matched definitions:
 *   func_021C5B80 (ov114) returns int, DWC_GdbShutdown (ov175 021E1340) returns int, func_020111E8 returns
 *   u32; all three applied: same 440 B (kept the draft's void externs). Tried: `if (r == 0) goto tail;`
 *   with case 4 ending `goto tail;` (both edges to one label): same bne/b. Scan of asm/overlays: 483 far
 *   Thumb conditional branches land on a `b`; in matched code the reused `b` is always itself the kept
 *   `bcc body; b far` form of another far branch (ov186 021FFC9C: beq and bhi reuse the else-if's b at
 *   021FFD1A, not the earlier case-end b's; ov011 02172D70 0x2172DBE expands although a b is in range).
 *   Probe with cases 1 and 2 deleted: the beq still expands, no join `b` after a call is reused. So the
 *   original 02156022 b was not a plain join b at branch-fix time; source form still unknown.
 * 2026-10-05 (wD9r lane65): still 4 bytes (440 vs 436). Twin search: no matched function with this
 *   callee set (021552E8 and 02156690 call func_02059E38 but are different shapes). Tried: case 4 as
 *   `if (out of range) break; DWC_GdbShutdown(); break;` and as two nested ifs (both 440 B, same bne/b);
 *   a dead local store and `ret = ret` after the switch with case 4 last, as a probe for a non-empty
 *   join block (both 440 B, same bne/b, so an early-emptied block is not the cause); `if (r == 0) goto L;`
 *   with `L:` inside case 4's if-body followed by a written-out copy of the post-switch tail (probe):
 *   the beq then lands at the right place (after the DWC call) and the range fails go to the main tail as
 *   in the original, but mwcc does not cross-jump the multi-block tail copy (504 B with `return`, 464 B
 *   with `goto out`). Not a real source form; reverted to the draft code.
 * 2026-10-05 (wD9r lane52): still 4 bytes (440 vs 436). Tried: the callbacks and the switch in two
 *   separate `if (r != 0)` blocks, so the first block's r == 0 edge reaches a second test that the
 *   compiler could thread into a different block: 444 B, worse (case 4's DWC_GdbShutdown tail is
 *   duplicated and r4/r5 swap). Reverted to the draft code.
 * 2026-10-05 (wD9r lane25): still 4 bytes (440 vs 436). Tried: case 4 moved to the end of the switch with no break,
 *   so that its call falls into the switch exit, which is also the exit of `if (r != 0)` (one shared join block):
 *   same 440 B, the r == 0 edge still threads to end (bne/b).
 * 2026-10-05 (wD9r lane09): still 4 bytes (bne/b, 440 vs 436). Tried: the switch result in a second variable
 *   (`v = a; if (a == 0 || b == 1) v = r; switch ...; ret = v;` inside the r != 0 block) so that a copy sits
 *   at the join: coalesced, same bne/b. Confirmed mwcc does no island reuse in our build (three `b end` are in
 *   range of the r == 0 branch and none is used), so the original IR edge targets case 4's join block.
 * 2026-10-05 (wD9 lane08): still 4 bytes. Reading: in range of the beq there are three `b end`
 *   (02155FF0, 02156022, 02156028); only 02156022 (case 4 join) is a block that holds nothing but
 *   the goto, so the r == 0 edge reached that block in the IR (or a tail merge of identical
 *   [copy; goto end] blocks put it there). Our build has the same block at the same place and
 *   still emits bne/b. No new source form tested closes it.
 * 2026-10-05 (wave D7 lane 18): still 4 bytes. Reading: the original beq lands on the `b end`
 *   that is the fall-through of case 4's DWC_GdbShutdown call (the bgt/blt range fails go straight
 *   to end), so the r == 0 edge targeted the block after that call. Tried: `if (r == 0) goto skip;`
 *   with `skip:` inside case 4's if-body right after the call (threaded to end, same bne/b, 440 B).
 * 2026-10-05 (wave D6 lane 19): still 4 bytes (bne/b instead of beq onto case 4's `b end`).
 *   Tried: `if (r == 0) { } else { ... }` (empty then-arm, same bne/b). The r == 0 target is
 *   threaded to the tail before range fixing in every form so far.
 *
 * note (2026-10-04, wave D3 lane 13): complete draft, only residue is the first
 *   branch after func_02059E38: original is `beq 0x2156022` (a short branch to the
 *   `b end` that closes case 4), ours is `bne body; b end` (+4 bytes, 440 vs 436).
 *   Everything after matches instruction for instruction modulo that shift.
 *   Tried: `if (r == 0) goto tail;` plus a tail label (same output).
 *   Idea left: find what makes mwcc retarget a far beq to an existing b-trampoline.
 * note (2026-10-05, D4-11): still 4 bytes (beq onto case 4's `b end`). Tried: `goto skip`
 *   with the label inside case 4 before its break (threaded to end, same output); the
 *   post-switch tail written out in the r == 0 arm (504 bytes, no cross-jump); an
 *   `else { ret = 0; }` / `else { ret = r; }` arm (still bne/b, worse).
 * note (2026-10-05, D5-15): still 4 bytes. mwcc threads the branch to `end` without
 *   checking range, so the original beq target must have held code at threading time
 *   that a later pass removed (or a cross-jump merged a separate `b end` block into
 *   case 4's tail). Tried: `do { if (r == 0) break; ... } while (0)` and again
 *   `goto skip` with `skip: break;` after case 4's if (both bne/b, 440 bytes).
 *
 * 2026-10-05 (wD8 lane09): still 4 bytes. New reading of the jump table: [0]->end, 1->02155FD8, 2->02155FF2,
 *   3,6->0215602A, 4->02156012, 5->02156024, 7->02156092. The beq target 02156022 is the join block of case 4's
 *   range if (its range-fail edges go straight to end). Case 5's `b end` at 02156028 is also in range but is not
 *   used, so the r == 0 edge targets that join block in the IR and is not an island reuse. No new form found.
 */
int func_02155F58(void)
{
    int a, b;
    int r;
    u32 ret;
    u32 v = 0;
    Cb cb;

    r = func_02059E38(&a, &b);
    if (r == 0) goto L;
    cb = *(Cb *)(g_021A8264 + 0x294);
    if (cb != 0) {
        if (cb(*(u32 *)(g_021A8264 + 0x298), a, b, r) == 1)
            return v;
    }
    cb = *(Cb *)(g_021A8264 + 0x28C);
    if (cb != 0)
        cb(*(u32 *)(g_021A8264 + 0x290), a, b, r);
    v = a;
    if (a == 0 || b == 1)
        v = r;
    ret = v;
    switch (b) {
    case 1:
        func_02059F18();
        if (g_021A8264 != 0 && *(u32 *)(g_021A8264 + 0x754) == 0xE)
            func_02155374(6);
        break;
    case 2:
        if (a <= -40000 && a >= -41999)
            DWC_GdbShutdown();
        if (g_021A8264 != 0 && *(u32 *)(g_021A8264 + 0x754) == 0xE)
            func_02155374(6);
        break;
    case 4:
        if (a <= -40000 && a >= -41999) {
            DWC_GdbShutdown();
        L:
            ret = v;
        }
        break;
    case 5:
        func_021C5B80();
        break;
    case 3:
    case 6:
        if (g_021A8264 != 0) {
            switch (*(u32 *)(g_021A8264 + 0x754)) {
            case 3: case 6: case 7: case 8: case 9: case 10: case 11:
            case 14: case 18: case 19: case 20:
                if (g_021A8264[0x7A9] == 1) {
                    func_0216AD50();
                    g_021A8264[0x7A9] = 0;
                }
                /* fall through */
            case 0: case 1: case 2:
                func_0205CC20();
                break;
            default:
                break;
            }
        }
        if (g_021A8264 != 0)
            func_02155374(0x10);
        break;
    case 7:
        if (g_021A8264 != 0) {
            Cb f;
            func_02155374(0x11);
            f = *(Cb *)(g_021A8264 + 0x2A8);
            if (f != 0)
                ((void (*)(int))f)(-a);
        }
        break;
    default:
        break;
    }
    if (g_021A8264[0x79E] != 0) {
        ret = 0x3EE;
        func_0203C9AC(a, b, r, ret);
    } else if (*(u32 *)(g_021A8264 + 0x754) == 0x14) {
        ret = 0x3F0;
        func_0203C9AC(a, b, r, ret);
    } else if (r != 0) {
        func_0203C9AC(a, b, r, 0);
        func_020111E8();
    }
    return ret;
}




int func_0215610C(void)
{
    int i;
    int found = 0;
    for (i = 0; i < *(int *)(g_021A8264 + 0x764); i++) {
        if (i != func_0216B838() && func_0216B94C(i)) {
            found = 1;
            if (func_02176DEC((u8)i) == 0) {
                return 0;
            }
        }
    }
    return found;
}




int func_0215615C(u32 idx)
{
    if (*(u32 *)(g_021A8264 + 0x760) == 0 && func_0215610C() != 0
        && (func_0216B908() & 0xFFFE) != 0) {
        *(u32 *)(g_021A8264 + 0x760) = 1;
        *(u32 *)g_021A8264 = ((u32)*(u16 *)(g_021A8264 + 0x794) << 8) | 2;
        func_02176FD4(func_0216B908(), g_021A8264, 4);
        *(u32 *)(g_021A8264 + idx * 4 + 0x784) = 0;
        return 1;
    }
    return 0;
}




int func_021561C0(void)
{
    G *g;
    int i;

    func_02156CF4();
    func_0216AE88();
    func_021567B8();
    if (d_021A8264->f76c != 0) {
        int v;
        if (d_021A8264->h794 == 1 && d_021A8264->f790 == 1 && d_021A8264->h796 == 1)
            v = 0;
        else
            v = 1;
        func_021AEE14(v);
        g = d_021A8264;
        if (g->aid != func_0216B908() && g->b79f == 0 && g->s782 != 0) {
            if (func_021AF238(func_0216B908(), func_0216B838()) != 0)
                d_021A8264->aid = func_0216B908();
        }
    }
    if (d_021A8264->state == 0x14) {
        int r = func_02155F58();
        if (r == 0)
            return 0x3eb;
        return r;
    }
    if (d_021A8264->state == 0x13)
        return 0x3ec;
    if (d_021A8264->state == 9 || d_021A8264->state == 10) {
        for (i = 0; i < d_021A8264->n; i++) {
            if (d_021A8264->cnt[i]++ >= 0xf0 && d_021A8264->f760 == 0 && func_0215615C(i) != 0) {
                func_02155C70();
                break;
            }
        }
    }
    return func_02155F58();
}




/*
 * Three functions: 0x021562EC, 0x0215631C, 0x02156330.
 */
int func_021562EC(void)
{
    u8 *g = g_021A8264;
    if (g != 0) {
        u32 s = ((struct Obj18650 *)g)->f754;
        if (s == 9 || s == 10 || s == 0x12) {
            return func_0216B838();
        }
    }
    return -1;
}




void func_0215631C(void)
{
    *(u32 *)(g_021A8264 + 0x76c) = 0;
}




void func_02156330(void)
{
    *(u16 *)(g_021A8264 + 0x794) = 1;
}




/*
 *   unit src/matched/ov/ov009_func_021562EC.c contains 0215631C and02156330,
 *   but its function: header lists only021562EC, so its shard cannot attest
 *   0215631C. Owner correction: one comma-separated function: value listing
 *   func_021562EC, func_0215631C, func_02156330, then verify that unit shard.
 *   021AF18C (ov013) is an unlabelled setter; no leaf filed while the existing
 *   unit metadata blocker remains. No ARM9 blocker.
 *   The old note had the switch mapping wrong: 0,1,5,default -> 4; 2 -> 1;
 *   3 -> 2; 4 -> 3, and case 5 needs its own arm (the table's lone `b`).
 *
 * 2026-10-04 (wave D2 lane 04): unit header of ov009_func_021562EC.c corrected to list
 * func_021562EC, func_0215631C, func_02156330 (shard needs regen by the integrator).
 * The remaining blocker is 0x021AF18C in ov013 (pengy's overlay, not touched).
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Only open reloc is THM_CALL func_021AF18C (ov013, pengy's overlay,
 * unlabelled Thumb setter `ldr r1,=A; ldr r2,[r1]; ldr r1,=B; str r0,[r2,r1]; bx lr`, mis-listed as ARM by show). Not filed here.
 *
 * 2026-10-05 (wD8 lane09): re-run, still MATCH. Only open relocation: THM_CALL func_021AF18C (ov013,
 *   pengy's overlay, no witness). Not a same-overlay leaf, so no witness filed.
 */
void func_02156344(void *a)
{
    u32 v;
    *(u16 *)(g_021A8264 + 0x794) = 1;
    *(u32 *)(g_021A8264 + 0x790) = 1;
    *(u16 *)(g_021A8264 + 0x796) = 1;
    if (*(u32 *)(g_021A8264 + 0x76c) == 0) {
        v = 1;
        switch (*(u32 *)(g_021A8264 + 0x77c)) {
        case 2:
            v = 1;
            break;
        case 3:
            v = 2;
            break;
        case 4:
            v = 3;
            break;
        case 5:
            v = 4;
            break;
        default:
            v = 4;
            break;
        }
        func_021AEF6C(a, v, 1);
        func_021AF18C(func_0215631C);
        *(u32 *)(g_021A8264 + 0x76c) = 1;
    }
}




/*
 * Halfword at +0x56 of the block func_0203D798 returns, passed on.
 */
void func_021563C0(int a)
{
    func_02156344((void *)(*(unsigned short *)(func_0203D798(a) + 0x56)));
}



/*
 * Calls the ov013 routine when the word at +0x76c of the module pointer is set.
 */
void func_021563D0(void)
{
        void func_021AF13C(void);
    if (d_021A8264->f76c) func_021AF13C();
}


/*
 * Unlabelled accessor blocking owned ov099 caller 021BFDA8.
 */
int func_021563EC(void) {
 return d_021A8264->f76c;
}


void func_02156400(void)
{
    func_021AF1A0();
    if (d_021A8264) {
        d_021A8264->f76c = 0;
        d_021A8264->aid = 0;
        d_021A8264->h794 = 0;
    }
}

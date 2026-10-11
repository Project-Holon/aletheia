/*
 * file:     btl_server_p16.c
 * unit:     yes
 * function: func_021C8E58, func_021C8F24, func_021C8FA4, func_021C9010, func_021C9068
 * address:  0x021C8E58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C8F14  0x021C8F14  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5C30  0x021D5C30  thumb  ov093
 *   func_021C20BC  0x021C20BC  thumb  ov093
 *   func_021C20D0  0x021C20D0  thumb  ov093
 *   func_021C5A1C  0x021C5A1C  thumb  ov093
 *   func_021C5A34  0x021C5A34  thumb  ov093
 *   func_021C70E4  0x021C70E4  thumb  ov093
 *   func_021C8F94  0x021C8F94  thumb  ov093
 *   func_021C5B74  0x021C5B74  thumb  ov093
 *   func_021C195C  0x021C195C  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021D55D8  0x021D55D8  thumb  ov093
 *   func_021C6080  0x021C6080  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C0898  0x021C0898  thumb  ov093
 *   func_021C7194  0x021C7194  thumb  ov093
 *   func_021C2128  0x021C2128  thumb  ov093
 *   func_021C56A8 0x021C56A8 thumb ov093
 *   func_021C5620 0x021C5620 thumb ov093
 *   func_021C9168 0x021C9168 thumb ov093
 *   func_021C8810 0x021C8810 thumb ov093
 */
#include "../../matched/include/Obj00003.h"

struct UtilWork;
struct Msg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6; u16 h8; u8 ba; u8 bb;
} Ent_021C8E58;

typedef struct {
    u32 w; u8 n; u8 b5; u8 b6; u8 ids[9]; u32 v[4];
} Ent_021C8F24;

typedef struct { int pad0; int pad1; char *f8; } P;

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 rest : 19;
    u8 b4; u8 b5; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6;
} Ent_021C8FA4;

typedef struct {
    u32 w; u8 b4; u8 b5; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6;
} Ent_021C9010;

struct Slot { u32 kind : 3; u32 rest : 29; };

struct Msg {
    u16 a; u16 kind : 8; u16 n : 7; u16 flag : 1;
    u8 data[0x1c]; u32 w20;
};

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    int value;
    u8 targets[12];
    u8 count;
    u8 flag;
    u8 gap[2];
    struct Msg msg;
} Ent;

extern u8 *func_021B9934(char *p, int i);
extern int func_021C8F14(int a, u8 b);
extern int func_021D5B68(void *p);
extern int func_021D5C30(struct UtilWork *p);
extern int func_021C20BC(u8 *p, u8 *a, int r);
extern int func_021C20D0(u8 *p, u8 *a, int c, u8 *l);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021C5A34(u8 *p, u8 *a);
extern void func_021C70E4(u8 *p, int a, int b, int c, int e, u32 f);
extern int func_021C8F94(int a, u8 b);
extern void func_021C5B74(u8 *p, u8 *a, int c, int d);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern int func_021D5B7C(void *m);
extern int func_021D55D8(u8 *p, int i, int s);
extern void func_021C6080(u8 *p, u8 *a, int b, int c, int d);
extern int func_021C99A0(void *w, const struct Msg *m);
extern int func_021C0898(u8 *p, u8 *a, u32 b, u32 c);
extern int func_021C7194(u8 *p, u8 *a, u32 v);
extern int func_021C2128(u8 *p, u8 *a);
extern int func_021C56A8(u8 *, int *);
extern void func_021C5620(u8 *, u8 *, int, struct Slot *);
extern int func_021C9168(int, struct Slot, u8 *, unsigned long, struct Msg *);
extern void func_021C8810(u8 *p);
int func_021C8E58(int p, const Ent_021C8E58 *e);
int func_021C8F24(P *pp, const Ent_021C8F24 *e);
int func_021C8FA4(int p, const Ent_021C8FA4 *e);
int func_021C9010(int p, const Ent_021C9010 *e);
u8 func_021C9068(u8 *p, const Ent *e, u16 arg);



int func_021C8E58(int p, const Ent_021C8E58 *e)
{
    int a;
    u8 *b;
    u32 i;

    if (func_021C8F14(p + 0x1ab8, e->b6)) {
        a = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b6);
        b = 0;
        i = e->idx;
        if (i != 0x1f)
            b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)i);
        if (func_021D5B68((void *)a) == 0) {
            if (!e->f7a || func_021D5C30((struct UtilWork *)a) == 0) {
                if (func_021C20BC((u8 *)p, (u8 *)a, e->h4)) {
                    if (e->fl)
                        func_021C5A1C((u8 *)p, b);
                    if (e->f7b)
                        func_021C70E4((u8 *)p, e->h8, e->ba, e->bb, 0, 0);
                    func_021C20D0((u8 *)p, (u8 *)a, e->h4, (void *)((u8 *)e + 0xc));
                    if (e->fl)
                        func_021C5A34((u8 *)p, b);
                    return 1;
                }
            }
        }
    }
    return 0;
}



int func_021C8F24(P *pp, const Ent_021C8F24 *e)
{
    int p = (int)pp;
    int r = 0;
    u32 i;
    u8 *a;

    for (i = 0; i < e->n; i++) {
        if (func_021C8F94(p + 0x1ab8, e->ids[i])) {
            a = func_021B9934(pp->f8, e->ids[i]);
            if (func_021D5B68(a) == 0) {
                func_021C5B74((u8 *)p, a, e->v[i], !e->b5);
                if (e->b6 == 0)
                    func_021C195C((u8 *)p, a, 1);
                r = 1;
            }
        }
    }
    return r;
}




int func_021C8FA4(int p, const Ent_021C8FA4 *e)
{
    u8 *a;
    int r;

    func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)e->idx);
    a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b5);
    if (func_021D5B7C(a) || e->f7b) {
        r = !e->f7a;
        if (func_021D55D8(a, e->b6, r) == 0) {
            func_021C6080((u8 *)p, a, e->b6, e->b4, r);
            func_021C99A0((void *)p, (void *)((u8 *)e + 8));
            return 1;
        }
    }
    return 0;
}




int func_021C9010(int p, const Ent_021C9010 *e)
{
    int a;

    a = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b5);
    if (func_021D5B68((void *)a) == 0 || e->f7b) {
        if (func_021C0898((u8 *)p, (u8 *)a, e->b6, e->b4)) {
            func_021C99A0((void *)p, (void *)((u8 *)e + 8));
            if (func_021C7194((u8 *)p, (u8 *)a, e->b6))
                func_021C2128((u8 *)p, (u8 *)a);
        }
        return 1;
    }
    return 0;
}



/*
 * checks: 1 own B9934/C5620/C56A8/C99A0 bodies rederived, original
 *   B9934 narrowing and five-argument 9168 veneer setup preserved;
 *   2 matched C8E58/C8FA4 bodies refreshed, no exact twin;
 *   3 full-word unsigned-long veneer argument compiles unchanged at256/18;
 *   4 long-index, loop-invariant and typed-address idioms read;
 *   5 full idiom directory relisted, C8FA4 refreshed, Slot frame agrees.
 * residual: 256/256 bytes, 8 concrete bytes; 13/13 relocations resolve.
 *   Only the pool load + adds r7 (p+0x1ae4) versus movs #1/str result order at +70..76 differs.
 * retry: wave76 R8,4 compiles. Long arg and long i each retain18;
 *   integer-spelled msg address hoists both addresses and regresses to73;
 *   three nonshrinking changes stopped iteration; check 3 wide veneer
 *   argument retains18. Pointer msg spelling restored in best C.
 * permuter: prior once300 --types consumed; expand(work x3) improved64
 *   to18 and match.py agreed. No search repeated. Prior inner work local,
 *   enum arg and redundant work assignment gave65/18/64 respectively.
 * proof: original passes the full fourth argument word; no narrowing,
 *   volatile, invented defaults or altered control flow accepted.
 * recoup 2026-10-05 (lane X6, no pending file existed; started from the
 *   docs/notes draft, 18 B off, 12 compiles): callee return types checked,
 *   all match the draft (B9934 u8*, 5A1C/5A34/5620 void, 56A8 int, 99A0 int,
 *   8810 void, 195C void); 9168 is a veneer, no definition. Tried:
 *   (1) arg as u16/u8 with u16 callee param: store of r2 moves to the top of
 *   the entry (original has it after the first lsls), 18 B, other residue same;
 *   arg as int: same as unsigned long, 18 B. (2) work address in a local w
 *   (struct Msg *): compiler hoists msg and w to the for-body top, 64 B.
 *   (3) result as int: 32 B (extra uxtb at return). (4) result = 1 before msg:
 *   22 B. (5) const Ent *e, pragma scheduling off, opt_lifetimes off: 18 B
 *   unchanged. opt_propagation off: 198 B. (6) callee B9934 declared (char *,
 *   int): drops the u8 narrowing, 225 B. (7) idx in a u8 local: 18 B.
 *   Residue: entry spill str r2,[sp,#8] sits after the first lsls in the
 *   original, after the call args in ours; and the pool load + adds r7 for
 *   p+0x1ae4 comes before movs #1/str result in the original, after it in ours.
 *   Idioms read: a-later-parameters-width-reorders-the-entry-spill-stores,
 *   a-copy-and-a-pointer-step-hoisted-above-a-call-are-written-before-it,
 *   a-local-declared-at-its-first-use-schedules-its-store-there,
 *   a-spilled-pointer-plus-constant-argument-is-the-sum-stored-in-the-local,
 *   a-const-record-pointer-moves-the-outgoing-stack-store-below-the-register-copies.
 * final push 2026-10-05 G5L5 (37 compiles, 3 rounds, 18 B -> 8 B): the entry spill residue is closed
 *   by the shape of matched func_021C9250 (same prologue): p as u8 * with raw offsets
 *   (*(char **)(p + 8), p + 0x1ae4), const Ent *e, u16 arg with the callee still taking unsigned long.
 *   Any one of the three alone keeps 18 B (struct p with const e and u16 arg: 18 B; u16 arg without const e: 18 B).
 *   Remaining: the original computes the work address (ldr pool; adds r7) before movs #1/str result;
 *   ours emits the loop-invariant store first. Tried with no change (8 B): result = 1 at the top, the end,
 *   after func_021C5620 or inside the do body (the store is hoisted to the same place); a named work
 *   local (u8 *w = p; w += 0x1ae4 before result) is propagated, a typed Msg * local hoists the msg and
 *   work setup to the top of the for body (54 to 64 B); &p[0x1ae4] and a struct view; callee 9168 with const
 *   Msg *; pragmas scheduling, opt_lifetimes, opt_common_subs off (8 B each); opt_propagation off (188 B);
 *   while (k) form instead of if + do-while (146 to 154 B); int result with return (u8) (22 B).
 *   Matched-assembly search for ldr pool; adds rN,r5,r0; movs; str over ov093.s: only this function.
 *   Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register (no change),
 *   opt-propagation-off-with-named-locals-pins-argument-constants-against-stack-stores (188 B).
 * pass 2 2026-10-06 P2L18: EXACT (256/256). The work buffer passed to func_021C9168 is a named
 *   local w assigned at the top of the do body and used only in that call; the two calls after it
 *   spell p + 0x1ae4 again (they CSE onto w), and result = 1 is written after the if/else in the
 *   body. Both named assignments are hoisted into the inner preheader in source order (w before
 *   result), which gives the original pool load + adds r7 before movs #1/str. A w used in all three
 *   calls is hoisted out of the outer for loop (54 B); the expression form puts the hoisted
 *   address after result (8 B).
 */
u8 func_021C9068(u8 *p, const Ent *e, u16 arg)
{
    const struct Msg *msg;
    u8 *first;
    u8 result;
    unsigned long i;
    u8 *a;
    int value;
    int k;
    struct Slot slot;
    struct Msg *w;
    first = (u8 *)func_021B9934(*(char **)(p + 8), (u8)e->idx);
    result = 0;
    if (e->fl) func_021C5A1C(p, first);
    for (i = 0; i < e->count; i++) {
        a = (u8 *)func_021B9934(*(char **)(p + 8), (u8)e->targets[i]);
        if (func_021D5B7C(a)) {
          value = e->value;
          k = func_021C56A8(a, &value);
          if (k) {
          msg = &e->msg;
          do {
            w = (struct Msg *)(p + 0x1ae4);
            func_021C5620(p, a, k, &slot);
            if (!e->flag) {
                if (func_021C9168(k, slot, a, arg, w)) {
                    func_021C99A0(p, (struct Msg *)(p + 0x1ae4));
                    func_021C8810((u8 *)(p + 0x1ae4));
                }
            } else {
                func_021C99A0(p, msg);
            }
            result = 1;
            if (k == 0x13) func_021C195C(p, a, 0);
            k = func_021C56A8(a, &value);
          } while (k);
          }
        }
    }
    if (e->fl) func_021C5A34(p, first);
    return result;
}

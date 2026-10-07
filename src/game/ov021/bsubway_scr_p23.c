/*
 * file:     bsubway_scr_p23.c
 * unit:     yes
 * function: func_021CB86C, func_021CB8AC, func_021CB914, func_021CB934, func_021CB9BC, func_021CB9E4, func_021CBBA0, func_021CBBAC, func_021CBBD0, func_021CBC14, func_021CBC94, func_021CBCC4, func_021CBD08, func_021CBD84, func_021CBD90, func_021CBED8, func_021CBEFC, func_021CBF38, func_021CBF98
 * address:  0x021CB86C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED8  0x02012ED8  thumb
 *   func_02158FE0  0x02158FE0  thumb  ov010
 *   func_02167D00  0x02167D00  thumb  ov010
 *   func_0203D378  0x0203D378  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02167B18  0x02167B18  thumb  ov010
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215A684  0x0215A684  thumb  ov010
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb
 *   func_02190BE4  0x02190BE4  thumb
 *   func_02190C78  0x02190C78  thumb
 *   func_021909BC  0x021909BC  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0200DF94  0x0200DF94  thumb
 *   func_0200DFB4  0x0200DFB4  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0216CE6C  0x0216CE6C  thumb  ov010
 *   func_0216D620  0x0216D620  thumb  ov010
 *   func_0216D5B4  0x0216D5B4  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_0200DB80  0x0200DB80  thumb
 *   d_021DADD0     0x021DADD0  data  a2
 *   d_021DAD48     0x021DAD48  data  a2
 *   d_021DAD5C     0x021DAD5C  data  a2
 *   d_021DAEBC     0x021DAEBC  data  a2
 *   d_021DADF8     0x021DADF8  data  a4
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   data_021DAEBC  0x021DAEBC  data
 *   func_0200B6E0  0x0200B6E0  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_021CA210  0x021CA210  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_021681C8  0x021681C8  thumb  ov010
 *   _s32_div_f  0x0209C0A4  arm
 *   d_021DB3D0  0x021DB3D0  data
 *   d_021DB3D8  0x021DB3D8  data
 *   d_021DB3E4  0x021DB3E4  data
 *   d_021DB3F4  0x021DB3F4  data
 *   func_02168878  0x02168878  thumb  ov010
 *   func_021688BC  0x021688BC  thumb  ov010
 *   func_021684E8  0x021684E8  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 */
#include "../../matched/include/Obj20240.h"
#include "../../matched/include/Obj12974.h"
#include "../../matched/include/Obj12976.h"

struct Big;
struct Ctx;
struct Obj;
struct Desc;
struct Handle;
struct Blk1AC;
struct Sub020071CCCtrl;
struct Buf3FC;
struct RecSlot;
struct SubEnt;
struct Party;
struct PartyMon;
struct Bs;
struct Rec;
struct BattleMon;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8  pad0[0xc];
    u16 lo   : 9;
    u16 flag : 1;
    u16 hi   : 6;
} Owner;

typedef int (*TaskFn)(void *task, int *state, void *work);

typedef struct {
    void *owner;
    u16 *result;
    u32 screen;
    u32 arg;
} Work;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct {
    s16 x;
    s16 pad0;
    s16 y;
    s16 pad1;
} Pt;

typedef struct {
    u16 id;
    u16 idx;
    s16 x;
    u16 pad6;
    s16 y;
    u16 k;
    u32 padc;
} Ent;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
} Flags;

typedef struct {
    u8  pad0[0xa];
    u16 fa;
    u16 fc;
    u16 fe;
} Entry;

typedef struct {
    u8  pad0[0xc];
    u16 lo  : 5;
    u16 sel : 3;
    u16 hi  : 8;
} Sel;

typedef struct {
    u16 lo;
    u16 hi;
} Range;

typedef struct {
    u8 raw[0x3c];
} BattleMon;

typedef struct {
    u32 otId;
    u16 member[2];
    u32 pid[2];
} Rec;

extern void *func_0215A5F4(void *p);
extern void *func_02158F54(void *a);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012ED8(struct Big *p);
extern u16 *func_02158FE0(void *a, void *b, unsigned int id);
extern int func_02167D00(struct Obj *o, u16 *out);
extern u32 func_0203D378(void);
extern void func_0203D7BC(u8 a0);
extern void func_02167B18(void *p);
extern int func_0203D1B4(void);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0215A684(int *p, unsigned short v);
extern int func_0215A690(char *a0);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(void *a);
extern u16 func_02188C9C(u8 *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern struct Buf3FC *func_0200DF58(struct RecSlot *p, u32 heap);
extern u32 func_0200DF94(struct Buf3FC *b);
extern u32 func_0200DFB4(struct SubEnt *e);
extern void *func_0216CE6C(void *o, int x, int y, u16 d, u32 a, u32 b, u32 c, u32 e);
extern int func_0216D620(int a0, int a1, int a2);
extern void func_0216D5B4(void *h, u16 v);
extern u32 func_020307B0(void *p);
extern u16 func_0200DB80(struct Blk1AC *p, u32 i);
extern int func_0216D63C(char *a0, int a1);
extern u32 func_0200B6E0(void *a, u16 b, u32 c, u32 d, u32 e, u16 *state, u16 *sub);
extern struct Party *func_0201A920(u32 heap);
extern void *func_021CA210(u8 *p);
extern void func_0201A954(struct Party *p, s32 capacity);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern struct Bs *func_021681C8(void *sys, void *partyA, u32 mode0, struct Rec *recA, struct Rec *recB, int n);
extern u8 func_02168878(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_021688BC(u8 *party, int id, u16 heap);
extern u32 func_021684E8(struct BattleMon *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap);
extern u32 func_020056EC(u32 max);
extern u32 _u32_div_f(u32 a, u32 b);
int func_021CB86C(u32 unused, u32 a);
int func_021CB8AC(void *task, int *state, Owner **work);
void *func_021CB914(void *a, u32 owner);
int func_021CB934(void *task, int *state, Work *w);
void *func_021CB9BC(void *a, u32 owner, u32 result, u32 arg);
void func_021CB9E4(u8 *p, void *a1, void *a2, void *a3);
u32 func_021CBBA0(u32 a);
u32 func_021CBBAC(u8 *p, u32 idx);
void func_021CBBD0(u8 *p, u32 idx, u16 *a, u16 *b, u16 *c);
int func_021CBC14(u32 unused, u32 a);
int func_021CBC94(u32 kind);
int func_021CBCC4(void *p);
u32 func_021CBD08(u8 *p, int a);
void *func_021CBD84(void *a);
u16 func_021CBD90(void *ctx, u32 round, u32 stage, u32 line, u8 alt);
u8 func_021CBED8(u32 unused, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
u8 func_021CBEFC(u32 v);
void func_021CBF38(void *unused, u8 *party, int id, int useItem, Rec *rec, u16 heap);
u16 func_021CBF98(void *ctx);
extern const Pt d_021DADD0[];
extern const u16 d_021DAD48[];
extern const u16 d_021DAD5C[];
extern const Ent d_021DAEBC[];
extern const u32 d_021DADF8[];
extern const Entry data_021DAEBC[];
extern const Range d_021DB3D0[];
extern const Range d_021DB3D8[];
extern const Range d_021DB3E4[];
extern const Range d_021DB3F4[];


int func_021CB86C(u32 unused, u32 a)
{
    void *t;
    void *s;
    u8 *p;
    u16 *q;

    s = func_0215A5F4((void *)a);
    t = func_020120F4(func_02158F54(s));
    p = func_02012ED8(t);
    q = func_02158FE0(s, t, ((struct Obj20240 *)p)->f72A);
    if (func_02167D00((struct Obj *)p, q) == 1)
        return 1;
    return 0;
}


/*
 * Task step: closes the message window, optionally resumes the field, then waits for the save to finish.
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 * The caller leaves the owner pointer in r0 for func_02167B18, so the extern
 * keeps one (ignored) parameter.
 *
 * Addresses are Black-image addresses.
 */
int func_021CB8AC(void *task, int *state, Owner **work)
{
    switch (*state) {
    case 0:
        if (func_0203D378() == 1)
            func_0203D7BC(0);
        if ((*work)->flag == 1)
            func_02167B18(*work);
        (*state)++;
        break;
    case 1:
        if (func_0203D378() == 1) {
            if (func_0203D1B4() <= 1) {
                func_0203CEAC(0);
                (*state)++;
            }
        } else {
            func_0203CEAC(0);
            (*state)++;
        }
        break;
    case 2:
        if (func_0203CDBC() == 1)
            return 1;
        break;
    }
    return 0;
}


/*
 * Starts the task 0x021CB8AC with a one-word work area holding the owner.
 *
 * Addresses are Black-image addresses.
 */
void *func_021CB914(void *a, u32 owner)
{
    void *task = func_020122C0(a, 0, (TaskFn)func_021CB8AC, 4);
    *(u32 *)func_020124E8(task) = owner;
    return task;
}


/*
 * Task step: fades out, runs the ov021 sub-screen on the +0xc argument, stores whether it was cancelled at *w[1].
 *
 * Addresses are Black-image addresses.
 */
int func_021CB934(void *task, int *state, Work *w)
{
    func_0215A5F4(w->owner);
    switch (*state) {
    case 0:
        func_0215A684(w->owner, 8);
        (*state)++;
    case 1:
        if (func_0215A690(w->owner) == 1) {
            w->screen = (u32)func_02190BE4((u16 *)func_02188C54(func_0201210C(func_0215A5DC(w->owner))), w->arg);
            (*state)++;
        }
        break;
    case 2:
        switch (func_02190C78((struct Handle *)w->screen)) {
        case 0:
            *w->result = 0;
            (*state)++;
            break;
        case 2:
            break;
        default:
            *w->result = 1;
            (*state)++;
            break;
        }
        break;
    case 3:
        func_021909BC((void *)w->screen);
        return 1;
    }
    return 0;
}


void *func_021CB9BC(void *a, u32 owner, u32 result, u32 arg)
{
    void *task = func_020122C0(a, 0, (TaskFn)func_021CB934, 0x10);
    u32 *w = func_020124E8(task);

    w[0] = owner;
    w[1] = result;
    w[3] = arg;
    return task;
}


/*
 * Spawns the marker objects for mode byte +9: in mode 4 up to five from the
 * 0x3B record list (newest first), otherwise every 0x021DAEBC entry whose
 * threshold equals the step count. The u16 accessor result held in a u32
 * local is what puts it in the top spill slot (a u16 or int local takes the
 * lowest). Unlabelled follower: 0x021CBBA0 (already filed).
 *
 * Addresses are Black-image addresses.
 */
void func_021CB9E4(u8 *p, void *a1, void *a2, void *a3)
{
    int i;
    u16 slot;
    u32 zone;
    u8 kind;
    const Pt *pt;
    u8 *list;
    u32 n;
    u8 *e;
    u16 v;
    void *h;
    u16 cnt;
    const Ent *ent;

    i = 0;
    zone = func_02188C9C(a3);
    slot = 0x80;
    kind = p[9];
    if (kind == 4) {
        pt = d_021DADD0;
        list = (u8 *)func_0200DF58(func_020071CC(func_02012EBC(a1), 0x3B), (int)4);
        n = func_0200DF94((struct Buf3FC *)list);
        if (n != 0) {
            e = list + (n - 1) * 0x22;
            while (n != 0 && i < 5) {
                u32 r = func_0200DFB4((struct SubEnt *)e) % 10;
                if (((Flags *)(e + 0x20))->b1 == 0)
                    v = d_021DAD48[r];
                else
                    v = d_021DAD5C[r];
                h = func_0216CE6C(a2, pt->x, pt->y, i % 4, slot, v, 2, zone);
                func_0216D620((int)h, (u16)(n - 1), 0);
                func_0216D5B4(h, 5);
                e -= 0x22;
                i++;
                slot++;
                pt++;
                n--;
            }
        }
        func_020307B0(list);
        return;
    }
    ent = d_021DAEBC;
    cnt = func_0200DB80(((struct Obj12974 *)p)->f74, kind);
    switch (kind) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        cnt += 3;
        break;
    }
    while (ent->id != 0xFFFF) {
        if (cnt == d_021DADF8[ent->idx - 1]) {
            h = func_0216CE6C(a2, ent->x, ent->y, i % 4, slot, ent->id, 2, zone);
            func_0216D620((int)h, (u16)i, 0);
            func_0216D620((int)h, (u16)ent->k, 1);
            func_0216D5B4(h, 5);
            if (slot < 0xFF)
                slot++;
        }
        ent++;
        i++;
    }
}


/*
 * Tail call into ov010 with a fixed second argument of 1 (unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBBA0(u32 a)
{
    return func_0216D63C((char *)a, 1);
}


/*
 * Whether entry idx of the 16-byte table at 0x021DAEBC is available (never for kind 4; unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBBAC(u8 *p, u32 idx)
{
    const Entry *e = &data_021DAEBC[idx];

    if (p[9] == 4)
        return 0;
    if (e->fe != 0)
        return 1;
    return 0;
}


/*
 * Reads the three halfwords of table entry idx, or the empty triple (0, 0, 4) (unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
void func_021CBBD0(u8 *p, u32 idx, u16 *a, u16 *b, u16 *c)
{
    const Entry *e = &data_021DAEBC[idx];

    if (p[9] == 4) {
        *a = 0;
        *b = 0;
        *c = 4;
        return;
    }
    if (e->fe == 0) {
        *a = 0;
        *b = 0;
        *c = 4;
        return;
    }
    *a = e->fa;
    *b = e->fc;
    *c = e->fe;
}


/*
 * Shows the kind's message (20/21/22) with the +0x10 number capped at 9999 and reports whether it ended with 2 or 3.
 *
 * Addresses are Black-image addresses.
 */
int func_021CBC14(u32 unused, u32 a)
{
    void *t;
    u8 *p;
    int id;
    int v;
    int r;

    t = func_020120F4(func_02158F54(func_0215A5F4((void *)a)));
    p = func_02012ED8(t);
    id = 20;
    v = ((struct Obj12976 *)p)->f10;
    switch (p[9]) {
    case 0:
    case 4:
    case 5:
        break;
    case 1:
    case 6:
        id = 21;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        id = 22;
        break;
    }
    if (v > 9999)
        v = 9999;
    r = func_0200B6E0(t, 4, id, v, 0, (u16 *)(p + 0x7e8), (u16 *)(p + 0x7ea));
    if (r == 2 || r == 3)
        return 1;
    return 0;
}


/*
 * Maps a kind 0..8 to the message id 20, 21 or 22.
 * Addresses are Black-image addresses.
 */
int func_021CBC94(u32 kind)
{
    int id = 20;

    switch (kind) {
    case 0:
    case 4:
    case 5:
        break;
    case 1:
    case 6:
        id = 21;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        id = 22;
        break;
    }
    return id;
}


/*
 * Maps the owner's mode 0x43..0x49 to a small index.
 *
 * Addresses are Black-image addresses.
 */
int func_021CBCC4(void *p)
{
    u16 m = func_02188C9C(p);
    int r = 0;

    switch (m) {
    case 0x43:
        r = 0;
        break;
    case 0x44:
        r = 5;
        break;
    case 0x45:
        r = 1;
        break;
    case 0x46:
        r = 6;
        break;
    case 0x47:
        r = 2;
        break;
    case 0x48:
        r = 7;
        break;
    case 0x49:
        r = 4;
        break;
    }
    return r;
}


/*
 * Builds a party list from the selected slots and runs the ov010 summary on it.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBD08(u8 *p, int a)
{
    void *list = func_0201A920(0x8004);
    void *h = func_021CA210(p);
    int i;
    u32 r;

    func_0201A954(list, p[8]);
    for (i = 0; i < p[8]; i++)
        func_0201A98C(list, func_0201AB28(h, p[0x1e + i]));
    r = (u32)func_021681C8((void *)a, list, p[9], (struct Rec *)(p + 0x88), (struct Rec *)(p + 0x2c8 + ((Sel *)p)->sel * 0x120), p[8]);
    func_020307B0(list);
    return r;
}

/*
 * Unlabelled leaf in ov021 (printed as a `.word` run at 0x021CBD84); the
 * matching byte at 0x021CBD8C is the pool word 0x0000074C.  Six-byte
 * accessor reached from ov010's func_0216CAD4 across the overlay pair.
 */
void *func_021CBD84(void *a)
{
    return (char *)a + 0x74c;
}


static inline u16 RandInRange(void *ctx, u32 tbl, u32 round)
{
    u16 span = ((const Range *)(tbl + round * 4))->hi - ((const Range *)(tbl + round * 4))->lo + 1;
    return func_021CBF98(ctx) % span + ((const Range *)(tbl + round * 4))->lo;
}


/*
 * Picks a battle-subway trainer id: the fixed boss ids on the boss round, otherwise a random id from the per-round range table of the line (normal or super, early or late stages).
 *
 * Each table arm calls the random-range helper with the table address cast to
 * an integer. A shared `const Range *tbl` local is a named variable and takes
 * the first callee-saved register (r4) ahead of the scaled index and the span;
 * per-arm calls leave the base as a short-lived load that colours after them
 * (r6, with round*4 in r4 and span in r5), and the arms' identical tails are
 * cross-jumped into one block. The integer base keeps `tbl + off` then `+2`
 * for hi instead of folding the field offset into a second pool word
 * (d_X + 2), and loads the base before the index shift. 0x0209C0A4 is
 * _s32_div_f, so the u16 % u16 modulo is signed (int promotion).
 *
 * Addresses are Black-image addresses.
 */
u16 func_021CBD90(void *ctx, u32 round, u32 stage, u32 line, u8 alt)
{
    int super;
    int boss;
    u16 id;

    id = 0;
    super = 0;
    boss = -1;

    switch (line) {
    case 5:
    case 6:
    case 7:
    case 8:
        super = 1;
        break;
    }

    if (stage == 6) {
        if (!super) {
            if (round == 2)
                boss = 0;
        } else {
            if (round == 6)
                boss = 1;
        }
    }

    if (boss != -1) {
        switch (line) {
        case 0:
        case 5:
            if (boss == 0)
                id = 0x132;
            else if (boss == 1)
                id = 0x133;
            break;
        case 1:
        case 6:
            if (boss == 0)
                id = 0x134;
            else if (boss == 1)
                id = 0x135;
            break;
        case 2:
        case 3:
        case 7:
        case 8:
            if (boss == 0) {
                if (alt == 0)
                    id = 0x137;
                else
                    id = 0x136;
            } else if (boss == 1) {
                if (alt == 0)
                    id = 0x139;
                else
                    id = 0x138;
            }
            break;
        }
    } else if (!super) {
        if (round >= 3)
            goto end;
        if (stage < 6) {
            id = RandInRange(ctx, (u32)d_021DB3D8, round);
            goto end;
        }
        if (round >= 2)
            goto end;
        id = RandInRange(ctx, (u32)d_021DB3D0, round);
    } else {
        if (round >= 4)
            goto rnd;
        if (stage < 6) {
            id = RandInRange(ctx, (u32)d_021DB3E4, round);
            goto end;
        }
        id = RandInRange(ctx, (u32)d_021DB3F4, round);
        goto end;
rnd:
        id = func_021CBF98(ctx) % 100 + 200;
    }
end:
    return id;
}


/*
 * Forwarder into ov010 that drops the first argument and returns its byte result.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021CBED8(u32 unused, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g)
{
    return func_02168878(a, b, c, d, e, f, g);
}


/*
 * Maps a value to a bracket 3..31 in steps of 20.
 * Addresses are Black-image addresses.
 */
u8 func_021CBEFC(u32 v)
{
    if (v < 100)
        return 3;
    if (v < 120)
        return 6;
    if (v < 140)
        return 9;
    if (v < 160)
        return 12;
    if (v < 180)
        return 15;
    if (v < 200)
        return 18;
    if (v < 220)
        return 21;
    return 31;
}


/*
 * Builds the two battle-subway opponent mons at +0x30 of the party block from a trainer record.
 *
 * Addresses are Black-image addresses.
 */
void func_021CBF38(void *unused, u8 *party, int id, int useItem, Rec *rec, u16 heap)
{
    u8 iv;
    void *buf;
    int i;

    buf = func_021688BC(party, id, heap);
    iv = func_021CBEFC(id);

    for (i = 0; i < 2; i++)
        func_021684E8((struct BattleMon *)((BattleMon *)(party + 0x30) + i), rec->member[i], rec->otId, rec->pid[i], iv, i, useItem, heap);
    func_020307B0(buf);
}


/*
 * A 16-bit random value: the arm9 random source scaled down by 0xFFFF.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021CBF98(void *ctx)
{
    return func_020056EC(0xffffffff) / 0xffff;
}

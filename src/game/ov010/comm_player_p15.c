/*
 * file:     comm_player_p15.c
 * unit:     yes
 * function: func_02168C74, func_02168CF4, func_02168D30, func_02168E5C, func_02168EB0, func_02168EEC
 * address:  0x02168C74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02167EF4  0x02167EF4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0201210C 0x0201210C thumb
 *   func_021681C8 0x021681C8 thumb ov010
 *   func_0216E910 0x0216E910 thumb ov010
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 *   func_02012444 0x02012444 thumb
 *   d_021BA39C 0x021BA39C data ov220 a4
 *   ov220_id 0x000000DC data
 *   func_02008B14  0x02008B14  thumb
 *   func_0203F49C  0x0203F49C  arm
 *   func_02168F54  0x02168F54  thumb
 *   func_02008BE0  0x02008BE0  thumb
 *   func_02169068  0x02169068  thumb
 *   func_02169004  0x02169004  thumb
 */
#include "../../matched/include/Obj04944.h"

struct Evt;
struct Bs;
struct Ctx;
struct Rec;
struct Big;
struct Desc;
struct Obj;
struct Sub0200852CObj;
struct Sub02008AECSession;
struct RtcDate;
struct RtcTime;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
    u16 *fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    u32 f30;
} C;

typedef unsigned char u8;

typedef enum { KIND_OFF = 0x12c } Offset;

typedef struct {
    u8 pad[0x124];
    int count;
    void *save;
    Offset kind;
} Record_02168CF4;

typedef struct Result {
    u8 pad00[0x24];
    void *party;        /* 0x24 */
    u8 pad28[0xB4 - 0x28];
    u16 fb4;            /* 0xB4 */
    u8 fb6[11];         /* 0xB6 */
} Result;

typedef struct Record_02168D30 {
    u8 pad000[0x134];
    u16 f134[10];       /* 0x134 */
    u16 f148;           /* 0x148 */
    u16 f14a;           /* 0x14A */
} Record_02168D30;

extern int func_02167EF4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_020307B0(void *p);
extern void *func_0201210C(const struct Ctx *p);
extern struct Bs *func_021681C8(void *sys, void *partyA, u32 mode0, struct Rec *recA, struct Rec *recB, int n);
extern int func_0216E910(void *, void *, void *);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E8F8(void *sys);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern void func_0203F49C(struct RtcDate *date, struct RtcTime *time);
extern int func_02168F54(int *, int *, int *, int *, int *);
extern void func_02008BE0(struct Sub02008AECSession *s, u32 n);
extern void func_02169068(int, int, int *);
extern void func_02169004(int, int);
int func_02168C74(int a, int *b, C *c);
int func_02168CF4(void *a, Record_02168CF4 *p);
void func_02168D30(Record_02168D30 *r, Result *s);
int func_02168E5C(int a, int b, int c);
int func_02168EB0(void *a, int *state);
void func_02168EEC(int a);
extern const unsigned int d_021BA39C[];
extern unsigned char ov220_id[];



/*
 * Battle state step: state 0 starts the request and moves to state 1; state 1 releases the
 * object and stores the result flag. The flag store is written in each arm of the if/else
 * (2026-10-05 recoup), which keeps the store before the epilogue add sp.
 */
int func_02168C74(int a, int *b, C *c)
{
    int r0 = c->f0;
    switch (*b) {
    case 0: {
        int t = func_02167EF4(r0, c->f10, 0x17, c->f14, c->f18, (int)(&c->f28), (int)(&c->f20), (int)(&c->f24), *(int *)(c->f30 + 0x128));
        func_02012374((struct Evt *)a, (struct Evt **)t);
        *b = 1;
        break;
    }
    case 1:
        if (c->f1c != 0)
            func_020307B0((void *)c->f1c);
        if (c->f24 != 0 || (u32)(c->f20 - 7) <= 1)
            *c->fc = 0;
        else
            *c->fc = 1;
        return 1;
    }
    return 0;
}

/*
 * accepted 2026-10-05 by the user: the held form (see the notes below) is accepted as plausible original source.
 * recoup 2026-10-05 (P21L10): extent 60 B includes a 2-byte pad (movs r0,r0); code is 58 B.
 * The old draft (12 B off, only the ldr r2 position and the lsls/adds r6 order) closed by
 * dropping const from the record pointer and the byte-pointer casts: EXACT* in c99 and c.
 * Not filed as matched: the Offset enum local (off = KIND_OFF, then off - 4, off - 8) is only
 * there to stop mwcc folding 0x12c into the load offsets. With int k or a plain int typedef,
 * literals, struct fields or a named kind local the compiler folds to a 0x49 base (40 B off).
 * A human reason for the held 0x12c is not known; integrator decides. Callee func_021681C8
 * has u8 kind/n params in the ov021 twin caller but this caller passes full words (no
 * truncation), so the prototype here is int. pragmas scheduling/peephole/opt_lifetimes off:
 * no change on the old const form (12 B). unsigned kind: 15 B.
 */
int func_02168CF4(void *a, Record_02168CF4 *p)
{
    void *b;
    Offset kind;
    Offset off;
    b = func_0201210C(a);
    off = KIND_OFF;
    kind = (Offset)*(int *)((u8 *)p + off);
    return func_0216E910(a, b, func_021681C8(a, *(void *const *)((u8 *)p + (off - 4)), kind, (struct Rec *)p, 0, *(int *)((u8 *)p + (off - 8))));
}


/*
 * Add one battle's tallies into the running record and credit the
 * score share against the party's summed stat 0xA1. First draft.
 */
void func_02168D30(Record_02168D30 *r, Result *s)
{
    void *party;
    int n;
    int i;
    int sum;

    r->f134[0] += (u16)(s->fb6[0] + 1);
    r->f134[1] += s->fb6[1];
    r->f134[2] += s->fb6[2];
    r->f134[3] += s->fb6[3];
    r->f134[4] += s->fb6[4];
    r->f134[5] += s->fb6[5];
    r->f134[6] += s->fb6[6];
    r->f134[7] += s->fb6[7];
    r->f134[8] += s->fb6[8];
    r->f134[9] += s->fb6[9];
    r->f14a += s->fb6[10];
    party = s->party;
    n = func_0201AA18(party);
    sum = 0;
    for (i = 0; i < n; i++)
        sum += func_02017E1C(func_0201AB28(party, i), 0xA1, 0);
    r->f148 += (u16)(s->fb4 * 100 / sum);
}


int func_02168E5C(int a, int b, int c)
{
    int x = (int)func_020120F4((const struct Ctx *)a);
    int h = (int)func_020122C0((void *)a, 0, func_02168EB0, 0x18);
    int *p = func_020124E8((struct Obj *)h);
    p[0] = a;
    p[1] = (int)func_0201210C((void *)a); /* int-typed on purpose: field is int in record */
    ((struct Obj04944 *)p)->f8 = func_02008550((const struct Sub0200852CObj *)func_02012944((void *)x));
    p[3] = (int)func_0200E8F8(func_02012EBC((struct Big *)x));
    p[4] = b;
    p[5] = c;
    return h;
}

/*
 * former blocker: pooled ov220_id is passed to func_02012444 r1, missing from
 * OVERLAY_ID_CONSUMERS. Its matched body stores a1 to payload[0]; matched
 * func_0201240C forwards item[0] as func_020120B4 r1 (known consumer).
 * The ov220 table hint is supported by that load chain; matcher refuses
 * it as contested until the ID site resolves. No code leaf blocks this.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_02168EB0(void *a, int *state)
{
    u8 *p;
    p = func_020124E8(a);
    switch (*state) {
    case 0:
        func_02012444(a, (unsigned int)ov220_id, (unsigned int)d_021BA39C, (unsigned int)(p + 8));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}


void func_02168EEC(int a)
{
    int A[4];
    int B[3];
    int y;
    int x;
    int *p = (int *)func_02008B14(func_02012EBC((struct Big *)a));
    if (*p == 0)
        return;
    func_0203F49C((struct RtcDate *)A, (struct RtcTime *)B);
    if (func_02168F54(p, A, B, &y, &x) == 0)
        return;
    if (x == 0 && y != 0)
        return;
    if (x != 0) {
        func_02008BE0((struct Sub02008AECSession *)p, x);
        func_02169068(a, x, B);
    }
    if (y != 0)
        func_02169004(a, y);
}

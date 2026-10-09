/*
 * file:     comm_player_p03.c
 * unit:     yes
 * function: func_021688BC, func_02168924, func_02168AC8, func_02168AEC, func_02168B18, func_02168B20, func_02168BBC, func_02168BF0, func_02168C74, func_02168CF4, func_02168D30, func_02168E5C, func_02168EB0, func_02168EEC
 * address:  0x021688BC
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
 *   func_02045B38  0x02045B38  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216880C  0x0216880C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A38  0x02045A38  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02168824  0x02168824  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02168800  0x02168800  thumb  ov010
 *   func_0216883C  0x0216883C  thumb  ov010
 *   func_021684E8  0x021684E8  thumb  ov010
 *   g_0217208C  0x0217208C  data  ov010  a2
 *   g_0217208E  0x0217208E  data  ov010  a2
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CCC  0x02188CCC  thumb ov021
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02012158  0x02012158  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_021A0F7C  0x021A0F7C  thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02012934  0x02012934  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_02167EF4  0x02167EF4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021681C8 0x021681C8 thumb ov010
 *   func_0216E910 0x0216E910 thumb ov010
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
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
#include "../../matched/include/Obj12052.h"
#include "../../matched/include/Obj04944.h"

struct MsgBank;
struct Rec;
struct U16Vec;
struct Ctx;
struct Comm;
struct IcaAnime;
struct Desc;
struct Obj;
struct Big;
struct BigObj;
struct Evt;
struct Bs;
struct Sub0200852CObj;
struct Sub02008AECSession;
struct RtcDate;
struct RtcTime;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    int f0;
    u16 f4;
    u16 f6;
    u8 f8[16];
    u16 f18;
    u16 f1a;
} Blk;

typedef struct FacRec {
    u16 species;        /* 0x00 */
    u16 moves[4];       /* 0x02 */
    u8 evMask;          /* 0x0A */
    u8 nature;          /* 0x0B */
    u16 item;           /* 0x0C */
    u16 form;           /* 0x0E */
} FacRec;

typedef struct FacGroup {
    u16 id;             /* 0x00 */
    u16 count;          /* 0x02 */
    u16 members[1];     /* 0x04 */
} FacGroup;

typedef struct FacDraw {
    u32 otId;           /* 0x00 */
    u16 ids[2];         /* 0x04 */
    u32 pids[2];        /* 0x08 */
    u8 natures[2];      /* 0x10 */
} FacDraw;

typedef struct BattleMon {
    u8 data[0x3C];
} BattleMon;

typedef enum { ST_0, ST_1, ST_2, ST_3, ST_4, ST_5 } State;

typedef struct {
    void *f0;
    void *f4;
    int f8;
    u16 *fc;
    int f10;
    int f14;
    void *f18;
    void *f1c;
    u32 pad[4];
    int f30;
} R;

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

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02082BCC(void *, int, int);
extern void *func_0216880C(u32 group, u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045A38(struct U16Vec *, u16 *, u32);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern int func_02168824(void);
extern void func_02168800(void *dst, u32 member);
extern u8 func_0216883C(u32 n);
extern u32 func_021684E8(BattleMon *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap);
extern void *func_0201210C(const struct Ctx *);
extern u32 func_02188CCC(u8 *p);
extern unsigned int func_02012138(const struct Ctx *);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern void func_02012158(char *p, unsigned int v);
extern u32 func_020121CC(struct IcaAnime *p);
extern int func_021A0F7C(u32 a, u32 b, u32 c, u32 d);
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *p);
extern void *func_0200BAF4(int a0, int a1);
extern int func_02167EF4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_020307B0(void *p);
extern struct Bs *func_021681C8(void *sys, void *partyA, u32 mode0, struct Rec *recA, struct Rec *recB, int n);
extern int func_0216E910(void *, void *, void *);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_0200E8F8(void *sys);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern void func_0203F49C(struct RtcDate *date, struct RtcTime *time);
extern int func_02168F54(int *, int *, int *, int *, int *);
extern void func_02008BE0(struct Sub02008AECSession *s, u32 n);
extern void func_02169068(int, int, int *);
extern void func_02169004(int, int);
u16 *func_021688BC(Blk *a, int b, int c);
int func_02168924(FacGroup *group, u16 rank, BattleMon *mons, int count, u16 *exclSpecies, u16 *exclItems, FacDraw *draw, u16 heap);
int func_02168AC8(int a0);
u16 func_02168AEC(u16 a0);
void func_02168B18(int *p);
int func_02168B20(int a, int *b, int *c);
void *func_02168BBC(void *a, void *b);
struct Desc *func_02168BF0(int a, int b, int c, int d, u16 *e);
int func_02168C74(int a, int *b, C *c);
int func_02168CF4(void *a, Record_02168CF4 *p);
void func_02168D30(Record_02168D30 *r, Result *s);
int func_02168E5C(int a, int b, int c);
int func_02168EB0(void *a, int *state);
void func_02168EEC(int a);
extern u16 g_0217208C[];
extern u16 g_0217208E[];
extern const unsigned int d_021BA39C[];
extern unsigned char ov220_id[];




u16 *func_021688BC(Blk *a, int b, int c)
{
    int h = (int)func_02045B38(0, 2, 11, c);
    u16 *r;
    int t;
    func_02082BCC(a, 0, 0x120);
    r = func_0216880C(b, c);
    a->f0 = b + 1;
    a->f18 = 0xFFFF;
    a->f1a = b * 3;
    a->f4 = *r;
    t = (int)func_02045EC0((struct MsgBank *)h, b);
    func_02045A38((struct U16Vec *)t, (u16 *)a->f8, 16);
    func_02045808((struct U16Vec *)t);
    func_02045C04((struct Rec *)h);
    return r;
}




/*
 * Draws `count` distinct battle-facility Pokemon from an a/2/1/5 group
 * list (func_0216880C's record): no repeated species, none of the
 * excluded species, and for the first 50 tries no repeated or excluded
 * held item. Builds each one with func_021684E8 under one random trainer
 * id and optionally reports the first two draws. Returns 1 when the
 * item rule had to be dropped.
 *
 * Levers: locals declared in reverse of their frame order (the arrays
 * after natures, the scalars from otId down), the IV step as u8 (its
 * reader returns only constants up to 31), and a 16-bit `rank` parameter,
 * which moves the r1 spill ahead of the r3 copy (u8 matches equally; int
 * and u32 are 4 bytes out).
 */
int func_02168924(FacGroup *group, u16 rank, BattleMon *mons, int count, u16 *exclSpecies, u16 *exclItems, FacDraw *draw, u16 heap)
{
    u8 natures[4];
    int ids[4];
    u32 pids[4];
    FacRec other;
    FacRec rec;
    u32 otId;
    u8 iv;
    int id;
    int tries;
    int fail;
    int i;
    int n;

    fail = 0;
    tries = 0;
    n = 0;
    while (n != count) {
        id = group->members[(u8)(func_02168824() % group->count)];
        func_02168800(&rec, id);
        for (i = 0; i < n; i++) {
            func_02168800(&other, ids[i]);
            if (other.species == rec.species)
                break;
        }
        if (i != n)
            continue;
        if (exclSpecies != 0) {
            for (i = 0; i < count; i++) {
                if (rec.species == exclSpecies[i])
                    break;
            }
            if (i != count)
                continue;
        }
        if (tries < 50) {
            for (i = 0; i < n; i++) {
                func_02168800(&other, ids[i]);
                if (other.item != 0 && other.item == rec.item)
                    break;
            }
            if (i != n) {
                tries++;
                continue;
            }
            if (exclItems != 0) {
                for (i = 0; i < count; i++) {
                    if (rec.item == exclItems[i] && exclItems[i] != 0)
                        break;
                }
                if (i != count) {
                    tries++;
                    continue;
                }
            }
        }
        ids[n] = id;
        natures[n] = rec.nature;
        n++;
    }

    iv = func_0216883C(rank);
    otId = func_02168824() | (func_02168824() << 16);
    if (tries >= 50)
        fail = 1;
    for (i = 0; i < n; i++)
        pids[i] = func_021684E8(&mons[i], (u16)ids[i], otId, 0, iv, i, fail, heap);
    if (draw == 0)
        return fail;
    draw->otId = otId;
    for (i = 0; i < 2; i++) {
        draw->ids[i] = ids[i];
        draw->pids[i] = pids[i];
        draw->natures[i] = natures[i];
    }
    return fail;
}






int func_02168AC8(int a0)
{
    int a1;
    int a2;
    int a3;

a3 = 0;
loc_02168ACA:
a1 = a3 << 1;
a2 = a0 + a1;
a1 = ((struct Obj12052 *)a2)->f20;
    if (a1 == 0) goto loc_02168AD8;
loc_02168AD4:
a0 = 1;
    return a0;
loc_02168AD8:
a1 = ((struct Obj12052 *)a2)->f28;
    if (a1 == 0) goto loc_02168AE2;
loc_02168ADE:
a0 = 1;
    return a0;
loc_02168AE2:
a3 = a3 + 1;
    if (a3 < 4) goto loc_02168ACA;
loc_02168AE8:
a0 = 0;
    return a0;}




/*
 * Recursive MATCH unblocker: ABS32 target of func_021D0BCC (ov021) +0008.
 * Coherent Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes
 * that site attest as `matched`.
 */
u16 func_02168AEC(u16 a0)
{
    u32 i;

    for (i = 0; i < 0x35; i++) {
        if (g_0217208C[i * 2] == a0)
            return g_0217208E[i * 2];
    }
    return 0xA;
}



/*
 * Unlabelled leaf callback (movs r1,#1; str r1,[r0]; bx lr); filed as the
 * sole blocker of func_02168B20 (its pool word).
 */
void func_02168B18(int *p)
{
    *p = 1;
}




/*
 * lever: 02026454 reads the live 02012138 result in r0 in cases 0 and 1.
 */
int func_02168B20(int a, int *b, int *c)
{
    int s = c[2];
    int x = func_02188CCC((u8 *)((int)func_0201210C((const struct Ctx *)s)));
    int y = func_02012138((const struct Ctx *)s);
    State t = (State)*b;
    switch (t) {
    case 0:
        if (func_02026454((void *)y) != 0)
            func_02026400((struct Comm *)y);
        (*b)++;
        break;
    case 1:
        if (func_02026454((void *)y) != 0)
            break;
        func_02012158((char *)s, 0);
        (*b)++;
        break;
    case 2:
        if (c[1] != 0) {
            func_02012158((char *)s, 1);
            func_020121CC((struct IcaAnime *)s);
        }
        (*b)++;
        break;
    case 3:
        func_021A0F7C(x, 8, (u32)func_02168B18, (u32)c);
        (*b)++;
        break;
    case 4:
        if (c[0] != 0)
            *b = t + 1;
        break;
    case 5:
        return 1;
    }
    return 0;
}



void *func_02168BBC(void *a, void *b)
{
    void *h;
    void **p;
    func_020120F4(a);
    h = func_020122C0(a, 0, func_02168B20, 0xc);
    p = func_020124E8(h);
    func_02082BCC(p, 0, 0xc);
    p[2] = a;
    p[1] = b;
    return h;
}




struct Desc *func_02168BF0(int a, int b, int c, int d, u16 *e)
{
    struct Desc *hd;
    void *h;
    R *p;
    int k;
    void *v;
    h = func_020120F4((void *)a);
    hd = func_020122C0((void *)a, 0, (void *)func_02168C74, 0x34);
    p = func_020124E8((struct Obj *)hd);
    p->f0 = (void *)a;
    p->f4 = func_0201210C((void *)a);
    p->fc = e;
    p->f30 = b;
    if (c == 0x14 || c == 0x15) {
        if (c == 0x14) {
            p->f10 = 0;
            k = 0x14;
        } else {
            p->f10 = 1;
            k = 0x15;
        }
    } else {
        p->f10 = 0;
        k = 0x14;
    }
    p->f14 = k;
    if (d == 0) {
        p->f1c = 0;
        v = func_02012934(h);
    } else {
        v = func_0200BAF4((int)func_0200BAC8(func_02012EBC(h)), 5);
        p->f1c = v;
    }
    p->f18 = v;
    return hd;
}




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

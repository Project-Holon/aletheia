/*
 * file:     worldtrade_box_p15.c
 * unit:     yes
 * function: func_021F6BFC, func_021F6C28, func_021F6C48, func_021F6C80, func_021F6CDC, func_021F6D14, func_021F6DB4, func_021F6DE8, func_021F6E08, func_021F6E58
 * address:  0x021F6BFC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F6B40  0x021F6B40  thumb
 *   func_021F8554  0x021F8554  thumb
 *   func_021F50EC  0x021F50EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02202608  0x02202608  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0200ADB4  0x0200ADB4  thumb
 *   func_021F72C4  0x021F72C4  thumb
 *   func_0200AD9C  0x0200AD9C  thumb
 *   func_02019CE0  0x02019CE0  thumb
 *   func_02034714  0x02034714  arm
 *   func_02031348  0x02031348  arm
 *   str_02203B6C   0x02203B6C  data  a1
 *   d_021E75B4     0x021E75B4  data  ov119
 *   d_021E75CC     0x021E75CC  data  ov119
 *   d_021E75FC     0x021E75FC  data  ov119
 *   ov119_id       0x00000077  data
 */
#include "../../matched/include/Obj07243.h"
#include "../../matched/include/Obj07244.h"

struct Sav;
struct Ctx_021F6E58;
struct RecDC;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

typedef signed char s8;

typedef struct {
    u16 species;
    u8 form;
    u8 gender;
} MonTag;

typedef struct {
    u16 species;
    u8 form;
    u8 b3;
    u8 b4;
} WantTag;

typedef struct {
    u8 pad0[0xCC];
    void *mon;
    u8 padD0[0xD4 - 0xD0];
    int sel;
    u8 padD8[0x20C - 0xD8];
    u8 list[1][0x128];
} Work_021F6D14;

typedef struct {
    u8 pad0[0xEC];
    MonTag have;
    WantTag want;
} Deposit;

typedef struct {
    s16 a;
    s16 b;
} Rec;

typedef struct {
    u32 f0;
    int f4;
    u8 pad8[0x20C - 8];
} Entry_021F6DB4;

typedef struct { u8 pad[12]; void *save; } Ctx_021F6E08;

typedef struct { Ctx_021F6E08 *ctx; u8 pad[0xC8-4]; unsigned count; } Work_021F6E08;

typedef struct {
    u8 pad0[0x30];
    void *f30;
    void *f34;
    void *f38;
    u32 f3C;
    void *f40;
} Req;

typedef struct {
    void *sys;
    u8 pad4[0x1C - 4];
    u32 f1C;
    u8 pad20[0x40 - 0x20];
    void *f40;
} Ctx_021F6E58;

typedef struct {
    u8 data[0x128];
} Entry_021F6E58;

typedef struct {
    Ctx_021F6E58 *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[0xB8 - 0x24];
    u32 fB8;
    u8 padBC[0xD4 - 0xBC];
    int cur;
    void *info;
    u8 padDC[0xE4 - 0xDC];
    u8 mon[0x207 - 0xE4];
    s8 f207;
    u8 pad208[0x20C - 0x208];
    Entry_021F6E58 arr[8];
    u8 padB4C[0xEA4 - 0xB4C];
    void *saveMon;
    void *fEA8;
    u8 padEAC[0x10DC - 0xEAC];
    Req *req;
    u8 pad10E0[0x12E4 - 0x10E0];
    u32 f12E4;
    u8 pad12E8[0x12F0 - 0x12E8];
    void *f12F0;
} Work_021F6E58;

extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern u32 func_02018438(void *p);
extern void func_021F8554(Deposit *dst, Work_021F6D14 *p);
extern void *func_020185F4(void *a);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern u32 func_0202136C(u16 v);
extern u8 func_020076A4(void *save);
extern int func_020078C4(void *save, unsigned i);
extern u8 func_020076B4(void *save);
extern void func_021F50EC(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02202608(u32 heap);
extern void *func_020120F4(const struct Ctx_021F6E58 *p);
extern void *func_0200ADB4(void *sys);
extern void *func_021F72C4(void *e);
extern void func_0200AD9C(void *sys, void *mon);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02031348(void *h, u32 id, void *a, void *b);
int func_021F6BFC(u32 handle);
int func_021F6C28(u32 handle);
int func_021F6C48(void *party, void *save, int box, int slot);
int func_021F6C80(void *pa, void *pb);
int func_021F6CDC(void *mon, void *want);
void func_021F6D14(Deposit *dst, Work_021F6D14 *p);
void func_021F6DB4(Rec *recs, u32 unused, void *key, Entry_021F6DB4 *ent);
int func_021F6DE8(u32 handle);
void func_021F6E08(Work_021F6E08 *p);
int func_021F6E58(Work_021F6E58 *p);
extern char str_02203B6C[];
extern u8 d_021E75B4[];
extern u8 d_021E75CC[];
extern u8 d_021E75FC[];
extern u8 ov119_id[];


/*
 * Restart the channel: stamp, force ports 5 and 0x6f to zero, hand the stamp over.
 */
int func_021F6BFC(u32 handle)
{
    u32 stamp = func_02017DBC((struct Sav *)handle);

    func_02017E88((void *)handle, 5, 0);
    func_02017E88((void *)handle, 0x6f, 0);
    func_02017DE4((struct Sav *)handle, stamp);
    return 0;
}


/*
 * Restart the channel: take a stamp, force port 6 to zero and hand the handle over.
 */
int func_021F6C28(u32 handle)
{
    u32 stamp = func_02017DBC((struct Sav *)handle);

    func_02017E88((void *)handle, 6, 0);
    func_02017DE4((struct Sav *)handle, stamp);
    return 0;
}


int func_021F6C48(void *party, void *save, int box, int slot)
{
    void *mon = func_021F6B40(party, save, box, slot);

    if (mon == 0) {
        return 0;
    }
    if (func_02017E88(mon, 0xA9, 0) == 0) {
        return 0;
    }
    if (func_02017E88(mon, 0xAA, 0) != 0) {
        return 2;
    }
    return 1;
}


int func_021F6C80(void *pa, void *pb)
{
    signed char a3;
    signed char b3;
    signed char b4;
    signed char b2;

    if (((struct Obj07243 *)pa)->f0 != ((struct Obj07244 *)pb)->f0)
        return 0;
    b2 = ((struct Obj07244 *)pb)->f2;
    if (b2 != 3 && b2 != ((struct Obj07243 *)pa)->f2)
        return 0;
    a3 = ((struct Obj07243 *)pa)->f3;
    if (a3 == 0)
        return 0;
    b3 = ((struct Obj07244 *)pb)->f3;
    if (b3 != 0 && b3 > a3)
        return 0;
    b4 = ((struct Obj07244 *)pb)->f4;
    if (b4 != 0 && b4 < a3)
        return 0;
    return 1;
}


int func_021F6CDC(void *mon, void *want)
{
    MonTag t;

    t.species = func_02017E88(mon, 5, 0);
    t.form = func_02017E88(mon, 0x6E, 0) + 1;
    t.gender = func_02018438(mon);
    return func_021F6C80(&t, want);
}


void func_021F6D14(Deposit *dst, Work_021F6D14 *p)
{
    MonTag m;
    WantTag w;
    void *e;

    m.species = func_02017E88(p->mon, 5, 0);
    m.form = func_02017E88(p->mon, 0x6E, 0) + 1;
    m.gender = func_02018438(p->mon);
    dst->have = m;
    func_021F8554(dst, p);
    e = func_020185F4(p->list[p->sel]);
    w.species = func_02017E88(e, 5, 0);
    w.form = func_02017E88(e, 0x6E, 0) + 1;
    w.b3 = 0;
    w.b4 = 0;
    dst->want = w;
}


void func_021F6DB4(Rec *recs, u32 unused, void *key, Entry_021F6DB4 *ent)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (recs[i].a != 0 && func_021F6C80(&recs[i], key) == 0) {
            ent[i].f4 += 3;
        }
    }
}


/*
 * Read port 6 and report whether the follow-up check accepted it.
 */
int func_021F6DE8(u32 handle)
{
    int ok = 0;
    u16 v = (u16)func_02017E1C((void *)handle, 6, 0);

    if (func_0202136C(v) != 0) {
        ok = 1;
    }
    return ok;
}

void func_021F6E08(Work_021F6E08 *p)
{
    unsigned i;
    p->count = func_020076A4(p->ctx->save);
    if (p->count < 24) {
        for (i = 0; i < p->count; i++) {
            if (func_020078C4(p->ctx->save, i) == 0) break;
        }
        if (i == p->count) p->count = func_020076B4(p->ctx->save);
    }
}


int func_021F6E58(Work_021F6E58 *p)
{
    Req *d;
    void *tmpl;

    func_021F50EC((u8 *)p);
    p->req = func_02030734(0x48, 0x44, 0, str_02203B6C, 0x5E);
    func_02082BCC(p->req, 0, 0x44);
    d = p->req;
    p->saveMon = func_02202608(0x48);
    d->f30 = func_020120F4(p->ctx->f40);
    d->f3C = p->ctx->f1C;
    switch (p->kind) {
    case 7:
        d->f38 = d->f34 = func_0200ADB4(p->ctx->sys);
        d->f40 = p->info = func_021F72C4(p->mon);
        tmpl = d_021E75FC;
        break;
    case 8:
        if (p->f207 != 0) {
            d->f38 = p->mon;
        } else {
            d->f38 = func_0200ADB4(p->ctx->sys);
        }
        d->f34 = d->f38;
        d->f40 = p->info = func_021F72C4(p->mon);
        tmpl = d_021E75B4;
        break;
    case 10:
        if (p->f207 != 0) {
            d->f38 = p->mon;
        } else {
            d->f38 = func_0200ADB4(p->ctx->sys);
        }
        func_0200AD9C(p->ctx->sys, p->saveMon);
        d->f34 = p->saveMon;
        d->f40 = p->info = func_021F72C4(p->mon);
        tmpl = d_021E75CC;
        break;
    case 9:
        func_02019CE0(p->fEA8, p->saveMon);
        d->f34 = p->fEA8;
        d->f38 = &p->arr[p->cur];
        d->f40 = p->info = func_021F72C4(&p->arr[p->cur]);
        tmpl = d_021E75CC;
        break;
    default:
        func_02034714((void *)0x02203B80, 0, (void *)0x02203B80);
        break;
    }
    func_02031348(p->f12F0, (u32)ov119_id, tmpl, p->req);
    p->fB8 = 1;
    p->f12E4 = 0;
    return 1;
}

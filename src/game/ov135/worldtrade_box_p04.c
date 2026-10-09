/*
 * file:     worldtrade_box_p04.c
 * unit:     yes
 * function: func_021F68A4, func_021F6B34, func_021F6B40, func_021F6B80, func_021F6BA4, func_021F6BC4, func_021F6BFC, func_021F6C28, func_021F6C48, func_021F6C80, func_021F6CDC, func_021F6D14, func_021F6DB4, func_021F6DE8, func_021F6E08, func_021F6E58, func_021F6FD4, func_021F7268, func_021F72C4, func_021F7338
 * address:  0x021F68A4
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
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02007A18  0x02007A18  thumb
 *   func_021F6748  0x021F6748  thumb
 *   func_021F67A8  0x021F67A8  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0200785C  0x0200785C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020185F4  0x020185F4  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02034714  0x02034714  arm
 *   func_02049238  0x02049238  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021F6754  0x021F6754  thumb
 *   str_02203B54   0x02203B54  data  a1
 *   tbl_02202C58  0x02202C58  data  a4
 *   func_021F8554  0x021F8554  thumb
 *   func_021F50EC  0x021F50EC  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02202608  0x02202608  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0200ADB4  0x0200ADB4  thumb
 *   func_0200AD9C  0x0200AD9C  thumb
 *   func_02019CE0  0x02019CE0  thumb
 *   func_02031348  0x02031348  arm
 *   str_02203B6C   0x02203B6C  data  a1
 *   d_021E75B4     0x021E75B4  data  ov119
 *   d_021E75CC     0x021E75CC  data  ov119
 *   d_021E75FC     0x021E75FC  data  ov119
 *   ov119_id       0x00000077  data
 *   func_021F7374  0x021F7374  thumb
 *   func_021F4EC0  0x021F4EC0  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0201B2B0  0x0201B2B0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   d_02208C40     0x02208C40  data  ov195
 *   ov067_id       0x00000043  data
 *   ov195_id       0x000000C3  data
 *   func_021F5074 0x021F5074 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_02008560  0x02008560  thumb
 *   func_02008568  0x02008568  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02008558  0x02008558  thumb
 *   func_02008574  0x02008574  thumb
 */
#include "../../matched/include/Obj07243.h"
#include "../../matched/include/Obj07244.h"
#include "../../matched/include/Obj03829.h"

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Sub020079BCEntry;
struct Obj_021F68A4;
struct Sav;
struct Ctx_021F6E58;
struct RecDC;
struct BigObj;
struct Ctx_021F6FD4;
struct Party;
struct PartyMon;
struct Sub0200852CObj;
typedef signed char s8;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u16 species;
    s8 f2;
    u8 f3;
} Info_021F68A4;

typedef struct {
    u32 vram;
    u32 pal;
    u32 spr;
    u8 pixels[0x200];
} IconRec;

typedef struct {
    u8 pad0[0xF0];
    u8 key[0x128 - 0xF0];
} Entry;

typedef struct {
    u8 pad0[8];
    void *party;
    void *storage;
} Ctx_021F68A4;

typedef struct {
    Ctx_021F68A4 *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[0xC8 - 0x24];
    u32 nbox;
    u8 padCC[0xD4 - 0xCC];
    int cur;
    u8 padD8[0x20C - 0xD8];
    Entry arr[8];
    u8 padB4C[0xB6C - 0xB4C];
    void *fB6C;
    u8 padB70[0xB80 - 0xB70];
    void *fB80;
    u8 padB84[0xC00 - 0xB84];
    u32 icon[30];
    u32 item[30];
    u32 mark[6];
    u8 padD08[0xD4C - 0xD08];
    void *fD4C;
    u8 padD50[0xEAC - 0xD50];
    Info_021F68A4 *info;
    u8 padEB0[0xEB8 - 0xEB0];
    IconRec *icons;
    void (*vblank)(void *);
    u8 padEC0[0xFA0 - 0xEC0];
    u8 fFA0[4];
} Work;

typedef signed short s16;

typedef signed int s32;

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
} Req_021F68A4;

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
    Req_021F68A4 *req;
    u8 pad10E0[0x12E4 - 0x10E0];
    u32 f12E4;
    u8 pad12E8[0x12F0 - 0x12E8];
    void *f12F0;
} Work_021F6E58;

typedef struct {
    void *f0;
    void *list;
    u16 f8;
    u8 fA;
    u8 fB;
    u32 fC;
    u32 f10;
} Req_021F6FD4;

typedef struct {
    void *save;
    u8 pad4[0x40 - 4];
    void *f40;
} Ctx_021F6FD4;

typedef struct {
    Ctx_021F6FD4 *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[0x28 - 0x24];
    int state;
    u8 pad2C[0xEA4 - 0x2C];
    void *fEA4;
    u8 padEA8[0x10DC - 0xEA8];
    Req_021F6FD4 *req;
    u8 pad10E0[0x12F0 - 0x10E0];
    void *f12F0;
    u32 busy;
    u32 f12F8;
} Obj_021F68A4;

typedef struct {
    u8 pad0[0x10];
    u32 f10;
    u32 f14;
} Info_021F72C4;

typedef struct {
    u8 pad0[0xF6];
    u8 fF6;
    u8 padF7[0x108 - 0xF7];
    u32 f108;
    u32 f10C;
    u8 name[0x120 - 0x110];
    u8 f120;
    u8 f121;
    u8 f122;
    u8 pad123;
    u8 f124;
    u8 f125;
} Entry_021F72C4;

typedef struct {
    u8 data[0x128];
} Entry_021F7338;

typedef struct {
    u8 pad0[0xD4];
    int cur;
    u8 padD8[0xE4 - 0xD8];
    Entry_021F7338 single;
    Entry_021F7338 arr[1];
} Obj_021F72C4;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void func_021F6748(u32 a, u8 *q);
extern void func_021F67A8(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, void *arc, Info_021F68A4 *info, IconRec *rec);
extern void func_0204B3DC(struct Obj_021F68A4 *, unsigned int);
extern void func_0200785C(void *save, u32 box, void *dest);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *list, u32 i);
extern void *func_020185F4(void *a);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02049238(void *h);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void func_021F6754(Work *p);
extern int func_020078C4(void *save, u32 box);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32 func_02018438(void *p);
extern void func_021F8554(Deposit *dst, Work_021F6D14 *p);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern u32 func_0202136C(u16 v);
extern u8 func_020076A4(void *save);
extern u8 func_020076B4(void *save);
extern void func_021F50EC(u8 *p);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02202608(u32 heap);
extern void *func_020120F4(const struct Ctx_021F6E58 *p);
extern void *func_0200ADB4(void *sys);
extern void func_0200AD9C(void *sys, void *mon);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern void func_02031348(void *h, u32 id, void *a, void *b);
extern void func_021F7374(Obj_021F68A4 *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern u32 func_020307B0(void *p);
extern struct Party *func_0201A920(u32 heap);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_02034A5C(s32 handle);
extern int func_02034AC4(s32 handle);
extern void func_021F5074(void *p);
extern void func_021F4EC8(u8 *p);
extern void *func_0200846C(int a0);
extern void func_020084A0(struct Sub0200852CObj *p);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_02008560(struct Sub0200852CObj *obj, u8 value);
extern void func_02008568(struct Sub0200852CObj *obj, u8 value);
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void func_02008558(struct Sub0200852CObj *obj, u8 value);
extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);
void func_021F68A4(Work *p, int box);
int func_021F6B34(int v);
void *func_021F6B40(void *party, void *save, int box, int slot);
u32 func_021F6B80(u8 *p, u32 b, u32 c);
int func_021F6BA4(void *party, void *save, int box, int slot);
u32 func_021F6BC4(void *sav);
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
int func_021F6FD4(Obj_021F68A4 *p);
int func_021F7268(u8 *p);
Info_021F72C4 *func_021F72C4(Entry_021F72C4 *e);
Entry_021F7338 *func_021F7338(Obj_021F72C4 *p, int kind);
extern char str_02203B54[];
extern const u32 tbl_02202C58[];
extern char str_02203B6C[];
extern u8 d_021E75B4[];
extern u8 d_021E75CC[];
extern u8 d_021E75FC[];
extern u8 ov119_id[];
extern u8 d_02208C40[];
extern u8 ov067_id[];
extern u8 ov195_id[];





/*
 * Build the 30 Pokemon icon slots of the screen from box `box` of the
 * storage (+0xC of the context) or, for box 0xFF, from the party (+8),
 * blanking the slots past the party size. Icon records (0x3D68 bytes,
 * +0xEB8) are uploaded later by func_021F6754, installed at +0xEBC.
 * Any other box reports through func_02034714 (raw 0x02203B68). Kind 6
 * then runs func_021F6DB4 against the current entry's key.
 */
void func_021F68A4(Work *p, int box)
{
    void *storage = p->ctx->storage;
    u16 species[30];
    void *arc;
    IconRec *icons;
    u16 i;

    icons = func_02030734(0x8001, 0x3D68, 0, str_02203B54, 0x892);
    p->icons = icons;
    arc = func_020490F4(7, 0x48);
    if (box >= 0 && box < p->nbox) {
        for (i = 0; i < 30; i++) {
            func_021F6748((u32)func_02007A18(storage, box, i), (u8 *)(&p->info[i]));
        }
        for (i = 0; i < 30; i++) {
            p->info[i].species = 0;
            func_021F67A8(func_02007A18(storage, box, i), p->icon[i], p->item[i], &species[i], i, arc, (Info_021F68A4 *)(&p->info[i]), &icons[i]);
            if (i < 6) {
                func_0204B3DC((struct Obj_021F68A4 *)p->mark[i], 0);
            }
        }
        func_0200785C(storage, box, p->fB80);
    } else if (box == 0xff) {
        int n = func_0201AA18(p->ctx->party);

        for (i = 0; i < n; i++) {
            void *mon = func_020185F4(func_0201AB28(p->ctx->party, i));

            func_021F6748((u32)mon, (u8 *)(&p->info[i]));
            func_021F67A8(mon, p->icon[i], p->item[i], &species[i], i, arc, (Info_021F68A4 *)(&p->info[i]), &icons[i]);
            func_0204B3DC((struct Obj_021F68A4 *)p->mark[i], 0);
        }
        for (; i < 30; i++) {
            p->info[i].species = 0;
            func_0204B3DC((struct Obj_021F68A4 *)p->icon[i], 0);
            func_0204B3DC((struct Obj_021F68A4 *)p->item[i], 0);
            icons[i].spr = 0;
            if (i < 6) {
                func_0204B3DC((struct Obj_021F68A4 *)p->mark[i], 0);
            }
        }
        func_02045CAC(p->fB6C, 0x62, p->fB80);
    } else {
        func_02034714((void *)0x02203B68, 0, (void *)0x02203B68);
    }
    func_02049238(arc);
    func_02043B5C(func_02045770(p->fD4C), 0);
    func_021F91A0(p->fD4C, (u32)p->fB80, 0, 5, 1, 0x440, (u32)p->fFA0);
    if (p->kind == 6) {
        func_021F6DB4((Rec *)p->info, (u32)p->icon, p->arr[p->cur].key, (Entry_021F6DB4 *)icons);
    }
    p->vblank = (void (*)(void *))func_021F6754;
}





/*
 * True only for the 0xff sentinel.
 */
int func_021F6B34(int v)
{
    if (v == 0xff) {
        return 1;
    }
    return 0;
}






void *func_021F6B40(void *party, void *save, int box, int slot)
{
    if (func_021F6B34(box) != 0) {
        if (slot > (int)func_0201AA18(party) - 1) {
            return 0;
        }
        return func_020185F4(func_0201AB28(party, slot));
    }
    return func_02007A18(save, box, slot);
}






u32 func_021F6B80(u8 *p, u32 b, u32 c)
{
    if (func_021F6B34(c) != 0) {
        return func_0201AA18(p);
    }
    return func_020078C4((void *)b, c);
}






int func_021F6BA4(void *party, void *save, int box, int slot)
{
    if (func_021F6B34(box) != 0 && (int)func_0201AA18(party) < 2) {
        return 0;
    }
    return 1;
}






u32 func_021F6BC4(void *sav)
{
    u32 f = func_02017DBC(sav);
    u32 i;
    u32 r;

    for (i = 0; i < 15; i++) {
        r = func_02017E88(sav, tbl_02202C58[i], 0);
        if (r == 1) {
            break;
        }
    }
    func_02017DE4(sav, f);
    return r;
}





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
    Req_021F68A4 *d;
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
        d->f40 = p->info = (void *)func_021F72C4((Entry_021F72C4 *)p->mon);
        tmpl = d_021E75FC;
        break;
    case 8:
        if (p->f207 != 0) {
            d->f38 = p->mon;
        } else {
            d->f38 = func_0200ADB4(p->ctx->sys);
        }
        d->f34 = d->f38;
        d->f40 = p->info = (void *)func_021F72C4((Entry_021F72C4 *)p->mon);
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
        d->f40 = p->info = (void *)func_021F72C4((Entry_021F72C4 *)p->mon);
        tmpl = d_021E75CC;
        break;
    case 9:
        func_02019CE0(p->fEA8, p->saveMon);
        d->f34 = p->fEA8;
        d->f38 = &p->arr[p->cur];
        d->f40 = p->info = (void *)func_021F72C4((Entry_021F72C4 *)(&p->arr[p->cur]));
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




/*
 * Two-state step. State 0, once the +0x12F4 busy word clears: for kind 9
 * (or kinds 8/10 when the stored entry differs from the one rebuilt from
 * the save data by func_02202608/func_0200AD9C) build a 0x14-byte request
 * (func_0201B2B0 result, list holding the entry, out byte) at +0x10DC,
 * load overlay 67 and start the overlay-195 task (d_02208C40, hinted to
 * ov195 because this function names ov195_id), then go to state 1; any
 * failure calls func_021F4EC0(p, 1, 0) and returns 3. State 1 copies the
 * result back into the entry, frees the request, refreshes the record
 * (func_021F7374), clears the DISPCNT window bits, unloads overlay 67 and
 * calls func_021F4EC0(p, 7, 0xC). Returns 2 while waiting, else 3.
 */
int func_021F6FD4(Obj_021F68A4 *p)
{
    int ret = 2;

    switch (p->state) {
    case 0:
        if (p->busy != 0) {
            break;
        }
        if (p->kind == 9) {
            void *e = (void *)func_021F7338((Obj_021F72C4 *)p, p->kind);
            u32 out;
            u32 r;

            func_02017E1C(e, 6, 0);
            r = func_0201B2B0(0, e, 1, (u32)p->fEA4, func_02012984(func_020120F4((const struct Ctx_021F6E58 *)p->ctx->f40)), &out, 0x48);
            if (r != 0) {
                Req_021F6FD4 *w;

                if (p->req != 0) {
                    func_020307B0(p->req);
                    p->req = 0;
                }
                p->req = func_02030734(0x48, 0x14, 0, str_02203B6C, 0xEB);
                func_02082BCC(p->req, 0, 0x14);
                w = p->req;
                w->f0 = func_020120F4((const struct Ctx_021F6E58 *)p->ctx->f40);
                w->list = func_0201A920(0x48);
                func_0201A98C(w->list, e);
                w->f8 = r;
                w->fA = 0;
                w->fB = out;
                w->fC = 1;
                w->f10 = 0;
                func_02034A5C((u32)ov067_id);
                func_02031348(p->f12F0, (u32)ov195_id, d_02208C40, p->req);
                p->state = 1;
            } else {
                func_021F4EC0((u8 *)p, 1, 0);
                ret = 3;
            }
        } else if (p->kind == 8 || p->kind == 10) {
            void *e = (void *)func_021F7338((Obj_021F72C4 *)p, p->kind);
            void *mon = func_02202608(0x48);
            u32 out;
            u32 r;

            func_0200AD9C(p->ctx->save, mon);
            if (func_02017E1C(e, 5, 0) != func_02017E1C(mon, 5, 0)
                || func_02017E1C(e, 0, 0) != func_02017E1C(mon, 0, 0)) {
                func_02017E1C(e, 6, 0);
                r = 0;
                if (p->f12F8 != 0) {
                    p->f12F8 = 0;
                    r = func_0201B2B0(0, e, 1, (u32)mon, func_02012984(func_020120F4((const struct Ctx_021F6E58 *)p->ctx->f40)), &out, 0x48);
                }
                if (r != 0) {
                    Req_021F6FD4 *w;

                    if (p->req != 0) {
                        func_020307B0(p->req);
                        p->req = 0;
                    }
                    p->req = func_02030734(0x48, 0x14, 0, str_02203B6C, 0x130);
                    func_02082BCC(p->req, 0, 0x14);
                    w = p->req;
                    w->f0 = func_020120F4((const struct Ctx_021F6E58 *)p->ctx->f40);
                    w->list = func_0201A920(0x48);
                    func_0201A98C(w->list, e);
                    w->f8 = r;
                    w->fA = 0;
                    w->fB = out;
                    w->fC = 1;
                    w->f10 = 0;
                    func_02034A5C((u32)ov067_id);
                    func_02031348(p->f12F0, (u32)ov195_id, d_02208C40, p->req);
                    p->state = 1;
                } else {
                    func_021F4EC0((u8 *)p, 1, 0);
                    ret = 3;
                }
            } else {
                func_021F4EC0((u8 *)p, 1, 0);
                ret = 3;
            }
            func_020307B0(mon);
        } else {
            func_021F4EC0((u8 *)p, 1, 0);
            ret = 3;
        }
        break;
    case 1:
        if (p->busy != 0) {
            break;
        }
        if (p->req != 0) {
            Req_021F6FD4 *w = p->req;
            void *e = (void *)func_021F7338((Obj_021F72C4 *)p, p->kind);

            func_02019CE0(func_0201AB28(w->list, 0), e);
            func_020307B0(w->list);
            func_020307B0(p->req);
            p->req = 0;
        }
        func_021F7374((Obj_021F68A4 *)p);
        *(volatile u32 *)0x04000000 &= ~0xE000;
        func_02034AC4((u32)ov067_id);
        func_021F4EC0((u8 *)p, 7, 0xC);
        ret = 3;
        break;
    }
    return ret;
}



/*
 * volatile: 0x021F72AC writes hardware halfword 0x04000050.
 */
int func_021F7268(u8 *p)
{
    if (((struct Obj03829 *)p)->fD8) {
        func_020307B0(((struct Obj03829 *)p)->fD8);
        ((struct Obj03829 *)p)->fD8 = 0;
    }
    func_020307B0(((struct Obj03829 *)p)->fEA4);
    if (((struct Obj03829 *)p)->f10DC) {
        func_020307B0(((struct Obj03829 *)p)->f10DC);
        ((struct Obj03829 *)p)->f10DC = 0;
    }
    ((struct Obj03829 *)p)->f12F8 = 0;
    func_021F5074(p);
    func_021F4EC8(p);
    *(volatile unsigned short *)0x04000050 = 0;
    return 0;
}



Info_021F72C4 *func_021F72C4(Entry_021F72C4 *e)
{
    Info_021F72C4 *info;

    info = func_0200846C(0x48);
    func_020084A0((struct Sub0200852CObj *)info);
    func_020084D4((u32)info, e->name);
    func_02008560((struct Sub0200852CObj *)info, e->f124);
    func_02008568((struct Sub0200852CObj *)info, e->f125);
    func_0200854C((struct Sub0200852CObj *)info, e->fF6);
    func_02008558((struct Sub0200852CObj *)info, e->f122);
    func_02008574((struct Sub0200852CObj *)info, e->f120, e->f121);
    info->f10 = e->f10C;
    info->f14 = e->f108;
    return info;
}



/*
 * Return the slot record for a kind: kind 9 is the current 0x128-byte
 * entry of the +0x20C array (index at +0xD4), kinds 10 and 8 share the
 * record at +0xE4. Any other kind reports through func_02034714 (raw
 * address 0x02203B80, a plain constant as in func_02202B20) and yields 0.
 */
Entry_021F7338 *func_021F7338(Obj_021F72C4 *p, int kind)
{
    if (kind == 9) {
        return &p->arr[p->cur];
    } else if (kind == 10) {
        return &p->single;
    } else if (kind == 8) {
        return &p->single;
    }
    func_02034714((void *)0x02203B80, 0, (void *)0x02203B80);
    return 0;
}

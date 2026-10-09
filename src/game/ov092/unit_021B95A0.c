/*
 * file:     unit_021B95A0.c
 * unit:     yes
 * function: func_021B95A0, func_021B95E8, func_021B9614, func_021B9A14, func_021B9AA0, func_021B9BD8, func_021B9C34, func_021B9C80, func_021B9CA4
 * address:  0x021B95A0
 * region:   ov092
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02031324  0x02031324  arm
 *   func_0203133C 0x0203133C arm
 *   func_02045808 0x02045808 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02031330 0x02031330 arm
 *   func_02012934 0x02012934 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0201293C 0x0201293C thumb
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_0201B038 0x0201B038 thumb
 *   func_0201B170 0x0201B170 thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C278 0x0200C278 thumb
 *   func_0200C29C 0x0200C29C thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02008500 0x02008500 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AA14 0x0201AA14 thumb
 *   func_02007698 0x02007698 thumb
 *   func_020076D0 0x020076D0 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E4C 0x02013E4C thumb
 *   func_0202F190 0x0202F190 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_02031348 0x02031348 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0216C0A4 0x0216C0A4 thumb ov010
 *   func_0216C0E4 0x0216C0E4 thumb ov010
 *   func_0216C0D4 0x0216C0D4 thumb ov010
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0216C0C0 0x0216C0C0 thumb ov010
 *   func_021B9D04 0x021B9D04 thumb ov092
 *   func_0201A98C 0x0201A98C thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_020074D8 0x020074D8 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_02012984 0x02012984 thumb
 *   func_0201B2B0 0x0201B2B0 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   data_0220BAB0 0x0220BAB0 data a4 ov207
 *   data_021F5580 0x021F5580 data a4 ov194
 *   data_02208C40 0x02208C40 data a4 ov195
 *   ov207_id 0x000000CF data a1
 *   ov194_id 0x000000C2 data a1
 *   ov195_id 0x000000C3 data a1
 *   data_021B9DC0 0x021B9DC0 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021B9D44 0x021B9D44 data a1
 *   d_021B9D6E 0x021B9D6E data ov092 a2
 *   d_021B9D58 0x021B9D58 data ov092 a2
 *   d_021B9D4D 0x021B9D4D data ov092 a1
 *   func_02017F9C  0x02017F9C  thumb
 *   func_0216E62C  0x0216E62C  thumb  ov010
 *   func_02048F60 0x02048F60 arm
 */
#include "../../matched/include/Obj07738.h"
#include "../../matched/include/Obj13264.h"

struct Obj0203159C;
struct U16Vec;
struct S020314B8;
struct S020315D4;
struct Big;
struct BigObj;
struct Blk34;
struct Blk37;
struct MsgBank;
struct Party;
struct PartyMon;
struct Rec;
struct Rec44;
struct Rec534;
struct S_021B95A0;
struct SaveBlock;
struct Sub02007454Entry;
struct Sub02008C20Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct W {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0c[0x20];
    u32 f2c;
    u32 f30;
    u32 f34;
    u8 pad38[4];
    u16 f3c;
    u8 pad3e[2];
    u32 f40;
    u32 f44;
    u32 f48;
};

typedef struct { u8 pad[0x38]; u16 idx, mask; } Rec;

typedef struct { void *save, *party; u16 species; u8 slot, method; u32 x, flag; } Extra;

typedef signed int     s32;

struct In {
    u32 f00;
    u8 pad04[0x20];
    void *f24;
    u8 pad28[0x64];
    u32 f8c;
};

struct S_021B95A0 {
    void *f00;
    struct In *f04;
};

struct S_021B9AA0 {
    u32 f00;
    u8 *f04;
};

extern void func_0203064C(u32 src, u32 dst, u32 size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02031324(int a0);
extern void func_0203133C(struct S020314B8 *);
extern void func_02045808(struct U16Vec *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
extern u32 func_02031330(void *);
extern void *func_02012934(const struct BigObj *p);
extern u8 *func_02012944(void *);
extern void *func_0200CA1C(void *);
extern u32 func_0201293C(const struct BigObj *p);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_0201B038(void *);
extern void func_0201B170(void *);
extern void *func_02012F08(int *p);
extern u32 func_0200C278(struct Blk34 *p, u32 v);
extern u32 func_0200C29C(struct Blk34 *p, u32 v);
extern void *func_0201AB28(void *, u32);
extern void func_02008500(void *, void *);
extern void func_02017E40(void *, u32, u32);
extern u32 func_0201AA18(void *p);
extern u32 func_0201AA14(void *p);
extern u32 func_02007698(void *);
extern int func_020076D0(void *, int *, int *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013E4C(u32);
extern void func_0202F190(void *, u32, u32, u32, u16);
extern u32 func_0200CA38(struct Blk37 *p);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void func_02031348(void *, u32, const u8 *, void *);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *);
extern int *func_0216C0A4(unsigned short a, int b, int c, int d, int e, int f, int g, int h);
extern int func_0216C0E4(int *p);
extern void func_0216C0D4(int *p, int a1);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int func_0216C0C0(int a0);
extern void func_021B9D04(void *);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *func_020185F0(void *);
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);
extern void func_02005E30(u32);
extern int func_02005E50(void);
extern void func_02005D28(void);
extern u8 func_02012984(const struct BigObj *p);
extern u16 func_0201B2B0(void *, void *, u32, u32, u8, u32 *, u16);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_020056EC(u32);
extern void func_02017F9C(void *mon, u32 v);
extern void func_0216E62C(int a, int p, int id);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
int func_021B95A0(struct Obj0203159C *a0);
int func_021B95E8(struct S020315D4 *p, u32 b, u32 c, u32 d);
int func_021B9614(void *unused, u32 *step, u8 *s, u8 *r);
void func_021B9A14(u8 *a0, struct S_021B95A0 *s);
void func_021B9AA0(void *party);
void func_021B9BD8(void *party);
void func_021B9C34(struct S_021B9AA0 *s, void *party, int c);
u32 func_021B9C80(u32 p, u32 heap);
void func_021B9CA4(struct S_021B9AA0 *s, void *party);
extern const u8 data_0220BAB0[], data_021F5580[], data_02208C40[], data_021B9DC0[];
extern const u8 ov207_id[], ov194_id[], ov195_id[];
extern const u8 d_021B9D44[];
extern const u16 d_021B9D6E[];
extern const u16 d_021B9D58[];
extern const u8 d_021B9D4D[];



int func_021B95A0(struct Obj0203159C *a0)
{
    struct W *p;

    func_0203064C(1, 0x52, 0x1000);
    p = func_0203159C(a0, 0x4c, 0x52);
    p->f04 = (u32)func_020457B0(0x20, 0x52);
    p->f00 = 0;
    p->f08 = 0;
    p->f2c = 0;
    p->f30 = 0;
    p->f34 = 0;
    p->f3c = 0x52;
    p->f40 = (u32)func_02031324(p->f3c);
    p->f44 = 0;
    p->f48 = 0;
    return 1;
}


int func_021B95E8(struct S020315D4 *p, u32 b, u32 c, u32 d)
{
    func_0203133C(*(struct S020314B8 * *)&((struct Obj07738 *)d)->f40);
    if (*(struct U16Vec * *)&((struct Obj07738 *)d)->f2C) func_02045808(*(struct U16Vec * *)&((struct Obj07738 *)d)->f2C);
    func_02045808(*(struct U16Vec * *)&((struct Obj07738 *)d)->f4);
    func_020315D4(p);
    func_020306F0(0x52);
    return 1;
}


/*
 * note: 2026-10-05 matched. Loader order (context, id, descriptor, argument). Closing forms: case 1, 2 and 5 are
 *   `if (busy != 1) { body; break; } return 0;` (return block after the body); `ok = 0; if (f == 1) ok = 1;`;
 *   `if (flag) x = 0; else x = 1;`; `case 6: default: return 1;`; the case 4 tail `r68 = 1; break;` written in
 *   the guarded arm and again after it (cross-jumped copy leaves the b stub); species and slot as u16 locals,
 *   box/bslot declared first; the source record pointer s is not const. Case 4 mask and slot use a two-field view.
 */
int func_021B9614(void *unused, u32 *step, u8 *s, u8 *r)
{
    u32 busy;
    void *party;
    int box, bslot;
    u32 method;
    void *mon;
    u8 *buf;
    void *dex, *save, *bank;
    int amount, used, index;
    int flag;
    unsigned long dexno;
    u16 species;
    u16 slot;
    Extra *e;
    busy = func_02031330((*(void **)((u8 *)(r)+( 64))));
    if (busy == 1) return 0;
    switch (*step) {
    case 0:
        party = func_02012934((*(void **)((u8 *)(s)+( 0))));
        buf = func_02012944((*(void **)((u8 *)(s)+( 0))));
        dex = func_0200CA1C((*(void **)((u8 *)(s)+( 0))));
        save = (void *)func_0201293C((*(void **)((u8 *)(s)+( 0))));
        (((Rec *)r)->idx) = 0;
        (((Rec *)r)->mask) = 0;
        if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 0))) <= 1) {
            func_021B9A14(r, (struct S_021B95A0 *)s);
            func_0201AC2C((*(void **)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 36))), party);
            func_0201B038(party);
            func_0201B170(party);
            if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 140))) == 1) func_021B9AA0(party);
            func_021B9C34((struct S_021B9AA0 *)((struct S_021B95A0 *)s), party, func_021B9C80((u32)(*(void **)((u8 *)(s)+( 4))) + 8, (*(u16 *)((u8 *)(r)+( 60)))));
            func_021B9CA4((struct S_021B9AA0 *)((struct S_021B95A0 *)s), party);
            amount = (*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 136)));
            if (amount > 0) func_0200C278(func_02012F08((*(void **)((u8 *)(s)+( 0)))), amount);
            else if (amount < 0) func_0200C29C(func_02012F08((*(void **)((u8 *)(s)+( 0)))), -amount);
        }
        func_021B9BD8(party);
        if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 140))) == 5) {
            (*(void **)((u8 *)(r)+( 8))) = func_0201AB28((*(void **)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 40))), *((u8 *)(*(void **)((u8 *)(s)+( 4))) + 144));
            func_02008500(buf, (*(void **)((u8 *)(r)+( 4))));
            func_02017E40((*(void **)((u8 *)(r)+( 8))), 141, (*(u32 *)((u8 *)(r)+( 4))));
            used = (int)func_0201AA18(party);
            if (used >= (int)func_0201AA14(party)) {
                box = func_02007698(save); bslot = 0;
                func_020076D0(save, &box, &bslot);
                (*(u32 *)((u8 *)(r)+( 48))) = box;
                bank = func_02045B38(0, 2, 234, 82);
                index = func_020142E8((void *)func_0201296C((*(void **)((u8 *)(s)+( 0)))), 0x96d) ? 177 : 176;
                (*(void **)((u8 *)(r)+( 44))) = func_02045EC0(bank, index);
                func_02045C04(bank);
            }
            func_0202F190((*(void **)((u8 *)(r)+( 8))), 0, (u32)buf, func_02013E4C(func_02012AC8(func_020127A4((*(void **)((u8 *)(s)+( 0)))))), (*(u16 *)((u8 *)(r)+( 60))));
            flag = 0;
            dexno = func_0200CA38(dex);
            if (func_0200CED4(dex, func_02017E1C((*(void **)((u8 *)(r)+( 8))), 5, 0)) == 0) flag = 1;
            func_0200CFA0(dex, (*(void **)((u8 *)(r)+( 8))));
            func_0200CDE0(dex, (*(void **)((u8 *)(r)+( 8))));
            (*(u32 *)((u8 *)(r)+( 20))) = dexno;
            (*(void **)((u8 *)(r)+( 16))) = (*(void **)((u8 *)(r)+( 8)));
            (*(void **)((u8 *)(r)+( 24))) = (*(void **)((u8 *)(r)+( 44)));
            (*(void **)((u8 *)(r)+( 28))) = save;
            (*(u32 *)((u8 *)(r)+( 32))) = (*(u32 *)((u8 *)(r)+( 48)));
            (*(void **)((u8 *)(r)+( 36))) = (*(void **)((u8 *)(s)+( 0)));
            if (flag) (*(u32 *)((u8 *)(r)+( 12))) = 0; else (*(u32 *)((u8 *)(r)+( 12))) = 1;
            func_02031348((*(void **)((u8 *)(r)+( 64))), (u32)ov207_id, data_0220BAB0, r + 12);
            ++*step;
        } else *step = 4;
        break;
    case 1:
        if (busy != 1) {
        save = (void *)func_0201293C((*(void **)((u8 *)(s)+( 0))));
        flag = 0;
        if ((*(u32 *)((u8 *)(r)+( 40))) == 1) flag = 1;
        if (flag) {
            bank = func_0200C0F0(func_02012EBC((*(void **)((u8 *)(s)+( 0)))));
            (*(void **)((u8 *)(r)+( 0))) = func_0216C0A4((*(u16 *)((u8 *)(r)+( 60))), (int)(*(void **)((u8 *)(r)+( 8))), 10, 0, (int)(*(void **)((u8 *)(r)+( 44))), (int)save, (*(u32 *)((u8 *)(r)+( 48))), (int)bank);
            func_02031348((*(void **)((u8 *)(r)+( 64))), (u32)ov194_id, data_021F5580, (*(void **)((u8 *)(r)+( 0))));
            ++*step;
        } else *step = 3;
        break;
        }
        return 0;
    case 2:
        if (busy != 1) {
        if (!func_0216C0E4((*(void **)((u8 *)(r)+( 0))))) {
            func_0216C0D4((*(void **)((u8 *)(r)+( 0))), (u32)(*(u32 *)((u8 *)(r)+( 4))));
            func_02017E40((*(void **)((u8 *)(r)+( 8))), 115, (*(u32 *)((u8 *)(r)+( 4))));
            func_02008DF0(func_02012F2C((*(void **)((u8 *)(s)+( 0)))), 30);
        }
        func_0216C0C0((int)(*(void **)((u8 *)(r)+( 0))));
        (*(void **)((u8 *)(r)+( 0))) = 0;
        ++*step;
        break;
        }
        return 0;
    case 3:
        party = func_02012934((*(void **)((u8 *)(s)+( 0))));
        func_021B9D04((*(void **)((u8 *)(r)+( 8))));
        if (!(*(void **)((u8 *)(r)+( 44)))) func_0201A98C(party, (*(void **)((u8 *)(r)+( 8))));
        else {
            save = (void *)func_0201293C((*(void **)((u8 *)(s)+( 0))));
            func_020074D8(save, func_020185F0((*(void **)((u8 *)(r)+( 8)))));
        }
        ++*step;
        break;
    case 4: {
        void *party;
        if (!(*(u32 *)((u8 *)(r)+( 68)))) {
            if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 140))) == 5 && (((Rec *)r)->mask)) {
                if (!(*(u32 *)((u8 *)(r)+( 72)))) { func_02005E30(30); (*(u32 *)((u8 *)(r)+( 72))) = 1; break; }
                if (func_02005E50()) break;
                func_02005D28();
                (*(u32 *)((u8 *)(r)+( 68))) = 1;
                break;
            }
            (*(u32 *)((u8 *)(r)+( 68))) = 1;
            break;
        }
        if ((((Rec *)r)->mask)) {
            species = 0;
            party = func_02012934((*(void **)((u8 *)(s)+( 0))));
            *step = 6;
            while ((((Rec *)r)->mask)) {
                if ((((Rec *)r)->mask) & 1) {
                    mon = func_0201AB28(party, (((Rec *)r)->idx));
                    species = func_0201B2B0(party, mon, 0, (*(u16 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 18))), func_02012984((*(void **)((u8 *)(s)+( 0)))), &method, (*(u16 *)((u8 *)(r)+( 60))));
                    slot = (((Rec *)r)->idx);
                }
                (((Rec *)r)->mask) = (((Rec *)r)->mask) >> 1;
                (((Rec *)r)->idx)++;
                if (species) {
                    e = func_02030734((*(u16 *)((u8 *)(r)+( 60))), 20, 0, (const char *)data_021B9DC0, 0x1ca);
                    e->save = (*(void **)((u8 *)(s)+( 0))); e->party = party; e->species = species; e->slot = slot; e->method = method; e->x = 0; e->flag = 1;
                    (*(void **)((u8 *)(r)+( 52))) = e;
                    func_02031348((*(void **)((u8 *)(r)+( 64))), (u32)ov195_id, data_02208C40, e);
                    *step = 5;
                    break;
                }
            }
        } else *step = 6;
        break;
    }
    case 5:
        if (busy != 1) {
        func_020307B0((*(void **)((u8 *)(r)+( 52))));
        (*(void **)((u8 *)(r)+( 52))) = 0;
        if ((((Rec *)r)->mask)) *step = 4;
        else ++*step;
        break;
        }
        return 0;
    case 6:
    default:
        return 1;
    }
    return 0;
}



void func_021B9A14(u8 *a0, struct S_021B95A0 *s)
{
    struct In *in = s->f04;
    void *p1;
    int n;
    int i;
    u16 *dst;

    if (in->f8c == 1 || in->f8c == 3 || in->f8c == 5) {
        switch (in->f00) {
        case 0:
        case 1:
            p1 = func_02012934(s->f00);
            n = func_0201AA18(p1);
            i = 0;
            if (n > 0) {
                dst = (u16 *)(a0 + 0x3a);
                do {
                    void *m1 = func_0201AB28(p1, i);
                    void *m2 = func_0201AB28(s->f04->f24, i);
                    u32 v1 = func_02017E1C(m1, 0x9e, 0);
                    u32 v2 = func_02017E1C(m2, 0x9e, 0);
                    if (v1 < v2) {
                        *dst |= (u16)(1 << i);
                    }
                    i++;
                } while (i < n);
            }
            break;
        }
    }
}


void func_021B9AA0(void *party)
{
    int i;
    void *mon;
    u16 species,item;
    int ability;
    int random;
    int j;
    u8 tier;
    int threshold;
    int index;
    for (i=0;i<(int)func_0201AA18(party);i++) {
        mon = func_0201AB28(party,i);
        species = func_02017E1C(mon,0xab,0);
        item = func_02017E1C(mon,6,0);
        ability = (u8)func_02017E1C(mon,0xa,0);
        if (ability == 0x35 && species != 0 && species != 0x28a && item == 0 && func_020056EC(10) == 0) {
            random = func_020056EC(100);
            tier = (func_02017E1C(mon,0x9e,0)-1)/10u;
            if (tier >= 10) tier=9;
            for (j=0;j<9;j++) {
                if (d_021B9D44[j] > random) {
                    func_02017E40(mon,6,d_021B9D6E[tier+j]);
                    break;
                } else if (random >= 98 && random <= 99) {
                    func_02017E40(mon,6,d_021B9D58[tier+(99-random)]);
                    break;
                }
            }
        }
        if (ability == 0x76 && species != 0 && species != 0x28a && item == 0) {
            index=0;
            threshold=10;
            ability=(u8)func_02017E1C(mon,0x9e,0);
            while (threshold < ability) {
                threshold+=10;
                index++;
            }
            if (func_020056EC(100) < d_021B9D4D[index]) func_02017E40(mon,6,0x5e);
        }
    }
}



void func_021B9BD8(void *party)
{
    int i;
    void *mon;
    u16 a;
    u8 b;

    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, i);
        a = func_02017E1C(mon, 0xab, 0);
        b = func_02017E1C(mon, 0xa, 0);
        if (b == 0x1e && a != 0 && a != 0x28a) {
            func_02017F9C(mon, 0);
        }
    }
}



void func_021B9C34(struct S_021B9AA0 *s, void *party, int c)
{
    int i;

    if (*(u32 *)s->f04 - 2 > 1) {
        for (i = 0; i < (int)func_0201AA18(party); i++) {
            if (s->f04[0xc2 + i] != 0) {
                func_0216E62C(s->f00, (int)func_0201AB28(party, i), c);
            }
        }
    }
}


u32 func_021B9C80(u32 p, u32 heap)
{
    void *data;
    u32 result;
    u8 *record;
    data = func_02048F60(0x98, 0, heap);
    record = (u8 *)data + ((struct Obj13264 *)p)->f0 * 0x24;
    result = *(record + ((struct Obj13264 *)p)->f4 + 0x13);
    func_020307B0(data);
    return result;
}



void func_021B9CA4(struct S_021B9AA0 *s, void *party)
{
    int i;
    void *mon;
    u32 t;

    t = *(u32 *)s->f04;
    switch (t) {
    case 0:
    case 1:
        for (i = 0; i < (int)func_0201AA18(party); i++) {
            if (s->f04[0xc2 + i] != 0) {
                mon = func_0201AB28(party, i);
                if (func_02017E1C(mon, 5, 0) == 0x1ec) {
                    func_0200CFA0(func_0200CA1C((void *)s->f00), mon);
                }
            }
        }
        break;
    }
}

/*
 * file:     comm_player_p10.c
 * unit:     yes
 * function: func_021680C8, func_02168174, func_021681C8
 * address:  0x021680C8
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
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0202435C  0x0202435C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216DE94  0x0216DE94  thumb
 *   func_0216D88C  0x0216D88C  thumb
 *   func_0219129C  0x0219129C  thumb ov021
 *   func_02191388  0x02191388  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_021912D8  0x021912D8  thumb
 *   func_021912F8  0x021912F8  thumb
 *   func_02045808  0x02045808  arm
 *   func_021AA304  0x021AA304  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_02013610  0x02013610  thumb
 *   func_02013644  0x02013644  thumb
 *   func_02013734  0x02013734  thumb
 *   func_02013810  0x02013810  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_02039338  0x02039338  arm
 *   func_02013980  0x02013980  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_02017528  0x02017528  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02019CE0  0x02019CE0  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02019CA0  0x02019CA0  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045924  0x02045924  arm
 *   func_0202428C  0x0202428C  thumb
 *   func_02168AC8  0x02168AC8  thumb  ov010
 *   func_0216869C  0x0216869C  thumb  ov010
 *   func_0201394C  0x0201394C  thumb
 *   d_02172A2C     0x02172A2C  data
 */
#include "../../matched/include/Obj07204.h"
#include "../../matched/include/Obj09162.h"

struct BigObj;
struct Ctx;
struct Desc;
struct Ent;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Obj;
struct Actor;
struct VecFx32;
struct Party;
struct Strbuf;
struct BattleMon;
struct Entry;
struct Obj02013734;
struct PartyMon;
struct RecDC;
struct Sav;
struct ZoneData;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    u8 pad0[0x18];
    u16 f18;
    u16 f1a;
    u8 pad1c[0x120 - 0x1c];
} E;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} R;

typedef signed int s32;

struct Info { u32 f00; u32 f04; u8 f08; u8 f09; u16 f0A; u8 f0C; u8 f0D; u8 pad0E[2]; };

typedef struct { u8 raw[0x3C]; } BattleMon;

typedef struct { u16 v[8]; } W8;

typedef enum { SIDE_0, SIDE_1, SIDE_2, SIDE_3 } Side;

typedef struct Rec {
    u32 f00;
    u16 f04;
    u8 pad06[2];
    u8 f08[0x18];
    W8 w20;
    BattleMon mons[4];
} Rec;

typedef struct Spr {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[8];
    struct Strbuf *f14;
    W8 w18;
} Spr;

typedef struct Bs {
    u8 pad00[0x22];
    u8 f22;
    u8 pad23;
    struct Party *f24[4];
    u8 *f34[4];
    u8 pad44[4];
    Spr *f48[4];
} Bs;

extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C54(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_0202435C(void *slots, unsigned int heap);
extern u32 func_02012964(const struct BigObj *p);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern int func_02191388();
extern u32 func_020362DC(void);
extern int func_021912D8();
extern int func_021912F8();
extern int func_02045808();
extern void func_021AA304(struct Info *out, void *a1, void *a2);
extern void *func_02013090(u32 heap);
extern void func_02013610(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013644(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013734(struct Obj02013734 *o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02013810(u8 *o, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u32 a6, u16 a7);
extern struct Entry *func_020399A8(void);
extern u16 func_02039338(void);
extern void func_02013980(struct ZoneData *o, u32 heap);
extern u8 *func_02012944(void *p);
extern void func_0201A954(struct Party *p, s32 capacity);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02017528(struct Sav *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02019CA0(void *p, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0202428C(void *p);
extern int func_02168AC8(int a0);
extern void func_0216869C(const struct BattleMon *src, void *mon);
extern void func_0201394C(struct ZoneData *o);
int func_021680C8(int a, E *b, int c, int d);
int func_02168174(int a0, int a1, int a2);
Bs *func_021681C8(void *sys, void *partyA, u32 mode0, Rec *recA, Rec *recB, int n);
extern const char d_02172A2C[];


/*
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =func_02024368; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x0216C778), so the call
 * attests as `label`.
 */
int func_021680C8(int a, E *b, int c, int d)
{
    int hd;
    int h;
    int g;
    R *p;
    h = (int)func_020120F4((const struct Ctx *)a);
    g = func_02188C54(func_0201210C((void *)a));
    hd = (int)func_020122C0((void *)a, 0, func_02168174, 0x1c);
    p = func_020124E8((struct Obj *)hd);
    p->f0 = a;
    if (b->f18 == 0xFFFF) {
        int t;
        p->f14 = (int)func_020457B0(0x5c, 4);
        t = (int)func_02045B38(0, 2, 0xb8, 4);
        func_02045CAC((struct MsgBank *)t, b->f1a, (void *)p->f14);
        func_02045C04((struct Rec *)t);
    } else {
        p->f14 = (int)func_0202435C(&b[c].f18, 4);
    }
    func_0216D88C((const struct Actor *)func_0216DE94((void *)func_02012964((const struct BigObj *)h), d), (struct VecFx32 *)&p->f4);
    p->f10 = (int)func_0219129C((u8 *)g, 1, (u32)(&p->f4), p->f14, 0, 0);
    return hd;
}


int func_02168174(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a1 + 0;
a0 = ((struct Obj09162 *)((char *)t5))->f0;
t4 = a2 + 0;
    if (a0 == 0) goto loc_0216818A;
loc_02168180:
    if (a0 == 1) goto loc_0216819C;
loc_02168184:
    if (a0 == 2) goto loc_021681AE;
loc_02168188:
    goto loc_021681C2;
loc_0216818A:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = func_02191388(a0);
loc_02168190:
    if (a0 != 1) goto loc_021681C2;
loc_02168194:
a0 = ((struct Obj09162 *)((char *)t5))->f0;
a0 = a0 + 1;
((struct Obj09162 *)((char *)t5))->f0 = a0;
    goto loc_021681C2;
loc_0216819C:
    a0 = func_020362DC();
loc_021681A0:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_021681C2;
loc_021681A6:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = func_021912D8(a0);
loc_021681AC:
    goto loc_02168194;
loc_021681AE:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = func_021912F8(a0);
loc_021681B4:
    if (a0 != 1) goto loc_021681C2;
loc_021681B8:
a0 = ((struct Obj07204 *)t4)->f14;
    a0 = func_02045808(a0);
loc_021681BE:
a0 = 1;
    return a0;
loc_021681C2:
a0 = 0;
    return a0;}


/*
 * Builds the battle-intro sprite set: a func_02013090 object, one party
 * list per side filled from 0x3C-byte records through func_0216869C.
 * Levers: side ids are an enum (an int index folds to a constant offset);
 * the mode truncation is a u16 local copied from a u32 parameter; the
 * mode==4 and func_02168AC8 arms each carry their own copy of the eight
 * halfword stores (the cross-jump leaves the `b` into the second copy);
 * one party local per side block sets the spill slots; the sprite pointer
 * of the third block is read before the record pointer moves.
 */
Bs *func_021681C8(void *sys, void *partyA, u32 mode0, Rec *recA, Rec *recB, int n)
{
    u16 mode;
    struct Info info;
    Bs *bs;
    void *ctx;
    void *mon;
    struct Party *party;
    struct Party *partyB;
    struct Party *partyC;
    struct Party *partyD;
    Spr *o;
    int i;
    Side k;
    int flag;
    void *e;
    u8 *vec;
    Rec *recC;

    ctx = func_020120F4((const struct Ctx *)sys);
    mode = mode0;
    func_021AA304(&info, ctx, func_0201210C((const struct Ctx *)sys));
    bs = func_02013090(4);
    switch (mode) {
    case 0:
    case 4:
    case 5:
        func_02013610((u8 *)bs, (u32)ctx, (u32)(&info), 0, 4);
        break;
    case 1:
    case 6:
        func_02013644((u8 *)bs, (u32)ctx, (u32)(&info), 0, 4);
        break;
    case 2:
    case 7:
        func_02013734((struct Obj02013734 *)bs, (u32)ctx, (u32)(&info), 0, 0, 0, 4);
        break;
    case 3:
    case 8:
        e = func_020399A8();
        flag = 0;
        if (func_02039338() != 0)
            flag = 2;
        func_02013810((u8 *)bs, (u32)ctx, (u32)e, 1, flag, 0, 0, 4);
        break;
    }
    func_02013980((struct ZoneData *)bs, 4);

    k = SIDE_0;
    i = 0;
    vec = func_02012944(ctx);
    bs->f34[k] = vec;
    party = bs->f24[k];
    func_0201A954(party, 6);
    mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x253);
    func_02017528(mon);
    for (; i < n; i++) {
        e = func_0201AB28(partyA, i);
        func_02019CE0(e, mon);
        if (func_02017E1C(e, 0x9E, 0) != 0x32)
            func_02019CA0(mon, 0x32);
        func_0201A98C(party, mon);
    }
    func_020307B0(mon);

    k = SIDE_1;
    o = bs->f48[k];
    o->f00 = recA->f00;
    o->f04 = recA->f04;
    o->f08 = 0x87;
    func_02045924(o->f14, (const u16 *)recA->f08);
    func_0202428C(&o->w18.v[0]);
    func_0202428C(&o->w18.v[4]);
    if (mode == 4) {
        o->w18.v[0] = recA->w20.v[0];
        o->w18.v[1] = recA->w20.v[1];
        o->w18.v[2] = recA->w20.v[2];
        o->w18.v[3] = recA->w20.v[3];
        o->w18.v[4] = recA->w20.v[4];
        o->w18.v[5] = recA->w20.v[5];
        o->w18.v[6] = recA->w20.v[6];
        o->w18.v[7] = recA->w20.v[7];
    } else if (func_02168AC8((int)recA) != 0) {
        o->w18.v[0] = recA->w20.v[0];
        o->w18.v[1] = recA->w20.v[1];
        o->w18.v[2] = recA->w20.v[2];
        o->w18.v[3] = recA->w20.v[3];
        o->w18.v[4] = recA->w20.v[4];
        o->w18.v[5] = recA->w20.v[5];
        o->w18.v[6] = recA->w20.v[6];
        o->w18.v[7] = recA->w20.v[7];
    }
    partyB = bs->f24[k];
    func_0201A954(partyB, 6);
    mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x29E);
    for (i = 0; i < n; i++) {
        func_0216869C((const struct BattleMon *)(&recA->mons[i]), mon);
        func_0201A98C(partyB, mon);
    }
    func_020307B0(mon);

    if (bs->f22 != 0) {
        k = SIDE_3;
        o = bs->f48[k];
        recC = recA + 1;
        o->f00 = recC->f00;
        o->f04 = recC->f04;
        o->f08 = 0x87;
        func_02045924(o->f14, (const u16 *)recC->f08);
        partyC = bs->f24[k];
        func_0201A954(partyC, 6);
        mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x2C4);
        for (i = 0; i < n; i++) {
            func_0216869C((const struct BattleMon *)(&recC->mons[i]), mon);
            func_0201A98C(partyC, mon);
        }
        func_020307B0(mon);
    }
    if (bs->f22 == 3) {
        k = SIDE_2;
        o = bs->f48[k];
        o->f00 = recB->f00;
        o->f04 = recB->f04;
        o->f08 = 0x87;
        func_02045924(o->f14, (const u16 *)recB->f08);
        func_0202428C(&o->w18.v[0]);
        func_0202428C(&o->w18.v[4]);
        partyD = bs->f24[k];
        func_0201A954(partyD, 6);
        mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x2F3);
        for (i = 0; i < n; i++) {
            func_0216869C((const struct BattleMon *)(&recB->mons[i]), mon);
            func_0201A98C(partyD, mon);
        }
        func_020307B0(mon);
    }
    func_0201394C((struct ZoneData *)bs);
    return bs;
}

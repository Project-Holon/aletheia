/*
 * function: func_021681C8
 * address:  0x021681C8
 * packet:   pkt_ov010_021681C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the battle-intro sprite set: a func_02013090 object, one party
 * list per side filled from 0x3C-byte records through func_0216869C.
 * Levers: side ids are an enum (an int index folds to a constant offset);
 * the mode truncation is a u16 local copied from a u32 parameter; the
 * mode==4 and func_02168AC8 arms each carry their own copy of the eight
 * halfword stores (the cross-jump leaves the `b` into the second copy);
 * one party local per side block sets the spill slots; the sprite pointer
 * of the third block is read before the record pointer moves.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021AA304  0x021AA304  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_02013610  0x02013610  thumb
 *   func_02013644  0x02013644  thumb
 *   func_02013734  0x02013734  thumb
 *   BTL_SETUP_SetupCommAiMulti  0x02013810  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_02039338  0x02039338  arm
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02019CE0  0x02019CE0  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02019CA0  0x02019CA0  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045924  0x02045924  arm
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   func_02168AC8  0x02168AC8  thumb  ov010
 *   func_0216869C  0x0216869C  thumb  ov010
 *   BTL_SETUP_ChangeToSubway  0x0201394C  thumb
 *   d_02172A2C     0x02172A2C  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct Ctx;
struct Party;
struct Strbuf;
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
extern void func_021AA304(struct Info *out, void *a1, void *a2);
struct BattleMon;
struct Entry;
struct Obj02013734;
struct PartyMon;
struct RecDC;
struct Sav;
struct ZoneData;
extern void *func_02013090(u32 heap);
extern void func_02013610(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013644(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013734(struct Obj02013734 *o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void BTL_SETUP_SetupCommAiMulti(u8 *o, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u32 a6, u16 a7);
extern struct Entry *func_020399A8(void);
extern u16 func_02039338(void);
extern void BTL_SETUP_AllocRecordBuffer(struct ZoneData *o, u32 heap);
extern u8 *func_02012944(void *p);
extern void func_0201A954(struct Party *p, s32 capacity);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void POKE_TOOL_ClearPartyParam(struct Sav *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02019CA0(void *p, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void PMSI_PARAM_ClearSentence(void *p);
extern int func_02168AC8(int a0);
extern void func_0216869C(const struct BattleMon *src, void *mon);
extern void BTL_SETUP_ChangeToSubway(struct ZoneData *o);
extern const char d_02172A2C[];

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
        BTL_SETUP_SetupCommAiMulti((u8 *)bs, (u32)ctx, (u32)e, 1, flag, 0, 0, 4);
        break;
    }
    BTL_SETUP_AllocRecordBuffer((struct ZoneData *)bs, 4);

    k = SIDE_0;
    i = 0;
    vec = func_02012944(ctx);
    bs->f34[k] = vec;
    party = bs->f24[k];
    func_0201A954(party, 6);
    mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x253);
    POKE_TOOL_ClearPartyParam(mon);
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
    PMSI_PARAM_ClearSentence(&o->w18.v[0]);
    PMSI_PARAM_ClearSentence(&o->w18.v[4]);
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
        PMSI_PARAM_ClearSentence(&o->w18.v[0]);
        PMSI_PARAM_ClearSentence(&o->w18.v[4]);
        partyD = bs->f24[k];
        func_0201A954(partyD, 6);
        mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x2F3);
        for (i = 0; i < n; i++) {
            func_0216869C((const struct BattleMon *)(&recB->mons[i]), mon);
            func_0201A98C(partyD, mon);
        }
        func_020307B0(mon);
    }
    BTL_SETUP_ChangeToSubway((struct ZoneData *)bs);
    return bs;
}

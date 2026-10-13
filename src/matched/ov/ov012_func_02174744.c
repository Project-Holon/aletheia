/*
 * function: UNION_MAIN_StepColosseumPartyEntry
 * address:  0x02174744
 * packet:   pkt_ov012_02174744
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * note (2026-10-04, wave D3 lane 05): every concrete byte matches. The one
 * wildcard is the bl at +0x350 to COLOSSEUM_ClearBattleInfo, an unlabelled Thumb leaf
 * (memset tail call, 0x58 bytes) filed this wave as
 * src/matched/ov/ov012_func_0217534C.c. Once its shard is verified
 * (manifest --verify --shard pkt_ov012_0217534C) this file should verify EXACT;
 * move it to src/matched/ov then. Levers that closed it: case 16 and default
 * share one `return 1` placed before case 17 so the tails cross-jump onto
 * case 15 and case 17; func_02157450 takes a2 (not self) in r1; the byte
 * argument goes through `u8 *q = self + 0x2830` declared at function top
 * (as in ov012_func_02174AD8), which loads the base before the pool offset.
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_021B6114  0x021B6114  thumb  ov090
 *   func_021B6100  0x021B6100  thumb  ov090
 *   func_021B6108  0x021B6108  thumb  ov090
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02034714  0x02034714  arm
 *   func_0201A920  0x0201A920  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   POKEPARTY_Init  0x0201A948  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02175240  0x02175240  thumb  ov012
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02174D98  0x02174D98  thumb  ov012
 *   func_02175214  0x02175214  thumb  ov012
 *   COLOSSEUM_SetupBattleInfo  0x02175280  thumb  ov012
 *   COLOSSEUM_ClearBattleInfo  0x0217534C  thumb  ov012
 *   func_02157450  0x02157450  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02009D1C  0x02009D1C  thumb
 *   func_02009BB8  0x02009BB8  thumb
 *   func_02009B80  0x02009B80  thumb
 *   ov090_id       0x0000005A  data   a1
 *   ov091_id       0x0000005B  data   a1
 *   ov131_id       0x00000083  data   a1
 *   gPartyListProcData     0x021BED00  data   ov091  a4
 *   gPokeStatusProcData     0x021DC800  data   ov131  a4
 *   gUnionMainEmptyString     0x02175628  data   ov012  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Link;

typedef struct Rec2C {
    u8 pad[0x2c];
} Rec2C;

typedef struct Trade {
    u8    pad0[0x18];
    Rec2C recs[4];
    u8    pad[0x148 - 0x18 - 0xb0];
    void *parties[5];
    u8    flags[4];
} Trade;

typedef struct Out {
    void *f0;
    u8    pad4[0xc];
    u16   f10;
    u8    f12;
    u8    pad13;
    u32   f14;
    u8    f18[0x40];
    u32   f58;
} Out;

typedef struct Sub98 {
    void *f0;
    u32   f4;
    void *f8;
    u8    fc;
    u8    fd;
    u8    fe;
    u8    ff;
    u8    f10;
    u8    pad11[7];
    u32   f18;
} Sub98;

typedef struct Work {
    void *f0;
    u8    pad4[8];
    u32   fc;
    u8    pad10[0x2c];
    u32   f3c;
    u32   f40;
    u8    pad44[5];
    u8    f49[6];
    u8    pad4F[0x49];
    Sub98 f98;
    u8    padB4[0xc];
    Out  *fc0;
} Work;

struct BigObj;
struct Blk37;
struct Entry;
struct Evt;
struct IcaAnime;
struct Party;
struct PartyMon;
struct Rec534;
struct Sub0200852CObj;
struct Sub020097BCObj;
extern struct Entry *func_020399A8(void);
extern u32   func_0203D1A4(struct Link *p);
extern void func_021B6114(u8 *p);
extern void func_021B6100(u8 *p);
extern void func_021B6108(void *unused);
extern int   func_021BE8D4(void *a, int b, int sel, int d);
extern int   func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int   FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern int   func_02034AC4(signed int id);
extern void  func_02034A5C(int id);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32   GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32   func_0201AA18(void *p);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA38(struct Blk37 *p);
extern u32 func_0200FB24(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void POKEPARTY_Init(struct Party *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
extern void func_02175240(u8 *a, int b);
extern void  func_02039C68(struct Link *a0, unsigned int a1, unsigned int a2);
extern unsigned int func_02039CB4(struct Link *a0, unsigned int a1, unsigned int a2);
extern u32 func_02174D98(u32 p);
extern int func_02175214(u8 *p);
extern void COLOSSEUM_SetupBattleInfo(u8 *a, void *b, u8 *out, int d);
extern u32   func_02157450(u32 ctx, u32 a2, u8 v, Out *o);
extern u32 func_0201283C(const struct BigObj *p);
extern int   func_0203D1B4(void);
extern int func_02009D1C(struct Sub020097BCObj *obj, struct Sub0200852CObj *p, u32 *out);
extern void func_02009BB8(struct Sub020097BCObj *obj, int i, int a, int b, int c);
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
extern void  COLOSSEUM_ClearBattleInfo(void *p);

extern char ov090_id[];
extern char ov091_id[];
extern char ov131_id[];
extern u8 gPartyListProcData[];
extern u8 gPokeStatusProcData[];
extern u8 gUnionMainEmptyString[];

int UNION_MAIN_StepColosseumPartyEntry(u32 a0, u8 *self, u32 a2, Work *w, void *obj, u32 *res, u8 *state)
{
    u8 *q = self + 0x2830;
    Trade *t = *(Trade **)(self + 0x355C);
    Sub98 *s = &w->f98;
    Out *o = w->fc0;
    u32 me = func_0203D1A4((struct Link *)func_020399A8());
    void *party;
    void *tmp;
    int i;
    u32 obj2;
    int n;
    u32 flag;
    u32 id;

    if (*state > 2 && *state < 7)
        func_021B6114((u8 *)w);

    switch (*state) {
    case 0:
        func_02012374(obj, (void *)func_021BE8D4((void *)a0, a2, 0, 0));
        (*state)++;
        break;
    case 1:
        func_02012374(obj, (void *)FIELD_STATUS_CreateFieldCloseEvent(a0, a2));
        (*state)++;
        break;
    case 2:
        func_02034AC4((int)ov090_id);
        func_021B6100((u8 *)w);
        (*state)++;
        break;
    case 3:
        GAMESYSTEM_CallProc((void *)a0, (u32)ov091_id, gPartyListProcData, w);
        (*state)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)a0) != 0)
            break;
        if (w->f40 == 1)
            *state = 5;
        else
            *state = 7;
        break;
    case 5:
        s->f0 = w->f0;
        s->f4 = w->fc;
        s->f8 = func_020120F4((const struct Ctx *)a0);
        s->fc = 1;
        s->fe = func_0201AA18(w->f0);
        s->fd = 0;
        s->ff = w->f3c;
        s->f10 = 0;
        s->f18 = func_0200CA38(func_0200CA1C(s->f8));
        GAMESYSTEM_CallProc((void *)a0, (u32)ov131_id, gPokeStatusProcData, s);
        (*state)++;
        break;
    case 6:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)a0) != 0)
            break;
        w->f3c = s->ff;
        *state = 3;
        break;
    case 7:
        func_021B6108(w);
        func_02034A5C((int)ov090_id);
        *state = 8;
        break;
    case 8:
        if (func_0200FB24() != 0) {
            *state = 0x11;
            break;
        }
        if (w->f40 != 0)
            func_02034714((const char *)gUnionMainEmptyString, 0, (const char *)gUnionMainEmptyString);
        if (w->f3c != 6)
            func_02034714((const char *)gUnionMainEmptyString, 0, (const char *)gUnionMainEmptyString);
        party = t->parties[me];
        tmp = func_0201A920(0x41);
        func_0201AC2C(party, tmp);
        POKEPARTY_Init(party);
        for (i = 0; i < 6; i++) {
            if (w->f49[i] == 0)
                break;
            func_0201A98C(party, func_0201AB28(tmp, w->f49[i] - 1));
        }
        func_020307B0(tmp);
        func_02175240((u8 *)t, 1);
        func_02039C68((struct Link *)func_020399A8(), 0x16, 0x14);
        (*state)++;
        break;
    case 9:
        if (func_0200FB24() != 0) {
            *state = 0x11;
            break;
        }
        if (func_02039CB4((struct Link *)func_020399A8(), 0x16, 0x14) == 1)
            (*state)++;
        break;
    case 10:
        if (func_0200FB24() != 0) {
            *state = 0x11;
            break;
        }
        if (func_02174D98((u32)t->parties[me]) == 1)
            (*state)++;
        break;
    case 11:
        if (func_0200FB24() != 0) {
            *state = 0x11;
            break;
        }
        if (func_02175214((u8 *)t) == 1)
            (*state)++;
        break;
    case 12:
        o->f0 = t->parties[me];
        o->f12 = t->flags[me];
        o->f14 = *(u32 *)(self + 0x352C);
        if (me == 0 || (t->flags[0] & 2) == (t->flags[me] & 2))
            o->f10 = 0x48B;
        else
            o->f10 = 0x48C;
        COLOSSEUM_SetupBattleInfo((u8 *)t, (void *)a0, o->f18, 0x41);
        *res = func_02157450(a0, a2, q[0], o);
        (*state)++;
        break;
    case 13:
        if (func_0200FB24() == 0) {
            obj2 = func_0201283C(func_020120F4((const struct Ctx *)a0));
            n = func_0203D1B4();
            flag = t->flags[me] & 1;
            for (i = 0; i < n; i++) {
                if (i == me)
                    continue;
                if (func_02009D1C((struct Sub020097BCObj *)obj2, (struct Sub0200852CObj *)(&t->recs[i]), &id) != 1)
                    continue;
                if (flag == (t->flags[i] & 1)) {
                    func_02009B80((struct Sub020097BCObj *)obj2, id);
                    continue;
                }
                switch (o->f58) {
                case 0:
                    func_02009BB8((struct Sub020097BCObj *)obj2, id, 1, 0, 0);
                    break;
                case 1:
                    func_02009BB8((struct Sub020097BCObj *)obj2, id, 0, 1, 0);
                    break;
                case 2:
                    func_02009B80((struct Sub020097BCObj *)obj2, id);
                    break;
                }
            }
        }
        COLOSSEUM_ClearBattleInfo(o->f18);
        *state = 0x10;
        break;
    case 14:
        func_02012374(obj, FIELD_STATUS_CreateFieldOpenEvent((void *)a0));
        (*state)++;
        break;
    case 15:
        func_02012374(obj, (void *)func_021BE92C((void *)a0, a2, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 16:
    default:
        return 1;
    case 17:
        *state = 0xE;
        break;
    }
    return 0;
}

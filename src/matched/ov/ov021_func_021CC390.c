/*
 * function: FLD_TRADE_EventMain
 * address:  0x021CC390
 * packet:   pkt_ov021_021CC390
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five-step task callback (*state 0..4) that builds a mon through
 * FLD_TRADE_BuildPokemon, starts the ov119 and ov195 tasks and frees its work.
 *
 * Blocked (MATCH, every concrete byte right), three sites:
 *  - the pooled words 0x00000077 and 0x000000C3 are overlay ids (ov119_id,
 *    ov195_id) passed to FIELD_STATUS_CreateSubProcEvent's third argument; FIELD_STATUS_CreateSubProcEvent is
 *    not in match.py's OVERLAY_ID_CONSUMERS and no pool word outside this
 *    range holds either value (same blocker as pending ov021_func_021CD348
 *    and ov021_func_021C5A54).
 *  - FLD_TRADE_DumpTradeData is an unlabelled 4-byte leaf (`bx lr`, then 00 00
 *    padding) in ov021: `void FLD_TRADE_DumpTradeData(void *p) {}`. Not filed here
 *    because the overlay ids cap this function at MATCH regardless; file it
 *    as pkt_ov021_021CC38C together with the id fix.
 * d_021E75A8 resolves only without its ov119 token (sole-ref on re-run).
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   FLD_TRADE_Create  0x021CBFB0  thumb  ov021
 *   FLD_TRADE_BuildPokemon  0x021CC098  thumb  ov021
 *   FLD_TRADE_DumpPokemonParams  0x021CC23C  thumb  ov021
 *   FLD_TRADE_DumpTradeData  0x021CC38C  thumb  ov021
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   POKEPARTY_SetMember  0x0201AB48  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   SHINKA_CHECK_CheckEvolution  0x0201B2B0  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   FLD_TRADE_Delete  0x021CC040  thumb  ov021
 *   ov119_id       0x00000077  data  a1
 *   ov195_id       0x000000C3  data  a1
 *   d_021E75A8     0x021E75A8  data  a4
 *   d_02208C40     0x02208C40  data  ov195  a4
 *   d_021DE59C     0x021DE59C  data  ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    void *f8;
    void *fC;
    void *f10;
} Obj;

typedef struct {
    void *sys;      /* 0x00 */
    void *f4;       /* 0x04 */
    void *f8;       /* 0x08 */
    u8 fC;          /* 0x0C */
    u8 fD;          /* 0x0D */
    u8 padE[2];
    Obj *obj;       /* 0x10 */
    u8 f14[0x30];   /* 0x14 */
    void *f44;
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
} Work;

typedef struct {
    void *a;
    void *b;
    u16 h8;
    u8 bA;
    u8 bB;
    u32 fC;
    u32 f10;
} Req;

struct BigObj;
struct Blk37;
struct Ctx;
struct Evt;
struct Party;
struct PartyMon;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern Obj *FLD_TRADE_Create(u32 a, u32 b);
extern void FLD_TRADE_BuildPokemon(void *a, u16 b, void *mon, void *d, u32 e);
extern void FLD_TRADE_DumpPokemonParams(int obj);
extern void FLD_TRADE_DumpTradeData(void *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *FIELD_STATUS_CreateSubProcEvent(char *a0, int a1, int a2, int a3, int a4);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void POKEPARTY_SetMember(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *func_0200CA1C(void *p);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void FLD_TRADE_Delete(Obj *o);

extern const u8 ov119_id[];
extern const u8 ov195_id[];
extern u8 d_021E75A8[];
extern u8 d_02208C40[];
extern const char d_021DE59C[];

int FLD_TRADE_EventMain(void *a, u32 *state, Work *w)
{
    void *sys = w->sys;
    void *f4 = w->f4;
    void *f8 = w->f8;
    void *h = GAMESYSTEM_GetFieldMap(sys);
    void *m = POKEPARTY_GetMember(f8, w->fD);
    Obj *o;
    void *t;
    void *box;
    u32 sel;
    u32 r;
    Req *q;

    switch (*state) {
    case 0:
        o = FLD_TRADE_Create(4, w->fC);
        w->obj = o;
        FLD_TRADE_BuildPokemon(f4, 4, o->fC, o->f8, w->fC);
        FLD_TRADE_DumpPokemonParams((int)w->obj->fC);
        FLD_TRADE_DumpTradeData(w->obj->f8);
        *state = 1;
        break;
    case 1:
        t = GAMESYSTEM_GetFieldMap(sys);
        w->f44 = f4;
        w->f50 = GAME_DATA_GetMyStatus(f4);
        w->f48 = m;
        w->f54 = w->obj->f10;
        w->f4C = w->obj->fC;
        GAME_EVENT_CallEvent(a, FIELD_STATUS_CreateSubProcEvent(sys, (int)t, (int)ov119_id, (int)d_021E75A8, (int)w->f14));
        *state = 2;
        break;
    case 2:
        POKEPARTY_SetMember(f8, w->fD, w->obj->fC);
        box = func_0200CA1C(f4);
        func_0200CFA0(box, w->obj->fC);
        func_0200CDE0(box, w->obj->fC);
        *state = 4;
        break;
    case 3:
        r = SHINKA_CHECK_CheckEvolution(f8, m, 1, 0, GAME_DATA_GetSeason(f4), &sel, 4);
        if (r != 0) {
            q = func_02030734(4, 0x14, 0, d_021DE59C, 0x1F0);
            q->a = f4;
            q->b = f8;
            q->h8 = r;
            q->bA = w->fD;
            q->bB = sel;
            q->fC = 1;
            q->f10 = 0;
            w->f58 = q;
            GAME_EVENT_CallEvent(a, FIELD_STATUS_CreateSubProcEvent(sys, (int)h, (int)ov195_id, (int)d_02208C40, (int)q));
        }
        *state = 4;
        break;
    case 4:
        if (w->f58 != 0)
            func_020307B0(w->f58);
        FLD_TRADE_Delete(w->obj);
        return 1;
    }
    return 0;
}

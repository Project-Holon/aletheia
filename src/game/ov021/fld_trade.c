/*
 * file:     fld_trade.c
 * unit:     yes
 * function: func_021CBFB0, func_021CC040, func_021CC060, func_021CC068, func_021CC070, func_021CC098, func_021CC23C, func_021CC38C, func_021CC390, func_021CC500
 * address:  0x021CBFB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fld_trade_p01.c and fld_trade_p02.c (lane CL125b): __FILE__ anchor 021CC03C (d_021DE59C "fld_trade.c").
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02048F88  0x02048F88  arm
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_02045A38  0x02045A38  arm
 *   func_02045808  0x02045808  arm
 *   func_020084D4  0x020084D4  thumb
 *   func_0200854C  0x0200854C  thumb
 *   d_021DE59C  0x021DE59C  data  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201862C  0x0201862C  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0202F190  0x0202F190  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201AB48  0x0201AB48  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0201B2B0  0x0201B2B0  thumb
 *   ov119_id       0x00000077  data  a1
 *   ov195_id       0x000000C3  data  a1
 *   d_021E75A8     0x021E75A8  data  a4
 *   d_02208C40     0x02208C40  data  ov195  a4
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 */
struct U16Vec;
struct Sub0200852CObj;
struct MsgBank;
struct Mon;
struct Personal;
struct BigObj;
struct Blk37;
struct Ctx;
struct Evt;
struct Party;
struct PartyMon;
struct Desc;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* One in-game trade record (archive 0xA5, 0x6C bytes per trade). */
typedef struct FldTradeData {
    u32 tradeId;            /* 0x00 */
    u32 species;            /* 0x04 */
    u32 formNo;             /* 0x08 */
    u32 level;              /* 0x0C */
    u32 iv[6];              /* 0x10: Pokemon params 0x46..0x4B */
    u32 abilitySlot;        /* 0x28: 0, 1 or 2 (third personal ability) */
    u32 nature;             /* 0x2C */
    u32 gender;             /* 0x30 */
    u32 otId;               /* 0x34 */
    u32 contest[5];         /* 0x38: Pokemon params 0x13..0x17 */
    u32 heldItem;           /* 0x4C */
    u32 otGender;           /* 0x50 */
    u32 tradeFlag;          /* 0x54 */
    u32 language;           /* 0x58 */
    u32 wantedSpecies;      /* 0x5C */
    u32 wantedGender;       /* 0x60 */
    u32 nicknameMsgId;      /* 0x64 */
    u32 otNameMsgId;        /* 0x68 */
} FldTradeData;

typedef struct FldTradeHolder {
    u16 heapId;
    u32 tradeId;
    FldTradeData *data;
    void *mon;              /* 0xDC-byte Pokemon */
    void *traderStatus;
} FldTradeHolder;

/* Parameter block of the ov195 evolution process. */
typedef struct FldTradeEvolveParam {
    void *gameData;
    void *party;
    u16 newSpecies;
    u8 partyIndex;
    u8 evolveMethod;
    u32 mode;
    u32 result;
} FldTradeEvolveParam;

/* Parameter block of the ov119 trade demo process. */
typedef struct FldTradeDemoParam {
    u8 demoWork[0x30];
    void *gameData;         /* 0x30 */
    void *sentMon;          /* 0x34 */
    void *receivedMon;      /* 0x38 */
    void *playerStatus;     /* 0x3C */
    void *traderStatus;     /* 0x40 */
} FldTradeDemoParam;

/* Event work (0x5C bytes). */
typedef struct FldTradeEvent {
    void *gsys;
    void *gameData;
    void *party;
    u8 tradeId;
    u8 partyIndex;
    FldTradeHolder *holder;             /* 0x10 */
    FldTradeDemoParam demoParam;        /* 0x14 */
    FldTradeEvolveParam *evolveParam;   /* 0x58 */
} FldTradeEvent;

extern void *func_02030734(u16 heap, u32 size, u32 clear, const char *file, u32 line);
extern void *func_02048F88(u32 archive_id, u32 member, u32 heap, u32 mode, u32 *size_out);
extern void *func_0200846C(int a0);
extern void func_020084A0(struct Sub0200852CObj *);
extern void func_02045A38(struct U16Vec *, u16 *, u32);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_0200854C(int, u32);
extern u32 func_020307B0(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct MsgBank *bank);
extern u32 func_0201862C(u32 id, u16 species, u16 formNo, u8 gender, u8 a4, int a5);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *mon, u32 field, u32 v);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u8 *func_02012944(void *p);
extern void func_0202F190(void *mon, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_020185C4(void *mon);
extern u32 func_02017E1C(void *obj, u32 key, u32 off);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0201AB48(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *func_0200CA1C(void *p);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Desc *event);

FldTradeHolder *func_021CBFB0(u32 heapId, u32 tradeId);
void func_021CC040(FldTradeHolder *holder);
u32 func_021CC060(FldTradeHolder *holder);
u32 func_021CC068(FldTradeHolder *holder);
void *func_021CC070(u32 heapId, u32 msgId);
void func_021CC098(void *gameData, u16 heapId, void *mon, FldTradeData *data, u32 tradeId);
void func_021CC23C(int mon);
void func_021CC38C(FldTradeData *data);
int func_021CC390(void *event, u32 *seq, FldTradeEvent *work);
void *func_021CC500(void *gsys, u32 tradeId, u32 partyIndex);

extern const char d_021DE59C[];
extern const u8 ov119_id[];
extern const u8 ov195_id[];
extern u8 d_021E75A8[];
extern u8 d_02208C40[];

/*
 * Loads trade record tradeId and builds the trader's Pokemon buffer and the
 * trader's status (OT name from message bank 0x23, OT gender).
 */
FldTradeHolder *func_021CBFB0(u32 heapId, u32 tradeId)
{
    FldTradeHolder *holder;
    int otName;
    char nameBuf[0x100];

    holder = func_02030734((u16)heapId, 0x14, 1, d_021DE59C, 0x5d);
    holder->heapId = (u16)heapId;
    holder->tradeId = tradeId;
    holder->data = func_02048F88(0xa5, tradeId, (u16)heapId, 0, (u32 *)0x6c);
    holder->mon = func_02030734((u16)heapId, 0xdc, 0, d_021DE59C, 0x65);
    holder->traderStatus = (void *)func_0200846C(heapId);
    func_020084A0((struct Sub0200852CObj *)holder->traderStatus);
    otName = (int)func_021CC070(heapId, holder->data->otNameMsgId);
    func_02045A38((struct U16Vec *)otName, (u16 *)nameBuf, 0x80);
    func_02045808((struct U16Vec *)otName);
    func_020084D4((int)holder->traderStatus, nameBuf);
    func_0200854C((int)holder->traderStatus, holder->data->otGender);
    return holder;
}

void func_021CC040(FldTradeHolder *holder)
{
    func_020307B0(holder->data);
    func_020307B0(holder->mon);
    func_020307B0(holder->traderStatus);
    func_020307B0(holder);
}

u32 func_021CC060(FldTradeHolder *holder)
{
    return holder->data->wantedSpecies;
}

u32 func_021CC068(FldTradeHolder *holder)
{
    return holder->data->wantedGender;
}

/* Copies one string of message bank 0x23. */
void *func_021CC070(u32 heapId, u32 msgId)
{
    void *bank = func_02045B38(0, 2, 0x23, (u16)heapId);
    void *str = func_02045EC0(bank, msgId);
    func_02045C04(bank);
    return str;
}

void func_021CC098(void *gameData, u16 heapId, void *mon, FldTradeData *data, u32 tradeId)
{
    u32 personalRnd;
    u32 str;
    u32 personal;
    u32 ability[3];

    personalRnd = func_0201862C(data->otId, data->species, data->formNo, data->gender, 0, 0);
    func_02017588(mon, data->species, data->level, data->otId, 0xFFFFFFFF, personalRnd);
    func_02017E40(mon, 0x6F, data->formNo);
    func_021CC23C((int)mon);
    str = (u32)func_021CC070(heapId, data->nicknameMsgId);
    func_02017E40(mon, 0x73, str);
    func_02045808((struct U16Vec *)str);
    func_02017E40(mon, 0x46, data->iv[0]);
    func_02017E40(mon, 0x47, data->iv[1]);
    func_02017E40(mon, 0x48, data->iv[2]);
    func_02017E40(mon, 0x49, data->iv[3]);
    func_02017E40(mon, 0x4A, data->iv[4]);
    func_02017E40(mon, 0x4B, data->iv[5]);
    personal = (u32)func_0201ADE4((u16)data->species, (u16)data->formNo, heapId);
    ability[0] = func_0201AE1C((const struct Personal *)personal, 0x1A);
    ability[1] = func_0201AE1C((const struct Personal *)personal, 0x1B);
    ability[2] = func_0201AE1C((const struct Personal *)personal, 0x1C);
    func_0201AE14((void *)personal);
    switch (data->abilitySlot) {
    case 0:
        break;
    case 1:
        ability[0] = ability[1];
        break;
    case 2:
        ability[0] = ability[2];
        break;
    }
    func_02017E40(mon, 0xA, ability[0]);
    func_02017E40(mon, 0x70, data->nature);
    func_02017E40(mon, 0x13, data->contest[0]);
    func_02017E40(mon, 0x14, data->contest[1]);
    func_02017E40(mon, 0x15, data->contest[2]);
    func_02017E40(mon, 0x16, data->contest[3]);
    func_02017E40(mon, 0x17, data->contest[4]);
    func_02017E40(mon, 0x6, data->heldItem);
    str = (u32)func_021CC070(heapId, data->otNameMsgId);
    func_02017E40(mon, 0x8D, str);
    func_02045808((struct U16Vec *)str);
    func_02017E40(mon, 0x9A, data->otGender);
    func_02017E40(mon, 0xC, data->language);
    func_0202F190(mon, 1, (u32)func_02012944(gameData), 0x7532, heapId);
    func_021CC23C((int)mon);
    func_020185C4(mon);
}

/*
 * Reads 33 Pokemon params and drops the values: a debug dump whose print
 * calls are compiled out.
 */
void func_021CC23C(int mon)
{
    func_02017E1C((void *)mon, 0, 0);
    func_02017E1C((void *)mon, 5, 0);
    func_02017E1C((void *)mon, 0x6f, 0);
    func_02017E1C((void *)mon, 6, 0);
    func_02017E1C((void *)mon, 7, 0);
    func_02017E1C((void *)mon, 8, 0);
    func_02017E1C((void *)mon, 9, 0);
    func_02017E1C((void *)mon, 0xa, 0);
    func_02017E1C((void *)mon, 0x6e, 0);
    func_02017E1C((void *)mon, 0x70, 0);
    func_02017E1C((void *)mon, 0xb, 0);
    func_02017E1C((void *)mon, 0xc, 0);
    func_02017E1C((void *)mon, 0xd, 0);
    func_02017E1C((void *)mon, 0xe, 0);
    func_02017E1C((void *)mon, 0xf, 0);
    func_02017E1C((void *)mon, 0x10, 0);
    func_02017E1C((void *)mon, 0x11, 0);
    func_02017E1C((void *)mon, 0x12, 0);
    func_02017E1C((void *)mon, 0x13, 0);
    func_02017E1C((void *)mon, 0x14, 0);
    func_02017E1C((void *)mon, 0x15, 0);
    func_02017E1C((void *)mon, 0x16, 0);
    func_02017E1C((void *)mon, 0x17, 0);
    func_02017E1C((void *)mon, 0x18, 0);
    func_02017E1C((void *)mon, 0x46, 0);
    func_02017E1C((void *)mon, 0x47, 0);
    func_02017E1C((void *)mon, 0x48, 0);
    func_02017E1C((void *)mon, 0x49, 0);
    func_02017E1C((void *)mon, 0x4a, 0);
    func_02017E1C((void *)mon, 0x4b, 0);
    func_02017E1C((void *)mon, 0x9a, 0);
    func_02017E1C((void *)mon, 0x9e, 0);
    func_02017E1C((void *)mon, 0x95, 0);
}

/* Debug dump of a trade record; empty in the release build. */
void func_021CC38C(FldTradeData *data)
{
}

/*
 * Trade event: build the trader's Pokemon, run the ov119 trade demo, put the
 * received Pokemon in the party and register it in the Pokedex. Step 3 (the
 * ov195 trade evolution) is never reached: step 2 goes straight to 4.
 */
int func_021CC390(void *event, u32 *seq, FldTradeEvent *work)
{
    void *gsys = work->gsys;
    void *gameData = work->gameData;
    void *party = work->party;
    void *fieldmap = func_0201210C(gsys);
    void *sentMon = func_0201AB28(party, work->partyIndex);
    FldTradeHolder *holder;
    void *demoFieldmap;
    void *zukan;
    u32 evolveMethod;
    u32 newSpecies;
    FldTradeEvolveParam *evolveParam;

    switch (*seq) {
    case 0:
        holder = func_021CBFB0(4, work->tradeId);
        work->holder = holder;
        func_021CC098(gameData, 4, holder->mon, holder->data, work->tradeId);
        func_021CC23C((int)work->holder->mon);
        func_021CC38C(work->holder->data);
        *seq = 1;
        break;
    case 1:
        demoFieldmap = func_0201210C(gsys);
        work->demoParam.gameData = gameData;
        work->demoParam.playerStatus = func_02012944(gameData);
        work->demoParam.sentMon = sentMon;
        work->demoParam.traderStatus = work->holder->traderStatus;
        work->demoParam.receivedMon = work->holder->mon;
        func_02012374(event, func_020146F8(gsys, (int)demoFieldmap, (int)ov119_id, (int)d_021E75A8, (int)&work->demoParam));
        *seq = 2;
        break;
    case 2:
        func_0201AB48(party, work->partyIndex, work->holder->mon);
        zukan = func_0200CA1C(gameData);
        func_0200CFA0(zukan, work->holder->mon);
        func_0200CDE0(zukan, work->holder->mon);
        *seq = 4;
        break;
    case 3:
        newSpecies = func_0201B2B0(party, sentMon, 1, 0, func_02012984(gameData), &evolveMethod, 4);
        if (newSpecies != 0) {
            evolveParam = func_02030734(4, 0x14, 0, d_021DE59C, 0x1F0);
            evolveParam->gameData = gameData;
            evolveParam->party = party;
            evolveParam->newSpecies = newSpecies;
            evolveParam->partyIndex = work->partyIndex;
            evolveParam->evolveMethod = evolveMethod;
            evolveParam->mode = 1;
            evolveParam->result = 0;
            work->evolveParam = evolveParam;
            func_02012374(event, func_020146F8(gsys, (int)fieldmap, (int)ov195_id, (int)d_02208C40, (int)evolveParam));
        }
        *seq = 4;
        break;
    case 4:
        if (work->evolveParam != 0)
            func_020307B0(work->evolveParam);
        func_021CC040(work->holder);
        return 1;
    }
    return 0;
}

/* Creates the trade event for trade record tradeId and party slot partyIndex. */
void *func_021CC500(void *gsys, u32 tradeId, u32 partyIndex)
{
    void *gameData;
    void *party;
    void *event;
    FldTradeEvent *work;

    gameData = func_020120F4(gsys);
    party = func_02012934(gameData);
    event = func_020122C0(gsys, 0, (void *)func_021CC390, 0x5c);
    work = func_020124E8(event);
    work->gsys = gsys;
    work->gameData = gameData;
    work->party = party;
    work->tradeId = tradeId;
    work->partyIndex = partyIndex;
    work->evolveParam = 0;
    return event;
}

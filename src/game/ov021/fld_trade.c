/*
 * file:     fld_trade.c
 * unit:     yes
 * function: FLD_TRADE_Create, FLD_TRADE_Delete, FLD_TRADE_GetWantedSpecies, FLD_TRADE_GetWantedGender, FLD_TRADE_GetMessageString, FLD_TRADE_BuildPokemon, FLD_TRADE_DumpPokemonParams, FLD_TRADE_DumpTradeData, FLD_TRADE_EventMain, FLD_TRADE_CreateEvent
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
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ARC_TOOL_LoadMemberRange  0x02048F88  arm
 *   MYSTATUS_Create  0x0200846C  thumb
 *   MYSTATUS_Init  0x020084A0  thumb
 *   STRBUF_ToChars  0x02045A38  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MYSTATUS_CopyName  0x020084D4  thumb
 *   MYSTATUS_SetOutfitVariant  0x0200854C  thumb
 *   d_021DE59C  0x021DE59C  data  ov021
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   POKE_TOOL_AdjustPersonalRnd  0x0201862C  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   SAVE_EVENT_Write  0x0202F190  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   POKEPARTY_SetMember  0x0201AB48  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   SHINKA_CHECK_CheckEvolution  0x0201B2B0  thumb
 *   ov119_id       0x00000077  data  a1
 *   ov195_id       0x000000C3  data  a1
 *   d_021E75A8     0x021E75A8  data  a4
 *   d_02208C40     0x02208C40  data  ov195  a4
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
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
#include "poke_tool_param.h"

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

extern void *GFL_HEAP_Alloc(u16 heap, u32 size, u32 clear, const char *file, u32 line);
extern void *ARC_TOOL_LoadMemberRange(u32 archive_id, u32 member, u32 heap, u32 mode, u32 *size_out);
extern void *MYSTATUS_Create(int heap_id);
extern void MYSTATUS_Init(struct Sub0200852CObj *);
extern void STRBUF_ToChars(struct U16Vec *, u16 *, u32);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MYSTATUS_CopyName(u32 value, void *dst);
extern void MYSTATUS_SetOutfitVariant(int, u32);
extern u32 GFL_HEAP_Free(void *p);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u32 POKE_TOOL_AdjustPersonalRnd(u32 id, u16 species, u16 formNo, u8 gender, u8 shinyWanted, int genderMode);
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void POKE_TOOL_SetPartyValue(void *mon, u32 field, u32 v);
extern void *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void SAVE_EVENT_Write(void *mon, u32 mode, u32 record, u32 eventId, u16 index);
extern void POKE_TOOL_RecalcParam(void *mon);
extern u32 POKE_TOOL_GetPartyValue(void *obj, u32 key, u32 off);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void *FIELD_STATUS_CreateSubProcEvent(char *gameSystem, int fieldMap, int overlayId, int procData, int procWork);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void POKEPARTY_SetMember(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *ZUKAN_SAVE_GetFromGameData(void *p);
extern void ZUKAN_SAVE_RegisterSeen(struct Blk37 *p, void *m);
extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *p, void *m);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern struct Desc *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
extern void *GAME_EVENT_GetWork(struct Desc *event);

FldTradeHolder *FLD_TRADE_Create(u32 heapId, u32 tradeId);
void FLD_TRADE_Delete(FldTradeHolder *holder);
u32 FLD_TRADE_GetWantedSpecies(FldTradeHolder *holder);
u32 FLD_TRADE_GetWantedGender(FldTradeHolder *holder);
void *FLD_TRADE_GetMessageString(u32 heapId, u32 msgId);
void FLD_TRADE_BuildPokemon(void *gameData, u16 heapId, void *mon, FldTradeData *data, u32 tradeId);
void FLD_TRADE_DumpPokemonParams(int mon);
void FLD_TRADE_DumpTradeData(FldTradeData *data);
int FLD_TRADE_EventMain(void *event, u32 *seq, FldTradeEvent *work);
void *FLD_TRADE_CreateEvent(void *gsys, u32 tradeId, u32 partyIndex);

extern const char d_021DE59C[];
extern const u8 ov119_id[];
extern const u8 ov195_id[];
extern u8 d_021E75A8[];
extern u8 d_02208C40[];

/*
 * Loads trade record tradeId and builds the trader's Pokemon buffer and the
 * trader's status (OT name from message bank 0x23, OT gender).
 */
FldTradeHolder *FLD_TRADE_Create(u32 heapId, u32 tradeId)
{
    FldTradeHolder *holder;
    int otName;
    char nameBuf[0x100];

    holder = GFL_HEAP_Alloc((u16)heapId, 0x14, 1, d_021DE59C, 0x5d);
    holder->heapId = (u16)heapId;
    holder->tradeId = tradeId;
    holder->data = ARC_TOOL_LoadMemberRange(0xa5, tradeId, (u16)heapId, 0, (u32 *)0x6c);
    holder->mon = GFL_HEAP_Alloc((u16)heapId, 0xdc, 0, d_021DE59C, 0x65);
    holder->traderStatus = (void *)MYSTATUS_Create(heapId);
    MYSTATUS_Init((struct Sub0200852CObj *)holder->traderStatus);
    otName = (int)FLD_TRADE_GetMessageString(heapId, holder->data->otNameMsgId);
    STRBUF_ToChars((struct U16Vec *)otName, (u16 *)nameBuf, 0x80);
    STRBUF_Delete((struct U16Vec *)otName);
    MYSTATUS_CopyName((int)holder->traderStatus, nameBuf);
    MYSTATUS_SetOutfitVariant((int)holder->traderStatus, holder->data->otGender);
    return holder;
}

void FLD_TRADE_Delete(FldTradeHolder *holder)
{
    GFL_HEAP_Free(holder->data);
    GFL_HEAP_Free(holder->mon);
    GFL_HEAP_Free(holder->traderStatus);
    GFL_HEAP_Free(holder);
}

u32 FLD_TRADE_GetWantedSpecies(FldTradeHolder *holder)
{
    return holder->data->wantedSpecies;
}

u32 FLD_TRADE_GetWantedGender(FldTradeHolder *holder)
{
    return holder->data->wantedGender;
}

/* Copies one string of message bank 0x23. */
void *FLD_TRADE_GetMessageString(u32 heapId, u32 msgId)
{
    void *bank = MSGDATA_CreateFromArchive(0, 2, 0x23, (u16)heapId);
    void *str = MSGDATA_AllocString(bank, msgId);
    MSGDATA_Delete(bank);
    return str;
}

void FLD_TRADE_BuildPokemon(void *gameData, u16 heapId, void *mon, FldTradeData *data, u32 tradeId)
{
    u32 personalRnd;
    u32 str;
    u32 personal;
    u32 ability[3];

    personalRnd = POKE_TOOL_AdjustPersonalRnd(data->otId, data->species, data->formNo, data->gender, 0, 0);
    POKE_TOOL_SetupPartyParamEx(mon, data->species, data->level, data->otId, 0xFFFFFFFF, personalRnd);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_FORM, data->formNo);
    FLD_TRADE_DumpPokemonParams((int)mon);
    str = (u32)FLD_TRADE_GetMessageString(heapId, data->nicknameMsgId);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_NICKNAME_STRBUF, str);
    STRBUF_Delete((struct U16Vec *)str);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_IV_HP, data->iv[0]);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_IV_ATTACK, data->iv[1]);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_IV_DEFENSE, data->iv[2]);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_IV_SPEED, data->iv[3]);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_IV_SP_ATTACK, data->iv[4]);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_IV_SP_DEFENSE, data->iv[5]);
    personal = (u32)POKE_PERSONAL_Create((u16)data->species, (u16)data->formNo, heapId);
    ability[0] = POKE_PERSONAL_GetParam((const struct Personal *)personal, 0x1A);
    ability[1] = POKE_PERSONAL_GetParam((const struct Personal *)personal, 0x1B);
    ability[2] = POKE_PERSONAL_GetParam((const struct Personal *)personal, 0x1C);
    POKE_PERSONAL_Delete((void *)personal);
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
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_ABILITY, ability[0]);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_NATURE, data->nature);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_CONTEST_COOL, data->contest[0]);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_CONTEST_BEAUTY, data->contest[1]);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_CONTEST_CUTE, data->contest[2]);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_CONTEST_SMART, data->contest[3]);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_CONTEST_TOUGH, data->contest[4]);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_HELD_ITEM, data->heldItem);
    str = (u32)FLD_TRADE_GetMessageString(heapId, data->otNameMsgId);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_OT_NAME_STRBUF, str);
    STRBUF_Delete((struct U16Vec *)str);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_OT_GENDER, data->otGender);
    POKE_TOOL_SetPartyValue(mon, POKE_TOOL_PARAM_LANGUAGE, data->language);
    SAVE_EVENT_Write(mon, 1, (u32)GAME_DATA_GetMyStatus(gameData), 0x7532, heapId);
    FLD_TRADE_DumpPokemonParams((int)mon);
    POKE_TOOL_RecalcParam(mon);
}

/*
 * Reads 33 Pokemon params and drops the values: a debug dump whose print
 * calls are compiled out.
 */
void FLD_TRADE_DumpPokemonParams(int mon)
{
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_PERSONALITY, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_SPECIES, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_FORM, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_HELD_ITEM, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_OT_ID, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_EXP, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_FRIENDSHIP, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_ABILITY, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_GENDER, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_NATURE, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_MARKINGS, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_LANGUAGE, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_EV_HP, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_EV_ATTACK, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_EV_DEFENSE, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_EV_SPEED, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_EV_SP_ATTACK, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_EV_SP_DEFENSE, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_CONTEST_COOL, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_CONTEST_BEAUTY, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_CONTEST_CUTE, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_CONTEST_SMART, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_CONTEST_TOUGH, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_CONTEST_SHEEN, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_IV_HP, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_IV_ATTACK, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_IV_DEFENSE, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_IV_SPEED, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_IV_SP_ATTACK, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_IV_SP_DEFENSE, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_OT_GENDER, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_LEVEL, 0);
    POKE_TOOL_GetPartyValue((void *)mon, POKE_TOOL_PARAM_EGG_LOCATION, 0);
}

/* Debug dump of a trade record; empty in the release build. */
void FLD_TRADE_DumpTradeData(FldTradeData *data)
{
}

/*
 * Trade event: build the trader's Pokemon, run the ov119 trade demo, put the
 * received Pokemon in the party and register it in the Pokedex. Step 3 (the
 * ov195 trade evolution) is never reached: step 2 goes straight to 4.
 */
int FLD_TRADE_EventMain(void *event, u32 *seq, FldTradeEvent *work)
{
    void *gsys = work->gsys;
    void *gameData = work->gameData;
    void *party = work->party;
    void *fieldmap = GAMESYSTEM_GetFieldMap(gsys);
    void *sentMon = POKEPARTY_GetMember(party, work->partyIndex);
    FldTradeHolder *holder;
    void *demoFieldmap;
    void *zukan;
    u32 evolveMethod;
    u32 newSpecies;
    FldTradeEvolveParam *evolveParam;

    switch (*seq) {
    case 0:
        holder = FLD_TRADE_Create(4, work->tradeId);
        work->holder = holder;
        FLD_TRADE_BuildPokemon(gameData, 4, holder->mon, holder->data, work->tradeId);
        FLD_TRADE_DumpPokemonParams((int)work->holder->mon);
        FLD_TRADE_DumpTradeData(work->holder->data);
        *seq = 1;
        break;
    case 1:
        demoFieldmap = GAMESYSTEM_GetFieldMap(gsys);
        work->demoParam.gameData = gameData;
        work->demoParam.playerStatus = GAME_DATA_GetMyStatus(gameData);
        work->demoParam.sentMon = sentMon;
        work->demoParam.traderStatus = work->holder->traderStatus;
        work->demoParam.receivedMon = work->holder->mon;
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcEvent(gsys, (int)demoFieldmap, (int)ov119_id, (int)d_021E75A8, (int)&work->demoParam));
        *seq = 2;
        break;
    case 2:
        POKEPARTY_SetMember(party, work->partyIndex, work->holder->mon);
        zukan = ZUKAN_SAVE_GetFromGameData(gameData);
        ZUKAN_SAVE_RegisterSeen(zukan, work->holder->mon);
        ZUKAN_SAVE_RegisterCaught(zukan, work->holder->mon);
        *seq = 4;
        break;
    case 3:
        newSpecies = SHINKA_CHECK_CheckEvolution(party, sentMon, 1, 0, GAME_DATA_GetSeason(gameData), &evolveMethod, 4);
        if (newSpecies != 0) {
            evolveParam = GFL_HEAP_Alloc(4, 0x14, 0, d_021DE59C, 0x1F0);
            evolveParam->gameData = gameData;
            evolveParam->party = party;
            evolveParam->newSpecies = newSpecies;
            evolveParam->partyIndex = work->partyIndex;
            evolveParam->evolveMethod = evolveMethod;
            evolveParam->mode = 1;
            evolveParam->result = 0;
            work->evolveParam = evolveParam;
            GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcEvent(gsys, (int)fieldmap, (int)ov195_id, (int)d_02208C40, (int)evolveParam));
        }
        *seq = 4;
        break;
    case 4:
        if (work->evolveParam != 0)
            GFL_HEAP_Free(work->evolveParam);
        FLD_TRADE_Delete(work->holder);
        return 1;
    }
    return 0;
}

/* Creates the trade event for trade record tradeId and party slot partyIndex. */
void *FLD_TRADE_CreateEvent(void *gsys, u32 tradeId, u32 partyIndex)
{
    void *gameData;
    void *party;
    void *event;
    FldTradeEvent *work;

    gameData = GAMESYSTEM_GetGameData(gsys);
    party = GAME_DATA_GetMyParty(gameData);
    event = GAME_EVENT_Create(gsys, 0, (void *)FLD_TRADE_EventMain, 0x5c);
    work = GAME_EVENT_GetWork(event);
    work->gsys = gsys;
    work->gameData = gameData;
    work->party = party;
    work->tradeId = tradeId;
    work->partyIndex = partyIndex;
    work->evolveParam = 0;
    return event;
}

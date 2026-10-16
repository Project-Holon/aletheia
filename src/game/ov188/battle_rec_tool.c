/*
 * file:     battle_rec_tool.c
 * unit:     yes
 * function: BATTLE_REC_TOOL_PackMon, BATTLE_REC_TOOL_UnpackMon, BATTLE_REC_TOOL_PackSetup, BATTLE_REC_TOOL_UnpackSetup, BATTLE_REC_TOOL_PackParty, BATTLE_REC_TOOL_UnpackParty, BATTLE_REC_TOOL_PackParties, BATTLE_REC_TOOL_UnpackParties, BATTLE_REC_TOOL_PackPlayers, BATTLE_REC_TOOL_UnpackPlayers, BATTLE_REC_TOOL_PackPlayerProfile, BATTLE_REC_TOOL_UnpackPlayerProfile, BATTLE_REC_TOOL_PackInputLog, BATTLE_REC_TOOL_UnpackInputLog, BATTLE_REC_TOOL_PackBattleRules, BATTLE_REC_TOOL_UnpackBattleRules
 * address:  0x021EE920
 * region:   ov188
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from battle_rec_tool.c, ov188_func_021EF2D4.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   POKE_CRYPTO_XorBlock 0x02019A50 thumb
 *   POKE_TOOL_GetBoxSubstruct 0x02019C38 thumb
 *   POKE_CRYPTO_Checksum 0x02019A9C thumb
 *   g_0214616C     0x0214616C  data
 *   BATTLE_REC_TOOL_UnpackBattleRules  0x021EF2D4  thumb  ov188
 *   POKEPARTY_GetCapacity   0x0201AA14  thumb
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   POKEPARTY_GetMember   0x0201AB28  thumb
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   POKEPARTY_InitEx 0x0201A954 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   d_021EF360 0x021EF360 data a4
 *   MYSTATUS_Copy 0x02008494 thumb
 *   STRBUF_ToChars 0x02045A38 arm
 *   STRBUF_SetString 0x02045924 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   CONFIG_Copy  0x02008314  thumb
 */
#include "../arm9/poke_tool_types.h"
#include "battle_rec_tool_types.h"

struct Party;
struct StrBuf;
struct MyStatus;
struct Config;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern void MI_CpuFill8(void *,int,u32);

extern void POKE_CRYPTO_XorBlock(u16 *,u32,u32);

extern void *POKE_TOOL_GetBoxSubstruct(struct BoxPokemon *,u32,u32);

extern u16 POKE_CRYPTO_Checksum(const u16 *,u32);

extern int BATTLE_REC_TOOL_UnpackBattleRules(struct BattleSetupParam *setup, const struct BattleRecData *rec);

extern u32 POKEPARTY_GetCapacity(struct Party *p);

extern u32 POKEPARTY_GetCount(struct Party *);

extern struct PokemonParam *POKEPARTY_GetMember(struct Party *p, u32 idx);

extern u32 POKE_TOOL_GetPartyParamSize(void);

extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);

extern void POKEPARTY_InitEx(struct Party *p, s32 capacity);

extern void POKE_TOOL_SetPartyValue(void *,u32,u32);

extern u32 POKEPARTY_Add(struct Party *p, const struct PokemonParam *src);

extern u32 GFL_HEAP_Free(void *p);

extern void MYSTATUS_Copy(void *, void *);

extern void STRBUF_ToChars(struct StrBuf *vec, u16 *out, u32 n);

extern void STRBUF_SetString(struct StrBuf *o, const u16 *src);

extern u16 *STRBUF_GetChars(struct StrBuf *vec);

extern u16 STRBUF_GetEosChar(void);

extern void MI_CpuCopy8(void *, void *, int);

extern void CONFIG_Copy(void *a, void *b);

void BATTLE_REC_TOOL_PackMon(struct PokemonParam *mon, struct BattleRecMon *rec);

void BATTLE_REC_TOOL_UnpackMon(struct BattleRecMon *rec, struct PokemonParam *mon);

void BATTLE_REC_TOOL_PackSetup(struct BattleSetupParam *setup);

void BATTLE_REC_TOOL_UnpackSetup(struct BattleSetupParam *setup, u32 heapId);

void BATTLE_REC_TOOL_PackParty(struct Party *party, struct BattleRecParty *rec);

void BATTLE_REC_TOOL_UnpackParty(struct BattleRecParty *rec, struct Party *party, u32 heapId);

void BATTLE_REC_TOOL_PackParties(struct BattleSetupParam *setup, struct BattleRecData *rec);

void BATTLE_REC_TOOL_UnpackParties(struct BattleSetupParam *setup, struct BattleRecData *rec, u32 heapId);

void BATTLE_REC_TOOL_PackPlayers(struct BattleSetupParam *setup, struct BattleRecData *rec);

void BATTLE_REC_TOOL_UnpackPlayers(struct BattleSetupParam *setup, struct BattleRecData *rec);

void BATTLE_REC_TOOL_PackPlayerProfile(struct BattleTrainerData *trainer, struct BattleRecTrainer *rec);

void BATTLE_REC_TOOL_UnpackPlayerProfile(struct BattleTrainerData *trainer, struct BattleRecTrainer *rec);

int BATTLE_REC_TOOL_PackInputLog(struct BattleSetupParam *setup, struct BattleRecData *rec);

int BATTLE_REC_TOOL_UnpackInputLog(struct BattleSetupParam *setup, struct BattleRecData *rec);

int BATTLE_REC_TOOL_PackBattleRules(struct BattleSetupParam *setup, struct BattleRecData *rec);

extern struct BattleRec *g_0214616C;

extern char d_021EF360[];

/* Pack a Pokemon into its 0x70-byte replay form. The box blocks are shuffled by the personality value. */
void BATTLE_REC_TOOL_PackMon(struct PokemonParam *mon, struct BattleRecMon *rec)
{
    struct BoxPokemonBlockA *blockA;
    struct BoxPokemonBlockB *blockB;
    struct BoxPokemonBlockC *blockC;
    struct BoxPokemonBlockD *blockD;
    int i;
    MI_CpuFill8(rec,0,sizeof(struct BattleRecMon));
    if (!mon->box.partyDecoded) {
        POKE_CRYPTO_XorBlock((u16 *)&mon->statusCondition,0x54,mon->box.personality);
        POKE_CRYPTO_XorBlock((u16 *)mon->box.blocks,0x80,mon->box.checksum);
    }
    blockA=POKE_TOOL_GetBoxSubstruct(&mon->box,mon->box.personality,0);
    blockB=POKE_TOOL_GetBoxSubstruct(&mon->box,mon->box.personality,1);
    blockC=POKE_TOOL_GetBoxSubstruct(&mon->box,mon->box.personality,2);
    blockD=POKE_TOOL_GetBoxSubstruct(&mon->box,mon->box.personality,3);
    rec->personality=mon->box.personality;
    rec->partyDecoded=0;
    rec->boxDecoded=0;
    rec->checksumFailed=mon->box.checksumFailed;
    rec->nature=blockB->nature;
    rec->species=blockA->species;
    rec->heldItem=blockA->heldItem;
    rec->otId=blockA->otId;
    rec->exp=blockA->exp;
    rec->friendship=blockA->friendship;
    rec->ability=blockA->ability;
    rec->evs[0]=blockA->evs[0];
    rec->evs[1]=blockA->evs[1];
    rec->evs[2]=blockA->evs[2];
    rec->evs[3]=blockA->evs[3];
    rec->evs[4]=blockA->evs[4];
    rec->evs[5]=blockA->evs[5];
    rec->language=blockA->language;
    for(i=0;i<4;i++) {
        rec->moves[i]=blockB->moves[i];
        rec->pp[i]=blockB->pp[i];
        rec->ppUps[i]=blockB->ppUps[i];
    }
    rec->ivHp=blockB->ivHp;
    rec->ivAttack=blockB->ivAttack;
    rec->ivDefense=blockB->ivDefense;
    rec->ivSpeed=blockB->ivSpeed;
    rec->ivSpAttack=blockB->ivSpAttack;
    rec->ivSpDefense=blockB->ivSpDefense;
    rec->isEgg=blockB->isEgg;
    rec->hasNickname=blockB->hasNickname;
    rec->fatefulEncounter=blockB->fatefulEncounter;
    rec->gender=blockB->gender;
    rec->form=blockB->form;
    for(i=0;i<11;i++) rec->nickname[i]=blockC->nickname[i];
    for(i=0;i<8;i++) rec->otName[i]=blockD->otName[i];
    rec->ball=blockD->ball;
    rec->statusCondition=mon->statusCondition;
    rec->level=mon->level;
    rec->capsuleIndex=mon->capsuleIndex;
    rec->hp=mon->hp;
    rec->maxHp=mon->maxHp;
    rec->attack=mon->attack;
    rec->defense=mon->defense;
    rec->speed=mon->speed;
    rec->spAttack=mon->spAttack;
    rec->spDefense=mon->spDefense;
    if (!mon->box.partyDecoded) {
        POKE_CRYPTO_XorBlock((u16 *)&mon->statusCondition,0x54,mon->box.personality);
        POKE_CRYPTO_XorBlock((u16 *)mon->box.blocks,0x80,mon->box.checksum);
    }
}

/* Rebuild a Pokemon from its replay form and re-encrypt it. */
void BATTLE_REC_TOOL_UnpackMon(struct BattleRecMon *rec, struct PokemonParam *mon)
{
    struct BoxPokemonBlockA *blockA;
    struct BoxPokemonBlockB *blockB;
    struct BoxPokemonBlockC *blockC;
    struct BoxPokemonBlockD *blockD;
    int i;
    MI_CpuFill8(mon,0,sizeof(struct PokemonParam));
    blockA=POKE_TOOL_GetBoxSubstruct(&mon->box,rec->personality,0);
    blockB=POKE_TOOL_GetBoxSubstruct(&mon->box,rec->personality,1);
    blockC=POKE_TOOL_GetBoxSubstruct(&mon->box,rec->personality,2);
    blockD=POKE_TOOL_GetBoxSubstruct(&mon->box,rec->personality,3);
    mon->box.personality=rec->personality;
    mon->box.partyDecoded=0;
    mon->box.boxDecoded=0;
    mon->box.checksumFailed=rec->checksumFailed;
    blockA->species=rec->species;
    blockA->heldItem=rec->heldItem;
    blockA->otId=rec->otId;
    blockA->exp=rec->exp;
    blockA->friendship=rec->friendship;
    blockA->ability=rec->ability;
    blockA->evs[0]=rec->evs[0];
    blockA->evs[1]=rec->evs[1];
    blockA->evs[2]=rec->evs[2];
    blockA->evs[3]=rec->evs[3];
    blockA->evs[4]=rec->evs[4];
    blockA->evs[5]=rec->evs[5];
    blockA->language=rec->language;
    for(i=0;i<4;i++) {
        blockB->moves[i]=rec->moves[i];
        blockB->pp[i]=rec->pp[i];
        blockB->ppUps[i]=rec->ppUps[i];
    }
    blockB->ivHp=rec->ivHp;
    blockB->ivAttack=rec->ivAttack;
    blockB->ivDefense=rec->ivDefense;
    blockB->ivSpeed=rec->ivSpeed;
    blockB->ivSpAttack=rec->ivSpAttack;
    blockB->ivSpDefense=rec->ivSpDefense;
    blockB->isEgg=rec->isEgg;
    blockB->hasNickname=rec->hasNickname;
    blockB->fatefulEncounter=rec->fatefulEncounter;
    blockB->gender=rec->gender;
    blockB->form=rec->form;
    blockB->nature=rec->nature;
    for(i=0;i<11;i++) blockC->nickname[i]=rec->nickname[i];
    for(i=0;i<8;i++) blockD->otName[i]=rec->otName[i];
    blockD->ball=rec->ball;
    mon->statusCondition=rec->statusCondition;
    mon->level=rec->level;
    mon->capsuleIndex=rec->capsuleIndex;
    mon->hp=rec->hp;
    mon->maxHp=rec->maxHp;
    mon->attack=rec->attack;
    mon->defense=rec->defense;
    mon->speed=rec->speed;
    mon->spAttack=rec->spAttack;
    mon->spDefense=rec->spDefense;
    POKE_CRYPTO_XorBlock((u16 *)&mon->statusCondition,0x54,mon->box.personality);
    mon->box.checksum=POKE_CRYPTO_Checksum((u16 *)mon->box.blocks,0x80);
    POKE_CRYPTO_XorBlock((u16 *)mon->box.blocks,0x80,mon->box.checksum);
}

void BATTLE_REC_TOOL_PackSetup(struct BattleSetupParam *setup)
{
    struct BattleRecData *rec = &g_0214616C->data;

    BATTLE_REC_TOOL_PackParties(setup, rec);
    BATTLE_REC_TOOL_PackPlayers(setup, rec);
    BATTLE_REC_TOOL_PackInputLog(setup, rec);
    BATTLE_REC_TOOL_PackBattleRules(setup, rec);
}

void BATTLE_REC_TOOL_UnpackSetup(struct BattleSetupParam *setup, u32 heapId)
{
    struct BattleRecData *rec = &g_0214616C->data;

    BATTLE_REC_TOOL_UnpackParties(setup, rec, heapId);
    BATTLE_REC_TOOL_UnpackPlayers(setup, rec);
    BATTLE_REC_TOOL_UnpackInputLog(setup, rec);
    BATTLE_REC_TOOL_UnpackBattleRules(setup, rec);
}

/* Pack a party: clear the record, store capacity and count, pack every member. */
void BATTLE_REC_TOOL_PackParty(struct Party *party, struct BattleRecParty *rec)
{
    int i;
    MI_CpuFill8(rec, 0, sizeof(struct BattleRecParty));
    if (POKEPARTY_GetCount(party) == 0)
        return;
    rec->capacity = POKEPARTY_GetCapacity(party);
    rec->count = POKEPARTY_GetCount(party);
    for (i = 0; i < rec->count; i++)
        BATTLE_REC_TOOL_PackMon(POKEPARTY_GetMember(party, i), &rec->members[i]);
}

void BATTLE_REC_TOOL_UnpackParty(struct BattleRecParty *rec, struct Party *party, u32 heapId)
{
    int i;
    struct PokemonParam *mon;
    mon=GFL_HEAP_Alloc((u16)((heapId & 0x7FFF)|0x8000),POKE_TOOL_GetPartyParamSize(),1,d_021EF360,173);
    POKEPARTY_InitEx(party,rec->capacity);
    for(i=0;i<rec->count;i++) {
        BATTLE_REC_TOOL_UnpackMon(&rec->members[i],mon);
        POKE_TOOL_SetPartyValue(mon,159,0);
        POKEPARTY_Add(party,mon);
    }
    GFL_HEAP_Free(mon);
}

void BATTLE_REC_TOOL_PackParties(struct BattleSetupParam *setup, struct BattleRecData *rec)
{
    unsigned int i;
    MI_CpuFill8(rec->parties, 0, sizeof(rec->parties));
    for (i = 0; i < 4; i++) {
        struct Party *party = setup->party[i];
        if (party != 0)
            BATTLE_REC_TOOL_PackParty(party, &rec->parties[i]);
    }
}

void BATTLE_REC_TOOL_UnpackParties(struct BattleSetupParam *setup, struct BattleRecData *rec, u32 heapId)
{
    u32 i = 0;

    for (; i < 4; i++) {
        struct Party *party = setup->party[i];

        if (party != 0)
            BATTLE_REC_TOOL_UnpackParty(&rec->parties[i], party, heapId);
    }
}

void BATTLE_REC_TOOL_PackPlayers(struct BattleSetupParam *setup, struct BattleRecData *rec)
{
    unsigned i;
    for(i=0;i<4;i++) {
        if (setup->trainerData[i]) {
            BATTLE_REC_TOOL_PackPlayerProfile(setup->trainerData[i], &rec->players[i].data.trainer);
            rec->players[i].kind = BATTLE_REC_PLAYER_TRAINER;
        } else if (setup->playerStatus[i]) {
            MYSTATUS_Copy(setup->playerStatus[i], rec->players[i].data.status);
            rec->players[i].kind = BATTLE_REC_PLAYER_STATUS;
        } else {
            rec->players[i].kind = BATTLE_REC_PLAYER_NONE;
        }
        rec->players[i].voiceFlags = setup->voiceFlags[i];
    }
}

void BATTLE_REC_TOOL_UnpackPlayers(struct BattleSetupParam *setup, struct BattleRecData *rec)
{
    unsigned i;
    for(i=0;i<4;i++) {
        switch(rec->players[i].kind) {
        case BATTLE_REC_PLAYER_STATUS: MYSTATUS_Copy(rec->players[i].data.status, setup->playerStatus[i]); break;
        case BATTLE_REC_PLAYER_TRAINER: BATTLE_REC_TOOL_UnpackPlayerProfile(setup->trainerData[i], &rec->players[i].data.trainer); break;
        }
        setup->voiceFlags[i] = rec->players[i].voiceFlags;
    }
}

/* winWord and loseWord are read and written as eight halfwords (winWords[0..3]
 * and loseWords[0..3] through the union in BattleTrainerData). */
void BATTLE_REC_TOOL_PackPlayerProfile(struct BattleTrainerData *trainer, struct BattleRecTrainer *rec)
{
    unsigned i;
    rec->trainerId = trainer->trainerId;
    rec->trainerType = trainer->trainerType;
    rec->aiFlags = trainer->aiFlags;
    rec->winWords[0] = trainer->winWords[0];
    rec->winWords[1] = trainer->winWords[1];
    rec->winWords[2] = trainer->winWords[2];
    rec->winWords[3] = trainer->winWords[3];
    rec->loseWords[0] = trainer->loseWords[0];
    rec->loseWords[1] = trainer->loseWords[1];
    rec->loseWords[2] = trainer->loseWords[2];
    rec->loseWords[3] = trainer->loseWords[3];
    for(i=0;i<4;i++) rec->itemIds[i] = trainer->itemIds[i];
    STRBUF_ToChars(trainer->name, rec->name, 16);
}

void BATTLE_REC_TOOL_UnpackPlayerProfile(struct BattleTrainerData *trainer, struct BattleRecTrainer *rec)
{
    unsigned i;
    u16 *p;
    trainer->trainerId = rec->trainerId;
    trainer->trainerType = rec->trainerType;
    trainer->aiFlags = rec->aiFlags;
    trainer->winWords[0] = rec->winWords[0];
    trainer->winWords[1] = rec->winWords[1];
    trainer->winWords[2] = rec->winWords[2];
    trainer->winWords[3] = rec->winWords[3];
    trainer->loseWords[0] = rec->loseWords[0];
    trainer->loseWords[1] = rec->loseWords[1];
    trainer->loseWords[2] = rec->loseWords[2];
    trainer->loseWords[3] = rec->loseWords[3];
    for(i=0;i<4;i++) trainer->itemIds[i] = rec->itemIds[i];
    STRBUF_SetString(trainer->name, rec->name);
    p = STRBUF_GetChars(trainer->name);
    while (*p != STRBUF_GetEosChar()) p++;
}

int BATTLE_REC_TOOL_PackInputLog(struct BattleSetupParam *setup, struct BattleRecData *rec)
{
    void *log = setup->recordBuffer;

    if (log != 0) {
        u32 size = setup->recordSize;

        if (size < 0xc00) {
            rec->inputLogSize = size;
            MI_CpuCopy8(log, rec->inputLog, size);
            return 1;
        }
    }
    return 0;
}

int BATTLE_REC_TOOL_UnpackInputLog(struct BattleSetupParam *setup, struct BattleRecData *rec)
{
    int size = rec->inputLogSize;

    setup->recordSize = size;
    MI_CpuCopy8(rec->inputLog, setup->recordBuffer, size);
    return 1;
}

int BATTLE_REC_TOOL_PackBattleRules(struct BattleSetupParam *setup, struct BattleRecData *rec)
{
    rec->field = setup->fieldSituation;
    rec->rng = setup->rng;
    rec->bgmBattle = setup->bgmBattle;
    rec->bgmWin = setup->bgmWin;
    rec->competitor = setup->competitor;
    rec->rule = setup->rule;
    rec->multiMode = setup->multiMode;
    rec->resultCount = setup->resultCount;
    rec->netId = setup->netId;
    rec->recordEnabled = (setup->recordEnabled != 0);
    CONFIG_Copy(setup->config, rec->config);
    return 1;
}

int BATTLE_REC_TOOL_UnpackBattleRules(struct BattleSetupParam *setup, const struct BattleRecData *rec)
{
    setup->fieldSituation = rec->field;
    setup->rng = rec->rng;
    setup->bgmBattle = rec->bgmBattle;
    setup->bgmWin = rec->bgmWin;
    setup->competitor = rec->competitor;
    setup->rule = rec->rule;
    setup->multiMode = rec->multiMode;
    setup->resultCount = rec->resultCount;
    setup->netId = rec->netId;
    setup->recordEnabled = rec->recordEnabled;
    return 1;
}

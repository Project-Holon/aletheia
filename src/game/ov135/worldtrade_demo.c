/*
 * file:     worldtrade_demo.c
 * unit:     yes
 * function: WORLDTRADE_DEMO_Init, WORLDTRADE_DEMO_EvolveStep, WORLDTRADE_DEMO_Exit, WORLDTRADE_DEMO_CreateMyStatusFromEntry, WORLDTRADE_DEMO_GetSlotRecord, WORLDTRADE_DEMO_InitSlotRecord
 * address:  0x021F6E58
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_box.c, worldtrade_enter.c, worldtrade_adapter.c, WORLDTRADE_ADAPTER_QueueMessagePrint.c by tools/splitfile.py.
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_AllocHeapBuf  0x02202608  thumb
 *   ov067_id  0x00000043  data
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   GF_PANIC_Fail 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   WORLDTRADE_NoOp  0x0200ADB4  thumb
 *   WORLDTRADE_CopyPokemon  0x0200AD9C  thumb
 *   POKE_TOOL_CopyPartyPokemon  0x02019CE0  thumb
 *   PROCSYS_Push  0x02031348  arm
 *   str_02203B6C   0x02203B6C  data  a1
 *   d_021E75B4     0x021E75B4  data  ov119
 *   d_021E75CC     0x021E75CC  data  ov119
 *   d_021E75FC     0x021E75FC  data  ov119
 *   ov119_id       0x00000077  data
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   SHINKA_CHECK_CheckEvolution  0x0201B2B0  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   d_02208C40     0x02208C40  data  ov195
 *   ov195_id       0x000000C3  data
 *   MYSTATUS_Create  0x0200846C  thumb
 *   MYSTATUS_Init  0x020084A0  thumb
 *   MYSTATUS_CopyName  0x020084D4  thumb
 *   MYSTATUS_SetRomCode  0x02008560  thumb
 *   MYSTATUS_SetLanguage  0x02008568  thumb
 *   MYSTATUS_SetSex  0x0200854C  thumb
 *   MYSTATUS_SetTrainerView  0x02008558  thumb
 *   MYSTATUS_SetNationAndArea  0x02008574  thumb
 *   WORLDTRADE_ADAPTER_CopyMon  0x0220262C  thumb
 *   BOX_SAVEDATA_ClearPokemon  0x02007664  thumb
 *   BOX_SAVEDATA_FindFreeSlot  0x020076D0  thumb
 *   BOX_SAVEDATA_AddPokemonToBox  0x0200752C  thumb
 *   WORLDTRADE_ExitPlanes 0x021F50EC thumb ov135
 *   WORLDTRADE_ClearAndShowPlanes  0x021F5074  thumb  ov135
 *   WORLDTRADE_AdvanceScreenId  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_ADAPTER_QueueMessagePrint  0x02202B20  thumb
 *   WORLDTRADE_DEMO_CreateMyStatusFromEntry 0x021F72C4 thumb ov135
 */
#include "worldtrade_types.h"

typedef struct {
    u8 pad0[0x10];
    u32 trainerId;
    u32 profileId;
} TradePartnerInfo;

extern int GF_OVERLAY_Load(s32 handle);

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void *WORLDTRADE_ADAPTER_AllocHeapBuf(u32 heap);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void GF_OVERLAY_Unload(s32 handle);

extern void GF_PANIC_Fail(const char *expr, u32 line, const char *file);

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);

extern void *POKEPARTY_GetMember(void *p, u32 idx);

extern void *POKE_TOOL_GetBoxParam(void *a);

extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);

extern void *WORLDTRADE_NoOp(void *sys);

extern void WORLDTRADE_CopyPokemon(void *sys, void *mon);

extern void POKE_TOOL_CopyPartyPokemon(const struct RecDC *src, struct RecDC *dest);

extern void PROCSYS_Push(void *h, u32 id, void *a, void *b);

extern u8 GAME_DATA_GetSeason(const struct BigObj *p);

extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);

extern struct Party *POKEPARTY_Create(u32 heap);

extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);

extern void *MYSTATUS_Create(int heap_id);

extern void MYSTATUS_Init(struct Sub0200852CObj *p);

extern u32 MYSTATUS_CopyName(u32 value, void *dst);

extern void MYSTATUS_SetRomCode(struct Sub0200852CObj *obj, u8 value);

extern void MYSTATUS_SetLanguage(struct Sub0200852CObj *obj, u8 value);

extern void MYSTATUS_SetSex(struct Sub0200852CObj *obj, u8 value);

extern void MYSTATUS_SetTrainerView(struct Sub0200852CObj *obj, u8 value);

extern void MYSTATUS_SetNationAndArea(struct Sub0200852CObj *obj, u8 a, u8 b);

extern void WORLDTRADE_ADAPTER_CopyMon(u32 a, u32 b);

extern void BOX_SAVEDATA_ClearPokemon(void *save, u32 box, u32 slot);

extern int BOX_SAVEDATA_FindFreeSlot(void *save, int *pbox, int *pslot);

extern int BOX_SAVEDATA_AddPokemonToBox(void **save, u32 box, const struct Sub02007454Entry *src);

void WORLDTRADE_SetStateAndReturn(Work *p, u32 a, u32 b);

void WORLDTRADE_AdvanceScreenId(Work *p);

void WORLDTRADE_ClearAndShowPlanes(Work *p);

void WORLDTRADE_ExitPlanes(Work *p);

int WORLDTRADE_DEMO_Init(Work *p);

int WORLDTRADE_DEMO_EvolveStep(Work *p);

int WORLDTRADE_DEMO_Exit(Work *p);

TradePartnerInfo *WORLDTRADE_DEMO_CreateMyStatusFromEntry(Entry *e);

Entry *WORLDTRADE_DEMO_GetSlotRecord(Work *p, int kind);

void WORLDTRADE_DEMO_InitSlotRecord(Work *p);

extern u8 ov067_id[];

extern char str_02203B6C[];

extern u8 d_021E75B4[];

extern u8 d_021E75CC[];

extern u8 d_021E75FC[];

extern u8 ov119_id[];

extern u8 d_02208C40[];

extern u8 ov195_id[];

int WORLDTRADE_DEMO_Init(Work *p)
{
    Req *d;
    void *tmpl;

    WORLDTRADE_ExitPlanes(p);
    p->req = GFL_HEAP_Alloc(0x48, 0x44, 0, str_02203B6C, 0x5E);
    MI_CpuFill8(p->req, 0, 0x44);
    d = p->req;
    p->monCopy = WORLDTRADE_ADAPTER_AllocHeapBuf(0x48);
    d->tradeGameData = GAMESYSTEM_GetGameData(p->ctx->gameData);
    d->myStatus = p->ctx->myStatus_u;
    switch (p->kind) {
    case 7:
        d->partnerMon = d->ownMon = WORLDTRADE_NoOp(p->ctx->sys);
        d->partnerStatus = p->info = (void *)WORLDTRADE_DEMO_CreateMyStatusFromEntry(p->ent);
        tmpl = d_021E75FC;
        break;
    case 8:
        if (p->receivedEgg != 0) {
            d->partnerMon = p->ent;
        } else {
            d->partnerMon = WORLDTRADE_NoOp(p->ctx->sys);
        }
        d->ownMon = d->partnerMon;
        d->partnerStatus = p->info = (void *)WORLDTRADE_DEMO_CreateMyStatusFromEntry(p->ent);
        tmpl = d_021E75B4;
        break;
    case 10:
        if (p->receivedEgg != 0) {
            d->partnerMon = p->ent;
        } else {
            d->partnerMon = WORLDTRADE_NoOp(p->ctx->sys);
        }
        WORLDTRADE_CopyPokemon(p->ctx->sys, p->monCopy);
        d->ownMon = p->monCopy;
        d->partnerStatus = p->info = (void *)WORLDTRADE_DEMO_CreateMyStatusFromEntry(p->ent);
        tmpl = d_021E75CC;
        break;
    case 9:
        POKE_TOOL_CopyPartyPokemon(p->tradeMon, p->monCopy);
        d->ownMon = p->tradeMon;
        d->partnerMon = &p->arr[p->cur];
        d->partnerStatus = p->info = (void *)WORLDTRADE_DEMO_CreateMyStatusFromEntry(&p->arr[p->cur]);
        tmpl = d_021E75CC;
        break;
    default:
        GF_PANIC_Fail((void *)0x02203B80, 0, (void *)0x02203B80);
        break;
    }
    PROCSYS_Push(p->procSys, (u32)ov119_id, tmpl, p->req);
    p->subLcdRefresh = 1;
    p->keepBgLayers = 0;
    return 1;
}

/*
 * Two-state step. State 0, once the +0x12F4 busy word clears: for kind 9
 * (or kinds 8/10 when the stored entry differs from the one rebuilt from
 * the save data by WORLDTRADE_ADAPTER_AllocHeapBuf/WORLDTRADE_CopyPokemon) build a 0x14-byte request
 * (SHINKA_CHECK_CheckEvolution result, list holding the entry, out byte) at +0x10DC,
 * load overlay 67 and start the overlay-195 task (d_02208C40, hinted to
 * ov195 because this function names ov195_id), then go to state 1; any
 * failure calls WORLDTRADE_SetStateAndReturn(p, 1, 0) and returns 3. State 1 copies the
 * result back into the entry, frees the request, refreshes the record
 * (WORLDTRADE_DEMO_InitSlotRecord), clears the DISPCNT window bits, unloads overlay 67 and
 * calls WORLDTRADE_SetStateAndReturn(p, 7, 0xC). Returns 2 while waiting, else 3.
 */
int WORLDTRADE_DEMO_EvolveStep(Work *p)
{
    int ret = 2;

    switch (p->state_i) {
    case 0:
        if (p->busy_u != 0) {
            break;
        }
        if (p->kind == 9) {
            void *e = (void *)WORLDTRADE_DEMO_GetSlotRecord((Work *)p, p->kind);
            u32 out;
            u32 r;

            POKE_TOOL_GetPartyValue(e, 6, 0);
            r = SHINKA_CHECK_CheckEvolution(0, e, 1, (u32)p->monCopy, GAME_DATA_GetSeason(GAMESYSTEM_GetGameData((const struct Ctx *)p->ctx->gameData)), &out, 0x48);
            if (r != 0) {
                Req *w;

                if (p->req != 0) {
                    GFL_HEAP_Free(p->req);
                    p->req = 0;
                }
                p->req = GFL_HEAP_Alloc(0x48, 0x14, 0, str_02203B6C, 0xEB);
                MI_CpuFill8(p->req, 0, 0x14);
                w = p->req;
                w->evoGameData = GAMESYSTEM_GetGameData((const struct Ctx *)p->ctx->gameData);
                w->list = POKEPARTY_Create(0x48);
                POKEPARTY_Add(w->list, (const struct PartyMon *)e);
                w->evoSpecies = r;
                w->evoPartyPos = 0;
                w->evoCondition = out;
                w->evoFlag = 1;
                w->evoResult = 0;
                GF_OVERLAY_Unload((u32)ov067_id);
                PROCSYS_Push(p->procSys, (u32)ov195_id, d_02208C40, p->req);
                p->state_i = 1;
            } else {
                WORLDTRADE_SetStateAndReturn(p, 1, 0);
                ret = 3;
            }
        } else if (p->kind == 8 || p->kind == 10) {
            void *e = (void *)WORLDTRADE_DEMO_GetSlotRecord((Work *)p, p->kind);
            void *mon = WORLDTRADE_ADAPTER_AllocHeapBuf(0x48);
            u32 out;
            u32 r;

            WORLDTRADE_CopyPokemon(p->ctx->sys, mon);
            if (POKE_TOOL_GetPartyValue(e, 5, 0) != POKE_TOOL_GetPartyValue(mon, 5, 0)
                || POKE_TOOL_GetPartyValue(e, 0, 0) != POKE_TOOL_GetPartyValue(mon, 0, 0)) {
                POKE_TOOL_GetPartyValue(e, 6, 0);
                r = 0;
                if (p->checkEvolution != 0) {
                    p->checkEvolution = 0;
                    r = SHINKA_CHECK_CheckEvolution(0, e, 1, (u32)mon, GAME_DATA_GetSeason(GAMESYSTEM_GetGameData((const struct Ctx *)p->ctx->gameData)), &out, 0x48);
                }
                if (r != 0) {
                    Req *w;

                    if (p->req != 0) {
                        GFL_HEAP_Free(p->req);
                        p->req = 0;
                    }
                    p->req = GFL_HEAP_Alloc(0x48, 0x14, 0, str_02203B6C, 0x130);
                    MI_CpuFill8(p->req, 0, 0x14);
                    w = p->req;
                    w->evoGameData = GAMESYSTEM_GetGameData((const struct Ctx *)p->ctx->gameData);
                    w->list = POKEPARTY_Create(0x48);
                    POKEPARTY_Add(w->list, (const struct PartyMon *)e);
                    w->evoSpecies = r;
                    w->evoPartyPos = 0;
                    w->evoCondition = out;
                    w->evoFlag = 1;
                    w->evoResult = 0;
                    GF_OVERLAY_Unload((u32)ov067_id);
                    PROCSYS_Push(p->procSys, (u32)ov195_id, d_02208C40, p->req);
                    p->state_i = 1;
                } else {
                    WORLDTRADE_SetStateAndReturn(p, 1, 0);
                    ret = 3;
                }
            } else {
                WORLDTRADE_SetStateAndReturn(p, 1, 0);
                ret = 3;
            }
            GFL_HEAP_Free(mon);
        } else {
            WORLDTRADE_SetStateAndReturn(p, 1, 0);
            ret = 3;
        }
        break;
    case 1:
        if (p->busy_u != 0) {
            break;
        }
        if (p->req != 0) {
            Req *w = p->req;
            void *e = (void *)WORLDTRADE_DEMO_GetSlotRecord((Work *)p, p->kind);

            POKE_TOOL_CopyPartyPokemon(POKEPARTY_GetMember(w->list, 0), e);
            GFL_HEAP_Free(w->list);
            GFL_HEAP_Free(p->req);
            p->req = 0;
        }
        WORLDTRADE_DEMO_InitSlotRecord((Work *)p);
        *(volatile u32 *)0x04000000 &= ~0xE000;
        GF_OVERLAY_Load((u32)ov067_id);
        WORLDTRADE_SetStateAndReturn(p, 7, 0xC);
        ret = 3;
        break;
    }
    return ret;
}

/*
 * volatile: 0x021F72AC writes hardware halfword 0x04000050.
 */
int WORLDTRADE_DEMO_Exit(Work *p)
{
    if (p->info) {
        GFL_HEAP_Free(p->info);
        p->info = 0;
    }
    GFL_HEAP_Free(p->monCopy);
    if (p->req) {
        GFL_HEAP_Free(p->req);
        p->req = 0;
    }
    p->checkEvolution = 0;
    WORLDTRADE_ClearAndShowPlanes((Work *)p);
    WORLDTRADE_AdvanceScreenId(p);
    *(volatile unsigned short *)0x04000050 = 0;
    return 0;
}

TradePartnerInfo *WORLDTRADE_DEMO_CreateMyStatusFromEntry(Entry *ent)
{
    TradePartnerInfo *info;

    info = MYSTATUS_Create(0x48);
    MYSTATUS_Init((struct Sub0200852CObj *)info);
    MYSTATUS_CopyName((u32)info, ent->name);
    MYSTATUS_SetRomCode((struct Sub0200852CObj *)info, ent->romCode);
    MYSTATUS_SetLanguage((struct Sub0200852CObj *)info, ent->language);
    MYSTATUS_SetSex((struct Sub0200852CObj *)info, ent->sex);
    MYSTATUS_SetTrainerView((struct Sub0200852CObj *)info, ent->trainerView);
    MYSTATUS_SetNationAndArea((struct Sub0200852CObj *)info, ent->nation, ent->area);
    info->trainerId = ent->trainerId;
    info->profileId = ent->profileId;
    return info;
}

/*
 * Return the slot record for a kind: kind 9 is the current 0x128-byte
 * entry of the +0x20C array (index at +0xD4), kinds 10 and 8 share the
 * record at +0xE4. Any other kind reports through GF_PANIC_Fail (raw
 * address 0x02203B80, a plain constant as in WORLDTRADE_ADAPTER_QueueMessagePrint) and yields 0.
 */
Entry *WORLDTRADE_DEMO_GetSlotRecord(Work *p, int kind)
{
    if (kind == 9) {
        return &p->arr_entry1[p->cur];
    } else if (kind == 10) {
        return &p->single;
    } else if (kind == 8) {
        return &p->single;
    }
    GF_PANIC_Fail((void *)0x02203B80, 0, (void *)0x02203B80);
    return 0;
}

/*
 * Fill the slot record for the current kind (+0x20). A +0xDC source of
 * 0xFF copies party member +0xE0 into it (WORLDTRADE_ADAPTER_CopyMon); otherwise the
 * box/slot pair (+0xDC, +0xE0) is looked up in the storage at +0xC of
 * the context and the found entry is written into the record.
 */
void WORLDTRADE_DEMO_InitSlotRecord(Work *p)
{
    u32 e = (u32)WORLDTRADE_DEMO_GetSlotRecord(p, p->kind);

    if (p->box_u == 0xff) {
        WORLDTRADE_ADAPTER_CopyMon(e, (u32)POKEPARTY_GetMember(p->ctx->party, p->pos));
    } else {
        u32 a;
        u32 b;

        a = 0;
        b = 0;
        BOX_SAVEDATA_ClearPokemon((void *)p->ctx->box, p->box_u, p->pos);
        BOX_SAVEDATA_FindFreeSlot((void *)p->ctx->box, (int *)(&a), (int *)(&b));
        BOX_SAVEDATA_AddPokemonToBox((void **)p->ctx->box, a, (const struct Sub02007454Entry *)((u32)POKE_TOOL_GetBoxParam((void *)e)));
    }
}

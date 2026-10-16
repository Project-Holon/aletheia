/*
 * file:     worldtrade_demo.c
 * unit:     yes
 * function: WORLDTRADE_DEMO_Init, WORLDTRADE_DEMO_EvolveStep, WORLDTRADE_DEMO_Exit, WORLDTRADE_DEMO_ReadMyStatus, WORLDTRADE_DEMO_GetSlotRecord, WORLDTRADE_DEMO_InitSlotRecord
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
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_02034714 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02030734 0x02030734 arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
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
 *   func_02034AC4  0x02034AC4  arm
 *   d_02208C40     0x02208C40  data  ov195
 *   ov195_id       0x000000C3  data
 *   MYSTATUS_Create  0x0200846C  thumb
 *   MYSTATUS_Init  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_02008560  0x02008560  thumb
 *   func_02008568  0x02008568  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02008558  0x02008558  thumb
 *   func_02008574  0x02008574  thumb
 *   WORLDTRADE_ADAPTER_CopyMon  0x0220262C  thumb
 *   func_02007664  0x02007664  thumb
 *   func_020076D0  0x020076D0  thumb
 *   func_0200752C  0x0200752C  thumb
 *   WORLDTRADE_ExitPlanes 0x021F50EC thumb ov135
 *   WORLDTRADE_ClearAndShowPlanes  0x021F5074  thumb  ov135
 *   WORLDTRADE_ClearBusyFlag  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_ADAPTER_QueueMessagePrint  0x02202B20  thumb
 *   WORLDTRADE_DEMO_ReadMyStatus 0x021F72C4 thumb ov135
 */
#include "worldtrade_types.h"

typedef struct {
    u8 pad0[0x10];
    u32 trainerId;
    u32 profileId;
} TradePartnerInfo;

extern int func_02034AC4(s32 handle);

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void *WORLDTRADE_ADAPTER_AllocHeapBuf(u32 heap);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void func_02034A5C(s32 handle);

extern void func_02034714(const char *expr, u32 line, const char *file);

struct Ctx;
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);

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

extern void *MYSTATUS_Create(int a0);

extern void MYSTATUS_Init(struct Sub0200852CObj *p);

extern u32 func_020084D4(u32 value, void *dst);

extern void func_02008560(struct Sub0200852CObj *obj, u8 value);

extern void func_02008568(struct Sub0200852CObj *obj, u8 value);

extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);

extern void func_02008558(struct Sub0200852CObj *obj, u8 value);

extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);

extern void WORLDTRADE_ADAPTER_CopyMon(u32 a, u32 b);

extern void func_02007664(void *save, u32 box, u32 slot);

extern int func_020076D0(void *save, int *pbox, int *pslot);

extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);

void WORLDTRADE_SetStateAndReturn(Work *p, u32 a, u32 b);

void WORLDTRADE_ClearBusyFlag(Work *p);

void WORLDTRADE_ClearAndShowPlanes(Work *p);

void WORLDTRADE_ExitPlanes(Work *p);

int WORLDTRADE_DEMO_Init(Work *p);

int WORLDTRADE_DEMO_EvolveStep(Work *p);

int WORLDTRADE_DEMO_Exit(Work *p);

TradePartnerInfo *WORLDTRADE_DEMO_ReadMyStatus(Entry *e);

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
    p->req = func_02030734(0x48, 0x44, 0, str_02203B6C, 0x5E);
    MI_CpuFill8(p->req, 0, 0x44);
    d = p->req;
    p->fEA4 = WORLDTRADE_ADAPTER_AllocHeapBuf(0x48);
    d->f30 = ICA_ANIME_GetField1C(p->ctx->f40);
    d->f3C = p->ctx->f1C_u;
    switch (p->kind) {
    case 7:
        d->f38 = d->f34 = WORLDTRADE_NoOp(p->ctx->sys);
        d->f40 = p->info = (void *)WORLDTRADE_DEMO_ReadMyStatus(p->ent);
        tmpl = d_021E75FC;
        break;
    case 8:
        if (p->f207 != 0) {
            d->f38 = p->ent;
        } else {
            d->f38 = WORLDTRADE_NoOp(p->ctx->sys);
        }
        d->f34 = d->f38;
        d->f40 = p->info = (void *)WORLDTRADE_DEMO_ReadMyStatus(p->ent);
        tmpl = d_021E75B4;
        break;
    case 10:
        if (p->f207 != 0) {
            d->f38 = p->ent;
        } else {
            d->f38 = WORLDTRADE_NoOp(p->ctx->sys);
        }
        WORLDTRADE_CopyPokemon(p->ctx->sys, p->fEA4);
        d->f34 = p->fEA4;
        d->f40 = p->info = (void *)WORLDTRADE_DEMO_ReadMyStatus(p->ent);
        tmpl = d_021E75CC;
        break;
    case 9:
        POKE_TOOL_CopyPartyPokemon(p->fEA8, p->fEA4);
        d->f34 = p->fEA8;
        d->f38 = &p->arr[p->cur];
        d->f40 = p->info = (void *)WORLDTRADE_DEMO_ReadMyStatus(&p->arr[p->cur]);
        tmpl = d_021E75CC;
        break;
    default:
        func_02034714((void *)0x02203B80, 0, (void *)0x02203B80);
        break;
    }
    PROCSYS_Push(p->f12F0, (u32)ov119_id, tmpl, p->req);
    p->fB8 = 1;
    p->f12E4 = 0;
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
            r = SHINKA_CHECK_CheckEvolution(0, e, 1, (u32)p->fEA4, GAME_DATA_GetSeason(ICA_ANIME_GetField1C((const struct Ctx *)p->ctx->f40)), &out, 0x48);
            if (r != 0) {
                Req *w;

                if (p->req != 0) {
                    func_020307B0(p->req);
                    p->req = 0;
                }
                p->req = func_02030734(0x48, 0x14, 0, str_02203B6C, 0xEB);
                MI_CpuFill8(p->req, 0, 0x14);
                w = p->req;
                w->f0 = ICA_ANIME_GetField1C((const struct Ctx *)p->ctx->f40);
                w->list = POKEPARTY_Create(0x48);
                POKEPARTY_Add(w->list, (const struct PartyMon *)e);
                w->f8 = r;
                w->fA = 0;
                w->fB = out;
                w->fC = 1;
                w->f10 = 0;
                func_02034A5C((u32)ov067_id);
                PROCSYS_Push(p->f12F0, (u32)ov195_id, d_02208C40, p->req);
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
                if (p->f12F8 != 0) {
                    p->f12F8 = 0;
                    r = SHINKA_CHECK_CheckEvolution(0, e, 1, (u32)mon, GAME_DATA_GetSeason(ICA_ANIME_GetField1C((const struct Ctx *)p->ctx->f40)), &out, 0x48);
                }
                if (r != 0) {
                    Req *w;

                    if (p->req != 0) {
                        func_020307B0(p->req);
                        p->req = 0;
                    }
                    p->req = func_02030734(0x48, 0x14, 0, str_02203B6C, 0x130);
                    MI_CpuFill8(p->req, 0, 0x14);
                    w = p->req;
                    w->f0 = ICA_ANIME_GetField1C((const struct Ctx *)p->ctx->f40);
                    w->list = POKEPARTY_Create(0x48);
                    POKEPARTY_Add(w->list, (const struct PartyMon *)e);
                    w->f8 = r;
                    w->fA = 0;
                    w->fB = out;
                    w->fC = 1;
                    w->f10 = 0;
                    func_02034A5C((u32)ov067_id);
                    PROCSYS_Push(p->f12F0, (u32)ov195_id, d_02208C40, p->req);
                    p->state_i = 1;
                } else {
                    WORLDTRADE_SetStateAndReturn(p, 1, 0);
                    ret = 3;
                }
            } else {
                WORLDTRADE_SetStateAndReturn(p, 1, 0);
                ret = 3;
            }
            func_020307B0(mon);
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
            func_020307B0(w->list);
            func_020307B0(p->req);
            p->req = 0;
        }
        WORLDTRADE_DEMO_InitSlotRecord((Work *)p);
        *(volatile u32 *)0x04000000 &= ~0xE000;
        func_02034AC4((u32)ov067_id);
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
        func_020307B0(p->info);
        p->info = 0;
    }
    func_020307B0(p->fEA4);
    if (p->req) {
        func_020307B0(p->req);
        p->req = 0;
    }
    p->f12F8 = 0;
    WORLDTRADE_ClearAndShowPlanes((Work *)p);
    WORLDTRADE_ClearBusyFlag(p);
    *(volatile unsigned short *)0x04000050 = 0;
    return 0;
}

TradePartnerInfo *WORLDTRADE_DEMO_ReadMyStatus(Entry *e)
{
    TradePartnerInfo *info;

    info = MYSTATUS_Create(0x48);
    MYSTATUS_Init((struct Sub0200852CObj *)info);
    func_020084D4((u32)info, e->name);
    func_02008560((struct Sub0200852CObj *)info, e->region);
    func_02008568((struct Sub0200852CObj *)info, e->city);
    func_0200854C((struct Sub0200852CObj *)info, e->gender);
    func_02008558((struct Sub0200852CObj *)info, e->country);
    func_02008574((struct Sub0200852CObj *)info, e->lang, e->ver);
    info->trainerId = e->trainerId;
    info->profileId = e->profileId;
    return info;
}

/*
 * Return the slot record for a kind: kind 9 is the current 0x128-byte
 * entry of the +0x20C array (index at +0xD4), kinds 10 and 8 share the
 * record at +0xE4. Any other kind reports through func_02034714 (raw
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
    func_02034714((void *)0x02203B80, 0, (void *)0x02203B80);
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
        func_02007664((void *)p->ctx->box, p->box_u, p->pos);
        func_020076D0((void *)p->ctx->box, (int *)(&a), (int *)(&b));
        func_0200752C((void **)p->ctx->box, a, (const struct Sub02007454Entry *)((u32)POKE_TOOL_GetBoxParam((void *)e)));
    }
}

/*
 * function: WORLDTRADE_ADAPTER_RegisterReceivedMon
 * address:  0x022022B8
 * packet:   pkt_022022B8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_CalcGender  0x02017F50  thumb
 *   WORLDTRADE_ADAPTER_GetDateTime  0x0220246C  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   func_020076D0  0x020076D0  thumb
 *   WORLDTRADE_ADAPTER_GetBoxParam  0x022026BC  thumb
 *   func_0200752C  0x0200752C  thumb
 *   func_0200AD94  0x0200AD94  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *sys;
    u8 pad4[4];
    void *party;
    u32 box;
    void *dex;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0xDC - 4];
    u32 boxId;
    u32 pos;
} Work;

extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
struct Blk37;
struct Party;
struct PartyMon;
struct Rec0200AD94;
extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *p, void *m);
extern u32 POKEPARTY_GetCount(void *p);
extern void POKE_TOOL_SetPartyValue(void *mon, u32 id, u32 v);
extern u8 POKE_TOOL_CalcGender(u32 species, u16 form, u32 pid);
extern void WORLDTRADE_ADAPTER_GetDateTime(void *p, int which);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern u32 WORLDTRADE_ADAPTER_GetBoxParam(void *mon);
struct Sub02007454Entry;
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern void func_0200AD94(struct Rec0200AD94 *p, u16 v);

void WORLDTRADE_ADAPTER_RegisterReceivedMon(Work *p, void *mon, u32 box, int hatch)
{
    u32 pos;
    u32 species;
    u32 form;
    u32 slot;

    POKE_TOOL_GetPartyValue(mon, 6, 0);
    ZUKAN_SAVE_RegisterCaught(p->ctx->dex, mon);
    box = 0xFF;
    if (POKEPARTY_GetCount(p->ctx->party) == 6) {
        box = 0;
    }
    if (hatch != 0) {
        POKE_TOOL_SetPartyValue(mon, 9, 0x46);
        species = POKE_TOOL_GetPartyValue(mon, 5, 0);
        form = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
        POKE_TOOL_SetPartyValue(mon, 0x6E, POKE_TOOL_CalcGender((u16)species, form, POKE_TOOL_GetPartyValue(mon, 0, 0)));
        WORLDTRADE_ADAPTER_GetDateTime(p->ctx->sys, 0);
    }
    if (box == 0xFF) {
        POKEPARTY_Add(p->ctx->party, mon);
        slot = POKEPARTY_GetCount(p->ctx->party);
        p->boxId = 0xFF;
        slot -= 1;
    } else {
        pos = 0;
        func_020076D0((void *)p->ctx->box, (int *)(&box), (int *)(&pos));
        func_0200752C((void **)p->ctx->box, box, (const struct Sub02007454Entry *)WORLDTRADE_ADAPTER_GetBoxParam(mon));
        p->boxId = box;
        slot = pos;
    }
    p->pos = slot;
    func_0200AD94(p->ctx->sys, 0);
}

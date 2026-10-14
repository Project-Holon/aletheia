/*
 * function: WORLDTRADE_BOX_SelectMonForOffer
 * address:  0x021F5A7C
 * packet:   pkt_021F5A7C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
  *
 * symbols:
 *   WORLDTRADE_BOX_GetMonTradeState  0x021F6C48  thumb
 *   WORLDTRADE_BOX_CanRemoveMon  0x021F6BA4  thumb
 *   WORLDTRADE_BOX_GetPartyMon  0x021F6B40  thumb
 *   WORLDTRADE_ADAPTER_CreateMonFromBox  0x022025E4  thumb
 *   WORLDTRADE_BOX_PrintMessage  0x021F663C  thumb
 *   WORLDTRADE_SetNextState  0x021F4E98  thumb
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[8];
    void *party;
    void *save;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x28 - 4];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    u8 padC8[0xB68 - 0xC8];
    void *msg;
    u8 padB6C[0xBFC - 0xB6C];
    u32 cursor;
} Work;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
struct Actor;
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern int WORLDTRADE_BOX_GetMonTradeState(void *party, void *save, int box, int slot);
extern int WORLDTRADE_BOX_CanRemoveMon(void *party, void *save, int box, int slot);
extern void *WORLDTRADE_BOX_GetPartyMon(void *party, void *save, int box, int slot);
extern void WORLDTRADE_ADAPTER_CreateMonFromBox(u32 a, u32 b, u32 c);
extern void WORLDTRADE_BOX_PrintMessage(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);

void WORLDTRADE_BOX_SelectMonForOffer(Work *p)
{
    if (p->slot == 0x1E) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_RestartActorAnim((struct Actor *)p->cursor);
        p->state = 0x11;
        GFL_USE_PlaySeDefaultVolume(0x551);
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (WORLDTRADE_BOX_GetMonTradeState(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (WORLDTRADE_BOX_CanRemoveMon(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
            WORLDTRADE_ADAPTER_CreateMonFromBox((u32)p->msg, 0, (u32)WORLDTRADE_BOX_GetPartyMon(p->ctx->party, p->ctx->save, p->box, p->slot));
            WORLDTRADE_BOX_PrintMessage((u8 *)p, 0x16, 1, 0, 0xF0F, 0);
            WORLDTRADE_SetNextState((u8 *)p, 3, 7);
        } else {
            WORLDTRADE_BOX_PrintMessage((u8 *)p, 0x1A, 1, 0, 0xF0F, 1);
            WORLDTRADE_SetNextState((u8 *)p, 4, 1);
        }
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        WORLDTRADE_BOX_PrintMessage((u8 *)p, 0x21, 1, 0, 0xF0F, 1);
        WORLDTRADE_SetNextState((u8 *)p, 4, 1);
        break;
    }
}

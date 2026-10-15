/*
 * function: WORLDTRADE_BOX_StateOfferMenuInput
 * address:  0x021F601C
 * packet:   pkt_021F601C
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
 *   WORLDTRADE_UpdateTaskMenuList  0x021F4E30  thumb
 *   WORLDTRADE_CloseTaskMenuList  0x021F4E64  thumb
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_BOX_GetPartyMon  0x021F6B40  thumb
 *   WORLDTRADE_BOX_GetBoxCount  0x021F6BC4  thumb
 *   WORLDTRADE_BOX_PrintMessage  0x021F663C  thumb
 *   WORLDTRADE_SetNextState  0x021F4E98  thumb
 *   WORLDTRADE_BOX_CheckMonRestrictionA  0x021F6BFC  thumb
 *   WORLDTRADE_BOX_CheckMonRestrictionB  0x021F6C28  thumb
 *   WORLDTRADE_BOX_ClampSlot  0x021F6B34  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  arm9
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
    u8 padC8[0xCC - 0xC8];
    void *mon;
    u8 padD0[0xD40 - 0xD0];
    void *d40;
    u8 padD44[0xDE8 - 0xD44];
    void *de8;
} Work;

extern u32 WORLDTRADE_UpdateTaskMenuList(u8 *p);
extern void WORLDTRADE_CloseTaskMenuList(u8 *p);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void *WORLDTRADE_BOX_GetPartyMon(void *party, void *save, int box, int slot);
extern u32 WORLDTRADE_BOX_GetBoxCount(void *mon);
extern void WORLDTRADE_BOX_PrintMessage(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);
extern int WORLDTRADE_BOX_CheckMonRestrictionA(u32 handle);
extern int WORLDTRADE_BOX_CheckMonRestrictionB(u32 handle);
extern int WORLDTRADE_BOX_ClampSlot(int v);
extern void *POKEPARTY_GetMember(void *p, u32 idx);

int WORLDTRADE_BOX_StateOfferMenuInput(Work *p)
{
    void *mon;

    switch (WORLDTRADE_UpdateTaskMenuList((u8 *)p)) {
    case 1:
        WORLDTRADE_CloseTaskMenuList((u8 *)p);
        BMP_MENUWORK_Delete(p->de8);
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        p->state = 2;
        WORLDTRADE_SetStateAndReturn((u8 *)p, 8, 5);
        break;
    case 2:
        WORLDTRADE_CloseTaskMenuList((u8 *)p);
        BMP_MENUWORK_Delete(p->de8);
        mon = WORLDTRADE_BOX_GetPartyMon(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (WORLDTRADE_BOX_GetBoxCount(mon) != 0) {
            WORLDTRADE_BOX_PrintMessage((u8 *)p, 0x2B, 1, 0, 0xF0F, 1);
            WORLDTRADE_SetNextState((u8 *)p, 4, 1);
        } else if (WORLDTRADE_BOX_CheckMonRestrictionA((u32)mon) != 0) {
            if (WORLDTRADE_BOX_CheckMonRestrictionA((u32)mon) == 1) {
                WORLDTRADE_BOX_PrintMessage((u8 *)p, 0xBF, 1, 0, 0xF0F, 1);
            } else {
                WORLDTRADE_BOX_PrintMessage((u8 *)p, 0xC0, 1, 0, 0xF0F, 1);
            }
            WORLDTRADE_SetNextState((u8 *)p, 4, 1);
        } else if (WORLDTRADE_BOX_CheckMonRestrictionB((u32)mon) != 0) {
            WORLDTRADE_BOX_PrintMessage((u8 *)p, 0xC1, 1, 0, 0xF0F, 1);
            WORLDTRADE_SetNextState((u8 *)p, 4, 1);
        } else {
            if (WORLDTRADE_BOX_ClampSlot(p->box) != 0) {
                POKEPARTY_GetMember(p->ctx->party, p->slot);
            }
            p->mon = WORLDTRADE_BOX_GetPartyMon(p->ctx->party, p->ctx->save, p->box, p->slot);
            p->state = 2;
            WORLDTRADE_SetStateAndReturn((u8 *)p, 6, 0);
        }
        break;
    case 3:
    case (u32)-2:
        WORLDTRADE_CloseTaskMenuList((u8 *)p);
        BMP_MENUWORK_Delete(p->de8);
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        p->state = 0;
        break;
    }
    return 2;
}

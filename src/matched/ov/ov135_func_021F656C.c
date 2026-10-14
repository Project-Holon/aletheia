/*
 * function: WORLDTRADE_BOX_StateSelectConfirmInput
 * address: 0x021F656C
 * packet: pkt_ov135_021F656C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_BOX_GetPartyMon 0x021F6B40 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[8]; void *party; void *save; } Ctx;
typedef struct { Ctx *ctx; u8 pad4[0x28-4]; unsigned state; u8 pad2c[0xC4-0x2C]; u16 box, slot; unsigned count; void *mon; u8 padD0[0xDD0-0xD0]; void *dd0; } Work;
typedef unsigned int   u32;
extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);
extern void WORLDTRADE_CloseTaskMenu(char *p);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void *WORLDTRADE_BOX_GetPartyMon(void *party, void *save, int box, int slot);
extern void func_0201F7A8(void *desc, unsigned kind);
int WORLDTRADE_BOX_StateSelectConfirmInput(Work *p)
{
    unsigned result = WORLDTRADE_UpdateTaskMenuYesNo((char *)p);
    if (result == 1) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        p->mon = WORLDTRADE_BOX_GetPartyMon(p->ctx->party, p->ctx->save, p->box, p->slot);
        p->state = 2;
        WORLDTRADE_SetStateAndReturn((u8 *)p, 6, 0);
    } else if (result == 2) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        func_0201F7A8(p->dd0, 0);
        p->state = 1;
    }
    return 2;
}

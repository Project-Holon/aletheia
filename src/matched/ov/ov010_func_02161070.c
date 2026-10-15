/*
 * function: EVENT_FIELD_PROCLINK_ReturnBag
 * address:  0x02161070
 * packet:   pkt_ov010_02161070
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Menu selection dispatch: maps the chosen item (sel->item) to the next
 * state, either a sub-mode (w->ctx->mode, answer 3) or a follow-up
 * screen (w->next, answer 4).
 *
 * Levers (2026-09-28 tree_ov010_4): the arms in the image's block order
 * (not case order), and the party fetch in case 18 as its own statement
 * so w->ctx is reloaded after the calls.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   FILE_UTIL_Check136C  0x0202136C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct MenuCtx {
    void *sys;          /* 0x00 */
    u8 pad04[0x24];
    u32 mode;           /* 0x28 */
    u32 slot;           /* 0x2C */
} MenuCtx;

typedef struct MenuWork {
    u8 pad00[0xC];
    u32 next;           /* 0x0C */
    u8 pad10[8];
    MenuCtx *ctx;       /* 0x18 */
    u8 pad1C[0x4C];
    u32 f68;            /* 0x68 */
} MenuWork;

typedef struct MenuSel {
    u8 pad00[0x2C];
    u32 f2c;            /* 0x2C */
    u8 pad30[4];
    u32 item;           /* 0x34 */
    u32 arg;            /* 0x38 */
} MenuSel;

struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 FILE_UTIL_Check136C(u16 v);

int EVENT_FIELD_PROCLINK_ReturnBag(MenuWork *w, MenuSel *sel)
{
    void *party;

    switch (sel->item) {
    case 0:
        return 1;
    case 1:
        if (sel->f2c == 2) {
            w->next = 0;
            return 4;
        }
        return 0;
    case 12:
        w->next = 0;
        return 4;
    case 10:
    case 11:
        w->ctx->mode = 0;
        return 3;
    case 13:
        w->ctx->mode = 1;
        return 3;
    case 15:
        w->ctx->mode = 3;
        return 3;
    case 16:
        w->ctx->mode = 4;
        return 3;
    case 14:
        w->ctx->mode = 2;
        return 3;
    case 8:
        w->next = 8;
        return 4;
    case 7:
        w->next = 7;
        return 4;
    case 17:
        w->next = 11;
        return 4;
    case 19:
        w->next = 9;
        return 4;
    case 18:
        party = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData(w->ctx->sys));
        if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, w->ctx->slot), 6, 0) != 0)
            w->next = 0;
        else
            w->next = 9;
        w->f68 = 2;
        return 4;
    case 20:
        w->ctx->mode = 5;
        return 3;
    case 2:
        if (FILE_UTIL_Check136C(sel->arg) == 1)
            w->f68 = 0;
        w->next = 0;
        return 4;
    }
    w->next = 0;
    return 4;
}

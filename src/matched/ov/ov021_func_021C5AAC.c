/*
 * function: SCRCMD_CreateNicknameEvent
 * address:  0x021C5AAC
 * packet:   pkt_ov021_021C5AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   NAMEIN_SETUP_CreateArgs  0x0216BFD4  thumb  ov010
 *   SCRCMD_NicknameEventMain  0x021C5B58  thumb  ov021
 */

typedef unsigned int u32;

struct Big;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *a);
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Work {
    void *a;
    void *f04;
    int *f08;
    int f0C;
    int f10;
    int f14;
};

extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200C0F0(void *a);
extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);
extern int *NAMEIN_SETUP_CreateArgs(int a, int b, int c, int d, int e, int f, void *g);
extern int SCRCMD_NicknameEventMain(int a, int *b, int *c);

int SCRCMD_CreateNicknameEvent(void *a, int b, int c, int d)
{
    int h;
    struct Work *p;
    int e;
    void *r6;
    int x;
    int y;

    if ((int)POKEPARTY_GetCount(GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData(a))) <= c) {
        c = 0;
    }
    h = (int)func_020122C0(a, 0, (void *)SCRCMD_NicknameEventMain, 0x18);
    p = func_020124E8((struct Obj *)h);
    p->a = a;
    p->f04 = GAMESYSTEM_GetFieldMap(a);
    p->f10 = b;
    p->f14 = d;
    r6 = GAMESYSTEM_GetGameData(p->a);
    e = (int)POKEPARTY_GetMember(GAME_DATA_GetMyParty(r6), c);
    r6 = func_0200C0F0(GAME_DATA_GetSaveControl(r6));
    x = POKE_TOOL_GetPartyValue((void *)e, 5, 0);
    y = POKE_TOOL_GetPartyValue((void *)e, 0x6f, 0) | (POKE_TOOL_GetPartyValue((void *)e, 0x6e, 0) << 8);
    p->f08 = NAMEIN_SETUP_CreateArgs(4, 1, x, y, 0xa, 0, r6);
    p->f0C = e;
    return h;
}

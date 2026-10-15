/*
 * function: SCRCMD_FLD_BATTLE_CreatePartyCheckTask
 * address:  0x021B58B0
 * packet:   pkt_ov021_021B58B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two spellings carry the block layout: the else arm's result goes through
 * a temporary (tmp), which keeps the inner if/else ahead of the outer else
 * rather than sunk before the rest; and the not-1 path is an if/else of two
 * stores, not a ternary (which compiles branch-free).  `b = 0` after the
 * task call is what puts its zero in r1.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02019ED4  0x02019ED4  thumb
 *   POKE_REGULATION_CheckParty  0x0201A090  thumb
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   BATTLE_BOX_HasMon  0x0200BBA8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020307B0  0x020307B0  arm
 *   SCRCMD_FLD_BATTLE_PartyCheckTaskMain  0x021B59B0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03600.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern int func_02019ED4(void *ctx, void *q);
extern int POKE_REGULATION_CheckParty(void *rules, void *party, u32 *mask);
extern void *BATTLE_BOX_GetFromSave(void *);
extern u32 BATTLE_BOX_HasMon(void *a);
extern void *func_0200BAF4(int a0, int a1);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_020307B0(void *p);
extern void SCRCMD_FLD_BATTLE_PartyCheckTaskMain(void);

void *SCRCMD_FLD_BATTLE_CreatePartyCheckTask(void *sys, int flag, void *rules, u16 *out, u16 k)
{
    u32 mask = 0;
    void *w;
    void *party;
    int r2;
    void *q;
    void *task;
    u32 *e;
    u32 b;
    int r1;
    int tmp;

    w = GAMESYSTEM_GetGameData(sys);
    mask = 0;
    party = GAME_DATA_GetMyParty(w);
    if (flag) {
        r1 = func_02019ED4(rules, party);
    } else {
        r1 = POKE_REGULATION_CheckParty(rules, party, &mask);
    }
    q = BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(w));
    if (BATTLE_BOX_HasMon(q) == 1) {
        mask = 0;
        w = func_0200BAF4((int)q, k);
        if (flag) {
            r2 = func_02019ED4(rules, w);
        } else {
            tmp = POKE_REGULATION_CheckParty(rules, w, &mask);
            r2 = tmp;
        }
    } else {
        if (r1) {
            *out = 3;
        } else {
            *out = 0;
        }
        return 0;
    }
    if (r1 && r2) {
        if (w) {
            func_020307B0(w);
        }
        *out = 3;
        return 0;
    }
    task = func_020122C0(sys, 0, (void *)SCRCMD_FLD_BATTLE_PartyCheckTaskMain, 0x1c);
    b = 0;
    e = func_020124E8(task);
    e[0] = (u32)sys;
    e[1] = (u32)GAMESYSTEM_GetFieldMap(sys);
    e[6] = (u32)out;
    ((struct Obj03600 *)e)->f16 = k;
    e[3] = (u32)party;
    e[4] = (u32)w;
    if (r1) {
        b = 1;
    }
    *((u8 *)e + 0x14) = b;
    *((u8 *)e + 0x15) = r2 ? 1 : 0;
    return task;
}

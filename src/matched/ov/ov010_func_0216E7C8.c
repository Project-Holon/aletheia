/*
 * function: EVENT_BATTLE_CreateScriptedBattle
 * address:  0x0216E7C8
 * packet:   pkt_ov010_0216E7C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x10-byte task record (handler EVENT_BATTLE_ProcScriptedBattle) and fills it
 * from the arguments.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_BATTLE_ProcScriptedBattle  0x0216E68C  thumb  ov010
 *   EVENT_BATTLE_NotifyLeadSpecies  0x0216EE40  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_ConsumeSpot  0x021AAABC  thumb  ov021
 */

typedef unsigned int u32;

struct Work;
extern int EVENT_BATTLE_ProcScriptedBattle(void *evt, u32 *state, struct Work *w);
typedef unsigned char  u8;
struct Ctx;
struct Desc;
struct Obj;
struct Sub02008C20Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void EVENT_BATTLE_NotifyLeadSpecies(void *p, int which);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern void EFFECT_ENCOUNT_ConsumeSpot(int s);

int EVENT_BATTLE_CreateScriptedBattle(int a0, int a1, int a2, int a3, int a4)
{
    int h;
    u32 *t;

    h = (int)func_020122C0((void *)a0, 0, EVENT_BATTLE_ProcScriptedBattle, 0x10);
    t = func_020124E8((struct Obj *)h);
    t[0] = a0;
    t[1] = a2;
    t[2] = a3;
    t[3] = a4;
    EVENT_BATTLE_NotifyLeadSpecies((void *)a2, 0);
    func_02008DF0(GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData((const struct Ctx *)a0)), 5);
    EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount((u8 *)a1));
    return h;
}

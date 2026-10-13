/*
 * function: EVENT_BATTLE_CreateEncounterTask
 * address:  0x0216E818
 * packet:   pkt_ov010_0216E818
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   BTL_SETUP_Create  0x02013090  thumb
 *   FIELD_ENCOUNT_SetupTrainerBattle  0x021AA5CC  thumb  ov021
 *   EVENT_BATTLE_DispatchBattleKindNotify  0x0216EE20  thumb  ov010
 *   func_02008DF0  0x02008DF0  thumb
 *   EVENT_BATTLE_InitTaskWork  0x0216F02C  thumb  ov010
 *   BTL_SETUP_SetStatusFlag  0x02013144  thumb
 *   func_021CF748  0x021CF748  thumb  ov021
 *   EFFECT_ENCOUNT_ConsumeSpot  0x021AAABC  thumb  ov021
 *   EVENT_BATTLE_ProcBattleTask  0x0216EB98  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Work;
extern int EVENT_BATTLE_ProcBattleTask(void *evt, u32 *state, struct Work *w);
typedef unsigned char  u8;
struct Ctx;
struct Desc;
struct Obj;
struct Sub02008C20Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern void *BTL_SETUP_Create(u32 heap);
extern void FIELD_ENCOUNT_SetupTrainerBattle(struct Ctx *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap);
extern void EVENT_BATTLE_DispatchBattleKindNotify(u16 id, int col);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void EVENT_BATTLE_InitTaskWork(void **p, void *a, void *b);
extern void BTL_SETUP_SetStatusFlag(char *p, int v);
extern void func_021CF748(u32 a, u32 x, int *out, u16 *out2);
extern void EFFECT_ENCOUNT_ConsumeSpot(int s);

int EVENT_BATTLE_CreateEncounterTask(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    int h;
    int *t;
    int v;
    int w;
    int x;

    h = (int)func_020122C0((void *)a0, 0, EVENT_BATTLE_ProcBattleTask, 0x28);
    t = func_020124E8((struct Obj *)h);
    v = FIELDMAP_GetEncount((u8 *)a1);
    w = (int)GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData((const struct Ctx *)a0));
    x = (int)BTL_SETUP_Create(4);
    FIELD_ENCOUNT_SetupTrainerBattle((struct Ctx *)v, (void *)x, a2, a3, (void *)a4, a5, 4);
    EVENT_BATTLE_DispatchBattleKindNotify(a4, 0);
    func_02008DF0((struct Sub02008C20Obj *)w, 6);
    func_02008DF0((struct Sub02008C20Obj *)w, 0x56);
    EVENT_BATTLE_InitTaskWork((void **)t, (void *)a0, (void *)x);
    t[5] = 1;
    if (a6 & 1) {
        BTL_SETUP_SetStatusFlag((char *)x, 0x100);
        t[6] = 1;
    }
    func_021CF748(a4, a1, (int *)((int)t + 0x24), (u16 *)(t[2] + 0x18));
    EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount((u8 *)a1));
    return h;
}

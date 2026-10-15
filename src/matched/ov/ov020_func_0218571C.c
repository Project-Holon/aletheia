/*
 * function: EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent
 * address: 0x0218571C
 * packet: pkt_ov020_0218571C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   GAME_DATA_GetSituationWarpId 0x02012914 thumb
 *   MAP_REPLACE_ApplyWarpLocation 0x02159FA8 thumb ov010
 *   EVENT_MAPCHANGE_RunSituationWarpArrivalEvent 0x02185694 thumb ov020
 */
typedef struct { void *owner; void *object; unsigned char payload[0x1c]; } Work;
typedef unsigned short u16;
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u16 GAME_DATA_GetSituationWarpId(const struct BigObj *p);
extern void MAP_REPLACE_ApplyWarpLocation(int a, int b);
extern int EVENT_MAPCHANGE_RunSituationWarpArrivalEvent(int a0, int *st, int *p);
void *EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent(void *owner)
{
    void *task;
    Work *w;
    GAMESYSTEM_GetGameData(owner);
    task = func_020122C0(owner, 0, (void *)EVENT_MAPCHANGE_RunSituationWarpArrivalEvent, sizeof(Work));
    w = func_020124E8(task);
    w->owner = owner;
    w->object = GAMESYSTEM_GetGameData(owner);
    MAP_REPLACE_ApplyWarpLocation(GAME_DATA_GetSituationWarpId(w->object), (int)w->payload);
    return task;
}

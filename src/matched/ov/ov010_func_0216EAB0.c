/*
 * function: EVENT_BATTLE_CreateEncounterTaskWithMon
 * address:  0x0216EAB0
 * packet:   pkt_ov010_0216EAB0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Every concrete byte matches; the one wildcard is the bl to 0x02012FD8, an
 * unlabelled 12-byte arm9 Thumb leaf (ldr r0,[r0]; tail call
 * func_020071CC(r0, 0x43)) with no label, no shard and so no witness.
 * Blocker: label/matched for arm9 0x02012FD8.  It verifies EXACT at arm9
 * as `void *GAME_DATA_GetSaveBlock43(void **p) { return func_020071CC(*p, 0x43); }`
 * (symbols: func_020071CC 0x020071CC thumb), which is outside an overlay
 * lane's write set; once it has a shard this file should verify EXACT.
 *
 * The level argument to POKE_TOOL_SetupPartyParamEx is passed untruncated here, so its
 * extern takes u32 level rather than the u16 other callers declare.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveBlock43  0x02012FD8  thumb
 *   EVENT_BATTLE_CreateEncounterTask  0x0216E818  thumb  ov010
 *   MON_SNAPSHOT_IsFilled   0x0200E740  thumb
 *   GAME_EVENT_GetWork   0x020124E8  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   MON_SNAPSHOT_GetSpeciesForSlot   0x0200E788  thumb
 *   MON_SNAPSHOT_GetLevel   0x0200E74C  thumb
 *   MON_SNAPSHOT_GetOtId   0x0200E7B4  thumb
 *   MON_SNAPSHOT_GetPersonalRnd   0x0200E7A4  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   MON_SNAPSHOT_HasAbility   0x0200E76C  thumb
 *   MON_SNAPSHOT_GetAbility   0x0200E780  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   MON_SNAPSHOT_GetNickname   0x0200E7AC  thumb
 *   POKE_TOOL_ChangeSpecies  0x020178D8  thumb
 *   POKE_TOOL_SetDefaultMoves  0x02017FA8  thumb
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

struct Ctx;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveBlock43(void **p);
extern int EVENT_BATTLE_CreateEncounterTask(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern u32   MON_SNAPSHOT_IsFilled(const void *obj, u32 idx);
extern void *GAME_EVENT_GetWork(struct Obj *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32   POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32   MON_SNAPSHOT_GetSpeciesForSlot(const void *obj, u32 a, u32 b);
extern u32   MON_SNAPSHOT_GetLevel(const void *obj, u32 idx);
extern u32   MON_SNAPSHOT_GetOtId(const void *obj, u32 idx);
extern u32   MON_SNAPSHOT_GetPersonalRnd(const void *obj, u32 idx);
extern void  POKE_TOOL_SetupPartyParamEx(void *p, u16 species, u32 level, u64 id, u32 pow, u64 rnd);
extern u32   MON_SNAPSHOT_HasAbility(const void *obj, u32 idx);
extern u8    MON_SNAPSHOT_GetAbility(const void *obj, u32 idx);
extern void  POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern void *MON_SNAPSHOT_GetNickname(void *obj, u32 idx);
extern void POKE_TOOL_ChangeSpecies(void *p, u32 a);
extern u32   POKE_TOOL_SetDefaultMoves(void *p);

void *EVENT_BATTLE_CreateEncounterTaskWithMon(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 idx)
{
    void *data;
    void *task;
    void *mon;
    u32 old;
    u32 species;
    u32 level;
    u32 id;
    u32 rnd;

    data = GAME_DATA_GetSaveBlock43(GAMESYSTEM_GetGameData(a0));
    task = (void *)EVENT_BATTLE_CreateEncounterTask((int)a0, a1, a2, a3, a4, a5, a6);
    if (MON_SNAPSHOT_IsFilled(data, idx) != 0) {
        mon = POKEPARTY_GetMember(*(void **)(*(u8 **)((u8 *)GAME_EVENT_GetWork(task) + 8) + 0x28), 0);
        old = POKE_TOOL_GetPartyValue(mon, 5, 0);
        species = MON_SNAPSHOT_GetSpeciesForSlot(data, idx, 0x15);
        level = MON_SNAPSHOT_GetLevel(data, idx);
        id = MON_SNAPSHOT_GetOtId(data, idx);
        rnd = MON_SNAPSHOT_GetPersonalRnd(data, idx);
        POKE_TOOL_SetupPartyParamEx(mon, species, level, id, -1, rnd);
        if (MON_SNAPSHOT_HasAbility(data, idx) != 0) {
            POKE_TOOL_SetPartyValue(mon, 10, MON_SNAPSHOT_GetAbility(data, idx));
        }
        POKE_TOOL_SetPartyValue(mon, 0x74, (u32)MON_SNAPSHOT_GetNickname(data, idx));
        POKE_TOOL_ChangeSpecies(mon, (u16)old);
        POKE_TOOL_SetDefaultMoves(mon);
    }
    return task;
}

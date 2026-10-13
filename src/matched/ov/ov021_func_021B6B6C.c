/*
 * function: SCRCMD_POKEMON_FLD_WarpToEntry
 * address:  0x021B6B6C
 * packet:   pkt_ov021_021B6B6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetFadeState  0x0215A6C4  thumb  ov010
 *   SCRCMD_WORK_GetScriptId  0x0215A5D0  thumb  ov010
 *   SCRCMD_POKEMON_FLD_CountWarpEntries  0x021B6AB0  thumb
 *   SCRCMD_POKEMON_FLD_GetWarpEntry  0x021B6AA4  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb  ov020
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u32 SCRCMD_WORK_GetFadeState(void *p);
extern u16 SCRCMD_WORK_GetScriptId(void *);
struct Ctx;
extern int SCRCMD_POKEMON_FLD_CountWarpEntries(void *a);
extern int SCRCMD_POKEMON_FLD_GetWarpEntry(u32 a, u32 b);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetGameSystem(void *);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(void *, void *, int, Vec3 *, int);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

u32 SCRCMD_POKEMON_FLD_WarpToEntry(void *a, void *b)
{
    u32 idx = SCRIPT_WORK_ReadWorkValue(a, b);
    void *tab = (void *)SCRCMD_WORK_GetFadeState(b);

    SCRCMD_WORK_GetScriptId(b);
    if (idx < SCRCMD_POKEMON_FLD_CountWarpEntries(tab)) {
        const u16 *e = (const u16 *)SCRCMD_POKEMON_FLD_GetWarpEntry((u32)tab, idx);
        void *r5 = SCRCMD_WORK_GetScriptWork(b);
        void *r6 = SCRIPT_WORK_GetGameSystem(r5);
        void *cur = GAMESYSTEM_GetFieldMap(r6);
        Vec3 v;
        u32 f3 = e[3];
        u32 f4 = e[4];
        u32 f1 = e[1];
        u32 f2 = e[2];

        v.x = f2 << 16;
        v.y = f3 << 16;
        v.z = f4 << 16;
        SCRIPT_SYS_CallEvent(r5, (void *)EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(r6, cur, f1, &v, 1));
    }
    return 1;
}

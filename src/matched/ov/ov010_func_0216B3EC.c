/*
 * function: FIELD_INTRUDE_EVENT_SymbolEntryEventMain
 * address:  0x0216B3EC
 * packet:   pkt_ov010_0216B3EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Seven-state proc of an ov010 field menu: run the list task, then the
 * chosen entry's screen, writing 0 or 1 to the caller's result word.
 * Byte-correct first draft.
 * Blocker (MATCH): the arm9 Thumb callee 0x02012FA4 has no func_ label
 * and no matched file (seed).
 *
 * 2026-10-05: byte-identical; the wildcard is arm9 GAME_DATA_SetSymbolMapFlag (new matched/arm9 file, EXACT, this lane); needs its shard.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FIELD_INTRUDE_EVENT_CreateIntrudeRequestEvent  0x0216B24C  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   SYMBOL_MAP_GetSelectedCellTile  0x021665D0  thumb  ov010
 *   GAME_DATA_SetSymbolMapFlag  0x02012FA4  thumb
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb
 *   FLDMMDL_BLACT_IsReservePending  0x0219C630  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    u16 *result;        /* 0x00 */
    u16 f04;            /* 0x04 */
    u8 pad06[2];
    u8 f08[0x14 - 0x08];/* 0x08 */
    u16 f14;            /* 0x14 */
    u8 f16;             /* 0x16 */
    u8 pad17;
    u16 f18;            /* 0x18 */
    u8 pad1A[2];
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
} Work;

struct Ctx;
struct Evt;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void FLDMMDL_SysPauseMove(void *map);
extern int FIELD_INTRUDE_EVENT_CreateIntrudeRequestEvent(void *vm, int value, int flag);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *sys, void *proc, u32 a, u32 b);
extern int SYMBOL_MAP_GetSelectedCellTile(int a0, int a1);
extern void GAME_DATA_SetSymbolMapFlag(char *p, unsigned char v);
extern void *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(void *sys, void *proc, u32 id, void *pos, u32 flag);
extern int FLDMMDL_BLACT_IsReservePending(void *map);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 *FLDMMDL_SysResumeMove(void *c);

int FIELD_INTRUDE_EVENT_SymbolEntryEventMain(void *evt, u32 *state, Work *w)
{
    void *sys = GAME_EVENT_GetGameSystem(evt);
    void *ctx;
    void *proc;

    GAMESYSTEM_GetGameComm(sys);
    ctx = GAMESYSTEM_GetGameData(sys);
    proc = GAMESYSTEM_GetFieldMap(sys);
    switch (*state) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(proc));
        if (w->f20 == 1) {
            *state = 2;
        } else {
            GAME_EVENT_CallEvent(evt, (void *)FIELD_INTRUDE_EVENT_CreateIntrudeRequestEvent(sys, (int)(&w->f18), w->f16));
            (*state)++;
        }
        break;
    case 1:
        if (w->f18 == 0) {
            if (w->result != 0)
                *w->result = 0;
            *state = 6;
        } else {
            (*state)++;
        }
        break;
    case 2:
        if (w->f1c != 0)
            GFL_USE_PlaySeDefaultVolume(1369);
        GAME_EVENT_CallEvent(evt, EVENT_FIELDMAP_CONTROL_StartFadeOut(sys, proc, 9, 0));
        (*state)++;
        break;
    case 3:
        w->f04 = SYMBOL_MAP_GetSelectedCellTile((int)sys, w->f16);
        GAME_DATA_SetSymbolMapFlag(ctx, w->f16);
        GAME_EVENT_CallEvent(evt, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(sys, proc, w->f04, w->f08, w->f14));
        (*state)++;
        break;
    case 4:
        if (FLDMMDL_BLACT_IsReservePending(FIELDMAP_GetMmdlSys(GAMESYSTEM_GetFieldMap(sys))) == 1)
            break;
        GAME_EVENT_CallEvent(evt, EVENT_FIELDMAP_CONTROL_StartFadeIn(sys, proc, 9, 0, 0, 0, 0));
        (*state)++;
        break;
    case 5:
        if (w->result != 0)
            *w->result = 1;
        *state = 6;
        break;
    case 6:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(proc));
        return 1;
    }
    return 0;
}

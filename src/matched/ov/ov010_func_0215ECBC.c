/*
 * function: MOVE_POKEMON_FlashEventMain
 * address:  0x0215ECBC
 * packet:   pkt_ov010_0215ECBC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three-state sequence step: state 0 opens message 0x2718, state 1 waits
 * for an object to go idle then starts sound 0x94, state 2 waits for a
 * status of 3. Returns 1 when finished.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMapEff  0x02189A10  thumb  ov021
 *   FIELDSKILL_MAPEFF_GetFlash  0x021C7FBC  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   FIELD_STATUS_IsFlashActive  0x02014468  thumb
 *   FIELD_STATUS_SetFlashActive  0x02014464  thumb
 *   GAME_BEACON_SEARCH_SetCountValue  0x02165534  thumb  ov010
 *   FIELD_FLASH_SetPendingCommand  0x021C7E50  thumb  ov021
 *   FIELD_STATUS_GetMapEffectMask  0x02014470  thumb
 *   FIELD_STATUS_SetMapEffectMask  0x0201446C  thumb
 *   FIELD_FLASH_GetState  0x021C7E54  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Arg {
    u8 pad00[8];
    void *f08;          /* 0x08 */
    u16 f0c;            /* 0x0C */
} Arg;

struct BigObj;
struct Ctx;
struct Obj;
struct Sub02014444Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetMapEff(struct Obj *p);
extern void *FIELDSKILL_MAPEFF_GetFlash(void **p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *SCRIPT_SYS_CallScriptEvent(void *a, u32 id, u32 b, u32 c, u32 d);
extern int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e);
extern u8 FIELD_STATUS_IsFlashActive(struct Sub02014444Obj *o);
extern void FIELD_STATUS_SetFlashActive(struct Sub02014444Obj *o, u8 v);
extern void GAME_BEACON_SEARCH_SetCountValue(void *a0);
extern void FIELD_FLASH_SetPendingCommand(u8 *p, u16 v);
extern u16 FIELD_STATUS_GetMapEffectMask(struct Sub02014444Obj *o);
extern void FIELD_STATUS_SetMapEffectMask(void *p, u32 v);
extern u16 FIELD_FLASH_GetState(struct Obj *p);

int MOVE_POKEMON_FlashEventMain(void *a0, int *state, Arg *arg)
{
    void *obj;
    void *obj2;
    void *ctl;
    u32 d;
    void *msg;
    void *o;
    u16 id;

    obj = GAMESYSTEM_GetGameData(arg->f08);
    GAME_DATA_GetEventWork(obj);
    obj2 = GAME_DATA_GetMoveModelSys(obj);
    ctl = FIELDSKILL_MAPEFF_GetFlash(FIELDMAP_GetMapEff(GAMESYSTEM_GetFieldMap(arg->f08)));
    d = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(arg->f08));

    switch (*state) {
    case 0:
        id = arg->f0c;
        msg = SCRIPT_SYS_CallScriptEvent(a0, 0x2718, 0, 0, d);
        SCRIPT_WORK_SetParams((int)msg, id, 0, 0, 0);
        (*state)++;
        break;
    case 1:
        if (FIELD_STATUS_IsFlashActive(obj2) == 0) {
            o = GAME_DATA_GetMoveModelSys(obj);
            FIELD_STATUS_SetFlashActive(obj2, 1);
            GAME_BEACON_SEARCH_SetCountValue((void *)0x94);
            FIELD_FLASH_SetPendingCommand(ctl, 1);
            FIELD_STATUS_SetMapEffectMask(o, (FIELD_STATUS_GetMapEffectMask(o) & ~1) | 2);
        } else {
            return 1;
        }
        (*state)++;
        break;
    case 2:
        if (FIELD_FLASH_GetState(ctl) == 3) {
            return 1;
        }
        break;
    }
    return 0;
}

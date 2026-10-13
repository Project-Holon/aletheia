/*
 * function: SP_POKE_GIMMICK_SwapNpcEventMain
 * address:  0x021F3D9C
 * packet:   pkt_ov059_021F3D9C
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the task callback SP_POKE_GIMMICK_StartSwapNpc installs; the function is 180
 *           bytes, the rest of the handed 772 is data.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   FLDMMDL_AddMmdlHeaderById  0x0216CEE4  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x24];
    u16 *p24;
} W;

struct BigObj;
struct Ctx;
struct Obj;
struct Rec44;
struct SaveBlock;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern int FLD_EXP_OBJ_GetAnimeFrame(int a, int b, int c, int d);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern void FLDMMDL_DeleteMmdl(void *o);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern u16 EVENTDATA_SYSTEM_GetNpcCount(u8 *p);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 EVENTDATA_SYSTEM_GetNpcHeaders(u8 *p);
extern void *FLDMMDL_AddMmdlHeaderById(void *a, void *e, u32 b, int n, u32 c, u32 id);
extern void FLDMMDL_OnMoveBitMovePause(void *obj);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);

int SP_POKE_GIMMICK_SwapNpcEventMain(void *a)
{
    void *o;
    void *t;
    void *s;
    W *w;
    u16 x;
    u16 y;
    void *map;
    void *v;
    void *m;
    u16 k;
    u32 b;
    u32 c;
    void *e;
    int r;

    o = func_020124E4(a);
    t = GAMESYSTEM_GetFieldMap(o);
    s = (void *)FIELDMAP_GetExpObj(t);
    w = (W *)FIELDMAP_GetCommonWork(t, 1);
    if (FLD_EXP_OBJ_GetAnimeFrame((int)s, 0, 2, 0) == 0xF000) {
        x = w->p24[0];
        y = w->p24[1];
        map = FIELDMAP_GetMmdlSys(t);
        FLDMMDL_DeleteMmdl(FLDMMDL_SysSearchObjId(map, x));
        v = GAMESYSTEM_GetGameData(o);
        m = (void *)GAME_DATA_GetEventData(v);
        k = EVENTDATA_SYSTEM_GetNpcCount(m);
        b = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(v));
        if (k != 0) {
            c = GAME_DATA_GetEventWork(v);
            e = FLDMMDL_AddMmdlHeaderById(map, (void *)EVENTDATA_SYSTEM_GetNpcHeaders(m), b, k, c, y);
            if (e != 0)
                FLDMMDL_OnMoveBitMovePause(e);
        }
    }
    r = 0;
    if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(s, 0, 2, 0)) != 0)
        r = 1;
    return r;
}

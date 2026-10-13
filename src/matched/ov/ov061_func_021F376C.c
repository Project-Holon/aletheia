/*
 * function: FIELD_GIMMICK_CONNECT_MARKERS_Update
 * address:  0x021F376C
 * packet:   pkt_ov061_021F376C
 * region:   ov061
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers  0x021F388C  thumb  ov061
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FIELD_GIMMICK_CONNECT_MARKERS_IsPlayerStepReady  0x021F3868  thumb  ov061
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   FIELD_PLAYER_GetPosInDir  0x021A3364  thumb  ov021
 *   EVENTDATA_SYSTEM_CheckAutoPosEvent  0x02162478  thumb  ov010
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern int FIELDMAP_GetExpObj(int *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern int *FIELDMAP_GetCommonWork(char *a, int idx);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers(int *o, int a);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_UpdateAnimes(int a);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern int FIELD_GIMMICK_CONNECT_MARKERS_IsPlayerStepReady(void *unused, void *x);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern void FIELD_PLAYER_GetPosInDir(u32 *a, int b, int *out);
extern int EVENTDATA_SYSTEM_CheckAutoPosEvent(char *p, int *v);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);

void FIELD_GIMMICK_CONNECT_MARKERS_Update(struct Obj00020 *a)
{
    int *o;
    int s;
    void *g;
    int h;
    int cur;
    u8 *e;
    V3 v;

    s = FIELDMAP_GetExpObj((int *)a);
    g = FIELDMAP_GetFieldPlayer(a);
    h = GAME_DATA_GetEventData(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a)));
    o = FIELDMAP_GetCommonWork((char *)a, 0);
    cur = FIELDMAP_GetZoneId((u8 *)a);
    if (o[2] != cur) {
        FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers(o, (int)a);
        o[2] = cur;
    }
    e = FLD_EXP_OBJ_GetAnime((char *)s, 0, 0, 0);
    FLD_EXP_OBJ_UpdateAnimes(s);
    if (o[0] != 0 && FLD_EXP_OBJ_IsAnimeStopped((int *)e) != 0) {
        FLD_EXP_OBJ_SetModelHidden((char *)s, 0, 0, 1);
        o[0] = 0;
    }
    if (FIELD_GIMMICK_CONNECT_MARKERS_IsPlayerStepReady(o, g) == 0) {
        return;
    }
    FIELD_PLAYER_GetPosInDir(g, FIELD_PLAYER_GetDirDisp(g), (int *)(&v));
    v.a -= 0x8000;
    v.c -= 0x8000;
    if (EVENTDATA_SYSTEM_CheckAutoPosEvent((char *)h, (int *)(&v)) == 0) {
        return;
    }
    o[0] = 1;
    FLD_EXP_OBJ_SetModelHidden((char *)s, 0, 0, 0);
    e = FLD_EXP_OBJ_GetAnime((char *)s, 0, 0, 0);
    FLD_EXP_OBJ_SetAnimeFrame(s, 0, 0, 0, 0);
    FLD_EXP_OBJ_SetAnimePaused(e, 0);
    *(V3 *)o[1] = v;
}

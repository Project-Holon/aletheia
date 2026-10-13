/*
 * function: GIMMICK61_PlaceMarkers
 * address:  0x021F388C
 * packet:   pkt_ov061_021F388C
 * region:   ov061
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * EVENTDATA_SYSTEM_GetConnectCount, EVENTDATA_SYSTEM_GetConnectCenterPosThunk (a thunk) and EVENTDATA_SYSTEM_GetConnectCenterPos behind it are
 * unlabelled ov010 leaves filed alongside this function.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetConnectCount  0x02162560  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectCenterPosThunk  0x02162A64  thumb  ov010
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern u16 EVENTDATA_SYSTEM_GetConnectCount(u8 *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void *EVENTDATA_SYSTEM_GetConnectData(char *p, unsigned i);
extern u8 EVENTDATA_SYSTEM_GetConnectExitType(u8 *p);
extern void EVENTDATA_SYSTEM_GetConnectCenterPosThunk(const void *p, V3 *out);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void *FLD_EXP_OBJ_GetModelStatus(int a, int b, u16 c);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimeEnabled(int a, int b, u16 c, u16 d, int e);

void GIMMICK61_PlaceMarkers(int *o, int a)
{
    int h;
    int n;
    int s;
    int i;
    void *e;
    V3 v;

    h = GAME_DATA_GetEventData(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a)));
    n = EVENTDATA_SYSTEM_GetConnectCount((u8 *)h);
    FIELDMAP_GetHeapId((u8 *)a);
    s = FIELDMAP_GetExpObj((int *)a);
    for (i = 0; i < 8; i++) {
        FLD_EXP_OBJ_SetModelHidden((char *)s, 0, (u16)(i + 1), 1);
    }
    for (i = 0; i < n; i++) {
        e = EVENTDATA_SYSTEM_GetConnectData((char *)h, (u16)i);
        if (e != 0 && EVENTDATA_SYSTEM_GetConnectExitType(e) == 6) {
            EVENTDATA_SYSTEM_GetConnectCenterPosThunk(e, &v);
            if (FIELDMAP_GetZoneId((u8 *)a) == 0x12E) {
                v.b -= 0x2000;
            }
            FLD_EXP_OBJ_SetModelHidden((char *)s, 0, (u16)(i + 1), 0);
            *(V3 *)FLD_EXP_OBJ_GetModelStatus(s, 0, i + 1) = v;
            FLD_EXP_OBJ_GetAnime((char *)s, 0, (u16)(i + 1), (u16)0);
            FLD_EXP_OBJ_SetAnimeEnabled(s, 0, i + 1, 0, 1);
        }
    }
}

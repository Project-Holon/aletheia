/*
 * function: GIMMICK39_CheckRideEvent
 * address:  0x021F404C
 * packet:   pkt_ov039_021F404C
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     FLD_EXP_OBJ_GetAnime's third parameter is u8 here (the caller truncates
 *           the int local before the bl); the 0x02188D2C result bound to a
 *           named local keeps `k` computed before that call.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb ov021
 *   FIELD_PLAYER_GetDirDisp 0x021A3050 thumb ov021
 *   FIELD_PLAYER_GetPos 0x021A3038 thumb ov021
 *   GIMMICK39_FindDockAt 0x021F36C0 thumb ov039
 *   GIMMICK39_IsCartAtDock 0x021F3DB8 thumb ov039
 *   GIMMICK39_GetDockLane 0x021F3DAC thumb ov039
 *   GIMMICK39_GetDockCart 0x021F3D98 thumb ov039
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   GIMMICK39_IsLaneLocked 0x021F4158 thumb ov039
 *   func_020122C0 0x020122C0 thumb
 *   GIMMICK39_RideRefusedEventMain 0x021F4610 thumb ov039
 *   GIMMICK39_RideEventMain 0x021F41A8 thumb ov039
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetGameSystem(void *p);
struct Big;
struct Desc;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern u8 *FIELDMAP_GetCommonWork(void *p, int idx);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern u8 GIMMICK39_FindDockAt(int x, int z);
extern int GIMMICK39_IsCartAtDock(signed char *p, int i);
extern u8 GIMMICK39_GetDockLane(int n);
extern u8 GIMMICK39_GetDockCart(u8 *s, int n);
extern int FIELDMAP_GetExpObj(int *p);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern int GIMMICK39_IsLaneLocked(u8 *p, int i);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int GIMMICK39_RideRefusedEventMain(void *a0, int *a1);
extern int GIMMICK39_RideEventMain(void *a0, int *a1);

int GIMMICK39_CheckRideEvent(void *a0)
{
    void *sys;
    void *p;
    u8 *s;
    void *x;
    Vec v;
    u8 n;
    int c;
    u8 k;
    int h;

    sys = GAMESYSTEM_GetFieldMap(a0);
    p = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(sys))), 2);
    s = FIELDMAP_GetCommonWork(sys, 1);
    x = FIELDMAP_GetFieldPlayer(sys);
    if (FIELD_PLAYER_GetDirDisp(x)) {
        return 0;
    }
    FIELD_PLAYER_GetPos(x, (struct VecFx32 *)&v);
    n = GIMMICK39_FindDockAt(v.x / 0x10000, v.z / 0x10000);
    if (n == 0xff) {
        return 0;
    }
    if (GIMMICK39_IsCartAtDock((signed char *)s, n)) {
        c = GIMMICK39_GetDockLane(n);
        s[4] = GIMMICK39_GetDockCart(s, n);
        k = s[4] + 1;
        h = FIELDMAP_GetExpObj(sys);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)h, 0, (u8)c, (u16)k), 1);
        s[7] = c;
        if (GIMMICK39_IsLaneLocked(p, c)) {
            return (int)func_020122C0(a0, 0, GIMMICK39_RideRefusedEventMain, 0);
        }
        return (int)func_020122C0(a0, 0, GIMMICK39_RideEventMain, 0);
    }
    return 0;
}

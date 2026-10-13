/*
 * function: SYMBOL_MAP_CheckEventFlag
 * address:  0x02166CD0
 * packet:   pkt_ov010_02166CD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02009590  0x02009590  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   FIELD_G3D_MAP_CheckBeaconTrainerKey  0x0216BF9C  thumb  ov010
 */

typedef unsigned int u32;

struct Big;
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void *GAME_DATA_GetMiscSave(int *p);
typedef signed int     s32;
typedef unsigned char  u8;
struct Sub02009470Obj;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u8 func_02009590(void *a, u32 b, u32 c);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *a, int i, void *b);

int SYMBOL_MAP_CheckEventFlag(void *a, u32 msg)
{
    int r7 = GAME_DATA_GetEventWork(a);
    int r0 = (int)GAME_DATA_GetMiscSave(a);
    int r6 = (int)GAME_DATA_GetMyStatus(a);
    u32 t;
    int res;
    t = (u32)func_02009470(GAME_DATA_GetSaveControl(a));
    switch (msg) {
    case 0xF000:
        return FIELD_G3D_MAP_CheckBeaconTrainerKey((void *)r0, 1, (void *)r6);
    case 0xF001:
        res = 0;
        if (func_02009590((void *)t, r6, 0) >= 1)
            res = 1;
        return res;
    }
    return ZONEDATA_CheckEventFlag((void *)r7, msg);
}

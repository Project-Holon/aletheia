/*
 * function: FIELD_G3D_MAP_CmdGetMissionProgress
 * address:  0x0216B86C
 * packet:   pkt_ov010_0216B86C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0200C32C  0x0200C32C  thumb
 *   FIELD_G3D_MAP_GetMissionKind  0x0216BB70  thumb  ov010
 *   FIELD_G3D_MAP_GetMissionHoursLeft  0x0216BAE8  thumb  ov010
 *   FIELD_G3D_MAP_GetMissionShortfall  0x0216BA88  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200C0E8(void *sys);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Blk34;
extern u8 func_0200C32C(struct Blk34 *p);
extern int FIELD_G3D_MAP_GetMissionKind(int index);
extern u16 FIELD_G3D_MAP_GetMissionHoursLeft(int p);
extern u16 FIELD_G3D_MAP_GetMissionShortfall(int c);

int FIELD_G3D_MAP_CmdGetMissionProgress(int c, int vm)
{
    u16 *dst;
    void *r6;
    void *r7;
    int r5;
    u8 k;

    r6 = GAME_DATA_GetSaveControl((struct Big *)SCRCMD_WORK_GetGameData((void *)vm));
    r7 = func_0200C0E8(r6);
    dst = SCRIPT_WORK_ReadWorkPointer((void *)c, (void *)vm);
    k = FIELD_G3D_MAP_GetMissionKind(func_0200C32C(r7));
    if (k != 0) {
        if (k == 1) {
            r5 = FIELD_G3D_MAP_GetMissionHoursLeft((int)r6);
        }
    } else {
        r5 = FIELD_G3D_MAP_GetMissionShortfall((int)r6);
    }
    *dst = r5;
    return 0;
}

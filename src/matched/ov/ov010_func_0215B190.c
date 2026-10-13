/*
 * function: SCRCMD_WORK_CmdCheckExtraSaveData
 * address:  0x0215B190
 * packet:   pkt_ov010_0215B190
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200ECB4  0x0200ECB4  thumb
 *   func_020072A4  0x020072A4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
struct Ctrl;
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
typedef signed int     s32;
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 SAVE_CONTROL_LoadExtraSave(struct Ctrl *ctrl, u32 id, u8 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern u32 func_0200ECB4(char *o);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
int SCRCMD_WORK_CmdCheckExtraSaveData(int a0, int a1)
{
    void *p = SCRCMD_WORK_GetGameData((void *)a1);
    int q = GAME_DATA_GetEventWork(p);
    u16 *out = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    void *t;
    int r;
    if (ZONEDATA_CheckEventFlag((void *)q, 0x97B) != 0) {
        t = GAME_DATA_GetSaveControl((struct Big *)p);
        r = SAVE_CONTROL_LoadExtraSave(t, 8, 4);
        switch (r) {
        case 0:
            *out = 0;
            break;
        case 1:
        case 2:
            if (func_0200ECB4(func_020073D8(t, 8, 0)) == 0) {
                *out = 0;
            } else {
                *out = 1;
            }
            break;
        default:
            *out = 2;
            break;
        }
        func_020072A4(t, 8);
    } else {
        *out = 0;
    }
    return 0;
}

/*
 * function: SCRCMD_FLDMMDL_AddMmdl
 * address:  0x021B181C
 * packet:   pkt_ov021_021B181C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   SCRCMD_WORK_GetMmdlSys  0x0215A5EC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   FLDMMDL_GetRealObjCode  0x0216E3D0  thumb  ov010
 *   FLDMMDL_AddMmdlParam  0x0216CE6C  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 */

typedef signed short s16;

void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
typedef unsigned char  u8;
int SCRIPT_WORK_ResetFieldParam(int a0);
unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
u16 FIELDMAP_GetZoneId(u8 *p);
void *SCRCMD_WORK_GetMmdlSys(void *p);
void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned int   u32;
struct BigObj;
u32 GAME_DATA_GetEventWork(const struct BigObj *p);
int FLDMMDL_GetRealObjCode(int a, int b);
int FLDMMDL_AddMmdlParam(int a, s16 b, s16 c, int d, int e, int f, int g, int h);
void FLDMMDL_OnMoveBitMovePause(void *a0);

int SCRCMD_FLDMMDL_AddMmdl(int a, int b)
{
    int r6;
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int r7;
    int r5;
    int r0;

    r6 = (int)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b));
    v0 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v1 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v2 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v3 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v4 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r7 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r5 = FIELDMAP_GetZoneId((u8 *)(((int *)r6)[1]));
    r6 = (int)SCRCMD_WORK_GetMmdlSys((void *)b);
    r0 = FLDMMDL_GetRealObjCode(GAME_DATA_GetEventWork(SCRCMD_WORK_GetGameData((void *)b)), v4);
    r0 = FLDMMDL_AddMmdlParam(r6, v0, v1, v2, v3, r0, r7, r5);
    if (r0 != 0) {
        FLDMMDL_OnMoveBitMovePause((void *)r0);
    }
    return 0;
}

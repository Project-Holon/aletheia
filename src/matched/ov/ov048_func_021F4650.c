/*
 * function: GIMMICK_OBJ_ELBOARD_CmdStartCameraEvent
 * address:  0x021F4650
 * packet:   pkt_ov048_021F4650
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GIMMICK_OBJ_ELBOARD_CreateCameraEvent  0x021F4DBC  thumb  ov048
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned int   u32;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void *GIMMICK_OBJ_ELBOARD_CreateCameraEvent(int a, int b, int c);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);

int GIMMICK_OBJ_ELBOARD_CmdStartCameraEvent(int a, int b)
{
    void *r6;
    void *r7;
    void *sp;
    int r4;

    r6 = SCRCMD_WORK_GetScriptWork((void *)b);
    r7 = SCRCMD_WORK_GetGameSystem((void *)b);
    sp = GAMESYSTEM_GetFieldMap((void *)r7);
    r4 = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    GFL_USE_PlaySeDefaultVolume(0x547);
    SCRIPT_SYS_CallEvent(r6, GIMMICK_OBJ_ELBOARD_CreateCameraEvent((int)r7, (int)sp, r4));
    return 1;
}

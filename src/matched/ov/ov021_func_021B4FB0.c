/*
 * function: SCRCMD_PROC_FLD_CallShortcutEvent
 * address:  0x021B4FB0
 * packet:   pkt_ov021_021B4FB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SCRCMD_CreateSubProcEvent  0x021C5BD0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Big;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *SCRCMD_CreateSubProcEvent(void *a, u32 b, u32 c);

int SCRCMD_PROC_FLD_CallShortcutEvent(u32 a, u32 b)
{
    void *r0;
    void *r7;
    u32 r4;
    unsigned short *x;
    u32 y;

    r0 = SCRCMD_WORK_GetScriptWork((void *)b);
    r7 = SCRCMD_WORK_GetGameSystem((void *)b);
    GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(r7));
    GAMESYSTEM_GetFieldMap((void *)r7);
    r4 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    x = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    if (r4 == 0 || r4 != 1)
        y = 0;
    else
        y = 1;
    SCRIPT_SYS_CallEvent(r0, SCRCMD_CreateSubProcEvent(r7, y, (u32)x));
    return 1;
}

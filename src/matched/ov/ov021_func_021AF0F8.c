/*
 * function: SCRCMD_PushBgm
 * address:  0x021AF0F8
 * packet:   pkt_ov021_021AF0F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELD_SOUND_SYSTEM_StartPushTask  0x020295A4  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u8 *FIELD_SOUND_SYSTEM_StartPushTask(u8 *p, u32 a);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void SCRIPT_WORK_SetCheckFlag(int n);

int SCRCMD_PushBgm(u32 a, u32 b)
{
    void *y = SCRCMD_WORK_GetGameSystem((void *)b);
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);

    SCRIPT_SYS_CallEvent(x, FIELD_SOUND_SYSTEM_StartPushTask(y, SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b)));
    SCRIPT_WORK_SetCheckFlag(10);
    return 1;
}

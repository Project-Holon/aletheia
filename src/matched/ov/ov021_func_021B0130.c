/*
 * function: SCRCMD_MSGWIN_CmdYesNoWin
 * address:  0x021B0130
 * packet:   pkt_ov021_021B0130
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_CreateYesNoEvent  0x021B010C  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u32 SCRCMD_MSGWIN_CreateYesNoEvent(u32 a, u32 x, u32 y);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_MSGWIN_CmdYesNoWin(u32 a, u32 b)
{
    u16 *r = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);

    SCRIPT_SYS_CallEvent(x, (void *)SCRCMD_MSGWIN_CreateYesNoEvent((u32)SCRCMD_WORK_GetGameSystem((void *)b), b, (u32)r));
    return 1;
}

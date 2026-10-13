/*
 * function: SCRCMD_MSGWIN_CmdStartMenu
 * address:  0x021B0394
 * packet:   pkt_021B0394
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_MSGWIN_CreateMenuEvent  0x021B01B8  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern u32 SCRCMD_MSGWIN_CreateMenuEvent(u32 a, u32 x, u32 y);

int SCRCMD_MSGWIN_CmdStartMenu(u32 a, u32 b, u32 c, u32 d)
{
SCRIPT_SYS_CallEvent(SCRCMD_WORK_GetScriptWork((void *)b), (void *)SCRCMD_MSGWIN_CreateMenuEvent((u32)SCRCMD_WORK_GetGameSystem((void *)b), b, 0));
return 1;
}


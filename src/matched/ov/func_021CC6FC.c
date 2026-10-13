/*
 * function: SCRCMD_PALPARK_CallFieldEvent
 * address:  0x021CC6FC
 * packet:   pkt_021CC6FC
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
 *   GPOWER_EVENT_CreateFlashEvent  0x021F5340  thumb  ov083
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
extern void *GPOWER_EVENT_CreateFlashEvent(void *p);

int SCRCMD_PALPARK_CallFieldEvent(u32 a, u32 b, u32 c, u32 d)
{
SCRIPT_SYS_CallEvent(SCRCMD_WORK_GetScriptWork((void *)b), GPOWER_EVENT_CreateFlashEvent(SCRCMD_WORK_GetGameSystem((void *)b)));
return 1;
}


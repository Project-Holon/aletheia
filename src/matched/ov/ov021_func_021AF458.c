/*
 * function: SCRCMD_IssSwitchOn
 * address:  0x021AF458
 * packet:   pkt_ov021_021AF458
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   ISS_SYS_GetSwitchSys  0x0202B578  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   ISS_SWITCH_SYS_SwitchOn  0x0202C0D0  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u32 GAMESYSTEM_GetIssSystem(u32 *p);
extern u32 ISS_SYS_GetSwitchSys(u32 *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void ISS_SWITCH_SYS_SwitchOn(u8 *p, u32 a);

int SCRCMD_IssSwitchOn(u32 a, u32 b)
{
    u32 x = ISS_SYS_GetSwitchSys((u32 *)GAMESYSTEM_GetIssSystem(SCRCMD_WORK_GetGameSystem((void *)b)));

    ISS_SWITCH_SYS_SwitchOn((u8 *)x, SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b));
    return 0;
}

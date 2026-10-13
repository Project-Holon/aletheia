/*
 * function: SCRCMD_MSGWIN_CmdCloseMoneyWin
 * address:  0x021B07E0
 * packet:   pkt_ov021_021B07E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetInfoWindow  0x02188D48  thumb  ov021
 *   FIELDMAP_SetInfoWindow  0x02188D4C  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetInfoWindow(u8 *p);
extern int FIELD_MSGBG_DeleteMsgWin(void *a);
extern void FIELDMAP_SetInfoWindow(u8 *p, u32 v);

int SCRCMD_MSGWIN_CmdCloseMoneyWin(u32 a, u32 b)
{
    void *x = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b));
    u32 y = FIELDMAP_GetInfoWindow(x);

    if (y != 0) {
        FIELD_MSGBG_DeleteMsgWin((void *)y);
        FIELDMAP_SetInfoWindow(x, 0);
    }
    return 0;
}

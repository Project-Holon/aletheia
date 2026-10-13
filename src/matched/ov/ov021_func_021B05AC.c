/*
 * function: SCRCMD_MSGWIN_CmdSetTimeIcon
 * address:  0x021B05AC
 * packet:   pkt_ov021_021B05AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetTimeIcon  0x0215A630  thumb  ov010
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   SCRCMD_WORK_SetTimeIcon  0x0215A624  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_GetInfoSysWinBmpWin  0x021911B4  thumb  ov021
 *   func_020056BC  0x020056BC  thumb
 *   TIME_ICON_Create  0x0202EE30  thumb
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int SCRIPT_WORK_CheckFlag(int a0);
extern u32 SCRCMD_WORK_GetTimeIcon(u8 *p);
extern void TIME_ICON_Delete(u8 *p);
extern void SCRCMD_WORK_SetTimeIcon(u8 *p, u32 v);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern u32 FIELD_MSGBG_GetInfoSysWinBmpWin(u8 *p);
extern u32 func_020056BC(void);
extern u32 TIME_ICON_Create(u32, u32, u32, u32, u32);

int SCRCMD_MSGWIN_CmdSetTimeIcon(u32 a, u32 b)
{
    u32 r6, r4, t0;

    r6 = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b)));
    r4 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    if (!SCRIPT_WORK_CheckFlag(1)) {
        return 0;
    }
    t0 = SCRCMD_WORK_GetTimeIcon((u8 *)b);
    if (t0) {
        TIME_ICON_Delete((void *)t0);
        SCRCMD_WORK_SetTimeIcon((u8 *)b, 0);
    }
    if (r4 == 0) {
        u32 t = FIELD_MSGBG_GetInfoSysWinBmpWin((u8 *)SCRCMD_WORK_GetMsgWindow(b));
        SCRCMD_WORK_SetTimeIcon((u8 *)b, TIME_ICON_Create(func_020056BC(), t, 0xf, 0x10, r6));
    }
    return 0;
}

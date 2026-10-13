/*
 * function: SCRCMD_MSGWIN_OpenTalkWin
 * address:  0x021B0ADC
 * packet:   pkt_ov021_021B0ADC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb  ov010
 *   FIELD_MSGBG_AddTalkWin  0x0219129C  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
struct Ent;
extern struct Ent *FIELD_MSGBG_AddTalkWin(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern void SCRCMD_WORK_SetMsgWindow(u8 *p, u32 v);
extern void SCRIPT_WORK_SetCheckFlag(int n);

void SCRCMD_MSGWIN_OpenTalkWin(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    SCRCMD_WORK_SetMsgWindow((u8 *)a, (u32)FIELD_MSGBG_AddTalkWin((u8 *)b, c, d, e, f, g));
    SCRIPT_WORK_SetCheckFlag(2);
}

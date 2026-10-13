/*
 * function: EVENT_RESEARCH_RADAR_ReportTaskMain
 * address:  0x02167080
 * packet:   pkt_ov010_02167080
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_RESEARCH_RADAR_LoadReportMsgData  0x02167154  thumb  ov010
 *   EVENT_RESEARCH_RADAR_CreateInfoWindow  0x02167178  thumb  ov010
 *   EVENT_RESEARCH_RADAR_CreateWordSet  0x021671DC  thumb  ov010
 *   EVENT_RESEARCH_RADAR_PrintReport  0x021671FC  thumb  ov010
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   EVENT_RESEARCH_RADAR_CloseInfoWindow  0x021672B4  thumb  ov010
 *   EVENT_RESEARCH_RADAR_DeleteWordSet  0x021671EC  thumb  ov010
 *   EVENT_RESEARCH_RADAR_DeleteInfoWindow  0x021671CC  thumb  ov010
 *   EVENT_RESEARCH_RADAR_DeleteReportMsgData  0x02167168  thumb  ov010
 */

typedef unsigned int u32;

struct O {
    u32 pad[5];
    int f14;
};

struct MsgBank;
extern struct MsgBank *EVENT_RESEARCH_RADAR_LoadReportMsgData(int a0, int a1, int a2, int a3);
extern void EVENT_RESEARCH_RADAR_CreateInfoWindow(struct O *o);
struct WordSet;
extern struct WordSet *EVENT_RESEARCH_RADAR_CreateWordSet(int a0);
extern void EVENT_RESEARCH_RADAR_PrintReport(struct O *o);
typedef unsigned char  u8;
extern int FIELD_MSGBG_IsMsgWinTransDone(u8 *p);
extern u32 func_020362DC(void);
extern int EVENT_RESEARCH_RADAR_CloseInfoWindow(int a0);
extern int EVENT_RESEARCH_RADAR_DeleteWordSet(int a0);
extern int EVENT_RESEARCH_RADAR_DeleteInfoWindow(int a0);
extern int EVENT_RESEARCH_RADAR_DeleteReportMsgData(int a0);

int EVENT_RESEARCH_RADAR_ReportTaskMain(void *a, int *st, struct O *o, int a3)
{
    switch (*st) {
    case 0:
        EVENT_RESEARCH_RADAR_LoadReportMsgData((int)o, (int)st, (int)o, a3);
        EVENT_RESEARCH_RADAR_CreateInfoWindow(o);
        EVENT_RESEARCH_RADAR_CreateWordSet((int)o);
        EVENT_RESEARCH_RADAR_PrintReport(o);
        *st = *st + 1;
        break;
    case 1:
        if (FIELD_MSGBG_IsMsgWinTransDone((u8 *)o->f14) == 1)
            *st = *st + 1;
        break;
    case 2:
        if (func_020362DC() & 0xf3)
            *st = *st + 1;
        break;
    case 3:
        EVENT_RESEARCH_RADAR_CloseInfoWindow((int)o);
        EVENT_RESEARCH_RADAR_DeleteWordSet((int)o);
        EVENT_RESEARCH_RADAR_DeleteInfoWindow((int)o);
        EVENT_RESEARCH_RADAR_DeleteReportMsgData((int)o);
        return 1;
    }
    return 0;
}

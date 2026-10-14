/*
 * function: SCRCMD_RESEARCH_CmdStartResearchReport
 * address:  0x0216B7F8
 * packet:   pkt_0216B7F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 36 compiled 34
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   EVENT_RESEARCH_RADAR_CreateReportTask  0x021670F8  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *EVENT_RESEARCH_RADAR_CreateReportTask(void *p);
extern int SCRIPT_SYS_CallEvent();

int SCRCMD_RESEARCH_CmdStartResearchReport(int a0, int a1)
{    int t5;
    void *p;
    void *v0;
    void *v1;

t5 = a1 + 0;
a0 = t5 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0216B802:
a0 = t5 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0216B80A:
    p = EVENT_RESEARCH_RADAR_CreateReportTask(v1);
loc_0216B80E:
    a0 = SCRIPT_SYS_CallEvent(v0, p);
loc_0216B816:
a0 = 1;
    return a0;}

/*
 * function: EVENT_RESEARCH_RADAR_CreateReportTask
 * address: 0x021670F8
 * packet: pkt_ov010_021670F8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_RESEARCH_RADAR_ReportTaskMain 0x02167080 thumb ov010
 *   EVENT_RESEARCH_RADAR_InitReportWork 0x0216711C thumb ov010
 */
struct O;
extern int EVENT_RESEARCH_RADAR_ReportTaskMain(void *a, int *st, struct O *o, int a3);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void EVENT_RESEARCH_RADAR_InitReportWork(u8 *p, void *sys);
void *EVENT_RESEARCH_RADAR_CreateReportTask(void *p) {
    void *task;
    task = func_020122C0(p, 0, EVENT_RESEARCH_RADAR_ReportTaskMain, 32);
    EVENT_RESEARCH_RADAR_InitReportWork(func_020124E8(task), p);
    return task;
}

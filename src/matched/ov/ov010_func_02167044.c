/*
 * function: EVENT_RESEARCH_RADAR_CreateTopTask
 * address: 0x02167044
 * packet: pkt_ov010_02167044
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_RESEARCH_RADAR_TopTaskMain 0x02166F9C thumb ov010
 *   func_02030734 0x02030734 arm
 *   g_ResearchRadarFileName 0x02172A00 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern int EVENT_RESEARCH_RADAR_TopTaskMain(void *, int *, int *);
extern const char g_ResearchRadarFileName[];
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
void *EVENT_RESEARCH_RADAR_CreateTopTask(void *a, void *b) {
    void *task;
    void **w;
    void **q;
    task = func_020122C0(a, 0, EVENT_RESEARCH_RADAR_TopTaskMain, 12);
    w = func_020124E8(task);
    w[0] = a;
    w[1] = b;
    q = func_02030734(4, 4, 0, g_ResearchRadarFileName, 117);
    w[2] = q;
    q[0] = a;
    return task;
}

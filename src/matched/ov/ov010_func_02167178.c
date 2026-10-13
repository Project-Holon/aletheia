/*
 * function: EVENT_RESEARCH_RADAR_CreateInfoWindow
 * address:  0x02167178
 * packet:   pkt_ov010_02167178
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_RESEARCH_RADAR_GetReportKind  0x021672D0  thumb  ov010
 *   FIELD_MSGBG_CreateMsgWin  0x02190708  thumb  ov021
 */

typedef unsigned short u16;

struct O {
    u16 pad0[8];
    int f10;
    int f14;
    int f18;
};

extern int EVENT_RESEARCH_RADAR_GetReportKind(int a0);
typedef unsigned int   u32;
struct Fx;
extern void *FIELD_MSGBG_CreateMsgWin(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);

void EVENT_RESEARCH_RADAR_CreateInfoWindow(struct O *o)
{
    int a;
    int b;
    int c;
    switch (EVENT_RESEARCH_RADAR_GetReportKind((int)o)) {
    case 0:
        a = 1;
        b = 0x1e;
        c = 4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        a = 1;
        b = 0x1e;
        c = 8;
        break;
    }
    o->f14 = (int)FIELD_MSGBG_CreateMsgWin((struct Fx *)o->f10, o->f18, a, a, b, c);
}

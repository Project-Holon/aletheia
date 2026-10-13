/*
 * function: EVENT_RESEARCH_RADAR_PrintReport
 * address:  0x021671FC
 * packet:   pkt_ov010_021671FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   EVENT_RESEARCH_RADAR_GetReportKind  0x021672D0  thumb  ov010
 *   EVENT_RESEARCH_RADAR_GetReportNumberA  0x021672E4  thumb  ov010
 *   EVENT_RESEARCH_RADAR_GetReportNumberB  0x021672F8  thumb  ov010
 *   EVENT_RESEARCH_RADAR_GetReportMessageId  0x0216730C  thumb  ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201F31C  0x0201F31C  thumb
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb  ov021
 *   FIELD_MSGBG_GetMsgWinBmpWin  0x021907C0  thumb  ov021
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   STRBUF_Delete  0x02045808  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct O {
    u16 id;
    u16 pad2[3];
    int f8;
    int pad0c[2];
    int f14;
    int f18;
    int f1c;
};

typedef unsigned char  u8;
struct Descriptor;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct MsgBank;
struct WordSet;
extern int EVENT_RESEARCH_RADAR_GetReportKind(int a0);
extern int EVENT_RESEARCH_RADAR_GetReportNumberA(int a0);
extern int EVENT_RESEARCH_RADAR_GetReportNumberB(int a0);
extern int EVENT_RESEARCH_RADAR_GetReportMessageId(unsigned int n);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201F31C(struct WordSet *p);
extern int FIELD_MSGBG_MsgWinPrintStr(u32 a, u32 b, u32 c, u32 d);
extern u32 FIELD_MSGBG_GetMsgWinBmpWin(u8 *p);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);

void EVENT_RESEARCH_RADAR_PrintReport(struct O *o)
{
    void *r4;
    void *r6;
    int r7;
    int s8;
    int sc;
    r4 = STRBUF_Create(0x100, o->id);
    r6 = STRBUF_Create(0x100, o->id);
    r7 = EVENT_RESEARCH_RADAR_GetReportKind((int)o);
    s8 = EVENT_RESEARCH_RADAR_GetReportNumberA((int)o);
    sc = EVENT_RESEARCH_RADAR_GetReportNumberB((int)o);
    r7 = EVENT_RESEARCH_RADAR_GetReportMessageId(r7);
    func_0201F02C((struct WordSet *)o->f1c, 0, GAME_DATA_GetMyStatus((void *)o->f8));
    func_0201EFA4((struct WordSet *)o->f1c, 1, s8, 5, 1, 1);
    func_0201EFA4((struct WordSet *)o->f1c, 2, sc, 5, 1, 1);
    MSGDATA_ReadString((struct MsgBank *)o->f18, r7, r4);
    func_0201F250((struct WordSet *)o->f1c, r6, r4);
    func_0201F31C((struct WordSet *)o->f1c);
    FIELD_MSGBG_MsgWinPrintStr(o->f14, 8, 0, (u32)r6);
    func_020409B4(func_02045730((void *)FIELD_MSGBG_GetMsgWinBmpWin((u8 *)o->f14)));
    STRBUF_Delete(r4);
    STRBUF_Delete(r6);
}

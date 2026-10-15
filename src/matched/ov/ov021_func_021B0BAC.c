/*
 * function: SCRCMD_MSGWIN_OpenBalloonWinMsg
 * address:  0x021B0BAC
 * packet:   pkt_ov021_021B0BAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_OpenBalloonWinMsg  0x021B0BAC  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetMsgData  0x0215A60C  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   SCRIPT_WORK_GetMsgBuffer  0x02158F78  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb  ov010
 *   func_02045CAC  0x02045CAC  arm
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   SCRCMD_WORK_GetWordSetWork  0x0215A63C  thumb  ov010
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_TalkWinPrintStr  0x02191348  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   SCRCMD_WORK_GetWindowState  0x0215A654  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   SCRCMD_MSGWIN_GetBalloonSide  0x021B0A40  thumb  ov021
 *   SCRCMD_MSGWIN_GetBalloonTailParams  0x021B09EC  thumb  ov021
 *   SCRCMD_WORK_SetWindowState  0x0215A660  thumb  ov010
 *   SCRCMD_WORK_SetWindowKind  0x0215A678  thumb  ov010
 *   SCRCMD_MSGWIN_UpdateBalloonPos  0x021B0B08  thumb  ov021
 *   SCRCMD_MSGWIN_OpenTalkWin  0x021B0ADC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct V3 {
    int x, y, z;
} V3;

typedef struct S {
    u16 id;
    u16 flag;
    V3 sum;
    V3 a;
    V3 b;
} S;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct MsgBank;
struct Rec;
struct WordSet;
extern u32 SCRCMD_WORK_GetMsgData(u8 *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *SCRCMD_WORK_GetOccupyInfo(void *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern u32 SCRIPT_WORK_GetMsgBuffer(u8 *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u32 SCRIPT_WORK_GetTempBuffer(u8 *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u8 *SCRCMD_WORK_GetWordSetWork(u8 *p);
extern int SCRIPT_WORK_CheckFlag(int a0);
extern int SCRCMD_WORK_GetMsgWindow(int a0);
extern u32 FIELD_MSGBG_TalkWinPrintStr(u32 *a, u32 b);
extern void MI_CpuFill8(void *p, int v, int n);
extern u32 SCRCMD_WORK_GetWindowState(u8 *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
struct Q;
extern int SCRCMD_MSGWIN_GetBalloonSide(u32 a, struct Q *q);
extern void SCRCMD_MSGWIN_GetBalloonTailParams(int, int *, int *);
extern void SCRCMD_WORK_SetWindowState(u8 *p, u32 v);
extern void SCRCMD_WORK_SetWindowKind(u8 *p, u8 v);
extern void SCRCMD_MSGWIN_UpdateBalloonPos(void *a, int b);
extern void SCRCMD_MSGWIN_OpenTalkWin(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

int SCRCMD_MSGWIN_OpenBalloonWinMsg(u32 b, u16 id, u16 c, u16 d, u16 e, int f)
{
    u32 s28;
    void *o;
    u32 *q;
    u32 t, m20, m1c, r7, r18, r5, h;
    int sel;
    S *s;
    V3 v;
    int oa, ob;

    sel = e;
    o = SCRCMD_WORK_GetScriptWork((void *)b);
    s28 = SCRCMD_WORK_GetMsgData((u8 *)b);
    q = (u32 *)SCRIPT_WORK_ResetFieldParam((int)o);
    t = (u32)SCRCMD_WORK_GetOccupyInfo((void *)b);
    m20 = (u32)FLDMMDL_SysSearchObjId((void *)t, 0xff);
    m1c = (u32)FLDMMDL_SysSearchObjId((void *)t, id);
    if (m1c == 0) {
        return 0;
    }
    r7 = SCRIPT_WORK_GetMsgBuffer(o);
    r18 = (u32)SCRIPT_WORK_GetWordSet(o);
    r5 = SCRIPT_WORK_GetTempBuffer(o);
    if (c == 0x400) {
        func_02045CAC((struct MsgBank *)s28, d, (void *)r5);
    } else {
        h = (u32)func_02045B38(0, 3, c, SCRCMD_WORK_GetHeapId((void *)b));
        func_02045CAC((struct MsgBank *)h, d, (void *)r5);
        MSGDATA_Delete((struct Rec *)h);
    }
    WORDSET_CopyTaggedText((struct WordSet *)r18, (void *)r7, (void *)r5);
    s = (S *)SCRCMD_WORK_GetWordSetWork((u8 *)b);
    if (SCRIPT_WORK_CheckFlag(2) != 0) {
        FIELD_MSGBG_TalkWinPrintStr((u32 *)SCRCMD_WORK_GetMsgWindow(b), r7);
    } else {
        MI_CpuFill8(s, 0, 0x28);
        s->id = id;
        if (e == 0) {
            SCRCMD_WORK_GetWindowState((u8 *)b);
            FLDMMDL_GetPos((const struct Actor *)m1c, (struct VecFx32 *)&v);
            sel = SCRCMD_MSGWIN_GetBalloonSide(m20, (struct Q *)(&v));
        }
        SCRCMD_MSGWIN_GetBalloonTailParams(sel, &oa, &ob);
        s->flag = oa;
        SCRCMD_WORK_SetWindowState((u8 *)b, (u8)sel);
        SCRCMD_WORK_SetWindowKind((u8 *)b, e);
        SCRCMD_MSGWIN_UpdateBalloonPos((void *)b, 1);
        SCRCMD_MSGWIN_OpenTalkWin(b, *q, oa, (u32)(&s->sum), r7, f, ob);
    }
    return 1;
}

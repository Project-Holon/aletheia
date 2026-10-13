/*
 * function: SCRCMD_MSGWIN_CmdAddSubWinMsg
 * address:  0x021B1100
 * packet:   pkt_ov021_021B1100
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_CmdAddSubWinMsg  0x021B1100  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   STRBUF_Create  0x020457B0  arm
 *   SCRCMD_WORK_GetMsgData  0x0215A60C  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb  ov010
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   FIELD_MSGBG_GetStrSizeChars  0x02191830  thumb  ov021
 *   FIELD_MSGBG_AddSubMsgWinStr  0x021918DC  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 SCRCMD_WORK_GetMsgData(u8 *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u32 SCRIPT_WORK_GetTempBuffer(u8 *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Q;
extern void FIELD_MSGBG_GetStrSizeChars(struct Q *q, u32 a, u8 *w, u8 *h);
extern void FIELD_MSGBG_AddSubMsgWinStr(u16 *a, u32 b, u32 c, u8 d, u8 e, u8 f, u8 g);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void SCRIPT_WORK_SetCheckFlag(int n);

int SCRCMD_MSGWIN_CmdAddSubWinMsg(void *a, u32 b)
{
    u32 h, y, z, w;
    void *o;
    u16 x1, x2;
    u16 **q;
    int k0, k1;
    u8 buf[2];
    u8 t;

    o = SCRCMD_WORK_GetScriptWork((void *)b);
    q = (u16 **)SCRIPT_WORK_ResetFieldParam((int)o);
    x1 = VM_GetU16(a);
    k0 = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    k1 = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    x2 = VM_GetU16(a);
    buf[0] = 2;
    h = (u32)STRBUF_Create(0x40, SCRCMD_WORK_GetHeapId((void *)b));
    y = SCRCMD_WORK_GetMsgData((u8 *)b);
    z = (u32)SCRIPT_WORK_GetWordSet(o);
    w = SCRIPT_WORK_GetTempBuffer(o);
    MSGDATA_ReadString((struct MsgBank *)y, x1, (void *)w);
    func_0201F250((struct WordSet *)z, (void *)h, (void *)w);
    FIELD_MSGBG_GetStrSizeChars((struct Q *)(*q), h, &buf[1], &buf[0]);
    t = buf[1];
    if (k0 + t > 0x1f) {
        k0 = (u16)(0x1f - t);
    }
    if (k1 + buf[0] > 0x18) {
        k1 = 4;
        buf[0] = k1;
    }
    FIELD_MSGBG_AddSubMsgWinStr(*q, h, x2, k0, k1, t, buf[0]);
    STRBUF_Delete((struct U16Vec *)h);
    SCRIPT_WORK_SetCheckFlag(5);
    return 0;
}

/*
 * function: SCRCMD_MSGWIN_CmdBgWinMsgFont
 * address:  0x021B1334
 * packet:   pkt_ov021_021B1334
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_CmdBgWinMsgFont  0x021B1334  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRCMD_WORK_GetMsgData  0x0215A60C  thumb  ov010
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   SCRIPT_WORK_SetMsgData  0x02158F80  thumb  ov010
 *   FIELD_MSGBG_CreateBgWinFont  0x02191A10  thumb  ov021
 *   SCRCMD_WORK_SetMsgWindow  0x0215A614  thumb  ov010
 *   SCRIPT_WORK_GetMsgBuffer  0x02158F78  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb  ov010
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   SCRCMD_MSGWIN_WaitBgWin  0x021B1240  thumb
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
struct Stream;
struct WordSet;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u16 VM_GetU16(struct Stream *s);
struct GfFont;
extern u16 FIELDMAP_GetHeapId(unsigned char *p);
extern unsigned int SCRCMD_WORK_GetMsgData(unsigned char *p);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, unsigned int heapId);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void SCRIPT_WORK_SetMsgData(u8 *p, u32 v);
struct MsgBank;
extern u32 *FIELD_MSGBG_CreateBgWinFont(u16 *a, u32 b, u32 c);
extern void SCRCMD_WORK_SetMsgWindow(u8 *p, u32 v);
extern u32 SCRIPT_WORK_GetMsgBuffer(u8 *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u32 SCRIPT_WORK_GetTempBuffer(u8 *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void VM_SetWait(char *p, int val);
extern void SCRIPT_WORK_SetCheckFlag(int);
extern int SCRCMD_MSGWIN_WaitBgWin(int, int);

int SCRCMD_MSGWIN_CmdBgWinMsgFont(int a, unsigned char *b)
{
    void *o;
    int *q, *q2;
    int s0, s1, s2, h, m;
    int x, y, z;
    o = SCRCMD_WORK_GetScriptWork((void *)b);
    q = (int *)SCRIPT_WORK_ResetFieldParam((int)o);
    s0 = VM_GetU16((struct Stream *)a);
    s1 = VM_GetU16((struct Stream *)a);
    h = FIELDMAP_GetHeapId((unsigned char *)q[1]);
    q2 = (int *)SCRIPT_WORK_ResetFieldParam((int)o);
    s2 = SCRCMD_WORK_GetMsgData(b);
    m = (int)GF_FONT_Create(0x17, 4, 0, 0, h);
    SCRIPT_WORK_SetMsgData(o, m);
    SCRCMD_WORK_SetMsgWindow((u8 *)b, (u32)FIELD_MSGBG_CreateBgWinFont((u16 *)(*q2), s1, m));
    x = SCRIPT_WORK_GetMsgBuffer(o);
    y = (int)SCRIPT_WORK_GetWordSet(o);
    z = SCRIPT_WORK_GetTempBuffer(o);
    MSGDATA_ReadString((struct MsgBank *)s2, s0, (void *)z);
    WORDSET_CopyTaggedText((struct WordSet *)y, (void *)x, (void *)z);
    VM_SetWait((char *)a, (int)SCRCMD_MSGWIN_WaitBgWin);
    SCRIPT_WORK_SetCheckFlag(4);
    return 1;
}

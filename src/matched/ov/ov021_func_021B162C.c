/*
 * function: SCRCMD_MSGWIN_ExpandMessage
 * address:  0x021B162C
 * packet:   pkt_ov021_021B162C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F250  0x0201F250  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_GetMsgBuffer  0x02158F78  thumb  ov010
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb  ov010
 *   SCRCMD_WORK_GetMsgData  0x0215A60C  thumb  ov010
 */

typedef unsigned int u32;

typedef unsigned char  u8;
struct MsgBank;
struct WordSet;
extern u32 SCRCMD_WORK_GetMsgData(u8 *p);
extern u32 SCRIPT_WORK_GetMsgBuffer(u8 *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u32 SCRIPT_WORK_GetTempBuffer(u8 *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

u32 SCRCMD_MSGWIN_ExpandMessage(u32 a, u32 b, u32 c)
{
    u32 x, r, s, n;

    x = SCRCMD_WORK_GetMsgData((u8 *)a);
    r = SCRIPT_WORK_GetMsgBuffer((u8 *)b);
    s = (u32)SCRIPT_WORK_GetWordSet((void *)b);
    n = SCRIPT_WORK_GetTempBuffer((u8 *)b);
    MSGDATA_ReadString((struct MsgBank *)x, c, (void *)n);
    func_0201F250((struct WordSet *)s, (void *)r, (void *)n);
    return r;
}

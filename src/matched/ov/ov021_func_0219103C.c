/*
 * function: FIELD_MSGBG_InfoSysWinPrintMsg
 * address:  0x0219103C
 * packet:   pkt_ov021_0219103C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MSGBG_DeleteMsgStream  0x02190D48  thumb  ov021
 *   FIELD_MSGBG_CreateMsgStream  0x02190D2C  thumb  ov021
 *   FIELD_MSGBG_KeyWaitGetCharWait  0x02193210  thumb  ov021
 *   MSGDATA_ReadString  0x02045CAC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_MSGBG_DeleteMsgStream(void *a);
extern u32 FIELD_MSGBG_CreateMsgStream(u32, u32, u32, u16, u32, u32);
struct MsgBank;
extern u32 FIELD_MSGBG_KeyWaitGetCharWait(u8 *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);

void FIELD_MSGBG_InfoSysWinPrintMsg(u32 *p, u32 b, u32 c, u32 d)
{
    if (p[1] != 0) {
        FIELD_MSGBG_DeleteMsgStream((void *)p[1]);
    }
    MSGDATA_ReadString((struct MsgBank *)p[3], d, (void *)p[4]);
    p[1] = FIELD_MSGBG_CreateMsgStream(p[5], p[4], p[0], b + 8, c, FIELD_MSGBG_KeyWaitGetCharWait((u8 *)(p[5] + 0x160)));
}

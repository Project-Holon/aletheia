/*
 * function: BTL_MSG_BuildStandard
 * address:  0x021EF1CC
 * packet:   pkt_ov093_021EF1CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlMsgState  0x021F6398  data  a4
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   BTL_MSG_CountWordTags  0x021EEF98  thumb  ov093
 *   BTL_MSG_BuildStandardPair  0x021EF280  thumb  ov093
 *   BTL_MSG_BuildStandardSingle  0x021EF204  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 t[8];
} D;

extern D gBtlMsgState;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u8 BTL_MSG_CountWordTags(void *s);
extern void BTL_MSG_BuildStandardPair(u32 a, u32 b, u32 c);
extern void BTL_MSG_BuildStandardSingle(u32 a, u32 b, u32 *p);

void BTL_MSG_BuildStandard(u32 a, u32 b, u32 c)
{
    MSGDATA_ReadString((struct MsgBank *)gBtlMsgState.t[1], b, (void *)gBtlMsgState.fc);
    if (BTL_MSG_CountWordTags((void *)gBtlMsgState.fc) == 2)
        BTL_MSG_BuildStandardPair(a, b, c);
    else
        BTL_MSG_BuildStandardSingle(a, b, (u32 *)c);
}

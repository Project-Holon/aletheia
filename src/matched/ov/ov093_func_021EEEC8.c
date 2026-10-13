/*
 * function: BTL_MSG_BuildString
 * address:  0x021EEEC8
 * packet:   pkt_ov093_021EEEC8
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
 *   BTL_MSG_ExpandTags  0x021EEFE0  thumb  ov093
 *   func_0201F250  0x0201F250  thumb
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
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void BTL_MSG_ExpandTags(void *s, const u32 *values, void *w);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

void BTL_MSG_BuildString(u32 a, u32 b, u32 c)
{
    MSGDATA_ReadString((struct MsgBank *)gBtlMsgState.t[0], b, (void *)gBtlMsgState.fc);
    BTL_MSG_ExpandTags((void *)gBtlMsgState.fc, (const u32 *)c, (void *)gBtlMsgState.f8);
    func_0201F250((struct WordSet *)gBtlMsgState.f8, (void *)a, (void *)gBtlMsgState.fc);
}

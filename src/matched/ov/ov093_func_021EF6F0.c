/*
 * function: BTL_MSG_BuildTrainerStringBody
 * address:  0x021EF6F0
 * packet:   pkt_ov093_021EF6F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MSG_ExpandTags  0x021EEFE0  thumb  ov093
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   gBtlMsgState     0x021F6398  data   a4
 *
 * Unlabelled leaf, callee of the tail stub 0x021EF6E8 that BTLV_CORE_BuildMessage calls.
 * Twin of BTL_MSG_BuildUiStringFlagged without the +0x5a flag stores, using the +0x28 slot.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 pad[10];
    u32 f54;
    u16 f58;
    u16 f5a;
} D;

struct MsgBank;
struct WordSet;
extern void BTL_MSG_ExpandTags(void *s, const u32 *values, void *w);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern D gBtlMsgState;

void BTL_MSG_BuildTrainerStringBody(u32 a, u32 b, u32 c)
{
    MSGDATA_ReadString((struct MsgBank *)gBtlMsgState.f28, b, (void *)gBtlMsgState.fc);
    BTL_MSG_ExpandTags((void *)gBtlMsgState.fc, (const u32 *)c, (void *)gBtlMsgState.f8);
    func_0201F250((struct WordSet *)gBtlMsgState.f8, (void *)a, (void *)gBtlMsgState.fc);
}

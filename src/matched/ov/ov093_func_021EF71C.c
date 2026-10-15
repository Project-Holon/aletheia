/*
 * function: BTL_MSG_BuildBallStatusOpen
 * address:  0x021EF71C
 * packet:   pkt_ov093_021EF71C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   gBtlMsgState     0x021F6398  data   a4
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
    u32 pad[11];
    u32 f54;
    u16 f58;
    u16 f5a;
} D;

struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern D gBtlMsgState;

void BTL_MSG_BuildBallStatusOpen(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    MSGDATA_ReadString((struct MsgBank *)gBtlMsgState.f1c, 0x10, (void *)gBtlMsgState.fc);
    WORDSET_SetSlotNumber((struct WordSet *)gBtlMsgState.f8, 0, b, 2, 0, 1);
    WORDSET_SetSlotNumber((struct WordSet *)gBtlMsgState.f8, 1, c, 2, 0, 1);
    WORDSET_SetSlotNumber((struct WordSet *)gBtlMsgState.f8, 2, d, 2, 0, 1);
    WORDSET_SetSlotNumber((struct WordSet *)gBtlMsgState.f8, 3, e, 2, 0, 1);
    WORDSET_SetSlotNumber((struct WordSet *)gBtlMsgState.f8, 4, f, 2, 0, 1);
    WORDSET_SetSlotNumber((struct WordSet *)gBtlMsgState.f8, 5, g, 2, 0, 1);
    WORDSET_CopyTaggedText((struct WordSet *)gBtlMsgState.f8, (void *)a, (void *)gBtlMsgState.fc);
}
